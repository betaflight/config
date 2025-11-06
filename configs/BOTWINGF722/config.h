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

#define FC_TARGET_MCU                       STM32F7X2
#define BOARD_NAME                          BOTWINGF722
#define MANUFACTURER_ID                     BLDY

// ADC
#define ADC_CURR_PIN                        PC0
#define ADC_RSSI_PIN                        PC1
#define ADC_VBAT_PIN                        PC2
#define ADC1_DMA_OPT                        0
#define ADC_INSTANCE                        ADC1
#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE         400
#define DEFAULT_VOLTAGE_METER_SCALE         110

// BARO
#define USE_BARO
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE                   I2CDEV_3

// BEEPER
#define BEEPER_INVERTED
#define BEEPER_PIN                          PB7

// DEBUG
#define SWDIO_PIN                           PA13
#define SWCLK_PIN                           PA14

// FLASH
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define SPI1_NSS_PIN                        PA4
#define SPI1_SCK_PIN                        PA5
#define SPI1_SDI_PIN                        PA6
#define SPI1_SDO_PIN                        PA7
#define FLASH_CS_PIN                        SPI1_NSS_PIN
#define FLASH_SPI_INSTANCE                  SPI1
#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH

// I2C
#define I2C3_SCL_PIN                        PA8
#define I2C3_SDA_PIN                        PC9

// IMU
#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P
#define SPI3_NSS_PIN                        PD2
#define SPI3_SCK_PIN                        PC10
#define SPI3_SDI_PIN                        PC11
#define SPI3_SDO_PIN                        PC12
#define GYRO_1_EXTI_PIN                     PC13
#define GYRO_1_CS_PIN                       SPI3_NSS_PIN
#define GYRO_1_SPI_INSTANCE                 SPI3

// LED
#define LED_STRIP_PIN                       PB6
#define LED0_PIN                            PC4
#define LED1_PIN                            PB2

// MAG
#define MAG_I2C_INSTANCE                    I2CDEV_3

// MOTOR
#define MOTOR1_PIN                          PB4
#define MOTOR2_PIN                          PB5
#define MOTOR3_PIN                          PB0
#define MOTOR4_PIN                          PB1
#define SERVO1_PIN                          PA15
#define SERVO2_PIN                          PB3

// OSD
#define USE_MAX7456
#define SPI2_NSS_PIN                        PB12
#define SPI2_SCK_PIN                        PB13
#define SPI2_SDI_PIN                        PB14
#define SPI2_SDO_PIN                        PB15
#define MAX7456_SPI_CS_PIN                  SPI2_NSS_PIN
#define MAX7456_SPI_INSTANCE                SPI2

// PINIO
#define PINIO1_PIN                          PC3
#define PINIO1_BOX                          40
#define PINIO1_CONFIG                       129
#define BOX_USER1_NAME                      "VTX PWR"

#define PINIO2_PIN                          PC14
#define PINIO2_BOX                          41

// UART
#define UART1_TX_PIN                        PA9
#define UART1_RX_PIN                        PA10

#define UART2_TX_PIN                        PA2
#define UART2_RX_PIN                        PA3

#define UART3_TX_PIN                        PB10
#define UART3_RX_PIN                        PB11

#define UART4_TX_PIN                        PA0
#define UART4_RX_PIN                        PA1

#define UART6_TX_PIN                        PC6
#define UART6_RX_PIN                        PC7

#define RX_PPM_PIN                          PA3

#define SERIALRX_UART                       SERIAL_PORT_USART2
#define ESC_SENSOR_UART                     SERIAL_PORT_UART4
#define GPS_UART                            SERIAL_PORT_USART6
#define DEFAULT_DSHOT_BITBANG               DSHOT_BITBANG_ON

#define CAMERA_CONTROL_PIN                  PB8

// TIMER && DMA
#define TIMER_PIN_MAPPING                   TIMER_PIN_MAP(0,  LED_STRIP_PIN,       1,  0) \
                                            TIMER_PIN_MAP(1,  MOTOR1_PIN,          1,  0) \
                                            TIMER_PIN_MAP(2,  MOTOR2_PIN,          1,  0) \
                                            TIMER_PIN_MAP(3,  MOTOR3_PIN,          2,  0) \
                                            TIMER_PIN_MAP(4,  MOTOR4_PIN,          2,  0) \
                                            TIMER_PIN_MAP(5,  SERVO1_PIN,          1, -1) \
                                            TIMER_PIN_MAP(6,  SERVO2_PIN,          1, -1) \
                                            TIMER_PIN_MAP(9,  RX_PPM_PIN,          3, -1) \
                                            TIMER_PIN_MAP(10, CAMERA_CONTROL_PIN,  2, -1)
