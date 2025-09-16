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

#define FC_TARGET_MCU     RP2350A
#define BOARD_NAME        PICO2_2350A
#define MANUFACTURER_ID   RASP

#define LED0_PIN             PA25

// For debugging (trace) via UART, make with env var PICO_TRACE set (see RP2350.mk).
// Example instance and pins below.
#define PICO_TRACE_UART_INSTANCE  0
#define PICO_TRACE_TX_GPIO        0
#define PICO_TRACE_RX_GPIO        1

// Example GPIO pins for testing motor output
#define MOTOR1_PIN           PA10
#define MOTOR2_PIN           PA11
#define MOTOR3_PIN           PA12
#define MOTOR4_PIN           PA13

