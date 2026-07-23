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

/*
SUPPORTED TARGET - THANK YOU
REFERENCE: sha256_d4fc19053c1dc0af7804ac528c82b9d416b7a61e2186e9e24829d04bc3203a21
DATE: 2026-05-01
*/

#pragma once

// TBS Lucid Raspberry Pi FC -- RP2350B-based variant of the Lucid family.
// Based on HELLBENDER_0001 (RASP) with the schematic for the TBS "Lucid Raspberry Pi FC".
// Differences vs HELLBENDER_0001:
//  - Discrete analogue OSD (74LVC1G3157 mux + TLV3231/TLV3541) instead of MAX7456
//    (no Betaflight driver -- OSD pins are wired but inactive in firmware)
//  - W25Q64 QSPI flash instead of W25Q128
//  - DPS368 baro (BMP390 alt) on a separate I2C0 bus from external I2C1 header
//  - Single 10 V VTX BEC enable instead of dual 5 V/9 V enables
//  - Gyro footprint accepts MPU6000 (primary) or ICM42688P (alt)

#define FC_TARGET_MCU     RP2350B
#define BOARD_NAME        TBS_LUCID_RPI_FC
#define MANUFACTURER_ID   TEBS

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P

#define SDCARD_SPI_INSTANCE  SPI1
#define GYRO_1_SPI_INSTANCE  SPI0

// Motors: DSHOT1..4 -> M1..M4
#define MOTOR1_PIN           PA9
#define MOTOR2_PIN           PA8
#define MOTOR3_PIN           PA7
#define MOTOR4_PIN           PA6

// Status LEDs (LED_B, LED_G on dual-colour 0402 LEDs)
#define LED0_PIN             PA0
#define LED1_PIN             PA1

// WS2812B RGB strip output (J5)
#define LED_STRIP_PIN        PA2

// SPI0 -- IMU (ICM42688P / MPU6000)
#define SPI0_SCK_PIN         PA34
#define SPI0_SDI_PIN         PA32  // MISO
#define SPI0_SDO_PIN         PA35  // MOSI

// SPI1 -- SD card (P7 TF-110 socket); R9/R10/R11/R33 22Ω series resistors on the lines
#define SPI1_SCK_PIN         PA30
#define SPI1_SDI_PIN         PA28  // MISO
#define SPI1_SDO_PIN         PA31  // MOSI

// QSPI flash (W25Q64JV) -- pins fixed via QMI on RP2350; FLASH_CS_PIN is a placeholder
#define USE_QUADSPI
#define USE_QUADSPI_DEVICE_1
#define FLASH_QUADSPI_INSTANCE	  1

#define USE_FLASH
#define FLASH_CS_PIN         PA0  // shared with LED0 -- platform handles real QSPI CS via QMI
#define USE_FLASH_CHIP
#define USE_FLASH_W25Q128FV  // populated chip is W25Q64JV; W25Q-series share the same command set
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH

// SD card on SPI1 -- this board has no MAX7456, so the SD card path is always available
#define USE_SDCARD
#define USE_SDCARD_SPI
#define SDCARD_SPI_CS_PIN    PA29

// IMU CS / interrupt / external clock-in (6-wire IMU bus on schematic)
#define GYRO_1_CS_PIN        PA33
#define GYRO_1_EXTI_PIN      PA26

// #define USE_GYRO_CLKIN -- TODO: ICM426xx CLKIN driver path doesn't compile on RP2350 yet
#define GYRO_1_CLKIN_PIN     PA27

#define GYRO_2_CS_PIN        NONE

// UARTs --------------------------------------------------------------
// UART0 -- DVTX (DJI O4)
#define UART0_TX_PIN         PA44
#define UART0_RX_PIN         PA45
#define MSP_DISPLAYPORT_UART SERIAL_PORT_UART0

// UART1 -- GPS
#define UART1_TX_PIN         PA36
#define UART1_RX_PIN         PA37
#define GPS_UART             SERIAL_PORT_UART1

// UART2 -- XF2 receiver (CRSF default)
#define UART2_TX_PIN         PA42
#define UART2_RX_PIN         PA43
#define USE_RX_CRSF
#define DEFAULT_RX_FEATURE   FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER    SERIALRX_CRSF
#define SERIALRX_UART        SERIAL_PORT_UART2

// UART3 -- SmartAudio HD (TX-only used by VTX, but RX pin is wired)
#define UART3_TX_PIN         PA16
#define UART3_RX_PIN         PA17

// UART4 -- ESC telemetry (RX only)
#define UART4_RX_PIN         PA5
#define ESC_SENSOR_UART      SERIAL_PORT_UART4

// UART5 -- SBUS RX pad (J3 P pin, "SBUS" net)
#define UART5_RX_PIN         PA41

// I2C ----------------------------------------------------------------
// I2C0 -- onboard barometer (DPS368 / BMP390 alt) with R54/R55 2k pull-ups
#define USE_BARO
#define USE_BARO_DPS310     // DPS368 is pin/register-compatible with DPS310
#define USE_BARO_BMP390
#define BARO_I2C_INSTANCE    I2CDEV_0
#define I2C0_SDA_PIN         PA24
#define I2C0_SCL_PIN         PA25

// I2C1 -- external bus on FPC connector (J7 GPS header also exposes it)
#define I2C1_SDA_PIN         PA38
#define I2C1_SCL_PIN         PA39

// Beeper (Q2 transistor driving J6 buzzer pads)
#define USE_BEEPER
#define BEEPER_PWM_HZ        1971
#define BEEPER_PIN           PA3

// VTX BEC enable -- single 10 V rail, transistor-driven (Q3) on PA18
// Exposed as PINIO1 so the user can toggle the rail from the GUI/CLI
#define USE_PINIO
#define USE_PINIOBOX
#define VTX_ENABLE_PIN       PA18
#define PINIO1_PIN           VTX_ENABLE_PIN
#define PINIO1_BOX           40
#define PINIO1_CONFIG        129

// ADC inputs
#define ADC_VBAT_PIN         PA46
#define ADC_CURR_PIN         PA47
#define ADC_RSSI_PIN         PA40   // SPARE_ADC pad on J7

// OSD ----------------------------------------------------------------
// Board has a discrete analogue OSD (74LVC1G3157 mux + TLV3541/TLV3231 comparators)
// driven by OSD_W (PA21), OSD_EN (PA22) and OSD_SYNC (PA23). Betaflight has no
// driver for this DIY OSD path, so these are left undefined and the OSD will be
// inactive until external HD VTX OSD is used (MSP DisplayPort over UART0).

// Spare GPIO header (J7 SM06B-SRSS-TB) -- not currently consumed by firmware
//   SPARE_GPIO1 = PA12, SPARE_GPIO2 = PA13, SPARE_GPIO3 = PA14
