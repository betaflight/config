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

// NXP MR-NAVQ95, the Cortex-M7 core of the i.MX95.

#define FC_TARGET_MCU           MIMX9596

#define BOARD_NAME              MR_NAVQ95
#define MANUFACTURER_ID         NXPI

// What this board's System Manager configuration grants the M7.
#define NXP_SCMI_MU             MU5_MUA
// LPUART2, LPUART5, LPUART6 and LPUART7.
#define NXP_LPUART_INSTANCE_MASK ((1 << 2) | (1 << 5) | (1 << 6) | (1 << 7))
// TPM3 to TPM5; TPM1 and TPM2 stay with the always on domain and TPM6 faults.
#define NXP_TPM_INSTANCE_MASK   ((1 << 3) | (1 << 4) | (1 << 5))
// eDMA2 channels 30 to 59; Linux keeps the rest.
#define NXP_EDMA2_CHANNEL_FIRST 30
#define NXP_EDMA2_CHANNEL_COUNT 30
// eDMA3 channels shared with the M33: the LPI2C1, LPSPI1 and LPUART2 requests.
#define NXP_EDMA3_CHANNEL_MASK  ((1UL << 12) | (1UL << 13) | (1UL << 16) | (1UL << 17) | (1UL << 22) | (1UL << 23))
// FlexIO1 drives the motors.
#define NXP_DSHOT_FLEXIO_INSTANCE 1
// Every bonded pad of GPIO1 to GPIO5.
#define TARGET_IO_PORTA 0x0000ffff
#define TARGET_IO_PORTB 0xffffffff
#define TARGET_IO_PORTC 0xffffffff
#define TARGET_IO_PORTD 0x3fffffff
#define TARGET_IO_PORTE 0x0003ffff
// The octal NOR bus the image runs from.
#define NXP_RESERVED_PINS \
    IO_TAG(XSPI1_DATA0), IO_TAG(XSPI1_DATA1), IO_TAG(XSPI1_DATA2), IO_TAG(XSPI1_DATA3), \
    IO_TAG(XSPI1_DATA4), IO_TAG(XSPI1_DATA5), IO_TAG(XSPI1_DATA6), IO_TAG(XSPI1_DATA7), \
    IO_TAG(XSPI1_SCLK), IO_TAG(XSPI1_SS0_B), IO_TAG(XSPI1_DQS)

// Serial ports: LPUART2 debug console, MSP and CLI, LPUART5 GPS, LPUART6 CRSF
// on J9 pins 2 and 5, LPUART7 TELEM on J14.
#define UART2_TX_PIN            UART2_TXD
#define UART2_RX_PIN            UART2_RXD
#define UART5_TX_PIN            GPIO_IO00
#define UART5_RX_PIN            GPIO_IO01
#define UART6_TX_PIN            GPIO_IO04            // J9 pin 2
#define UART6_RX_PIN            GPIO_IO05            // J9 pin 5
#define UART7_TX_PIN            GPIO_IO08            // J14
#define UART7_RX_PIN            GPIO_IO09            // J14

#define MSP_UART                SERIAL_PORT_USART2
#define SERIALRX_UART           SERIAL_PORT_UART6
#define SERIALRX_PROVIDER       SERIALRX_CRSF
#define DEFAULT_RX_FEATURE      FEATURE_RX_SERIAL

// Linux on the A55 over rpmsg: MSP and the CLI on /dev/ttyBF, the configuration
// and the blackbox logs in /betaflight.
#define USE_RPMSG

#ifndef USE_GPS
#define USE_GPS
#endif
#define GPS_UART                SERIAL_PORT_UART5

// Four motors on J9 pins 3, 4, 6 and 7: TPM3 channels 1 and 3, TPM4 channel 1
// and TPM5 channel 0 give PWM, and every pad is also a FlexIO1 pin for DShot.
// The eight motor layout used GPIO_IO04/05/06/20/21/22/23/24; pins 2 and 5 went
// to CRSF, pin 8 to ESC telemetry and pin 9 to the buzzer.
#define MOTOR1_PIN              GPIO_IO20            // J9 pin 3, FlexIO1 pin 20, TPM3 CH1
#define MOTOR2_PIN              GPIO_IO24            // J9 pin 4, FlexIO1 pin 24, TPM3 CH3
#define MOTOR3_PIN              GPIO_IO21            // J9 pin 6, FlexIO1 pin 21, TPM4 CH1
#define MOTOR4_PIN              GPIO_IO06            // J9 pin 7, FlexIO1 pin 6,  TPM5 CH0

