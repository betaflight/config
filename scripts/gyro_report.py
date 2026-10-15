#!/usr/bin/env python3
#
# This file is part of Betaflight.
#
# Betaflight is free software. You can redistribute this software
# and/or modify this software under the terms of the GNU General
# Public License as published by the Free Software Foundation,
# either version 3 of the License, or (at your option) any later
# version.
#
# Betaflight is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public
# License along with this software.
#
# If not, see <http://www.gnu.org/licenses/>.

"""Inventory and lint the gyro/accelerometer declarations in configs/.

A board declares a *menu* of IMU parts -- the firmware probes each gyro
footprint at boot and binds whichever part answers. Alignment, in contrast,
belongs to the footprint, so it is reported per GYRO_n.

Report:
    ./scripts/gyro_report.py --sensor BMI270
    ./scripts/gyro_report.py --sensor LSM6DSK320X --format md -o boards.md
    ./scripts/gyro_report.py --format html -o gyro.html
    ./scripts/gyro_report.py --list-sensors

Lint:
    ./scripts/gyro_report.py --check
    ./scripts/gyro_report.py --check --strict
"""

import argparse
import csv
import html
import io
import json
import os
import re
import sys
from collections import Counter

MAX_GYROS = 8

DEFINE_RE = re.compile(r"^\s*#\s*define\s+([A-Za-z_]\w*)(?:\s+(.*?))?\s*(?://.*)?$")

# USE_GYRO_* / USE_ACC_* names that select a driver or a position rather than
# name a part. The numeric suffixes track MAX_GYROS so a future USE_GYRO_5 is
# not mistaken for a part number.
NON_SENSOR_SUFFIXES = frozenset(
    ("CLKIN", "EXTI", "BOTH", "DEFAULT", "OVERFLOW")
    + tuple(str(n) for n in range(1, MAX_GYROS + 1))
)
SENSOR_RE = re.compile(r"^USE_(?:ACCGYRO|GYRO_SPI|ACC_SPI|GYRO|ACC)_([A-Z0-9]+)$")

# Standard alignments, mapped to their clockwise rotation for the HTML glyph.
ROTATION = {
    "CW0_DEG": 0,
    "CW90_DEG": 90,
    "CW180_DEG": 180,
    "CW270_DEG": 270,
    "CW0_DEG_FLIP": 0,
    "CW90_DEG_FLIP": 90,
    "CW180_DEG_FLIP": 180,
    "CW270_DEG_FLIP": 270,
}

# Absent GYRO_n_ALIGN, src/main/pg/gyrodev.c falls back to this.
DEFAULT_ALIGN = "CW0_DEG"


class Board:
    """One parsed config.h."""

    def __init__(self, path, defines, order, root=None):
        self.path = path
        # path as written in the repo, e.g. configs/AIKO/AIKONF4/config.h
        self.relpath = (
            os.path.relpath(path, os.path.dirname(root)).replace(os.sep, "/")
            if root
            else path
        )
        self.defines = defines
        self.name = defines.get("BOARD_NAME") or os.path.basename(os.path.dirname(path))
        self.manufacturer = defines.get("MANUFACTURER_ID", "")
        self.mcu = defines.get("FC_TARGET_MCU", "")
        self.i2c = "USE_I2C_GYRO" in defines
        self.default_gyro = defines.get("DEFAULT_GYRO_TO_USE", "")
        self.sensors = self._sensors(order)
        self.footprints = self._footprints()

    def _sensors(self, order):
        """Part numbers this board may be populated with, in declaration order."""
        found = []
        for name in order:
            match = SENSOR_RE.match(name)
            if not match:
                continue
            part = match.group(1)
            if part in NON_SENSOR_SUFFIXES or part in found:
                continue
            found.append(part)
        return found

    def _resolve(self, value, depth=0):
        """Follow macro aliases, e.g. GYRO_1_ALIGN -> ICM42688P_ALIGN -> CW180_DEG."""
        while value in self.defines and depth < 8:
            value = self.defines[value]
            depth += 1
        return value

    def _get(self, key):
        """Resolved value of a define, or None when absent or explicitly NONE.

        A config may write `#define GYRO_2_CS_PIN NONE` to say the position is
        deliberately unpopulated, which is not the same as leaving it out.
        """
        if key not in self.defines:
            return None
        value = self._resolve(self.defines[key])
        return None if value == "NONE" else value

    def _footprints(self):
        """Every GYRO_n position the config mentions, whether or not it is complete."""
        found = []
        for n in range(1, MAX_GYROS + 1):
            keys = (f"GYRO_{n}_CS_PIN", f"GYRO_{n}_SPI_INSTANCE", f"GYRO_{n}_ALIGN")
            if not any(self._get(k) is not None for k in keys):
                continue

            align_key = f"GYRO_{n}_ALIGN"
            omitted = self._get(align_key) is None
            align = DEFAULT_ALIGN if omitted else self._resolve(self.defines[align_key])

            custom = {}
            for axis in ("ROLL", "PITCH", "YAW"):
                raw = self._get(f"{align_key}_{axis}")
                if raw is not None:
                    try:
                        custom[axis.lower()] = int(raw) / 10
                    except ValueError:
                        # An alias that resolves to something non-numeric; keep it
                        # verbatim so the report shows what the config actually says.
                        custom[axis.lower()] = raw

            found.append(
                {
                    "n": n,
                    "align": align,
                    "omitted": omitted,
                    "custom": custom,
                    "spi": self._get(f"GYRO_{n}_SPI_INSTANCE") or "",
                    "cs": self._get(f"GYRO_{n}_CS_PIN") or "",
                    "exti": self._get(f"GYRO_{n}_EXTI_PIN") or "",
                    "clkin": self._get(f"GYRO_{n}_CLKIN_PIN") is not None,
                }
            )
        return found

    def footprint(self, n):
        return next((f for f in self.footprints if f["n"] == n), None)

    def align_label(self, n):
        """Human-readable alignment, e.g. 'ALIGN_CUSTOM (r=0, p=0, y=225)'."""
        fp = self.footprint(n)
        if fp is None:
            return ""
        label = fp["align"]
        if fp["custom"]:
            axes = ", ".join(
                f"{k[0]}={v:g}" if isinstance(v, float) else f"{k[0]}={v}"
                for k, v in fp["custom"].items()
            )
            label += f" ({axes})"
        return label


