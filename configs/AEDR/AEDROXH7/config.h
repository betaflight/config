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

#define FC_TARGET_MCU                   STM32H743
#define BOARD_NAME                      AEDROXH7
#define MANUFACTURER_ID                 AEDR

// BEEPER & LEDS
#define BEEPER_PIN                      PA7
#define BEEPER_INVERTED
#define LED_STRIP_PIN                   PA5
#define LED0_PIN                        PE5
#define LED1_PIN                        PE4

// MOTORS & SERVOS
#define MOTOR1_PIN                      PC7
#define MOTOR2_PIN                      PC6
#define MOTOR3_PIN                      PC9
#define MOTOR4_PIN                      PC8
#define MOTOR5_PIN                      PE9
#define MOTOR6_PIN                      PE11
#define MOTOR7_PIN                      PE13
#define MOTOR8_PIN                      PE14

// SPI
#define SPI2_SCK_PIN                    PB13
#define SPI2_SDI_PIN                    PB14
#define SPI2_SDO_PIN                    PB15

#define SPI3_SCK_PIN                    PC10
#define SPI3_SDI_PIN                    PC11
#define SPI3_SDO_PIN                    PB2

// GYRO & ACC
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_CLKIN

#define GYRO_1_CLKIN_PIN                PD13
#define GYRO_1_EXTI_PIN                 PC4
#define GYRO_1_CS_PIN                   PA4
#define GYRO_1_SPI_INSTANCE             SPI2
#define GYRO_1_ALIGN                    CW90_DEG

// FLASH
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_FLASH_M25P16
#define FLASH_CS_PIN                    PA15
#define FLASH_SPI_INSTANCE              SPI3
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH

// BARO & MAG
#define USE_BARO
#define USE_BARO_DPS310

#define I2C1_SCL_PIN                    PB6
#define I2C1_SDA_PIN                    PB7

#define I2C2_SCL_PIN                    PB10
#define I2C2_SDA_PIN                    PB11

#define MAG_I2C_INSTANCE                I2CDEV_1
#define BARO_I2C_INSTANCE               I2CDEV_2

// UART & VCP
#define UART1_TX_PIN                    PA9
#define UART1_RX_PIN                    PA10

#define UART2_TX_PIN                    PD5
#define UART2_RX_PIN                    PD6

#define UART3_TX_PIN                    PD8
#define UART3_RX_PIN                    PD9

#define UART4_TX_PIN                    PD1
#define UART4_RX_PIN                    PD0

#define UART7_RX_PIN                    PE7

#define UART8_TX_PIN                    PE1
#define UART8_RX_PIN                    PE0

// ADC
#define ADC_VBAT_PIN                    PC0
#define ADC_RSSI_PIN                    PC5
#define ADC_CURR_PIN                    PC1
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC

// PINIO
#define PINIO1_PIN                      PA2
#define PINIO2_PIN                      PA3
#define PINIO3_PIN                      PB12

#define PINIO1_BOX                      40
#define PINIO2_BOX                      41
#define PINIO3_BOX                      42

#define PINIO3_CONFIG                   129

#define BOX_USER3_NAME                  "VTX POWER"

// CONNECTORS
#ifdef USE_GPS
#define GPS_UART                        SERIAL_PORT_USART2
#endif

#define SERIALRX_UART                   SERIAL_PORT_USART3

#ifdef USE_ESCSERIAL
#define ESC_SENSOR_UART                 SERIAL_PORT_USART7
#endif

#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART            SERIAL_PORT_USART8
#endif

// TIMERS & DMA
#define TIMER_PIN_MAPPING               TIMER_PIN_MAP( 0, MOTOR1_PIN,       2,  0 ) \
                                        TIMER_PIN_MAP( 1, MOTOR2_PIN,       2,  1 ) \
                                        TIMER_PIN_MAP( 2, MOTOR3_PIN,       2,  2 ) \
                                        TIMER_PIN_MAP( 3, MOTOR4_PIN,       2,  3 ) \
                                        TIMER_PIN_MAP( 4, MOTOR5_PIN,       1,  4 ) \
                                        TIMER_PIN_MAP( 5, MOTOR6_PIN,       1,  5 ) \
                                        TIMER_PIN_MAP( 6, MOTOR7_PIN,       1,  6 ) \
                                        TIMER_PIN_MAP( 7, MOTOR8_PIN,       1,  7 ) \
                                        TIMER_PIN_MAP( 8, LED_STRIP_PIN,    1, 10 ) \
                                        TIMER_PIN_MAP( 9, GYRO_1_CLKIN_PIN, 1, -1 ) \
                                        TIMER_PIN_MAP(10, BEEPER_PIN,       2, -1 )

#define ADC1_DMA_OPT                    8
#define ADC3_DMA_OPT                    9
