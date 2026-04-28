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

#define BOARD_NAME         AXISFLYINGH743MINI
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

#define BEEPER_PIN            PA15

#define MOTOR1_PIN            PC6
#define MOTOR2_PIN            PC7
#define MOTOR3_PIN            PC8
#define MOTOR4_PIN            PC9

#define LED_STRIP_PIN         PE5

#define UART1_TX_PIN          PB6
#define UART2_TX_PIN          PA2
#define UART3_TX_PIN          PD8
#define UART4_TX_PIN          PA0
#define UART8_TX_PIN          PE1

#define UART1_RX_PIN          PB7
#define UART2_RX_PIN          PA3
#define UART3_RX_PIN          PD9
#define UART4_RX_PIN          PA1
#define UART7_RX_PIN          PA8  // ESC TELEMETRY
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

#define SPI3_SCK_PIN          PC10
#define SPI3_SDI_PIN          PC11
#define SPI3_SDO_PIN          PC12

#define ADC_VBAT_PIN          PC0
#define ADC_CURR_PIN          PC1

#define LED0_PIN              PD3

#define PINIO1_PIN            PE2

#define GYRO_1_CS_PIN         PC4
#define GYRO_1_EXTI_PIN       PA4
#define GYRO_1_CLKIN_PIN      PB0

#define MAX7456_SPI_CS_PIN    PB12
#define FLASH_CS_PIN          PA9

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN,       2,  0) /* PC6  TIM8_CH1  */ \
    TIMER_PIN_MAP( 1, MOTOR2_PIN,       2,  1) /* PC7  TIM8_CH2  */ \
    TIMER_PIN_MAP( 2, MOTOR3_PIN,       2,  2) /* PC8  TIM8_CH3  */ \
    TIMER_PIN_MAP( 3, MOTOR4_PIN,       2,  3) /* PC9  TIM8_CH4  */ \
    TIMER_PIN_MAP( 4, LED_STRIP_PIN,    1,  4) /* PE5  TIM15_CH1 */ \
    TIMER_PIN_MAP( 5, GYRO_1_CLKIN_PIN, 2, -1) /* PB0  TIM3_CH3  */ \
    TIMER_PIN_MAP( 6, BEEPER_PIN,       1, -1) /* PA15 TIM2_CH1  */

#define ADC1_DMA_OPT                    7
#define ADC3_DMA_OPT                    8
#define TIMUP8_DMA_OPT                  9
#define TIMUP2_DMA_OPT                  10

#ifdef USE_GPS
#define GPS_UART                        SERIAL_PORT_USART8
#endif

#define SERIALRX_UART                   SERIAL_PORT_UART4
#define ESC_SENSOR_UART                 SERIAL_PORT_USART7

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
#define MAX7456_SPI_INSTANCE            SPI2
#define FLASH_SPI_INSTANCE              SPI3

#define PINIO1_BOX                      40
#define PINIO1_CONFIG                   129
#define BOX_USER1_NAME                  "VTX PWR"
