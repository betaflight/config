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

#define BOARD_NAME        MOH7DV2
#define MANUFACTURER_ID   CUST

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_ACC_SPI_ICM42605
//#define USE_ACC_SPI_MPU6000
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42605
//#define USE_GYRO_SPI_MPU6000
//#define USE_ACCGYRO_IIM42652
#define USE_BARO
//#define USE_BARO_BMP581
//#define USE_BARO_BMP280
#define USE_BARO_DPS310
//#define USE_MAX7456
#define USE_SDCARD
#define USE_SDCARD_SDIO
#define USE_MAG
//#define USE_WING
//#define USE_OSD_HD
//#define USE_GPS
//#define USE_GPS_PLUS_CODES
//#define USE_ACRO_TRAINER
//#define USE_CAMERA_CONTROL
//#define USE_DSHOT
//#define USE_LED_STRIP
//#define USE_LED_STRIP_64
//#define USE_OPTICALFLOW
//#define USE_POSITION_HOLD
//#define USE_PINIO
//#define USE_SERVOS
//#define USE_SERIALRX
//#define USE_SERIALRX_CRSF
//#define USE_CRSF_V3
//#define USE_TELEMETRY
//#define USE_TELEMETRY_CRSF
//#define USE_I2C
//#define USE_HAL_DRIVER
//#define USE_FULL_LL_DRIVER
//#define USE_YAW_SPIN_RECOVERY
//#define USE_CUSTOM_BOX_NAMES
//#define USE_BOARD_INFO


//  MOTORS  //
#define MOTOR1_PIN           PB0
#define MOTOR2_PIN           PB1
#define MOTOR3_PIN           PA0
#define MOTOR4_PIN           PA1
#define MOTOR5_PIN           PA2
#define MOTOR6_PIN           PA3
#define MOTOR7_PIN           PD12
#define MOTOR8_PIN           PD13
//#define MOTOR9_PIN           PD14
//#define MOTOR10_PIN          PD15

//  SERVOS  //
#define SERVO1_PIN           PE5
#define SERVO2_PIN           PE6

//  UARTS  //
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10

#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PD6

#define UART3_TX_PIN         PD8
#define UART3_RX_PIN         PD9

#define UART4_TX_PIN         PB9
#define UART4_RX_PIN         PB8

#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7

#define UART7_TX_PIN         PE8
#define UART7_RX_PIN         PE7

#define UART8_TX_PIN         PE1
#define UART8_RX_PIN         PE0

//  I2C  //
#define I2C1_SCL_PIN         PB6
#define I2C1_SDA_PIN         PB7

#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11

//  SPI  //
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7


#define SPI3_SCK_PIN         PB3
#define SPI3_SDI_PIN         PB4
#define SPI3_SDO_PIN         PB5

#define SPI4_SCK_PIN         PE12
#define SPI4_SDI_PIN         PE13
#define SPI4_SDO_PIN         PE14

//  SDIO  //
#define SDIO_CK_PIN          PC12
#define SDIO_CMD_PIN         PD2
#define SDIO_D0_PIN          PC8
#define SDIO_D1_PIN          PC9
#define SDIO_D2_PIN          PC10
#define SDIO_D3_PIN          PC11

//  GYRO  //
#define GYRO_2_SPI_INSTANCE SPI4
#define GYRO_2_CS_PIN        PE11
#define GYRO_2_EXTI_PIN      PE15

#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_CS_PIN        PC15
#define GYRO_1_EXTI_PIN      PB2
//#define GYRO_2_ALIGN CW90_DEG
//#define GYRO_2_ALIGN CW0_DEG_FLIP
//#define DEFAULT_GYRO_TO_USE GYRO_CONFIG_USE_GYRO_1
#define DEFAULT_GYRO_TO_USE GYRO_CONFIG_USE_GYRO_BOTH


//  SD CARD  //
#define SDCARD_DETECT_PIN NONE
#define SDIO_DEVICE SDIODEV_1
#define SDIO_USE_4BIT 1


// ADC  //
#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC1
#define ADC_EXTERNAL1_PIN    PC4  //ADC12  AirS  :1-1
#define ADC_EXTERNAL2_PIN    PA4  //ADC12  VB2   :210
#define ADC_EXTERNAL3_PIN    PC5  //ADC12  CU2   :external divider needed
//#define ADC_RSSI_PIN         PC5

//  PINIO  //
#define PINIO1_PIN           PD10
#define PINIO1_BOX 40
#define PINIO1_CONFIG 129

#define PINIO2_PIN           PD11
#define PINIO2_BOX 41
#define PINIO2_CONFIG 129

