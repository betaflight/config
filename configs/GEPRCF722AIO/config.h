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
#define BOARD_NAME HGLRCF722AIO
#define MANUFACTURER_ID HGLR

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_ACCGYRO_BMI270
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_MAX7456

#define BEEPER_PIN C13
#define MOTOR1_PIN B04
#define MOTOR2_PIN B05
#define MOTOR3_PIN B00
#define MOTOR4_PIN B01
#define MOTOR5_PIN A15
#define MOTOR6_PIN B03
#define MOTOR7_PIN B06
#define MOTOR8_PIN B07
#define LED_STRIP_PIN A08
#define UART1_TX_PIN A09
#define UART2_TX_PIN A02
#define UART3_TX_PIN B10
#define UART4_TX_PIN A00
#define UART6_TX_PIN C06
#define UART1_RX_PIN A10
#define UART2_RX_PIN A03
#define UART3_RX_PIN B11
#define UART4_RX_PIN A01
#define UART6_RX_PIN C07
#define I2C1_SCL_PIN B08
#define I2C1_SDA_PIN B09
#define LED0_PIN A14
#define LED1_PIN A13
#define SPI1_SCK_PIN A05
#define SPI2_SCK_PIN B13
#define SPI3_SCK_PIN C10
#define SPI1_SDI_PIN A06
#define SPI2_SDI_PIN B14
#define SPI3_SDI_PIN C11
#define SPI1_SDO_PIN A07
#define SPI2_SDO_PIN B15
#define SPI3_SDO_PIN C12
#define ADC_VBAT_PIN C02
#define ADC_RSSI_PIN C00
#define ADC_CURR_PIN C01
#define BARO_CS_PIN A04
#define PINIO1_PIN C08
#define PINIO2_PIN C09
#define FLASH_CS_PIN D02
#define MAX7456_SPI_CS_PIN B12
#define GYRO_1_EXTI_PIN C04
#define GYRO_1_CS_PIN B02
#define USB_DETECT_PIN C14

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB4,  1,  0) \
    TIMER_PIN_MAP( 1, PB5,  1,  0) \
    TIMER_PIN_MAP( 2, PB0,  2,  0) \
    TIMER_PIN_MAP( 3, PB1,  2,  0) \
    TIMER_PIN_MAP( 4, PA15, 1,  0) \
    TIMER_PIN_MAP( 5, PB3,  1,  0) \
    TIMER_PIN_MAP( 6, PB6,  1,  0) \
    TIMER_PIN_MAP( 7, PB7,  1,  0) \
    TIMER_PIN_MAP( 8, PA8,  1,  2) \
    TIMER_PIN_MAP( 9, PA3,  3, -1) \
    TIMER_PIN_MAP(10, PA2,  3, -1) \
    TIMER_PIN_MAP(11, PA1,  2,  0) \
    TIMER_PIN_MAP(12, PA0,  2,  0)

#define ADC1_DMA_OPT 1

#define MAG_I2C_INSTANCE (I2CDEV_1)
#define BARO_I2C_INSTANCE (I2CDEV_1)
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_ON
//TODO #define MOTOR_PWM_PROTOCOL DSHOT600
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE 200
#define BEEPER_INVERTED
#define MAX7456_SPI_INSTANCE SPI2
#define FLASH_SPI_INSTANCE SPI3
#define USE_SPI_GYRO
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN  CW180_DEG
#define GYRO_1_ALIGN_YAW 1800
