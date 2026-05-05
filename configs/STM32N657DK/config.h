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

// STM32N6570-DK development bring-up config.
//
// Goal: exercise the STM32N657 platform path with synthetic sensors and the
// on-board LCD acting as a runtime debug console for boot/trace output. No
// real flight hardware is wired — the IMU/baro/mag/GPS stack runs against
// the existing virtual drivers under src/main/drivers/{accgyro,compass,
// barometer}/*_virtual.c.
//
// The LCD path uses the in-RAM stub backend (LCD_CONSOLE_PANEL_STUB):
// writes land in a debug grid that the `lcd` CLI (and OpenOCD
// `mdw stubGrid`) can dump. The bare DK has no panel attached — the
// real LTDC panel backend (lcd_ltdc_n6.c) is exercised by the
// STM32N657DK_DSK320 config when paired with the DSK320K daughter board.

#define FC_TARGET_MCU                   STM32N657

#define BOARD_NAME                      STM32N657DK
#define MANUFACTURER_ID                 STMI

// STM32N6570-DK ships with a 48 MHz HSE clock source.
#define SYSTEM_HSE_MHZ                  48

// Keep the runtime config in RAM for the bring-up — no need for persistent
// storage during platform exploration, and it sidesteps the flash-partition
// path which currently expects USE_FLASHFS to ride alongside
// CONFIG_IN_MEMORY_MAPPED_FLASH (a pre-existing latent issue in flash.c that
// only surfaces in USE_CONFIG mode where common_pre.h defaults are skipped).
#define CONFIG_IN_RAM

// --- Synthetic sensors ---------------------------------------------------
// No real sensors are wired; rely on the virtual drivers so the flight code
// has something coherent to talk to during the platform bring-up.
#define USE_ACC
#define USE_VIRTUAL_ACC
#define USE_GYRO
#define USE_VIRTUAL_GYRO
#define USE_BARO
#define USE_VIRTUAL_BARO
#define USE_MAG
#define USE_VIRTUAL_MAG

// --- USB VCP -------------------------------------------------------------
// USB1 OTG_HS in FS mode on the user USB-C connector (PA11/PA12 internally
// routed via the integrated PHY). USE_VCP is opted in per board because
// the boot ROM hands off USB power-rail state non-deterministically and
// each board does its own MspInit sequencing.
#define USE_VCP

// USE_ADC requires SystemClock_Config to set up the ADC kernel clock
// (PERIPHCLK_ADC). The legacy STM32N657DK config didn't enable ADC, so
// keep parity here until ADC clock setup lands per-board.

// --- LCD console ---------------------------------------------------------
// Inherit the lcd_console framework with the in-RAM stub backend so
// printf/trace output is captured into a debug grid that the `lcd` CLI
// (and OpenOCD `mdw stubGrid`) can dump. A real LTDC panel backend is a
// follow-up — until that lands, the CLI keeps its existing USB-VCP path
// and the LCD path is purely a memory-resident scratchpad.
#define ENABLE_LCD_CONSOLE              1
#define LCD_CONSOLE_PANEL_STUB
#define LCD_CONSOLE_COLS                80
#define LCD_CONSOLE_ROWS                30
#define ENABLE_LCD_PRINTF_REDIRECT      1
