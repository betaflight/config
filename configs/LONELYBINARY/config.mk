# The "lonely binary" dev board carries a 16 MB flash module (confirmed by
# esptool flash_id). Override the 8 MB ESP32S3 default; target.mk / ESP32S3.mk
# use ?= so this config.mk value (included first) wins. See mk/config.mk.
MCU_FLASH_SIZE := 16384
