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
#define BOARD_NAME        GEPRC_TAKER_H743MINI
#define MANUFACTURER_ID   GEPR

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_BARO_MS5611
#define USE_MAX7456
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_GYRO_CLKIN

#define BEEPER_PIN           PD2 
#define MOTOR1_PIN           PC6
#define MOTOR2_PIN           PC7
#define MOTOR3_PIN           PC8
#define MOTOR4_PIN           PC9
#define MOTOR5_PIN           PE9
#define MOTOR6_PIN           PE11
#define MOTOR7_PIN           PE13
#define MOTOR8_PIN           PE14
#define LED_STRIP_PIN        PD12
#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PD5
#define UART3_TX_PIN         PD8
#define UART4_TX_PIN         PA0
#define UART7_TX_PIN         PE8
#define UART8_TX_PIN         PE1
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PD6
#define UART3_RX_PIN         PD9
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PB5
#define UART7_RX_PIN         PE7
#define UART8_RX_PIN         PE0
#define I2C1_SCL_PIN         PB8
#define I2C2_SCL_PIN         PB10
#define I2C1_SDA_PIN         PB9
#define I2C2_SDA_PIN         PB11
#define LED0_PIN             PB7
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PC2  
#define SPI2_SDO_PIN         PC3 
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12
#define SPI4_SCK_PIN         PE2
#define SPI4_SDI_PIN         PE5   
#define SPI4_SDO_PIN         PE6
#define ADC_VBAT_PIN         PC1
#define ADC_CURR_PIN         PC0
#define FLASH_CS_PIN         PA15
#define PINIO1_PIN           PC5
#define PINIO2_PIN           PD3
#define MAX7456_SPI_CS_PIN   PE4
#define GYRO_1_EXTI_PIN      PB2
#define GYRO_1_CS_PIN        PB12
#define GYRO_1_CLKIN_PIN     PB0

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1, 0) \
    TIMER_PIN_MAP( 1, MOTOR1_PIN,    2, 1) \
    TIMER_PIN_MAP( 2, MOTOR2_PIN,    2, 2) \
    TIMER_PIN_MAP( 3, MOTOR3_PIN,    2, 3) \
    TIMER_PIN_MAP( 4, MOTOR4_PIN,    2, 4) \
    TIMER_PIN_MAP( 5, MOTOR5_PIN,    1, 5) \
    TIMER_PIN_MAP( 6, MOTOR6_PIN,    1, 6) \
    TIMER_PIN_MAP( 7, MOTOR7_PIN,    1, 7) \
    TIMER_PIN_MAP( 8, MOTOR8_PIN,    1, 8) \
    TIMER_PIN_MAP( 9, GYRO_1_CLKIN_PIN, 2, -1 )

#define ADC1_DMA_OPT                    9
#define ADC3_DMA_OPT                    10
#define TIMUP1_DMA_OPT                  11
#define TIMUP3_DMA_OPT                  12

#define MSP_DISPLAYPORT_UART            SERIAL_PORT_USART1
#define SERIALRX_UART                   SERIAL_PORT_USART2
#define MSP_UART                        SERIAL_PORT_USART8
#define MAG_I2C_INSTANCE                I2CDEV_2
#define BARO_I2C_INSTANCE               I2CDEV_1
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE     100
#define BEEPER_INVERTED
#define FLASH_SPI_INSTANCE              SPI3
#define PINIO1_CONFIG 129
#define PINIO2_CONFIG 129
#define PINIO1_BOX 40
#define PINIO2_BOX 41
#define BOX_USER1_NAME  "LIGHT OFF"
#define BOX_USER2_NAME "12V BEC OFF"
#define GYRO_1_SPI_INSTANCE             SPI2
#define MAX7456_SPI_INSTANCE            SPI4
