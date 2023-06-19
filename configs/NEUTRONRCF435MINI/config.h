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

#define FC_TARGET_MCU        AT32F435G

#define BOARD_NAME           NEUTRONRCF435MINI
#define MANUFACTURER_ID      NERC

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P



#define GYRO_1_CS_PIN                   PA4
#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_ALIGN                    CW180_DEG

// GYRO interrupts
#define USE_EXTI
#define USE_GYRO_EXTI
#define GYRO_1_EXTI_PIN                 PA15

#define SPI1_SCK_PIN                    PA5
#define SPI1_SDI_PIN                    PA6
#define SPI1_SDO_PIN                    PA7

#define SPI2_SCK_PIN                    PB13
#define SPI2_SDI_PIN                    PB14
#define SPI2_SDO_PIN                    PB15

#define BEEPER_PIN                      PC15
#define BEEPER_INVERTED

#define MOTOR1_PIN                      PB6
#define MOTOR2_PIN                      PB7
#define MOTOR3_PIN                      PA3
#define MOTOR4_PIN                      PB1


#define LED0_PIN                        PC13
#define LED0_INVERTED

#define LED_STRIP_PIN                   PA8

#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART5
#define USE_UART7
#define SERIAL_PORT_COUNT       (UNIFIED_SERIAL_PORT_COUNT + 5)

#define UART1_TX_PIN                    PA9
#define UART2_TX_PIN                    PA2
#define UART3_TX_PIN                    PB11
#define UART5_TX_PIN                    PB9
#define UART7_TX_PIN                    PB4

#define UART1_RX_PIN                    PA10
#define UART2_RX_PIN                    PB0
#define UART3_RX_PIN                    PB10
#define UART5_RX_PIN                    PB8
#define UART7_RX_PIN                    PB3

#define I2C2_SCL_PIN                    PH2
#define I2C2_SDA_PIN                    PH3

//TODO resource RX_BIND 1 @01
#define RX_BIND_PLUG_PIN                PO15


#define ADC_VBAT_PIN                    PA0
#define ADC_CURR_PIN                    PA1
#define ADC1_DMA_OPT                    11

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G
#define FLASH_CS_PIN                    PB5
#define FLASH_SPI_INSTANCE              SPI2
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH

#define BARO_I2C_INSTANCE               I2CDEV_2
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310

#define USE_OSD
#define USE_MAX7456
#define MAX7456_SPI_INSTANCE            SPI2
#define MAX7456_SPI_CS_PIN              PB12

#define TIMER_PIN_MAPPING               TIMER_PIN_MAP( 1, LED_STRIP_PIN, 2, 7 ) \
                                        TIMER_PIN_MAP( 2, UART2_RX_PIN, 1,  6 ) \
                                        TIMER_PIN_MAP( 7, MOTOR1_PIN, 2,  0 ) \
                                        TIMER_PIN_MAP( 8, MOTOR2_PIN, 2,  2 ) \
                                        TIMER_PIN_MAP( 9, MOTOR3_PIN, 1,  1 ) \
                                        TIMER_PIN_MAP(10, MOTOR4_PIN, 1,  3 )

#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     110
#define DEFAULT_CURRENT_METER_SCALE     100

#define DEFAULT_FEATURES (FEATURE_OSD |FEATURE_LED_STRIP)
