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
#define BOARD_NAME        HELLBENDER_0001
#define MANUFACTURER_ID   RASP

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P

#define MAX7456_SPI_INSTANCE SPI1
#define SDCARD_SPI_INSTANCE  SPI1
#define GYRO_1_SPI_INSTANCE  SPI0

#define MOTOR1_PIN           PA28
#define MOTOR2_PIN           PA29
#define MOTOR3_PIN           PA30
#define MOTOR4_PIN           PA31

#define LED0_PIN             PA6
#define LED1_PIN             PA7

#define LED_STRIP_PIN        PA38

#define SPI0_SCK_PIN         PA2
#define SPI0_SDI_PIN         PA4
#define SPI0_SDO_PIN         PA3

#define SPI1_SCK_PIN         PA26
#define SPI1_SDI_PIN         PA24
#define SPI1_SDO_PIN         PA27

#define USE_MAX7456

#define MAX7456_SPI_CS_PIN   PA17

// Enable QUADSPI on RP2350 (pins are fixed via QMI; platform code handles them)
#define USE_QUADSPI
#define USE_QUADSPI_DEVICE_1
#define FLASH_QUADSPI_INSTANCE	  1

// MAX7456 and SD card cannot be used at the same time
#ifdef USE_MAX7456
#define USE_FLASH
#define FLASH_CS_PIN         PA0
#define USE_FLASH_CHIP
#define USE_FLASH_W25Q128FV

#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#else
#define USE_SDCARD
#define USE_SDCARD_SPI
#define SDCARD_SPI_CS_PIN    PA25

#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_SDCARD
#endif

#define GYRO_1_CS_PIN        PA1
#define GYRO_1_EXTI_PIN      PA22

#define GYRO_2_CS_PIN        NONE

#define UART1_TX_PIN         PA20
#define UART1_RX_PIN         PA21

#define USE_BARO
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE    I2CDEV_0
#define I2C0_SDA_PIN         PA44
#define I2C0_SCL_PIN         PA45

#define USE_BEEPER
#define BEEPER_PWM_HZ        1971
#define BEEPER_PIN           PA5

#define PICO_BEC_5V_ENABLE_PIN PA14
#define PICO_BEC_9V_ENABLE_PIN PA15

#define ADC_VBAT_PIN         PA40
#define ADC_CURR_PIN         PA41
#define ADC_RSSI_PIN         PA42
