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

// Tropic Community VMU: a carrier board around a Teensy 4.1 module, which
// brings the MIMXRT1062DVJ6B, the boot flash, the micro SD socket and USB.

#define FC_TARGET_MCU           TEENSY41

#define BOARD_NAME              TROPICCOMMUNITY
#define MANUFACTURER_ID         NXPI

// Serial ports by connector: LPUART2 GPS (10 pin JST-GH), LPUART3 TELEM,
// LPUART4 AUX, LPUART5 debug console (all 6 pin JST-GH), LPUART8 RC receiver
// (3 pin header). TELEM RTS on GPIO_AD_B1_05 and CTS on GPIO_AD_B1_04 are wired
// but unused. LPUART6 shares the AUX connector pins with the blue and red LEDs.
#define UART2_TX_PIN            GPIO_AD_B1_02
#define UART2_RX_PIN            GPIO_AD_B1_03
#define UART3_TX_PIN            GPIO_AD_B1_06
#define UART3_RX_PIN            GPIO_AD_B1_07
#define UART4_TX_PIN            GPIO_B1_00
#define UART4_RX_PIN            GPIO_B1_01
#define UART5_TX_PIN            GPIO_B1_12
#define UART5_RX_PIN            GPIO_B1_13

// The RC header carries one signal wire on LPUART8's transmit pad, so the
// receiver port runs half duplex and takes SBUS; CRSF needs two wires.
#define UART8_TX_PIN            GPIO_AD_B1_10

#define MSP_UART                SERIAL_PORT_UART5

#ifndef USE_GPS
#define USE_GPS
#endif
#define SERIALRX_UART           SERIAL_PORT_USART8
#define SERIALRX_HALFDUPLEX     1
#define SERIALRX_PROVIDER       SERIALRX_SBUS
#define GPS_UART                SERIAL_PORT_USART2

// The six 3 pin headers labelled PWM_1 to PWM_6, in board label order. MOTOR4's
// pad has no FlexIO1 pin and carries FlexIO2 pin 11, so DShot drives that one
// from FlexIO2; both instances run from the same 108 MHz clock.
#define MOTOR1_PIN              GPIO_EMC_06          // FlexIO1 pin 6, FlexPWM2 SM0 A
#define MOTOR2_PIN              GPIO_EMC_07          // FlexIO1 pin 7, FlexPWM2 SM0 B
#define MOTOR3_PIN              GPIO_EMC_08          // FlexIO1 pin 8, FlexPWM2 SM1 A
#define MOTOR4_PIN              GPIO_B0_11           // FlexIO2 pin 11, FlexPWM2 SM2 B
#define MOTOR5_PIN              GPIO_EMC_04          // FlexIO1 pin 4, FlexPWM4 SM2 A
#define MOTOR6_PIN              GPIO_EMC_05          // FlexIO1 pin 5, FlexPWM4 SM2 B

// An ICM-42688-P on LPSPI3, which the board labels SPI2. The module brings all
// four of that bus's pads out: pins 38 and 39 are two a Teensy 4.0 does not
// bond at all. Chip select is a plain GPIO, not the LPSPI hardware select. The
// board's BMI088 on LPSPI4 has no Betaflight driver, so that bus is left
// without pins, which also leaves the module's pin 13 LED alone.
#define USE_ACC
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P

#define SPI3_SCK_PIN            GPIO_AD_B1_15        // pin 27
#define SPI3_SDI_PIN            GPIO_AD_B1_13        // pin 39, MISO
#define SPI3_SDO_PIN            GPIO_AD_B1_14        // pin 26, MOSI

#define GYRO_1_SPI_INSTANCE     SPI3
#define GYRO_1_CS_PIN           GPIO_AD_B1_12        // pin 38

// DRDY in the board pinout table. This is pin 28, LPUART7's receive pad, and
// LPUART7's only other receive pad is on the boot flash bus, so LPUART7 stays
// without pins.
#define GYRO_1_EXTI_PIN         GPIO_EMC_32          // pin 28

#define GYRO_1_ALIGN            CW90_DEG

// LPI2C4 is the internal bus the board labels BARO_MAG, carrying a BMP388 and a
// BMM150. The BMM150 has no Betaflight driver and is left alone.
#define I2C4_SCL_PIN            GPIO_AD_B0_12
#define I2C4_SDA_PIN            GPIO_AD_B0_13
#define I2C_DEVICE              I2CDEV_4

#define USE_BARO
#define USE_BARO_BMP388
#define BARO_I2C_INSTANCE       I2CDEV_4

// The 4 pin external I2C connector, on LPI2C1, where a GPS puck's compass
// lands.
#define I2C1_SCL_PIN            GPIO_AD_B1_00
#define I2C1_SDA_PIN            GPIO_AD_B1_01

#define USE_MAG
#define MAG_I2C_INSTANCE        I2CDEV_1

// The micro SD socket is on the Teensy module, so the target names its pins.
#define USE_SDCARD
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD

// Battery voltage and current come in on the 6 pin power module connector. 180
// is the 18 to 1 divider of the modules this board is sold with; the current
// scale is left at the Betaflight default, as it follows the module's shunt.
#define ADC_VBAT_PIN            GPIO_AD_B1_08        // ADC1 channel 13
#define ADC_CURR_PIN            GPIO_AD_B1_11        // ADC1 channel 0
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     180

// The Tropic power module reports 38.462 amps per volt, and this scale counts
// millivolts per ten amps.
#define DEFAULT_CURRENT_METER_SCALE     260

// The onboard RGB LED, from the rev C schematic netlist, which corrects the
// README's pin table. Blue and red drive AO3400A gates and so light high, which
// is what LEDx_INVERTED means; green sinks the LED current and lights low. The
// blue and red pads double as LPUART6 on AUX connector pins 4 and 5.
#define LED0_PIN                GPIO_AD_B0_02        // blue
#define LED1_PIN                GPIO_B1_03           // green, direct low side
#define LED2_PIN                GPIO_AD_B0_03        // red
#define LED0_INVERTED
#define LED2_INVERTED

// The 4 pin CAN connector, on FlexCAN3, which is the only controller the Teensy
// module brings out to a transceiver on this carrier. These two pads carry
// FlexCAN3 on alternate 9. The transceiver has no silent or standby input, so
// there is no CAN3_SILENT_PIN.
#define CAN3_TX_PIN             GPIO_EMC_36
#define CAN3_RX_PIN             GPIO_EMC_37

// The DroneCAN stack, on FlexCAN3: dronecan_device defaults to 1, so a
// DroneCAN GNSS module needs "set dronecan_device = 3" as well as
// "set dronecan_enabled = ON".
#define USE_DRONECAN

// The onboard buzzer, on FlexPWM3 submodule 1 channel A. Its switch is on the
// low side and idles off, so the pin is not inverted.
#define USE_BEEPER
#define BEEPER_PIN              GPIO_EMC_31
#define BEEPER_PWM_HZ           3500
