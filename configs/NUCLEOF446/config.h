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

// #define USE_TARGET_CONFIG

#define FC_TARGET_MCU                   STM32F446

#define BOARD_NAME                      NUCLEOF446
#define MANUFACTURER_ID                 STMI

#define USE_ACC
#define USE_FAKE_ACC
#define USE_ACC_SPI_MPU6500
#define USE_ACC_SPI_MPU9250
#define USE_GYRO
#define USE_FAKE_GYRO
#define USE_GYRO_SPI_MPU6500
#define USE_GYRO_SPI_MPU9250
#define USE_BARO
#define USE_FAKE_BARO
#define USE_MAG
#define USE_FAKE_MAG
//#define USE_MAX7456
//#define USE_SDCARD
#define USE_SONAR
#define USE_RX_SPI
#define USE_CC2500
// #define USE_RX_NRF24
// #define USE_RX_CX10
// #define USE_RX_H8_3D
// #define USE_RX_INAV
// #define USE_RX_SYMA
// #define USE_RX_V202

//#define USE_BEEPER
//#define BEEPER_PIN                    PD12

#define LED0_PIN                        PA5  // Onboard (green) LED

#define SPI2_NSS_PIN                    PB12
#define SPI2_SCK_PIN                    PB13
#define SPI2_SDI_PIN                    PB14
#define SPI2_SDO_PIN                    PB15

#define GYRO_1_SPI_INSTANCE             SPI2
#define GYRO_1_CS_PIN                   PB12
//#define GYRO_1_EXTI_PIN                 PC13

#define UART1_TX_PIN                    PA9
#define UART1_RX_PIN                    PA10

#define UART2_TX_PIN                    PA2
#define UART2_RX_PIN                    PA3

// #define USE_UART3
#define UART3_TX_PIN                    PB10
#define UART3_RX_PIN                    PB11

#define ESCSERIAL_TIMER_TX_PIN          PB8  // (HARDARE=0,PPM)

#define I2C2_SCL                        NONE // PB10, shared with UART3TX
#define I2C2_SDA                        NONE // PB11, shared with UART3RX

#define I2C3_SCL                        NONE // PA8
#define I2C3_SDA                        NONE // PC9

#define VBAT_ADC_PIN                    PC0
#define CURRENT_METER_ADC_PIN           PC1
#define RSSI_ADC_PIN                    PC2
#define EXTERNAL1_ADC_PIN               PC3

#define SONAR_TRIGGER_PIN               PB0
#define SONAR_ECHO_PIN                  PB1

#define RX_SPI_INSTANCE                 SPI1
// Nordic Semiconductor uses 'CSN', STM uses 'NSS'
#define RX_CE_PIN                       PC7 // D9
#define RX_NSS_PIN                      PB6 // D10
// NUCLEO has NSS on PB6, rather than the standard PA4

#define SPI1_NSS_PIN                    RX_NSS_PIN
#define SPI1_SCK_PIN                    PA5 // D13
#define SPI1_SDI_PIN                    PA6 // D12
#define SPI1_SDO_PIN                    PA7 // D11

//#define MAX7456_SPI_INSTANCE    SPI2
//#define MAX7456_SPI_CS_PIN      SPI2_NSS_PIN

//#define SDCARD_SPI_INSTANCE     SPI2
//#define SDCARD_SPI_CS_PIN       PB12

//// Note, this is the same DMA channel as UART1_RX. Luckily we don't use DMA for USART Rx.
//#define SDCARD_DMA_CHANNEL_TX               DMA1_Channel5
// Performance logging for SD card operations:
// #define AFATFS_USE_INTROSPECTIVE_LOGGING


#define USE_ADC
#define ADC_INSTANCE                    ADC1
#define ADC1_DMA_OPT                    1  // DMA 2 Stream 4 Channel 0 (compat default)

//#define ADC_INSTANCE                  ADC2
//#define ADC2_DMA_OPT                  1  // DMA 2 Stream 3 Channel 1 (compat default)

#define RX_SPI_DEFAULT_PROTOCOL         RX_SPI_NRF24_H8_3D
#define I2C_DEVICE                      (I2CDEV_2)

#define MAX_SUPPORTED_MOTORS            12

//#define USE_GYRO_EXTI
//#define USE_MPU_DATA_READY_SIGNAL
//#define ENSURE_MPU_DATA_READY_IS_LOW
