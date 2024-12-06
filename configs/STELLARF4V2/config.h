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

#define FC_TARGET_MCU STM32F405
#define BOARD_NAME STELLARF4V2
#define MANUFACTURER_ID STBE

#define TARGET_BOARD_IDENTIFIER "STF4"
#define USBD_PRODUCT_STRING     "StingBee Stellar F4 V2"

#define USE_ACC
#define USE_ACC_SPI_ICM42605
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42605
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_CLKIN
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#define USE_MAX7456
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_W25M02G

#define BEEPER_PIN          PB2
#define MOTOR1_PIN          PC9 // TIM8 CH4 (AF3) DMA2 Stream 7 Channel 7
#define MOTOR2_PIN          PC8 // TIM8 CH3 (AF3) DMA2 Stream 4 Channel 7
#define MOTOR3_PIN          PC7 // TIM8 CH2 (AF3) DMA2 Stream 3 Channel 7
#define MOTOR4_PIN          PC6 // TIM8 CH1 (AF3) DMA2 Stream 2 Channel 7
#define SERVO1_PIN          PB6 // TIM4 CH1 (AF2)
#define SERVO2_PIN          PB7 // TIM4 CH2 (AF2)
#define SERVO3_PIN          PB8 // TIM4 CH3 (AF2)
#define SERVO4_PIN          PB9 // TIM4 CH4 (AF2)
#define SERVO5_PIN          PA9 // TIM1 CH2 (AF1) or UART1_TX_PIN
#define SERVO6_PIN          PA10 // TIM1 CH3 (AF1) or UART1_RX_PIN
#define SERVO7_PIN          PA8 // TIM1 CH1 (AF1) 

#define RX_PPM_PIN          PA3 // TIM5 CH4 (AF2) 
#define UART2_TX_PIN        PA2
#define UART3_TX_PIN        PC10
#define UART4_TX_PIN        PA0
#define UART5_TX_PIN        PC12
#define UART2_RX_PIN        PA3
#define UART3_RX_PIN        PC11
#define UART4_RX_PIN        PA1
#define UART5_RX_PIN        PD2
#define I2C2_SCL_PIN        PB10
#define I2C2_SDA_PIN        PB11
#define LED0_PIN            PA15
#define SPI1_SCK_PIN        PA5
#define SPI2_SCK_PIN        PB13
#define SPI3_SCK_PIN        PB3
#define SPI1_SDI_PIN        PA6
#define SPI2_SDI_PIN        PC2
#define SPI3_SDI_PIN        PB4
#define SPI1_SDO_PIN        PA7
#define SPI2_SDO_PIN        PB15
#define SPI3_SDO_PIN        PB5
#define ADC_VBAT_PIN        PC0
#define ADC_CURR_PIN        PC1
#define FLASH_CS_PIN        PC13
#define PINIO1_PIN          PC14
#define MAX7456_SPI_CS_PIN  PB12
#define GYRO_1_EXTI_PIN     PA4
#define GYRO_1_CS_PIN       PC5
#define GYRO_1_CLKIN_PIN    PB0 // // TIM3 CH3 (AF2) no DMA

#define TIMER_PIN_MAPPING   TIMER_PIN_MAP( 0,  PC9,  2,  0 ) \
                            TIMER_PIN_MAP( 1,  PC8,  2,  1 ) \
                            TIMER_PIN_MAP( 2,  PC7,  2,  1 ) \
                            TIMER_PIN_MAP( 3,  PC6,  2,  1 ) \
                            TIMER_PIN_MAP( 4,  PB6,  1, -1 ) \
                            TIMER_PIN_MAP( 5,  PB7,  1, -1 ) \
                            TIMER_PIN_MAP( 6,  PB8,  1, -1 ) \
                            TIMER_PIN_MAP( 7,  PB9,  1, -1 ) \
                            TIMER_PIN_MAP( 8,  PA9,  1, -1 ) \
                            TIMER_PIN_MAP( 9,  PA10, 1, -1 ) \
                            TIMER_PIN_MAP( 10, PA8,  1, -1 ) \
                            TIMER_PIN_MAP( 11, PA3 , 2, -1 ) \
                            TIMER_PIN_MAP( 12, PB0,  2, -1 )

#define ADC_INSTANCE ADC3
#define ADC3_DMA_OPT 1 //  DMA2 Stream 1 Channel 2

#define SERIALRX_UART SERIAL_PORT_USART2
#define SERIALRX_PROVIDER SERIALRX_CRSF

#define MAG_I2C_INSTANCE I2CDEV_2
#define BARO_I2C_INSTANCE I2CDEV_2

#define DEFAULT_DSHOT_BURST DSHOT_DMAR_OFF
#define MOTOR_PWM_PROTOCOL DSHOT300
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE 110
#define DEFAULT_CURRENT_METER_SCALE 100
#define BEEPER_INVERTED
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define FLASH_SPI_INSTANCE SPI3
#define MAX7456_SPI_INSTANCE SPI2

#define PINIO1_BOX 40
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW180_DEG
#define GYRO_1_ALIGN_PITCH 1800

#define BOX_USER1_NAME       "CAM 1,2"
