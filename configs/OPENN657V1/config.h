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

// Open-hardware STM32N657 flight controller, v1.0 layout. Ported from
// the upstream fork's monolithic target.h into the per-config layout
// expected by current Betaflight master.
//
// Real sensors only — the SPI/I2C bring-up for N6 is being completed
// in a parallel session, so this config commits to the actual ICM-42688P
// IMU on SPI1. The BMP280 baro is wired on I2C but the bus/pin
// assignment was never finalised in the source we received, so it stays
// behind a TODO until that's confirmed.

#define FC_TARGET_MCU                   STM32N657

#define BOARD_NAME                      OPENN657V1
#define MANUFACTURER_ID                 CUST

// 48 MHz HSE crystal — matches the fork's target.mk and the N6570-DK
// reference clock tree the platform expects.
#define SYSTEM_HSE_MHZ                  48

// N6 has no internal user flash; the runtime config has to live in RAM
// (or external flash, once the XSPI self-flasher path is exercised on
// this board). Stay in RAM for bring-up.
#define CONFIG_IN_RAM

// --- USB VCP -------------------------------------------------------------
// Opted in per-board because the boot ROM hands USB power-rail state off
// non-deterministically and each board does its own MspInit sequencing.
#define USE_VCP

// --- LEDs ----------------------------------------------------------------
#define LED0_PIN                        PD15
#define LED1_PIN                        PG10

// --- Serial --------------------------------------------------------------
// UART3: bidirectional debug / MSP
#define UART3_TX_PIN                    PE8
#define UART3_RX_PIN                    PE0

// UART4: SBUS RX (RX-only on the fork target)
#define UART4_RX_PIN                    PD0
#define SERIALRX_UART                   SERIAL_PORT_UART4
#define USE_SERIALRX
#define USE_SERIALRX_SBUS
#define SERIALRX_PROVIDER               SERIALRX_SBUS

// UART5/6: free RX-capable pads exposed on the board
#define UART5_RX_PIN                    PH2
#define UART6_RX_PIN                    PC9

// --- IMU: ICM-42688P on SPI1 --------------------------------------------
#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define SPI1_SCK_PIN                    PB9
#define SPI1_SDI_PIN                    PB8
#define SPI1_SDO_PIN                    PA7

#define ICM42688P_SPI_INSTANCE          SPI1
#define ICM42688P_CS_PIN                PE2
#define ICM42688P_EXTI_PIN              PA3
#define ICM42688P_ALIGN                 CW180_DEG

#define GYRO_1_SPI_INSTANCE             ICM42688P_SPI_INSTANCE
#define GYRO_1_CS_PIN                   ICM42688P_CS_PIN
#define GYRO_1_EXTI_PIN                 ICM42688P_EXTI_PIN
#define GYRO_1_ALIGN                    ICM42688P_ALIGN

// --- Baro ----------------------------------------------------------------
// TODO BMP280 I2C wiring — bus + SCL/SDA pins not finalised in the fork
// target.h we received. Confirm against the v1.0 schematic and uncomment
// (matching I2Cx_SCL_PIN/I2Cx_SDA_PIN against the chosen instance).
//
// #define USE_BARO
// #define USE_BARO_BMP280
// #define BARO_I2C_INSTANCE             I2CDEV_?
// #define I2C?_SCL_PIN                  P??
// #define I2C?_SDA_PIN                  P??

// --- Motors --------------------------------------------------------------
// TODO MOTOR3/MOTOR4 wiring — PD2 and PC12 are inherited from the fork's
// target.h but neither pin has a TIM1_CH3/CH4 alternate function on the
// STM32N657 (per src/platform/STM32/timer_stm32n6xx.c, TIM1_CH3 is on
// PA10/PE13 and TIM1_CH4 on PA11/PE14). M3/M4 will not PWM out as
// configured — confirm against the v1.0 schematic and reassign before
// flying.
#define MOTOR1_PIN                      PE9     // TIM1_CH1
#define MOTOR2_PIN                      PE11    // TIM1_CH2
#define MOTOR3_PIN                      PD2     // TIM1_CH3 (TODO: invalid AF, see above)
#define MOTOR4_PIN                      PC12    // TIM1_CH4 (TODO: invalid AF, see above)

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN, 1, 0) \
    TIMER_PIN_MAP(1, MOTOR2_PIN, 1, 1) \
    TIMER_PIN_MAP(2, MOTOR3_PIN, 1, 2) \
    TIMER_PIN_MAP(3, MOTOR4_PIN, 1, 3)
