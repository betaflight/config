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

#define FC_TARGET_MCU        AT32F435M

#define BOARD_NAME           GREATMOUNTAINF435
#define MANUFACTURER_ID      GMRC

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define GYRO_1_CS_PIN                   PA4
#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_ALIGN                    CW180_DEG_FLIP

// GYRO interrupts
#define USE_EXTI
#define USE_GYRO_EXTI
#define GYRO_1_EXTI_PIN                 PA15

#define SPI1_SCK_PIN                    PA5
#define SPI2_SCK_PIN                    PD1
#define SPI3_SCK_PIN                    PC10
#define SPI1_SDI_PIN                    PA6
#define SPI2_SDI_PIN                    PD3
#define SPI3_SDI_PIN                    PC11
#define SPI1_SDO_PIN                    PA7
#define SPI2_SDO_PIN                    PD4
#define SPI3_SDO_PIN                    PC12

#define BEEPER_PIN                      PB11
#define BEEPER_INVERTED

#define MOTOR1_PIN                      PB6
#define MOTOR2_PIN                      PB7
#define MOTOR3_PIN                      PB8
#define MOTOR4_PIN                      PB9

#define MOTOR5_PIN                      PC6
#define MOTOR6_PIN                      PC7
#define MOTOR7_PIN                      PC8
#define MOTOR8_PIN                      PC9

#define LED0_PIN                        PD15
#define LED1_PIN                        PD14
#define LED_STRIP_PIN                   PB10

#define UART1_TX_PIN                    PA9
#define UART2_TX_PIN                    PA2
#define UART3_TX_PIN                    PC4
#define UART4_TX_PIN                    PA0
#define UART8_TX_PIN                    PC2

#define UART1_RX_PIN                    PA10
#define UART2_RX_PIN                    PA3
#define UART3_RX_PIN                    PC5
#define UART4_RX_PIN                    PA1
#define UART8_RX_PIN                    PC3

//TODO resource RX_BIND 1 @01
// #define RX_BIND_PLUG_PIN                PO15
// #define CAMERA_CONTROL_PIN              PA0

#define ADC_VBAT_PIN                    PB0
#define ADC_CURR_PIN                    PB1
#define ADC1_DMA_OPT                    11

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G
#define FLASH_CS_PIN                    PD6
#define FLASH_SPI_INSTANCE              SPI3
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH

#define I2C3_SCL_PIN                    PC0
#define I2C3_SDA_PIN                    PC1

#define BARO_I2C_INSTANCE               I2CDEV_3
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310

#define USE_MAX7456
#define MAX7456_SPI_INSTANCE            SPI2
#define MAX7456_SPI_CS_PIN              PD5

#define PINIO1_PIN                      PD2
#define PINIO1_CONFIG                   129
#define PINIO1_BOX                      39

#define TIMER_PIN_MAPPING               TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1, 7 ) \
                                        TIMER_PIN_MAP( 1, BEEPER_PIN, 1,  6 ) \
                                        TIMER_PIN_MAP( 2, MOTOR5_PIN, 1,  11 ) \
                                        TIMER_PIN_MAP( 3, MOTOR6_PIN, 1,  10 ) \
                                        TIMER_PIN_MAP( 4, MOTOR7_PIN, 2,  8 ) \
                                        TIMER_PIN_MAP( 5, MOTOR8_PIN, 2,  9 ) \
                                        TIMER_PIN_MAP( 6, MOTOR1_PIN, 2,  0 ) \
                                        TIMER_PIN_MAP( 7, MOTOR2_PIN, 2,  2 ) \
                                        TIMER_PIN_MAP( 8, MOTOR3_PIN, 1,  1 ) \
                                        TIMER_PIN_MAP( 9, MOTOR4_PIN, 1,  3 )

#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     110
#define DEFAULT_CURRENT_METER_SCALE     100

#define DEFAULT_FEATURES (FEATURE_OSD | FEATURE_LED_STRIP)
