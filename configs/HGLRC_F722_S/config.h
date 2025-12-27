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
#define BOARD_NAME        HGLRC_F722_S
#define MANUFACTURER_ID   HGLR

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

#define BEEPER_PIN           PC13
#define MOTOR1_PIN           PC9
#define MOTOR2_PIN           PC7
#define MOTOR3_PIN           PC8
#define MOTOR4_PIN           PC6
#define LED_STRIP_PIN        PA8
#define UART1_TX_PIN         PB6
#define UART2_TX_PIN         PA2
#define UART5_TX_PIN         PC12
#define UART1_RX_PIN         PB6
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PC11
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PD2
#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9
#define LED1_PIN             PC0
#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PB3
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PB4
#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PB5
#define ADC_VBAT_PIN         PC2
#define ADC_CURR_PIN         PC1
#define FLASH_CS_PIN         PA15
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_CLKIN_PIN     PB10
#define GYRO_1_CS_PIN        PA4

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, LED_STRIP_PIN , 1, -1) \
    TIMER_PIN_MAP( 1, MOTOR1_PIN , 3,  4) \
    TIMER_PIN_MAP( 2, MOTOR2_PIN , 3,  2) \
    TIMER_PIN_MAP( 3, MOTOR3_PIN , 3,  3) \
    TIMER_PIN_MAP( 4, MOTOR4_PIN , 3,  1)


#define SPI3_TX_DMA_OPT     1
#define ADC1_DMA_OPT        0


#define MAG_I2C_INSTANCE I2CDEV_1
#define USE_BARO
#define BARO_I2C_INSTANCE I2CDEV_1
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE 110               
#define DEFAULT_CURRENT_METER_SCALE 400    
#define BEEPER_INVERTED
#define FLASH_SPI_INSTANCE SPI3
#define MAX7456_SPI_INSTANCE SPI2
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW0_DEG
#define DEFAULT_ALIGN_BOARD_YAW 45
