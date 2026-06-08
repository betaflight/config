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

// ARCROBO_C562V1 -- Arcrobo hand-built FC, STM32C562RET6 in LQFP64.
// Schematic: ~/src/ref/C562/STM32C562_SCH_V1.0-20260409.pdf

#define FC_TARGET_MCU                   STM32C562

#define BOARD_NAME                      ARCROBO_C562V1
#define MANUFACTURER_ID                 ACRO

// HSE 8 MHz crystal on PH0/PH1 (Y1)
#define SYSTEM_HSE_MHZ                  8

// Config in W25Q128 on SPI1.
#define CONFIG_IN_EXTERNAL_FLASH

// --- USB VCP -------------------------------------------------------------
#define USE_VCP
#define USB_DETECT_PIN                  PC0
#define USE_USB_DETECT

// --- Status LED ----------------------------------------------------------
#define LED0_PIN                        PE2

// --- UART pin map --------------------------------------------------------
#define UART1_TX_PIN                    PA9
#define UART1_RX_PIN                    PA10
#define UART2_TX_PIN                    PA2
#define UART2_RX_PIN                    PA3
#define UART3_TX_PIN                    PB10
#define UART3_RX_PIN                    PC4
#define UART4_TX_PIN                    PA0
#define UART4_RX_PIN                    PA1
#define UART5_TX_PIN                    PC12
#define UART5_RX_PIN                    PD2

// --- IMU: ICM-42688P on SPI3 ---------------------------------------------
// SPI3 SCK=PB9, MISO=PB6, MOSI=PB5 (AF7 -- C5 quirk patched in #15284),
// CS=PB8, INT/DRDY=PB7.
#define USE_ACC
#define USE_GYRO
#define USE_GYRO_EXTI

#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN                    PB9
#define SPI3_SDI_PIN                    PB6
#define SPI3_SDO_PIN                    PB5

// The IMU populated on this board is an LSM6 family part (WHO_AM_I=0x75 at
// reg 0x0F), matched by BF's LSM6DSK320X driver. Schematic markings refer to
// it as ICM-42688P but the silicon is LSM6 -- different register map, so the
// LSM6 driver path is what actually drives it.
#define USE_ACCGYRO_LSM6DSK320X

#define GYRO_1_SPI_INSTANCE             SPI3
#define GYRO_1_CS_PIN                   PB8
#define GYRO_1_EXTI_PIN                 PB7
#define GYRO_1_ALIGN                    CW0_DEG

// SPA06-003 baro over I3C1 (PC10=SCL/PC11=SDA, AF4). First-cut probe; the
// real driver is still to land. Probe reads CHIP_ID and parks the result for
// SWD inspection.
#define ENABLE_BARO_SPA06_PROBE         1

// --- External flash: W25Q128JV on SPI1 -----------------------------------
// AF5 standard for SPI1 on STM32C5.
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN                    PA5
#define SPI1_SDI_PIN                    PA6
#define SPI1_SDO_PIN                    PA7

#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define FLASH_SPI_INSTANCE              SPI1
#define FLASH_CS_PIN                    PA4

#define USE_FLASHFS
#define USE_BLACKBOX

// --- OSD: AT7456E on SPI2 ------------------------------------------------
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN                    PB13
#define SPI2_SDI_PIN                    PB14
#define SPI2_SDO_PIN                    PB15

#define USE_MAX7456
#define MAX7456_SPI_INSTANCE            SPI2
#define MAX7456_SPI_CS_PIN              PB12

#define USE_OSD
// AT7456E is SD-only OSD; declare USE_OSD_SD so common_pre.h does
// not auto-define USE_OSD_HD and short-circuit init.c to the MSP OSD
// path (same trap as OPENC5A3V1).
#define USE_OSD_SD

// --- Baro: virtual ------------------------------------------------------
// Schematic labels PC10/PC11 as I2C3 SCL/SDA, but C562 has no I2C3
// peripheral -- PC10/PC11 are I3C1 alternates and BF has no
// I3C-as-I2C driver yet. Stay on virtual baro for first light.
#define USE_BARO
#define USE_VIRTUAL_BARO

// --- Mag still synthetic -------------------------------------------------
#define USE_MAG
#define USE_VIRTUAL_MAG

// --- Motors: DShot bitbang on TIM8 ---------------------------------------
// M1 PC6 / M2 PC7 / M3 PC8 / M4 PC9.
#define MOTOR1_PIN                      PC6
#define MOTOR2_PIN                      PC7
#define MOTOR3_PIN                      PC8
#define MOTOR4_PIN                      PC9

// --- LED strip on PA8 (TIM1_CH1) -----------------------------------------
#define USE_LED_STRIP
#define LED_STRIP_PIN                   PA8

// PC6-PC9 motors on TIM8: C562 omits TIM3 from the C5 timer table, so the only
// occurrence of these pins is TIM8 (index 1). C591/C5A3 has both TIM3 and TIM8
// in the table -- those configs need index 2 for TIM8.
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, PC6, 1, -1) \
    TIMER_PIN_MAP(1, PC7, 1, -1) \
    TIMER_PIN_MAP(2, PC8, 1, -1) \
    TIMER_PIN_MAP(3, PC9, 1, -1) \
    TIMER_PIN_MAP(4, PA8, 1, -1)

#define DEFAULT_PID_PROCESS_DENOM       2

// --- ADC: VBAT + current + RSSI ------------------------------------------
#define ADC_VBAT_PIN                    PC1
#define ADC_CURR_PIN                    PC2
#define ADC_RSSI_PIN                    PC3
#define ADC1_INSTANCE                   ADC1

// --- Buzzer --------------------------------------------------------------
// Passive buzzer driven by PC5 via Q1 MOSFET (inverted).
#define USE_BEEPER
#define BEEPER_PIN                      PC5
#define BEEPER_INVERTED
