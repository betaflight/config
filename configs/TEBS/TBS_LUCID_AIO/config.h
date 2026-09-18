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
    REFERENCE: sha256_8d657664626b4675b1ab2add2a84b8153efed2c3fe5990b27ccc7acbafdc5347
*/

#pragma once

#define FC_TARGET_MCU                       AT32F435M

#define BOARD_NAME                          TBS_LUCID_AIO
#define MANUFACTURER_ID                     TEBS

#define USE_ACC
#define USE_ACC_SPI_ICM42688P

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define GYRO_1_CS_PIN                       PA4
#define GYRO_1_SPI_INSTANCE                 SPI1
#define GYRO_1_EXTI_PIN                     PB2

#define USE_BARO
#define USE_BARO_BMP388

#define USE_FLASH
#define USE_FLASH_M25P16
#define FLASH_CS_PIN                        PA15
#define FLASH_SPI_INSTANCE                  SPI3

#define USE_MAX7456
#define MAX7456_SPI_CS_PIN                  PB12
#define MAX7456_SPI_INSTANCE                SPI2

#define BEEPER_INVERTED
#define BEEPER_PIN                          PC13

#define MOTOR1_PIN                          PA8
#define MOTOR2_PIN                          PA9
#define MOTOR3_PIN                          PA10
#define MOTOR4_PIN                          PA3

#define LED_STRIP_PIN                       PH3

#define UART1_TX_PIN                        PB6
#define UART1_RX_PIN                        PB7

#define UART2_TX_PIN                        PA2
#define UART2_RX_PIN                        NONE

#define UART3_TX_PIN                        PB10
#define UART3_RX_PIN                        PB11

#define UART4_TX_PIN                        NONE
#define UART4_RX_PIN                        PH2

#define UART5_TX_PIN                        PB9
#define UART5_RX_PIN                        PB8

#define I2C2_SCL_PIN                        PA0
#define I2C2_SDA_PIN                        PA1

#define LED0_PIN                            PC14

#define SPI1_SCK_PIN                        PA5
#define SPI1_SDI_PIN                        PA6
#define SPI1_SDO_PIN                        PA7

#define SPI2_SCK_PIN                        PB13
#define SPI2_SDI_PIN                        PB14
#define SPI2_SDO_PIN                        PB15

#define SPI3_SCK_PIN                        PB3
#define SPI3_SDI_PIN                        PB4
#define SPI3_SDO_PIN                        PB5

#define ADC_VBAT_PIN                        PB0
#define ADC_CURR_PIN                        PB1

#define TIMER_PIN_MAPPING \
                                            TIMER_PIN_MAP(0, PH3, 1, 4) \
                                            TIMER_PIN_MAP(1, PA8, 1, 0) \
                                            TIMER_PIN_MAP(2, PA9, 1, 1) \
                                            TIMER_PIN_MAP(3, PA10, 1, 2) \
                                            TIMER_PIN_MAP(4, PA3, 1, 3) 

#define ADC1_DMA_OPT                        11

#define ADC_INSTANCE                        ADC1
#define BARO_I2C_INSTANCE                   I2CDEV_2

#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH

#define DEFAULT_ALIGN_BOARD_YAW             315

#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE         1120
#define DEFAULT_VOLTAGE_METER_SCALE         31

#define SERIALRX_PROVIDER                   SERIALRX_CRSF
#define SERIALRX_UART                       SERIAL_PORT_UART5

#define DEFAULT_FEATURES (FEATURE_OSD | FEATURE_LED_STRIP)
