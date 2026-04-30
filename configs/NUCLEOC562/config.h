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

// NUCLEO-C562RE development bring-up config.
//
// Goal: exercise the STM32C562 platform path on the STMicro NUCLEO-64 board.
// No flight hardware is wired -- the IMU/baro/mag stack runs against the
// virtual drivers under src/main/drivers/{accgyro,compass,barometer}/*_virtual.c.
// CLI/MSP runs over the MCU's on-chip USB DRD FS (PA11/PA12). USART2 on
// PA2/PA3 is kept as a backup serial console wired to the on-board ST-LINK.
//
// Motor map: TIM1 CH1/CH2 on PA8/PA9 for MOTOR1/MOTOR2, TIM2 CH3/CH4 on
// PB10/PB11 for MOTOR3/MOTOR4. PA10 is reserved for the DSK320X EXTI
// data-ready line; PA11/PA12 are the USB DRD FS pins. The STM32C562 die
// lacks TIM3 and TIM4 so a contiguous single-timer motor group isn't
// available without rewiring the sensor.

#define FC_TARGET_MCU                   STM32C562

#define BOARD_NAME                      NUCLEOC562
#define MANUFACTURER_ID                 STMI

// Keep the runtime config in RAM during platform bring-up to sidestep the
// flash-partition path (see notes on STM32N657DK bring-up).
#define CONFIG_IN_RAM

// --- Sensors ------------------------------------------------------------
// LSM6DSK320X gyro/accel on SPI1 (CS PC9, MOSI PA7, MISO PA6, SCK PA5),
// data-ready/EXTI line on PA10. Mag stays virtual (none wired).
#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_LSM6DSK320X
#define USE_GYRO_EXTI

#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN                    PA5
#define SPI1_SDI_PIN                    PA6
#define SPI1_SDO_PIN                    PA7

#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_CS_PIN                   PC9
#define GYRO_1_EXTI_PIN                 PA10

#define USE_MAG
#define USE_VIRTUAL_MAG

// --- ST-LINK Virtual COM port -------------------------------------------
// USART2 PA2 (TX) / PA3 (RX), AF7 -- wired to the on-board ST-LINK MCU.
// Kept as a backup serial console; MSP defaults to the USB VCP.
#define UART2_TX_PIN                    PA2
#define UART2_RX_PIN                    PA3

// --- Motor outputs ------------------------------------------------------
// MOTOR1/MOTOR2 on TIM1 CH1/CH2 (PA8/PA9). MOTOR3/MOTOR4 on TIM2 CH3/CH4
// (PB10/PB11). PA10 is the DSK320X EXTI line; PA11/PA12 are USB DM/DP.
#define MOTOR1_PIN                      PA8
#define MOTOR2_PIN                      PA9
#define MOTOR3_PIN                      PB10
#define MOTOR4_PIN                      PB11

// --- Status LED ---------------------------------------------------------
// LD2 (User LED) on PA5, also exposed as Arduino D13.
#define LED0_PIN                        PA5
