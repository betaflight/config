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

#define FC_TARGET_MCU STM32H743

#define BOARD_NAME NYX743V1
#define MANUFACTURER_ID NYXT

#define USE_ACC
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define USE_ACCGYRO_BMI270
#define ENABLE_BMI270_ALIGN_AS_ICM 1

#define USE_SDCARD
#define USE_MAX7456
#define USE_BARO
#define USE_BARO_DPS310
#define USE_SDCARD
#define USE_SDCARD_SDIO

#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN     PA2

#define MOTOR1_PIN           PC6
#define MOTOR2_PIN           PC7
#define MOTOR3_PIN           PC8
#define MOTOR4_PIN           PC9
#define MOTOR5_PIN           PE14
#define MOTOR6_PIN           PE13
#define MOTOR7_PIN           PE9
#define MOTOR8_PIN           PE11
#define BEEPER_PIN           PA3
#define SERVO1_PIN           PD12
#define SERVO2_PIN           PD13
#define SERVO3_PIN           PD14
#define SERVO4_PIN           PD15
#define LED_STRIP_PIN        PB0
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PD6
#define UART3_TX_PIN         PD8
#define UART3_RX_PIN         PD9
#define UART4_TX_PIN         PA0
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PB12
#define UART7_TX_PIN         PE8
#define UART7_RX_PIN         PE7
#define UART8_TX_PIN         PE1
#define UART8_RX_PIN         PE0
#define I2C1_SCL_PIN         PB6
#define I2C1_SDA_PIN         PB7
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define LED0_PIN             PD3
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12
#define SPI4_SCK_PIN         PE2
#define SPI4_SDI_PIN         PE5
#define SPI4_SDO_PIN         PE6
#define ADC_VBAT_PIN         PB1
#define ADC_RSSI_PIN         PC4
#define ADC_CURR_PIN         PC5
#define ADC_EXTERNAL1_PIN    PC0
#define MAX7456_SPI_CS_PIN   PA15
#define GYRO_1_EXTI_PIN      PB2
#define GYRO_1_CS_PIN        PA4
#define GYRO_2_EXTI_PIN      PE3
#define GYRO_2_CS_PIN        PE4
#define PINIO1_PIN           PD10   // IO1 PAD
#define PINIO2_PIN           PE15   // IO2 PAD
#define PINIO3_PIN           PE10   // IO3 PAD
#define PINIO4_PIN           PC14   // 12V BEC EN
#define PINIO_COUNT 8
#define PINIO5_PIN           PE12   // IO4 PAD
#define SDCARD_DETECT_PIN    PD2
#define SDIO_DEVICE          SDIODEV_2
#define SDIO_USE_4BIT        1
#define SDIO_CK_PIN          PC1
#define SDIO_CMD_PIN         PD7
#define SDIO_D0_PIN          PB14
#define SDIO_D1_PIN          PB15
#define SDIO_D2_PIN          PB3
#define SDIO_D3_PIN          PB4
#define CAN1_RX_PIN          PB8
#define CAN1_TX_PIX          PB9

/*
    PC6 -  TIM8_CH1
    PC7 -  TIM8_CH2
    PC8 -  TIM8_CH3
    PC9 -  TIM8_CH4
    PE9 -  TIM1_CH1
    PE11 - TIM1_CH2
    PE13 - TIM1_CH3 
    PE14 - TIM1_CH4
    PD12 - TIM4_CH1
    PD13 - TIM4_CH2
    PD14 - TIM4_CH3
    PD15 - TIM4_CH4
    PB0 -  TIM3_CH3
    PA2 -  TIM2_CH3
    PA3 -  TIM5_CH4
*/

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN,       2,  0) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN,       2,  1) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN,       2,  2) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN,       2,  3) \
    TIMER_PIN_MAP( 4, MOTOR5_PIN,       1,  4) \
    TIMER_PIN_MAP( 5, MOTOR6_PIN,       1,  5) \
    TIMER_PIN_MAP( 6, MOTOR7_PIN,       1,  6) \
    TIMER_PIN_MAP( 7, MOTOR8_PIN,       1,  7) \
    TIMER_PIN_MAP( 8, SERVO1_PIN,       1, -1) \
    TIMER_PIN_MAP( 9, SERVO2_PIN,       1, -1) \
    TIMER_PIN_MAP(10, SERVO3_PIN,       1, -1) \
    TIMER_PIN_MAP(11, SERVO4_PIN,       1, -1) \
    TIMER_PIN_MAP(12, LED_STRIP_PIN,    2,  8) \
    TIMER_PIN_MAP(13, BEEPER_PIN,       2, -1) \
    TIMER_PIN_MAP(14, GYRO_1_CLKIN_PIN, 1, -1)

#define ADC1_DMA_OPT        9
#define ADC3_DMA_OPT        10

#define MAG_I2C_INSTANCE                    I2CDEV_1
#define BARO_I2C_INSTANCE                   I2CDEV_2
#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE         80
#define BEEPER_INVERTED
#define DEFAULT_GYRO_TO_USE                 GYRO_CONFIG_USE_GYRO_BOTH
#define GYRO_1_SPI_INSTANCE                 SPI1
#define GYRO_1_ALIGN                        CW0_DEG
#define GYRO_2_SPI_INSTANCE                 SPI4
#define GYRO_2_ALIGN                        CW0_DEG
#define MAX7456_SPI_INSTANCE                SPI3
#define SDCARD_DETECT_INVERTED
#define PINIO1_BOX 40
#define PINIO2_BOX 41
#define PINIO3_BOX 42
#define PINIO4_BOX 43
#define BOX_USER4_NAME "12V BEC"

#define ESC_SENSOR_UART SERIAL_PORT_UART5
