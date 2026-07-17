/*
 * This file is part of Betaflight.
 *
 * Betaflight is free software. You can redistribute this software
 * and/or modify this software under the terms of the GNU General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later
 * version.
 *
 * Betaflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define FC_TARGET_MCU     RP2350B
#define BOARD_NAME        RASPBERRY_PI_UAVFC
#define MANUFACTURER_ID   RASP

#define USE_GYRO
#define USE_ACC
#define USE_ACCGYRO_ICM56686
#define USE_GYRO_SPI_ICM56686
#define USE_ACC_SPI_ICM56686
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define GYRO_1_SPI_INSTANCE  SPI0

#define USE_SDCARD
#define SDCARD_SPI_INSTANCE  SPI1

#ifdef PICO_TRACE
// For debugging (trace) via UART, make with env var PICO_TRACE set (see RP2350.mk).
#if 1
// uart0 via LED connector (J2)
#define PICO_TRACE_UART_INSTANCE  0
#define PICO_TRACE_TX_GPIO       2 // J2 (LED connector) 3 of 3
#define PICO_TRACE_RX_GPIO       4 // not connected
#else
// uart1 via Radio "UART2" connector
#define PICO_TRACE_UART_INSTANCE  1
#define PICO_TRACE_TX_GPIO       42
#define PICO_TRACE_RX_GPIO       4 // not connected
#endif
#endif

#define MOTOR1_PIN           PA6
#define MOTOR2_PIN           PA7
#define MOTOR3_PIN           PA8
#define MOTOR4_PIN           PA9

#define LED0_PIN             PA0
#define LED1_PIN             PA1

#define SPI0_SCK_PIN         PA34
#define SPI0_SDI_PIN         PA32
#define SPI0_SDO_PIN         PA35

#define SPI1_SCK_PIN         PA30
#define SPI1_SDI_PIN         PA28
#define SPI1_SDO_PIN         PA31
#define SDCARD_SPI_CS_PIN    PA29

#define GYRO_1_CS_PIN        PA33
#define GYRO_1_EXTI_PIN      PA26

#define GYRO_2_CS_PIN        NONE

#if !defined(PICO_TRACE_UART_INSTANCE) || PICO_TRACE_UART_INSTANCE != 0
#define UART0_TX_PIN         PA44
#define UART0_RX_PIN         PA45
#endif

#if !defined(PICO_TRACE_UART_INSTANCE) || PICO_TRACE_UART_INSTANCE != 1
#if 0
// UART1 spare, could be GPS
#define UART1_TX_PIN         PA36
#define UART1_RX_PIN         PA37
#else
// or Radio RX
#define UART1_TX_PIN         PA42
#define UART1_RX_PIN         PA43
#endif
#endif

// PIOUART0 spare
#if !ENABLE_FB_OSD
#define PIOUART0_TX_PIN      PA22
#define PIOUART0_RX_PIN      PA23
#endif

// PIOUART1 spare, could be e.g. AVTX or GPS
#if 0
#define PIOUART1_TX_PIN      PA16
#define PIOUART1_RX_PIN      PA17
#else
#define PIOUART1_TX_PIN      PA36
#define PIOUART1_RX_PIN      PA37
#endif

#define USE_BARO
// DPS368 same drivers as for DPS310
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE    I2CDEV_0
#define I2C0_SDA_PIN         PA24
#define I2C0_SCL_PIN         PA25

#define USE_MAG
#define MAG_I2C_INSTANCE     I2CDEV_1

// I2C1, could be GPS (Magnetemometer/Compass)
#define I2C1_SDA_PIN         PA38
#define I2C1_SCL_PIN         PA39

#define USE_BEEPER
#define BEEPER_PWM_HZ        1971
#define BEEPER_PIN           PA3

#ifndef PICO_BEC_ENABLE_NONINVERTED
#define PICO_BEC_ENABLE_NONINVERTED 1
#endif
#define PICO_BEC_5V_ENABLE_PIN PA18
#define PICO_BEC_9V_ENABLE_PIN PA19

#define ADC_VBAT_PIN         PA46
#define ADC_CURR_PIN         PA47
#define ADC_RSSI_PIN         PA40

// In this config file, we choose between support for LED STRIP or FB OSD (both require a PIO block)
#ifndef ENABLE_FB_OSD
// Set the default behaviour
// #define ENABLE_FB_OSD        0
#define ENABLE_FB_OSD        1
#endif

#if ENABLE_FB_OSD
// ENABLE_FB_OSD not LED STRIP

#ifndef USE_OSD_SD
#define USE_OSD_SD
#endif

// undef USE_MSP_DISPLAYPORT in target.h, would be better to migrate to ENABLE_MSP_DISPLAYPORT then set ENABLE to 0 here
#define REMOVE_MSP_DISPLAYPORT

// OSD_EN_PIN must be next GPIO up from OSD_W_PIN
// and OSD_SYNC_PIN next up from OSD_EN_PIN
#define OSD_W_PIN            PA21
#define OSD_EN_PIN           PA22
#define OSD_SYNC_PIN         PA23

// Save space by leaving font in FLASH, don't copy to RAM
#define OSD_FB_PICO_FLASH_FONT

#ifdef PICO_TRACE
#define DEBUG_OSD_FB_PICO
#endif

// Allow to set,get osd_canvas_width,height in cli
#define OSD_CANVAS_SIZE_DEBUG

// Trade off speed for space, for static elements
// #define PICO_OSD_USE_BACKGROUND_BUFFER

#ifndef OSD_FB_PICO_ENABLE_PIXEL_MODE
// Default is to enable pixel-based elements
#define OSD_FB_PICO_ENABLE_PIXEL_MODE 1

// Alternative is to reproduce MAX7456-like purely character-based display
// #define OSD_FB_PICO_ENABLE_PIXEL_MODE 0
#endif

#if OSD_FB_PICO_ENABLE_PIXEL_MODE
// Bring in pixel-based elements

// These default to enabled, can disable here
// #define OSD_FB_ELEMENT_ENABLE_ARTIFICIAL_HORIZON  0
// #define OSD_FB_ELEMENT_ENABLE_ALTITUDE            0

// Post process to add black borders
// #define OSD_FB_PICO_POSTPROCESS 0 // None
// #define OSD_FB_PICO_POSTPROCESS 1 // One pixel left and right (not across word boundaries)
#define OSD_FB_PICO_POSTPROCESS 2 // One pixel left and right, one above and below
// #define OSD_FB_PICO_POSTPROCESS 3 // Two pixels left, right, one above below
// #define OSD_FB_PICO_POSTPROCESS 6 // One pixel left, right, up, down, diagonally
// #define OSD_FB_PICO_POSTPROCESS 7 // Two pixels left, right

#define OSD_BATTERY_PERCENT_WITH_SYMBOL
#define OSD_RSSI_WITH_SYMBOL

// Small font is almost compulsory for pixel mode, not guaranteeing to support elements with large fonts
#ifndef OSD_FB_ENABLE_SMALLFONT
#define OSD_FB_ENABLE_SMALLFONT 1
#endif

#else
// LED STRIP not ENABLE_FB_OSD

// External LED STRIP GPIO number
#if PICO_TRACE_TX_GPIO != 2
#define LED_STRIP_PIN        PA2
#endif

#endif // #if OSD_PICO_ENABLE_PIXEL_MODE

#if !OSD_FB_ENABLE_SMALLFONT
#undef OSD_RSSI_WITH_SYMBOL
#endif

#define OSD_FRAMERATE_MAX_HZ 100
#define OSD_FRAMERATE_DEFAULT_HZ 50
#define OSD_DRAWSCREEN_TIME_LIMIT_US 20

#endif // ENABLE_FB_OSD

#define USE_SDCARD_SPI

#ifndef DEFAULT_ALIGN_BOARD_YAW
#define DEFAULT_ALIGN_BOARD_YAW 180
#endif

#define DEFAULT_BLACKBOX_DEVICE  BLACKBOX_DEVICE_SDCARD
#define DEFAULT_VOLTAGE_METER_SCALE 110

/*
GYRO_CLK        PA27
TELEM_RX        PA5
DVTX_SBUS_RX    PA41
*/