def parse_config(path):
    """Parse one config.h into (defines, declaration order).

    Preprocessor conditionals are not evaluated -- every #define is taken at
    face value. Verified safe for this repo: no gyro or acc define in any
    config sits inside an #if/#ifdef block. --check re-verifies that.
    """
    defines, order = {}, []
    with open(path, encoding="utf-8", errors="replace") as handle:
        for line in handle:
            match = DEFINE_RE.match(line)
            if not match:
                continue
            name, value = match.group(1), (match.group(2) or "").strip()
            if name not in defines:
                order.append(name)
            defines[name] = value
    return defines, order


def guarded_defines(path):
    """Names #defined inside a preprocessor conditional in this file."""
    guarded, depth = set(), 0
    cond = re.compile(r"^\s*#\s*(if|ifdef|ifndef|endif)\b")
    with open(path, encoding="utf-8", errors="replace") as handle:
        for line in handle:
            match = cond.match(line)
            if match:
                depth = depth + 1 if match.group(1) != "endif" else max(0, depth - 1)
                continue
            define = DEFINE_RE.match(line)
            if define and depth:
                guarded.add(define.group(1))
    return guarded


def find_configs(root):
    """Locate every config.h under root, flat or grouped by manufacturer."""
    paths = []
    for dirpath, dirnames, filenames in os.walk(root):
        dirnames.sort()
        if "config.h" in filenames:
            paths.append(os.path.join(dirpath, "config.h"))
    return sorted(paths)


def collect(root, sensor=None):
    boards = []
    for path in find_configs(root):
        defines, order = parse_config(path)
        board = Board(path, defines, order, root)
        if not board.sensors:
            continue
        if sensor and sensor.upper() not in board.sensors:
            continue
        boards.append(board)
    boards.sort(key=lambda b: (b.manufacturer, b.name))
    return boards


# --------------------------------------------------------------------------
# checks
# --------------------------------------------------------------------------

