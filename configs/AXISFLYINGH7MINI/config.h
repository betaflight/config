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

#define BOARD_NAME        AXISFLYINGH7MINI
#define MANUFACTURER_ID   AXFL

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#define BEEPER_PIN           PA15

#define MOTOR1_PIN           PA0
#define MOTOR2_PIN           PA1
#define MOTOR3_PIN           PA2
#define MOTOR4_PIN           PA3
#define MOTOR5_PIN           PD12
#define MOTOR6_PIN           PD13
#define MOTOR7_PIN           PD14
#define MOTOR8_PIN           PD15

#define LED_STRIP_PIN        PA8

#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PD5
#define UART3_TX_PIN         PD8
#define UART4_TX_PIN         PB9
#define UART6_TX_PIN         PC6
#define UART7_TX_PIN         PE8
#define UART8_TX_PIN         PE1

#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PD6
#define UART3_RX_PIN         PD9
#define UART4_RX_PIN         PB8
#define UART6_RX_PIN         PC7
#define UART7_RX_PIN         PE7
#define UART8_RX_PIN         PE0

#define I2C1_SCL_PIN         PB6 // external
#define I2C1_SDA_PIN         PB7
#define I2C2_SCL_PIN         PB10 // internal
#define I2C2_SDA_PIN         PB11

#define LED0_PIN             PE3
#define LED1_PIN             PE4

#define SPI1_SCK_PIN         PA5 // imu1
#define SPI2_SCK_PIN         PB13 // osd
#define SPI3_SCK_PIN         PB3 // flash
#define SPI4_SCK_PIN         PE12 // imu2
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PB4
#define SPI4_SDI_PIN         PE13
#define SPI1_SDO_PIN         PD7
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PB5
#define SPI4_SDO_PIN         PE14

#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC1
#define ADC_EXTERNAL1_PIN    PA7

#define PINIO1_PIN           PD10
#define PINIO2_PIN           PE2

#define FLASH_CS_PIN         PD4
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PE10
#define GYRO_1_CS_PIN        PC15
#define GYRO_2_EXTI_PIN      PB2
#define GYRO_2_CS_PIN        PC13

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN, 1,  0 ) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN, 2,  1 ) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN, 1,  2 ) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN, 2,  3 ) \
    TIMER_PIN_MAP( 4, MOTOR5_PIN, 1,  4 ) \
    TIMER_PIN_MAP( 5, MOTOR6_PIN, 2,  5 ) \
    TIMER_PIN_MAP( 6, MOTOR7_PIN, 1,  6 ) \
    TIMER_PIN_MAP( 7, MOTOR8_PIN, 2, -1 ) \
    TIMER_PIN_MAP( 8, LED_STRIP_PIN, 1, 7 )

#define ADC1_DMA_OPT                   8
#define ADC2_DMA_OPT                   9
#define ADC3_DMA_OPT                   10

#define MAG_I2C_INSTANCE               I2CDEV_1
#define BARO_I2C_INSTANCE              I2CDEV_2

#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART           SERIAL_PORT_USART1
#endif
#define SERIALRX_UART                  SERIAL_PORT_USART2
#ifdef USE_GPS
#define GPS_UART                       SERIAL_PORT_USART3
#endif
#define ESC_SENSOR_UART                SERIAL_PORT_UART4

#define DEFAULT_BLACKBOX_DEVICE        BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG          DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE   CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE   VOLTAGE_METER_ADC
#define BEEPER_INVERTED
#define PINIO1_CONFIG                  129
#define PINIO1_BOX                     40
#define PINIO2_CONFIG                  129
#define PINIO2_BOX                     41
#define GYRO_1_SPI_INSTANCE            SPI1
#define GYRO_2_SPI_INSTANCE            SPI4
#define FLASH_SPI_INSTANCE             SPI3
#define MAX7456_SPI_INSTANCE           SPI2
