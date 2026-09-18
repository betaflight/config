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

#define BOARD_NAME        KAKUTEH7WING
#define MANUFACTURER_ID   HBRO

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42605
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_ACC_SPI_ICM42605
#define USE_ACCGYRO_BMI270
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_MAX7456
#define USE_SDCARD
#define USE_SDCARD_SDIO
#define SDIO_DEVICE          SDIODEV_2
#define SDIO_USE_4BIT        1

#ifndef USE_WING
#define USE_WING
#endif

#define BEEPER_PIN           PB9
#define MOTOR1_PIN           PA8
#define MOTOR2_PIN           PE11
#define MOTOR3_PIN           PE13
#define MOTOR4_PIN           PE14
#define MOTOR5_PIN           PD14
#define MOTOR6_PIN           PD15
#define MOTOR7_PIN           PA0
#define MOTOR8_PIN           PA1
#define SERVO1_PIN           PE5
#define SERVO2_PIN           PE6
#define SERVO3_PIN           PB5
#define SERVO4_PIN           PB0
#define SERVO5_PIN           PB1
#define LED_STRIP_PIN        PA15
#define UART1_TX_PIN         PB6
#define UART2_TX_PIN         PD5
#define UART3_TX_PIN         PD8
#define UART5_TX_PIN         PB13
#define UART6_TX_PIN         PC6
#define UART7_TX_PIN         PE8
#define UART8_TX_PIN         PE1
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PD6
#define UART3_RX_PIN         PD9
#define UART5_RX_PIN         PD2
#define UART6_RX_PIN         PC7
#define UART7_RX_PIN         PE7
#define UART8_RX_PIN         PE0
#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB7
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define I2C4_SCL_PIN         PD12
#define I2C4_SDA_PIN         PD13
#define LED0_PIN             PC15
#define LED1_PIN             PC14
#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PD3
#define SPI3_SCK_PIN         PC10
#define SPI4_SCK_PIN         PE2
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PC2
#define SPI3_SDI_PIN         PC11
#define SPI4_SDI_PIN         PE5
#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PC3
#define SPI3_SDO_PIN         PC12
#define SPI4_SDO_PIN         PE6
#define ADC_VBAT_PIN         PC5
#define ADC_RSSI_PIN         PC0
#define ADC_CURR_PIN         PC4
#define ADC_EXTERNAL1_PIN    PA3
#define SDCARD_SPI_CS_PIN    PA4
#define SDCARD_DETECT_PIN    PA3
#define PINIO1_PIN           PC13
#define PINIO2_PIN           PE3
#define PINIO3_PIN           PD4
#define PINIO4_PIN           PE4
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PE15
#define GYRO_1_CS_PIN        PE12
#define USB_DETECT_PIN       PA9

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN   , 1,  0) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN   , 1,  1) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN   , 1,  2) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN   , 1,  3) \
    TIMER_PIN_MAP( 4, MOTOR5_PIN   , 1,  4) \
    TIMER_PIN_MAP( 5, MOTOR6_PIN   , 1,  5) \
    TIMER_PIN_MAP( 6, MOTOR7_PIN   , 2,  6) \
    TIMER_PIN_MAP( 7, MOTOR8_PIN   , 2,  7) \
    TIMER_PIN_MAP( 8, SERVO1_PIN   , 1, -1) \
    TIMER_PIN_MAP( 9, SERVO2_PIN   , 1, -1) \
    TIMER_PIN_MAP(10, SERVO3_PIN   , 2, -1) \
    TIMER_PIN_MAP(11, SERVO4_PIN   , 2, -1) \
    TIMER_PIN_MAP(12, SERVO5_PIN   , 2, -1) \
    TIMER_PIN_MAP(13, LED_STRIP_PIN, 1,  8) \
    TIMER_PIN_MAP(14, BEEPER_PIN   , 1, -1)

#define SPI1_TX_DMA_OPT              9
#define ADC1_DMA_OPT                 10
#define ADC3_DMA_OPT                 11
#define TIMUP1_DMA_OPT               12
#define TIMUP4_DMA_OPT               13
#define TIMUP5_DMA_OPT               14

#define MAG_I2C_INSTANCE             I2CDEV_1
#define BARO_I2C_INSTANCE            I2CDEV_4

#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE  182
#define DEFAULT_CURRENT_METER_SCALE  366
#define BEEPER_INVERTED
#define MAX7456_SPI_INSTANCE         SPI2
#define GYRO_1_SPI_INSTANCE          SPI3
#define GYRO_1_ALIGN                 CW90_DEG
#define PINIO1_BOX                   40
#define BOX_USER1_NAME               "CAM 1,2"
#define PINIO2_CONFIG                129
#define PINIO2_BOX                   41
#define BOX_USER2_NAME               "VTX Power"
#define PINIO3_BOX                   42
#define PINIO4_BOX                   43
