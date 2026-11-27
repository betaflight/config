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

#define FC_TARGET_MCU     CH32H415

#define BOARD_NAME        H4AIO
#define MANUFACTURER_ID   RATE

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_ICM40609D
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_M25P16

#define BEEPER_PIN           PF4
#define MOTOR1_PIN           PE3
#define MOTOR2_PIN           PE4
#define MOTOR3_PIN           PE5
#define MOTOR4_PIN           PE6
#define SERVO1_PIN           PD3
#define SERVO2_PIN           PB11
#define LED_STRIP_PIN        PB6
#define LED0_PIN             PC4
#define CAMERA_CONTROL_PIN   PA4
#define PINIO1_PIN           PA11
#define PINIO2_PIN           PA12

#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART2_TX_PIN         PA2
#define UART2_RX_PIN         PA3
#define UART3_TX_PIN         PA13
#define UART3_RX_PIN         PA14
#define UART4_TX_PIN         PC6
#define UART4_RX_PIN         PC7
#define UART5_TX_PIN         PE0
#define UART5_RX_PIN         PF5
#define UART6_TX_PIN         PA0
#define UART6_RX_PIN         PA1
#define UART7_RX_PIN         PB12
#define UART8_TX_PIN         PB4
#define UART8_RX_PIN         PB3

#define I2C2_SCL_PIN         PC0
#define I2C2_SDA_PIN         PC1

#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12
#define GYRO_1_CS_PIN        PF3
#define GYRO_1_EXTI_PIN      PA15

#define SPI4_SCK_PIN         PE12
#define SPI4_SDI_PIN         PE13
#define SPI4_SDO_PIN         PE14
#define FLASH_CS_PIN         PB10

#define ADC_VBAT_PIN         PC3
#define ADC_CURR_PIN         PC2

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1,  1) \
    TIMER_PIN_MAP( 1, MOTOR1_PIN,    1,  4) \
    TIMER_PIN_MAP( 2, MOTOR2_PIN,    1,  5) \
    TIMER_PIN_MAP( 3, MOTOR3_PIN,    1,  6) \
    TIMER_PIN_MAP( 4, MOTOR4_PIN,    1,  7) \
    TIMER_PIN_MAP( 5, SERVO1_PIN,    1, -1) \
    TIMER_PIN_MAP( 6, SERVO2_PIN,    2, -1)

#define ADC1_DMA_OPT         0

#define ADC_INSTANCE         ADC1
#define BARO_I2C_INSTANCE    I2CDEV_2
#define MAG_I2C_INSTANCE     I2CDEV_2
#define GYRO_1_SPI_INSTANCE  SPI3
#define FLASH_SPI_INSTANCE   SPI4

#define GYRO_1_ALIGN         CW0_DEG

#define BEEPER_INVERTED
#define PINIO1_BOX           40
#define PINIO2_BOX           41

#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG        DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE  111
#define DEFAULT_CURRENT_METER_SCALE  166

#define SERIALRX_UART        SERIAL_PORT_USART1
#define SERIALRX_PROVIDER    SERIALRX_CRSF
#define MSP_DISPLAYPORT_UART SERIAL_PORT_USART3
#define VTX_MSP_UART         SERIAL_PORT_USART3
