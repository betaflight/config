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

#define BOARD_NAME        SAKURAH743
#define MANUFACTURER_ID   SSAK

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_IIM42652
#define USE_BARO
#define USE_BARO_SPI_DPS310
#ifndef USE_MAG
#define USE_MAG
#endif
#define USE_MAG_IST8310
#define USE_SDCARD

//buzzer
#define BEEPER_PIN           PD7

//motor
#define MOTOR1_PIN           PA2
#define MOTOR2_PIN           PA3
#define MOTOR3_PIN           PB1
#define MOTOR4_PIN           PB0
#define MOTOR5_PIN           PA1
#define MOTOR6_PIN           PA0
#define MOTOR7_PIN           PE5
#define MOTOR8_PIN           PE6

//additional pwm out
#define SERVO1_PIN           PD12
#define SERVO2_PIN           PD13
#define SERVO3_PIN           PD14
#define SERVO4_PIN           PD15

//sbus input
#define RX_PPM_PIN           PB8

//external led 
#define LED_STRIP_PIN        PA8

//uart
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

//i2c
#define I2C1_SCL_PIN         PB6
#define I2C1_SDA_PIN         PB7
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11

//onboard led
#define LED0_PIN             PB3
#define LED1_PIN             PB4
#define LED2_PIN             PB5

//spi1 for IIM42652 and baro
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7

//external spi
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15

//spi4 for icm42688
#define SPI4_SCK_PIN         PE12
#define SPI4_SDI_PIN         PE13
#define SPI4_SDO_PIN         PE14

//adc
#define ADC_VBAT_PIN         PC3
#define ADC_CURR_PIN         PC2
#define ADC_EXTERNAL1_PIN    PC0
#define ADC_RSSI_PIN         PC1

//sd card
#define SDIO_CK_PIN          PC12
#define SDIO_CMD_PIN         PD2
#define SDIO_D0_PIN          PC8
#define SDIO_D1_PIN          PC9
#define SDIO_D2_PIN          PC10
#define SDIO_D3_PIN          PC11

//pinio
#define PINIO1_PIN           PE15
#define PINIO2_PIN           PD10
#define PINIO3_PIN           PD11

//sensor CS and EXTI
#define GYRO_1_EXTI_PIN      PB2
#define GYRO_2_EXTI_PIN      PC4
#define GYRO_1_CS_PIN        PE11
#define GYRO_2_CS_PIN        PA4
#define BARO_CS_PIN          PC5

/* CS1 pads for SPI2 connection:
 *
 * CS1 PB12
 */

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA2 , 2,  0) \
    TIMER_PIN_MAP( 1, PA3 , 2,  1) \
    TIMER_PIN_MAP( 2, PB0 , 2,  2) \
    TIMER_PIN_MAP( 3, PB1 , 2,  3) \
    TIMER_PIN_MAP( 4, PA0 , 2,  4) \
    TIMER_PIN_MAP( 5, PA1 , 2,  5) \
    TIMER_PIN_MAP( 6, PE5 , 1,  6) \
    TIMER_PIN_MAP( 7, PE6 , 1, -1) \
    TIMER_PIN_MAP( 8, PD12, 1, -1) \
    TIMER_PIN_MAP( 9, PD13, 1, -1) \
    TIMER_PIN_MAP(10, PD14, 1, -1) \
    TIMER_PIN_MAP(11, PD15, 1, -1) \
    TIMER_PIN_MAP(12, PB8 , 1, -1) \
    TIMER_PIN_MAP(13, PA8 , 1,  7) 

#define ADC1_DMA_OPT        8
#define ADC3_DMA_OPT        9
#define TIMUP3_DMA_OPT      10
#define TIMUP5_DMA_OPT      11

#define USB_DETECT PD4

//mag config
#define MAG_I2C_INSTANCE I2CDEV_1
#define MAG_I2C_ADDRESS 14
#define MAG_ALIGN CW180_DEG

//default behavior
#define DEFAULT_RX_FEATURE FEATURE_RX_SERIAL
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE 170
#define DEFAULT_VOLTAGE_METER_DIVIDER 5
#define DEFAULT_CURRENT_METER_SCALE 250
#define BEEPER_INVERTED


//sdcard config
#define SDCARD_DETECT_PIN NONE
#define SDIO_DEVICE SDIODEV_1
#define SDIO_USE_4BIT 1

//pinio config
#define PINIO1_BOX 40
#define PINIO2_BOX 41
#define PINIO3_BOX 43
#define PINIO1_CONFIG 129

//gyro config
#define GYRO_1_SPI_INSTANCE SPI4
#define GYRO_1_ALIGN CW0_DEG_FLIP
#define GYRO_2_SPI_INSTANCE SPI1
#define GYRO_2_ALIGN CW0_DEG_FLIP

//baro config
#define BARO_SPI_INSTANCE SPI1

//default serial mapping
#define USE_I2C_PULLUP
#define MSP_UART SERIAL_PORT_USART1
#define MSP_DISPLAYPORT_UART SERIAL_PORT_USART6
#define GPS_UART SERIAL_PORT_USART3
#define ESC_SENSOR_UART SERIAL_PORT_USART8
#define SERIALRX_UART SERIAL_PORT_UART4
