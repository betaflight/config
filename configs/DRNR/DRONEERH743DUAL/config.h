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

#define FC_TARGET_MCU                   STM32H743
#define BOARD_NAME                      DRONEERH743DUAL
#define MANUFACTURER_ID                 DRNR

// Miscellaneous
#define LED0_PIN                        PC4  //ADC12_INP4
#define LED1_PIN                        PC5  //ADC12_INN4/ADC12_INP8
#define LED_STRIP_PIN                   PA0  //TIM2_CH1/TIM5_CH1/UART4_TX/ADC1_INP16
#define BEEPER_PIN                      PD14 //TIM4_CH3
#define BEEPER_INVERTED
#define USB_DETECT_PIN                  PA10 //TIM1_CH3/USART1_RX

// Camera control
#define CAMERA_CONTROL_PIN              PA1  //TIM2_CH2/TIM5_CH2/TIM15_CH1N/UART4_RX/ADC12_INP1

// PINIO1 -- VTX Switch
#define PINIO1_PIN                      PA2  //TIM2_CH3/TIM5_CH3/TIM15_CH1/USART2_TX/ADC12_INP14
#define PINIO1_CONFIG                   129
#define PINIO1_BOX                      40
#define BOX_USER1_NAME                  "VTX SW"

// PINIO2 -- CAM Switch
#define PINIO2_PIN                      PA3  //TIM2_CH4/TIM5_CH4/TIM15_CH2/USART2_RX/ADC12_INP15
#define PINIO2_CONFIG                   1
#define PINIO2_BOX                      41
#define BOX_USER2_NAME                  "CAM SW"

// UART 1
#define UART1_TX_PIN                    PA9  //TIM1_CH2/I2C3_SDA/SPI2_SCK/USART1_TX
#define UART1_RX_PIN                    PB7  //TIM17_CH1N/TIM4_CH2/I2C1_SDA/I2C4_SDA/USART1_RX

// UART 2 -- Control Link
#define UART2_TX_PIN                    PD5  //USART2_TX
#define UART2_RX_PIN                    PD6  //SPI3_MOSI/USART2_RX
#define SERIALRX_UART                   SERIAL_PORT_USART2

// UART 3
#define UART3_TX_PIN                    PD8  //USART3_TX
#define UART3_RX_PIN                    PD9  //USART3_RX

// UART 4 -- DJI / VTX
#define UART4_TX_PIN                    PD1  //UART4_TX
#define UART4_RX_PIN                    PD0  //UART4_RX
#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART            SERIAL_PORT_UART4
#endif

// UART 5
#define UART5_TX_PIN                    PB6
#define UART5_RX_PIN                    PD2  //UART5_RX/SDMMC1_CMD

// UART 6 -- GPS
#define UART6_TX_PIN                    PC6  //TIM3_CH1/TIM8_CH1/USART6_TX
#define UART6_RX_PIN                    PC7  //TIM3_CH2/TIM8_CH2/USART6_RX
#ifdef USE_GPS
#define GPS_UART                        SERIAL_PORT_USART6
#endif


// I2C
#define I2C1_SCL_PIN                    PB8  //TIM16_CH1/TIM4_CH3/I2C1_SCL/I2C4_SCL/UART4_RX
#define I2C1_SDA_PIN                    PB9  //TIM17_CH1/TIM4_CH4/I2C1_SDA/SPI2_NSS/I2C4_SDA/UART4_TX/I2C4_SMBA
#define I2C4_SCL_PIN                    PD12 //TIM4_CH1/I2C4_SCL
#define I2C4_SDA_PIN                    PD13 //TIM4_CH2/I2C4_SDA

// Baro
#define USE_BARO
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE               I2CDEV_1

// Compass
#define MAG_I2C_INSTANCE                I2CDEV_4

// IMU
#define USE_ACC
#define USE_GYRO

#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define SPI1_SCK_PIN                    PB3  //TIM2_CH2/SPI1_SCK/SPI3_SCK/SPI6_SCK/UART7_RX
#define SPI1_SDI_PIN                    PB4  //TIM3_CH1/SPI1_MISO/SPI3_MISO/SPI2_NSS/SPI6_MISO/UART7_TX
#define SPI1_SDO_PIN                    PB5  //TIM3_CH2/I2C1_SMBA/SPI1_MOSI/I2C4_SMBA/SPI3_MOSI/SPI6_MOSI/UART5_RX

#define GYRO_1_CS_PIN                   PA15 //TIM2_CH1/SPI1_NSS/SPI3_NSS/SPI6_NSS/UART7_TX
#define GYRO_1_EXTI_PIN                 PD7  //SPI1_MOSI
#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_ALIGN                    CW0_DEG

#define SPI4_SCK_PIN                    PE2  //SPI4_SCK
#define SPI4_SDI_PIN                    PE5  //TIM15_CH2/SPI4_MOSI
#define SPI4_SDO_PIN                    PE6  //TIM15_CH1/SPI4_MISO

