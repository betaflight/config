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

#define BOARD_NAME        SPEDIXH743
#define MANUFACTURER_ID   SPDX

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_MAX7456

#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN     PA5          // TIM2_CH1
#define GYRO_2_CLKIN_PIN     PB0          // TIM3_CH3

#define BEEPER_PIN           PD14         // TIM4_CH3
#define MOTOR1_PIN           PE9          // TIM1_CH1
#define MOTOR2_PIN           PE11         // TIM1_CH2
#define MOTOR3_PIN           PE13         // TIM1_CH3
#define MOTOR4_PIN           PE14         // TIM1_CH4
#define MOTOR5_PIN           PC8          // TIM8_CH3
#define MOTOR6_PIN           PC9          // TIM8_CH4
#define MOTOR7_PIN           PA6          // TIM3_CH1
#define MOTOR8_PIN           PA7          // TIM3_CH2

#define CAMERA_CONTROL_PIN   PA1          // TIM15_CH1N
#define LED_STRIP_PIN        PA0          // TIM5_CH1

#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PD5
#define UART3_TX_PIN         PD8
#define UART4_TX_PIN         PD1
#define UART5_TX_PIN         PB6
#define UART6_TX_PIN         PC6
#define UART7_TX_PIN         PE8
#define UART8_TX_PIN         PE1
#define UART1_RX_PIN         PB7
#define UART2_RX_PIN         PD6
#define UART3_RX_PIN         PD9
#define UART4_RX_PIN         PD0
#define UART5_RX_PIN         PD2
#define UART6_RX_PIN         PC7
#define UART7_RX_PIN         PE7
#define UART8_RX_PIN         PE0

#define I2C1_SCL_PIN         PB8
#define I2C2_SCL_PIN         PB10
#define I2C4_SCL_PIN         PD12
#define I2C1_SDA_PIN         PB9
#define I2C2_SDA_PIN         PB11
#define I2C4_SDA_PIN         PD13

#define LED0_PIN             PC4
#define LED1_PIN             PC5

// Gyro 1 SPI1
#define SPI1_SCK_PIN         PB3
#define SPI1_SDI_PIN         PB4
#define SPI1_SDO_PIN         PB5

// MAX7456 SPI2
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

// Flash SPI3
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12

// Gyro 2 SPI4
#define SPI4_SCK_PIN         PE2
#define SPI4_SDI_PIN         PE5
#define SPI4_SDO_PIN         PE6

#define ADC_VBAT_PIN         PC1
#define ADC_CURR_PIN         PC2

#define PINIO1_PIN           PA2 // VTX Switch
#define PINIO2_PIN           PA3 // Camera Switch

#define FLASH_CS_PIN         PA8
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PD7
#define GYRO_1_CS_PIN        PA15
#define GYRO_2_EXTI_PIN      PE4
#define GYRO_2_CS_PIN        PE3

#define TIMER_PIN_MAPPING \
   TIMER_PIN_MAP(  0, MOTOR1_PIN,          1,  0) \
   TIMER_PIN_MAP(  1, MOTOR2_PIN,          1,  1) \
   TIMER_PIN_MAP(  2, MOTOR3_PIN,          1,  2) \
   TIMER_PIN_MAP(  3, MOTOR4_PIN,          1,  3) \
   TIMER_PIN_MAP(  4, MOTOR5_PIN,          2,  4) \
   TIMER_PIN_MAP(  5, MOTOR6_PIN,          2,  5) \
   TIMER_PIN_MAP(  6, MOTOR7_PIN,          1,  6) \
   TIMER_PIN_MAP(  7, MOTOR8_PIN,          2,  7) \
   TIMER_PIN_MAP(  8, LED_STRIP_PIN,       2,  8) \
   TIMER_PIN_MAP(  9, GYRO_1_CLKIN_PIN,    1, -1) \
   TIMER_PIN_MAP( 10, GYRO_2_CLKIN_PIN,    2, -1) \
   TIMER_PIN_MAP( 11, BEEPER_PIN,          1, -1) \
   TIMER_PIN_MAP( 12, CAMERA_CONTROL_PIN,  3, -1)

#define TIMUP1_DMA_OPT                      12
#define TIMUP3_DMA_OPT                      13

#define ADC1_DMA_OPT                        9
#define ADC2_DMA_OPT                        10
#define ADC3_DMA_OPT                        11

#define BARO_I2C_INSTANCE                   I2CDEV_1
#define MAG_I2C_INSTANCE                    I2CDEV_2

#define PINIO1_CONFIG                       129
#define PINIO1_BOX                          40
#define BOX_USER1_NAME                      "VTX PWR"
#define PINIO2_CONFIG                       1
#define PINIO2_BOX                          41
#define BOX_USER2_NAME                      "CAM SWITCH"

#define DEFAULT_DSHOT_BITBANG               DSHOT_BITBANG_ON
#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE_DEFAULT 110
//#define DEFAULT_CURRENT_METER_SCALE         350
#define BEEPER_INVERTED
#define GYRO_1_SPI_INSTANCE                 SPI1
#define MAX7456_SPI_INSTANCE                SPI2
#define FLASH_SPI_INSTANCE                  SPI3
#define GYRO_2_SPI_INSTANCE                 SPI4
//#define GYRO_2_ALIGN                    CW90_DEG
