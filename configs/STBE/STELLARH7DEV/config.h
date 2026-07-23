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
#define BOARD_NAME                      STELLARH7DEV
#define MANUFACTURER_ID                 STBE

// Miscellaneous
#define LED1_PIN                        PB1
#define LED_STRIP_PIN                   PA15
#define BEEPER_PIN                      PA3
#define USB_DETECT_PIN                  PA12

// PINIO Box Config -- VTX Pit Mode
#define PINIO1_PIN                      PB3
#define PINIO1_CONFIG                   129
#define PINIO1_BOX                      40
#define BOX_USER1_NAME                  "VTX switch"

// UART 3
#define UART3_TX_PIN                    PD8
#define UART3_RX_PIN                    PD9

// RC pads
#define UART4_TX_PIN                    PA0
#define UART4_RX_PIN                    PA1
#define SERIALRX_UART                   SERIAL_PORT_UART4

// GPS connector
#define UART5_TX_PIN                    PB6
#define UART5_RX_PIN                    PB5
#ifdef USE_GPS
#define GPS_UART                        SERIAL_PORT_UART5
#endif

// DJI connector
#define UART7_TX_PIN                    PE8
#define UART7_RX_PIN                    PE7
#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART            SERIAL_PORT_USART7
#endif

#define UART8_TX_PIN                    PE1
#define UART8_RX_PIN                    PE0
#define ESC_SENSOR_UART                 SERIAL_PORT_USART8

// I2C
#define I2C2_SCL_PIN                    PB10
#define I2C2_SDA_PIN                    PB11

// Baro
#define USE_BARO
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE               I2CDEV_2

// Compass
#define MAG_I2C_INSTANCE                I2CDEV_2

// IMU
#define USE_ACC
#define USE_GYRO

#define SPI1_SCK_PIN                    PA5
#define SPI1_SDI_PIN                    PA6
#define SPI1_SDO_PIN                    PA7

#define SPI3_SCK_PIN                    PC10
#define SPI3_SDI_PIN                    PC11
#define SPI3_SDO_PIN                    PC12

/*
    Change logic to allow mix of gyro being used on SPI1 or SPI3
    This is to allow testing of different gyro types on the same board
    This is not a typical configuration and is only for testing purposes
*/

// GYRO 1: ICM-40609-D on SPI1
#define ICM40609D_SPI_INSTANCE          SPI1
#define ICM40609D_EXTI_PIN              PA4
#define ICM40609D_CS_PIN                PA2
#define ICM40609D_ALIGN                 CW180_DEG
// GYRO 2: ICM-45605 on SPI1
#define ICM45605_SPI_INSTANCE           SPI1
#define ICM45605_EXTI_PIN               PC4
#define ICM45605_CS_PIN                 PC0
#define ICM45605_ALIGN                  CW180_DEG
// GYRO 3: ICM-45686 on SPI3
#define ICM45686_SPI_INSTANCE           SPI3
#define ICM45686_EXTI_PIN               PA9
#define ICM45686_CS_PIN                 PD5
#define ICM45686_ALIGN                  CW180_DEG
// GYRO 4: ICM-42688P on SPI3
#define ICM42688P_SPI_INSTANCE          SPI3
#define ICM42688P_EXTI_PIN              PA8
#define ICM42688P_CS_PIN                PE3
#define ICM42688P_ALIGN                 CW180_DEG

#define GYRO_1_EXTI_PIN                 ICM40609D_EXTI_PIN
#define GYRO_1_CS_PIN                   ICM40609D_CS_PIN
#define GYRO_1_SPI_INSTANCE             ICM40609D_SPI_INSTANCE
#define GYRO_1_ALIGN                    ICM40609D_ALIGN
#define USE_ACCGYRO_ICM40609D

#define GYRO_2_EXTI_PIN                 ICM45605_EXTI_PIN
#define GYRO_2_CS_PIN                   ICM45605_CS_PIN
#define GYRO_2_SPI_INSTANCE             ICM45605_SPI_INSTANCE
#define GYRO_2_ALIGN                    ICM45605_ALIGN
#define USE_ACCGYRO_ICM45605

#define GYRO_3_EXTI_PIN                 ICM45686_EXTI_PIN
#define GYRO_3_CS_PIN                   ICM45686_CS_PIN
#define GYRO_3_SPI_INSTANCE             ICM45686_SPI_INSTANCE
#define GYRO_3_ALIGN                    ICM45686_ALIGN
#define USE_ACCGYRO_ICM45686

#define GYRO_4_EXTI_PIN                 ICM42688P_EXTI_PIN
#define GYRO_4_CS_PIN                   ICM42688P_CS_PIN
#define GYRO_4_SPI_INSTANCE             ICM42688P_SPI_INSTANCE
#define GYRO_4_ALIGN                    ICM42688P_ALIGN
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_CLKIN
#define GYRO_4_CLKIN_PIN                PB4

// Blackbox
#define USE_FLASH
#define USE_FLASH_W25M02G
#define SPI4_SCK_PIN                    PE2
#define SPI4_SDI_PIN                    PE5
#define SPI4_SDO_PIN                    PE6
#define FLASH_CS_PIN                    PC13
#define FLASH_SPI_INSTANCE              SPI4
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH

// BAT voltage ADC
#define ADC_VBAT_PIN                    PC5
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     210

// BAT current ADC
#define ADC_CURR_PIN                    PB0
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE     120

// MAX7456 OSD
#ifdef USE_OSD_SD
#define USE_MAX7456
#define SPI2_SCK_PIN                    PB13
#define SPI2_SDI_PIN                    PC2
#define SPI2_SDO_PIN                    PC1
#define MAX7456_SPI_CS_PIN              PB8
#define MAX7456_SPI_INSTANCE            SPI2
#endif

// Debug connector
#define USE_SWDIO_PIN                   PA13
#define USE_SWCLK_PIN                   PA14

// Motor configuration
#define MOTOR1_PIN                      PC6    // PC6  : TIM8_CH1
#define MOTOR2_PIN                      PC7    // PC7  : TIM8_CH2
#define MOTOR3_PIN                      PC8    // PC8  : TIM8_CH3
#define MOTOR4_PIN                      PC9    // PC9  : TIM8_CH4

// Servo configuration
#define SERVO1_PIN                      PD12   // PD12 : TIM4_CH1
#define SERVO2_PIN                      PD13   // PD13 : TIM4_CH2

// TIMER_PIN_MAP(idx, pin, occurance, dma_opt)
#define USE_TIMER_MAP_PRINT
#define TIMER_PIN_MAPPING               TIMER_PIN_MAP(0, MOTOR1_PIN, 2,  0) \
                                        TIMER_PIN_MAP(1, MOTOR2_PIN, 2,  1) \
                                        TIMER_PIN_MAP(2, MOTOR3_PIN, 2,  2) \
                                        TIMER_PIN_MAP(3, MOTOR4_PIN, 2,  3) \
                                        TIMER_PIN_MAP(4, SERVO1_PIN, 1, -1) \
                                        TIMER_PIN_MAP(5, SERVO2_PIN, 1, -1) \
                                        TIMER_PIN_MAP(6, LED_STRIP_PIN, 1, 4) \
                                        TIMER_PIN_MAP(7, GYRO_4_CLKIN_PIN, 1, -1)

// DMA stream assignment
#define ADC1_DMA_OPT                    8
#define ADC3_DMA_OPT                    10
