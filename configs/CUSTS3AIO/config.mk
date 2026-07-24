# CUSTS3AIO uses an ESP32-S3-MINI-1-N4R2 module: 4 MB flash (2 MB PSRAM unused).
# Override the 8 MB ESP32S3 default so the app image, the merged full image and
# the from-source bootloader header are all built for 4 MB. Included before
# target.mk / ESP32S3.mk (see mk/config.mk), which set MCU_FLASH_SIZE with ?=.
MCU_FLASH_SIZE := 4096
