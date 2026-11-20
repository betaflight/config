# Flash size and font allocation. See also pico_flash_mem.ld in this folder.

# Override MCU_FLASH_SIZE (W25Q64JV)
TARGET_FLASH_SIZE = 8192

# For pico-sdk, define flash-related attributes
# 8388608 = 8 * 1024 * 1024
PICO_FLASH_DEFINES = \
                   -DPICO_FLASH_SPI_CLKDIV=2 \
                   -DPICO_FLASH_SIZE_BYTES=8388608 \
                   -DPICO_BOOT_STAGE2_CHOOSE_W25Q080=1