def run_checks(boards):
    """Return findings as (severity, board, code, message) tuples."""
    findings = []

    def error(board, code, message):
        findings.append(("error", board, code, message))

    def warn(board, code, message):
        findings.append(("warning", board, code, message))

    for board in boards:
        defines = board.defines

        if not board.footprints and not board.i2c:
            error(
                board,
                "sensor-without-footprint",
                f"declares {', '.join(board.sensors)} but defines no GYRO_n footprint",
            )

        for fp in board.footprints:
            n = fp["n"]
            has_cs = bool(fp["cs"])
            has_spi = bool(fp["spi"])

            if has_cs and not has_spi:
                error(
                    board,
                    "footprint-not-bound",
                    f"GYRO_{n}_CS_PIN is set but GYRO_{n}_SPI_INSTANCE is missing. "
                    f"GYRO_COUNT counts this position, so the slot exists but "
                    f"gyrodev.c leaves it BUS_TYPE_NONE and it can never be detected",
                )
            if has_spi and not has_cs and not board.i2c:
                warn(
                    board,
                    "spi-without-cs",
                    f"GYRO_{n}_SPI_INSTANCE is set but GYRO_{n}_CS_PIN is missing. "
                    f"GYRO_COUNT keys on the CS pin (common_pre.h), so this define is "
                    f"inert and can be removed",
                )
            if not has_cs and not has_spi and not board.i2c:
                error(
                    board,
                    "align-without-footprint",
                    f"GYRO_{n}_ALIGN is set but GYRO_{n} has neither a CS pin nor an SPI instance",
                )
            if fp["align"] == "ALIGN_CUSTOM" and not fp["custom"]:
                error(
                    board,
                    "custom-align-without-degrees",
                    f"GYRO_{n}_ALIGN is ALIGN_CUSTOM but no "
                    f"GYRO_{n}_ALIGN_ROLL/PITCH/YAW is defined",
                )
            if fp["custom"] and fp["align"] != "ALIGN_CUSTOM" and not fp["omitted"]:
                error(
                    board,
                    "degrees-without-custom-align",
                    f"GYRO_{n}_ALIGN_ROLL/PITCH/YAW are defined but "
                    f"GYRO_{n}_ALIGN is {fp['align']}, not ALIGN_CUSTOM",
                )
            if fp["align"] not in ROTATION and fp["align"] != "ALIGN_CUSTOM":
                error(
                    board,
                    "unresolved-align",
                    f"GYRO_{n}_ALIGN resolves to '{fp['align']}', "
                    f"which is not a known sensor_align_e value",
                )

        wants_second = "GYRO_2" in board.default_gyro or "BOTH" in board.default_gyro
        if wants_second and board.footprint(2) is None:
            error(
                board,
                "default-gyro-missing-footprint",
                f"DEFAULT_GYRO_TO_USE is {board.default_gyro} but no GYRO_2 footprint exists",
            )

        spi_gyro = {k[len("USE_GYRO_SPI_"):] for k in defines if k.startswith("USE_GYRO_SPI_")}
        spi_acc = {k[len("USE_ACC_SPI_"):] for k in defines if k.startswith("USE_ACC_SPI_")}
        for part in sorted(spi_gyro - spi_acc):
            error(
                board,
                "acc-gyro-pair-mismatch",
                f"USE_GYRO_SPI_{part} has no matching USE_ACC_SPI_{part}",
            )
        for part in sorted(spi_acc - spi_gyro):
            error(
                board,
                "acc-gyro-pair-mismatch",
                f"USE_ACC_SPI_{part} has no matching USE_GYRO_SPI_{part}",
            )

        gyro_guarded = sorted(
            name
            for name in guarded_defines(board.path)
            if "GYRO" in name or "ACC" in name
        )
        if gyro_guarded:
            warn(
                board,
                "conditional-gyro-define",
                "gyro/acc defines sit inside a preprocessor conditional and are "
                "reported at face value: " + ", ".join(gyro_guarded),
            )

        # Note: an omitted GYRO_n_ALIGN is not a finding. Leaving it out is the
        # house style for CW0_DEG, so absence carries the same meaning as writing
        # it explicitly and nothing in the config distinguishes the two.

    order = {"error": 0, "warning": 1}
    findings.sort(key=lambda f: (order[f[0]], f[1].manufacturer, f[1].name, f[2]))
    return findings


# --------------------------------------------------------------------------
# renderers
# --------------------------------------------------------------------------

def is_bound(fp):
    """A position is only compiled in when it has both a CS pin and an SPI instance."""
    return bool(fp["cs"] and fp["spi"])


def summarise(boards, sensor):
    return {
        "sensor": sensor.upper() if sensor else None,
        "boards": len(boards),
        "manufacturers": len({b.manufacturer for b in boards}),
        "dual_footprint": sum(
            1 for b in boards if sum(1 for f in b.footprints if is_bound(f)) > 1
        ),
        "unbound_footprint": sum(
            1 for b in boards if any(not is_bound(f) for f in b.footprints)
        ),
        "omitted_alignment": sum(
            1 for b in boards if any(f["omitted"] and is_bound(f) for f in b.footprints)
        ),
        "single_sensor": sum(1 for b in boards if len(b.sensors) == 1),
    }


def board_rows(boards, sensor):
    """Flatten boards into the shape every renderer consumes."""
    key = sensor.upper() if sensor else None
    rows = []
    for b in boards:
        rows.append(
            {
                "board": b.name,
                "mfr": b.manufacturer,
                "mcu": b.mcu,
                "sensors": b.sensors,
                "others": [s for s in b.sensors if s != key],
                "fp": [
                    {
                        "n": f["n"],
                        "align": b.align_label(f["n"]),
                        "omitted": f["omitted"],
                        "spi": f["spi"] or "-",
                        "cs": f["cs"] or "-",
                        "bound": is_bound(f),
                        "clkin": f["clkin"],
                    }
                    for f in b.footprints
                ],
                "dual": sum(1 for f in b.footprints if is_bound(f)) > 1,
                "anyomitted": any(f["omitted"] and is_bound(f) for f in b.footprints),
                "dflt": b.default_gyro.replace("GYRO_CONFIG_USE_", ""),
                "path": b.relpath,
            }
        )
    return rows


def cell(row, n):
    fp = next((f for f in row["fp"] if f["n"] == n), None)
    if fp is None:
        return "—"
    if not fp["bound"]:
        missing = "no SPI instance" if fp["spi"] == "-" else "no CS pin"
        return f"**unbound** ({missing})"
    align = fp["align"] + (" *(default)*" if fp["omitted"] else "")
    return f"{align} · {fp['spi']}"


def render_md(rows, summary, sensor):
    title = f"Boards declaring {summary['sensor']}" if sensor else "Gyro/IMU inventory"
    out = [
        f"# {title}",
        "",
        f"{summary['boards']} boards across {summary['manufacturers']} manufacturers. "
        f"{summary['dual_footprint']} have two bound gyro footprints; "
        f"{summary['omitted_alignment']} leave `{DEFAULT_ALIGN}` implicit; "
        f"{summary['unbound_footprint']} declare a position that is never compiled in.",
        "",
        "A board's IMU defines are a menu, not an assignment: the firmware probes each",
        "footprint at boot and binds whichever part answers. Alignment belongs to the",
        f"footprint, so it is listed per `GYRO_n`. *(default)* means `{DEFAULT_ALIGN}`",
        "reached by omitting `GYRO_n_ALIGN`, which is the house style rather than an",
        "oversight. **unbound** means the position lacks a CS pin or an SPI instance,",
        "so it never reaches gyrodev.c.",
        "",
        "| Board | Mfr | MCU | IMUs declared | Footprint 1 | Footprint 2 | Default gyro |",
        "|---|---|---|---|---|---|---|",
    ]
    for r in rows:
        out.append(
            "| `{}` | {} | {} | {} | {} | {} | {} |".format(
                r["board"],
                r["mfr"],
                r["mcu"],
                ", ".join(r["sensors"]) or "—",
                cell(r, 1),
                cell(r, 2),
                r["dflt"] or "—",
            )
        )
    return "\n".join(out) + "\n"


def render_csv(rows, summary, sensor):
    buf = io.StringIO()
    writer = csv.writer(buf, lineterminator="\n")
    writer.writerow(
        [
            "board", "manufacturer", "mcu", "imus", "footprints",
            "gyro1_spi", "gyro1_align", "gyro1_omitted",
            "gyro2_spi", "gyro2_align", "gyro2_omitted",
            "default_gyro", "path",
        ]
    )
    for r in rows:
        by_n = {f["n"]: f for f in r["fp"]}

        def field(n, key):
            return by_n[n][key] if n in by_n else ""

        writer.writerow(
            [
                r["board"], r["mfr"], r["mcu"], " ".join(r["sensors"]), len(r["fp"]),
                field(1, "spi"), field(1, "align"), field(1, "omitted"),
                field(2, "spi"), field(2, "align"), field(2, "omitted"),
                r["dflt"], r["path"],
            ]
        )
    return buf.getvalue()


def render_json(rows, summary, sensor):
    return json.dumps({"summary": summary, "boards": rows}, indent=2) + "\n"


