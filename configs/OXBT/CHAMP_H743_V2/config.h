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

#define BOARD_NAME        CHAMP_H743_V2
#define MANUFACTURER_ID   OXBT

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_SPI_MPU6000
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456
#define USE_BARO
#define USE_BARO_DPS310

#define MOTOR1_PIN         PA0
#define MOTOR2_PIN         PA1
#define MOTOR3_PIN         PA2
#define MOTOR4_PIN         PA3

#define UART1_TX_PIN       PA9
#define UART1_RX_PIN       PA10
#define UART2_RX_PIN       PD6
#define UART5_TX_PIN       PC12
#define UART5_RX_PIN       PD2
#define UART6_TX_PIN       PC6
#define UART6_RX_PIN       PC7
#define UART7_RX_PIN       PE7
#define UART8_TX_PIN       PE1
#define UART8_RX_PIN       PE0
#define RX_PPM_PIN         PC7

#define I2C2_SCL_PIN       PB10
#define I2C2_SDA_PIN       PB11

#define SPI1_SCK_PIN       PA5
#define SPI1_SDI_PIN       PA6
#define SPI1_SDO_PIN       PD7
#define GYRO_1_CS_PIN      PC15
#define GYRO_1_EXTI_PIN    PB2
#define GYRO_1_CLKIN_PIN   PA8

#define SPI2_SCK_PIN       PB13
#define SPI2_SDI_PIN       PB14
#define SPI2_SDO_PIN       PB15
#define MAX7456_SPI_CS_PIN PB12

#define SPI3_SCK_PIN       PB3
#define SPI3_SDI_PIN       PB4
#define SPI3_SDO_PIN       PB5
#define FLASH_CS_PIN       PD4

#define ADC_VBAT_PIN       PC0
#define ADC_CURR_PIN       PC1
#define LED0_PIN           PB7
#define LED_STRIP_PIN      PD12
#define BEEPER_PIN         PA15
#define PINIO1_PIN         PA7

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN,         2,  0) \
    TIMER_PIN_MAP(1, MOTOR2_PIN,         2,  1) \
    TIMER_PIN_MAP(2, MOTOR3_PIN,         2,  2) \
    TIMER_PIN_MAP(3, MOTOR4_PIN,         2,  3) \
    TIMER_PIN_MAP(4, RX_PPM_PIN,         1, -1) \
    TIMER_PIN_MAP(5, LED_STRIP_PIN,      1,  4) \
    TIMER_PIN_MAP(6, GYRO_1_CLKIN_PIN,   1, -1) \
    TIMER_PIN_MAP(7, BEEPER_PIN,         1, -1)

#define ADC1_DMA_OPT    5
#define ADC3_DMA_OPT    6
#define TIMUP5_DMA_OPT  7
#define PINIO1_CONFIG   129
#define PINIO1_BOX      40
#define BOX_USER1_NAME  "VTX BEC OFF"

#define BEEPER_INVERTED
#define ADC_INSTANCE ADC1
#define MAG_I2C_INSTANCE     I2CDEV_2
#define BARO_I2C_INSTANCE    I2CDEV_2
#define GYRO_1_SPI_INSTANCE  SPI1
#define MAX7456_SPI_INSTANCE SPI2
#define FLASH_SPI_INSTANCE   SPI3

#define DEFAULT_ALIGN_BOARD_YAW      90
#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_TELEMETRY      DSHOT_TELEMETRY_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_NONE
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

#define MSP_UART             SERIAL_PORT_USART1
#define MSP_DISPLAYPORT_UART SERIAL_PORT_UART5
#define SERIALRX_UART        SERIAL_PORT_USART6
