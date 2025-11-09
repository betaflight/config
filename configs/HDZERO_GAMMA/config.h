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

#define FC_TARGET_MCU        STM32G47X

#define BOARD_NAME           HDZERO_GAMMA
#define MANUFACTURER_ID      HDZO

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P

#define USE_BARO
#define USE_BARO_DPS310

#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN     PB5

#define BEEPER_PIN           PA9

#define MOTOR1_PIN           PA3
#define MOTOR2_PIN           PA2
#define MOTOR3_PIN           PA1
#define MOTOR4_PIN           PA0

#define LED_STRIP_PIN        PA8

#define UART1_TX_PIN         PB6
#define UART1_RX_PIN         PB7

#define UART2_TX_PIN         PB3
#define UART2_RX_PIN         PB4

#define UART3_TX_PIN         PB10
#define UART3_RX_PIN         PB11

#define UART4_TX_PIN         PC10
#define UART4_RX_PIN         PC11

#define I2C1_SCL_PIN         PA15
#define I2C1_SDA_PIN         PB9	

#define LED0_PIN             PA4

#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

#define ADC_VBAT_PIN         PB1
#define ADC_CURR_PIN         PB0

#define GYRO_1_EXTI_PIN      PB12
#define GYRO_1_CS_PIN        PC6
#define GYRO_1_SPI_INSTANCE  SPI2

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(  0, MOTOR1_PIN,       2,  0 ) \
    TIMER_PIN_MAP(  1, MOTOR2_PIN,       2,  1 ) \
    TIMER_PIN_MAP(  2, MOTOR3_PIN,       2,  2 ) \
    TIMER_PIN_MAP(  3, MOTOR4_PIN,       2,  3 ) \
    TIMER_PIN_MAP(  4, LED_STRIP_PIN,    1,  4 ) \
    TIMER_PIN_MAP(  5, BEEPER_PIN,       2, -1 ) \
    TIMER_PIN_MAP(  6, GYRO_1_CLKIN_PIN, 1, -1 )

#define ADC1_DMA_OPT                 5
#define ADC2_DMA_OPT                 6
#define TIMUP5_DMA_OPT               7

#define BARO_I2C_INSTANCE            I2CDEV_1

#define DEFAULT_DSHOT_BITBANG        DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SCALE  107
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define SYSTEM_HSE_MHZ               8
#define GYRO_1_ALIGN                 CW0_DEG_FLIP
#define DEFAULT_ALIGN_BOARD_YAW      -45
#define MSP_DISPLAYPORT_UART         SERIAL_PORT_USART1
#define SERIALRX_UART                SERIAL_PORT_USART2
#define BEEPER_INVERTED
