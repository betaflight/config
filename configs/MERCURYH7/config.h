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

#define FC_TARGET_MCU     STM32H743

#define BOARD_NAME                      MERCURYH7
#define MANUFACTURER_ID                 ANYL

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_M25P16

#define BEEPER_PIN                      PE9
#define MOTOR1_PIN                      PC6
#define MOTOR2_PIN                      PC7
#define MOTOR3_PIN                      PC8
#define MOTOR4_PIN                      PC9
#define MOTOR5_PIN                      PE5
#define MOTOR6_PIN                      PE6
#define MOTOR7_PIN                      PE13
#define MOTOR8_PIN                      PE14
#define UART1_TX_PIN                    PB6
#define UART2_TX_PIN                    PA2
#define UART3_TX_PIN                    PD8
#define UART4_TX_PIN                    PC10
#define UART7_TX_PIN                    PB4
#define UART8_TX_PIN                    PE1
#define UART1_RX_PIN                    PB7
#define UART2_RX_PIN                    PA3
#define UART3_RX_PIN                    PD9
#define UART4_RX_PIN                    PC11
#define UART7_RX_PIN                    PB3
#define UART8_RX_PIN                    PE0
#define I2C1_SCL_PIN                    PB8
#define I2C1_SDA_PIN                    PB9
#define I2C2_SCL_PIN                    PB10
#define I2C2_SDA_PIN                    PB11
#define SPI1_SCK_PIN                    PA5
#define SPI2_SCK_PIN                    PA9
#define SPI1_SDI_PIN                    PA6
#define SPI2_SDI_PIN                    PB14
#define SPI1_SDO_PIN                    PA7
#define SPI2_SDO_PIN                    PB15
#define ADC_VBAT_PIN                    PA4
#define ADC_CURR_PIN                    PA0
#define FLASH_CS_PIN                    PE11
#define GYRO_1_EXTI_PIN                 PB12
#define GYRO_1_CS_PIN                   PC4
#define LED0_PIN                        PC13

#define TIMER_PIN_MAPPING               TIMER_PIN_MAP( 1, MOTOR1_PIN , 1,  -1) \
                                        TIMER_PIN_MAP( 2, MOTOR2_PIN , 1,  -1) \
                                        TIMER_PIN_MAP( 3, MOTOR3_PIN , 1,  -1) \
                                        TIMER_PIN_MAP( 4, MOTOR4_PIN , 1,  -1) \
                                        TIMER_PIN_MAP( 5, MOTOR5_PIN , 1,  -1) \
                                        TIMER_PIN_MAP( 6, MOTOR6_PIN , 1,  -1) \
                                        TIMER_PIN_MAP( 7, MOTOR7_PIN , 1,  -1) \
                                        TIMER_PIN_MAP( 8, MOTOR8_PIN , 1,  -1) \
                                        TIMER_PIN_MAP( 0, BEEPER_PIN , 2,  -1)

#define ADC_INSTANCE                    ADC1
#define ADC1_DMA_OPT                    6

#define SPI1_TX_DMA_OPT                 8
#define SPI1_RX_DMA_OPT                 9
#define SPI2_TX_DMA_OPT                 10
#define SPI2_RX_DMA_OPT                 11

#define BARO_I2C_INSTANCE               (I2CDEV_2)
#define FLASH_SPI_INSTANCE              SPI2
#define GYRO_1_SPI_INSTANCE             SPI1

#define BEEPER_INVERTED

#define SYSTEM_HSE_MHZ                  16
#define DEFAULT_PID_PROCESS_DENOM       1

#define DEFAULT_RX_FEATURE              FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER               SERIALRX_CRSF
#define SERIALRX_UART                   SERIAL_PORT_USART7

#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH

#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE_DEFAULT 118
#define DEFAULT_CURRENT_METER_SCALE     400

#define DEFAULT_BARO_I2C_ADDRESS        119
#define USE_I2C_PULLUP

#define GYRO_1_ALIGN                    CW90_DEG
#define GYRO_1_ALIGN_YAW                1800