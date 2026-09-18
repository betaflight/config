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
    SUPPORTED TARGET - THANK YOU
    REFERENCE: sha256_fac5a440080380dd0515aa3fbe743451d68933a21eba68f5cb30c0ee4f45da20
    DATE: 2025-01-01
*/

#pragma once

#define FC_TARGET_MCU     AT32F435G

#define BOARD_NAME        HUMMINGBIRD_AIO255
#define MANUFACTURER_ID   HBRD 

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G
#define USE_MAX7456

#define BEEPER_PIN           PB1
#define MOTOR1_PIN           PA6
#define MOTOR2_PIN           PA7
#define MOTOR3_PIN           PA10
#define MOTOR4_PIN           PA9
#define LED0_PIN             PH2
#define LED_STRIP_PIN        PA15
#define UART4_TX_PIN         PA0
#define UART5_TX_PIN         PB6
#define UART6_TX_PIN         PA4
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PB5
#define UART6_RX_PIN         PA5
#define UART7_RX_PIN         PB3
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11

#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PB12
#define SPI4_SCK_PIN         PB7
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PB4
#define SPI4_SDI_PIN         PB8
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PB0
#define SPI4_SDO_PIN         PB9

#define ADC_VBAT_PIN         PA2
#define ADC_CURR_PIN         PA3
#define PINIO1_PIN           PH3 //VTX 10V
#define FLASH_CS_PIN         PC15
#define MAX7456_SPI_CS_PIN   PA8
#define GYRO_1_EXTI_PIN      PC13
#define GYRO_1_CS_PIN        PC14

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, LED_STRIP_PIN, 1, 0) \
    TIMER_PIN_MAP( 1, MOTOR1_PIN   , 1, 1) \
    TIMER_PIN_MAP( 2, MOTOR2_PIN   , 2, 2) \
    TIMER_PIN_MAP( 3, MOTOR3_PIN   , 1, 3) \
    TIMER_PIN_MAP( 4, MOTOR4_PIN   , 1, 4) 

#define ADC_INSTANCE         ADC1
#define ADC1_DMA_OPT         12

#define BARO_I2C_INSTANCE  I2CDEV_2
#define MAG_I2C_INSTANCE   I2CDEV_2
#define FLASH_SPI_INSTANCE SPI3
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE 107
#define DEFAULT_CURRENT_METER_SCALE 300
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ 8
#define MAX7456_SPI_INSTANCE SPI2
#define GYRO_1_SPI_INSTANCE SPI4

#define PINIO1_CONFIG 129
#define PINIO1_BOX 40