HTML_TEMPLATE = r"""<title>__TITLE__</title>
<style>
:root{
  --bg:#e9edec; --panel:#ffffff; --panel-2:#f4f7f6; --line:#cdd6d4; --line-soft:#e0e7e5;
  --ink:#0f1917; --ink-2:#43524f; --ink-3:#6d7c79;
  --gold:#8a6210; --gold-bg:#f2e6cb; --gold-line:#d8bd7e;
  --flag:#9c3327;
  --shadow:0 1px 2px rgba(15,25,23,.06),0 8px 24px -18px rgba(15,25,23,.4);
}
@media (prefers-color-scheme:dark){
  :root{
    --bg:#0c1211; --panel:#141b1a; --panel-2:#101716; --line:#283331; --line-soft:#1d2726;
    --ink:#e3ebe9; --ink-2:#a3b1ae; --ink-3:#7c8a87;
    --gold:#d8a944; --gold-bg:#2c2311; --gold-line:#5b4820;
    --flag:#e08072;
    --shadow:0 1px 2px rgba(0,0,0,.5),0 8px 24px -18px rgba(0,0,0,.9);
  }
}
:root[data-theme="dark"]{
  --bg:#0c1211; --panel:#141b1a; --panel-2:#101716; --line:#283331; --line-soft:#1d2726;
  --ink:#e3ebe9; --ink-2:#a3b1ae; --ink-3:#7c8a87;
  --gold:#d8a944; --gold-bg:#2c2311; --gold-line:#5b4820;
  --flag:#e08072;
  --shadow:0 1px 2px rgba(0,0,0,.5),0 8px 24px -18px rgba(0,0,0,.9);
}
:root[data-theme="light"]{
  --bg:#e9edec; --panel:#ffffff; --panel-2:#f4f7f6; --line:#cdd6d4; --line-soft:#e0e7e5;
  --ink:#0f1917; --ink-2:#43524f; --ink-3:#6d7c79;
  --gold:#8a6210; --gold-bg:#f2e6cb; --gold-line:#d8bd7e;
  --flag:#9c3327;
  --shadow:0 1px 2px rgba(15,25,23,.06),0 8px 24px -18px rgba(15,25,23,.4);
}
*{box-sizing:border-box}
body{margin:0;background:var(--bg);color:var(--ink);
  font:400 14px/1.5 ui-monospace,"JetBrains Mono","SF Mono",Menlo,Consolas,monospace;
  font-variant-numeric:tabular-nums;-webkit-font-smoothing:antialiased}
.prose{font-family:system-ui,-apple-system,"Segoe UI",sans-serif}
.wrap{max-width:1280px;margin:0 auto;padding:40px 24px 80px;display:flex;flex-direction:column;gap:28px}
header{display:flex;flex-direction:column;gap:10px;border-bottom:1px solid var(--line);padding-bottom:24px}
.eyebrow{font-size:11px;letter-spacing:.16em;text-transform:uppercase;color:var(--ink-3)}
h1{margin:0;font-size:clamp(24px,4vw,34px);font-weight:600;letter-spacing:-.02em;text-wrap:balance}
h1 em{font-style:normal;color:var(--gold)}
.lede{margin:0;max-width:66ch;color:var(--ink-2);font-size:14px;line-height:1.65}
.src{display:flex;flex-wrap:wrap;gap:6px 18px;font-size:12px;color:var(--ink-3)}
.tiles{display:grid;grid-template-columns:repeat(auto-fit,minmax(170px,1fr));gap:1px;background:var(--line);
  border:1px solid var(--line);border-radius:3px;overflow:hidden;box-shadow:var(--shadow)}
.tile{background:var(--panel);padding:16px 18px;display:flex;flex-direction:column;gap:4px}
.tile b{font-size:28px;font-weight:600;letter-spacing:-.02em;line-height:1}
.tile span{font-size:11px;letter-spacing:.1em;text-transform:uppercase;color:var(--ink-3)}
.tile.warn b{color:var(--flag)}
.tile.mark b{color:var(--gold)}
.note{border:1px solid var(--line);border-left:3px solid var(--flag);background:var(--panel);
  border-radius:3px;padding:16px 18px;display:flex;flex-direction:column;gap:8px;box-shadow:var(--shadow)}
.note h2{margin:0;font-size:12px;letter-spacing:.14em;text-transform:uppercase;color:var(--flag)}
.note ul{margin:0;padding-left:18px;color:var(--ink-2);font-size:12px;line-height:1.8}
.note code{background:var(--panel-2);border:1px solid var(--line-soft);border-radius:2px;padding:0 4px}
.controls{position:sticky;top:0;z-index:20;background:var(--bg);padding:12px 0;
  display:flex;flex-wrap:wrap;gap:10px;align-items:center;border-bottom:1px solid var(--line)}
input[type=search],select{font:inherit;font-size:13px;color:var(--ink);background:var(--panel);
  border:1px solid var(--line);border-radius:3px;padding:8px 10px}
input[type=search]{flex:1 1 260px;min-width:0}
input[type=search]::placeholder{color:var(--ink-3)}
:focus-visible{outline:2px solid var(--gold);outline-offset:2px}
.toggle{font:inherit;font-size:12px;cursor:pointer;background:var(--panel);color:var(--ink-2);
  border:1px solid var(--line);border-radius:3px;padding:8px 12px;
  transition:background .12s,color .12s,border-color .12s}
.toggle:hover{border-color:var(--ink-3)}
.toggle[aria-pressed=true]{background:var(--gold-bg);border-color:var(--gold-line);color:var(--gold)}
.count{margin-left:auto;font-size:12px;color:var(--ink-3);white-space:nowrap}
.tablebox{border:1px solid var(--line);border-radius:3px;background:var(--panel);
  overflow-x:auto;box-shadow:var(--shadow)}
table{border-collapse:collapse;width:100%;min-width:1060px}
thead th{position:sticky;top:0;z-index:10;background:var(--panel-2);text-align:left;font-size:10px;
  letter-spacing:.13em;text-transform:uppercase;color:var(--ink-3);font-weight:500;
  padding:11px 14px;border-bottom:1px solid var(--line);white-space:nowrap}
thead th.sortable{cursor:pointer;user-select:none}
thead th.sortable:hover{color:var(--ink)}
thead th .dir{color:var(--gold);margin-left:4px}
tbody td{padding:11px 14px;border-bottom:1px solid var(--line-soft);vertical-align:top;font-size:13px}
tbody tr:last-child td{border-bottom:0}
tbody tr:hover{background:var(--panel-2)}
tbody tr.flagged td:first-child{box-shadow:inset 3px 0 0 var(--flag)}
.board{font-weight:600;letter-spacing:-.01em;white-space:nowrap}
.mfr{color:var(--ink-3);font-size:12px}
.mcu{color:var(--ink-2);font-size:12px;white-space:nowrap}
.dflt{font-size:11px;color:var(--ink-2);white-space:nowrap}
.dash{color:var(--ink-3)}
.chips{display:flex;flex-wrap:wrap;gap:4px}
.chip{font-size:11px;line-height:1;padding:4px 6px;border-radius:2px;border:1px solid var(--line);
  color:var(--ink-2);white-space:nowrap}
.chip.key{background:var(--gold-bg);border-color:var(--gold-line);color:var(--gold);font-weight:600}
.fp{display:flex;align-items:center;gap:9px;white-space:nowrap}
.fp .txt{display:flex;flex-direction:column;gap:2px}
.fp .a{font-size:12px}
.fp .b{font-size:10px;letter-spacing:.08em;text-transform:uppercase;color:var(--ink-3)}
.fp.imp .a{color:var(--ink-3);font-style:italic}
.fp.unbound .a{color:var(--flag);font-weight:600}
.gly{width:19px;height:19px;flex:none;border:1px solid var(--ink-3);border-radius:2px;
  position:relative;background:var(--panel-2)}
.gly::before{content:"";position:absolute;top:2.5px;left:2.5px;width:4px;height:4px;
  border-radius:50%;background:var(--gold)}
.gly::after{content:"";position:absolute;left:50%;top:5px;width:0;height:0;transform:translateX(-50%);
  border-left:3.5px solid transparent;border-right:3.5px solid transparent;border-bottom:6px solid var(--ink-2)}
.gly.flip{border-style:dashed}
.gly.flip::before{background:transparent;border:1px solid var(--gold)}
.gly.imp{border-color:var(--line);opacity:.55}
footer{color:var(--ink-3);font-size:12px;line-height:1.7;border-top:1px solid var(--line);padding-top:20px}
footer .legend{display:flex;flex-wrap:wrap;gap:8px 22px;align-items:center;margin-bottom:10px}
footer .li{display:flex;align-items:center;gap:8px}
@media (prefers-reduced-motion:reduce){*{transition:none!important;animation:none!important}}
</style>

<div class="wrap">
  <header>
    <div class="eyebrow">betaflight / config — gyro inventory</div>
    <h1>__HEADING__</h1>
    <p class="lede prose">A board's IMU defines are a <em>menu</em>, not an assignment — the firmware probes
      each footprint at boot and binds whichever part answers. Alignment, by contrast, belongs to the
      footprint, so it is listed per <code>GYRO_n</code>.</p>
    <div class="src"><span>generated by scripts/gyro_report.py</span>
      <span>fallback rule: src/main/pg/gyrodev.c</span></div>
  </header>

  <div class="tiles">__TILES__</div>
  __NOTE__

  <div class="controls">
    <input type="search" id="q" placeholder="Filter board, manufacturer, MCU or IMU…" aria-label="Filter boards">
    <select id="mcu" aria-label="Filter by MCU"><option value="">All MCUs</option>__MCUOPTS__</select>
    <select id="sensor" aria-label="Filter by IMU"><option value="">Any IMU</option>__SOPTS__</select>
    <button class="toggle" id="tDual" aria-pressed="false">Dual footprint</button>
    <button class="toggle" id="tImp" aria-pressed="false">CW0 implicit</button>
    <button class="toggle" id="tSolo" aria-pressed="false">Single IMU</button>
    <span class="count" id="count"></span>
  </div>

  <div class="tablebox">
    <table>
      <thead><tr>
        <th class="sortable" data-k="board">Board</th>
        <th class="sortable" data-k="mfr">Mfr</th>
        <th class="sortable" data-k="mcu">MCU</th>
        <th>IMUs declared</th>
        <th>Footprint 1 — GYRO_1</th>
        <th>Footprint 2 — GYRO_2</th>
        <th class="sortable" data-k="dflt">Default</th>
      </tr></thead>
      <tbody id="tb"></tbody>
    </table>
  </div>

  <footer>
    <div class="legend">
      <span class="li"><span class="gly"></span> CW0_DEG — dot marks pin 1, box rotates with the alignment</span>
      <span class="li"><span class="gly flip"></span> _FLIP — dashed box, hollow pin, chip is on the underside</span>
      <span class="li"><span class="gly imp"></span> GYRO_n_ALIGN omitted — CW0_DEG by convention</span>
    </div>
    Alignment is resolved through macro indirection where a config aliases it
    (<code>GYRO_1_ALIGN&nbsp;→&nbsp;ICM42688P_ALIGN&nbsp;→&nbsp;CW180_DEG</code>).
    ALIGN_CUSTOM entries carry their roll/pitch/yaw degrees inline.
  </footer>
</div>

<script>
const DATA = __DATA__, KEY = __KEY__, FLAGGED = new Set(__FLAGGED__);
const tb = document.getElementById('tb'), count = document.getElementById('count');
const q = document.getElementById('q'), mcuSel = document.getElementById('mcu');
const sSel = document.getElementById('sensor');
const toggles = {dual: document.getElementById('tDual'), imp: document.getElementById('tImp'),
                 solo: document.getElementById('tSolo')};
let sortKey = 'board', sortDir = 1;

const ROT = {CW0_DEG:0, CW90_DEG:90, CW180_DEG:180, CW270_DEG:270,
             CW0_DEG_FLIP:0, CW90_DEG_FLIP:90, CW180_DEG_FLIP:180, CW270_DEG_FLIP:270};
const esc = s => String(s).replace(/[&<>"]/g, c => ({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;'}[c]));

function glyph(f){
  const base = f.align.split(' ')[0], deg = ROT[base], cls = ['gly'];
  if (base.endsWith('_FLIP')) cls.push('flip');
  if (f.omitted) cls.push('imp');
  const style = deg === undefined ? '' : ` style="transform:rotate(${deg}deg)"`;
  const title = deg === undefined ? f.align : `${f.align} — ${deg}° clockwise`;
  return `<span class="${cls.join(' ')}"${style} title="${esc(title)}" aria-hidden="true"></span>`;
}

function fpCell(r, n){
  const f = r.fp.find(x => x.n === n);
  if (!f) return '<span class="dash">—</span>';
  if (!f.bound){
    const missing = f.spi === '-' ? 'no SPI instance' : 'no CS pin';
    return `<span class="fp unbound"><span class="txt">` +
      `<span class="a">unbound</span><span class="b">${missing}</span></span></span>`;
  }
  const label = f.align + (f.omitted ? ' (default)' : '');
  return `<span class="fp${f.omitted ? ' imp' : ''}">${glyph(f)}<span class="txt">` +
    `<span class="a">${esc(label)}</span><span class="b">${esc(f.spi)}</span></span></span>`;
}

function matches(r){
  const term = q.value.trim().toLowerCase();
  const hay = (r.board + ' ' + r.mfr + ' ' + r.mcu + ' ' + r.sensors.join(' ')).toLowerCase();
  if (term && !hay.includes(term)) return false;
  if (mcuSel.value && r.mcu !== mcuSel.value) return false;
  if (sSel.value && !r.sensors.includes(sSel.value)) return false;
  if (toggles.dual.getAttribute('aria-pressed') === 'true' && !r.dual) return false;
  if (toggles.imp.getAttribute('aria-pressed') === 'true' && !r.anyomitted) return false;
  if (toggles.solo.getAttribute('aria-pressed') === 'true' && r.sensors.length > 1) return false;
  return true;
}

function render(){
  const rows = DATA.filter(matches).sort((a, b) =>
    sortDir * String(a[sortKey]).localeCompare(String(b[sortKey])) || a.board.localeCompare(b.board));
  tb.innerHTML = rows.map(r => `<tr class="${FLAGGED.has(r.board) ? 'flagged' : ''}">
    <td class="board">${esc(r.board)}</td>
    <td class="mfr">${esc(r.mfr)}</td>
    <td class="mcu">${esc(r.mcu)}</td>
    <td><span class="chips">${r.sensors.map(s =>
      `<span class="chip${s === KEY ? ' key' : ''}">${esc(s)}</span>`).join('')}</span></td>
    <td>${fpCell(r, 1)}</td>
    <td>${fpCell(r, 2)}</td>
    <td class="dflt">${r.dflt ? esc(r.dflt) : '<span class="dash">—</span>'}</td>
  </tr>`).join('');
  count.textContent = `${rows.length} of ${DATA.length} boards`;
  document.querySelectorAll('thead th.sortable').forEach(th => {
    const on = th.dataset.k === sortKey;
    th.innerHTML = th.textContent.replace(/[↑↓]\s*$/, '').trim() +
      (on ? ` <span class="dir">${sortDir > 0 ? '↑' : '↓'}</span>` : '');
  });
}

document.querySelectorAll('thead th.sortable').forEach(th => th.addEventListener('click', () => {
  const k = th.dataset.k;
  if (k === sortKey) sortDir = -sortDir; else { sortKey = k; sortDir = 1; }
  render();
}));
Object.values(toggles).forEach(b => b.addEventListener('click', () => {
  b.setAttribute('aria-pressed', b.getAttribute('aria-pressed') === 'true' ? 'false' : 'true');
  render();
}));
[q, mcuSel, sSel].forEach(el => el.addEventListener('input', render));
render();
</script>
"""