#define GYRO_2_CS_PIN                   PE3  //SPI4_NSS
#define GYRO_2_EXTI_PIN                 PE4  //TIM15_CH1N/SPI4_NSS
#define GYRO_2_SPI_INSTANCE             SPI4
#define GYRO_2_ALIGN                    CW0_DEG

#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN                PA5  //TIM2_CH1/ADC12_INP5
#define GYRO_2_CLKIN_PIN                PB0  //TIM3_CH3/ADC12_INP15 (Conflicts with MOTOR7 when bitbang is disabled)

// Blackbox
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define SPI3_SCK_PIN                    PC10 //SPI3_SCK/USART3_TX/UART4_TX/SDMMC1_D2
#define SPI3_SDI_PIN                    PC11 //SPI3_MISO/USART3_RX/UART4_RX/SDMMC1_D3
#define SPI3_SDO_PIN                    PC12 //SPI3_MOSI/UART5_TX/SDMMC1_CK
#define FLASH_CS_PIN                    PA8  //TIM1_CH1/I2C3_SCL/UART7_RX
#define FLASH_SPI_INSTANCE              SPI3
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH

// BAT voltage ADC
#define ADC_VBAT_PIN                    PC0  //ADC123_INP10
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     110

// BAT current ADC
#define ADC_CURR_PIN                    PC1  //SPI2_MOSI/ADC123_INN10/ADC123_INP11
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC

// MAX7456 OSD
#define USE_MAX7456
#define SPI2_SCK_PIN                    PB13 //TIM1_CH1N/SPI2_SCK/USART3_NSS/UART5_TX
#define SPI2_SDI_PIN                    PB14 //TIM1_CH2N/TIM12_CH1/TIM8_CH2N/USART1_TX/SPI2_MISO
#define SPI2_SDO_PIN                    PB15 //TIM1_CH3N/TIM12_CH2/TIM8_CH3N/USART1_RX/SPI2_MOSI
#define MAX7456_SPI_CS_PIN              PB12 //I2C2_SMBA/SPI2_NSS/UART5_RX
#define MAX7456_SPI_INSTANCE            SPI2

// Debug
#define USE_SWDIO_PIN                   PA13
#define USE_SWCLK_PIN                   PA14

// Motor configuration
#define MOTOR1_PIN                      PE9  //TIM1_CH1
#define MOTOR2_PIN                      PE11 //TIM1_CH2/SPI4_NSS
#define MOTOR3_PIN                      PE13 //TIM1_CH3/SPI4_MISO
#define MOTOR4_PIN                      PE14 //TIM1_CH4/SPI4_MOSI
#define MOTOR5_PIN                      PA6  //TIM3_CH1/SPI1_MISO/SPI6_MISO/TIM13_CH1/ADC12_INP3
#define MOTOR6_PIN                      PA7  //TIM3_CH2/SPI1_MOSI/SPI6_MOSI/TIM14_CH1/ADC12_INN3
#define MOTOR7_PIN                      PC8  //TIM3_CH3/TIM8_CH3/SDMMC1_D0
#define MOTOR8_PIN                      PC9  //TIM3_CH4/TIM8_CH4/I2C3_SDA/SDMMC1_D1

// TIMER_PIN_MAP(idx, pin, occurance, dma_opt)
#define TIMER_PIN_MAPPING               TIMER_PIN_MAP( 0, MOTOR1_PIN, 1,  0 ) \
                                        TIMER_PIN_MAP( 1, MOTOR2_PIN, 1,  1 ) \
                                        TIMER_PIN_MAP( 2, MOTOR3_PIN, 1,  2 ) \
                                        TIMER_PIN_MAP( 3, MOTOR4_PIN, 1,  3 ) \
                                        TIMER_PIN_MAP( 4, MOTOR5_PIN, 1,  4 ) \
                                        TIMER_PIN_MAP( 5, MOTOR6_PIN, 1,  5 ) \
                                        TIMER_PIN_MAP( 6, MOTOR7_PIN, 2,  6 ) \
                                        TIMER_PIN_MAP( 7, MOTOR8_PIN, 2,  7 ) \
                                        TIMER_PIN_MAP( 8, LED_STRIP_PIN, 2, 11 ) \
                                        TIMER_PIN_MAP( 9, CAMERA_CONTROL_PIN, 3, -1 ) \
                                        TIMER_PIN_MAP(10, GYRO_1_CLKIN_PIN, 1, -1 ) \
                                        TIMER_PIN_MAP(11, GYRO_2_CLKIN_PIN, 2, -1 ) \
                                        TIMER_PIN_MAP(12, BEEPER_PIN, 1, -1 )

#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON

// DMA stream assignment
#define ADC1_DMA_OPT                    8
#define ADC3_DMA_OPT                    10
