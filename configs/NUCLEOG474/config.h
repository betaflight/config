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

#define FC_TARGET_MCU STM32G47X

#define BOARD_NAME NUCLEOG474
#define MANUFACTURER_ID STMI

// minimal config for NUCLEO-G474RE
// MSP over USB and STLink virtual port do work

// For USB connection:
//  GND (CN10-9)  - GND    (4/black)
//  PA11(CN10-14) - USB-   (3/white)
//  PA12(CN10-12) - USB+   (2/green)
//  no connection - USB 5V (1/red)

#define USE_GYRO
#define USE_FAKE_GYRO
#define USE_GYRO_MPU6050
#define USE_ACC
#define USE_FAKE_ACC
#define USE_ACC_MPU6050
#define USE_MAG
#define USE_FAKE_MAG
#define USE_SONAR
#define USE_RX_SPI
#define USE_CC2500

#define MOTOR1_PIN                      PA10  // ARD_D2
#define MOTOR2_PIN                      PB4   // ARD_D5
#define MOTOR3_PIN                      PB10  // ARD_D6
#define MOTOR4_PIN                      PC7   // ARD_D9

#define UART1_TX_PIN                    PC4 // ARD_D1
#define UART1_RX_PIN                    PC5 // ARD_D0

#define LPUART1_TX_PIN                  PA2  // STLINK-V3E Virtual COM port
#define LPUART1_RX_PIN                  PA3
#define USE_MSP_UART                    SERIAL_PORT_LPUART1 // enable MSP on Virtual COM

#define I2C1_SCL_PIN                    PB8    // ARD_D15
#define I2C1_SDA_PIN                    PB9    // ARD_D14
#define LED0_PIN                        PA5    // ARD_D13 / User LED LD2, SB6 solder bridge
#define SPI1_SCK_PIN                    PB3    // ARD_D3
#define SPI1_SDI_PIN                    PA6    // ARD_D12 MISO
#define SPI1_SDO_PIN                    PA7    // ARD_D11 MOSI


#define USE_ADC
#define ADC_INSTANCE                    ADC2

#define ADC_VBAT_PIN                    PA0    // ARD_A0
#define ADC_RSSI_PIN                    PA1    // ARD_A1
#define ADC_CURR_PIN                    PA4    // ARD_A2
