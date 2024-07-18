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

#define BOARD_NAME SEQUREH7V2
#define MANUFACTURER_ID SQRE

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#ifndef USE_CAMERA_CONTROL
#define USE_CAMERA_CONTROL
#endif

#define BEEPER_PIN PD15
#define MOTOR1_PIN PB4
#define MOTOR2_PIN PB5
#define MOTOR3_PIN PB0
#define MOTOR4_PIN PB1
#define MOTOR5_PIN PB6
#define MOTOR6_PIN PB7
#define MOTOR7_PIN PB10
#define MOTOR8_PIN PB11
#define LED_STRIP_PIN PA8
#define UART1_TX_PIN PA9
#define UART2_TX_PIN PA2
#define UART4_TX_PIN PA0
#define UART6_TX_PIN PC6
#define UART7_TX_PIN PE8
#define UART1_RX_PIN PA10
#define UART2_RX_PIN PA3
#define UART4_RX_PIN PA1
#define UART6_RX_PIN PC7
#define UART7_RX_PIN PE7
#define UART8_RX_PIN PE0
#define I2C1_SCL_PIN PB8
#define I2C1_SDA_PIN PB9
#define LED0_PIN PC13
#define SPI1_SCK_PIN PA5
#define SPI2_SCK_PIN PB13
#define SPI3_SCK_PIN PC10
#define SPI1_SDI_PIN PA6
#define SPI2_SDI_PIN PB14
#define SPI3_SDI_PIN PC11
#define SPI1_SDO_PIN PA7
#define SPI2_SDO_PIN PB15
#define SPI3_SDO_PIN PC12
#define ADC_VBAT_PIN PC3
#define ADC_CURR_PIN PC2
#define CAMERA_CONTROL_PIN PB3
#define FLASH_CS_PIN PA15
#define MAX7456_SPI_CS_PIN PA4
#define GYRO_1_EXTI_PIN PD0
#define GYRO_1_CS_PIN PB12

#define TIMER_PIN_MAPPING \
     TIMER_PIN_MAP( 1, PB5, 1, -1) \
     TIMER_PIN_MAP( 2, PB0, 2, -1) \
     TIMER_PIN_MAP( 3, PB1, 2, -1) \
     TIMER_PIN_MAP( 4, PB6, 2, -1) \
     TIMER_PIN_MAP( 5, PB7, 2, -1) \
     TIMER_PIN_MAP( 6, PB10, 1, -1) \
     TIMER_PIN_MAP( 7, PB11, 1, -1) \
     TIMER_PIN_MAP( 8, PA8, 1, 4) \
     TIMER_PIN_MAP( 9, PB3, 1, -1) \
     TIMER_PIN_MAP(10, PB8, 2, -1) \
     TIMER_PIN_MAP(11, PB9, 2, -1)

#define ADC1_DMA_OPT 8
#define ADC3_DMA_OPT 9
#define TIMUP1_DMA_OPT 0
#define TIMUP3_DMA_OPT 2
#define TIMUP5_DMA_OPT 0
#define TIMUP8_DMA_OPT 2

#define SERIALRX_UART SERIAL_PORT_USART1
#define GPS_UART SERIAL_PORT_USART6
#define MSP_DISPLAYPORT_UART SERIAL_PORT_USART7
#define ESC_SENSOR_UART SERIAL_PORT_USART8

#define MAG_I2C_INSTANCE (I2CDEV_1)
#define BARO_I2C_INSTANCE (I2CDEV_1)
#define ADC_INSTANCE ADC1
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_OFF
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE 110
#define DEFAULT_CURRENT_METER_SCALE 1052
#define BEEPER_INVERTED
#define MAX7456_SPI_INSTANCE SPI1
#define GYRO_1_SPI_INSTANCE SPI2
#define FLASH_SPI_INSTANCE SPI3
#define GYRO_1_ALIGN CW90_DEG
