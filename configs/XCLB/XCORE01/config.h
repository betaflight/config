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

#define FC_TARGET_MCU     X32M7B

#define BOARD_NAME        XCORE01
#define MANUFACTURER_ID   XCLB
#define SYSTEM_HSE_MHZ    25 // Required 25 MHz external crystal; must not be changed.

#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_LSM6DSK320X
#define USE_ACCGYRO_BMI270

#define USE_MAG
#define USE_BARO
#define USE_BARO_BMP388 // This driver also detects BMP390.
#define USE_BARO_DPS310
#define USE_MAX7456
#define USE_GYRO_CLKIN
#define USE_BLACKBOX
#define USE_SDCARD
#define USE_PINIO
#define USE_LED_STRIP

#define BEEPER_PIN           PA15 //GTIMA1_CH1
#define MOTOR1_PIN           PA0  //GTIMA4_CH1
#define MOTOR2_PIN           PA1  //GTIMA4_CH2
#define MOTOR3_PIN           PA2  //GTIMA4_CH3
#define MOTOR4_PIN           PA3  //GTIMA4_CH4
#define MOTOR5_PIN           PD12 //GTIMA3_CH1
#define MOTOR6_PIN           PD13 //GTIMA3_CH2
#define MOTOR7_PIN           PD14 //GTIMA3_CH3
#define MOTOR8_PIN           PD15 //GTIMA3_CH4
#define SERVO1_PIN           PB14 //GTIMA7_CH1
#define SERVO2_PIN           PB15 //GTIMA7_CH2
#define LED0_PIN             PD3
#define LED1_PIN             PD4
#define LED_STRIP_PIN        PE6  //GTIMB1_CH2

#define UART1_RX_PIN         PB7
#define UART1_TX_PIN         PB6
#define UART3_RX_PIN         PD9
#define UART3_TX_PIN         PD8
#define UART4_RX_PIN         PC7
#define UART4_TX_PIN         PC6
#define UART5_RX_PIN         PE2
#define UART5_TX_PIN         PE3
#define UART6_RX_PIN         PE4
#define UART6_TX_PIN         PE5
#define UART9_RX_PIN         PD0
#define UART9_TX_PIN         PD1
#define UART10_RX_PIN        PB12
#define UART10_TX_PIN        PB13
#define UART11_RX_PIN        PE7
#define UART11_TX_PIN        PE8
#define UART12_RX_PIN        PE0
#define UART12_TX_PIN        PE1

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define I2C10_SDA_PIN        PJ13
#define I2C10_SCL_PIN        PJ14

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define SPI1_NSS_PIN         PA4
#define SPI3_SCK_PIN         PB3
#define SPI3_SDI_PIN         PB4
#define SPI3_SDO_PIN         PB5
#define SPI3_NSS_PIN         PD10
#define SPI6_SCK_PIN         PE12
#define SPI6_SDI_PIN         PE13
#define SPI6_SDO_PIN         PE14
#define SPI6_NSS_PIN         PE11
#define SDIO_CK_PIN          PC12
#define SDIO_CMD_PIN         PD2
#define SDIO_D0_PIN          PC8
#define SDIO_D1_PIN          PC9
#define SDIO_D2_PIN          PC10
#define SDIO_D3_PIN          PC11

#define GYRO_1_CLKIN_PIN     PE9  //ATIM1_CH1
#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC1
// #define ADC_VBAT2_PIN        PB1
// #define ADC_CURR2_PIN        PJ0
#define ADC_EXTERNAL1_PIN    PC4
#define ADC_RSSI_PIN         PC5

#define PINIO1_PIN           PC15 // 10V enable: high = on
#define PINIO2_PIN           PC14 // Camera select: low = CAM1, high = CAM2
#define PINIO3_PIN           PC13
#define GYRO_1_CS_PIN        SPI1_NSS_PIN
#define GYRO_1_EXTI_PIN      PE10
#define MAX7456_SPI_CS_PIN   SPI3_NSS_PIN

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN , 2,  1)\
    TIMER_PIN_MAP( 1, MOTOR2_PIN , 2,  2)\
    TIMER_PIN_MAP( 2, MOTOR3_PIN , 2,  3)\
    TIMER_PIN_MAP( 3, MOTOR4_PIN , 2,  4)\
    TIMER_PIN_MAP( 4, MOTOR5_PIN , 1,  5)\
    TIMER_PIN_MAP( 5, MOTOR6_PIN , 1,  6)\
    TIMER_PIN_MAP( 6, MOTOR7_PIN , 2,  7)\
    TIMER_PIN_MAP( 7, MOTOR8_PIN , 2, 11)\
    TIMER_PIN_MAP( 8, SERVO1_PIN , 3,  -1)\
    TIMER_PIN_MAP( 9, SERVO2_PIN , 3,  -1)\
    TIMER_PIN_MAP( 10, BEEPER_PIN , 1,  -1)\
    TIMER_PIN_MAP( 11, LED_STRIP_PIN , 1,  0)\
    TIMER_PIN_MAP( 12, GYRO_1_CLKIN_PIN , 1,  -1)

#define ADC_INSTANCE        ADC1
#define ADC1_DMA_OPT        8
#define ADC2_DMA_OPT        9
#define ADC3_DMA_OPT        10

#define ENSURE_MPU_DATA_READY_IS_LOW
#define PINIO1_BOX                   40
#define PINIO2_BOX                   41
#define PINIO3_BOX                   42
#define BOX_USER1_NAME               "10V_ENABLE"
#define BOX_USER2_NAME               "CAM1/CAM2"
#define PINIO1_CONFIG                129 // Inverted push-pull; default 10V on
#define PINIO2_CONFIG                1   // Push-pull; default CAM1, USER2 selects CAM2
#define PINIO3_CONFIG                129
#define BARO_I2C_INSTANCE            I2CDEV_10
#define MAG_I2C_INSTANCE             I2CDEV_2
#define GYRO_1_SPI_INSTANCE          SPI1
#define MAX7456_SPI_INSTANCE         SPI3
#define GPS_UART                     SERIAL_PORT_UART9
#define SERIALRX_UART                SERIAL_PORT_USART1
#define ESC_SENSOR_UART              SERIAL_PORT_USART3
#define SDCARD_DETECT_INVERTED
#define SDCARD_DETECT_PIN            NONE
#define SDIO_DEVICE                  SDIODEV_1
#define SDIO_USE_4BIT                1
#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_SDCARD
#define DEFAULT_RX_FEATURE           FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER            SERIALRX_CRSF
#define DEFAULT_DSHOT_BITBANG        DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE  110
#define BEEPER_INVERTED
