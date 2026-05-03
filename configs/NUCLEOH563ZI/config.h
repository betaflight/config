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

// NUCLEO-H563ZI development bring-up config.
//
// First-stage goal is to verify the STM32H5 platform path on the STMicro
// NUCLEO-144 development board: CLI/MSP over USB FS (PA11/PA12) and a
// backup serial console on USART3 (PD8/PD9) routed to the on-board
// STLINK-V3EC virtual COM port. The three on-board user LEDs (LD1/LD2/LD3)
// are mapped to LED0..LED2. PLL/HSE bring-up to the H5's 250 MHz peak is
// deferred; the platform stays on HSI 64 MHz for the first bring-up so the
// initial flash / link can be validated independently of the X3 crystal.
//
// Reference: UM3115 "Getting started with STM32H5 Nucleo-144 boards"
// (NUCLEO-H563ZI/NUCLEO-H553ZI), revision 4, April 2024.

#define FC_TARGET_MCU                   STM32H563

#define BOARD_NAME                      NUCLEOH563ZI
#define MANUFACTURER_ID                 STMI

// HSE: 25 MHz X3 crystal (NUCLEO-H563ZI default fit). Feeds PLL1 (M=5,
// N=100, P=2) for SYSCLK = 250 MHz. The platform falls back to HSI at
// 64 MHz if the crystal does not lock. HSE_VALUE flows through this
// define into the HAL clock math; without it, HAL_RCC_GetSysClockFreq()
// would compute the SYSCLK from the Makefile default of 8 MHz and
// every derived rate (SysTick, baud, timer kernel) would be off by
// 25/8.
#define SYSTEM_HSE_MHZ                  25

// Keep the runtime config in RAM during platform bring-up to sidestep the
// flash-partition path while the H5 storage backend is still being shaken
// out. Drop this once flash config storage has been verified end-to-end
// on real hardware.
#define CONFIG_IN_RAM

// --- ST-LINK Virtual COM port -------------------------------------------
// USART3: MCU PD8 (TX) / PD9 (RX), AF7. Wired through the STLINK-V3EC to
// the host as a CDC ACM virtual COM port. Acts as a backup serial console
// while the on-chip USB FS bring-up settles.
#define USE_UART3
#define UART3_TX_PIN                    PD8
#define UART3_RX_PIN                    PD9

// --- USB FS (CN13 "USB user") -------------------------------------------
// On-chip USB FS PHY on PA11/PA12. Default CLI/MSP transport.
#define USE_VCP

// --- User LEDs ----------------------------------------------------------
// LD1 (green)  PB0 -- default Solder Bridge config (SB43 ON, SB51 OFF).
// LD2 (yellow) PF4.
// LD3 (red)    PG4.
// All three are active-high.
#define LED0_PIN                        PB0
#define LED1_PIN                        PF4
#define LED2_PIN                        PG4

// --- Future sensor headers (placeholder pinouts) ------------------------
// SPI1 on the Arduino-style ST Zio header: SCK PA5 / MISO PA6 / MOSI PA7
// (matches the NUCLEO-C562RE wiring so a daughterboard built for one can
// be reused on the other).
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN                    PA5
#define SPI1_SDI_PIN                    PA6
#define SPI1_SDO_PIN                    PA7

// I2C1 on the ST Zio header: PB8 (SCL) / PB9 (SDA).
// USE_I2C_GYRO compiles in the I2C reset/probe paths in pg/gyrodev.c and
// drivers/accgyro/accgyro_mpu.c (otherwise busType stays BUS_TYPE_NONE
// and mpuDetect short-circuits before any I2C transaction). I2C_DEVICE
// picks the bus the gyro PG defaults to; without it gyroResetI2cDeviceConfig
// points at I2CINVALID. MPU6050 module on PB8/PB9 (its on-board pull-ups
// hold the bus high — NUCLEO has none).
#define USE_I2C_DEVICE_1
#define I2C1_SCL_PIN                    PB8
#define I2C1_SDA_PIN                    PB9
#define I2C_DEVICE                      I2CDEV_1
#define USE_I2C_GYRO

// --- Sensors -----------------------------------------------------------
// USE_CONFIG (auto-set for per-board builds) suppresses common_pre.h's
// catch-all USE_GYRO_*/USE_ACC_* block, so the per-board config has to
// enumerate the drivers it wants. We only have an MPU6050 on the bench;
// pull in just its driver plus the master USE_GYRO/USE_ACC flags.
#define USE_GYRO
#define USE_ACC
#define USE_GYRO_MPU6050
#define USE_ACC_MPU6050

// --- ADC ----------------------------------------------------------------
// ADC1 and ADC2 are both routed to internal channels (VREFINT/TEMPSENSOR
// on ADC1, VBAT/4 on ADC2) so adc_internal can compute the actual mcu
// supply rail and core temperature without external wiring. The H5 driver
// requires a valid dmaopt for each ADC even when only internal channels
// are used. Park the two on GPDMA2 so any future DSHOT bitbang / SPI work
// has GPDMA1 free.
//   opt 0..7  = GPDMA1 CH0..CH7
//   opt 8..15 = GPDMA2 CH0..CH7
#define ADC1_DMA_OPT                    8
#define ADC2_DMA_OPT                    9

// --- Motor outputs (4 motors on TIM1) -----------------------------------
// All four PWM/DShot channels share TIM1 (advanced motor-control timer):
//   M1 PE9  -> TIM1_CH1   (CN10-9)
//   M2 PE11 -> TIM1_CH2   (CN10-11)
//   M3 PE13 -> TIM1_CH3   (CN10-13)
//   M4 PE14 -> TIM1_CH4   (CN10-15)
// All on PORTE so a bitbang DShot write reaches every motor with one BSRR
// access; all on TIM1 so regular DShot only needs one timer instance.
#define MOTOR1_PIN                      PE9
#define MOTOR2_PIN                      PE11
#define MOTOR3_PIN                      PE13
#define MOTOR4_PIN                      PE14

// timerIOConfig is empty by default; without these entries
// timerGetConfiguredByTag returns NULL for the motor pins and DSHOT
// bitbang init bails with MOTOR_PIN_CONFLICT (status:
// "Arming disable flags: ... DSHOT_BBANG"). Each pin appears only once
// in the H5 timer table (all on TIM1), so the occurrence index is
// always 1; dmaopt is -1 because bitbang uses per-port GPDMA, not
// per-pin.
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PE9 , 1, -1) \
    TIMER_PIN_MAP( 1, PE11, 1, -1) \
    TIMER_PIN_MAP( 2, PE13, 1, -1) \
    TIMER_PIN_MAP( 3, PE14, 1, -1)
