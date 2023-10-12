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

#define FC_TARGET_MCU     AT32F435G

#define BOARD_NAME        BAYCK_DOLPHIN_MINI
#define MANUFACTURER_ID   BKRC

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_MPU6500
#define USE_GYRO_SPI_ICM42688P

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_MPU6500
#define USE_ACC_SPI_ICM42688P

#define USE_BARO
#define USE_BARO_SPI_BMP280

#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G

#define USE_MAX7456

#define BEEPER_PIN           PA13
#define MOTOR1_PIN           PB1
#define MOTOR2_PIN           PB0
#define MOTOR3_PIN           PA3
#define MOTOR4_PIN           PA2
#define MOTOR5_PIN           PB6
#define MOTOR6_PIN           PB7
#define LED_STRIP_PIN        PA8
#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PA14
#define UART4_TX_PIN         PH3
#define UART5_TX_PIN         PB9
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA15
#define UART3_RX_PIN         PB11
#define UART5_RX_PIN         PB8
#define LED0_PIN             PC13
#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PB3
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PB4
#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PB5
#define CAMERA_CONTROL_PIN   PB10
#define ADC_VBAT_PIN         PA0
#define ADC_CURR_PIN         PA1
#define BARO_CS_PIN          PC15
#define FLASH_CS_PIN         PB12
#define MAX7456_SPI_CS_PIN   PC14
#define GYRO_1_EXTI_PIN      PH2
#define GYRO_1_CS_PIN        PA4

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN     , 2,  2) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN     , 2,  7) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN     , 1,  6) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN     , 2,  1) \
    TIMER_PIN_MAP( 4, MOTOR5_PIN     , 1, 13) \
    TIMER_PIN_MAP( 5, MOTOR6_PIN     , 1, 14) \
    TIMER_PIN_MAP( 6, LED_STRIP_PIN  , 1, 12) \
    TIMER_PIN_MAP( 7, UART1_TX_PIN   , 1,  5) \
    TIMER_PIN_MAP( 8, UART1_RX_PIN   , 1,  4) \
    TIMER_PIN_MAP( 9, CAMERA_CONTROL_PIN, 1, 3) \
    TIMER_PIN_MAP(10, UART2_RX_PIN   , 1,  8) \
    TIMER_PIN_MAP(11, UART3_RX_PIN   , 2, 10) \
    TIMER_PIN_MAP(12, UART5_TX_PIN   , 2,  0) \
    TIMER_PIN_MAP(13, UART5_RX_PIN   , 2,  9)

#define ADC_INSTANCE ADC1
#define ADC1_DMA_OPT        11
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_FLASH
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ 8
#define BARO_SPI_INSTANCE SPI3
#define MAX7456_SPI_INSTANCE SPI3
#define FLASH_SPI_INSTANCE SPI2
#define USE_SPI_GYRO
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW270_DEG
