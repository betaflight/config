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
    REFERENCE: sha256_1c28a1909ea50a7804548184e001e8586e926897f1518711fb5e31a80f97f6d4
*/

#pragma once

#define FC_TARGET_MCU                       AT32F435M

#define BOARD_NAME                          TBS_LUCID_FC
#define MANUFACTURER_ID                     TEBS

#define USE_ACC
#define USE_ACC_SPI_ICM42688P

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P

#define GYRO_1_EXTI_PIN                     PC4
#define GYRO_1_CS_PIN                       PA4
#define GYRO_1_SPI_INSTANCE                 SPI1

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

#define MOTOR1_PIN                          PC6
#define MOTOR2_PIN                          PB5
#define MOTOR3_PIN                          PC8
#define MOTOR4_PIN                          PC9
#define MOTOR5_PIN                          PA0
#define MOTOR6_PIN                          PA1
#define MOTOR7_PIN                          PA2
#define MOTOR8_PIN                          PA3

#define SERVO1_PIN                          PB7
#define SERVO2_PIN                          PB8

#define CAMERA_CONTROL_PIN                  PC5

#define LED_STRIP_PIN                       PA8

#define UART1_TX_PIN                        PA9
#define UART1_RX_PIN                        PA10

#define UART2_TX_PIN                        NONE
#define UART2_RX_PIN                        PB0

#define UART3_TX_PIN                        PB11
#define UART3_RX_PIN                        PB10

#define UART4_TX_PIN                        PH3
#define UART4_RX_PIN                        PH2

#define UART5_TX_PIN                        PB9
#define UART5_RX_PIN                        PD2

#define UART7_TX_PIN                        PB4
#define UART7_RX_PIN                        PB3

#define UART8_TX_PIN                        PC2
#define UART8_RX_PIN                        PC3

#define I2C1_SCL_PIN                        PB6
#define I2C1_SDA_PIN                        PC7

#define LED0_PIN                            PC14
#define LED1_PIN                            PC15

#define SPI1_SCK_PIN                        PA5
#define SPI1_SDI_PIN                        PA6
#define SPI1_SDO_PIN                        PA7

#define SPI2_SCK_PIN                        PB13
#define SPI2_SDI_PIN                        PB14
#define SPI2_SDO_PIN                        PB15

#define SPI3_SCK_PIN                        PC10
#define SPI3_SDI_PIN                        PC11
#define SPI3_SDO_PIN                        PC12

#define ADC_VBAT_PIN                        PC0
#define ADC_CURR_PIN                        PC1


#define TIMER_PIN_MAPPING             \
        TIMER_PIN_MAP(0, PC6, 1, 9)   \
        TIMER_PIN_MAP(1, PB5, 1, 10)  \
        TIMER_PIN_MAP(2, PC8, 1, 11)  \
        TIMER_PIN_MAP(3, PC9, 1, 12)  \
        TIMER_PIN_MAP(4, PA0, 1, -1)  \
        TIMER_PIN_MAP(5, PA1, 1, -1)  \
        TIMER_PIN_MAP(6, PA2, 1, -1)  \
        TIMER_PIN_MAP(7, PA3, 1, -1)  \
        TIMER_PIN_MAP(8, PA8, 1, 8)   \
        TIMER_PIN_MAP(9, PB7, 1, -1)  \
        TIMER_PIN_MAP(10, PB8, 2, -1) \
        TIMER_PIN_MAP(11, PC5, 1, -1)  

#define ADC1_DMA_OPT                        0
#define SPI3_TX_DMA_OPT                     5

#define ADC_INSTANCE                        ADC1
#define BARO_I2C_INSTANCE                   I2CDEV_1
#define MAG_I2C_INSTANCE                    I2CDEV_1

#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH

#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC

#define DEFAULT_ALIGN_BOARD_ROLL            180
#define DEFAULT_ALIGN_BOARD_YAW             90

#define SERIALRX_PROVIDER                   SERIALRX_CRSF
#define SERIALRX_UART                       SERIAL_PORT_UART5
