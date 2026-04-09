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

#define BOARD_NAME        DAKEFPVH743PRO
#define MANUFACTURER_ID   DAKE

#define USE_ACC
#define USE_GYRO

#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_LSM6DSV16X
#define USE_ACCGYRO_LSM6DSK320X

#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN     PE6

#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

#define BEEPER_PIN           PC2
#define MOTOR1_PIN           PA0
#define MOTOR2_PIN           PA1
#define MOTOR3_PIN           PA2
#define MOTOR4_PIN           PA3 
#define MOTOR5_PIN           PE9
#define MOTOR6_PIN           PE11
#define MOTOR7_PIN           PC8
#define MOTOR8_PIN           PC9
#define SERVO1_PIN           PD12
#define SERVO2_PIN           PD13
#define SERVO3_PIN           PD14
#define SERVO4_PIN           PD15
#define LED_STRIP_PIN        PB0
#define CAMERA_CONTROL_PIN   PE5
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PD6
#define UART3_TX_PIN         PD8
#define UART3_RX_PIN         PD9
#define UART4_TX_PIN         PB8
#define UART4_RX_PIN         PB9
#define UART5_TX_PIN         PB6
#define UART5_RX_PIN         PB5
#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7
#define UART7_TX_PIN         PE8
#define UART7_RX_PIN         PE7
#define UART8_TX_PIN         PE1
#define UART8_RX_PIN         PE0
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define LED0_PIN             PD10
#define LED1_PIN             PD11
#define LED2_PIN             PA8
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12
#define SPI4_SCK_PIN         PE12
#define SPI4_SDI_PIN         PE13
#define SPI4_SDO_PIN         PE14
#define ADC_VBAT_PIN         PC1
#define ADC_RSSI_PIN         PC5
#define ADC_CURR_PIN         PC0
#define PINIO1_PIN           PE2
#define PINIO2_PIN           PE3
#define PINIO3_PIN           PE4
#define FLASH_CS_PIN         PA15
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_CS_PIN        PA4
#define GYRO_2_EXTI_PIN      PB2
#define GYRO_2_CS_PIN        PB1



#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0,  PA0,  1,  0) \
    TIMER_PIN_MAP( 1,  PA1,  1,  1) \
    TIMER_PIN_MAP( 2,  PA2,  1,  2) \
    TIMER_PIN_MAP( 3,  PA3,  1,  3) \
    TIMER_PIN_MAP( 4,  PE9,  1,  4) \
    TIMER_PIN_MAP( 5,  PE11, 1,  5) \
    TIMER_PIN_MAP( 6,  PC8,  1,  6) \
    TIMER_PIN_MAP( 7,  PC9,  1,  7) \
    TIMER_PIN_MAP( 8,  PD12, 1, -1) \
    TIMER_PIN_MAP( 9,  PD13, 1, -1) \
    TIMER_PIN_MAP( 10, PD14, 1, -1) \
    TIMER_PIN_MAP( 11, PD15, 1, -1) \
    TIMER_PIN_MAP( 12, PE5,  1, -1) \
    TIMER_PIN_MAP( 13, PE6,  1, -1) \
    TIMER_PIN_MAP( 14, PB0 , 2,  8)

#define ADC1_DMA_OPT        9
#define ADC3_DMA_OPT        10

#define BARO_I2C_INSTANCE              I2CDEV_2
#define MAG_I2C_INSTANCE               I2CDEV_2

#define DEFAULT_BLACKBOX_DEVICE        BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG          DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE   CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE   VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE    120  
#define DEFAULT_VOLTAGE_METER_SCALE    160 

#define BEEPER_INVERTED
#define PINIO1_CONFIG                  129
#define PINIO1_BOX                     40
#define BOX_USER1_NAME                 "CAM 1,2"
#define PINIO2_CONFIG                  129
#define PINIO2_BOX                     41
#define BOX_USER2_NAME                 "12V BEC"
#define PINIO3_CONFIG                  129
#define PINIO3_BOX                     0

#define GYRO_1_SPI_INSTANCE            SPI1
#define GYRO_1_ALIGN                   CW0_DEG
#define MAX7456_SPI_INSTANCE           SPI2
#define FLASH_SPI_INSTANCE             SPI3
#define GYRO_2_SPI_INSTANCE            SPI4
#define GYRO_2_ALIGN                   CW180_DEG
#define DEFAULT_GYRO_TO_USE            GYRO_CONFIG_USE_GYRO_BOTH
 

#define SERIALRX_UART                  SERIAL_PORT_UART5
#define ESC_SENSOR_UART                SERIAL_PORT_USART3
#define MSP_UART                       SERIAL_PORT_USART2
