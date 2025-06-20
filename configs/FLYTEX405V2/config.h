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

#define FC_TARGET_MCU STM32F405
#define BOARD_NAME FLYTEX405V2
#define MANUFACTURER_ID FLTE

#define TARGET_BOARD_IDENTIFIER "FL42"
#define USBD_PRODUCT_STRING     "Flytex F405V2"

#define USE_ACC
#define USE_BARO
#define USE_FLASH
#define USE_GYRO

#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#define BEEPER_PIN PC5
#define MOTOR1_PIN PC9
#define MOTOR2_PIN PC8
#define MOTOR3_PIN PC7
#define MOTOR4_PIN PC6
#define SERVO1_PIN PB6
#define SERVO2_PIN PB7
#define SERVO3_PIN PB8
#define SERVO4_PIN PB9
#define RX_PPM_PIN PA3
#define LED_STRIP_PIN PA8
#define LED0_PIN PB0
#define UART1_TX_PIN PA9
#define UART2_TX_PIN PA2
#define UART3_TX_PIN PC10
#define UART4_TX_PIN PA0
#define UART5_TX_PIN PC12
#define UART1_RX_PIN PA10
#define UART2_RX_PIN PA3
#define UART3_RX_PIN PC11
#define UART4_RX_PIN PA1
#define UART5_RX_PIN PD2
#define I2C2_SCL_PIN PB10
#define I2C2_SDA_PIN PB11
#define SPI1_SCK_PIN PA5
#define SPI2_SCK_PIN PB13
#define SPI3_SCK_PIN PB3
#define SPI1_SDI_PIN PA6
#define SPI2_SDI_PIN PB14
#define SPI3_SDI_PIN PB4
#define SPI1_SDO_PIN PA7
#define SPI2_SDO_PIN PB15
#define SPI3_SDO_PIN PB5
#define ADC_VBAT_PIN PC0
#define ADC_RSSI_PIN PC2
#define ADC_CURR_PIN PC1
#define FLASH_CS_PIN PA15
#define MAX7456_SPI_CS_PIN PB12
#define GYRO_1_EXTI_PIN PC4
#define GYRO_1_CS_PIN PA4
#define PINIO1_PIN PC3
#define PINIO2_PIN PC14
#define PINIO3_PIN PC15
#define PINIO4_PIN PB1

#define TIMER_PIN_MAPPING \
          TIMER_PIN_MAP( 0, PC9, 2,  0 ) \
          TIMER_PIN_MAP( 1, PC8, 2,  1 ) \
          TIMER_PIN_MAP( 2, PC7, 2,  1 ) \
          TIMER_PIN_MAP( 3, PC6, 2,  1 ) \
          TIMER_PIN_MAP( 4, PB6, 1, -1 ) \
          TIMER_PIN_MAP( 5, PB7, 1, -1 ) \
          TIMER_PIN_MAP( 6, PB8, 1, -1 ) \
          TIMER_PIN_MAP( 7, PB9, 1, -1 ) \
          TIMER_PIN_MAP( 8, PA8, 1,  0 ) \
          TIMER_PIN_MAP( 9, PA3, 3, -1 )

#define ADC_INSTANCE ADC3
#define ADC3_DMA_OPT 1

#define SERIALRX_UART SERIAL_PORT_USART2

#define MAG_I2C_INSTANCE I2CDEV_2
#define BARO_I2C_INSTANCE I2CDEV_2

#define DEFAULT_DSHOT_BURST DSHOT_DMAR_OFF
#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_OFF
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE 210
#define DEFAULT_CURRENT_METER_SCALE 200
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ 8
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define FLASH_SPI_INSTANCE SPI2
#define MAX7456_SPI_INSTANCE SPI3
#define GYRO_1_SPI_INSTANCE SPI1
#define PINIO1_BOX 40
#define BOX_USER1_NAME       "CAM 1,2" 
#define PINIO2_BOX 41
#define PINIO3_BOX 42
#define PINIO4_BOX 43
#define PINIO4_CONFIG 129
#define BOX_USER4_NAME       "High-V BEC"
