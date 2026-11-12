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

#define FC_TARGET_MCU     GD32H757VI

#define BOARD_NAME        GD32H757V1START
#define MANUFACTURER_ID   GD32MCU

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_BARO_BMP280
#define USE_BARO_MS5611
#define USE_BARO_GDY112X

#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

// #define USE_MAG
// #define USE_MAG_QMC5883

#define BEEPER_PIN PD3

#define MOTOR1_PIN PE9
#define MOTOR2_PIN PE11
#define MOTOR3_PIN PE13
#define MOTOR4_PIN PE14
#define MOTOR5_PIN PC6
#define MOTOR6_PIN PC7
#define MOTOR7_PIN PC8
#define MOTOR8_PIN PC9

// #define SERVO1_PIN PE5
// #define SERVO2_PIN PE6

#define RX_PPM_PIN PA10
#define LED_STRIP_PIN PB1


#define UART0_TX_PIN PA9
#define UART1_TX_PIN PD5
#define UART2_TX_PIN PD8
#define UART3_TX_PIN PB8
#define UART4_TX_PIN PC12
#define UART6_TX_PIN PE8
#define UART7_TX_PIN PE1
#define UART0_RX_PIN PA10
#define UART1_RX_PIN PD6
#define UART2_RX_PIN PD9
#define UART3_RX_PIN PB9
#define UART4_RX_PIN PD2
#define UART6_RX_PIN PE7
#define UART7_RX_PIN PE0

#define I2C0_SCL_PIN PB6
#define I2C0_SDA_PIN PB7
#define I2C1_SCL_PIN PB10
#define I2C1_SDA_PIN PB11

#define LED0_PIN             PE3
#define LED1_PIN             PE1

#define SPI0_SCK_PIN PA5
#define SPI1_SCK_PIN PB13
#define SPI2_SCK_PIN PB3
#define SPI3_SCK_PIN PE2
#define SPI0_SDI_PIN PA6
#define SPI1_SDI_PIN PB14
#define SPI2_SDI_PIN PB4
#define SPI3_SDI_PIN PE5
#define SPI0_SDO_PIN PA7
#define SPI1_SDO_PIN PB15
#define SPI2_SDO_PIN PB5
#define SPI3_SDO_PIN PE6

#define ESCSERIAL_PIN PE7
#define ADC_VBAT_PIN PC0
#define ADC_CURR_PIN PC1
#define ADC_RSSI_PIN PC2

#define FLASH_CS_PIN PA15
#define MAX7456_SPI_CS_PIN  PB12
#define GYRO_1_EXTI_PIN PE15
#define GYRO_1_CS_PIN PA4
#define GYRO_2_EXTI_PIN PC13
#define GYRO_2_CS_PIN PE4

#define USB_DETECT_PIN PC15

// #define PINIO1_PIN PD10
// #define PINIO2_PIN PD11

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB1, 2,  8) \
    TIMER_PIN_MAP( 1, PE9, 1,  0) \
    TIMER_PIN_MAP( 2, PE11, 1,  0) \
    TIMER_PIN_MAP( 3, PE13, 1,  0) \
    TIMER_PIN_MAP( 4, PE14, 1,  0) \
    TIMER_PIN_MAP( 5, PC6, 2,  0) \
    TIMER_PIN_MAP( 6, PC7, 3,  0) \
    TIMER_PIN_MAP( 7, PC8, 2,  0) \
    TIMER_PIN_MAP( 8, PC9, 2,  0) \


#define ADC0_DMA_OPT                    0
#define ADC2_DMA_OPT                    1

#define GPS_UART SERIAL_PORT_USART1
#define SERIALRX_UART SERIAL_PORT_USART2
#define MSP_UART SERIAL_PORT_UART4

#define MAG_I2C_INSTANCE I2CDEV_1
#define BARO_I2C_INSTANCE I2CDEV_0
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH

// #define DEFAULT_DSHOT_BURST DSHOT_DMAR_OFF
// #define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_OFF

#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE 206
#define BEEPER_INVERTED
#define MAX7456_SPI_INSTANCE SPI1
#define PINIO1_BOX 40
#define PINIO2_BOX 41
#define PINIO3_BOX 42
#define PINIO1_CONFIG 129
#define PINIO2_CONFIG 129
#define FLASH_SPI_INSTANCE SPI2
#define SERIALRX_PROVIDER SERIALRX_CRSF
#define GYRO_1_SPI_INSTANCE SPI0
#define GYRO_1_ALIGN CW90_DEG
#define GYRO_2_SPI_INSTANCE SPI3
#define GYRO_2_ALIGN CW90_DEG
