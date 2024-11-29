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

#define FC_TARGET_MCU     STM32F7X2

#define BOARD_NAME        ORQAF7
#define MANUFACTURER_ID   ORQA

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#ifndef USE_SERIALRX_GHST
#define USE_SERIALRX_GHST
#endif

#define BEEPER_PIN           PA4
#define MOTOR1_PIN           PC8  
#define MOTOR2_PIN           PC9
#define MOTOR3_PIN           PA8
#define MOTOR4_PIN           PA9          

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9

#define UART1_TX_PIN         PB6
#define UART1_RX_PIN         PB7

#define UART2_TX_PIN         PA2
#define UART2_RX_PIN         PA3

#define UART3_TX_PIN         PB10         
#define UART3_RX_PIN         PB11

#define UART4_TX_PIN         PA0       
#define UART4_RX_PIN         PA1

#define UART4_TX_PIN         PA0       
#define UART4_RX_PIN         PA1

#define UART5_TX_PIN         PC12       
#define UART5_RX_PIN         PD2

#define UART6_TX_PIN         PC6       
#define UART6_RX_PIN         PC7

#define LED1_PIN             PC15
#define LED2_PIN             PC14  

#define SPI1_SCK_PIN         PA5   
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_CS_PIN        PB2
#define GYRO_1_SPI_INSTANCE SPI1

#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15
#define FLASH_CS_PIN         PB12
#define FLASH_SPI_INSTANCE SPI2

#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PB5
#define MAX7456_SPI_CS_PIN   PC3
#define MAX7456_SPI_INSTANCE SPI3

#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC2

#define ESCSERIAL_PIN        PD2                
#define USB_DETECT_PIN       PA10
#define CAMERA_CONTROL_PIN   PB3
#define LED_STRIP_PIN        PA15

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PC8,  1,  0) \
    TIMER_PIN_MAP( 1, PC9,  1,  0) \
    TIMER_PIN_MAP( 2, PA8,  1,  1) \
    TIMER_PIN_MAP( 3, PA9,  1,  1) \
    TIMER_PIN_MAP( 4, PA15, 1,  0) \
    TIMER_PIN_MAP( 5, PB3,  1,  0)

#define DEFAULT_VOLTAGE_METER_SCALE      112
#define DEFAULT_VOLTAGE_METER_DIVIDER    1
#define DEFAULT_VOLTAGE_METER_MULTIPLIER 12
#define DEFAULT_CURRENT_METER_SCALE      108
#define SERIALRX_UART                    SERIAL_PORT_USART2
#define GPS_UART                         SERIAL_PORT_USART6
#define BARO_I2C_INSTANCE                I2CDEV_1
#define MAG_I2C_INSTANCE                 I2CDEV_1
#define DEFAULT_BLACKBOX_DEVICE          BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE     CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE     VOLTAGE_METER_ADC
#define USE_BEEPER
#define SYSTEM_HSE_MHZ                   8
