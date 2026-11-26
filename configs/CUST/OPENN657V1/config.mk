# Boot flash chip on OPENN657V1 is Macronix MX66UW1G45G (1 Gbit octal NOR).
# The OpenBootloader leaves it in 1S-1S-1S mode for BF; flash.c uses
# build-time selection (OCTOSPI_FLASH_CHIP_<chip>) because the chip
# cannot answer 1/4-line JEDEC RDID while configured for OPI.
OCTOSPI_FLASH_CHIP := MX66UW1G45G
