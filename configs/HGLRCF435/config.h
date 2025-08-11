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

// MCU selection (AT32F435 QFN48). If your Flash size variant is M, change to AT32F435M
#define FC_TARGET_MCU        AT32F435G

#define BOARD_NAME           HGLRCF435
#define MANUFACTURER_ID      HGLR

// Sensors
#define USE_ACC
#define USE_GYRO
// IMU over SPI (popular modern choice)
#define USE_ACCGYRO_BMI270
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

// Optional peripherals commonly present on F435 boards
#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_MAX7456

// BEEPER / LEDs
#define USE_BEEPER
#define BEEPER_PIN              PC15
#define LED0_PIN                PH3   // IO_LED_0 per pinout

// Motors per pinout: PB6 (T4_1), PB7 (T4_2), PB8 (T4_3), PB9 (T4_4)
#define MOTOR1_PIN              PB6
#define MOTOR2_PIN              PB7
#define MOTOR3_PIN              PB8
#define MOTOR4_PIN              PB9   // per pinout: MOTOR_4_T4_4 on PB9

// LED strip
#define LED_STRIP_PIN           PA8

// UARTs
#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART4
#define UART1_TX_PIN            PA9
#define UART1_RX_PIN            PA10
#define UART2_TX_PIN            PA2
#define UART2_RX_PIN            PA3
#define UART3_TX_PIN            PB10
#define UART3_RX_PIN            PB11
#define UART4_RX_PIN            PH2   // per pinout: UART4_RX on PH2


// UART5/7 disabled to avoid conflicts with PB8 (motor) and PB3/PB4 (SPI3)

// SPI buses
#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3
#define SPI1_SCK_PIN            PA5
#define SPI1_SDI_PIN            PA6
#define SPI1_SDO_PIN            PA7

#define SPI2_SCK_PIN            PB13
#define SPI2_SDI_PIN            PB14
#define SPI2_SDO_PIN            PB15

// Analog
#define USE_ADC
#define ADC_VBAT_PIN            PB0   // per pinout: ADC1_IN8_VBAT on PB0
#define ADC_CURR_PIN            PB1   // per pinout: ADC1_IN9_CURRENT on PB1

// Chip-selects and interrupts
#define MAX7456_SPI_CS_PIN      PB12
#define GYRO_1_CS_PIN           PA4
#define GYRO_1_EXTI_PIN         PC14  // IMU EXTI per pinout
// External flash on SPI3 (PB3/PB4/PB5, CS on PA15)
#define SPI3_SCK_PIN            PB3
#define SPI3_SDI_PIN            PB4
#define SPI3_SDO_PIN            PB5
#define FLASH_CS_PIN            PA15

// Timer pin remapping table (index, pin, timer instance index, channel)
#define TIMER_PIN_MAPPING       TIMER_PIN_MAP(0, PA8,  1, 1) \
                                TIMER_PIN_MAP(1, PB6,  4, 1) \
                                TIMER_PIN_MAP(2, PB7,  4, 2) \
                                TIMER_PIN_MAP(3, PB8,  4, 3) \
                                TIMER_PIN_MAP(4, PB9,  4, 4)

// ADC settings
#define ADC_INSTANCE            ADC1
#define ADC1_DMA_OPT            11

// Defaults
#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST                 DSHOT_DMAR_AUTO
#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC

#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ                      8

// Bus instances
#define GYRO_1_SPI_INSTANCE     SPI1
#define MAX7456_SPI_INSTANCE    SPI2
#define FLASH_SPI_INSTANCE      SPI3

// I2C2 on PA0/PA1 per pinout
#define USE_I2C_DEVICE_2
#define I2C2_SCL_PIN            PA0
#define I2C2_SDA_PIN            PA1

// UART inverter per pinout (assign to UART2 typically used for SBUS)
#define INVERTER_PIN_UART2      PC13

// External clock pins per pinout (PH0/PH1)
#define HSE_PIN                PH0   // CRM_HEXT_IN per pinout
#define HSE_PIN_OUT            PH1   // CRM_HEXT_OUT per pinout

// Additional GPIO pins per pinout
#define PB2_PIN                PB2   // General purpose I/O per pinout (PB2/..)

// Debug and USB pins per pinout
#define USE_SERIAL_WIRE_DEBUG
#define SWDIO_PIN              PA13  // SWDIO per pinout
#define SWCLK_PIN              PA14  // SWCLK per pinout

// USB pins per pinout
#define USE_USB
#define USB_DETECT_PIN         PA12  // USB_OTGFS1_D+ per pinout
#define USB_DM_PIN             PA11  // USB_OTGFS1_D- per pinout




