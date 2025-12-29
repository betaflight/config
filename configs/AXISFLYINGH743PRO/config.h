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

#define FC_TARGET_MCU      STM32H743

#define BOARD_NAME         AXISFLYINGH743PRO
#define MANUFACTURER_ID    AXFL

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_FLASH
#define USE_FLASH_PY25Q128HA
#define USE_BARO
#define USE_BARO_DPS310
#define USE_MAX7456
#define USE_GYRO_CLKIN

#define BEEPER_PIN            PC13

#define MOTOR1_PIN            PC6
#define MOTOR2_PIN            PC7
#define MOTOR3_PIN            PC8
#define MOTOR4_PIN            PC9
#define MOTOR5_PIN            PA0
#define MOTOR6_PIN            PA1
#define MOTOR7_PIN            PA2
#define MOTOR8_PIN            PA3

#define SERVO1_PIN            PD12
#define SERVO2_PIN            PD13
#define SERVO3_PIN            PD14
#define SERVO4_PIN            PD15

#define LED_STRIP_PIN         PE5

#define UART1_TX_PIN          PB6
#define UART2_TX_PIN          PD5
#define UART3_TX_PIN          PD8
#define UART4_TX_PIN          PC10
#define UART7_TX_PIN          PE8
#define UART8_TX_PIN          PE1

#define UART1_RX_PIN          PB7
#define UART2_RX_PIN          PD6
#define UART3_RX_PIN          PD9
#define UART4_RX_PIN          PC11
#define UART5_RX_PIN          PD2  // ESC TELEMETRY
#define UART7_RX_PIN          PE7
#define UART8_RX_PIN          PE0

#define I2C1_SCL_PIN          PB8
#define I2C1_SDA_PIN          PB9

#define I2C2_SCL_PIN          PB10
#define I2C2_SDA_PIN          PB11

#define SPI1_SCK_PIN          PA5
#define SPI1_SDI_PIN          PA6
#define SPI1_SDO_PIN          PA7

#define SPI2_SCK_PIN          PB13
#define SPI2_SDI_PIN          PB14
#define SPI2_SDO_PIN          PB15

#define SPI3_SCK_PIN          PB3
#define SPI3_SDI_PIN          PB4
#define SPI3_SDO_PIN          PB5

#define SPI4_SCK_PIN          PE12
#define SPI4_SDI_PIN          PE13
#define SPI4_SDO_PIN          PE14

#define ADC_VBAT_PIN          PC0
#define ADC_CURR_PIN          PC1

#define LED0_PIN              PD3

#define PINIO1_PIN            PE2
#define PINIO2_PIN            PA8

#define GYRO_1_CS_PIN         PC4
#define GYRO_1_EXTI_PIN       PA4
#define GYRO_1_CLKIN_PIN      PB0

#define GYRO_2_CS_PIN         PE15
#define GYRO_2_EXTI_PIN       PE11
#define GYRO_2_CLKIN_PIN      PB1

#define MAX7456_SPI_CS_PIN    PB12
#define FLASH_CS_PIN          PD7

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(  0, MOTOR1_PIN,       2,  0) /* PC6  / TIM8_CH1 */ \
    TIMER_PIN_MAP(  1, MOTOR2_PIN,       2,  1) /* PC7  / TIM8_CH2 */ \
    TIMER_PIN_MAP(  2, MOTOR3_PIN,       2,  2) /* PC8  / TIM8_CH3 */ \
    TIMER_PIN_MAP(  3, MOTOR4_PIN,       2,  3) /* PC9  / TIM8_CH4 */ \
    TIMER_PIN_MAP(  4, MOTOR5_PIN,       1,  4) /* PA0  / TIM2_CH1 */ \
    TIMER_PIN_MAP(  5, MOTOR6_PIN,       1,  5) /* PA1  / TIM2_CH2 */ \
    TIMER_PIN_MAP(  6, MOTOR7_PIN,       1,  6) /* PA2  / TIM2_CH3 */ \
    TIMER_PIN_MAP(  7, MOTOR8_PIN,       1,  7) /* PA3  / TIM2_CH4 */ \
    TIMER_PIN_MAP(  8, SERVO1_PIN,       1, -1) /* PD12 / TIM4_CH1 */ \
    TIMER_PIN_MAP(  9, SERVO2_PIN,       1, -1) /* PD13 / TIM4_CH2 */ \
    TIMER_PIN_MAP( 10, SERVO3_PIN,       1, -1) /* PD14 / TIM4_CH3 */ \
    TIMER_PIN_MAP( 11, SERVO4_PIN,       1, -1) /* PD15 / TIM4_CH4 */ \
    TIMER_PIN_MAP( 12, LED_STRIP_PIN,    1,  8) /* PE5  / TIM15_CH1 */ \
    TIMER_PIN_MAP( 13, GYRO_1_CLKIN_PIN, 2, -1) /* PB0  / TIM3_CH3 */ \
    TIMER_PIN_MAP( 14, GYRO_2_CLKIN_PIN, 2, -1) /* PB1  / TIM3_CH4 */

#define ADC1_DMA_OPT                    9
#define ADC3_DMA_OPT                    10
#define TIMUP8_DMA_OPT                  11
#define TIMUP2_DMA_OPT                  12

#ifdef USE_GPS
#define GPS_UART                        SERIAL_PORT_USART8
#endif
#define SERIALRX_UART                   SERIAL_PORT_USART2
#define ESC_SENSOR_UART                 SERIAL_PORT_UART5
#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART            SERIAL_PORT_USART1
#endif

#define MAG_I2C_INSTANCE                I2CDEV_1
#define BARO_I2C_INSTANCE               I2CDEV_2

#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define BEEPER_INVERTED

#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_ALIGN                    CW0_DEG
#define GYRO_2_SPI_INSTANCE             SPI4
#define GYRO_2_ALIGN                    CW90_DEG
#define DEFAULT_GYRO_TO_USE             GYRO_CONFIG_USE_GYRO_BOTH
#define MAX7456_SPI_INSTANCE            SPI2
#define FLASH_SPI_INSTANCE              SPI3

#define PINIO1_BOX                      40
#define PINIO1_CONFIG                   129
#define BOX_USER1_NAME                  "VTX PWR"
#define PINIO2_BOX                      41
#define PINIO2_CONFIG                   1
#define BOX_USER2_NAME                  "CAM 1,2"
