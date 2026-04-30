# STM32N6570-DK config — pulls in the LTDC panel backend for the LCD console.
# Path is resolved against VPATH (which includes $(PLATFORM_DIR) i.e.
# src/platform), so this expands to src/platform/STM32/lcd_ltdc_n6.c.
TARGET_SRC += STM32/lcd_ltdc_n6.c
