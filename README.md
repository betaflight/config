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

