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

#define BOARD_NAME           SPEEDYBEEF435AIOELRS
#define MANUFACTURER_ID      SPBE

#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_BARO
#define USE_BARO_DPS310
#define USE_GYRO_CLKIN

#define MOTOR1_PIN              PB6
#define MOTOR2_PIN              PB7
#define MOTOR3_PIN              PB0
#define MOTOR4_PIN              PB1

#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10
#define UART2_RX_PIN            PA3
#define UART3_TX_PIN            PB10
#define UART3_RX_PIN            PB11
#define UART5_TX_PIN            PB9
#define UART5_RX_PIN            PB8
#define UART7_TX_PIN            PB4
#define UART7_RX_PIN            PB3

#define I2C2_SCL_PIN            PH2
#define I2C2_SDA_PIN            PH3

#define SPI1_SCK_PIN            PA5
#define SPI1_SDI_PIN            PA6
#define SPI1_SDO_PIN            PA7
#define GYRO_1_CS_PIN           PA4
#define GYRO_1_EXTI_PIN         PA15
#define GYRO_1_CLKIN_PIN        PA2

#define SPI2_SCK_PIN            PB13
#define SPI2_SDI_PIN            PB14
#define SPI2_SDO_PIN            PB15
#define FLASH_CS_PIN            PC13

#define ADC_CURR_PIN            PA1
#define ADC_VBAT_PIN            PA0
#define LED0_PIN                PA8
#define BEEPER_PIN              PB5
#define LED_STRIP_PIN           PB12

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN,       1,  1) \
    TIMER_PIN_MAP(1, MOTOR2_PIN,       1,  2) \
    TIMER_PIN_MAP(2, MOTOR3_PIN,       2,  3) \
    TIMER_PIN_MAP(3, MOTOR4_PIN,       2,  4) \
    TIMER_PIN_MAP(4, LED_STRIP_PIN,    1,  0) \
    TIMER_PIN_MAP(5, GYRO_1_CLKIN_PIN, 1, -1)

#define ADC_INSTANCE            ADC1
#define ADC1_DMA_OPT            11
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ          8

#define BARO_I2C_INSTANCE       I2CDEV_2
#define MAG_I2C_INSTANCE        I2CDEV_2
#define GYRO_1_ALIGN            CW90_DEG
#define GYRO_1_SPI_INSTANCE     SPI1
#define FLASH_SPI_INSTANCE      SPI2

#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG        DSHOT_BITBANG_ON
#define DEFAULT_DSHOT_TELEMETRY      DSHOT_TELEMETRY_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE  250

#define MSP_UART      SERIAL_PORT_USART1
#define SERIALRX_UART SERIAL_PORT_UART5
