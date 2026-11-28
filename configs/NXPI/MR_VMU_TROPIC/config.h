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

// MR-VMU-TROPIC, schematic SPF-94468 Rev D.

#define FC_TARGET_MCU           MIMXRT1064

#define BOARD_NAME              MR_VMU_TROPIC
#define MANUFACTURER_ID         NXPI

// USB1 VBUS comes from the connector, not from the supply.
#define USE_USB_DETECT

// Serial ports by connector: LPUART2 GPS J3, LPUART3 TELEM1 J7, LPUART4 AUX J8,
// LPUART5 TELEM2 J9, LPUART6 debug console J4 (nets CONSOLE_TX and CONSOLE_RX),
// LPUART7 ESC telemetry on the one wire net ONE_WIRE, LPUART8 RC input J11
// (CRSF and ELRS). TELEM1 CTS on GPIO_AD_B1_04 and RTS on GPIO_AD_B1_05 are
// wired but unused.
#define UART2_TX_PIN            GPIO_AD_B1_02
#define UART2_RX_PIN            GPIO_AD_B1_03
#define UART3_TX_PIN            GPIO_AD_B1_06
#define UART3_RX_PIN            GPIO_AD_B1_07
#define UART4_TX_PIN            GPIO_B1_00
#define UART4_RX_PIN            GPIO_B1_01
#define UART5_TX_PIN            GPIO_B1_12
#define UART5_RX_PIN            GPIO_B1_13
#define UART6_TX_PIN            GPIO_EMC_25
#define UART6_RX_PIN            GPIO_EMC_26
#define UART7_TX_PIN            GPIO_EMC_31          // the one wire pad
#define UART8_TX_PIN            GPIO_AD_B1_10
#define UART8_RX_PIN            GPIO_AD_B1_11

#define MSP_UART                SERIAL_PORT_USART6

#ifndef USE_GPS
#define USE_GPS
#endif
#define SERIALRX_UART           SERIAL_PORT_USART8
#define GPS_UART                SERIAL_PORT_USART2
#define ESC_SENSOR_UART         SERIAL_PORT_USART7

// LPUART7 transmit and receive share the one wire pad GPIO_EMC_31, so the ESC
// telemetry port only works half duplex.
#define DEFAULT_ESC_SENSOR_HALFDUPLEX 1
#define DEFAULT_FEATURES        FEATURE_ESC_SENSOR
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ESC
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ESC

// Motor outputs, connectors J13 (PWM_A) and J12 (PWM_B), in board label order,
// which is not the pad order: PWM_1 is GPIO_EMC_06 and PWM_5 is GPIO_EMC_02.
// Each pad carries a FlexIO pin (DShot) and a FlexPWM channel (PWM, brushed).
#define MOTOR1_PIN              GPIO_EMC_06          // FlexIO1 pin 6, FlexPWM2 SM0 A
#define MOTOR2_PIN              GPIO_EMC_07          // FlexIO1 pin 7, FlexPWM2 SM0 B
#define MOTOR3_PIN              GPIO_EMC_08          // FlexIO1 pin 8, FlexPWM2 SM1 A
#define MOTOR4_PIN              GPIO_EMC_09          // FlexIO1 pin 9, FlexPWM2 SM1 B
#define MOTOR5_PIN              GPIO_EMC_02          // FlexIO1 pin 2, FlexPWM4 SM1 A
#define MOTOR6_PIN              GPIO_EMC_03          // FlexIO1 pin 3, FlexPWM4 SM1 B
#define MOTOR7_PIN              GPIO_EMC_04          // FlexIO1 pin 4, FlexPWM4 SM2 A
#define MOTOR8_PIN              GPIO_EMC_05          // FlexIO1 pin 5, FlexPWM4 SM2 B

// An ICM-45686 on LPSPI3, which the schematic calls bus SPI2 on sheet 6. Chip
// select is a plain GPIO, not the LPSPI hardware select. The board's BMI088 on
// LPSPI4 has no Betaflight driver, so that bus is left without pins.
#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_ICM45686

#define SPI3_SCK_PIN            GPIO_AD_B1_15
#define SPI3_SDI_PIN            GPIO_AD_B1_13        // MISO
#define SPI3_SDO_PIN            GPIO_AD_B1_14        // MOSI

