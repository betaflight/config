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

#define FC_TARGET_MCU        STM32H743

#define BOARD_NAME           PRINCIPIOTH7PI
#define MANUFACTURER_ID      PRIN

#define USB_DETECT_PIN       PE2

#define BEEPER_PIN           PA15
#define MOTOR1_PIN           PA0
#define MOTOR2_PIN           PA1
#define MOTOR3_PIN           PA2
#define MOTOR4_PIN           PA3
#define MOTOR5_PIN           PB1
#define MOTOR6_PIN           PB0
#define SERVO1_PIN           PE5
#define SERVO2_PIN           PE6
#define LED_STRIP_PIN        PA8

// Debug connector
#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PD6

// Telem to Raspberry Pi
#define UART3_TX_PIN         PD8
#define UART3_RX_PIN         PD9

// GPS
#define UART4_TX_PIN         PB9
#define UART4_RX_PIN         PB8

// VTX
#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7

// ESC Telem in (RX only)
#define UART7_TX_PIN         PE8  // Not connected
#define UART7_RX_PIN         PE7

// Receiver
#define UART8_TX_PIN         PE1
#define UART8_RX_PIN         PE0

// Baro I2C
#define I2C1_SCL_PIN         PB6
#define I2C1_SDA_PIN         PB7

// Mag and GPS (External) I2C
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11

// LED pins, active low
#define LED0_PIN             PE3 // Blue
#define LED1_PIN             PE4 // Green

// ICM-42688P IMU
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PD7

// Unused
//#define SPI2_SCK_PIN         PB13
//#define SPI2_SDI_PIN         PB14
//#define SPI2_SDO_PIN         PB15

// FRAM (Unused for BF)
#define SPI3_SCK_PIN         PB3
#define SPI3_SDI_PIN         PB4
#define SPI3_SDO_PIN         PB5
// CS pin for SPI3 connection: PD4

// IIM-42653 IMU
#define SPI4_SCK_PIN         PE12
#define SPI4_SDI_PIN         PE13
#define SPI4_SDO_PIN         PE14

// ADC pins
#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC1

#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC

#define ADC1_DMA_OPT         9
#define ADC3_DMA_OPT         10

// SD card
#define USE_SDCARD
#define SDIO_CK_PIN          PC12
#define SDIO_CMD_PIN         PD2
#define SDIO_D0_PIN          PC8
#define SDIO_D1_PIN          PC9
#define SDIO_D2_PIN          PC10
#define SDIO_D3_PIN          PC11
#define SDCARD_DETECT_PIN    PD15
#define SDCARD_DETECT_INVERTED

#define SDIO_DEVICE SDIODEV_1
#define SDIO_USE_4BIT 1

#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD

// Sensors
#define USE_ACC
#define USE_GYRO
#define DEFAULT_GYRO_TO_USE GYRO_CONFIG_USE_GYRO_BOTH

// IMU 1 (ICM-42688P)
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define GYRO_1_EXTI_PIN      PB2
#define GYRO_1_CS_PIN        PC15
#define GYRO_1_SPI_INSTANCE  SPI1
#define GYRO_1_ALIGN         CW0_DEG

// IMU 2 (IIM-42653)
#define USE_ACCGYRO_IIM42653

#define GYRO_2_EXTI_PIN      PE15
#define GYRO_2_CS_PIN        PE11
#define GYRO_2_SPI_INSTANCE  SPI4
#define GYRO_2_ALIGN         CW0_DEG

// Baro
#define USE_BARO
#define USE_BARO_DPS310 // DPS368, but it's equivalent
#define BARO_I2C_INSTANCE    I2CDEV_1

// Mag
#ifndef USE_MAG
#define USE_MAG
#endif
#define USE_MAG_LIS2MDL
#define MAG_I2C_INSTANCE     I2CDEV_2
#define MAG_ALIGN            CW90_DEG

/*
Pin mapping:
Motor 1 (TIM5 CH1)
Motor 2 (TIM5 CH2)
Motor 3 (TIM5 CH3)
Motor 4 (TIM5 CH4)
Motor 5 (TIM3 CH3)
Motor 6 (TIM3 CH4)
Servo 1 (TIM15 CH1)
Servo 2 (TIM15 CH2)
LED strip (TIM1 CH1)
Beeper (TIM2 CH1)
*/

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA0 , 2,  0) \
    TIMER_PIN_MAP( 1, PA1 , 2,  1) \
    TIMER_PIN_MAP( 2, PA2 , 2,  2) \
    TIMER_PIN_MAP( 3, PA3 , 2,  3) \
    TIMER_PIN_MAP( 4, PB0 , 2,  4) \
    TIMER_PIN_MAP( 5, PB1 , 2,  5) \
    TIMER_PIN_MAP( 6, PE5 , 1, -1) \
    TIMER_PIN_MAP( 7, PE6 , 1, -1) \
    TIMER_PIN_MAP( 8, PA8 , 1,  8) \
    TIMER_PIN_MAP( 9, PA15, 1, -1)

#define TIMUP3_DMA_OPT      11
#define TIMUP5_DMA_OPT      12

// Other features:
#define DEFAULT_RX_FEATURE FEATURE_RX_SERIAL
#define SERIALRX_UART      SERIAL_PORT_USART8
#define GPS_UART           SERIAL_PORT_UART4

// PINIO
// PINIO 1 is the 10V enable pin for VTX power
#define PINIO1_PIN           PD10
#define PINIO1_CONFIG        129 // PINIO_CONFIG_MODE_OUT_PP, 10V enable, active low
#define PINIO1_BOX           40 // USER1
#define BOX_USER1_NAME       "VTX PWR"

#define PINIO2_PIN           PD11
#define PINIO2_CONFIG        1 // PINIO_CONFIG_MODE_OUT_PP
#define PINIO2_BOX           41 // USER2
