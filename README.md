# Target Configuration (config.h) repository

Repository for the storage of config.h files for board settings.

## How to use - Firmware

The config repository will be used directly by the firmware.

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

The TIMER_MAP define sets up the timers default settings, as adjusted but the `timer` and `dma` commands in CLI. The problem is there are some magic numbers (index entries), that need to be known.
 
You can activate the `timer map` CLI command (by compiling with `USE_TIMER_MAP_PRINT` defined i.e. `"EXTRA_FLAGS=-DUSE_TIMER_MAP_PRINT"`).

You will need to setup (again in CLI) what your default `timer` and `dma` should be. You can then run the `timer map` command and it will output the correct values for inserting into the config.h file.

