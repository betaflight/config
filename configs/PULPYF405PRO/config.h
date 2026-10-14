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

#define FC_TARGET_MCU     STM32F405

#define BOARD_NAME        PULPYF405PRO
#define MANUFACTURER_ID   CUST

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_CLKIN
#define USE_MAX7456
#define USE_SDCARD
#define USE_SDCARD_SPI
#define USE_BARO
#define USE_BARO_DPS310

#define BEEPER_PIN           PB8
#define MOTOR1_PIN           PC6
#define MOTOR2_PIN           PC7
#define MOTOR3_PIN           PC8
#define MOTOR4_PIN           PC9
#define SERVO1_PIN           PB0 // Gimbal X
#define SERVO2_PIN           PB1 // Gimbal Y
#define SERVO3_PIN           PA0 // Gimbal Z
#define LED_STRIP_PIN        PA15
#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PA2
#define UART3_TX_PIN         PB10
#define UART4_TX_PIN         PC10
#define UART5_TX_PIN         PC12
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PB11
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PD2
#define I2C1_SDA_PIN         PB7
#define I2C1_SCL_PIN         PB6
#define LED0_PIN             PC2
#define LED1_PIN             PC3
#define LED2_PIN             PC5
#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PB3
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PB4
#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PB5
#define SDCARD_SPI_CS_PIN    PB12
#define MAX7456_SPI_CS_PIN   PA8
#define ESCSERIAL_PIN        PC11
#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC1
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_CS_PIN        PA4
#define GYRO_1_CLKIN_PIN     PB9

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB8 , 2, -1) \
    TIMER_PIN_MAP( 1, PC6 , 2,  1) \
    TIMER_PIN_MAP( 2, PC7 , 2,  1) \
    TIMER_PIN_MAP( 3, PC8 , 2,  1) \
    TIMER_PIN_MAP( 4, PC9 , 2,  0) \
    TIMER_PIN_MAP( 5, PB0 , 2, -1) \
    TIMER_PIN_MAP( 6, PB1 , 2, -1) \
    TIMER_PIN_MAP( 7, PA0 , 2, -1) \
    TIMER_PIN_MAP( 8, PA15, 1,  0) \
    TIMER_PIN_MAP( 9, PB9 , 2, -1)


#define ADC_INSTANCE ADC3
#define ADC3_DMA_OPT 1
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_SDCARD
#define BARO_I2C_INSTANCE	            I2CDEV_1
#define MAG_I2C_INSTANCE	            I2CDEV_1
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_OFF
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ 8
#define SDCARD_SPI_INSTANCE  SPI2
#define MAX7456_SPI_INSTANCE SPI3
#define GYRO_1_SPI_INSTANCE  SPI1
//#define GYRO_1_ALIGN CW270_DEG
