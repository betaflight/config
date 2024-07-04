# Target Configuration (config.h) repository

Repository for the storage of config.h files for board settings. For more information please see https://betaflight.com

The config.h replaces the unified target configuration that is now deprecated from version 4.5.0. This frees up some flash space, and ensures defaults are baked into the build. This has been made possible due to the introduction of the cloud build service. Standard default targets are still available, but they require all configuration to be restored from a backup.

Cloud build takes care of the config repository for the general user, and knowledge of it is generally not needed. The instructions here are predominantly for tinkerers and for manufacturers around creating a target.

## NOTICE

For a target to be successfully approved it **must** adhere to both https://betaflight.com/docs/development/manufacturer/requirements-for-submission-of-targets AND https://betaflight.com/docs/development/manufacturer/config-target-guidance.

Pull-Requests for config submission should only be from a custom branch, and not `master` directly.

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

### TIMER_MAP

The `TIMER_MAP` define sets up the timers default settings, as adjusted with the `timer` and `dma` commands in CLI. The problem is there are some magic numbers (index entries), that need to be known.

You can activate the `timer map` CLI command (by compiling with `USE_TIMER_MAP_PRINT` defined i.e. `"EXTRA_FLAGS=-DUSE_TIMER_MAP_PRINT"`).

You will need to setup (again using CLI commands) what your default `timer` and `dma` should be. You can then run the `timer map` command and it will output the correct values for inserting into the config.h file.

