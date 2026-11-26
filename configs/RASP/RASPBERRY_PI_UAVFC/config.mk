# It's possibile to set makefile definitions here.
# Originally used to help configure linker scripts for flash size and font allocation. See also pico_flash_mem.ld in this folder.

# Override MCU_FLASH_SIZE
TARGET_FLASH_SIZE = 4096

# For pico-sdk, define flash-related attributes
# 4194304 = 4 * 1024 * 1024
PICO_FLASH_DEFINES = \
                   -DPICO_FLASH_SPI_CLKDIV=2 \
                   -DPICO_FLASH_SIZE_BYTES=4194304 \
                   -DPICO_BOOT_STAGE2_CHOOSE_W25Q080=1
