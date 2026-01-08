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

#define BOARD_NAME        SIMPLIFLYF405
#define MANUFACTURER_ID   SFLY

#define USE_GYRO
#define USE_ACC
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_MAX7456
#define USE_FLASH
#define USE_FLASH_W25Q128FV

#define BEEPER_INVERTED
#define BEEPER_PIN           PB1

#define MOTOR1_PIN           PC6
#define MOTOR2_PIN           PC7
#define MOTOR3_PIN           PC8
#define MOTOR4_PIN           PC9

#define RX_PPM_PIN           PA1

#define LED_STRIP_PIN        PB6

#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PA2
#define UART3_TX_PIN         PB10
#define UART4_TX_PIN         PA0
#define UART5_TX_PIN         PC12
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PB11
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PD2

// I2C1 for Mag/Baro
#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9
#define MAG_I2C_INSTANCE     I2CDEV_1
#define BARO_I2C_INSTANCE    I2CDEV_1

#define LED0_PIN             PB0

// SPI1 for Gyro/Acc
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define GYRO_1_EXTI_PIN      PC5
#define GYRO_1_CS_PIN        PC4
#define GYRO_1_SPI_INSTANCE  SPI1
#define GYRO_1_ALIGN         CW270_DEG_FLIP
#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN     PA8

// SPI2 for Max7456 OSD
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15
#define MAX7456_SPI_CS_PIN   PB12
#define MAX7456_SPI_INSTANCE SPI2

// SPI3 for Flash
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PB5
#define FLASH_CS_PIN         PB7
#define FLASH_SPI_INSTANCE   SPI3
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH

#define CAMERA_CONTROL_PIN   PB3

#define ADC_VBAT_PIN         PC2
#define ADC_RSSI_PIN         PC0
#define ADC_CURR_PIN         PC1

// PinIO
#define PINIO1_PIN           PB2
#define PINIO1_CONFIG        129
#define PINIO1_BOX           40
#define BOX_USER1_NAME       "9V BEC"

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN , 2,  1 ) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN , 2,  1 ) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN , 2,  1 ) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN , 2,  0 ) \
    TIMER_PIN_MAP( 4, LED_STRIP_PIN , 1,  0 ) \
    TIMER_PIN_MAP( 5, CAMERA_CONTROL_PIN , 1, -1 ) \
    TIMER_PIN_MAP( 6, RX_PPM_PIN , 2, -1 ) \
    TIMER_PIN_MAP( 7, BEEPER_PIN , 1, -1 )  \
    TIMER_PIN_MAP( 8, GYRO_1_CLKIN_PIN , 1, -1 ) 

#define ADC_INSTANCE         ADC3
#define ADC3_DMA_OPT         1

#define SYSTEM_HSE_MHZ 8
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
