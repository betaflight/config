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

#define FC_TARGET_MCU STM32H743
#define BOARD_NAME RMNOVAH7
#define MANUFACTURER_ID RDMR

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN     PA5
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

#define  BEEPER_PIN          PA9

#define  MOTOR1_PIN          PE9
#define  MOTOR2_PIN          PE11
#define  MOTOR3_PIN          PE13
#define  MOTOR4_PIN          PE14
#define  MOTOR5_PIN          PA6
#define  MOTOR6_PIN          PA7
#define  MOTOR7_PIN          PC8
#define  MOTOR8_PIN          PC9

#define  LED_STRIP_PIN       PA0

#define  UART1_TX_PIN        PB6
#define  UART1_RX_PIN        PB7

#define  UART2_TX_PIN        PD5
#define  UART2_RX_PIN        PD6

#define  UART3_TX_PIN        PD8
#define  UART3_RX_PIN        PD9

#define  UART4_TX_PIN        PD1
#define  UART4_RX_PIN        PD0

#define  UART5_TX_PIN        PD3
#define  UART5_RX_PIN        PD2

#define  UART6_TX_PIN        PC6
#define  UART6_RX_PIN        PC7

#define  UART7_TX_PIN        PE8
#define  UART7_RX_PIN        PE7

#define  UART8_TX_PIN        PE1
#define  UART8_RX_PIN        PE0

#define  I2C1_SCL_PIN        PB8
#define  I2C1_SDA_PIN        PB9

#define  I2C2_SCL_PIN        PB10
#define  I2C2_SDA_PIN        PB11

#define  LED0_PIN            PC4
#define  LED1_PIN            PC5

#define  SPI1_SCK_PIN        PB3
#define  SPI1_SDI_PIN        PB4
#define  SPI1_SDO_PIN        PB5

#define  SPI2_SCK_PIN        PB13
#define  SPI2_SDI_PIN        PB14
#define  SPI2_SDO_PIN        PB15

#define  SPI3_SCK_PIN        PC10
#define  SPI3_SDI_PIN        PC11
#define  SPI3_SDO_PIN        PC12

#define  SPI4_SCK_PIN        PE2
#define  SPI4_SDI_PIN        PE5
#define  SPI4_SDO_PIN        PE6

#define  ADC_VBAT_PIN        PC0
#define  ADC_CURR_PIN        PC1

#define  PINIO1_PIN          PA3
#define  PINIO2_PIN          PA2
#define  PINIO3_PIN          PA1

#define  FLASH_CS_PIN        PA8
#define  GYRO_1_EXTI_PIN     PD7
#define  GYRO_1_CS_PIN       PA15
#define  MAX7456_SPI_CS_PIN  PB12

#define  USB_DETECT_PIN      PA10


#define TIMER_PIN_MAPPING               TIMER_PIN_MAP( 0, PE9,  1,  0 ) \
                                        TIMER_PIN_MAP( 1, PE11, 1,  1 ) \
                                        TIMER_PIN_MAP( 2, PE13, 1,  2 ) \
                                        TIMER_PIN_MAP( 3, PE14, 1,  3 ) \
                                        TIMER_PIN_MAP( 4, PA6,  1,  5 ) \
                                        TIMER_PIN_MAP( 5, PA7,  2,  6 ) \
                                        TIMER_PIN_MAP( 6, PC8,  2,  7 ) \
                                        TIMER_PIN_MAP( 7, PC9,  2,  8 ) \
                                        TIMER_PIN_MAP( 8, PA0,  2,  9 ) \
                                        TIMER_PIN_MAP( 9, PA5,  1, -1 )


#define ADC1_DMA_OPT 10
#define ADC3_DMA_OPT 11

#define MAG_I2C_INSTANCE                I2CDEV_2
#define BARO_I2C_INSTANCE               I2CDEV_1

#define DEFAULT_RX_FEATURE              FEATURE_RX_SERIAL
#define SERIALRX_UART                   SERIAL_PORT_USART6
#define SERIALRX_PROVIDER               SERIALRX_CRSF

#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define BEEPER_INVERTED
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON

#define PINIO1_BOX                      40

#define PINIO2_BOX                      41
#define PINIO2_CONFIG                   129
#define BOX_USER2_NAME                  "VTX SW"

#define PINIO3_BOX                      42
#define BOX_USER3_NAME                  "CAM 1,2"

#define FLASH_SPI_INSTANCE              SPI3
#define MAX7456_SPI_INSTANCE            SPI2
#define GYRO_1_SPI_INSTANCE             SPI1
