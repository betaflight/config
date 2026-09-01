# scripts

Python 3, standard library only. No build step, no dependencies.

## gyro_report.py

Reports and lints the gyro/accelerometer declarations across `configs/`.

### Model

A config declares a **menu** of IMU parts, not an assignment. `USE_ACCGYRO_BMI270`
alongside `USE_GYRO_SPI_ICM42688P` means either part may be fitted; the firmware
probes each gyro position at boot and binds whichever answers. The part list
therefore belongs to the board, while alignment belongs to the position, and the
reports keep them in separate columns.

Four rules govern how a `config.h` is interpreted:

- **Absent `GYRO_n_ALIGN` means `CW0_DEG`** (`src/main/pg/gyrodev.c`). Omitting it
  is how that orientation is normally written. Reports show the effective
  alignment either way and tag it `(default)` where it was omitted; the lint does
  not flag it, since nothing in a config separates a position that is genuinely
  `CW0_DEG` from one where the value was forgotten.
- **`GYRO_COUNT` keys on `GYRO_n_CS_PIN`, not `GYRO_n_SPI_INSTANCE`**
  (`src/main/target/common_pre.h`). A position needs both to be compiled in. With
  one of the two it is **unbound**, and which half is missing determines the
  consequence — see `footprint-not-bound` and `spi-without-cs` below.
- **`GYRO_n_CS_PIN NONE` marks a position as unpopulated** and is read as absent.
- **Macro aliases are resolved**, so `GYRO_1_ALIGN` → `ICM42688P_ALIGN` →
  `CW180_DEG` reports as `CW180_DEG`.

Preprocessor conditionals are not evaluated; every `#define` is read at face
value. The `conditional-gyro-define` check guards that assumption.

### Reports

```sh
./scripts/gyro_report.py --sensor BMI270                  # markdown to stdout
./scripts/gyro_report.py --sensor LSM6DSK320X -f csv
./scripts/gyro_report.py -f html -o gyro.html             # every board, browsable
./scripts/gyro_report.py -f json | jq '.summary'
./scripts/gyro_report.py --list-sensors                   # parts, with board counts
```

Formats are `md` (default), `csv`, `json` and `html`. The HTML build is a single
self-contained file — sortable, filterable, light/dark aware, no network access —
and folds the lint findings in as a banner.

`-o/--output` writes to a file and prints a one-line summary to stderr, keeping
the report itself pipeable. `--sensor` matches case-insensitively against the
part names from `--list-sensors`.

### Lint

```sh
./scripts/gyro_report.py --check            # exit 1 on any error
./scripts/gyro_report.py --check --strict   # exit 1 on warnings too
```

One `path: severity: [code] board: message` line per finding.

| Code | Severity | Meaning |
|---|---|---|
| `footprint-not-bound` | error | `GYRO_n_CS_PIN` without `GYRO_n_SPI_INSTANCE`. `GYRO_COUNT` counts the position, but `gyrodev.c` leaves it `BUS_TYPE_NONE`, so the gyro can never be detected. |
| `default-gyro-missing-footprint` | error | `DEFAULT_GYRO_TO_USE` names `GYRO_2`/`BOTH` on a board with no second position. |
| `sensor-without-footprint` | error | An IMU part is declared but no `GYRO_n` position exists. Skipped for `USE_I2C_GYRO` boards, which need no CS pin. |
| `align-without-footprint` | error | `GYRO_n_ALIGN` on a position with neither a CS pin nor an SPI instance. |
| `custom-align-without-degrees` | error | `ALIGN_CUSTOM` with no `GYRO_n_ALIGN_ROLL/PITCH/YAW`, which silently means identity. |
| `degrees-without-custom-align` | error | `GYRO_n_ALIGN_ROLL/PITCH/YAW` set while `GYRO_n_ALIGN` is a standard alignment. The firmware `#error`s on this. |
| `unresolved-align` | error | `GYRO_n_ALIGN` resolves to something that is not a `sensor_align_e` value. |
| `acc-gyro-pair-mismatch` | error | `USE_GYRO_SPI_x` without `USE_ACC_SPI_x`, or the reverse. |
| `spi-without-cs` | warning | `GYRO_n_SPI_INSTANCE` without `GYRO_n_CS_PIN`. `GYRO_COUNT` never counts the position, so the define is inert and can be removed. |
| `conditional-gyro-define` | warning | A gyro/acc define sits inside an `#if`/`#ifdef` and is reported at face value. |

### CI

Add to `.github/workflows/pr.yml` once `--check` passes:

```yaml
  lint_gyro:
    name: Lint gyro configuration
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v5
      - run: ./scripts/gyro_report.py --check
```

### Options

```text
-c, --config-dir DIR   directory holding the board configs (default: ./configs)
-s, --sensor NAME      only report boards declaring this part
-f, --format FORMAT    md | csv | json | html   (default: md)
-o, --output FILE      write to a file instead of stdout
    --check            lint instead of reporting; exit non-zero on errors
    --strict           with --check, fail on warnings too
    --list-sensors     list every IMU part declared, with board counts
```

Both `configs/<MFR>/<BOARD>/config.h` and flat `configs/<BOARD>/config.h` layouts
are discovered.
