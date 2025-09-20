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

#define FC_TARGET_MCU     STM32F405
#define BOARD_NAME        PILOTIXF405AIO
#define MANUFACTURER_ID   PLTX
 
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#define MOTOR1_PIN PB0
#define MOTOR2_PIN PB1
#define MOTOR3_PIN PA3
#define MOTOR4_PIN PA2
#define MOTOR5_PIN PB5
#define MOTOR6_PIN PB7
#define MOTOR7_PIN PC9
#define MOTOR8_PIN PB4

#define UART1_TX_PIN PB6
#define UART1_RX_PIN PA10
#define UART3_TX_PIN PB10
#define UART3_RX_PIN PB11
#define UART4_TX_PIN PA0
#define UART4_RX_PIN PA1
#define UART5_RX_PIN PD2
#define UART6_TX_PIN PC6
#define UART6_RX_PIN PC7

#define LED0_PIN             PC14

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9

#define LED_STRIP_PIN          PC8
#define BEEPER_PIN             PC13

#define ESCSERIAL_PIN        UART5_RX_PIN
#define ADC_VBAT_PIN         PC3
#define ADC_CURR_PIN         PC2

#define FLASH_CS_PIN         PB3
#define MAX7456_SPI_CS_PIN   PB14
#define GYRO_1_CS_PIN        PC4
#define GYRO_1_EXTI_PIN      PC5

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN , 1,  0) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN , 1,  0) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN , 1,  0) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN , 1,  0) \
    TIMER_PIN_MAP( 4, MOTOR5_PIN , 1,  0) \
    TIMER_PIN_MAP( 5, MOTOR6_PIN , 1,  0) \
    TIMER_PIN_MAP( 6, MOTOR7_PIN , 1,  0) \
    TIMER_PIN_MAP( 7, MOTOR8_PIN , 1,  0)

#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE 118
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ 8

#define BARO_I2C_INSTANCE I2CDEV_1

#define FLASH_SPI_INSTANCE SPI3
#define MAX7456_SPI_INSTANCE SPI3
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW270_DEG


#define GPS_UART                SERIAL_PORT_USART3
#define SERIALRX_UART           SERIAL_PORT_UART4
#define ESC_SENSOR_UART         SERIAL_PORT_UART5
#define VTX_SMARTAUDIO_UART     SERIAL_PORT_USART6
