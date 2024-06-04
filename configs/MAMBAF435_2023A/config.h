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

#define FC_TARGET_MCU                       AT32F435G

#define BOARD_NAME                          MAMBAF435_2023A
#define MANUFACTURER_ID                     DIAT

#define USE_BARO
#define USE_BARO_DPS310

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P

#define USE_FLASH
#define USE_FLASH_W25Q128FV


#define USE_MAX7456
#define MAX7456_SPI_CS_PIN                  PB12
#define MAX7456_SPI_INSTANCE                SPI2

#define BEEPER_PIN                          PB11
#define BEEPER_INVERTED

#define MOTOR1_PIN                          PC9
#define MOTOR2_PIN                          PC8
#define MOTOR3_PIN                          PC7
#define MOTOR4_PIN                          PC6
#define MOTOR5_PIN                          PA0
#define MOTOR6_PIN                          PA1
#define MOTOR7_PIN                          PA2
#define MOTOR8_PIN                          PA3

#define SERVO1_PIN                          PA9
#define SERVO2_PIN                          PA10

#define LED_STRIP_PIN                       PA6

#define UART1_TX_PIN                        PB6
#define UART2_TX_PIN                        PA8
#define UART3_TX_PIN                        PC4
#define UART4_TX_PIN                        PC10
#define UART5_TX_PIN                        PC12
#define UART6_TX_PIN                        PA4
#define UART7_TX_PIN                        PC0


#define UART1_RX_PIN                        PB7
#define UART2_RX_PIN                        PB0
#define UART3_RX_PIN                        PC5
#define UART4_RX_PIN                        PC11
#define UART5_RX_PIN                        PD2
#define UART6_RX_PIN                        PA5

#define INVERTER_PIN_UART2                  PC0

#define I2C1_SCL_PIN                        PB8
#define I2C1_SDA_PIN                        PB9

#define LED0_PIN                            PC14
#define LED1_PIN                            PC15

#define SPI1_SCK_PIN                        PA5
#define SPI2_SCK_PIN                        PB13
#define SPI3_SCK_PIN                        PB3

#define SPI1_SDI_PIN                        PA6
#define SPI2_SDI_PIN                        PB14
#define SPI3_SDI_PIN                        PB4

#define SPI1_SDO_PIN                        PA7
#define SPI2_SDO_PIN                        PB15
#define SPI3_SDO_PIN                        PB5

#define ADC_VBAT_PIN                        PC1
#define ADC_CURR_PIN                        PC2

#define PINIO1_PIN                          PC3
#define PINIO2_PIN                          PA7

#define FLASH_CS_PIN                        PB10
#define FLASH_SPI_INSTANCE                  SPI2

#define GYRO_1_EXTI_PIN                     PA15
#define GYRO_1_CS_PIN                       PC13
#define GYRO_1_SPI_INSTANCE                 SPI3
#define GYRO_1_ALIGN                        CW270_DEG

#define TIMER_PIN_MAPPING                   TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1, 8 ) \
                                            TIMER_PIN_MAP( 1, SERVO1_PIN, 1,  9 ) \
                                            TIMER_PIN_MAP( 2, SERVO2_PIN, 1, 10) \
                                            TIMER_PIN_MAP( 3, BEEPER_PIN, 1, 7 )

#define ADC1_DMA_OPT                        11
#define SPI1_TX_DMA_OPT                     12
#define SPI2_TX_DMA_OPT                     13
#define SPI3_TX_DMA_OPT                     14

#define ADC_INSTANCE                        ADC1
#define BARO_I2C_INSTANCE                   (I2CDEV_1)

#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH

#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
