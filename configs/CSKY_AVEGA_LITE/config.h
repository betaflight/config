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

#define FC_TARGET_MCU     STM32F427

#define BOARD_NAME        AVEGA_LITE
#define MANUFACTURER_ID   CSKY

#define USE_GYRO
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_GYRO_SPI_MPU6000
#define USE_MAX7456
//#define USE_SDCARD
//#define USE_BARO_DPS310

#define BEEPER_PIN           PD1

#define MOTOR1_PIN           PE14
#define MOTOR2_PIN           PE13
#define MOTOR3_PIN           PE11
#define MOTOR4_PIN           PE9

#define MOTOR5_PIN           PC9
#define MOTOR6_PIN           PC8
#define MOTOR7_PIN           PC7
#define MOTOR8_PIN           PC6

#define SERVO1_PIN           PA15
#define SERVO2_PIN           PB11
#define SERVO3_PIN           PB3
#define SERVO4_PIN           PB10

#define RX_PPM_PIN           PB7
//#define LED_STRIP_PIN        PC9 TODO
#define UART1_TX_PIN         PB6
#define UART2_TX_PIN         PA2
#define UART3_TX_PIN         PD8
#define UART4_TX_PIN         PA0
#define UART5_TX_PIN         PC12
#define UART6_TX_PIN         PG14

#define UART1_RX_PIN         PA10
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PD9
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PD2
#define UART6_RX_PIN         PG9
// TODO add 7 8 uarts
//#define I2C2_SCL_PIN         PF1
//#define I2C2_SDA_PIN         PF0

#define LED0_PIN             PC0
#define LED1_PIN             PC1

#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PC2
#define SPI2_SDO_PIN         PC3

#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PD6

#define SPI5_SCK_PIN         PF7
#define SPI5_SDI_PIN         PF8
#define SPI5_SDO_PIN         PF9
//#define CAMERA_CONTROL_PIN   PB3 TODO
#define ADC_VBAT_PIN         PC5
//#define ADC_RSSI_PIN         PC2
#define ADC_CURR_PIN         PA5

#define PINIO1_PIN           PA9

#define SDCARD_SPI_CS_PIN    PD7
#define MAX7456_SPI_CS_PIN   PF4
#define GYRO_1_CS_PIN        PB12

#define GYRO_1_EXTI_PIN      PA8

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PE14 , 1,  0) \
    TIMER_PIN_MAP( 1, PE13 , 1,  0) \
    TIMER_PIN_MAP( 2, PE11 , 1,  0) \
    TIMER_PIN_MAP( 3, PE9 , 1, 0) \
    TIMER_PIN_MAP( 4, PC9 , 2,  0) \
    TIMER_PIN_MAP( 5, PB1 , 2,  0) \
    TIMER_PIN_MAP( 6, PC7 , 1,  0) \
    TIMER_PIN_MAP( 7, PC6 , 1,  0) \
    TIMER_PIN_MAP( 8, PA15 , 1,  0) \
    TIMER_PIN_MAP( 9, PB11 , 2,  0) \
    TIMER_PIN_MAP(10, PB3 , 1,  0) \
    TIMER_PIN_MAP(11, PB10 , 2,  0)


//#define SPI2_TX_DMA_OPT     0
#define ADC1_DMA_OPT        0

//#define MAG_I2C_INSTANCE (I2CDEV_2)
//#define USE_BARO
//#define BARO_I2C_INSTANCE (I2CDEV_2)

#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD
#define DEFAULT_DSHOT_BURST DSHOT_DMAR_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE 386
#define BEEPER_INVERTED
//#define USE_SDCARD_SPI
//#define SDCARD_SPI_INSTANCE SPI3
#define SYSTEM_HSE_MHZ 8
#define USE_MAX7456
#define MAX7456_SPI_INSTANCE SPI5
//#define DASHBOARD_I2C_INSTANCE (I2CDEV_2)
#define PINIO1_CONFIG PINIO_CONFIG_OUT_INVERTED
#define PINIO1_BOX 0
#define USE_SPI_GYRO
#define GYRO_1_SPI_INSTANCE SPI2
#define GYRO_1_ALIGN CW0_DEG_FLIP

#define MSP_DISPLAYPORT_UART    SERIAL_PORT_USART2
#define SERIALRX_UART           SERIAL_PORT_USART1
#define MSP_UART                SERIAL_PORT_UART4
//#define ESC_SENSOR_UART         SERIAL_PORT_UART5 TODO
