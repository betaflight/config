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

#define FC_TARGET_MCU     STM32F7X2

#define BOARD_NAME        NERO
#define MANUFACTURER_ID   BKMN

#define USE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_SDCARD

// Basic I/O
#define LED0_PIN             PB6
#define LED1_PIN             PB5
#define LED2_PIN             PB4
#define BEEPER_PIN           PC1
#define BEEPER_INVERTED
#define LED_STRIP_PIN        PB0 // Shared with MOTOR5_PIN
#define ESCSERIAL_PIN        PC7

// Motors
#define MOTOR1_PIN           PA0
#define MOTOR2_PIN           PA1
#define MOTOR3_PIN           PA2
#define MOTOR4_PIN           PA3
#define MOTOR5_PIN           PB0 // Shared with LED_STRIP_PIN
#define MOTOR6_PIN           PB1
#define MOTOR7_PIN           PC8
#define MOTOR8_PIN           PC9
#define RX_PPM_PIN           PC7
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_ON

// UART
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART3_TX_PIN         PB10
#define UART3_RX_PIN         PB11
#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7

// I2C
#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9

// ADC
#define ADC_VBAT_PIN         PC3
#define ADC_CURR_PIN         PC2 // --> pin AD
#define ADC_RSSI_PIN         PA4 // --> pin DA
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

// GYRO & ACC --> SPI1
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define GYRO_1_CS_PIN        PC4
#define GYRO_1_EXTI_PIN      PB15
#define GYRO_1_SPI_INSTANCE  SPI1

// ACC_SPI --> SPI2 (CS pin PB12)
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

// SDCARD --> SPI3
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12
#define SDCARD_SPI_CS_PIN    PA15
#define SDCARD_DETECT_PIN    PD2
#define SDCARD_DETECT_INVERTED
#define SDCARD_SPI_INSTANCE  SPI3
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA0 , 2,  0) \
    TIMER_PIN_MAP( 1, PA1 , 2,  0) \
    TIMER_PIN_MAP( 2, PA2 , 2, -1) \
    TIMER_PIN_MAP( 3, PA3 , 2, -1) \
    TIMER_PIN_MAP( 4, PB0 , 2,  0) \
    TIMER_PIN_MAP( 5, PB1 , 2,  0) \
    TIMER_PIN_MAP( 6, PC7 , 2, -1) \
    TIMER_PIN_MAP( 7, PC8 , 2, -1) \
    TIMER_PIN_MAP( 8, PC9 , 2, -1)

#define ADC1_DMA_OPT        1
