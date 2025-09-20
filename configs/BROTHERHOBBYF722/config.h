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

#define FC_TARGET_MCU                       STM32F7X2

#define BOARD_NAME                          BROTHERHOBBYF722
#define MANUFACTURER_ID                     BROT

// LEDS
#define BEEPER_PIN                          PC13
#define BEEPER_INVERTED
#define LED_STRIP_PIN                       PC8
//#define LED0_PIN                            
#define LED1_PIN                            PC9

// MOTORS & SERVOS
#define MOTOR1_PIN                          PA15
#define MOTOR2_PIN                          PB3
#define MOTOR3_PIN                          PB4
#define MOTOR4_PIN                          PB5

#define SERVO1_PIN                          PB6
#define SERVO2_PIN                          PB7
#define SERVO3_PIN                          PB0
#define SERVO4_PIN                          PB1

// SPI
#define SPI1_SCK_PIN                        PA5
#define SPI1_SDI_PIN                        PA6
#define SPI1_SDO_PIN                        PA7

#define SPI2_SCK_PIN                        PB13
#define SPI2_SDI_PIN                        PB14
#define SPI2_SDO_PIN                        PB15

#define SPI3_SCK_PIN                        PC10
#define SPI3_SDI_PIN                        PC11
#define SPI3_SDO_PIN                        PB2

// GYRO & ACC
#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P
#define DEFAULT_GYRO_TO_USE                 GYRO_CONFIG_USE_GYRO_BOTH
#define GYRO_1_EXTI_PIN                     PC4
#define GYRO_1_CS_PIN                       PA4
#define GYRO_1_SPI_INSTANCE                 SPI1
#define GYRO_1_ALIGN                        CW90_DEG
#define GYRO_2_EXTI_PIN                     PC3
#define GYRO_2_CS_PIN                       PA8
#define GYRO_2_SPI_INSTANCE                 SPI1
#define GYRO_2_ALIGN                        CW270_DEG

// OSD
#define USE_MAX7456
#define MAX7456_SPI_CS_PIN                  PB12
#define MAX7456_SPI_INSTANCE                SPI2

// FLASH
#define USE_FLASH
#define USE_FLASH_W25N02K
#define FLASH_SPI_CS_PIN                    PC14
#define FLASH_SPI_INSTANCE                  SPI3
#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH

// BARO & MAG
// Goertek SPL06-001 uses DPS310 driver
#define USE_BARO
#define USE_BARO_DPS310
#define I2C1_SCL_PIN                        PB8
#define I2C1_SDA_PIN                        PB9
#define BARO_I2C_INSTANCE                   I2CDEV_1
#define MAG_I2C_INSTANCE                    I2CDEV_1

// UART & VCP
#define UART1_TX_PIN                        PA9
#define UART1_RX_PIN                        PA10

#define UART2_TX_PIN                        PA2
#define UART2_RX_PIN                        PA3

#define UART3_TX_PIN                        PB10
#define UART3_RX_PIN                        PB11

#define UART4_TX_PIN                        PA0
#define UART4_RX_PIN                        PA1

#define UART5_TX_PIN                        PC12
#define UART5_RX_PIN                        PD2

#define UART6_TX_PIN                        PC6
#define UART6_RX_PIN                        PC7

#define USB_DETECT_PIN                      PA12

// ADC
#define ADC_VBAT_PIN                        PC2
#define ADC_RSSI_PIN                        PC0
#define ADC_CURR_PIN                        PC1
#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE         386
#define DEFAULT_VOLTAGE_METER_SCALE         110

// PINIO
#define PINIO1_PIN                          PC15
#define PINIO1_CONFIG                       129
#define PINIO1_BOX                          40
#define BOX_USER1_NAME                      "VTX PWR"

// TIMERS & DMA
/*
LED_STRIP_PIN                       PC8         1=TIM3_CH3 (C) 2=TIM8_CH3
MOTOR1_PIN                          PA15        1=TIM2_CH1
MOTOR2_PIN                          PB3         1=TIM2_CH2
MOTOR3_PIN                          PB4         1=TIM3_CH1
MOTOR4_PIN                          PB5         1=TIM3_CH2
SERVO1_PIN                          PB6         1=TIM4_CH1
SERVO2_PIN                          PB7         1=TIM4_CH2
SERVO3_PIN                          PB0         2=TIM3_CH3 (C)
SERVO4_PIN                          PB1         2=TIM3_CH4
*/

#define TIMER_PIN_MAPPING \
        TIMER_PIN_MAP( 0, MOTOR1_PIN,    1,  0 ) \
        TIMER_PIN_MAP( 1, MOTOR2_PIN,    1,  0 ) \
        TIMER_PIN_MAP( 2, MOTOR3_PIN,    1,  0 ) \
        TIMER_PIN_MAP( 3, MOTOR4_PIN,    1,  0 ) \
        TIMER_PIN_MAP( 4, SERVO1_PIN,    1, -1 ) \
        TIMER_PIN_MAP( 5, SERVO2_PIN,    1, -1 ) \
        TIMER_PIN_MAP( 6, SERVO3_PIN,    2, -1 ) \
        TIMER_PIN_MAP( 7, SERVO4_PIN,    2, -1 ) \
        TIMER_PIN_MAP( 8, LED_STRIP_PIN, 2,  0 )

#define ADC1_DMA_OPT                        0

#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART SERIAL_PORT_USART1
#endif

#define SERIALRX_UART SERIAL_PORT_USART2

#ifdef USE_GPS
#define GPS_UART SERIAL_PORT_USART6
#endif
