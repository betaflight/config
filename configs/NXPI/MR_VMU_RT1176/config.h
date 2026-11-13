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

// Pixhawk V6X-RT, hardware revision 2.

#define FC_TARGET_MCU           MIMXRT1176

#define BOARD_NAME              MR_VMU_RT1176
#define MANUFACTURER_ID         NXPI

// USB1 VBUS comes from the connector, not from the supply.
#define USE_USB_DETECT

// The switched power rails, all active high and all off out of reset. Nothing
// on them answers until they are on, so config.c turns them on before the
// buses and the sensor search.
#define USE_CONFIG_TARGET_PREINIT
#define VDD_3V3_SENSORS1_EN     GPIO_EMC_B1_33
#define VDD_3V3_SENSORS2_EN     GPIO_EMC_B1_22
#define VDD_3V3_SENSORS3_EN     GPIO_EMC_B1_14
#define VDD_3V3_SENSORS4_EN     GPIO_EMC_B1_36
#define VDD_3V3_SD_CARD_EN      GPIO_EMC_B1_01

// Serial ports by connector: LPUART1 debug console, LPUART3 GPS1, LPUART4
// TELEM1, LPUART5 GPS2, LPUART6 RC IN (CRSF and ELRS), LPUART8 TELEM2, LPUART10
// TELEM3. Connector flow control lines are wired but unused.
#define UART1_TX_PIN            GPIO_DISP_B1_02
#define UART1_RX_PIN            GPIO_DISP_B1_03
#define UART3_TX_PIN            GPIO_AD_30
#define UART3_RX_PIN            GPIO_AD_31
#define UART4_TX_PIN            GPIO_DISP_B1_06
#define UART4_RX_PIN            GPIO_DISP_B1_04
#define UART5_TX_PIN            GPIO_AD_28
#define UART5_RX_PIN            GPIO_AD_29
#define UART6_TX_PIN            GPIO_EMC_B1_40
#define UART6_RX_PIN            GPIO_EMC_B1_41
#define UART8_TX_PIN            GPIO_AD_02
#define UART8_RX_PIN            GPIO_AD_03
#define UART10_TX_PIN           GPIO_AD_15
#define UART10_RX_PIN           GPIO_AD_33

#define MSP_UART                SERIAL_PORT_USART1

#ifndef USE_GPS
#define USE_GPS
#endif
#define SERIALRX_UART           SERIAL_PORT_USART6
#define GPS_UART                SERIAL_PORT_USART3

// The first eight of the twelve FMU PWM channels, in the board's channel
// order; each pad also carries a FlexIO1 pin, so DShot works on all eight.
// Channels 9 to 12 (FlexPWM3 SM1 A and SM3 A, FlexPWM4 SM0 A and SM1 A on
// GPIO_EMC_B1_31, 21, 00 and 02) are free for "resource motor" in the CLI.
#define MOTOR1_PIN              GPIO_EMC_B1_23       // FlexIO1 pin 23, FlexPWM1 SM0 A
#define MOTOR2_PIN              GPIO_EMC_B1_25       // FlexIO1 pin 25, FlexPWM1 SM1 A
#define MOTOR3_PIN              GPIO_EMC_B1_27       // FlexIO1 pin 27, FlexPWM1 SM2 A
#define MOTOR4_PIN              GPIO_EMC_B1_06       // FlexIO1 pin 6,  FlexPWM2 SM0 A
#define MOTOR5_PIN              GPIO_EMC_B1_08       // FlexIO1 pin 8,  FlexPWM2 SM1 A
#define MOTOR6_PIN              GPIO_EMC_B1_10       // FlexIO1 pin 10, FlexPWM2 SM2 A
#define MOTOR7_PIN              GPIO_EMC_B1_19       // FlexIO1 pin 19, FlexPWM2 SM3 A
#define MOTOR8_PIN              GPIO_EMC_B1_29       // FlexIO1 pin 29, FlexPWM3 SM0 A

// Two ICM-45686 gyros, one each on LPSPI1 and LPSPI2; the board's BMI088 on
// LPSPI3 is left alone. Chip select is a plain GPIO, not the LPSPI hardware
// select. The alignments below are reset defaults, so a stored configuration
// keeps its old value until reset.
#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_ICM45686

#define SPI1_SCK_PIN            GPIO_EMC_B2_00
#define SPI1_SDI_PIN            GPIO_EMC_B2_03       // MISO
#define SPI1_SDO_PIN            GPIO_EMC_B2_02       // MOSI

#define GYRO_1_SPI_INSTANCE     SPI1
#define GYRO_1_CS_PIN           GPIO_EMC_B2_01
#define GYRO_1_EXTI_PIN         GPIO_AD_20
// Mounted upside down: top faces the board, X axis points to the rear.
#define GYRO_1_ALIGN            CW0_DEG_FLIP

#define SPI2_SCK_PIN            GPIO_AD_24
#define SPI2_SDI_PIN            GPIO_AD_27           // MISO
#define SPI2_SDO_PIN            GPIO_AD_26           // MOSI

