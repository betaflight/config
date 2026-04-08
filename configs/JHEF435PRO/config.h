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

#define BOARD_NAME           JHEF435PRO
#define MANUFACTURER_ID      JHEF

#define USE_ACC
#define USE_GYRO
#define USE_GYRO_CLKIN

#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define USE_BARO
#define USE_BARO_DPS310

#define USE_FLASH
#define USE_FLASH_W25Q128FV

#define USE_MAX7456

#define BEEPER_PIN          PC15
#define LED_STRIP_PIN       PB6  // TMR4_CH1 / I2C1_SCL / SPI4_CS / USART1_TX / UART5_TX
#define MOTOR1_PIN          PA0  // TMR2_CH1 / TMR5_CH1 / I2C2_SCL / UART4_TX
#define MOTOR2_PIN          PA1  // TMR2_CH2 / TMR5_CH2 / I2C2_SDA / SPI4_MOSI / UART4_RX
#define MOTOR3_PIN          PA3  // TMR2_CH4 / TMR5_CH4 / TMR9_CH2 / USART2_RX
#define MOTOR4_PIN          PA2  // TMR2_CH3 / TMR5_CH3 / TMR9_CH1 / USART2_TX / SDIO2_CK
#define UART1_TX_PIN        PA9  // TMR1_CH2 / SPI2_SCK / USART1_TX / I2C1_SCL
#define UART4_TX_PIN        PH3  // TMR5_CH1 / I2C2_SCL / UART4_RX
#define UART5_TX_PIN        PB9  // TMR2_CH2 / TMR4_CH4 / TMR11_CH1 / I2C1_SDA / SPI2_CS / SPI4_MOSI / I2C2_SDA / UART5_TX
#define UART1_RX_PIN        PA10 // TMR1_CH3 / SPI2_MOSI / USART1_RX / I2C1_SDA
#define UART4_RX_PIN        PH2  // TMR5_CH2 / I2C2_SDA / UART4_TX
#define UART5_RX_PIN        PB8  // TMR2_CH1 / TMR4_CH3 / TMR10_CH1 / I2C1_SCL / SPI4_MISO / UART5_RX
#define LED0_PIN            PB7  // TMR4_CH2 / I2C1_SDA / SPI4_SCK
#define I2C2_SCL_PIN        PB10 // TMR2_CH3 / I2C2_SCL / SPI2_SCK / USART3_TX
#define I2C2_SDA_PIN        PB11 // TMR2_CH4 / TMR5_CH4 / I2C2_SDA / USART3_RX
#define SPI1_SCK_PIN        PA5  // TMR2_CH1 / TMR8_CH1C / SPI1_SCK / USART6_RX
#define SPI2_SCK_PIN        PB13 // TMR1_CH1C / SPI2_SCK / SPI4_SCK / I2C3_SCL
#define SPI3_SCK_PIN        PB3  // TMR2_CH2 / I2C2_SDA / SPI1_SCK / SPI3_SCK / USART1_RX / UART7_RX
#define SPI1_SDI_PIN        PA6  // TMR3_CH1 / SPI1_MISO / TMR13_CH1
#define SPI2_SDI_PIN        PB14 // TMR1_CH2C / TMR8_CH2C / I2C3_SDA / SPI2_MISO
#define SPI3_SDI_PIN        PB4  // TMR3_CH1 / I2C3_SDA / SPI1_MISO / SPI3_MISO / UART7_TX
#define SPI1_SDO_PIN        PA7  // TMR1_CH1C / TMR3_CH2 / TMR8_CH1C / SPI1_MOSI / TMR14_CH1
#define SPI2_SDO_PIN        PB15 // TMR1_CH3C / TMR8_CH3C / I2C3_SCL / SPI2_MOSI
#define SPI3_SDO_PIN        PB5  // TMR3_CH2 / SPI1_MOSI / SPI3_MOSI / UART5_RX
#define ADC_VBAT_PIN        PB0  // TMR1_CH2C / TMR3_CH3 / TMR8_CH2C / USART2_RX / SPI3_MOSI / ADC
#define ADC_CURR_PIN        PB1  // TMR1_CH3C / TMR3_CH4 / TMR8_CH3C / SPI2_SCK / ADC
#define PINIO1_PIN          PC13
#define FLASH_CS_PIN        PA15 // TMR2_CH1 / SPI1_CS / SPI3_CS / USART1_TX / USART2_RX
#define MAX7456_SPI_CS_PIN  PB12 // TMR5_CH1 / SPI2_CS / SPI4_CS / SPI3_SCK
#define GYRO_1_EXTI_PIN     PC14
#define GYRO_1_CS_PIN       PA4  // SPI1_CS / SPI3_CS / USART6_TX
#define GYRO_1_CLKIN_PIN    PA8  // TMR1_CH1 / I2C3_SCL / USART2_TX

#define TIMER_PIN_MAPPING   TIMER_PIN_MAP(0, PB6, 1,  0) \
                            TIMER_PIN_MAP(1, PA0, 1,  1) \
                            TIMER_PIN_MAP(2, PA1, 1,  2) \
                            TIMER_PIN_MAP(3, PA3, 1,  3) \
                            TIMER_PIN_MAP(4, PA2, 1,  4) \
                            TIMER_PIN_MAP(5, PA8, 1, -1)

#define ADC_INSTANCE                    ADC1
#define ADC1_DMA_OPT                    8

#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ                  8
#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_ALIGN                    CW90_DEG
#define MAX7456_SPI_INSTANCE            SPI2
#define FLASH_SPI_INSTANCE              SPI3
#define BARO_I2C_INSTANCE               I2CDEV_2
#define MAG_I2C_INSTANCE                I2CDEV_2
#define PINIO1_BOX                      40
#define PINIO1_CONFIG                   129
#define BOX_USER1_NAME                  "COB"
#define LED0_INVERTED
