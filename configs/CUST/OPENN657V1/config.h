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
  VERSION: 2026.6.0
*/
#pragma once

#define FC_TARGET_MCU                   STM32N657
#define BOARD_NAME                      OPENN657V1
#define MANUFACTURER_ID                 CUST

#define SYSTEM_HSE_MHZ                  48

// CLI `save` writes config into the boot flash chip (mx66uw1g45g) at the
// top of XSPI2 via the meta-flash driver. The OCTOSPI_FLASH_CHIP setting
// in config.mk pairs with this — without it the build-time chip dispatch
// in flash.c can't select the chip and detection falls back to JEDEC
// probing (which the bootloader-configured MX66 doesn't honour cleanly).

// --- USB VCP -------------------------------------------------------------
#define USE_VCP

// --- LED -----------------------------------------------------------------
#define LED0_PIN                        PD15

// --- IMU: ICM-42688P on SPI1 --------------------------------------------
// SCK=PB9, SDI=PB8, SDO=PA7, CS=PE2, INT=PA3 (CW180_DEG mounting).
// All three SPI signals on AF5 (N6 SPI1 mapping; see
// src/platform/common/stm32/bus_spi_pinconfig.c STM32N6 block).
#define USE_ACC
#define USE_GYRO
#define USE_SPI_DEVICE_1
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

#define DEFAULT_PID_PROCESS_DENOM       2

// --- Baro: BMP280 on I2C1 ------------------------------------------------
// SCL=PH9, SDA=PC1 (AF4). Default I2C address 0x76 (SDO tied low).
// (USE_I2C is provided by the N657 target.h.)
#define USE_I2C_DEVICE_1
#define I2C1_SCL_PIN                    PH9
#define I2C1_SDA_PIN                    PC1

#define USE_BARO
#define USE_BARO_BMP280
#define BARO_I2C_INSTANCE               I2CDEV_1

// --- Motors --------------------------------------------------------------
// All four motors are on TIM1 channels (AF1). DShot via GPDMA1 burst-DMA
// to TIM1->DMAR; one GPDMA1 channel covers all four channels.
// Pin map matches STM32N6-FC-Pinout V3.0 (TIM1_CH1..CH4 columns).
#define MOTOR1_PIN                      PE9   /* TIM1_CH1 */
#define MOTOR2_PIN                      PE11  /* TIM1_CH2 */
#define MOTOR3_PIN                      PD2   /* TIM1_CH3 */
#define MOTOR4_PIN                      PC12  /* TIM1_CH4 */

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN, 1, 0) /* PE9  / TIM1_CH1 / GPDMA1_Channel0 */ \
    TIMER_PIN_MAP(1, MOTOR2_PIN, 1, 1) /* PE11 / TIM1_CH2 / GPDMA1_Channel1 */ \
    TIMER_PIN_MAP(2, MOTOR3_PIN, 1, 2) /* PD2  / TIM1_CH3 / GPDMA1_Channel2 */ \
    TIMER_PIN_MAP(3, MOTOR4_PIN, 1, 3) /* PC12 / TIM1_CH4 / GPDMA1_Channel3 */

#define TIMUP1_DMA_OPT                  4   /* GPDMA1_Channel4 — burst DMA */

// N6 GPDMA bitbang (TIM8-paced, BSRR-direct writes) is the working path —
// mirrors the reference implementation. Timer-DMA is still selectable via
// `set dshot_bitbang = OFF` but lacks the broken-OC-output workaround.
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON

// Default to per-channel DMA on N6: one GPDMA1 channel per motor writes
// directly to its own CCRx. Simpler path than TIM_DMAR burst (no
// auto-routing, no DBL bookkeeping) and the one validated during
// bring-up. DSHOT_DMAR_ON also works on the N6 GPDMA fix path.
#define DEFAULT_DSHOT_BURST             DSHOT_DMAR_OFF

// Bring-up trace UART (drivers/debug_uart.h). UART7 TX on PE8 (AF8),
// connected to the bench USB-serial adapter on /dev/ttyUSB0. Compiles
// out cleanly when ENABLE_DEBUG_UART is 0.
#define ENABLE_DEBUG_UART               1
#define DEBUG_UART                      UART7
#define DEBUG_UART_GPIO                 GPIOE
#define DEBUG_UART_PIN                  8
#define DEBUG_UART_AF                   8

// Enable CLI dxr / dxw for SPI1 bring-up register dump.
#define ENABLE_DEBUG_CLI_COMMANDS       1

// Don't write fresh defaults to MM-flash on first-boot EEPROM recovery.
// The save path stalls the scheduler for ~7 s mid-initPhase1.
#define ENABLE_RESET_CONFIG             1
