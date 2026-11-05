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

/*
    SUPPORTED TARGET - THANK YOU
    REFERENCE: sha256_153bfbf400795045a3d3883a1e7580b2c2d408a89b2ac2124add870e189a72b1
    DATE: 2025-01-01
*/

#pragma once

#define FC_TARGET_MCU       STM32H743

#define BOARD_NAME          ZEX_ATHENA_STD_PRO
#define MANUFACTURER_ID     ZEXM

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_CLKIN
#define USE_GYRO_SPI_ICM42688P
#define USE_MAX7456
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_BARO
#define USE_BARO_DPS310

#define BEEPER_PIN          PE9
#define CAMERA_CONTROL_PIN  PB0
#define MOTOR1_PIN          PA0
#define MOTOR2_PIN          PA1
#define MOTOR3_PIN          PA2
#define MOTOR4_PIN          PA3
#define MOTOR5_PIN          PD12
#define MOTOR6_PIN          PD13
#define MOTOR7_PIN          PD14
#define MOTOR8_PIN          PD15
#define SERVO1_PIN          PE5
#define SERVO2_PIN          PE6
#define LED_STRIP_PIN       PA8
#define UART2_TX_PIN        PD5
#define UART3_TX_PIN        PD8
#define UART4_TX_PIN        PB9
#define UART6_TX_PIN        PC6
#define UART7_TX_PIN        PE8
#define UART8_TX_PIN        PE1
#define UART1_RX_PIN        PA10
#define UART2_RX_PIN        PD6
#define UART3_RX_PIN        PD9
#define UART4_RX_PIN        PB8
#define UART6_RX_PIN        PC7
#define UART7_RX_PIN        PE7
#define UART8_RX_PIN        PE0
#define I2C1_SCL_PIN        PB6
#define I2C2_SCL_PIN        PB10
#define I2C1_SDA_PIN        PB7
#define I2C2_SDA_PIN        PB11
#define LED0_PIN            PE3
#define LED1_PIN            PE4
#define SPI1_SCK_PIN        PA5
#define SPI2_SCK_PIN        PB13
#define SPI3_SCK_PIN        PB3
#define SPI4_SCK_PIN        PE12
#define SPI1_SDI_PIN        PA6
#define SPI2_SDI_PIN        PB14
#define SPI3_SDI_PIN        PB4
#define SPI4_SDI_PIN        PE13
#define SPI1_SDO_PIN        PD7
#define SPI2_SDO_PIN        PB15
#define SPI3_SDO_PIN        PB5
#define SPI4_SDO_PIN        PE14
#define ADC_VBAT_PIN        PC0
#define ADC_CURR_PIN        PC1
#define PINIO1_PIN          PD10
#define FLASH_CS_PIN        PB12
#define MAX7456_SPI_CS_PIN  PE2
#define GYRO_1_EXTI_PIN     PB2
#define GYRO_2_EXTI_PIN     PC14
#define GYRO_1_CS_PIN       PC15
#define GYRO_2_CS_PIN       PC13
#define GYRO_1_CLKIN_PIN    PA15
#define GYRO_2_CLKIN_PIN    PA15

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0,  PA0 , 2,  0) /* TIM5  CH1 (AF2) DMA1 Stream 1 Request  55 */ \
    TIMER_PIN_MAP( 1,  PA1 , 2,  1) /* TIM5  CH2 (AF2) DMA1 Stream 2 Request  56 */ \
    TIMER_PIN_MAP( 2,  PA2 , 2,  2) /* TIM5  CH3 (AF2) DMA1 Stream 3 Request  57 */ \
    TIMER_PIN_MAP( 3,  PA3 , 2,  3) /* TIM5  CH4 (AF2) DMA1 Stream 4 Request  58 */ \
    TIMER_PIN_MAP( 4,  PD12, 1,  4) /* TIM4  CH1 (AF2) DMA1 Stream 1 Request  29 */ \
    TIMER_PIN_MAP( 5,  PD13, 1,  5) /* TIM4  CH2 (AF2) DMA1 Stream 2 Request  30 */ \
    TIMER_PIN_MAP( 6,  PD14, 1,  6) /* TIM4  CH3 (AF2) DMA1 Stream 3 Request  31 */ \
    TIMER_PIN_MAP( 7,  PD15, 1, -1) /* TIM4  CH4 (AF2) No DMA for PD15 available */ \
    TIMER_PIN_MAP( 8,  PE5 , 1, -1) /* TIM15 CH1 (AF4) DMA1 Stream 1 Request 105 */ \
    TIMER_PIN_MAP( 9,  PE6 , 1, -1) /* TIM15 CH2 (AF4)                           */ \
    TIMER_PIN_MAP(10,  PA8 , 1,  7) /* TIM1  CH1 (AF1) DMA1 Stream 1 Request  11 */ \
    TIMER_PIN_MAP(11,  PA15, 1, -1) /* TIM2  CH1 (AF1)                           */ \
    TIMER_PIN_MAP(12,  PB0 , 1, -1) /* TIM3  CH3 (AF2)                           */

#define ADC1_DMA_OPT                    9 /*# ADC 1: DMA2 Stream 0 Request 9*/
#define ADC3_DMA_OPT                    10 /*# ADC 3: DMA2 Stream 1 Request 115*/
#define TIMUP4_DMA_OPT                  11 /*# TIMUP 4: DMA1 Stream 1 Request 32*/
#define TIMUP5_DMA_OPT                  12 /*# TIMUP 5: DMA1 Stream 0 Request 59*/

#define SERIALRX_UART                   SERIAL_PORT_USART2
#define DEFAULT_GYRO_TO_USE             GYRO_CONFIG_USE_GYRO_BOTH
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON
#define MAG_I2C_INSTANCE                I2CDEV_2
#define BARO_I2C_INSTANCE               I2CDEV_1
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define BEEPER_INVERTED
#define MAX7456_SPI_INSTANCE            SPI3
#define PINIO1_BOX                      40
#define PINIO1_CONFIG                   129
#define BOX_USER1_NAME                  "12V BEC"
#define FLASH_SPI_INSTANCE              SPI2
#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_2_SPI_INSTANCE             SPI4
#define GYRO_2_ALIGN                    CW270_DEG
