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

// STM32N6570-DK + LSM6DSK320X (DSK320K) module bring-up config.
//
// Companion target: src/platform/STM32/target/STM32N657. The DSK320K module
// is wired with the same pinout used on the NUCLEO-C562RE bring-up:
//   SPI1   SCK PA5  / SDI PA6 / SDO PA7,  CS PC9,  DRDY/EXTI PA10
//   I2C1   SCL PB6  / SDA PB7
// Sensor stack on those buses: LSM6DSK320X gyro/accel (SPI1), LIS2MDL mag
// + LPS22DF baro (I2C1).
//
// The on-board ST-LINK-V3 brings out USART1 PE5/PE6 for a backup serial
// console. The MCU's own USB1 OTG_HS in FS mode (PA11/PA12) is exposed on
// the user USB connector — used for the CLI/MSP VCP.
//
// USER LEDs available on the N6570-DK:
//   LD1 green  PO1
//   LD2 red    PG10
//
// SDCARD: SDMMCx instance + pins inherit defaults from the platform target.

#define FC_TARGET_MCU                   STM32N657

#define BOARD_NAME                      STM32N657DK_DSK320
#define MANUFACTURER_ID                 STMI

// HSE: drive SYSCLK/PLL1 from the on-board 48 MHz HSE. SystemClock_Config
// in the platform translates SYSTEM_HSE_MHZ into the PLL1 N divider so the
// VCO lands at the canonical 1200 MHz with CPU = 600 MHz via IC1.
#define SYSTEM_HSE_MHZ                  48

// Keep config in RAM during platform exploration so we sidestep the flash
// partition path while bringing the board up. Switch to
// CONFIG_IN_MEMORY_MAPPED_FLASH once the XSPI flash storage path is proven.
#define CONFIG_IN_RAM

// --- Sensors ------------------------------------------------------------
// REAL SENSOR WIRING (DSK320K module, currently disabled):
//   SPI1 SCK PA5 / SDI PA6 / SDO PA7,  LSM6DSK320X CS PC9 / DRDY PA10
//   I2C1 SCL PB6 / SDA PB7,  LIS2MDL mag + LPS22DF baro
//
// Real sensors disabled until SPI1 + I2C1 kernel clocks + AF mappings are
// validated (sensorsAutodetect hangs trying to read WHOAMI). Use the
// existing virtual-sensor stack so the scheduler / task system can run
// and we can debug everything else first.
#define USE_ACC
#define USE_VIRTUAL_ACC
#define USE_GYRO
#define USE_VIRTUAL_GYRO
#define USE_BARO
#define USE_VIRTUAL_BARO
#define USE_MAG
#define USE_VIRTUAL_MAG

// Real-sensor pins kept here as comments for the next iteration:
// #define USE_ACCGYRO_LSM6DSK320X
// #define USE_GYRO_EXTI
// #define USE_SPI_DEVICE_1
// #define SPI1_SCK_PIN                    PA5
// #define SPI1_SDI_PIN                    PA6
// #define SPI1_SDO_PIN                    PA7
// #define GYRO_1_SPI_INSTANCE             SPI1
// #define GYRO_1_CS_PIN                   PC9
// #define GYRO_1_EXTI_PIN                 PA10
// #define USE_MAG_LIS2MDL
// #define USE_BARO_LPS22DF
// #define USE_I2C_DEVICE_1
// #define I2C1_SCL_PIN                    PB6
// #define I2C1_SDA_PIN                    PB7
// #define MAG_I2C_INSTANCE                I2CDEV_1
// #define BARO_I2C_INSTANCE               I2CDEV_1
// #define MAG_ALIGN                       CW0_DEG
// #define GYRO_1_ALIGN                    CW180_DEG

