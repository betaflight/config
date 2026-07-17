# It's possibile to set makefile definitions here.
# Originally used to help configure linker scripts for flash size and font allocation. See also pico_flash_mem.ld in this folder.

MCU_FLASH_SIZE = 4096
# 4194304 = 4 * 1024 * 1024
TARGET_DEVICE_FLAGS  = \
                   -DPICO_FLASH_SPI_CLKDIV=2 \
                   -DPICO_FLASH_SIZE_BYTES=4194304 \
                   -DPICO_BOOT_STAGE2_CHOOSE_W25Q080=1
