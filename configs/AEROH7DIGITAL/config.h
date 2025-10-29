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

#define BOARD_NAME        AEROH7DIGITAL
#define MANUFACTURER_ID   AERO

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_CLKIN
#define USE_BARO
#define USE_BARO_DPS310
#define USE_SDCARD

#define MOTOR1_PIN           PE9
#define MOTOR2_PIN           PE11
#define MOTOR3_PIN           PE13
#define MOTOR4_PIN           PE14
#define MOTOR5_PIN           PD12
#define MOTOR6_PIN           PD13
#define MOTOR7_PIN           PD14
#define MOTOR8_PIN           PD15
#define SERVO1_PIN           PC6
#define SERVO2_PIN           PC7

#define UART2_TX_PIN         PA2
#define UART4_TX_PIN         PD1
#define UART5_TX_PIN         PB13
#define UART8_TX_PIN         PE1
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PD9 // ESC TELEMETRY
#define UART4_RX_PIN         PD0
#define UART5_RX_PIN         PB12
#define UART7_RX_PIN         PE7 // SBUS DJI
#define UART8_RX_PIN         PE0

#define I2C1_SCL_PIN         PB8
#define I2C4_SCL_PIN         PB6
#define I2C1_SDA_PIN         PB9
#define I2C4_SDA_PIN         PB7

#define LED0_PIN             PD8  // Blue
#define LED1_PIN             PB15 // Green
#define LED2_PIN             PB14 // Amber

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7

#define ADC_VBAT_PIN         PA0
#define ADC_CURR_PIN         PA1

#define SDIO_CK_PIN          PC12
#define SDIO_CMD_PIN         PD2
#define SDIO_D0_PIN          PC8
#define SDIO_D1_PIN          PC9
#define SDIO_D2_PIN          PC10
#define SDIO_D3_PIN          PC11

#define PINIO1_PIN           PE2

#define GYRO_1_EXTI_PIN      PB1
#define GYRO_1_CS_PIN        PB0
#define GYRO_1_CLKIN_PIN     PE5

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PE9 , 1,  0) /* TIM1_CH1 */ \
    TIMER_PIN_MAP( 1, PE11, 1,  1) /* TIM1_CH2 */ \
    TIMER_PIN_MAP( 2, PE13, 1,  2) /* TIM1_CH3 */ \
    TIMER_PIN_MAP( 3, PE14, 1,  3) /* TIM1_CH4 */ \
    TIMER_PIN_MAP( 4, PD12, 1,  4) /* TIM4_CH1 */ \
    TIMER_PIN_MAP( 5, PD13, 1,  5) /* TIM4_CH2 */ \
    TIMER_PIN_MAP( 6, PD14, 1,  6) /* TIM4_CH3 */ \
    TIMER_PIN_MAP( 7, PD15, 1,  -1) /* TIM4_CH4 NO DMA */ \
    TIMER_PIN_MAP( 8, PC6 , 1, -1) /* TIM3_CH1 */ \
    TIMER_PIN_MAP( 9, PC7 , 1, -1) /* TIM3_CH2 */ \
    TIMER_PIN_MAP(10, PE5 , 1, -1) /* TIM15_CH1 */

#define ADC1_DMA_OPT                 8
#define ADC3_DMA_OPT                 9

#define BARO_I2C_INSTANCE            I2CDEV_1
#define MAG_I2C_INSTANCE             I2CDEV_4

#define SERIALRX_UART                SERIAL_PORT_UART4
#ifdef USE_GPS
#define GPS_UART                     SERIAL_PORT_UART8
#endif
#define MSP_DISPLAYPORT_UART         SERIAL_PORT_USART2
#define ESC_SENSOR_UART              SERIAL_PORT_USART3

#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_DSHOT_BITBANG        DSHOT_BITBANG_ON

#define SYSTEM_HSE_MHZ               16

#define SDIO_DEVICE                  SDIODEV_1
#define SDIO_USE_4BIT                1

#define PINIO1_BOX                   40
#define PINIO1_CONFIG                129
#define BOX_USER1_NAME               "10V BEC"

#define GYRO_1_SPI_INSTANCE          SPI1
#define GYRO_1_ALIGN                 CW90_DEG
