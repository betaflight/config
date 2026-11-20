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
  VERSION: 2026.12.0
*/
#pragma once

#define FC_TARGET_MCU        STM32F765

#define BOARD_NAME           LUXNDAAF7
#define MANUFACTURER_ID      LMNR
#define SYSTEM_HSE_MHZ       8

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456
#define USE_SDCARD

#ifndef USE_MAG
#define USE_MAG
#endif

// PE13 (PPM), PB10/PB11 (I2C2), PC1 (RSSI) and PC5 (PINIO1) are defined as in
// Lumenier's shipping 4.5.1 firmware; not confirmed on the board.
#define BEEPER_PIN           PC8

#define MOTOR1_PIN           PA0
#define MOTOR2_PIN           PA1
#define MOTOR3_PIN           PA2
#define MOTOR4_PIN           PA3
#define MOTOR5_PIN           PD12
#define MOTOR6_PIN           PD13
#define MOTOR7_PIN           PD14
#define MOTOR8_PIN           PD15

#define RX_PPM_PIN           PE13

#define LED_STRIP_PIN        PB5

#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PD5
#define UART3_TX_PIN         PD8
#define UART4_TX_PIN         PD1
#define UART5_TX_PIN         PB6
#define UART6_TX_PIN         PC6
#define UART7_TX_PIN         PE8
#define UART8_TX_PIN         PE1

#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PD6
#define UART3_RX_PIN         PD9
#define UART4_RX_PIN         PD0
#define UART5_RX_PIN         PD2
#define UART6_RX_PIN         PC7
#define UART7_RX_PIN         PE7
#define UART8_RX_PIN         PE0

#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define I2C3_SCL_PIN         PA8
#define I2C3_SDA_PIN         PC9

#define LED0_PIN             PE4

#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PC10
#define SPI4_SCK_PIN         PE2

#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PC11
#define SPI4_SDI_PIN         PE5

#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PC12
#define SPI4_SDO_PIN         PE6

#define CAMERA_CONTROL_PIN   PE10

#define ADC_VBAT_PIN         PC3
#define ADC_RSSI_PIN         PC1
#define ADC_CURR_PIN         PC2

#define SDCARD_SPI_CS_PIN    PE12
#define SDCARD_DETECT_PIN    PE3
#define PINIO1_PIN           PC5
#define FLASH_CS_PIN         PB12
#define MAX7456_SPI_CS_PIN   PA15
#define GYRO_1_EXTI_PIN      PE14
#define GYRO_1_CS_PIN        PA4
#define USB_DETECT_PIN       PC4

/*
    PE13 - TIM1_CH3
    PB5 -  TIM3_CH2
    PB0 -  TIM3_CH3
    PB1 -  TIM3_CH4
    PE9 -  TIM1_CH1
    PE11 - TIM1_CH2
    PA0 -  TIM2_CH1
    PA1 -  TIM2_CH2
    PA2 -  TIM2_CH3
    PA3 -  TIM2_CH4
    PD12 - TIM4_CH1
    PD13 - TIM4_CH2
    PD14 - TIM4_CH3
    PD15 - TIM4_CH4
    PB0, PB1, PE9, PE11 are the S1-S4 PWM pads (pin-to-pad order not confirmed)
*/

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0,  RX_PPM_PIN,          1, 1) \
    TIMER_PIN_MAP( 1,  LED_STRIP_PIN,       1, 0) \
    TIMER_PIN_MAP( 2,  PB0,                 2, 0) \
    TIMER_PIN_MAP( 3,  PB1,                 2, 0) \
    TIMER_PIN_MAP( 4,  PE9,                 1, 2) \
    TIMER_PIN_MAP( 5,  PE11,                1, 1) \
    TIMER_PIN_MAP( 6,  MOTOR1_PIN,          1, 0) \
    TIMER_PIN_MAP( 7,  MOTOR2_PIN,          1, 0) \
    TIMER_PIN_MAP( 8,  MOTOR3_PIN,          1, 0) \
    TIMER_PIN_MAP( 9,  MOTOR4_PIN,          1, 0) \
    TIMER_PIN_MAP( 10, MOTOR5_PIN,          1, 0) \
    TIMER_PIN_MAP( 11, MOTOR6_PIN,          1, 0) \
    TIMER_PIN_MAP( 12, MOTOR7_PIN,          1, 0) \
    TIMER_PIN_MAP( 13, MOTOR8_PIN,          1, -1) // TIM4_CH4 has no DMA on F7

#define ADC1_DMA_OPT                        1
#define SPI4_TX_DMA_OPT                     0

#define MAG_I2C_INSTANCE                    I2CDEV_3
#define BARO_I2C_INSTANCE                   I2CDEV_3
#define DEFAULT_BARO_I2C_ADDRESS            118

#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE         179
#define BEEPER_INVERTED

#define GYRO_1_SPI_INSTANCE                 SPI1
#define GYRO_1_ALIGN                        CW0_DEG_FLIP
#define FLASH_SPI_INSTANCE                  SPI2
#define MAX7456_SPI_INSTANCE                SPI3
#define SDCARD_SPI_INSTANCE                 SPI4
#define SDCARD_DETECT_INVERTED

#define PINIO1_CONFIG                       129
#define PINIO1_BOX                          0
