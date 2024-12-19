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

#define BOARD_NAME        PRINCIPIOTF7
#define MANUFACTURER_ID   PRIN


// Motors and GPIO Configuration
#define MOTOR1_PIN              PC8
#define MOTOR2_PIN              PC9
#define MOTOR3_PIN              PB4
#define MOTOR4_PIN              PB5
#define MOTOR5_PIN              PB0
#define MOTOR6_PIN              PB1
#define MOTOR7_PIN              PB10
#define MOTOR8_PIN              PB11

#define SERVO1_PIN              PB6
#define SERVO2_PIN              PB7

#define BEEPER_PIN              PC13

#define LED_STRIP_PIN           PA8
#define LED0_PIN                PA4
#define LED1_PIN                PB15


// UART Configuration
#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10

#define UART2_TX_PIN            PA2
#define UART2_RX_PIN            PA3

#define UART3_TX_PIN            PC10
#define UART3_RX_PIN            PC11

#define UART4_TX_PIN            PA0
#define UART4_RX_PIN            PA1

#define UART5_TX_PIN            PC12
#define UART5_RX_PIN            PD2

#define UART6_TX_PIN            PC6
#define UART6_RX_PIN            PC7


// Receiver Configuration
#define RX_PPM_PIN              PA3 // UART 2 RX
#define RX_PWM1_PIN             PA2 // UART 2 TX
#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL
#define SERIALRX_UART           SERIAL_PORT_USART2


// I2C/SPI Configuration
#define I2C1_SCL_PIN            PB8
#define I2C1_SDA_PIN            PB9

#define SPI1_SCK_PIN            PA5
#define SPI1_SDI_PIN            PA6
#define SPI1_SDO_PIN            PA7

#define SPI2_SCK_PIN            PB13
#define SPI2_SDI_PIN            PB14
#define SPI2_SDO_PIN            PC3


// Sensor Configuration
#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_ICM42688P // For ICM42688P variation
#define USE_GYRO_SPI_ICM42688P // For ICM42688P variation

#define GYRO_1_EXTI_PIN         PC4
#define GYRO_1_CS_PIN           PB2
#define GYRO_1_SPI_INSTANCE     SPI1
#define GYRO_1_ALIGN CW90_DEG

#define USE_BARO
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE I2CDEV_1

/*
// SPI barometer for older board revision
#define USE_BARO_SPI_DPS310
#define BARO_CS_PIN          PC15
#define BARO_BUSTYPE SPI
#define BARO_SPI_INSTANCE SPI2
#define BARO_HARDWARE           AUTO
*/

#define MAG_I2C_INSTANCE        I2CDEV_1


// Flash Configuration
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define FLASH_CS_PIN            PB12
#define FLASH_SPI_INSTANCE      SPI2
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH

// DMA configuration
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PC8 , 2,  1) \
    TIMER_PIN_MAP( 1, PC9 , 2,  0) \
    TIMER_PIN_MAP( 2, PB4 , 1,  0) \
    TIMER_PIN_MAP( 3, PB5 , 1,  0) \
    TIMER_PIN_MAP( 4, PB0 , 2,  0) \
    TIMER_PIN_MAP( 5, PB1 , 2,  0) \
    TIMER_PIN_MAP( 6, PB10, 1,  0) \
    TIMER_PIN_MAP( 7, PB11, 1,  1) \
    TIMER_PIN_MAP( 8, PB6 , 1,  -1) \
    TIMER_PIN_MAP( 9, PB7 , 1,  -1) \
    TIMER_PIN_MAP(10, PA8 , 1,  2) \
    TIMER_PIN_MAP(11, PA3 , 3, -1) \
    TIMER_PIN_MAP(12, PA2 , 2,  -1)

#define DEFAULT_DSHOT_BURST DSHOT_DMAR_OFF
#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_ON


// ADC Pins
#define ADC_INSTANCE            ADC1  // Default added
#define ADC1_DMA_OPT            0  // DMA 2 Stream 0 Channel 0

#define ADC_VBAT_PIN            PC2
#define ADC_CURR_PIN            PC1

#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE 179 // This depends on the ESC voltage divider


// PINIO Configuration
#define PINIO1_PIN PC15 // Accessory PINIO 1
#define PINIO2_PIN PB3 // Accessory PINIO 2
#define PINIO3_PIN PA15 // Pit mode VTX

#define PINIO1_CONFIG 1 // PINIO_CONFIG_MODE_OUT_PP
#define PINIO2_CONFIG 1 // PINIO_CONFIG_MODE_OUT_PP
#define PINIO3_CONFIG 129 // PINIO_CONFIG_MODE_OUT_PP, 10V enable, active low

#define PINIO1_BOX 40 // User 1
#define PINIO2_BOX 41 // User 2
#define PINIO3_BOX 42 // Turn VTX on/off

