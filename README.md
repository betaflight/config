# Target Configuration (config.h) repository

Repository for the storage of config.h files for default board settings. For more information please see https://betaflight.com

The config.h replaces the unified target configuration that is now deprecated from version 4.5.0. This frees up some flash space, and ensures defaults are baked into the build. This has been made possible due to the introduction of the cloud build service. Standard default targets are still available where possible, but they require all configuration to be restored from a backup.

Cloud build takes care of the config repository for the general user, and knowledge of it is generally not needed. The instructions here are predominantly for tinkerers, and for community and manufacturers creating and supporting targets.

## NOTICE

For a target to be considered supported it **must** adhere to both:
1. https://betaflight.com/docs/development/manufacturer/requirements-for-submission-of-targets
-- AND --
2. https://betaflight.com/docs/development/manufacturer/config-target-guidance.

In addition pull requests for config submission, or updates, should only be from a custom branch, and not `master` directly. PRs will be automatically closed that do not adhere to this.

## How to use - Firmware

The config repository will be used directly by the firmware, and is only required if you wish to use one of the targets present here when building locally.

You need to hydrate the target list first with:

```
> make configs
```

Then you can make a build for a specific target configuration e.g.
```
> make BETAFLIGHTF4
```

## Creating a config.h for a target

A `config.h` is a plain C header (`#pragma once`) that bakes a board's default settings into the firmware build. At minimum it identifies the MCU and the board; everything else (sensors, pin assignments, timers, default tuning) follows the usual `USE_*` and pin `#define` conventions used throughout the firmware. Look at any existing entry under `configs/` for a representative example.

### Required defines

Every config **must** declare these three — both the firmware build and the cloud build API derive the target's identity from them:

| Define | Purpose |
| --- | --- |
| `FC_TARGET_MCU` | MCU family/type. The build derives `TARGET` from this and fails if it is missing or unparseable. |
| `BOARD_NAME` | Unique board name. Must match the config's directory name under `configs/`. |
| `MANUFACTURER_ID` | Four-letter manufacturer code (see `Manufacturers.md`). |

### Common optional defines

| Define | Purpose |
| --- | --- |
| `SYSTEM_HSE_MHZ` | External oscillator frequency in MHz; sets `HSE_VALUE` for the clock tree. Required on boards with an HSE crystal, omit for boards running off the internal oscillator. |
| `FC_VMA_ADDRESS` | Sets the load/run (VMA) address. Its presence switches the build to an EXST (bootloader-relocated) image. Rare. |
| `TIMER_PIN_MAPPING` | Per-pin timer/DMA assignment (see [TIMER_MAP](#timer_map) below). |

Beyond these, add the device `USE_*` flags and pin `#define`s for the sensors, OSD, flash, motors, etc. fitted to the board.

### Supported-target header (REFERENCE / DATE / VERSION)

The cloud build API reads a comment block — placed after the GPL header and before `#pragma once` — to mark a target as officially supported and to gate which firmware releases it is offered for.
The directive lines are parsed by splitting on whitespace, so the first non-whitespace token on each directive line must be the keyword (do not prefix the lines with `*`):
```
/*
    SUPPORTED TARGET - THANK YOU
    REFERENCE: sha256_98b7e664d2f1544c315aec575140e68e4d89bebde9ec11222c8eaf63b018d4fa
    DATE: 2025-01-01
    VERSION: 4.6.0
*/
```

| Field | Meaning |
| --- | --- |
| `REFERENCE:` | A `sha256_…` hash that marks the target as **reviewed and supported by the Betaflight team**, as opposed to merely community-supported. The Betaflight team provides this value to the manufacturer/contributor once a target has been reviewed (it is generated internally and the mechanism is not public — you cannot compute it yourself). It is validated against the (upper-cased) `BOARD_NAME`; if it is absent or does not match, the target is not flagged as team-supported. |
| `DATE:` | Reference date (`YYYY-MM-DD`). The target is **excluded** from any release published *prior* to this date, so a new board does not appear against older releases that never supported it. |
| `VERSION:` | The first firmware version the target is valid for. Releases **prior** to this version are never offered for the target, irrespective of `DATE:`. |
| `GROUP:` | Categorises the target. `SUPPORTED` is the implicit default; `LEGACY` flags an older/deprecated board so it is grouped (and sorted) separately in the configurator's target list. A legacy target is not team-supported, so it carries no `REFERENCE:` and the `GROUP:` directive may stand alone in its own comment block — see the `REVO` target (`GROUP: LEGACY`). |

`REFERENCE:` together with a non-empty `BOARD_NAME` are required for the supported marking to take effect; `DATE:`, `VERSION:` and `GROUP:` are optional. (The API recognises `WIKI:` and `URL:` directives in the same block as well.)

### config.c (optional)

If a `config.c` sits alongside `config.h`, it is compiled into the build and `USE_CONFIG_SOURCE` is defined. Use it for configuration logic that cannot be expressed as plain `#define`s.

### config.mk (optional)

A per-config `config.mk` lets a target inject build-system (make) variables that a `config.h` cannot express. It is `-include`d by the firmware build (`mk/config.mk`) when present — before the target makefiles — so it can set or override build flags. It is optional, and only a small number of targets need one; most are fully described by `config.h` alone.

The currently recognised setting is `OCTOSPI_FLASH_CHIP`, which selects the boot/config flash chip wired to the OCTOSPI/XSPI peripheral. It emits both `-DUSE_FLASH_<chip>` (driver gating) and `-DOCTOSPI_FLASH_CHIP_<chip>` (build-time chip selection). The build-time selection is needed for chips that cannot be probed via JEDEC RDID at runtime — for example a chip left in 8-line OPI mode by the bootloader.

Example — `configs/OPENN657V1/config.mk`:

```
# Boot flash chip on OPENN657V1 is Macronix MX66UW1G45G (1 Gbit octal NOR).
# The OpenBootloader leaves it in 1S-1S-1S mode for BF; flash.c uses
# build-time selection (OCTOSPI_FLASH_CHIP_<chip>) because the chip
# cannot answer 1/4-line JEDEC RDID while configured for OPI.
OCTOSPI_FLASH_CHIP := MX66UW1G45G
```

### TIMER_MAP

For those targets that require it (e.g. STM32), the `TIMER_MAP` define sets up the timers default settings, as adjusted with the `timer` and `dma` commands in CLI. The problem is there are some magic numbers (index entries), that need to be known.

You can activate the `timer map` CLI command (by compiling with `USE_TIMER_MAP_PRINT` defined i.e. `"EXTRA_FLAGS=-DUSE_TIMER_MAP_PRINT"`).

You will need to setup (again using CLI commands) what your default `timer` and `dma` should be. You can then run the `timer map` command and it will output the correct values for inserting into the config.h file.

