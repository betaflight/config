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

#define BOARD_NAME        VGF405X8
#define MANUFACTURER_ID   VGRC

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#define BEEPER 1 B08
#define MOTOR 1 C06
#define MOTOR 2 C07
#define MOTOR 3 C08
#define MOTOR 4 C09
#define MOTOR 5 A15
#define MOTOR 6 A08
#define MOTOR 7 B10
#define MOTOR 8 B11
#define PPM 1 A03
#define LED_STRIP 1 B01
#define SERIAL_TX 1 A09
#define SERIAL_TX 2 A02
#define SERIAL_TX 3 C10
#define SERIAL_TX 4 A00
#define SERIAL_TX 5 C12
#define SERIAL_RX 1 A10
#define SERIAL_RX 2 A03
#define SERIAL_RX 3 C11
#define SERIAL_RX 4 A01
#define SERIAL_RX 5 D02
#define I2C_SCL 1 B06
#define I2C_SDA 1 B07
#define LED 1 C13
#define SPI_SCK 1 A05
#define SPI_SCK 2 B13
#define SPI_SCK 3 B03
#define SPI_MISO 1 A06
#define SPI_MISO 2 B14
#define SPI_MISO 3 B04
#define SPI_MOSI 1 A07
#define SPI_MOSI 2 B15
#define SPI_MOSI 3 B05
#define ESCSERIAL 1 C11
#define ADC_BATT 1 C02
#define ADC_RSSI 1 C03
#define ADC_CURR 1 C01
#define FLASH_CS 1 C00
#define OSD_CS 1 A13
#define GYRO_EXTI 1 C04
#define GYRO_CS 1 A04
#define USB_DETECT 1 B12
#define PINIO 1 B09
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PC7 , 2,  0) \
    TIMER_PIN_MAP( 1, PA8 , 1,  1) \
    TIMER_PIN_MAP( 2, PA9 , 1,  1) \
    TIMER_PIN_MAP( 3, PA10, 1,  1) \
    TIMER_PIN_MAP( 4, PC8 , 2,  1) \
    TIMER_PIN_MAP( 5, PC9 , 2,  0) \
    TIMER_PIN_MAP( 6, PB0 , 2,  0) \
    TIMER_PIN_MAP( 7, PB1 , 2,  0)


#define ADC1_DMA_OPT        0

#define MAG_I2C_INSTANCE (I2CDEV_1)
#define BARO_I2C_INSTANCE (I2CDEV_2)

#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE 179
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ 8
#define MAX7456_SPI_INSTANCE SPI1
#define FLASH_SPI_INSTANCE SPI2
#define USE_SPI_GYRO
#define GYRO_1_SPI_INSTANCE SPI3
#define GYRO_1_ALIGN CW270_DEG
#define GYRO_1_ALIGN_YAW 2700
#define GYRO_2_SPI_INSTANCE SPI3