#define GYRO_2_SPI_INSTANCE     SPI2
#define GYRO_2_CS_PIN           GPIO_AD_25
#define GYRO_2_EXTI_PIN         GPIO_EMC_B1_39
// Top side up, rotated 270 degrees clockwise seen from above.
#define GYRO_2_ALIGN            CW270_DEG

#define DEFAULT_GYRO_TO_USE     GYRO_CONFIG_USE_GYRO_BOTH

// Micro SD slot on USDHC1, four bits wide. No card detect pin.
#define USE_SDCARD
#define SDIO_DEVICE             SDIODEV_1
#define SDIO_USE_4BIT           true
#define SDIO_CK_PIN             GPIO_SD_B1_01
#define SDIO_CMD_PIN            GPIO_SD_B1_00
#define SDIO_D0_PIN             GPIO_SD_B1_02
#define SDIO_D1_PIN             GPIO_SD_B1_03
#define SDIO_D2_PIN             GPIO_SD_B1_04
#define SDIO_D3_PIN             GPIO_SD_B1_05

#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD

// CAN by connector: FlexCAN1 on CAN1, FlexCAN2 on CAN2, FlexCAN3 on the
// internal bus. No transceiver has a silent or standby input, so no
// CANx_SILENT_PIN. FlexCAN3 is in the low power domain and only reaches the
// GPIO_LPSR pads.
#define CAN1_TX_PIN             GPIO_AD_06
#define CAN1_RX_PIN             GPIO_AD_07
#define CAN2_TX_PIN             GPIO_AD_00
#define CAN2_RX_PIN             GPIO_AD_01
#define CAN3_TX_PIN             GPIO_LPSR_00
#define CAN3_RX_PIN             GPIO_LPSR_01

// The CAN1 connector is the DroneCAN bus a GPS puck or a set of CAN ESCs is
// expected on, and dronecan_device defaults to 1, so the stack comes up on it.
// Whether the task runs is still the dronecan_enabled CLI setting.
#define USE_DRONECAN

// Status LEDs, schematic nets nLED_RED, nLED_GREEN and nLED_BLUE. All three
// sink the LED current, so a low pin lights the LED, which is the default
// polarity: no LEDx_INVERTED.
#define LED0_PIN                GPIO_DISP_B2_00      // red
#define LED1_PIN                GPIO_DISP_B2_01      // green
#define LED2_PIN                GPIO_EMC_B1_13       // blue

// Buzzer. GPIO_EMC_B2_09 carries no FlexPWM output, so the tone comes from
// GPT3 compare channel 2 on ALT1, clocked by the 24 MHz crystal.
#define USE_BEEPER
#define BEEPER_PIN              GPIO_EMC_B2_09
#define BEEPER_PWM_HZ           2500
#define BEEPER_GPT_INSTANCE     3
#define BEEPER_GPT_CHANNEL      2
#define BEEPER_GPT_MUX_MODE     1       // ALT1 on this pad is GPT3_COMPARE2

// Analog inputs, all five on LPADC1, all behind dividers: GPIO_AD_10 CH2A and
// GPIO_AD_11 CH2B and GPIO_AD_12 CH3A and GPIO_AD_17 CH5B are 3V3 sensor rails
// 1 to 4, GPIO_AD_13 CH3B is the 5V rail. Battery voltage and current are not
// analog here: they come over I2C from the power brick, which Betaflight does
// not read yet, so no voltage meter is selected.
#define ADC_EXTERNAL1_PIN       GPIO_AD_10

// LPI2C3, schematic nets I2C3_SCL_FMU and I2C3_SDA_FMU: the internal sensor
// bus, with a BMP390 barometer at 0x77 and a BMM350 magnetometer on it. LPI2C3
// also reaches GPIO_DISP_B1_02 and GPIO_DISP_B1_03, which the debug console
// holds, so the bus takes its other pad pair.
#define I2C3_SCL_PIN            GPIO_DISP_B2_10
#define I2C3_SDA_PIN            GPIO_DISP_B2_11
#define I2C_DEVICE              I2CDEV_3

#define USE_BARO
#define USE_BARO_BMP388
#define BARO_I2C_INSTANCE       I2CDEV_3

// The barometer answers at 0x77, not the driver's built in 0x76, so the address
// has to be named here. The BMP388 driver accepts the BMP390 chip ID.
#define DEFAULT_BARO_I2C_ADDRESS 0x77

// LPI2C1, schematic nets I2C1_SCL_GPS1 and I2C1_SDA_GPS1: the GPS1 connector
// and the power brick that feeds it. A Pixhawk style GPS puck puts its
// magnetometer, typically an IST8310, on this bus. The board's second external
// bus is LPI2C6, which sits in the low power domain and only reaches the
// GPIO_LPSR pads; I2CDEV_COUNT is 4 here, so LPI2C5 and LPI2C6 have no driver
// and that connector is left without pins.
#define I2C1_SCL_PIN            GPIO_AD_08
#define I2C1_SDA_PIN            GPIO_AD_09

// The onboard BMM350 on LPI2C3 is the default compass; the GPS puck's IST8310 on
// LPI2C1 is chosen with `mag_i2c_device = 1` together with `align_mag = CW270FLIP`.
#define USE_MAG
#define MAG_I2C_INSTANCE        I2CDEV_3
#define MAG_ALIGN               CW180_DEG_FLIP
