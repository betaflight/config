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

#define FC_TARGET_MCU     RP2350B
#define BOARD_NAME        HELLBENDER_0001
#define MANUFACTURER_ID   RASP

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P

#define MAX7456_SPI_INSTANCE SPI1
#define SDCARD_SPI_INSTANCE  SPI1
#define GYRO_1_SPI_INSTANCE  SPI0

#define MOTOR1_PIN           PA28
#define MOTOR2_PIN           PA29
#define MOTOR3_PIN           PA30
#define MOTOR4_PIN           PA31

#define LED0_PIN             PA6
#define LED1_PIN             PA7

#define SPI0_SCK_PIN         PA2
#define SPI0_SDI_PIN         PA4
#define SPI0_SDO_PIN         PA3

#define SPI1_SCK_PIN         PA26
#define SPI1_SDI_PIN         PA24
#define SPI1_SDO_PIN         PA27

#define SDCARD_CS_PIN        PA25
//#define FLASH_CS_PIN         PA0
#define MAX7456_SPI_CS_PIN   PA17
#define USE_MAX7456

#define GYRO_1_CS_PIN        PA1
#define GYRO_1_EXTI_PIN      PA22

#define GYRO_2_CS_PIN        NONE

#define UART1_TX_PIN         PA20
#define UART1_RX_PIN         PA21

#define USE_BARO
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE    I2CDEV_0
#define I2C0_SDA_PIN         PA44
#define I2C0_SCL_PIN         PA45

#define USE_BEEPER
#define BEEPER_PWM_HZ        1971
#define BEEPER_PIN           PA5

#define PICO_BEC_5V_ENABLE_PIN PA14

/*

SPI0_CS         PA1
SPI0_SCLK       PA2
SPI0_COPI       PA3
SPI0_CIPO       PA4
BUZZER          PA5
LED0            PA6
LED1            PA7
UART1_TX        PA8
UART1_RX        PA9
I2C1_SDA        PA10
I2C1_SCL        PA11
UART0_TX        PA12
UART0_RX        PA13

OSD_CS          PA17

UART2_TX        PA20
UART2_RX        PA21

GYRO_INT        PA22

GYRO_CLK        PA23

SPI1_CIPO       PA24
SPI1_CS         PA25
SPI1_SCLK       PA26
SPI1_COPI       PA27

MOTOR1          PA28
MOTOR2          PA29
MOTOR3          PA30
MOTOR4          PA31

SPARE1          PA32
SPARE2          PA33

UART3_TX        PA34
UART3_RX        PA35

DVTX_SBUS_RX    PA36
TELEM_RX        PA37
LED_STRIP       PA38
RGB_LED         PA39

VBAT_SENSE      PA40
CURR_SENSE      PA41
ADC_SPARE       PA42

I2C0_SDA        PA44
I2C0_SCL        PA45

SPARE3          PA47

*/
