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

#define FC_TARGET_MCU        AT32F435G

#define BOARD_NAME           ACCIF435ELITE
#define MANUFACTURER_ID      FOSS

#define USE_ACC
#define USE_GYRO

#define USE_GYRO_CLKIN
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define USE_BARO
#define USE_BARO_DPS310
#define DEFAULT_BARO_I2C_ADDRESS 119

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G

// I/O
#define LED0_PIN             PC15
#define LED1_PIN             PC14
#define BEEPER_PIN           PC13
#define BEEPER_INVERTED
#define LED_STRIP_PIN        PB3

// ACC/GYRO SPI 1
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_CS_PIN        PA4
#define GYRO_1_SPI_INSTANCE  SPI1

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7

// FLASH SPI 2
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

#define FLASH_CS_PIN         PB12
#define FLASH_SPI_INSTANCE   SPI2

// ADC
#define USE_ADC
#define ADC_VBAT_PIN         PC1
#define ADC_RSSI_PIN         PC2
#define ADC_CURR_PIN         PC3
#define ADC_INSTANCE         ADC1

// UART PORTS
#define UART1_TX_PIN         PB6
#define UART1_RX_PIN         PB7

#define UART2_TX_PIN         PA2
#define UART2_RX_PIN         PA3

#define UART3_TX_PIN         PB10
#define UART3_RX_PIN         PB11

#define UART4_TX_PIN         PA0
#define UART4_RX_PIN         PA1

#define UART5_TX_PIN         PC12
#define UART5_RX_PIN         PD2

#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7

#define GYRO_1_CLKIN_PIN     PC5

// MOTORS PINOUT
#define MOTOR1_PIN           PA9
#define MOTOR2_PIN           PA8
#define MOTOR3_PIN           PC9
#define MOTOR4_PIN           PC8

// TIMERS
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA9 , 1,   0) \
    TIMER_PIN_MAP( 1, PA8 , 1,   1) \
    TIMER_PIN_MAP( 2, PC9 , 1,   2) \
    TIMER_PIN_MAP( 3, PC8 , 1,   3) \
    TIMER_PIN_MAP( 4, PB3 , 1,   4) \
    TIMER_PIN_MAP( 5, PC5 , 1,  -1)

#define ADC1_DMA_OPT         8

// I2C
#define BARO_I2C_INSTANCE    I2CDEV_1
#define MAG_I2C_INSTANCE     I2CDEV_1

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9

// USERS
#define PINIO1_PIN           PB1
#define PINIO1_BOX           40
#define PINIO1_CONFIG        129
#define BOX_USER1_NAME       "VTX PWR"

// DEFAULTS
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     113
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON
