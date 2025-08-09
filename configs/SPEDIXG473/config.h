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
    SUPPORTED TARGET - THANK YOU
    REFERENCE: sha256_27d31a264bc7dbf0640e384ee1e697a1a88a6cc7c8408a08e3140147113a3cb9
*/
#pragma once

#define FC_TARGET_MCU     STM32G47X

#define BOARD_NAME        SPEDIXG473
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

#define BEEPER_PIN           PA8
#define MOTOR1_PIN           PB1
#define MOTOR2_PIN           PB0
#define MOTOR3_PIN           PB9
#define MOTOR4_PIN           PB6
#define LED_STRIP_PIN        PB2
#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PA2
#define UART3_TX_PIN         PB10
#define UART4_TX_PIN         PC10
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PB11
#define UART4_RX_PIN         PC11
#define I2C1_SCL_PIN         PA15
#define I2C1_SDA_PIN         PB7
#define LED0_PIN             PC6
#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PB3
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PB4
#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PB5
#define PINIO1_PIN           PC14
#define PINIO2_PIN           PC15
#define ADC_VBAT_PIN         PA1
#define ADC_CURR_PIN         PA0
#define FLASH_CS_PIN         PC13
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_CS_PIN        PA4

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB1, 1,  1) \
    TIMER_PIN_MAP( 1, PB0, 1,  2) \
    TIMER_PIN_MAP( 2, PB9, 2,  3) \
    TIMER_PIN_MAP( 3, PB6, 2,  4) \
    TIMER_PIN_MAP( 4, PB2, 1,  5) \
    TIMER_PIN_MAP( 5, PA8, 1, -1)

#define ADC1_DMA_OPT         0

#define PINIO1_BOX           40
#define PINIO2_BOX           41
#define PINIO2_CONFIG        1
#define BOX_USER2_NAME       "VTXPWR"

#define BARO_I2C_INSTANCE	 I2CDEV_1
#define MAG_I2C_INSTANCE	 I2CDEV_1
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST  DSHOT_DMAR_OFF
#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ 8
#define MAX7456_SPI_INSTANCE SPI2
#define FLASH_SPI_INSTANCE   SPI3
#define GYRO_1_SPI_INSTANCE  SPI1
#define DEFAULT_ALIGN_BOARD_YAW 315