// --- ST-LINK V3 backup serial console -----------------------------------
// The N6570-DK routes USART1 PE5/PE6 to the on-board ST-LINK-V3 VCOM.
// USART1 kernel clock is sourced from HSI (64 MHz) via SystemClock_Config
// so baud-rate generation is independent of the bus-clock tree.
//
// MSP_UART pins MSP onto USART1 by default so the ST-LINK VCOM serves as
// a backup path to the CLI: connect at 115200 8N1, send "#<lf>" to drop
// out of MSP and into the CLI prompt.
#define USE_UART1
#define UART1_TX_PIN                    PE5
#define UART1_RX_PIN                    PE6
#define MSP_UART                        SERIAL_PORT_USART1

// --- USB VCP ------------------------------------------------------------
// USB1 OTG_HS in FS mode (PA11 D-/PA12 D+) routed to the user USB-C
// connector. SystemClock_Config feeds the USB1 PHY from HSE/2 (24 MHz),
// and HAL_PCD_MspInit (in usbd_conf_stm32n6xx.c) primes VddUSBVMEN +
// USB33RDY before the core leaves reset.
#define USE_VCP

// --- Status LED ---------------------------------------------------------
// LD2 (red) on PG10 — usable as status LED for bring-up. The on-board green
// LD1 sits on PO1 which the IO subsystem doesn't reach yet (io_def_generated.h
// only covers ports A..I, see follow-up task to extend coverage to J..Q for
// the wider N6 GPIO set including LCD lines).
#define LED0_PIN                        PG10

// --- SDCARD (on-board microSD slot) ------------------------------------
// SDMMC2 routed to all six lines via the on-board card cage. Pin map per
// CubeN6 STM32N6570-DK SD/SD_ReadWrite_DMA example (all AF11):
//   CK  PC2   CMD PC3
//   D0  PC4   D1  PC5   D2 PC0   D3 PE4
//
// TEMPORARILY DISABLED — SDMMC2 kernel clock is now configured but
// SD_DoInit still spin-loops polling the peripheral status register
// (offset 0x34). SDMMC2 peripheral may need additional setup (CKIN
// gating, init timing) beyond just kernel clock select. Re-enable
// after SD init path is fully validated. Pin defs kept for reference:
// #define USE_SDCARD
// #define SDIO_DEVICE                     SDIODEV_2
// #define SDIO_USE_4BIT                   true
// #define SDIO_CK_PIN                     PC2
// #define SDIO_CMD_PIN                    PC3
// #define SDIO_D0_PIN                     PC4
// #define SDIO_D1_PIN                     PC5
// #define SDIO_D2_PIN                     PC0
// #define SDIO_D3_PIN                     PE4

// --- Motors -------------------------------------------------------------
// MOTOR1..4 placeholder. The N6570-DK exposes its Arduino-style headers
// (Zio + Arduino Uno V3) — pick four pins with a timer output channel and
// no conflict with the SPI1 / I2C1 / USB / LED / SDMMC assignments above.
// Filled in once the BSP pin survey lands.
//
// #define MOTOR1_PIN                   ...
// #define MOTOR2_PIN                   ...
// #define MOTOR3_PIN                   ...
// #define MOTOR4_PIN                   ...
//
// TIMER_PIN_MAPPING entries are required alongside the pin defines so
// fullTimerHardware resolves a timer/channel for each motor pin during
// DSHOT bitbang init.

// --- LCD console ---------------------------------------------------------
// Inherit the lcd_console framework with the in-RAM stub backend. The
// stub backend mirrors writes into a static char grid that can be
// dumped via OpenOCD or the `lcd` CLI command — no real panel hardware
// required, so we get a debug log of boot/trace output for free.
#define ENABLE_LCD_CONSOLE              1
#define LCD_CONSOLE_PANEL_STUB
#define LCD_CONSOLE_COLS                80
#define LCD_CONSOLE_ROWS                30
#define ENABLE_LCD_PRINTF_REDIRECT      1

// 4 kHz PID loop at the default 8 kHz gyro rate.
#define DEFAULT_PID_PROCESS_DENOM       2
