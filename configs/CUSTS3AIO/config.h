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
// CUSTS3AIO - custom ESP32-S3 all-in-one flight controller.
//
//   MCU    : ESP32-S3-MINI-1-N4R2 (4 MB flash, 2 MB PSRAM unused), native USB.
//   IMU    : InvenSense ICM-42688-P on SPI0 (FSPI). INT not routed -> polled.
//   Baro   : Bosch BMP580 on I2C0.
//   ESCs   : 6x TI MCT8329A integrated BLDC drivers (PWM "SPEED" input);
//            4 used as a quad (M1-M4).
//   LED    : single WS2812 status LED.
//   USB-C  : native ESP32-S3 USB (GPIO19/20).
//   Also fitted but UNUSED by Betaflight: ST VL53L1 ToF on I2C0 (no BF driver).
//
// Pin map derived from the board schematic; GPIOn == PAn in Betaflight tags.
// ---------------------------------------------------------------------------

#define FC_TARGET_MCU     ESP32S3

#define BOARD_NAME        CUSTS3AIO
#define MANUFACTURER_ID   CUST

// --- Sensors ---------------------------------------------------------------
#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define USE_BARO
#define USE_BARO_BMP580

// --- Gyro/Acc on SPI0 ------------------------------------------------------
// ICM-42688-P. INT1 is not wired to the MCU on this board, so GYRO_1_EXTI_PIN
// is intentionally omitted: the gyro runs in the polled (GYRO_EXTI_NO_INT)
// path. ALIGN is a placeholder - verify against the physical IMU mounting.
#define USE_SPI_GYRO
#define GYRO_1_SPI_INSTANCE  SPI0
#define GYRO_1_CS_PIN        PA39   // MPUCS
#define GYRO_1_ALIGN         CW0_DEG

#define SPI0_SCK_PIN         PA38   // CLK
#define SPI0_SDI_PIN         PA36   // MISO
#define SPI0_SDO_PIN         PA37   // MOSI

// --- I2C0 (barometer) ------------------------------------------------------
#define BARO_I2C_INSTANCE    I2CDEV_0
#define I2C0_SCL_PIN         PA42   // VLCLK
#define I2C0_SDA_PIN         PA41   // VLDA

// --- ADC -------------------------------------------------------------------
// Battery voltage on GPIO1 (ADC1_CH0) via a 50k/10k divider (VBAT/6).
// VOLTAGE_METER_SCALE below is a first estimate - calibrate on the bench, the
// ESP32-S3 ADC uses an eFuse-trimmed Vref so the exact scale is board/part
// dependent. No shunt is fitted, hence the virtual current meter.
#define USE_ADC
#define ADC_VBAT_PIN         PA1    // VSENSE

// --- UARTs -----------------------------------------------------------------
// UART0: native console pins (U0TXD/U0RXD), not broken out for the user.
// UART1: TX/RX broken out on the FPC connector - primary serial-RX port.
#define UART0_TX_PIN         PA43
#define UART0_RX_PIN         PA44
#define UART1_TX_PIN         PA15   // TX
#define UART1_RX_PIN         PA16   // RX

// --- Motors ----------------------------------------------------------------
// The MCT8329A6 BLDC drivers read the DUTY CYCLE of a PWM throttle on their SPEED
// input (0% = stop, ~100% = full), so they are driven with duty-cycle PWM at 1 kHz
// (Betaflight's BRUSHED protocol), exactly as the reference firmware does - NOT the
// 1-2 ms RC PWM, which would idle at ~50% duty. The chips' speed-input mode is set
// in their own EEPROM, so no I2C configuration is needed at boot.
// Betaflight quad-X motor order (schematic M1/M2/M5/M6):
//   M1 back-right=GPIO33, M2 front-right=GPIO35, M3 back-left=GPIO4, M4 front-left=GPIO6.
#define MOTOR1_PIN           PA33   // M1 (back right)
#define MOTOR2_PIN           PA35   // M2 (front right)
#define MOTOR3_PIN           PA4    // M3 (back left)
#define MOTOR4_PIN           PA6    // M4 (front left)

// --- LED strip -------------------------------------------------------------
// Single WS2812 used as a status indicator (green disarmed / blue armed,
// blinking on warnings) so it is driven out of reset rather than sitting at
// its uncontrolled bright-white power-on state.
#define LED_STRIP_PIN        PA8    // LED
#define LED_STRIP_DEFAULT_BRIGHTNESS 20
#define LED_STRIP_DEFAULT_LED0  DEFINE_LED(0, 0, 0, 0, LED_FUNCTION_ARM_STATE, LED_FLAG_OVERLAY(LED_OVERLAY_WARNING))

// --- Defaults --------------------------------------------------------------
#define DEFAULT_MOTOR_PROTOCOL          MOTOR_PROTOCOL_BRUSHED
#define DEFAULT_MOTOR_PWM_RATE          1000   // Hz; MCT8329A6 SPEED duty-cycle PWM, per the Y3
#define DEFAULT_FEATURES                (FEATURE_LED_STRIP)
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_VIRTUAL
#define DEFAULT_VOLTAGE_METER_SCALE     60
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_SERIAL

// Polled gyro on a port with a high per-iteration cost: decimate the PID loop
// to keep the scheduler within budget. Tune once real loop timing is known.
#define DEFAULT_PID_PROCESS_DENOM       4
