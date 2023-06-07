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


