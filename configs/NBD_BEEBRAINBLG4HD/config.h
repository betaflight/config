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

#define FC_TARGET_MCU     STM32G47X

#define BOARD_NAME        NBD_BEEBRAINBLG4HD
#define MANUFACTURER_ID   NEBD

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_LED_STRIP

#define BEEPER_PIN           PB7
#define MOTOR1_PIN           PB0
#define MOTOR2_PIN           PB1
#define MOTOR3_PIN           PA6
#define MOTOR4_PIN           PA7
#define LED_STRIP_PIN        PB4
#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PA14
#define UART3_TX_PIN         PB9
#define UART4_TX_PIN         PC10
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA15
#define UART3_RX_PIN         PB8
#define UART4_RX_PIN         PC11
#define LED0_PIN             PB2
#define LED1_PIN             PA3
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15
#define ADC_VBAT_PIN         PA0
#define ADC_CURR_PIN         PA1
#define GYRO_1_EXTI_PIN      PC14
#define GYRO_1_CS_PIN        PB12

#define TIMER_PIN_MAPPING              \
    TIMER_PIN_MAP(0, MOTOR1_PIN, 2, 1) \
    TIMER_PIN_MAP(1, MOTOR2_PIN, 2, 2) \
    TIMER_PIN_MAP(2, MOTOR3_PIN, 3, 3) \
    TIMER_PIN_MAP(3, MOTOR4_PIN, 3, 4) \
    TIMER_PIN_MAP(4, LED_STRIP_PIN, 1, 12) \
    TIMER_PIN_MAP(5, BEEPER_PIN, 3, 5)



#define ADC1_DMA_OPT                 10

#define SPI2_RX_DMA_OPT              8
#define SPI2_TX_DMA_OPT              9

#define ADC_INSTANCE                 ADC1
#define GYRO_1_SPI_INSTANCE          SPI2

#define DEFAULT_RX_FEATURE           FEATURE_RX_SERIAL
#define SERIALRX_UART                SERIAL_PORT_USART2
#define SERIALRX_PROVIDER            SERIALRX_CRSF

#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE  500

#define BEEPER_INVERTED

#define GYRO_1_ALIGN                 CW90_DEG
#define GYRO_1_ALIGN_YAW             900
