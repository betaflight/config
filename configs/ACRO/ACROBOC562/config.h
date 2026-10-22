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
    REFERENCE: sha256_dcf8e2a99d5e043d97c9e6a789420b17f1e1c682b52eb05f2506044c95a480c3
    DATE: 2026-05-01
*/

#pragma once

#define FC_TARGET_MCU       STM32C562

#define BOARD_NAME          ACROBOC562
#define MANUFACTURER_ID     ACRO

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_LSM6DSK320X
#define USE_BARO
#define USE_BARO_DPS310
#define USE_BARO_LPS22DF
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#define MOTOR1_PIN          PC6
#define MOTOR2_PIN          PC7
#define MOTOR3_PIN          PC8
#define MOTOR4_PIN          PC9

#define UART1_TX_PIN        PA9
#define UART1_RX_PIN        PA10
#define UART2_TX_PIN        PA2
#define UART2_RX_PIN        PA3
#define UART3_TX_PIN        PB10
#define UART3_RX_PIN        PB1
#define UART4_TX_PIN        PA0
#define UART4_RX_PIN        PA1
#define UART5_TX_PIN        PC12
#define UART5_RX_PIN        PD2

#define CAN1_TX_PIN         PC13
#define CAN1_RX_PIN         PC14
#define CAN1_SILENT_PIN     PC15

#define I2C1_SCL_PIN        PB8
#define I2C1_SDA_PIN        PB9

#define SPI1_SCK_PIN        PA5
#define SPI1_SDI_PIN        PA6
#define SPI1_SDO_PIN        PA7

#define SPI2_SCK_PIN        PB13
#define SPI2_SDI_PIN        PB14
#define SPI2_SDO_PIN        PB15

#define SPI3_SCK_PIN        PC10
#define SPI3_SDI_PIN        PB6
#define SPI3_SDO_PIN        PB5

#define FLASH_CS_PIN        PA4
#define MAX7456_SPI_CS_PIN  PB12
#define GYRO_1_CS_PIN       PA15
#define GYRO_1_EXTI_PIN     PB7

#define LED0_PIN            PC5
#define BEEPER_PIN          PC4
#define LED_STRIP_PIN       PA8


#define CAMERA_CONTROL_PIN  PB0
#define USB_DETECT_PIN      PC0
#define USE_USB_DETECT

#define ADC_VBAT_PIN        PC1
#define ADC_CURR_PIN        PC2
#define ADC_RSSI_PIN        PC3

#define PINIO1_PIN          PC11

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN,         1,  0) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN,         1,  1) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN,         1,  2) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN,         1,  3) \
    TIMER_PIN_MAP( 4, LED_STRIP_PIN,      1,  4) \
    TIMER_PIN_MAP( 5, CAMERA_CONTROL_PIN, 3, -1) \
    TIMER_PIN_MAP( 6, BEEPER_PIN,         1, -1)


#define ADC1_DMA_OPT                 8

#define USE_BEEPER
#define BEEPER_INVERTED

#define BARO_I2C_INSTANCE            I2CDEV_1
#define MAG_I2C_INSTANCE             I2CDEV_1

#define GYRO_1_ALIGN                 CW270_DEG
#define GYRO_1_SPI_INSTANCE          SPI3
#define MAX7456_SPI_INSTANCE         SPI2
#define FLASH_SPI_INSTANCE           SPI1

#define PINIO1_BOX                   40
#define PINIO1_CONFIG                129
#define BOX_USER1_NAME               "VCC10V EN"

#define SYSTEM_HSE_MHZ               8

#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG        DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE  100
