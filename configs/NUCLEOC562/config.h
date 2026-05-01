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
#define USE_MAG_LIS2MDL

#define USE_BARO
#define USE_BARO_LPS22DF

// I2C1 on PB6/PB7 for LIS2MDL mag and LPS22DF baro.
#define USE_I2C_DEVICE_1
#define I2C1_SCL_PIN                    PB6
#define I2C1_SDA_PIN                    PB7

#define MAG_I2C_INSTANCE                I2CDEV_1
#define BARO_I2C_INSTANCE               I2CDEV_1

#define MAG_ALIGN                       CW0_DEG
#define GYRO_1_ALIGN                    CW180_DEG

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

// timerIOConfig is empty by default; without TIMER_PIN_MAPPING entries
// the motor pins find no timer and DSHOT bitbang init bails with
// MOTOR_PIN_CONFLICT, so the motor stack reports zero motors over MSP.
// Each pin only has one entry in fullTimerHardware on this die so the
// occurrence index is always 1; dmaopt is -1 (bitbang is per-port DMA).
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA8 , 1, -1) \
    TIMER_PIN_MAP( 1, PA9 , 1, -1) \
    TIMER_PIN_MAP( 2, PB10, 1, -1) \
    TIMER_PIN_MAP( 3, PB11, 1, -1)

// 4 kHz PID loop at the default 8 kHz gyro rate (denom = gyro / pid).
// Keeps headroom for the C562 / 144 MHz core during bring-up; can be
// raised once the platform settles.
#define DEFAULT_PID_PROCESS_DENOM 2

// ADC1 routes via LPDMA2 CH0 on the C5. The dmaChannelSpec opts 0-7
// are LPDMA1 CH0-7 (used by DSHOT bitbang pacers and SPI), so pick
// opt 8 (LPDMA2 CH0) which is free for the ADC. Default of
// DMA_OPT_UNUSED in common_defaults_post.h would make adcInit() skip
// DMA setup entirely (status: Vref=0.00V, Core temp=-282degC).
#define ADC1_DMA_OPT 8

// --- Status LED ---------------------------------------------------------
// LD2 (User LED) on PA5, also exposed as Arduino D13.
#define LED0_PIN                        PA5