def render_html(rows, summary, sensor, findings=()):
    key = summary["sensor"]
    safe_key = html.escape(key) if key else None
    heading = (
        f"Boards declaring <em>{safe_key}</em>, their alternate IMUs, "
        f"and per-footprint alignment"
        if key
        else "Gyro footprints and alignment across every <em>config.h</em>"
    )
    title = (
        f"{safe_key} boards — Betaflight config" if key else "Gyro inventory — Betaflight config"
    )

    tiles = [
        ("", summary["boards"], "Boards" + (f" with {key}" if key else " with an IMU")),
        ("", summary["manufacturers"], "Manufacturers"),
        ("mark", summary["single_sensor"], "Declare a single IMU"),
        ("", summary["dual_footprint"], "Two bound footprints"),
        ("", summary["omitted_alignment"], "CW0 left implicit"),
        ("warn", summary["unbound_footprint"], "Have an unbound position"),
    ]
    tiles_html = "".join(
        f'<div class="tile {c}"><b>{v}</b><span>{label}</span></div>' for c, v, label in tiles
    )

    note_html = ""
    if findings:
        by_board = {}
        for severity, board, code, message in findings:
            by_board.setdefault(board.name, []).append((severity, code, message))
        items = "".join(
            f"<li><code>{html.escape(name)}</code> — {html.escape(msgs[0][2])}</li>"
            for name, msgs in sorted(by_board.items())[:20]
        )
        extra = ""
        if len(by_board) > 20:
            extra = f"<li>… and {len(by_board) - 20} more, see <code>--check</code></li>"
        note_html = (
            f'<div class="note"><h2>{len(findings)} findings across '
            f"{len(by_board)} boards</h2><ul>{items}{extra}</ul></div>"
        )

    flagged = sorted({b.name for _, b, _, _ in findings})
    mcus = sorted({r["mcu"] for r in rows if r["mcu"]})
    sensors = sorted({s for r in rows for s in r["sensors"]})

    return (
        HTML_TEMPLATE.replace("__DATA__", json.dumps(rows, separators=(",", ":")))
        .replace("__KEY__", json.dumps(key))
        .replace("__FLAGGED__", json.dumps(flagged))
        .replace("__TITLE__", title)
        .replace("__HEADING__", heading)
        .replace("__TILES__", tiles_html)
        .replace("__NOTE__", note_html)
        .replace("__MCUOPTS__", "".join(f"<option>{html.escape(m)}</option>" for m in mcus))
        .replace("__SOPTS__", "".join(f"<option>{html.escape(x)}</option>" for x in sensors))
    )


