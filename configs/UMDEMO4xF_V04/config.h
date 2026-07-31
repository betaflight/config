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

#define FC_TARGET_MCU     UM324XF
#define BOARD_NAME        UMDEMO41FV04
#define MANUFACTURER_ID   UMIC


#define USE_GYRO
#define USE_GYRO_SPI_ICM42605
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42622P
#define USE_GYRO_SPI_MPU6000

#define USE_ACC
#define USE_ACC_SPI_ICM42605
#define USE_ACC_SPI_ICM42688P
#define USE_ACC_SPI_ICM42622P
#define USE_ACC_SPI_MPU6000

#define USE_ACCGYRO_LSM6DSV16X
#define USE_ACCGYRO_BMI270

#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_M25P16//default by previous for ver4.5
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

#define USE_MAG
#define USE_MAG_QMC5883

#ifndef USE_CAMERA_CONTROL
#define USE_CAMERA_CONTROL
#endif
// #define CAMERA_CONTROL_PIN   PC6

#define USE_BEEPER
#define BEEPER_PIN           PC13

#define MOTOR1_PIN           PE5//PA9
#define MOTOR2_PIN           PA8
#define MOTOR3_PIN           PE7//PC8
#define MOTOR4_PIN           PB15

#define SERVO1_PIN           PB0
#define SERVO2_PIN           PB1
#define SERVO3_PIN           PC4
#define SERVO4_PIN           PC5

#define LED_STRIP_PIN        PB3

#define UART1_TX_PIN         PB6
#define UART2_TX_PIN         PA2
#define UART3_TX_PIN         PB10
#define UART4_TX_PIN         PA0
//#define UART5_TX_PIN         PC0
#define UART6_TX_PIN         PC6
#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PB11
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PD2
#define UART6_RX_PIN         PC7

#define SA_UART_RX_PIN       PB7
#define USE_SMARTAUDIO_NOPULLDOWN

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9


#define LED0_PIN             PB12
#define LED1_PIN             PB14

#define SPI1_SCK_PIN         PA5
#define SPI1_SDO_PIN         PA7
#define SPI1_SDI_PIN         PA6
#define SPI1_NSS_PIN         PA4
#define SPI1_TX_DMA_OPT      0
#define SPI1_RX_DMA_OPT      0

#define SPI2_SCK_PIN         PB13
#define SPI2_SDO_PIN         PC3
#define SPI2_SDI_PIN         PC2
#define SPI2_NSS_PIN         PC15
#define SPI2_TX_DMA_OPT      0
#define SPI2_RX_DMA_OPT      0

#define SPI3_SCK_PIN         PC10
#define SPI3_SDO_PIN         PC12
#define SPI3_SDI_PIN         PC11
#define SPI3_NSS_PIN         PA15
#define SPI3_TX_DMA_OPT      0
#define SPI3_RX_DMA_OPT      0

#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC1

#define FLASH_CS_PIN         SPI2_NSS_PIN
#define MAX7456_SPI_CS_PIN   SPI1_NSS_PIN
#define GYRO_1_CS_PIN        SPI3_NSS_PIN
#define GYRO_1_EXTI_PIN      PB4

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN , 1,  0) \
    TIMER_PIN_MAP(1, MOTOR2_PIN , 1,  0) \
    TIMER_PIN_MAP(2, MOTOR3_PIN , 1,  0) \
    TIMER_PIN_MAP(3, MOTOR4_PIN , 1,  0) \
    TIMER_PIN_MAP(4, SERVO1_PIN , 1,  -1) \
    TIMER_PIN_MAP(5, SERVO2_PIN , 1,  -1) \
    TIMER_PIN_MAP(6, SERVO3_PIN , 1,  -1) \
    TIMER_PIN_MAP(7, SERVO4_PIN , 1,  -1) \
    TIMER_PIN_MAP(9, LED_STRIP_PIN , 1,  0)


#define ADC1_DMA_OPT        1
#define ADC2_DMA_OPT        0

#define MAG_I2C_INSTANCE  I2CDEV_1
#define BARO_I2C_INSTANCE I2CDEV_1


// #define DEFAULT_ALIGN_BOARD_YAW -45
#define GYRO_1_ALIGN                CW270_DEG
#define GYRO_1_SPI_INSTANCE         SPI3
#define MAX7456_SPI_INSTANCE        SPI1
#define FLASH_SPI_INSTANCE          SPI2


#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE         170
#define DEFAULT_CURRENT_METER_OFFSET        0
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ 8

#define DEFAULT_DSHOT_BITBANG               DSHOT_BITBANG_ON
#define DEFAULT_DSHOT_BURST                 DSHOT_DMAR_OFF



