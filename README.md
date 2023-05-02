# config repository

Repository for the storage of config.h files for board settings.

## Version Comments (simple rules engine)

The file can include comments that will be utilised by the https://build.betaflight.com API so as to produce a unique file for a given version as requested by the Makefile when a user begins a build.

Version comment details are as follows:

`// version <= 4.1.0`

all subsequent lines (until next rule is hit) are included for any version request less than or equal to 4.4.1

`// version == 4.5.0`

all subsequent lines (until next rule is hit) are included for version 4.5.0

`// version >= 4.5.0`

all subsequent lines (until next rule is hit) are included for any version request greater than or equal to 4.5.0

## How to use - Firmware

The repository cannot be used directly (unless you get fancy with SYM LINKS). The reason is it needs the API to interpret the config files, and return content based on the requested version (see the version rules above). The structure is also slightly different in the repository as the board name directories include the manufacturer code (similar to the unified targets repository).

You need to hydrate the target list first with:

```
> make configs
```

Let's say the current version.h file has the version 4.5.0 in it. Then when you make a build for a specific target configuration e.g. `make BETAFLIGHTF4` the make file will create `./src/config/4.5.0/BETAFLIGHTF4/` and download the `config.h` file from the API (passing the version and the board as required). The API will produce a `config.h` based on the content rules described above.

