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

#define FC_TARGET_MCU     STM32F411

#define BOARD_NAME        MATEKF411WTE
#define MANUFACTURER_ID   MTKS

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_ACC_SPI_BMI270
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_SPI_BMI270
#define USE_MAX7456
#define USE_BARO
#define USE_BARO_DPS310
#ifndef USE_SOFTSERIAL
#define USE_SOFTSERIAL
#endif


#ifndef USE_WING
#define USE_WING
#endif


#define BEEPER_PIN           PB2
#define MOTOR1_PIN           PB6
#define MOTOR2_PIN           PB7
#define SERVO1_PIN           PB0
#define SERVO2_PIN           PB1
#define SERVO3_PIN           PB4
#define SERVO4_PIN           PB5
#define LED_STRIP_PIN        PA8
#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PA2
#define SOFTSERIAL1_TX_PIN   PA0
#define SOFTSERIAL2_TX_PIN   PA15
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA3
#define SOFTSERIAL1_RX_PIN   PA1
#define SOFTSERIAL2_RX_PIN   PB3
#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15
#define ADC_VBAT_PIN         PA4
#define ADC_RSSI_PIN         PA6
#define ADC_CURR_PIN         PA5
#define PINIO1_PIN           PC15
#define PINIO2_PIN           PB10
#define LED0_PIN             PA14
#define LED1_PIN             PA13
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_CS_PIN        PC13
#define GYRO_1_EXTI_PIN      PC14

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB6 , 1,  0) \
    TIMER_PIN_MAP( 1, PB7 , 1,  0) \
    TIMER_PIN_MAP( 2, PB0 , 2, -1) \
    TIMER_PIN_MAP( 3, PB1 , 2, -1) \
    TIMER_PIN_MAP( 4, PB4 , 1, -1) \
    TIMER_PIN_MAP( 5, PB5 , 1, -1) \
    TIMER_PIN_MAP( 6, PA8 , 1,  0)

#define ADC1_DMA_OPT                   0

#define SERIALRX_UART                  SERIAL_PORT_USART2

#define DEFAULT_PID_PROCESS_DENOM      4
#define MAG_I2C_INSTANCE               I2CDEV_1
#define BARO_I2C_INSTANCE              I2CDEV_1
#define DEFAULT_DSHOT_BURST            DSHOT_DMAR_AUTO
#define DEFAULT_DSHOT_BITBANG          DSHOT_BITBANG_OFF
#define DEFAULT_CURRENT_METER_SOURCE   CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE   VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE    250
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ                 8
#define MAX7456_SPI_INSTANCE           SPI2
#define GYRO_1_SPI_INSTANCE            SPI2
#define GYRO_1_ALIGN                   CW180_DEG_FLIP
#define PINIO1_BOX                     40
#define PINIO1_CONFIG                  1
#define BOX_USER1_NAME                 "VTX PWR"
#define PINIO2_BOX                     41
#define PINIO2_CONFIG                  1
#define BOX_USER2_NAME                 "Cam1,2"
