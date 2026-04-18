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

#define BOARD_NAME        CKFLIGHTH7
#define MANUFACTURER_ID   CUST

#define USE_GYRO
#define USE_GYRO_SPI_ICM20602
#define USE_GYRO_SPI_ICM45686

#define USE_ACC
#define USE_ACC_SPI_ICM20602
#define USE_ACC_SPI_ICM45686

#define USE_BARO
#define USE_BARO_DPS310

#define USE_MAX7456

#define USE_SDCARD
#define USE_SDCARD_SDIO

#define BEEPER_PIN           PE5

#define MOTOR1_PIN           PB1
#define MOTOR2_PIN           PB0
#define MOTOR3_PIN           PA1
#define MOTOR4_PIN           PA0

#define LED_STRIP_PIN        PA8

#define UART7_TX_PIN         PB4
#define UART7_RX_PIN         PB3

#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7

#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PD6

#define UART4_RX_PIN         PB8

#define UART8_RX_PIN         PE0

#define LED0_PIN             PD12
#define LED1_PIN             PD13

#define I2C1_SCL_PIN         PB6
#define I2C1_SDA_PIN         PB7

#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7

#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

#define SPI4_SCK_PIN         PE12
#define SPI4_SDI_PIN         PE13
#define SPI4_SDO_PIN         PE14

#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC1

#define SDIO_CK_PIN          PC12  
#define SDIO_CMD_PIN         PD2  
#define SDIO_D0_PIN          PC8
#define SDIO_D1_PIN          PC9 
#define SDIO_D2_PIN          PC10  
#define SDIO_D3_PIN          PC11 

#define MAX7456_SPI_CS_PIN   PD11
#define GYRO_1_CS_PIN        PA3
#define GYRO_2_CS_PIN        PD8


#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, PB1, 1, 0) \
    TIMER_PIN_MAP(1, PB0, 1, 1) \
    TIMER_PIN_MAP(2, PA1, 1, 2) \
    TIMER_PIN_MAP(3, PA0, 1, 3) \
    TIMER_PIN_MAP(4, PA8, 1, 4) \
    TIMER_PIN_MAP(5, PE5, 1, 5)


#define ADC1_DMA_OPT        1

#define BARO_I2C_INSTANCE I2CDEV_2

#define BEEPER_INVERTED
#define BEEPER_PWM_HZ 4000

#define SYSTEM_HSE_MHZ 8

#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW0_DEG

#define GYRO_4_SPI_INSTANCE SPI4
#define GYRO_4_ALIGN CW0_DEG

#define MAX7456_SPI_INSTANCE SPI2

#define SDCARD_DETECT_PIN NONE
#define SDIO_DEVICE SDIODEV_1
#define SDIO_USE_4BIT 1

#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
