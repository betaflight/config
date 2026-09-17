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

#define FC_TARGET_MCU     STM32H562

#define BOARD_NAME        DAKEFPVH562
#define MANUFACTURER_ID   DAKE

#define USE_ACC
#define USE_GYRO

#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_LSM6DSK320X

#define USE_ACCGYRO_BMI270
#define ENABLE_BMI270_ALIGN_AS_ICM 1

#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

#define BEEPER_PIN           PA13
#define MOTOR1_PIN           PC6    // TIM8_CH1
#define MOTOR2_PIN           PC7    // TIM8_CH2
#define MOTOR3_PIN           PC8    // TIM8_CH3
#define MOTOR4_PIN           PC9    // TIM8_CH4
#define MOTOR5_PIN           PB4    // TIM3_CH1
#define MOTOR6_PIN           PB5    // TIM3_CH2
#define MOTOR7_PIN           PB0    // TIM3_CH3
#define MOTOR8_PIN           PB1    // TIM3_CH4
#define SERVO1_PIN           PB3    // TIM2_CH2
#define SERVO2_PIN           PB10   // TIM2_CH3 
#define LED_STRIP_PIN        PB6    // TIM4_CH1 
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART2_TX_PIN         PA2
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PC4
#define UART4_TX_PIN         PA0
#define UART4_RX_PIN         PA1
#define UART5_TX_PIN         PC12
#define UART5_RX_PIN         PD2
#define UART7_TX_PIN         PA15
#define UART7_RX_PIN         PA8
#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB7
#define LED0_PIN             PA14
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PB2
#define ADC_CURR_PIN         PC0
#define ADC_VBAT_PIN         PC1
#define PINIO1_PIN           PC13
#define PINIO2_PIN           PC2
#define FLASH_CS_PIN         PC3
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PC5
#define GYRO_1_CS_PIN        PA4

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0,  PC6 , 2,  0) \
    TIMER_PIN_MAP( 1,  PC7 , 2,  1) \
    TIMER_PIN_MAP( 2,  PC8 , 2,  2) \
    TIMER_PIN_MAP( 3,  PC9 , 2,  3) \
    TIMER_PIN_MAP( 4,  PB4 , 1,  4) \
    TIMER_PIN_MAP( 5,  PB5 , 1,  5) \
    TIMER_PIN_MAP( 6,  PB0 , 2,  6) \
    TIMER_PIN_MAP( 7,  PB1 , 2,  7) \
    TIMER_PIN_MAP( 8,  PB3 , 1, -1) \
    TIMER_PIN_MAP( 9,  PB10, 1, -1) \
    TIMER_PIN_MAP( 10, PB6 , 2,  8)

#define ADC1_DMA_OPT        9
#define ADC2_DMA_OPT        10

#define FLASH_SPI_INSTANCE SPI3
#define MAX7456_SPI_INSTANCE SPI2

#define BARO_I2C_INSTANCE I2CDEV_1
#define MAG_I2C_INSTANCE I2CDEV_1

#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

#define DEFAULT_CURRENT_METER_SCALE 120
#define DEFAULT_VOLTAGE_METER_SCALE 160

#define BEEPER_INVERTED
#define PINIO1_CONFIG 129
#define PINIO1_BOX 40
#define BOX_USER1_NAME                      "CAM 1,2"
#define PINIO2_CONFIG 129
#define PINIO2_BOX 41
#define BOX_USER2_NAME                      "12V BEC"
#define PINIO3_CONFIG 129
#define PINIO3_BOX 42

#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW90_DEG

#define ESC_SENSOR_UART         SERIAL_PORT_USART3
#define SERIALRX_UART           SERIAL_PORT_UART2
