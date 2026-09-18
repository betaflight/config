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

#define BOARD_NAME        KONEXH743
#define MANUFACTURER_ID   KONX

#define USE_GYRO
#define USE_GYRO_CLKIN
#define USE_ACC
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P

#define USE_FLASH
#define USE_FLASH_W25N01G

#define USE_BARO
#define USE_BARO_BMP388

#define LED0_PIN PC13
#define LED1_PIN PC10

#define LED_STRIP_PIN PC9
  
#define BEEPER_PIN PE10
#define BEEPER_INVERTED

#define UART3_TX_PIN PD8
#define UART3_RX_PIN PD9

#define UART4_TX_PIN PA0
#define UART4_RX_PIN PA1

#define UART5_RX_PIN PD2

#define UART6_TX_PIN PC6
#define UART6_RX_PIN PC7

#define UART7_RX_PIN PA8

#define UART8_TX_PIN PE1
#define UART8_RX_PIN PE0

#define I2C2_SCL_PIN PB10
#define I2C2_SDA_PIN PB11
#define I2C4_SCL_PIN PD12
#define I2C4_SDA_PIN PD13

#define SPI1_SCK_PIN PA5
#define SPI1_SDI_PIN PA6
#define SPI1_SDO_PIN PA7
#define GYRO_1_CS_PIN PB1
#define GYRO_1_EXTI_PIN PB0

#define SPI2_SCK_PIN PB13
#define SPI2_SDI_PIN PB14
#define SPI2_SDO_PIN PB15
#define GYRO_2_CS_PIN PB12
#define GYRO_2_EXTI_PIN PE13

#define SPI4_SCK_PIN PE2
#define SPI4_SDI_PIN PE5
#define SPI4_SDO_PIN PE6
#define FLASH_CS_PIN PE4

#define ADC_VBAT_PIN PC0
#define ADC_CURR_PIN PC5
#define ADC_EXTERNAL1_PIN PC1

#define MOTOR1_PIN PB6
#define MOTOR2_PIN PB7
#define MOTOR3_PIN PB8
#define MOTOR4_PIN PB9
#define MOTOR5_PIN PB4
#define MOTOR6_PIN PB5
#define MOTOR7_PIN PB3
#define MOTOR8_PIN PA15

#define VTX_ENABLE_PIN                PE3
#define PINIO1_PIN                    VTX_ENABLE_PIN
#define PINIO1_BOX 40
#define PINIO1_CONFIG 129

#define GYRO_1_CLKIN_PIN PA3

// Index, Pin, 1-based occurrence of pin in fullTimerHardware, dma opt (use -1 for no DMA)
// See timerio.c and timer_stm32h7xx.c

// MOTOR1 PB6 TIM4 CH1
// MOTOR2 PB7 TIM4 CH2
// MOTOR3 PB8 TIM4 CH3
// MOTOR4 PB9 TIM4 CH4
// MOTOR5 PB4 TIM3 CH1
// MOTOR6 PB5 TIM3 CH2
// MOTOR7 PB3 TIM2 CH2
// MOTOR8 PA15 TIM2 CH1

// LED PC9 TIM8 CH4

// CLKIN PA3 TIM15_CH2

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB6 , 2,  1 ) \
    TIMER_PIN_MAP( 1, PB7 , 2,  2 ) \
    TIMER_PIN_MAP( 2, PB8 , 2,  3 ) \
    TIMER_PIN_MAP( 3, PB9 , 2,  4 ) \
    TIMER_PIN_MAP( 4, PB4 , 1,  5 ) \
    TIMER_PIN_MAP( 5, PB5 , 1,  6 ) \
    TIMER_PIN_MAP( 6, PB3 , 1,  7 ) \
    TIMER_PIN_MAP( 7, PA15, 1, 11 ) \
    TIMER_PIN_MAP( 8, PC9 , 2,  0 ) \
    TIMER_PIN_MAP( 9, PA3 , 3, -1 )

#define ADC1_DMA_OPT 8
#define ADC2_DMA_OPT 9
#define ADC3_DMA_OPT 10

#define SERIALRX_UART SERIAL_PORT_UART4

#define BARO_I2C_INSTANCE I2CDEV_2
#define MAG_I2C_INSTANCE I2CDEV_4
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH

#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC

#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE 156

#define FLASH_SPI_INSTANCE SPI4

#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_2_SPI_INSTANCE SPI2

#define GYRO_1_ALIGN CW90_DEG
#define GYRO_2_ALIGN CW0_DEG

#define DEFAULT_GYRO_TO_USE GYRO_CONFIG_USE_GYRO_BOTH
