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
#define BOARD_NAME BRAHMA_F405
#define MANUFACTURER_ID DARK

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_ACCGYRO_BMI270
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25Q256
#define USE_MAX7456

#define BEEPER_PIN PC13
#define MOTOR1_PIN PB1
#define MOTOR2_PIN PB0
#define MOTOR3_PIN PA3
#define MOTOR4_PIN PA2
#define MOTOR5_PIN PB9
#define MOTOR6_PIN PB4
#define MOTOR7_PIN PB5
#define MOTOR8_PIN PC9
#define RX_PPM_PIN PA15
#define LED_STRIP_PIN PC8
#define UART1_TX_PIN PA9
#define UART3_TX_PIN PB10
#define UART4_TX_PIN PA0
#define UART6_TX_PIN PC6
#define UART1_RX_PIN PA10
#define UART3_RX_PIN PB11
#define UART4_RX_PIN PA1
#define UART6_RX_PIN PC7
#define I2C1_SCL_PIN PB6
#define I2C1_SDA_PIN PB7
#define LED0_PIN PA8
#define SPI1_SCK_PIN PA5
#define SPI2_SCK_PIN PB13
#define SPI3_SCK_PIN PC10
#define SPI1_SDI_PIN PA6
#define SPI2_SDI_PIN PB14
#define SPI3_SDI_PIN PC11
#define SPI1_SDO_PIN PA7
#define SPI2_SDO_PIN PB15
#define SPI3_SDO_PIN PC12
#define ADC_RSSI_PIN PC5
#define ADC_VBAT_PIN PC4
#define ADC_CURR_PIN PC3
#define FLASH_CS_PIN PB12
#define MAX7456_SPI_CS_PIN PA4
#define GYRO_1_EXTI_PIN PB8
#define GYRO_1_CS_PIN PB3

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB1 , 1,  1 ) \
    TIMER_PIN_MAP( 1, PB0 , 1,  0 ) \
    TIMER_PIN_MAP( 2, PA3 , 1,  0 ) \
    TIMER_PIN_MAP( 3, PA2 , 1,  0 ) \
    TIMER_PIN_MAP( 4, PB9 , 1, -1 ) \
    TIMER_PIN_MAP( 5, PB4 , 1,  0 ) \
    TIMER_PIN_MAP( 6, PB5 , 1,  0 ) \
    TIMER_PIN_MAP( 7, PC9 , 1,  0 ) \
    TIMER_PIN_MAP( 8, PC8 , 1,  0 ) \

// ##timer A15 NONE ### please Add

#define ADC1_DMA_OPT 0

#define MAG_I2C_INSTANCE (I2CDEV_1)
#define BARO_I2C_INSTANCE (I2CDEV_1)
#define DEFAULT_BARO_I2C_ADDRESS 119
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE 270
#define SYSTEM_HSE_MHZ 8
#define MAX7456_SPI_INSTANCE SPI1
#define FLASH_SPI_INSTANCE SPI2
#define USE_SPI_GYRO
#define GYRO_1_SPI_INSTANCE SPI3
