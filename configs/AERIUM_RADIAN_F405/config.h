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

#define FC_TARGET_MCU     STM32F405

#define BOARD_NAME        AERIUM_RADIAN_F405
#define MANUFACTURER_ID   AERIUM

#define USE_GYRO
#define USE_SPI_GYRO
#define USE_ACC

// This board features dual IMUs
// BMI270 currently disabled since ICM42688P is better
// #define USE_ACCGYRO_BMI270
// #define GYRO_1_SPI_INSTANCE             SPI1
// #define GYRO_1_ALIGN                    CW270_DEG_FLIP
// #define GYRO_1_EXTI_PIN                 PA15
// #define GYRO_1_CS_PIN                   PB4

#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define GYRO_1_SPI_INSTANCE             SPI2
#define GYRO_1_ALIGN                    CW180_DEG_FLIP
#define GYRO_1_EXTI_PIN                 PC4
#define GYRO_1_CS_PIN                   PC3

#define USE_BARO
#define USE_BARO_SPI_BMP280
#define BARO_SPI_INSTANCE       SPI2
#define BARO_CS_PIN             PB12

#define USE_SDCARD
#define USE_SDCARD_SPI
#define SDCARD_SPI_INSTANCE     SPI3
#define SDCARD_SPI_CS_PIN       PC13

#define USE_MAG
#define USE_MAG_LIS3MDL
#define MAG_I2C_INSTANCE        I2CDEV_1
#define DEFAULT_MAG_I2C_ADDRESS 28
#define DEFAULT_MAG_HARDWARE    AUTO

#define BEEPER_PIN           PA0

#define MOTOR1_PIN           PB1
#define MOTOR2_PIN           PB0
#define MOTOR3_PIN           PA8
#define MOTOR4_PIN           PA3
#define MOTOR5_PIN           PA2
#define MOTOR6_PIN           PA1
#define MOTOR7_PIN           PC9
#define MOTOR8_PIN           PC8

#define RX_PPM_PIN           PB5

#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10

#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7

#define UART3_TX_PIN         PC10
#define UART3_RX_PIN         PC11

#define I2C1_SCL_PIN         PB6
#define I2C1_SDA_PIN         PB7

#define LED0_PIN             PB3

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7

#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN, 2,  0) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN, 2,  0) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN, 1,  1) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN, 1,  1) \
    TIMER_PIN_MAP( 4, MOTOR5_PIN, 1,  0) \
    TIMER_PIN_MAP( 5, MOTOR6_PIN, 1,  0) \
    TIMER_PIN_MAP( 6, MOTOR7_PIN, 1,  0) \
    TIMER_PIN_MAP( 7, MOTOR8_PIN, 1,  0) \
    TIMER_PIN_MAP(12, BEEPER_PIN, 2, -1) \
    TIMER_PIN_MAP(13, RX_PPM_PIN, 3, -1)

#define SYSTEM_HSE_MHZ                  8
