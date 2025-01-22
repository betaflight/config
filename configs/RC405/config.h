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

#define BOARD_NAME        RC405
#define MANUFACTURER_ID   RADIOCOMP

#define USE_ACC
#define USE_GYRO

#define USE_ACC_SPI_MPU6000          // For MPU6000 variation
#define USE_GYRO_SPI_MPU6000         // For MPU6000 variation

#define USE_ACC_SPI_ICM42688P        // For ICM42688P variation
#define USE_GYRO_SPI_ICM42688P       // For ICM42688P variation

#define USE_ACCGYRO_BMI270           // For BMI270 variation

#define USE_BARO
#define USE_BARO_BMP280

#define USE_MAG
#define USE_MAG_QMC5883

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G
#define USE_MAX7456

#define SYSTEM_HSE_MHZ 8

#ifndef USE_CAMERA_CONTROL
#define USE_CAMERA_CONTROL
#endif

/**********************************************************************
 * Motor                                                              *
 **********************************************************************/
#define MOTOR1_PIN           PB0
#define MOTOR2_PIN           PB1
#define MOTOR3_PIN           PC8
#define MOTOR4_PIN           PC9

/**********************************************************************
 * SERVO                                                              *
 **********************************************************************/
#define SERVO1_PIN           PA9
#define SERVO2_PIN           PA10

#define RX_PPM_PIN           PC7  

/**********************************************************************
 * UART Bus                                                           *
 **********************************************************************/
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

/**********************************************************************
 * I2C Bus                                                            *
 **********************************************************************/
#define USE_I2C
#define USE_I2C_DEVICE_1

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9

#define BARO_I2C_INSTANCE (I2CDEV_1)
#define MAG_I2C_INSTANCE  (I2CDEV_1)

/**********************************************************************
 * LED & LED strip & Buzzer                                           *
 **********************************************************************/
#define LED0_PIN             PC15
#define LED1_PIN             PC14
#define LED_STRIP_PIN        PA8
#define BEEPER_PIN           PC13
#define BEEPER_INVERTED

/**********************************************************************
 * SPI Bus                                                            *
 **********************************************************************/
#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PB3

#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PB4

#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PB5

#define GYRO_1_SPI_INSTANCE  SPI1
#define FLASH_SPI_INSTANCE   SPI2
#define MAX7456_SPI_INSTANCE SPI3

/**********************************************************************
 * Camera control                                                     *
 **********************************************************************/
#define CAMERA_CONTROL_PIN   PA15 

/**********************************************************************
 * ADC                                                                *
 **********************************************************************/
#define ADC_VBAT_PIN         PC1
#define ADC_RSSI_PIN         PC2
#define ADC_CURR_PIN         PC3

/**********************************************************************
 * CS pins                                                            *
 **********************************************************************/
#define FLASH_CS_PIN         PB12
#define MAX7456_SPI_CS_PIN   PC11
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_CS_PIN        PA4

/**********************************************************************
 * PINIO                                                              *
 **********************************************************************/
#define PINIO1_PIN           PA14
#define PINIO2_PIN           PC10
#define PINIO3_PIN           PC0
#define PINIO4_PIN           PC5

#define PINIO1_BOX 40       // User 1 on/off 3,3 В on pad
#define PINIO2_BOX 41       // User 2 K1 - external load control key 1 connect pad to GND 
#define PINIO3_BOX 42       // User 3 K2 - external load control key 2 connect pad to GND
#define PINIO4_BOX 43       // User 4 Switch Camera

#define PINIO1_CONFIG 1
#define PINIO2_CONFIG 1
#define PINIO3_CONFIG 1
#define PINIO4_CONFIG 1

/**********************************************************************
 * Timer                                                              *
 **********************************************************************/
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB0 ,  2,  0)  \
    TIMER_PIN_MAP( 1, PB1 ,  2,  0)  \
    TIMER_PIN_MAP( 2, PC8 ,  3,  1)  \
    TIMER_PIN_MAP( 3, PC9 ,  3,  1)  \
    TIMER_PIN_MAP( 4, PA8 ,  1,  1)  \
    TIMER_PIN_MAP( 5, PA9 ,  1,  1)  \
    TIMER_PIN_MAP( 6, PA10,  1,  1)  \
    TIMER_PIN_MAP( 7, PA15,  1,  -1) \
    TIMER_PIN_MAP( 8, PC7,   3,  1)

// DMA

#define SPI2_TX_DMA_OPT     0

#define ADC2_DMA_OPT        1
#define ADC_INSTANCE ADC2

/**********************************************************************
 * Default settings                                                   *
 **********************************************************************/
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     100
#define DEFAULT_CURRENT_METER_SCALE     250

#define GYRO_1_ALIGN CW0_DEG
#define GYRO_1_ALIGN_YAW 0

#define MAG_ALIGN CW0_DEG
#define MAG_ALIGN_YAW 0
