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

#define FC_TARGET_MCU        STM32H743

#define BOARD_NAME           LUXH743NDAA
#define MANUFACTURER_ID      LMNR

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_ICM45686
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_SDCARD
#define USE_MAX7456

#ifndef USE_MAG
#define USE_MAG
#endif

#ifndef USE_GPS
#define USE_GPS
#endif

#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN     PB15

#define BEEPER_PIN           PA8

#define MOTOR1_PIN           PE9
#define MOTOR2_PIN           PE11
#define MOTOR3_PIN           PE13
#define MOTOR4_PIN           PE14
#define MOTOR5_PIN           PC6
#define MOTOR6_PIN           PC7
#define MOTOR7_PIN           PC8
#define MOTOR8_PIN           PC9

#define SERVO1_PIN           PD12
#define SERVO2_PIN           PD13
#define SERVO3_PIN           PD14
#define SERVO4_PIN           PD15

#define RX_PPM_PIN           PA2

#define LED_STRIP_PIN        PB0

#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PD5
#define UART3_TX_PIN         PD8
#define UART4_TX_PIN         PA0
#define UART5_TX_PIN         PB13
#define UART7_TX_PIN         PE8
#define UART8_TX_PIN         PE1

#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PD6
#define UART3_RX_PIN         PD9
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PB12
#define UART7_RX_PIN         PE7
#define UART8_RX_PIN         PE0

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9
#define I2C4_SCL_PIN         PB6
#define I2C4_SDA_PIN         PB7

#define LED0_PIN             PE3

#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB10
#define SPI3_SCK_PIN         PC10
#define SPI4_SCK_PIN         PE2
#define SPI6_SCK_PIN         PB3

#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PC2
#define SPI3_SDI_PIN         PC11
#define SPI4_SDI_PIN         PE5
#define SPI6_SDI_PIN         PB4

#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PC3
#define SPI3_SDO_PIN         PC12
#define SPI4_SDO_PIN         PE6
#define SPI6_SDO_PIN         PB5

#define CAMERA_CONTROL_PIN   PA3
#define ADC_VBAT_PIN         PC0
#define ADC_RSSI_PIN         PC5
#define ADC_CURR_PIN         PC1
#define ADC_EXTERNAL1_PIN    PC4    // Airspeed

#define SDCARD_SPI_CS_PIN    PB11   // SPI2_NSS
#define SDCARD_DETECT_PIN    PE15
#define PINIO1_PIN           PB1    // Camera Switch
#define PINIO2_PIN           PB2    // VTX Power Switch
#define FLASH_CS_PIN         PA4    // SPI1_NSS
#define MAX7456_SPI_CS_PIN   PE4    // SPI4_NSS
#define GYRO_1_EXTI_PIN      PC13   // ICM-42688-P INT
#define GYRO_1_CS_PIN        PD7    // ICM-42688-P SPI6_NSS
#define GYRO_2_EXTI_PIN      PD10   // ICM-45686 INT
#define GYRO_2_CS_PIN        PA15   // ICM-45686 SPI3_NSS
#define USB_DETECT_PIN       PD2

/*
    PE9 -  TIM1_CH1
    PE11 - TIM1_CH2
    PE13 - TIM1_CH3 
    PE14 - TIM1_CH4
    PC6 -  TIM8_CH1
    PC7 -  TIM8_CH2
    PC8 -  TIM8_CH3
    PC9 -  TIM8_CH4
    PD12 - TIM4_CH1
    PD13 - TIM4_CH2
    PD14 - TIM4_CH3
    PD15 - TIM4_CH4
    PA2 -  TIM2_CH3
    PB0 -  TIM3_CH3
    PB15 - TIM12_CH2
    PA3 -  TIM5_CH4
*/

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0,  MOTOR1_PIN,          1, 0) \
    TIMER_PIN_MAP( 1,  MOTOR2_PIN,          1, 1) \
    TIMER_PIN_MAP( 2,  MOTOR3_PIN,          1, 2) \
    TIMER_PIN_MAP( 3,  MOTOR4_PIN,          1, 3) \
    TIMER_PIN_MAP( 4,  MOTOR5_PIN,          2, 4) \
    TIMER_PIN_MAP( 5,  MOTOR6_PIN,          2, 5) \
    TIMER_PIN_MAP( 6,  MOTOR7_PIN,          2, 6) \
    TIMER_PIN_MAP( 7,  MOTOR8_PIN,          2, 7) \
    TIMER_PIN_MAP( 8,  SERVO1_PIN,          1, -1) \
    TIMER_PIN_MAP( 9,  SERVO2_PIN,          1, -1) \
    TIMER_PIN_MAP( 10, SERVO3_PIN,          1, -1) \
    TIMER_PIN_MAP( 11, SERVO4_PIN,          1, -1) \
    TIMER_PIN_MAP( 12, RX_PPM_PIN,          1, -1) \
    TIMER_PIN_MAP( 13, LED_STRIP_PIN,       2, 11) \
    TIMER_PIN_MAP( 14, GYRO_1_CLKIN_PIN,    2, -1) \
    TIMER_PIN_MAP( 15, CAMERA_CONTROL_PIN,  2, -1)

#define ADC1_DMA_OPT                        8
#define ADC3_DMA_OPT                        10
#define TIMUP1_DMA_OPT                      12
#define TIMUP8_DMA_OPT                      13

#define MAG_I2C_INSTANCE                    I2CDEV_1
#define BARO_I2C_INSTANCE                   I2CDEV_1
#define DEFAULT_BARO_I2C_ADDRESS            118

#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE         85
#define BEEPER_INVERTED

#define DEFAULT_GYRO_TO_USE                 GYRO_CONFIG_USE_GYRO_1
#define GYRO_1_SPI_INSTANCE                 SPI6
#define GYRO_1_ALIGN                        CW270_DEG_FLIP
#define GYRO_2_SPI_INSTANCE                 SPI3
#define GYRO_2_ALIGN                        CW180_DEG_FLIP
#define FLASH_SPI_INSTANCE                  SPI1
#define MAX7456_SPI_INSTANCE                SPI4
#define SDCARD_SPI_INSTANCE                 SPI2
#define SDCARD_DETECT_INVERTED

#define PINIO1_CONFIG                       1
#define PINIO1_BOX                          40
#define BOX_USER1_NAME                      "CAM 1,2"
#define PINIO2_CONFIG                       1
#define PINIO2_BOX                          41
#define BOX_USER2_NAME                      "VTX PWR"
