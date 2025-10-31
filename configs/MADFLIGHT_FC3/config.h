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

#define FC_TARGET_MCU        RP2350B
#define BOARD_NAME           MADFLIGHT_FC3
#define MANUFACTURER_ID      MADF

// For debugging (trace) via UART, make with env var PICO_TRACE set (see RP2350.mk).
// Example instance and pins below.
//#define PICO_TRACE_UART_INSTANCE  0
//#define PICO_TRACE_TX_GPIO        24
//#define PICO_TRACE_RX_GPIO        25

//------------------
// Internal Pins
//------------------

// Bus for internal I2C sensors
// NOTE: Board has BMP580 barometer, MMC5603 compass and INA226 power sensor, but not supported yet by BF
#define I2C0_SCL_PIN         PA33
#define I2C0_SDA_PIN         PA32

// LED
#define LED0_PIN             PA45 // BLUE

// Battery voltage
#define USE_ADC
#define ADC_INSTANCE         ADC1
#define ADC_VBAT_PIN         PA44
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     110 //note: voltage meter has 100k/10k divider

// RGB LED
#define USE_LED_STRIP
#define LED_STRIP_PIN        PA46

// Gyro+acc
//#define USE_GYRO_CLKIN //TODO - gives compile error...
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN         PA30
#define SPI1_SDI_PIN         PA28
#define SPI1_SDO_PIN         PA31
#define GYRO_1_EXTI_PIN      PA27
#define GYRO_1_CS_PIN        PA29
#define GYRO_1_CLKIN_PIN     PA26  //needs #define USE_GYRO_CLKIN
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW180_DEG

/*
// SDCARD 4-bit SDIO - TODO - Compiles but still have "SD-CARD: Not configured" in configurator
#define USE_SDCARD
#define SDCARD_DETECT_PIN    NONE
#define SDIO_DEVICE          SDIODEV_1
#define SDIO_USE_4BIT        1
#define SDIO_CK_PIN          PA34
#define SDIO_CMD_PIN         PA35
#define SDIO_D0_PIN          PA36
#define SDIO_D1_PIN          PA37
#define SDIO_D2_PIN          PA38
#define SDIO_D3_PIN          PA39
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_SDCARD
*/

// SDCARD 1-bit SPI - works
#define USE_SDCARD
#define USE_SDCARD_SPI
#define SPI0_SCK_PIN         PA34
#define SPI0_SDI_PIN         PA36
#define SPI0_SDO_PIN         PA35
#define SDCARD_SPI_CS_PIN    PA39
#define SDCARD_DETECT_PIN    NONE
#define SDCARD_DETECT_INVERTED
#define SDCARD_SPI_INSTANCE  SPI0
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD

//------------------
// External Pins
//------------------
// Pinout for up to 30 external GPIOS, only first 10 pins defined here. Available pins are PA10-25,40-43
#define UART0_TX_PIN         PA0
#define UART0_RX_PIN         PA1
#define I2C1_SDA_PIN         PA2
#define I2C1_SCL_PIN         PA3
#define UART1_TX_PIN         PA4
#define UART1_RX_PIN         PA5
#define MOTOR1_PIN           PA6
#define MOTOR2_PIN           PA7
#define MOTOR3_PIN           PA8
#define MOTOR4_PIN           PA9

// Optional external barometer connected to I2C1 (second i2c bus) PA2=SDA PA3=SCL
#define USE_BARO
#define USE_BARO_BMP085
#define USE_BARO_BMP280
#define USE_BARO_BMP388
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE I2CDEV_1

// Optional external compass connected to I2C1 (second i2c bus) PA2=SDA PA3=SCL
#define USE_MAG
#define USE_MAG_HMC5883L
#define USE_MAG_LIS3MDL
#define USE_MAG_QMC5883L
#define MAG_I2C_INSTANCE I2CDEV_1