#define GYRO_1_SPI_INSTANCE     SPI3
#define GYRO_1_CS_PIN           GPIO_AD_B1_12
// Schematic net ICM42688_DRDY: the footprint takes an ICM-45686, ICM-42688P or
// ICM-42686P and the net is named after one of the others.
#define GYRO_1_EXTI_PIN         GPIO_EMC_32

// The chip sits turned 90 degrees clockwise from the board's forward edge, seen
// from above.
#define GYRO_1_ALIGN            CW90_DEG

// Only FlexCAN3 is wired to a transceiver, on alternate 9 of these two pads, so
// the DroneCAN connector is this bus. The transceiver has no silent or standby
// input, so no CAN3_SILENT_PIN.
#define CAN3_TX_PIN             GPIO_EMC_36
#define CAN3_RX_PIN             GPIO_EMC_37

// The DroneCAN stack, on FlexCAN3: dronecan_device defaults to 1, so this board
// needs "set dronecan_device = 3" as well as dronecan_enabled.
#define USE_DRONECAN

// The RGB LED, U10 on sheet 7. The pins sink the LED current, so a low pin
// lights the LED, which is the default polarity.
#define LED0_PIN                GPIO_EMC_33          // red,   also FLEXPWM3 SM2 A
#define LED1_PIN                GPIO_EMC_34          // blue,  also FLEXPWM3 SM2 B
#define LED2_PIN                GPIO_EMC_38          // green, also FLEXPWM1 SM3 A

// The buzzer, on FlexPWM1 submodule 0 channel A, driven through Q1, a low side
// switch that idles off, so the pin is not inverted.
#define USE_BEEPER
#define BEEPER_PIN              GPIO_EMC_23
#define BEEPER_PWM_HZ           2500

// LPI2C4, schematic nets BARO_MAG_SCL and BARO_MAG_SDA: a BMP390 barometer at
// 0x76 and a BMM350 magnetometer at 0x14. These two pads are also the LPUART1
// pads, so LPUART1 must stay without pins. The BMP388 driver accepts the BMP390
// chip ID.
#define I2C4_SCL_PIN            GPIO_AD_B0_12
#define I2C4_SDA_PIN            GPIO_AD_B0_13
#define I2C_DEVICE              I2CDEV_4

#define USE_BARO
#define USE_BARO_BMP388
#define BARO_I2C_INSTANCE       I2CDEV_4

// GPS connector J3 and the external I2C connector J5/J10. A Pixhawk style GPS
// puck puts its magnetometer, typically an IST8310, on this bus.
#define I2C1_SCL_PIN            GPIO_AD_B1_00
#define I2C1_SDA_PIN            GPIO_AD_B1_01
#define I2C3_SCL_PIN            GPIO_EMC_22
#define I2C3_SDA_PIN            GPIO_EMC_21

// The POWER connector J2 is the Pixhawk 6X digital one, with the power module's
// INA226 or INA228 on LPI2C3 and no analog path, so battery voltage and current
// come from the ESC telemetry. This bus and the GPS puck's compass bus leave the
// board on a cable, so they run at 400 kHz; the baro bus stays on the board at
// the default.
#define I2C1_CLOCKSPEED         400
#define I2C3_CLOCKSPEED         400

// The onboard BMM350 on LPI2C4 is the default compass; the GPS puck's IST8310 on
// LPI2C1 is chosen with `mag_i2c_device = 1` together with `align_mag = CW270FLIP`.
#define USE_MAG
#define MAG_I2C_INSTANCE        I2CDEV_4
#define MAG_ALIGN               CW90_DEG_FLIP

// The micro SD slot CN1 on USDHC1, four bits wide. The board's detect switch,
// on nets CD_SW, CD_COMMON and CD_B, is not used, so there is no card detect
// pin and DAT3 stands in.
#define USE_SDCARD
#define SDIO_DEVICE             SDIODEV_1
#define SDIO_USE_4BIT           true
#define SDIO_CK_PIN             GPIO_SD_B0_01
#define SDIO_CMD_PIN            GPIO_SD_B0_00
#define SDIO_D0_PIN             GPIO_SD_B0_02
#define SDIO_D1_PIN             GPIO_SD_B0_03
#define SDIO_D2_PIN             GPIO_SD_B0_04
#define SDIO_D3_PIN             GPIO_SD_B0_05

#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD
