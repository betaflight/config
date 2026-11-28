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

#define FC_TARGET_MCU        RP2350A
#define BOARD_NAME           OPENFC_LITE_MINI_RP2350A
#define MANUFACTURER_ID      OPDR

// OpenFC-Lite-Mini rev3.3: 20x20 mm mounting, RP2354A (QFN-60), 3S-6S
// https://github.com/OpenDrone-hw/OpenFC-Lite-Mini

// UART0: digital VTX connector (U8, JST SH 6-pin)
#define UART0_TX_PIN         PA0
#define UART0_RX_PIN         PA1

// PIO UART0: GPS
#define PIOUART0_TX_PIN      PA2
#define PIOUART0_RX_PIN      PA3

// I2C0: external compass etc.
#define I2C0_SDA_PIN         PA4
#define I2C0_SCL_PIN         PA5

// UART1: external serial RX
#define UART1_TX_PIN         PA6
#define UART1_RX_PIN         PA7
#define DEFAULT_RX_FEATURE   FEATURE_RX_SERIAL
#define SERIALRX_PROVIDER    SERIALRX_CRSF
#define SERIALRX_UART        SERIAL_PORT_UART1

// LED strip pad. Its WS2812 program goes on PIO1 (with the PIO UART): the
// default PIO2 is shared with the FB OSD, whose 31-instruction program then
// no longer fits and the OSD stays blank.
#define LED_STRIP_PIN        PA8
#define PIO_LEDSTRIP_INDEX   1
#define LED_STRIP_INVERTED   // pad driven by N-FET Q6 with 2.4k to 5V: inverts

// Gyro+acc on SPI1: BMI270 fitted; the footprint also takes ICM-426xx/456xx
#define USE_GYRO
#define USE_ACC
#define USE_ACCGYRO_BMI270
#define USE_ACCGYRO_LSM6DSV16X
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define USE_ACCGYRO_ICM45686
#define SPI1_SCK_PIN         PA10
#define SPI1_SDO_PIN         PA11
#define SPI1_SDI_PIN         PA12
#define GYRO_1_CS_PIN        PA13
#define GYRO_1_EXTI_PIN      PA9
#define GYRO_1_SPI_INSTANCE  SPI1

// BMI270 sits rotated 90 deg vs ICM parts on the shared footprint (#15484).
#define ENABLE_BMI270_ALIGN_AS_ICM 1

// Analog OSD (framebuffer OSD, PIO2)
#define ENABLE_FB_OSD        1
#define DEFAULT_FEATURES     (FEATURE_OSD)
#define DEFAULT_OSD_DISPLAYPORT_DEVICE OSD_DISPLAYPORT_DEVICE_FBOSD
#define DEFAULT_VIDEO_SYSTEM VIDEO_SYSTEM_AUTO // digital VTX users set vcd_video_system = HD
// MSP DisplayPort on the digital VTX connector by default, so going digital only takes vcd_video_system = HD
#define MSP_DISPLAYPORT_UART SERIAL_PORT_UART0
#define OSD_W_PIN            PA14
#define OSD_EN_PIN           PA15
#define OSD_SYNC_PIN         PA16

// Beeper pad (N-MOS low-side)
#define USE_BEEPER
#define BEEPER_PIN           PA17

// Blackbox: microSD on SPI0
#define USE_SDCARD
#define USE_SDCARD_SPI
#define SPI0_SCK_PIN         PA18
#define SPI0_SDO_PIN         PA19
#define SPI0_SDI_PIN         PA20
#define SDCARD_SPI_CS_PIN    PA21
#define SDCARD_SPI_INSTANCE  SPI0
#define DEFAULT_BLACKBOX_DEVICE  BLACKBOX_DEVICE_SDCARD

// Motors (PIO0 DShot); silk M1-M4 maps to GPIO25..22
#define MOTOR1_PIN           PA25
#define MOTOR2_PIN           PA24
#define MOTOR3_PIN           PA23
#define MOTOR4_PIN           PA22

// Bidirectional DShot on by default. ESC serial telemetry stays off: its pin
// shares PIO UART0 with the GPS pads.
#define DEFAULT_DSHOT_TELEMETRY DSHOT_TELEMETRY_ON

// Status LED (blue)
#define LED0_PIN             PA26

// 10V VTX/cam rail enable, active high. Inverted so pinioInit drives it high
// at boot: the rail powers the VTX/air unit, which must come up without a
// switch. Bind PINIO1_BOX to a mode only if switched rail control is wanted.
#define PINIO1_PIN           PA27
#define PINIO1_CONFIG        (PINIO_CONFIG_MODE_OUT_PP | PINIO_CONFIG_OUT_INVERTED)

// ADC: ESC current on ADC2, VBAT on ADC3 (1k + 100nF RC on each)
#define USE_ADC
#define ADC_CURR_PIN         PA28
#define ADC_VBAT_PIN         PA29
#define DEFAULT_VOLTAGE_METER_SOURCE  VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE   110 // 100k:10k divider (R1/R2)
#define DEFAULT_CURRENT_METER_SOURCE  CURRENT_METER_ADC // ESC current signal via 1k, scale depends on ESC
#define DEFAULT_CURRENT_METER_SCALE   200  // mV per 10 A, OpenESC-20x20: INA186A3 100 V/V on 0.2 mOhm = 20 mV/A
