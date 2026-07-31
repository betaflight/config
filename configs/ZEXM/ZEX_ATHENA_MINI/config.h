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

#define FC_TARGET_MCU       STM32H743

#define BOARD_NAME          ZEX_ATHENA_MINI
#define MANUFACTURER_ID     ZEXM

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_CLKIN
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#define BEEPER_PIN              PE9

#define MOTOR1_PIN              PA0
#define MOTOR2_PIN              PA1
#define MOTOR3_PIN              PA2
#define MOTOR4_PIN              PA3

#define LED_STRIP_PIN           PA8

#define UART3_TX_PIN            PD8
#define UART4_TX_PIN            PB9
#define UART7_TX_PIN            PE8
#define UART8_TX_PIN            PE1

#define UART1_RX_PIN            PA10
#define UART2_RX_PIN            PD6
#define UART3_RX_PIN            PD9
#define UART4_RX_PIN            PB8
#define UART7_RX_PIN            PE7
#define UART8_RX_PIN            PE0

#define I2C1_SCL_PIN            PB6
#define I2C1_SDA_PIN            PB7
#define I2C2_SCL_PIN            PB10
#define I2C2_SDA_PIN            PB11

#define LED0_PIN                PE3
#define LED1_PIN                PE4

#define SPI1_SCK_PIN            PA5
#define SPI1_SDI_PIN            PA6
#define SPI1_SDO_PIN            PD7

#define SPI2_SCK_PIN            PB13
#define SPI2_SDI_PIN            PB14
#define SPI2_SDO_PIN            PB15

#define SPI3_SCK_PIN            PB3
#define SPI3_SDI_PIN            PB4
#define SPI3_SDO_PIN            PB5

#define SPI4_SCK_PIN            PE12
#define SPI4_SDI_PIN            PE13
#define SPI4_SDO_PIN            PE14

#define ADC_VBAT_PIN            PC0
#define ADC_CURR_PIN            PC1

#define FLASH_CS_PIN            PE2

#define MAX7456_SPI_CS_PIN      PB12

#define GYRO_1_EXTI_PIN         PB2
#define GYRO_1_CS_PIN           PC15
#define GYRO_1_CLKIN_PIN        PA15

#define GYRO_2_EXTI_PIN         PE15
#define GYRO_2_CS_PIN           PE11

#define CAMERA_CONTROL_PIN      PB0
#define PINIO1_PIN              PD10 // BEC12V_EN

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1,  0) \
    TIMER_PIN_MAP( 1, MOTOR1_PIN, 2,  1) \
    TIMER_PIN_MAP( 2, MOTOR2_PIN, 2,  2) \
    TIMER_PIN_MAP( 3, MOTOR3_PIN, 2,  3) \
    TIMER_PIN_MAP( 4, MOTOR4_PIN, 2,  4) \
    TIMER_PIN_MAP( 5, CAMERA_CONTROL_PIN, 2, -1) \
    TIMER_PIN_MAP( 6, GYRO_1_CLKIN_PIN, 1, -1)

#define ADC1_DMA_OPT                    8
#define ADC3_DMA_OPT                    9
#define TIMUP5_DMA_OPT                  10

#define MAG_I2C_INSTANCE                I2CDEV_1
#define BARO_I2C_INSTANCE               I2CDEV_2

#define GYRO_1_SPI_INSTANCE             SPI1
#define MAX7456_SPI_INSTANCE            SPI2
#define FLASH_SPI_INSTANCE              SPI3
#define GYRO_2_SPI_INSTANCE             SPI4

#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_GYRO_TO_USE             GYRO_CONFIG_USE_GYRO_BOTH

#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE     180
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC

#define PINIO1_BOX                      40
#define PINIO1_CONFIG                   129
#define BOX_USER1_NAME                  "12V BEC"

#define BEEPER_INVERTED

#define GYRO_1_ALIGN                    CW270_DEG
