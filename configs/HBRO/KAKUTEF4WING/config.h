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

#define BOARD_NAME        KAKUTEF4WING
#define MANUFACTURER_ID   HBRO

#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#ifndef USE_WING
#define USE_WING
#endif

#ifndef USE_SERVOS
#define USE_SERVOS
#endif

#define MOTOR1_PIN           PA8
#define MOTOR2_PIN           PA9
#define SERVO1_PIN           PB0
#define SERVO2_PIN           PB1
#define SERVO3_PIN           PC8
#define SERVO4_PIN           PC9
#define LED_STRIP_PIN        PA1
#define UART1_TX_PIN         PB6
#define UART2_TX_PIN         PA2
#define UART3_TX_PIN         PC10
#define UART5_TX_PIN         PC12
#define UART6_TX_PIN         PC6
#define UART1_RX_PIN         PB7
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PC11
#define UART5_RX_PIN         PD2
#define UART6_RX_PIN         PC7
#define INVERTER_PIN_UART3   PC13
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define LED0_PIN             PC5
#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PB3
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PC2
#define SPI3_SDI_PIN         PB4
#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PC3
#define SPI3_SDO_PIN         PB5
#define ESCSERIAL_PIN        PC7
#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC1
#define FLASH_CS_PIN         PC14
#define MAX7456_SPI_CS_PIN   PC15
#define GYRO_1_EXTI_PIN      PB2
#define GYRO_1_CS_PIN        PA4
#define USB_DETECT_PIN       PA10
#define PINIO1_PIN           PB14
#define PINIO2_PIN           PB15

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN   , 1,  1) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN   , 1,  1) \
    TIMER_PIN_MAP( 2, SERVO1_PIN   , 2, -1) \
    TIMER_PIN_MAP( 3, SERVO2_PIN   , 2, -1) \
    TIMER_PIN_MAP( 4, SERVO3_PIN   , 2, -1) \
    TIMER_PIN_MAP( 5, SERVO4_PIN   , 2, -1) \
    TIMER_PIN_MAP( 6, LED_STRIP_PIN, 1,  0)

#define ADC1_DMA_OPT                 1

// Not enough motor resources for a quad, default to Wing
#define DEFAULT_MIXER                MIXER_FLYING_WING  

#define MAG_I2C_INSTANCE             I2CDEV_2
#define BARO_I2C_INSTANCE            I2CDEV_2

#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_FLASH
//#define SERIALRX_UART                SERIAL_PORT_USART3  **//USART3 should not be used for a receiver due to DFU hijacking
#define DEFAULT_RX_FEATURE           FEATURE_RX_SERIAL
#define DEFAULT_DSHOT_BURST          DSHOT_DMAR_OFF
#define DEFAULT_DSHOT_BITBANG        DSHOT_BITBANG_OFF
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE  110
#define DEFAULT_CURRENT_METER_SCALE  250
#define SYSTEM_HSE_MHZ               8
#define MAX7456_SPI_INSTANCE         SPI2
#define FLASH_SPI_INSTANCE           SPI3
#define PINIO1_CONFIG                129
#define PINIO1_BOX                   40
#define PINIO2_CONFIG                129
#define PINIO2_BOX                   41
#define GYRO_1_SPI_INSTANCE          SPI1
#define GYRO_1_ALIGN                 CW270_DEG