RENDERERS = {"md": render_md, "csv": render_csv, "json": render_json, "html": render_html}


# --------------------------------------------------------------------------
# cli
# --------------------------------------------------------------------------

def default_config_dir():
    return os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "configs")


def main(argv=None):
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("-c", "--config-dir", default=default_config_dir(),
                        help="directory holding the board configs (default: ./configs)")
    parser.add_argument("-s", "--sensor",
                        help="only report boards declaring this part, e.g. BMI270")
    parser.add_argument("-f", "--format", choices=sorted(RENDERERS), default="md",
                        help="report format (default: md)")
    parser.add_argument("-o", "--output", help="write to a file instead of stdout")
    parser.add_argument("--check", action="store_true",
                        help="lint the configs and exit non-zero on errors")
    parser.add_argument("--strict", action="store_true",
                        help="with --check, fail on warnings too")
    parser.add_argument("--list-sensors", action="store_true",
                        help="list every IMU part declared, with board counts")
    args = parser.parse_args(argv)

    if not os.path.isdir(args.config_dir):
        parser.error(f"no such directory: {args.config_dir}")

    if args.check:
        boards = collect(args.config_dir)
        findings = run_checks(boards)
        for severity, board, code, message in findings:
            print(f"{board.relpath}: {severity}: [{code}] {board.name}: {message}")
        errors = sum(1 for f in findings if f[0] == "error")
        warnings = len(findings) - errors
        print(
            f"\n{errors} error(s), {warnings} warning(s) in {len(boards)} configs",
            file=sys.stderr,
        )
        return 1 if errors or (args.strict and warnings) else 0

    if args.list_sensors:
        boards = collect(args.config_dir)
        counts = Counter(s for b in boards for s in b.sensors)
        width = max(len(s) for s in counts) if counts else 0
        for part, n in sorted(counts.items(), key=lambda kv: (-kv[1], kv[0])):
            print(f"{part:<{width}}  {n}")
        return 0

    boards = collect(args.config_dir, args.sensor)
    if args.sensor and not boards:
        parser.error(f"no board declares {args.sensor.upper()}; try --list-sensors")

    summary = summarise(boards, args.sensor)
    rows = board_rows(boards, args.sensor)

    if args.format == "html":
        text = render_html(rows, summary, args.sensor, run_checks(boards))
    else:
        text = RENDERERS[args.format](rows, summary, args.sensor)

    if args.output:
        with open(args.output, "w", encoding="utf-8") as handle:
            handle.write(text)
        print(
            f"{summary['boards']} boards, {summary['manufacturers']} manufacturers "
            f"-> {args.output}",
            file=sys.stderr,
        )
    else:
        sys.stdout.write(text)
    return 0


if __name__ == "__main__":
    sys.exit(main())
