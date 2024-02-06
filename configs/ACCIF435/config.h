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

#define FC_TARGET_MCU     AT32F435G

#define BOARD_NAME        ACCIF435
#define MANUFACTURER_ID   CUST

#define USE_ACC
#define USE_GYRO

#define USE_ACC_SPI_MPU6000 // For MPU6000 variation
#define USE_GYRO_SPI_MPU6000 // For MPU6000 variation

#define USE_ACC_SPI_ICM42688P // For ICM42688P variation
#define USE_GYRO_SPI_ICM42688P // For ICM42688P variation

#define USE_ACCGYRO_BMI270 // For BMI270 variation

#define USE_BARO_BMP280

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G

#define USE_MAX7456

// I/O
#define LED0_PIN             PC15
#define LED1_PIN             PC14
#define BEEPER_PIN           PC13
#define BEEPER_INVERTED
#define OSD_DISPLAYPORT_DEVICE MAX7456

// ACC/GYRO SPI 1
#define USE_SPI_GYRO
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_CS_PIN        PA4
#define GYRO_1_SPI_INSTANCE  SPI1
#define GYRO_1_ALIGN CW0_DEG
#define GYRO_1_ALIGN_YAW 1800

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7

// FLASH SPI 2
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

#define FLASH_CS_PIN         PB12
#define FLASH_SPI_INSTANCE   SPI2

// OSD SPI 3
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PB5

#define MAX7456_SPI_CS_PIN   PA15
#define MAX7456_SPI_INSTANCE SPI3

// ADC
#define USE_ADC
#define ADC_VBAT_PIN         PC1
#define ADC_RSSI_PIN         PC2
#define ADC_CURR_PIN         PC3
#define ADC_INSTANCE ADC3

// UART PORTS
#define UART1_TX_PIN         PB6
#define UART1_RX_PIN         PB7

#define UART2_TX_PIN         PA2
#define UART2_RX_PIN         PA3

#define UART3_TX_PIN         PB10
#define UART3_RX_PIN         PB11

#define UART4_TX_PIN         PA0
#define UART4_RX_PIN         PA1

#define UART5_TX_PIN         PC12
#define UART5_RX_PIN         PD2

#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7

// TIMERS
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB9 , 2, -1) \
    TIMER_PIN_MAP( 1, PA9 , 1,  0) \
    TIMER_PIN_MAP( 2, PA8 , 1,  0) \
    TIMER_PIN_MAP( 3, PC9 , 2,  0) \
    TIMER_PIN_MAP( 4, PC8 , 2,  0) \
    TIMER_PIN_MAP( 5, PB8 , 1,  0)
    //TIMER_PIN_MAP( 6, PB3 , 1,  0)

// MOTORS PINOUT
#define MOTOR1_PIN           PA9
#define MOTOR2_PIN           PA8
#define MOTOR3_PIN           PC9
#define MOTOR4_PIN           PC8

#define ADC1_DMA_OPT         11

// BARO I2C
#define USE_BARO
#define BARO_I2C_INSTANCE (I2CDEV_1)
#define MAG_I2C_INSTANCE (I2CDEV_1)

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9

// USERS
#define PINIO1_PIN           PB1
#define PINIO1_BOX 40
#define PINIO1_CONFIG 129

// DEFAULTS
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_ON

// DISABLED
// #define INVERTER_PIN_UART1   PC0
// #define LED_STRIP_PIN        PB3
// #define ESCSERIAL_PIN        PB9
