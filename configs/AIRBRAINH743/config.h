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

#define FC_TARGET_MCU STM32H743

#define BOARD_NAME AIRBRAINH743
#define MANUFACTURER_ID GEUP

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN PC7 // FSYNC
#define GYRO_1_EXTI_PIN PC6 // IMU_INT
#define GYRO_1_CS_PIN PA3
#define USE_BARO
#define USE_BARO_DPS310  //DPS368
#define USE_FLASH
#define USE_FLASH_W25N01G

#ifndef USE_MAG
#define USE_MAG
#endif

#define BEEPER_PIN PA15
#define MOTOR1_PIN PE9
#define MOTOR2_PIN PE11
#define MOTOR3_PIN PE13
#define MOTOR4_PIN PE14
#define MOTOR5_PIN PB0
#define MOTOR6_PIN PB1
#define MOTOR7_PIN PB10
#define MOTOR8_PIN PB11
#define LED_STRIP_PIN PA2 
#define UART1_TX_PIN PA9
#define UART2_TX_PIN PD5
#define UART3_TX_PIN PD8
#define UART4_TX_PIN PB9
#define UART5_TX_PIN PB13
#define UART7_TX_PIN PE8  //NC
#define UART8_TX_PIN PE1
#define UART1_RX_PIN PA10
#define UART2_RX_PIN PD6
#define UART3_RX_PIN PD9
#define UART4_RX_PIN PB8
#define UART5_RX_PIN PB12
#define UART7_RX_PIN PE7
#define UART8_RX_PIN PE0 
#define I2C1_SCL_PIN PB6
#define I2C1_SDA_PIN PB7
#define LED0_PIN PB15     // BLUE
#define LED1_PIN PD11     // GREEN
#define LED2_PIN PD15     // RED
#define SPI1_SCK_PIN PA5  // IMU
#define SPI2_SCK_PIN PD3  // FLASH
#define SPI3_SCK_PIN PE12 // AUX SPI
#define SPI1_SDI_PIN PA6
#define SPI2_SDI_PIN PB14
#define SPI3_SDI_PIN PE5
#define SPI1_SDO_PIN PA7
#define SPI2_SDO_PIN PC3
#define SPI3_SDO_PIN PE6
#define ADC_VBAT_PIN PC4
#define ADC_CURR_PIN PC5
#define PINIO1_PIN PB3
#define FLASH_CS_PIN PD4

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, PE9, 1, 0) \
    TIMER_PIN_MAP(1, PE11, 1, 1) \
    TIMER_PIN_MAP(2, PE13, 1, 2) \
    TIMER_PIN_MAP(3, PE14, 1, 3) \
    TIMER_PIN_MAP(4, PB0, 2, 4) \
    TIMER_PIN_MAP(5, PB1, 2, 5) \
    TIMER_PIN_MAP(6, PB10, 1, 6) \
    TIMER_PIN_MAP(7, PB11, 1, 7) \
    TIMER_PIN_MAP(8, PA2, 2, 8) \
    TIMER_PIN_MAP(9, PC7, 2, -1)

#define ADC1_DMA_OPT 9
#define ADC2_DMA_OPT 10
#define ADC3_DMA_OPT 11
#define TIMUP1_DMA_OPT 12
#define TIMUP2_DMA_OPT 13
#define TIMUP3_DMA_OPT 14

#define MAG_I2C_INSTANCE I2CDEV_1
#define BARO_I2C_INSTANCE I2CDEV_1

#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_ON
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define BEEPER_INVERTED
#define PINIO1_BOX 40
#define PINIO1_CONFIG 129
#define BOX_USER1_NAME "VTX PWR"
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW90_DEG
#define FLASH_SPI_INSTANCE SPI2
#define DEFAULT_VOLTAGE_METER_SCALE 143
