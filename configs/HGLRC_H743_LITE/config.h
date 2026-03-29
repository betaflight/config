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

#define FC_TARGET_MCU       STM32H743

#define BOARD_NAME          HGLRC_H743_LITE
#define MANUFACTURER_ID     HGLR

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_MAX7456
#define USE_FLASH
#define USE_FLASH_W25Q128FV

#define SPI1_SCK_PIN            PA5
#define SPI1_SDI_PIN            PA6
#define SPI1_SDO_PIN            PA7
#define GYRO_1_EXTI_PIN         PC5
#define GYRO_1_CS_PIN           PA4
#define GYRO_1_SPI_INSTANCE     SPI1
#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN        PC6
#define GYRO_1_ALIGN            CW180_DEG_FLIP

#define SPI2_SCK_PIN            PB13
#define SPI2_SDI_PIN            PB14
#define SPI2_SDO_PIN            PB15
#define MAX7456_SPI_CS_PIN      PB12
#define MAX7456_SPI_INSTANCE    SPI2

#define SPI3_SCK_PIN            PB3
#define SPI3_SDI_PIN            PB4
#define SPI3_SDO_PIN            PB2
#define FLASH_CS_PIN            PA15
#define FLASH_SPI_INSTANCE      SPI3
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH

#define BEEPER_PIN              PE5
#define MOTOR1_PIN              PE9
#define MOTOR2_PIN              PE11
#define MOTOR3_PIN              PE13
#define MOTOR4_PIN              PE14
#define LED_STRIP_PIN           PA0

#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10
#define UART2_TX_PIN            PD5
#define UART2_RX_PIN            PD6
#define UART3_TX_PIN            PD8
#define UART3_RX_PIN            PD9
#define UART4_TX_PIN            PD1
#define UART4_RX_PIN            PA1
#define UART5_TX_PIN            PB6
#define UART5_RX_PIN            PB5
#define UART7_TX_PIN            PE8
#define UART7_RX_PIN            PE7
#define UART8_TX_PIN            PE1
#define UART8_RX_PIN            PE0

#define I2C1_SCL_PIN            PB8
#define I2C1_SDA_PIN            PB7
#define I2C2_SCL_PIN            PB10
#define I2C2_SDA_PIN            PB11

#define LED0_PIN                PE4
#define LED1_PIN                PE6
#define LED2_PIN                PE3

#define ADC_VBAT_PIN            PC0
#define ADC_CURR_PIN            PC1

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, BEEPER_PIN,       1, -1) \
    TIMER_PIN_MAP(1, MOTOR1_PIN,       1,  0) \
    TIMER_PIN_MAP(2, MOTOR2_PIN,       1,  1) \
    TIMER_PIN_MAP(3, MOTOR3_PIN,       1,  2) \
    TIMER_PIN_MAP(4, MOTOR4_PIN,       1,  3) \
    TIMER_PIN_MAP(5, LED_STRIP_PIN,    1,  8) \
    TIMER_PIN_MAP(6, GYRO_1_CLKIN_PIN, 1, -1)

#define ADC1_DMA_OPT        9
#define ADC3_DMA_OPT        10
#define TIMUP1_DMA_OPT      11
#define TIMUP5_DMA_OPT      12

#define BARO_I2C_INSTANCE   I2CDEV_1
#define MAG_I2C_INSTANCE    I2CDEV_2

#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     210

#define PINIO1_PIN     PC13
#define PINIO1_BOX     40
#define PINIO1_CONFIG  129
#define BOX_USER1_NAME "12V BEC"

#define BEEPER_INVERTED
