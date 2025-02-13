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
/* Legacy target, do not copy */

#pragma once

#define FC_TARGET_MCU     AT32F435G

#define BOARD_NAME        NBD_HUMMINGBIRD200RS
#define MANUFACTURER_ID   NEBD

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

#define BEEPER_PIN           PB0
#define MOTOR1_PIN           PA8
#define MOTOR2_PIN           PB10
#define MOTOR3_PIN           PA0
#define MOTOR4_PIN           PA1
#define LED_STRIP_PIN        PB1
#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PA2
#define UART6_TX_PIN         PA4
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PB11
#define UART6_RX_PIN         PA5
#define LED0_PIN             PC14
#define I2C2_SCL_PIN         PH2
#define I2C2_SDA_PIN         PH3
#define SPI1_SCK_PIN         PB3
#define SPI2_SCK_PIN         PB13
#define SPI4_SCK_PIN         PB7
#define SPI1_SDI_PIN         PB4
#define SPI2_SDI_PIN         PB14
#define SPI4_SDI_PIN         PB8
#define SPI1_SDO_PIN         PB5
#define SPI2_SDO_PIN         PB15
#define SPI4_SDO_PIN         PB9
#define ADC_VBAT_PIN         PA6
#define ADC_CURR_PIN         PA7
#define PINIO1_PIN           PC15
#define FLASH_CS_PIN         PB12
#define MAX7456_SPI_CS_PIN   PB6
#define GYRO_1_EXTI_PIN      PC13
#define GYRO_1_CS_PIN        PA15

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1, 0) \
    TIMER_PIN_MAP( 1, MOTOR1_PIN   , 1, 1) \
    TIMER_PIN_MAP( 2, MOTOR2_PIN   , 1, 2) \
    TIMER_PIN_MAP( 3, MOTOR3_PIN   , 1, 3) \
    TIMER_PIN_MAP( 4, MOTOR4_PIN   , 1, 4) 


#define ADC_INSTANCE         ADC1
#define ADC1_DMA_OPT         12

#define BARO_I2C_INSTANCE I2CDEV_2
#define MAG_I2C_INSTANCE I2CDEV_2
#define FLASH_SPI_INSTANCE SPI2
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE 107
#define DEFAULT_CURRENT_METER_SCALE 300
#define BEEPER_INVERTED
#define USE_SPI_DEVICE_4
#define SYSTEM_HSE_MHZ 8
#define MAX7456_SPI_INSTANCE SPI4
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW90_DEG

#define PINIO1_CONFIG 129
#define PINIO1_BOX 40

#define SERIALRX_UART SERIAL_PORT_USART2
#define SERIALRX_PROVIDER  SERIALRX_CRSF
