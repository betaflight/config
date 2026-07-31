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

 /*
    SUPPORTED TARGET - THANK YOU
    REFERENCE: sha256_6bceb225e4273acd251102f4372208ad1ca3488d61baf7734c36daf0d08e3ea8
    DATE: 2025-01-01
*/

#pragma once

#define FC_TARGET_MCU     STM32F405

#define BOARD_NAME        SPEEDYBEEF405AIOV2
#define MANUFACTURER_ID   SPBE

#define USE_ACC
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456
#define USE_BARO
#define USE_BARO_DPS310
#define USE_GYRO_CLKIN

#define MOTOR1_PIN          PA1
#define MOTOR2_PIN          PA0
#define MOTOR3_PIN          PA2
#define MOTOR4_PIN          PA3

#define UART1_TX_PIN        PA9
#define UART1_RX_PIN        PA10
#define UART2_RX_PIN        PD6
#define UART3_TX_PIN        PD8
#define UART3_RX_PIN        PD9
#define UART4_TX_PIN        PC10
#define UART4_RX_PIN        PC11
#define UART5_TX_PIN        PC12
#define UART5_RX_PIN        PD2
#define UART6_TX_PIN        PC6
#define UART6_RX_PIN        PC7

#define I2C1_SCL_PIN        PB8
#define I2C1_SDA_PIN        PB9

#define SPI1_SCK_PIN        PA5
#define SPI1_SDI_PIN        PA6
#define SPI1_SDO_PIN        PA7
#define GYRO_1_CS_PIN       PA4
#define GYRO_1_EXTI_PIN     PE9
#define GYRO_1_CLKIN_PIN    PB1

#define SPI2_SCK_PIN        PB13
#define SPI2_SDI_PIN        PB14
#define SPI2_SDO_PIN        PB15
#define FLASH_CS_PIN        PB12

#define SPI3_SCK_PIN        PB3
#define SPI3_SDI_PIN        PB4
#define SPI3_SDO_PIN        PB5
#define MAX7456_SPI_CS_PIN  PD5

#define LED0_PIN            PD7
#define BEEPER_PIN          PD11
#define RX_PPM_PIN          PC7
#define PINIO1_PIN          PC14
#define ADC_VBAT_PIN        PC0
#define ADC_CURR_PIN        PC2
#define LED_STRIP_PIN       PA8
#define CAMERA_CONTROL_PIN  PD15

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN,         1,  0) \
    TIMER_PIN_MAP(1, MOTOR2_PIN,         1,  0) \
    TIMER_PIN_MAP(2, MOTOR3_PIN,         2,  0) \
    TIMER_PIN_MAP(3, MOTOR4_PIN,         2,  0) \
    TIMER_PIN_MAP(4, LED_STRIP_PIN,      1,  1) \
    TIMER_PIN_MAP(5, CAMERA_CONTROL_PIN, 1, -1) \
    TIMER_PIN_MAP(6, RX_PPM_PIN,         2, -1) \
    TIMER_PIN_MAP(7, GYRO_1_CLKIN_PIN,   2, -1)

#define ADC1_DMA_OPT    1
#define SYSTEM_HSE_MHZ  8
#define PINIO1_BOX      40
#define PINIO1_CONFIG   129
#define BOX_USER1_NAME  "9V BEC OFF"

#define BEEPER_INVERTED
#define MAG_I2C_INSTANCE     I2CDEV_1
#define BARO_I2C_INSTANCE    I2CDEV_1
#define GYRO_1_ALIGN         CW270_DEG
#define GYRO_1_SPI_INSTANCE  SPI1
#define FLASH_SPI_INSTANCE   SPI2
#define MAX7456_SPI_INSTANCE SPI3

#define DEFAULT_PID_PROCESS_DENOM    2
#define DEFAULT_DSHOT_BURST          DSHOT_DMAR_OFF
#define DEFAULT_DSHOT_BITBANG        DSHOT_BITBANG_OFF
#define DEFAULT_CURRENT_METER_SCALE  88
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_FLASH
#define DEFAULT_MOTOR_DSHOT_SPEED    PWM_TYPE_DSHOT300

#define MSP_UART      SERIAL_PORT_USART1
#define SERIALRX_UART SERIAL_PORT_USART6