//  OTHER  //
#define LED_STRIP_PIN        PA8
#define LED0_PIN             PE3
#define LED1_PIN             PE4
#define BEEPER_PIN           PA15
#define BEEPER_INVERTED
#define BEEPER_PWM_HZ 2500
#define USB_DETECT_PIN       PE2
#define RX_PPM_PIN           PC7  //SAME AS TX6 YOU CAN USE TX6 AS PPM IF YOU WANT BUT YOU NEED TO ACTIVATE TIMER
#define SPI3_CS1            PD4

//#define CAMERA_CONTROL_PIN PB8    //THERE IS A PAD FOR IT, IF YOU WANT JUST ACTIVE THIS AND TIMER

/* CS1/CS2 pads for SPI3 connection:
 * CS1 PD4
 * CS2 PE2
 */

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB0 , 2,  0) \
    TIMER_PIN_MAP( 1, PB1 , 2,  1) \
    TIMER_PIN_MAP( 2, PA0 , 2,  2) \
    TIMER_PIN_MAP( 3, PA1 , 2,  3) \
    TIMER_PIN_MAP( 4, PA2 , 2,  4) \
    TIMER_PIN_MAP( 5, PA3 , 2,  5) \
    TIMER_PIN_MAP( 6, PD12, 1,  6) \
    TIMER_PIN_MAP( 7, PD13, 1,  7) \
    TIMER_PIN_MAP( 8, PE5 , 1, -1) \
    TIMER_PIN_MAP( 9, PE6 , 1, -1) \
    TIMER_PIN_MAP(10, PA8 , 1,  8) \
    TIMER_PIN_MAP(11, PA15, 1, -1) \
    TIMER_PIN_MAP(12, PC7 , 2, -1) 



#define ADC1_DMA_OPT        9
#define ADC3_DMA_OPT        10
#define TIMUP3_DMA_OPT      11
#define TIMUP4_DMA_OPT      12
#define TIMUP5_DMA_OPT      13
//#define ADC2_DMA_OPT        14
//#define SDCARD_SDIO_DMA_OPT 14


/*  ÖRNEK
    TIMER_PIN_MAP( 0, PB0 , 2,  0) \    //MOTOR1_PIN TIM3_CH3
    TIMER_PIN_MAP( 1, PB1 , 2,  1) \    //MOTOR2_PIN TIM3_CH4
    TIMER_PIN_MAP( 2, PA0 , 2,  2) \    //MOTOR3_PIN TIM5_CH1
    TIMER_PIN_MAP( 3, PA1 , 2,  3) \    //MOTOR4_PIN TIM5_CH2
    TIMER_PIN_MAP( 4, PA2 , 2,  4) \    //MOTOR5_PIN TIM5_CH3
    TIMER_PIN_MAP( 5, PA3 , 2,  5) \    //MOTOR6_PIN TIM5_CH4
    TIMER_PIN_MAP( 6, PD12, 1,  6) \    //MOTOR7_PIN TIM4_CH1
    TIMER_PIN_MAP( 7, PD13, 1,  7) \    //MOTOR8_PIN TIM4_CH2
    TIMER_PIN_MAP( 8, PE5 , 1, -1) \    //SERVO 1 
    TIMER_PIN_MAP( 9, PE6 , 1, -1) \    //SERVO 2
    TIMER_PIN_MAP(10, PA8 , 1, 8) \    //LED STRIP
    TIMER_PIN_MAP(11, PA15, 1, -1)      //BEEPER
     TIMER_PIN_MAP(12, PC7 , 2, -1)     //UART6_RX_PIN-PPM
    TIMER_PIN_MAP( 13, PD14, 1,  0)     //MOTOR9_PIN TIM4_CH3    - 
    TIMER_PIN_MAP( 14, PD15, 1,  0)     //MOTOR10_PIN TIM4_CH4 - NO DMA  - 
    TIMER_PIN_MAP( 15, PB08, 1,  -1)    //camera control kullanırsan
*/


#define BARO_I2C_INSTANCE I2CDEV_2
#define MAG_I2C_INSTANCE I2CDEV_1
//#define DASHBOARD_I2C_INSTANCE I2CDEV_1
//#define DASHBOARD_I2C_INSTANCE (I2CDEV_1)

//#define DEFAULT_RX_FEATURE FEATURE_RX_SERIAL
#define SERIALRX_UART SERIAL_PORT_USART6
#define ESC_SENSOR_UART SERIAL_PORT_UART8
#define MSP_DISPLAYPORT_UART SERIAL_PORT_USART1
#define GPS_UART SERIAL_PORT_USART2
#define MSP_UART SERIAL_PORT_UART4

#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE_DEFAULT 110
#define DEFAULT_CURRENT_METER_SCALE 250


#define SYSTEM_HSE_MHZ 8




#define ENSURE_MPU_DATA_READY_IS_LOW