// ESC telemetry, receive only, on FlexIO1 pin 22 (J9 pin 8).
#define USE_PIOUART0
#define PIOUART0_RX_PIN         GPIO_IO22
#define ESC_SENSOR_UART         SERIAL_PORT_PIOUART0

// The buzzer on J9 pin 9 while S1 is ON; assumed active high.
#define USE_BEEPER
#define BEEPER_PIN              GPIO_IO23

// An ICM-45686 on LPSPI1 and a BMI088 on LPSPI8; the BMI088 has no Betaflight
// driver, so LPSPI8 is left without pins. Chip select is a plain GPIO, not the
// LPSPI hardware select.
#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_ICM45686

#define SPI1_SCK_PIN            SAI1_TXD0
#define SPI1_SDI_PIN            SAI1_TXC             // MISO
#define SPI1_SDO_PIN            SAI1_RXD0            // MOSI

#define GYRO_1_SPI_INSTANCE     SPI1
#define GYRO_1_CS_PIN           SAI1_TXFS            // GPIO1_IO11
#define GYRO_1_EXTI_PIN         XSPI1_SS1_B          // GPIO5_IO11

// The gyro is mounted flipped, so its alignment is CW0_DEG_FLIP.
#define GYRO_1_ALIGN            CW0_DEG_FLIP

// FlexCAN2 and FlexCAN3. No silent pin is known, so no CANx_SILENT_PIN.
#define CAN2_TX_PIN             GPIO_IO25
#define CAN2_RX_PIN             GPIO_IO27
#define CAN3_TX_PIN             CCM_CLKO3
#define CAN3_RX_PIN             CCM_CLKO4

#define USE_DRONECAN

// The onboard BMM350 is on the I2C1 pads, LPI2C1, which Linux
// calls I3C1. LPI2C6 is the external connector, where a GPS puck puts its
// magnetometer. The BMP581 at 0x46 shares the I2C1 pads and answers plain I2C.
// The I2C1 pads need the pad pull-up: without it the bus stays busy and the BMM350 is not found.
#define USE_I2C_PULLUP
#define I2C1_SCL_PIN            I2C1_SCL
#define I2C1_SDA_PIN            I2C1_SDA
#define I2C6_SCL_PIN            GPIO_IO03
#define I2C6_SDA_PIN            GPIO_IO02
#define I2C_DEVICE              I2CDEV_1

// USE_BARO_BMP581 alone leaves the barometer bus unset, DEFAULT_BARO_BMP581 selects I2C.
#define USE_BARO
#define USE_BARO_BMP581
#define DEFAULT_BARO_BMP581
#define BARO_I2C_INSTANCE       I2CDEV_1
#define DEFAULT_BARO_I2C_ADDRESS 0x46

// The BMM350 is rotated 90 degrees and flipped, so its alignment is CW90_DEG_FLIP.
#define USE_MAG
#define MAG_I2C_INSTANCE        I2CDEV_1
#define MAG_ALIGN               CW90_DEG_FLIP

// Analog inputs by ADC channel: VIN on channel 0 is the battery voltage and the
// 5 V rail on channel 1 is the external input. The board has no current sense.
#define ADC_VBAT_CHANNEL        0
#define ADC_EXTERNAL1_CHANNEL   1

// The VIN divider is 64.4; 193 / (3 * 1) = 64.33 is the nearest ratio the 8 bit settings hold.
#define DEFAULT_VOLTAGE_METER_SOURCE      VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE       193
#define DEFAULT_VOLTAGE_METER_DIVIDER     3
#define DEFAULT_VOLTAGE_METER_MULTIPLIER  1
#define DEFAULT_CURRENT_METER_SOURCE      CURRENT_METER_NONE

// No USB, SD card, flash or LED pins are defined.
