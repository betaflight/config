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

#define FC_TARGET_MCU     STM32H743
 
#define BOARD_NAME        GEPRC_TAKER_H743V2
#define MANUFACTURER_ID   GEPR
 
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_ACCGYRO_LSM6DSK320X
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_BARO_MS5611
#define USE_MAX7456
#define USE_FLASH
#define USE_SDCARD
#define USE_GYRO_CLKIN

#define GYRO_1_CLKIN_PIN PB14
#define MOTOR1_PIN           PB4
#define MOTOR2_PIN           PB5
#define MOTOR3_PIN           PB0
#define MOTOR4_PIN           PB1
#define MOTOR5_PIN           PE9
#define MOTOR6_PIN           PE11
#define MOTOR7_PIN           PE13
#define MOTOR8_PIN           PE14

#define SERVO1_PIN          PD13
#define SERVO2_PIN          PD14

#define BEEPER_PIN           PA2
#define LED_STRIP_PIN        PB3
#define CAMERA_CONTROL_PIN   PA3

#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PD5
#define UART3_TX_PIN         PD8
#define UART4_TX_PIN         PA0
#define UART6_TX_PIN         PC6
#define UART7_TX_PIN         PE8
#define UART8_TX_PIN         PE1
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PD6
#define UART3_RX_PIN         PD9
#define UART4_RX_PIN         PA1
#define UART6_RX_PIN         PC7
#define UART7_RX_PIN         PE7
#define UART8_RX_PIN         PE0
#define I2C1_SCL_PIN         PB8
#define I2C2_SCL_PIN         PB10
#define I2C1_SDA_PIN         PB9
#define I2C2_SDA_PIN         PB11
#define LED0_PIN             PB7
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PC2
#define SPI2_SDO_PIN         PC3
#define SDIO_CK_PIN          PC12
#define SDIO_CMD_PIN         PD2
#define SDIO_D0_PIN          PC8
#define SDIO_D1_PIN          PC9
#define SDIO_D2_PIN          PC10
#define SDIO_D3_PIN          PC11
#define SPI4_SCK_PIN         PE2
#define SPI4_SDI_PIN         PE5
#define SPI4_SDO_PIN         PE6
#define ADC_VBAT_PIN         PC1
#define ADC_CURR_PIN         PC0
#define PINIO1_PIN           PC5
#define PINIO2_PIN           PD3
#define PINIO3_PIN           PE3
#define MAX7456_SPI_CS_PIN   PE4
#define GYRO_1_EXTI_PIN      PB2
#define GYRO_1_CS_PIN        PB12
 
 
 
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1, 0) \
    TIMER_PIN_MAP( 1, MOTOR1_PIN,    1, 1) \
    TIMER_PIN_MAP( 2, MOTOR2_PIN,    1, 2) \
    TIMER_PIN_MAP( 3, MOTOR3_PIN,    2, 3) \
    TIMER_PIN_MAP( 4, MOTOR4_PIN,    2, 4) \
    TIMER_PIN_MAP( 5, MOTOR5_PIN,    1, 5) \
    TIMER_PIN_MAP( 6, MOTOR6_PIN,    1, 6) \
    TIMER_PIN_MAP( 7, MOTOR7_PIN,    1, 7) \
    TIMER_PIN_MAP( 8, MOTOR8_PIN,    1, 8) \
    TIMER_PIN_MAP( 9, GYRO_1_CLKIN_PIN, 2, -1 )\
    TIMER_PIN_MAP( 10, SERVO1_PIN,    1, -1) \
    TIMER_PIN_MAP( 11, SERVO2_PIN,    1, -1) \
    TIMER_PIN_MAP( 12, CAMERA_CONTROL_PIN, 2, -1) 
#define ADC1_DMA_OPT                    9
#define ADC3_DMA_OPT                    10
#define TIMUP3_DMA_OPT                  11
#define TIMUP4_DMA_OPT                  12
#define TIMUP8_DMA_OPT                  13

#define PINIO1_CONFIG 129
#define PINIO2_CONFIG 129
#define PINIO3_CONFIG 129
#define PINIO1_BOX 40
#define PINIO2_BOX 41
#define PINIO3_BOX 42
#define BOX_USER1_NAME "RF OFF"
#define BOX_USER2_NAME "12V BEC OFF"
#define BOX_USER3_NAME       "CAM 1,2"
 
#define MSP_DISPLAYPORT_UART            SERIAL_PORT_USART1
#define SERIALRX_UART                   SERIAL_PORT_USART2
#define MSP_UART                        SERIAL_PORT_USART8
#define MAG_I2C_INSTANCE                I2CDEV_2
#define BARO_I2C_INSTANCE               I2CDEV_1
 
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE     100
#define BEEPER_INVERTED
#define SDCARD_DETECT_PIN NONE
#define SDIO_DEVICE SDIODEV_1
#define SDIO_USE_4BIT 1
#define GYRO_1_SPI_INSTANCE             SPI2
#define MAX7456_SPI_INSTANCE            SPI4
 
