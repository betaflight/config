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

#define BOARD_NAME        ATOMRCF405NAVI
#define MANUFACTURER_ID   COMM

#ifndef USE_WING
#define USE_WING
#endif

#ifndef USE_SERVOS
#define USE_SERVOS
#endif

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270

#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_MS5611
#define USE_BARO_DPS310
#define USE_BARO_SPL06

#define USE_MAG

#define USE_MAX7456
#define USE_SDCARD

#define BEEPER_PIN           PC5
#define BEEPER_INVERTED

#define LED0_PIN             PA13
#define LED1_PIN             PA14

#define MOTOR1_PIN           PC8   // S1
#define MOTOR2_PIN           PC9   // S2
#define SERVO1_PIN           PA8   // S3
#define SERVO2_PIN           PB1   // S4
#define SERVO3_PIN           PA15  // S5
#define SERVO4_PIN           PB10  // S6
#define SERVO5_PIN           PB11  // S7
#define SERVO6_PIN           PB0   // S8
#define LED_STRIP_PIN        PB7

#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PA2
#define UART3_TX_PIN         PC10
#define UART4_TX_PIN         PA0
#define UART5_TX_PIN         PC12
#define UART6_TX_PIN         PC6
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PC11
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PD2
#define UART6_RX_PIN         PC7

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9

#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PB3
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PB4
#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PB5

#define ADC_VBAT_PIN         PC2
#define ADC_CURR_PIN         PC1
#define ADC_RSSI_PIN         PC0

#define GYRO_1_CS_PIN        PA4
#define MAX7456_SPI_CS_PIN   PB12
#define SDCARD_SPI_CS_PIN    PB6

#define GYRO_1_EXTI_PIN      NONE

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PC8 , 2,  0) \
    TIMER_PIN_MAP( 1, PC9 , 2,  0) \
    TIMER_PIN_MAP( 2, PA8 , 1, -1) \
    TIMER_PIN_MAP( 3, PB1 , 1, -1) \
    TIMER_PIN_MAP( 4, PA15, 1, -1) \
    TIMER_PIN_MAP( 5, PB10, 1, -1) \
    TIMER_PIN_MAP( 6, PB11, 1, -1) \
    TIMER_PIN_MAP( 7, PB0 , 2, -1) \
    TIMER_PIN_MAP( 8, PB7 , 1,  0)

#define ADC1_DMA_OPT                    0

#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_ALIGN                    CW180_DEG

#define MAG_I2C_INSTANCE                I2CDEV_1
#define BARO_I2C_INSTANCE               I2CDEV_1

#define MAX7456_SPI_INSTANCE            SPI2

#define USE_SDCARD_SPI
#define SDCARD_SPI_INSTANCE             SPI3
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_SDCARD

#define DEFAULT_DSHOT_BURST             DSHOT_DMAR_OFF
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_OFF

#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE     320

#define DEFAULT_RX_FEATURE              FEATURE_RX_SERIAL
#define SERIALRX_UART                   SERIAL_PORT_USART2

#define SYSTEM_HSE_MHZ                  8
