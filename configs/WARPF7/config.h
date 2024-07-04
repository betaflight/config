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

#define FC_TARGET_MCU     STM32F7X2

#define BOARD_NAME WARPF7
#define MANUFACTURER_ID ZERO

#define USE_ACC
#define USE_ACC_SPI_ICM42688P

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P

#define GYRO_1_EXTI_PIN PC4
#define GYRO_1_CS_PIN PA4
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW270_DEG
#define GYRO_1_ALIGN_YAW 2700

#define USE_BARO
#define USE_BARO_SPI_BMP280
#define BARO_CS_PIN PC13
#define BARO_SPI_INSTANCE SPI3

#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G
#define FLASH_CS_PIN PB6
#define FLASH_SPI_INSTANCE SPI3

#define USE_MAX7456
#define MAX7456_SPI_CS_PIN PB12
#define MAX7456_SPI_INSTANCE SPI2

#define BEEPER_INVERTED
#define BEEPER_PIN PA15

#define MOTOR1_PIN PB0
#define MOTOR2_PIN PB1
#define MOTOR3_PIN PB10
#define MOTOR4_PIN PB11
#define MOTOR5_PIN PC9
#define MOTOR6_PIN PC8
#define MOTOR7_PIN PC7
#define MOTOR8_PIN PC6

#define CAMERA_CONTROL_PIN PB7

#define LED_STRIP_PIN PA8

#define UART1_TX_PIN PA9
#define UART1_RX_PIN PA10

#define UART2_TX_PIN PA2
#define UART2_RX_PIN PA3

#define UART3_TX_PIN PC10
#define UART3_RX_PIN PC11

#define UART4_TX_PIN PA0
#define UART4_RX_PIN PA1

#define UART5_TX_PIN PC12
#define UART5_RX_PIN PD2

#define I2C1_SCL_PIN PB8
#define I2C1_SDA_PIN PB9

#define LED0_PIN PC3
#define LED1_PIN PB2

#define SPI1_SCK_PIN PA5
#define SPI1_SDI_PIN PA6
#define SPI1_SDO_PIN PA7

#define SPI2_SCK_PIN PB13
#define SPI2_SDI_PIN PB14
#define SPI2_SDO_PIN PB15

#define SPI3_SCK_PIN PB3
#define SPI3_SDI_PIN PB4
#define SPI3_SDO_PIN PB5

#define ADC_VBAT_PIN PC2
#define ADC_RSSI_PIN PC0
#define ADC_CURR_PIN PC1

#define PINIO1_PIN PC14
#define PINIO2_PIN PC15

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN, 2, 0) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN, 2, 0) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN, 1, 0) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN, 1, 0) \
    TIMER_PIN_MAP( 4, MOTOR5_PIN, 2, 0) \
    TIMER_PIN_MAP( 5, MOTOR6_PIN, 2, 0) \
    TIMER_PIN_MAP( 6, MOTOR7_PIN, 2, 0) \
    TIMER_PIN_MAP( 7, MOTOR8_PIN, 2, 0) \
    TIMER_PIN_MAP( 8, LED_STRIP_PIN, 1, 0) \
    TIMER_PIN_MAP( 9, CAMERA_CONTROL_PIN, 1, -1)

#define SPI3_TX_DMA_OPT     0
#define SPI3_RX_DMA_OPT     0
#define ADC1_DMA_OPT        1

#define MAG_I2C_INSTANCE (I2CDEV_1)
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define PINIO1_BOX 40
#define PINIO2_BOX 41

#define SERIALRX_UART SERIAL_PORT_USART1
#define ESC_SENSOR_UART SERIAL_PORT_USART2
#if defined(USE_OSD_SD) && !defined(USE_OSD_HD)
#define VTX_SMARTAUDIO_UART SERIAL_PORT_USART3
#endif
#if defined(USE_OSD_HD) && !defined(USE_OSD_SD)
#define MSP_DISPLAYPORT_UART SERIAL_PORT_USART3
#endif
#ifdef USE_GPS
#define GPS_UART SERIAL_PORT_UART4
#endif
