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

#define FC_TARGET_MCU           STM32H743
#define BOARD_NAME              AIRBOTRACINGSUPERH7
#define MANUFACTURER_ID         AIRB

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MSP_DISPLAYPORT_FONT

#define BEEPER_PIN              PC0
#define MOTOR1_PIN              PB0
#define MOTOR2_PIN              PB1
#define MOTOR3_PIN              PE9
#define MOTOR4_PIN              PE11
#define LED_STRIP_PIN           PF6
#define UART1_TX_PIN            PA9
#define UART2_TX_PIN            PA2
#define UART3_TX_PIN            PD8
#define UART4_TX_PIN            PA0
#define UART5_TX_PIN            PB6
#define UART6_TX_PIN            PC6
#define UART7_TX_PIN            PE8
#define UART8_TX_PIN            PE1
#define UART1_RX_PIN            PA10
#define UART2_RX_PIN            PA3
#define UART3_RX_PIN            PD9
#define UART4_RX_PIN            PA1
#define UART5_RX_PIN            PB5
#define UART6_RX_PIN            PC7
#define UART7_RX_PIN            PE7
#define UART8_RX_PIN            PE0
#define I2C2_SCL_PIN            PB10
#define I2C3_SCL_PIN            PA8
#define I2C2_SDA_PIN            PB11
#define I2C3_SDA_PIN            PC9
#define LED0_PIN                PG13
#define SPI1_SCK_PIN            PA5
#define SPI2_SCK_PIN            PB13
#define SPI3_SCK_PIN            PC10
#define SPI4_SCK_PIN            PE2
#define SPI1_SDI_PIN            PA6
#define SPI2_SDI_PIN            PB14
#define SPI3_SDI_PIN            PC11
#define SPI4_SDI_PIN            PE5
#define SPI1_SDO_PIN            PA7
#define SPI2_SDO_PIN            PB15
#define SPI3_SDO_PIN            PC12
#define SPI4_SDO_PIN            PE6
#define ADC_VBAT_PIN            PC3
#define ADC_CURR_PIN            PC2
#define PINIO1_PIN              PA15
#define FLASH_CS_PIN            PD10
#define GYRO_1_EXTI_PIN         PB3
#define GYRO_1_CS_PIN           PD7

#define TIMER_PIN_MAPPING       TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1, 0 ) \
                                TIMER_PIN_MAP( 1, MOTOR1_PIN, 2,  1 ) \
                                TIMER_PIN_MAP( 2, MOTOR2_PIN, 2,  2 ) \
                                TIMER_PIN_MAP( 3, MOTOR3_PIN, 1,  3 ) \
                                TIMER_PIN_MAP( 4, MOTOR4_PIN, 1,  4 )

#define ADC1_DMA_OPT            8
#define ADC3_DMA_OPT            9
#define TIMUP1_DMA_OPT          10
#define TIMUP3_DMA_OPT          11

#define BARO_I2C_INSTANCE               I2CDEV_2
#define ADC_INSTANCE                    ADC1
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST             DSHOT_DMAR_OFF
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define BEEPER_INVERTED
#define PINIO1_BOX                      40
#define PINIO1_CONFIG                   129
#define BOX_USER1_NAME                  "VTX POWER"
#define FLASH_SPI_INSTANCE              SPI2
#define GYRO_1_SPI_INSTANCE             SPI3
#define GYRO_1_ALIGN                    CW270_DEG_FLIP

#define MSP_DISPLAYPORT_UART            SERIAL_PORT_UART4
#define MSP_UART                        SERIAL_PORT_USART1
