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

// ---------------------------------------------------------------------------
// LONELYBINARY - ESP32-S3 bring-up / development board ("the lonely binary").
//
//   MCU   : ESP32-S3 (16 MB flash, 8 MB PSRAM unused), native USB VCP.
//   IMU   : InvenSense MPU-6500 on SPI0 (the MPU-9250 driver also detects it),
//           INT1 wired to GPIO9 (data-ready EXTI).
//   LED   : WS2812 NeoPixel on GPIO48.
//   Motors: 4x PWM (LEDC) on GPIO4-7, kept clear of the JTAG pins (GPIO39-42).
//
// This is the board the ESP32-S3 port was brought up on; the pin map mirrors
// the defaults that used to live directly in the ESP32S3 target.h (now config
// driven). GPIOn == PAn in Betaflight pin tags.
// ---------------------------------------------------------------------------

#define FC_TARGET_MCU     ESP32S3

#define BOARD_NAME        LONELYBINARY
#define MANUFACTURER_ID   CUST

// --- Sensors ---------------------------------------------------------------
#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_MPU6500
#define USE_GYRO_SPI_MPU6500
#define USE_ACC_SPI_MPU9250
#define USE_GYRO_SPI_MPU9250

// --- Gyro/Acc on SPI0 ------------------------------------------------------
#define USE_SPI_GYRO
#define GYRO_1_SPI_INSTANCE  SPI0
#define GYRO_1_CS_PIN        PA10
#define GYRO_1_EXTI_PIN      PA9
#define GYRO_1_ALIGN         CW0_DEG

#define SPI0_SCK_PIN         PA12
#define SPI0_SDI_PIN         PA13   // MISO
#define SPI0_SDO_PIN         PA11   // MOSI

// --- Motors ----------------------------------------------------------------
#define MOTOR1_PIN           PA4
#define MOTOR2_PIN           PA5
#define MOTOR3_PIN           PA6
#define MOTOR4_PIN           PA7

// --- LED strip -------------------------------------------------------------
// Single WS2812 NeoPixel used as a status indicator, driven out of reset.
#define LED_STRIP_PIN        PA48
#define LED_STRIP_DEFAULT_BRIGHTNESS 20
#define LED_STRIP_DEFAULT_LED0  DEFINE_LED(0, 0, 0, 0, LED_FUNCTION_ARM_STATE, LED_FLAG_OVERLAY(LED_OVERLAY_WARNING))

// --- Defaults --------------------------------------------------------------
#define DEFAULT_MOTOR_PROTOCOL          MOTOR_PROTOCOL_PWM
#define DEFAULT_FEATURES                (FEATURE_LED_STRIP)

// High per-iteration cost on this port; decimate the PID loop. Tune to taste.
#define DEFAULT_PID_PROCESS_DENOM       4
