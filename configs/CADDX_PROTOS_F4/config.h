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

/*
    NOTE: this board is community and manufacturer supported only.
*/

#pragma once

#define FC_TARGET_MCU     STM32F405

#define BOARD_NAME        CADDX_PROTOS_F4
#define MANUFACTURER_ID   CADX

//---------------SPI+I2C------------
// gyro+acc
#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270

#define GYRO_1_CS_PIN        PA4
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_SPI_INSTANCE  SPI1
#define DEFAULT_ALIGN_BOARD_YAW -45

// baro
#define USE_BARO
#define USE_BARO_DPS310
#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9
#define BARO_I2C_INSTANCE    I2CDEV_1
#define MAG_I2C_INSTANCE     I2CDEV_1

// osd
#define USE_MAX7456
#define MAX7456_SPI_CS_PIN   PB12
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15
#define MAX7456_SPI_INSTANCE SPI2

// flash
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define FLASH_CS_PIN         PA15
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12
#define FLASH_SPI_INSTANCE   SPI3
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH

//------------UART---------------
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define GPS_UART             SERIAL_PORT_USART1

#define UART2_TX_PIN         PA2
#define UART2_RX_PIN         PA3

#define UART3_TX_PIN         PB10
#define UART3_RX_PIN         PB11

#define UART4_TX_PIN         PA0
#define UART4_RX_PIN         PA1
#define MSP_DISPLAYPORT_UART SERIAL_PORT_UART4

#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7
#define USE_RX_CRSF
#define DEFAULT_RX_FEATURE FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER SERIALRX_CRSF
#define SERIALRX_UART SERIAL_PORT_USART6

//------PWM+DMA---------
#define MOTOR1_PIN           PC8
#define MOTOR2_PIN           PC9
#define MOTOR3_PIN           PB0
#define MOTOR4_PIN           PB1
#define LED_STRIP_PIN        PB6

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PC8 , 2,  0) \
    TIMER_PIN_MAP( 1, PC9 , 2,  0) \
    TIMER_PIN_MAP( 2, PB0 , 2,  0) \
    TIMER_PIN_MAP( 3, PB1 , 2,  0) \
    TIMER_PIN_MAP( 4, PB6 , 1,  0) 

#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_OFF

//-----------GPIO----------
#define LED0_PIN             PB5
#define BEEPER_PIN           PB4
#define BEEPER_INVERTED

//-----------ADC-------------
#define ADC_CURR_PIN         PC1
#define ADC_VBAT_PIN         PC2
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     109
#define DEFAULT_CURRENT_METER_SCALE     191
#define ADC1_DMA_OPT        1
#define ADC_INSTANCE ADC1

