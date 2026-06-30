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

#define FC_TARGET_MCU                   STM32F7X2
#define BOARD_NAME                      DRONEERF722
#define MANUFACTURER_ID                 DRNR

// Miscellaneous
#define LED0_PIN                        PB1  //PB1/TIM1-CH3N/TIM3-CH4/TIM8-CH3N/ADC12-IN9

#define LED_STRIP_PIN                   PB3  //PB3/TIM2-CH2/SPI1-SCK/SPI3-SCK
#define BEEPER_PIN                      PB5  //PB5/TIM3-CH2/SPI1-MOSI/SPI3-MOSI
#define BEEPER_INVERTED
#define USB_DETECT_PIN                  PB2  //PB2/SPI3-MOSI/I2S3-SD

// PINIO1 -- VTX Switch
#define PINIO1_PIN                      PC13 //PC13/EVENTOUT
#define PINIO1_CONFIG                   129
#define PINIO1_BOX                      40
#define BOX_USER1_NAME                  "VTX SW"

// PINIO2 -- CAM Switch
#define PINIO2_PIN                      PC14
#define PINIO2_CONFIG                   1
#define PINIO2_BOX                      41
#define BOX_USER2_NAME                  "CAM SW"

// UART 1
#define UART1_TX_PIN                    PB6  //PB6/TIM4-CH1/I2C1-SCL/USART1-TX
#define UART1_RX_PIN                    PB7  //PB7/TIM4-CH2/I2C1-SDA/USART1-RX

// UART 2
#define UART2_TX_PIN                    PA2  //PA2/TIM2-CH3/TIM5-CH3/TIM9-CH1/USART2-TX/ADC123-IN2
#define UART2_RX_PIN                    PA3  //PA3/TIM2-CH4/TIM5-CH4/TIM9-CH2/USART2-RX/ADC123-IN3
#define SERIALRX_UART                   SERIAL_PORT_USART2

// UART 3 -- Control Link
#define UART3_TX_PIN                    PB10 //PB10/TIM2-CH3/I2C2-SCL/SPI2-SCK/USART3-TX
#define UART3_RX_PIN                    PB11 //PB11/TIM2-CH4/I2C2-SDA/USART3-RX

// UART 4 -- DJI / VTX
#define UART4_TX_PIN                    PA0  //PA0/TIM2-CH1/TIM5-CH1/UART4-TX/ADC123-IN0
#define UART4_RX_PIN                    PA1  //PA1/TIM2-CH2/TIM5-CH2/UART4-RX/ADC123-IN1
#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART            SERIAL_PORT_UART4
#endif

// UART 6
#define UART6_TX_PIN                    PC6  //PC6/TIM3-CH1/TIM8-CH1/USART6-TX
#define UART6_RX_PIN                    PC7  //PC7/TIM3-CH2/TIM8-CH2/USART6-RX

// I2C
#define I2C1_SCL_PIN                    PB8  //PB8/TIM4-CH3/TIM10-CH1/I2C1-SCL/CAN1-RX
#define I2C1_SDA_PIN                    PB9  //PB9/TIM4-CH4/TIM11-CH1/I2C1-SDA/SPI2-NSS/CAN1-TX

// Baro
#define USE_BARO
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE               I2CDEV_1

// Compass
#define MAG_I2C_INSTANCE                I2CDEV_1

// IMU
#define USE_ACC
#define USE_GYRO

#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define SPI1_SCK_PIN                    PA5  //PA5/TIM2-CH1/TIM8-CH1N/SPI1-SCK/ADC12-IN5/DAC-OUT2
#define SPI1_SDI_PIN                    PA6  //PA6/TIM3-CH1/TIM13-CH1/SPI1-MISO/ADC12-IN6
#define SPI1_SDO_PIN                    PA7  //PA7/TIM1-CH1N/TIM3-CH2/TIM8-CH1N/TIM14-CH1/SPI1-MOSI/ADC12-IN7

#define GYRO_1_CS_PIN                   PA4  //PA4/SPI1-NSS/SPI3-NSS/ADC12-IN4/DAC-OUT1
#define GYRO_1_EXTI_PIN                 PC4  //PC4/I2S1-MCK/ADC12-IN14
#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_ALIGN                    CW0_DEG

#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN                PB0  //PB0/TIM1-CH2N/TIM3-CH3/TIM8-CH2N/ADC-IN8

// Blackbox
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define SPI3_SCK_PIN                    PC10 //PC10/SPI3-SCK/USART3-TX/UART4-TX
#define SPI3_SDI_PIN                    PC11 //PC11/SPI3-MISO/USART3-RX/UART4-RX
#define SPI3_SDO_PIN                    PC12 //PC12/SPI3-MOSI/UART5-TX
#define FLASH_CS_PIN                    PA15 //PA15/TIM2-CH1/SPI1-NSS/SPI3-NSS
#define FLASH_SPI_INSTANCE              SPI3
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH

// BAT voltage ADC
#define ADC_VBAT_PIN                    PC2  //PC2/SPI2-MISO/ADC123-IN12
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     110

// BAT current ADC
#define ADC_CURR_PIN                    PC1  //PC1/SPI2-MOSI/I2S2-SD/ADC123-IN11
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC

// MAX7456 OSD
#define USE_MAX7456
#define SPI2_SCK_PIN                    PB13 //PB13/TIM1-CH1N/SPI2-SCK
#define SPI2_SDI_PIN                    PB14 //PB14/TIM1-CH2N/TIM8-CH2N/TIM12-CH1/SPI2-MISO
#define SPI2_SDO_PIN                    PB15 //PB15/TIM1-CH3N/TIM8-CH3N/TIM12-CH2/SPI2-MOSI
#define MAX7456_SPI_CS_PIN              PB12 //PB12/SPI2-NSS/TIM1-BKIN
#define MAX7456_SPI_INSTANCE            SPI2

// Debug
#define USE_SWDIO_PIN                   PA13
#define USE_SWCLK_PIN                   PA14

// Motor configuration
#define MOTOR1_PIN                      PA8  //PA8/TIM1-CH1/I2C3-SCL
#define MOTOR2_PIN                      PA9  //PA9/TIM1-CH2/SPI2-SCK/USART1-TX
#define MOTOR3_PIN                      PC8  //PC8/TIM3-CH3/TIM8-CH3/UART5-RTS/USART6-CK
#define MOTOR4_PIN                      PC9  //PC9/TIM3-CH4/TIM8-CH4/I2C3-SDA

// TIMER_PIN_MAP(idx, pin, occurance, dma_opt)
#define TIMER_PIN_MAPPING               TIMER_PIN_MAP( 0, MOTOR1_PIN, 1,  0 ) \
                                        TIMER_PIN_MAP( 1, MOTOR2_PIN, 1,  0 ) \
                                        TIMER_PIN_MAP( 2, MOTOR3_PIN, 2,  0 ) \
                                        TIMER_PIN_MAP( 3, MOTOR4_PIN, 2,  0 ) \
                                        TIMER_PIN_MAP( 4, LED_STRIP_PIN, 2,  0 ) \
                                        TIMER_PIN_MAP( 5, GYRO_1_CLKIN_PIN, 2, -1 ) \
                                        TIMER_PIN_MAP( 6, BEEPER_PIN, 1, -1 )

#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON

// DMA stream assignment
#define ADC1_DMA_OPT                    1
