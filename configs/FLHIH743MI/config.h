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
#define BOARD_NAME          FLHIH743MI
#define MANUFACTURER_ID     FLHI

#define USE_ACC
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P

#define USE_BARO
#define USE_BARO_BMP280

#define USE_SDCARD
#define USE_SDCARD_SPI

#define ADC_CURR_PIN        PC1
#define ADC_VBAT_PIN        PC0

#define BEEPER_PIN          PD2

#define SDCARD_SPI_CS_PIN   PA4

#define GYRO_1_EXTI_PIN     PB2
#define GYRO_2_EXTI_PIN     PE15

#define GYRO_1_CS_PIN       PC15
#define GYRO_2_CS_PIN       PB12

#define I2C1_SCL_PIN        PB6
#define I2C1_SDA_PIN        PB7

#define I2C2_SCL_PIN        PB10 // currently unused
#define I2C2_SDA_PIN        PB11 // currently unused

#define LED0_PIN            PE3
#define LED1_PIN            PE4

#define MOTOR1_PIN          PB0
#define MOTOR2_PIN          PB1
#define MOTOR3_PIN          PD12
#define MOTOR4_PIN          PD13
//#define MOTOR5_PIN        PA3
//#define MOTOR6_PIN        PA2
//#define MOTOR7_PIN        PA1
//#define MOTOR8_PIN        PA0

#define SPI1_SCK_PIN        PA5
#define SPI1_SDI_PIN        PA6
#define SPI1_SDO_PIN        PD7

#define SPI2_SCK_PIN        PB13
#define SPI2_SDI_PIN        PB14
#define SPI2_SDO_PIN        PB15

#define SPI6_SCK_PIN        PB3
#define SPI6_SDI_PIN        PB4
#define SPI6_SDO_PIN        PB5

#define LED_STRIP_PIN       PA8

#define UART1_TX_PIN        PA9
#define UART2_TX_PIN        PD5
#define UART3_TX_PIN        PD8
#define UART4_TX_PIN        PB9
#define UART6_TX_PIN        PC6 // currently unused
#define UART7_TX_PIN        PE8
#define UART8_TX_PIN        PE1 // currently unused

#define UART1_RX_PIN        PA10
#define UART2_RX_PIN        PD6
#define UART3_RX_PIN        PD9
#define UART4_RX_PIN        PB8
#define UART6_RX_PIN        PC7 // currently unused
#define UART7_RX_PIN        PE7
#define UART8_RX_PIN        PE0 // currently unused

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1, 0 ) \
    TIMER_PIN_MAP( 1, MOTOR1_PIN,    2, 1 ) \
    TIMER_PIN_MAP( 2, MOTOR2_PIN,    2, 2 ) \
    TIMER_PIN_MAP( 3, MOTOR3_PIN,    1, 3 ) \
    TIMER_PIN_MAP( 4, MOTOR4_PIN,    1, 4 )

#define ADC1_DMA_OPT                    8
#define ADC2_DMA_OPT                    9
#define ADC3_DMA_OPT                    10

#define BARO_I2C_INSTANCE               I2CDEV_1
#define MAG_I2C_INSTANCE                I2CDEV_1

#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_2_SPI_INSTANCE             SPI2
#define SDCARD_SPI_INSTANCE             SPI6

#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     110
#define DEFAULT_CURRENT_METER_SCALE     50 // check scale !!!

#define BEEPER_INVERTED

#define GYRO_1_ALIGN                    CW180_DEG
#define GYRO_2_ALIGN                    CW270_DEG
