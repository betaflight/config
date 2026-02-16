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

#define FC_TARGET_MCU        RP2350B
#define BOARD_NAME           MADFLIGHT_FC3
#define MANUFACTURER_ID      MADF

// Board info: https://madflight.com/Board-FC3/

// For debugging (trace) via UART, make with env var PICO_TRACE set (see RP2350.mk).
// Example instance and pins below.
//#define PICO_TRACE_UART_INSTANCE  0
//#define PICO_TRACE_TX_GPIO        20
//#define PICO_TRACE_RX_GPIO        21

//------------------
// Internal Pins
//------------------

// Bus for internal I2C sensors
// NOTE: Board has BMP580 barometer, MMC5603 compass and INA226 power sensor.
#define I2C0_SCL_PIN         PA33
#define I2C0_SDA_PIN         PA32
#define I2C0_CLOCKSPEED      100    // 100kHz (slow, most compatible)
#define USE_I2C_PULLUP                 // Enable internal pull-ups

// LED
#define LED0_PIN             PA45 // blue
//#define LED0_INVERTED

// INA226 Current Sensor (connected to I2C0)
#define USE_CURRENT_METER_INA226
#define DEFAULT_INA226_I2C_DEVICE        1      // 1 = I2CDEV_0 (internal I2C bus)
#define DEFAULT_INA226_ADDRESS           0x40   // Default INA226 address (A0=GND, A1=GND)
#define DEFAULT_INA226_SHUNT_RESISTANCE  2000   // 2mΩ shunt resistor (2000 µΩ) - adjust based on actual board design
#define DEFAULT_INA226_MAX_CURRENT       50000  // 50A maximum expected current
#define DEFAULT_INA226_VBAT_SCALE        100    // Calibration: 100 = 1.00x (no scaling needed, INA226 reads accurately)
#define DEFAULT_CURRENT_METER_SOURCE     CURRENT_METER_INA226

// Battery voltage - use INA226 for voltage measurement (no ADC needed)
#define DEFAULT_VOLTAGE_METER_SOURCE     VOLTAGE_METER_INA226

// RGB LED
#define LED_STRIP_PIN        PA46

// Motor protocol - Oneshot125 for analog ESCs
#define DEFAULT_MOTOR_PROTOCOL  MOTOR_PROTOCOL_ONESHOT125

// Digital OSD via MSP Displayport (for HDZero, Walksnail, DJI, etc.)
// Connect VTX to PIOUART0 (PA10=TX, PA11=RX)
#define USE_OSD
#define USE_MSP_DISPLAYPORT
#define MSP_DISPLAYPORT_UART    SERIAL_PORT_PIOUART0

// Gyro+acc
//#define USE_GYRO_CLKIN //TODO - gives compile error with betaflight_2025.12.0-beta
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_ACCGYRO_ICM45686
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN         PA30
#define SPI1_SDI_PIN         PA28
#define SPI1_SDO_PIN         PA31
#define GYRO_1_EXTI_PIN      PA27
#define GYRO_1_CS_PIN        PA29
#define GYRO_1_CLKIN_PIN     PA26  // for ICM42688P,ICP45686 needs #define USE_GYRO_CLKIN
#define GYRO_1_SPI_INSTANCE  SPI1
#define GYRO_1_ALIGN         CW180_DEG

// SDCARD 1-bit SPI - works
#define USE_SDCARD
#define USE_SDCARD_SPI
#define SPI0_SCK_PIN         PA34
#define SPI0_SDI_PIN         PA36
#define SPI0_SDO_PIN         PA35
#define SDCARD_SPI_CS_PIN    PA39
#define SDCARD_DETECT_PIN    NONE
#define SDCARD_DETECT_INVERTED
#define SDCARD_SPI_INSTANCE  SPI0
#define DEFAULT_BLACKBOX_DEVICE        BLACKBOX_DEVICE_SDCARD

/*
// SDCARD 4-bit SDIO - TODO - Compiles but still have "SD-CARD: Not configured" in configurator with betaflight_2025.12.0-beta
#define USE_SDCARD
#define SDCARD_DETECT_PIN    NONE
#define SDIO_DEVICE          SDIODEV_1
#define SDIO_USE_4BIT        1
#define SDIO_CK_PIN          PA34
#define SDIO_CMD_PIN         PA35
#define SDIO_D0_PIN          PA36
#define SDIO_D1_PIN          PA37
#define SDIO_D2_PIN          PA38
#define SDIO_D3_PIN          PA39
#define DEFAULT_BLACKBOX_DEVICE        BLACKBOX_DEVICE_SDCARD
*/

//------------------
// External Pins
//------------------

// Board has 3 rows of 10 external GPIOS, each row has 3 power+ground pins. Available pins are PA0-25,40-43

// --- First row of pins ---

// RC Radio - 1-on-1 connect ELRS / CRSF module
#define UART0_TX_PIN         PA0
#define UART0_RX_PIN         PA1
//+5V
//GND

// GPS + Compass
#define I2C1_SDA_PIN         PA2
#define I2C1_SCL_PIN         PA3
#define UART1_TX_PIN         PA4
#define UART1_RX_PIN         PA5
//+5V
//GND

// Motors
#define MOTOR1_PIN           PA6 // pwm3a
#define MOTOR2_PIN           PA7 // pwm3b
#define MOTOR3_PIN           PA8 // pwm4a
#define MOTOR4_PIN           PA9 // pwm4b
//+3.3V
//GND

// --- Second row of pins ---

// Additional UART
#define PIOUART0_TX_PIN      PA10
#define PIOUART0_RX_PIN      PA11
//+5V
//GND

// External LEDs
#define LED1_PIN             PA12 // green
//#define LED1_INVERTED
#define LED2_PIN             PA13 // red
//#define LED2_INVERTED

// Additional UART
#define PIOUART1_TX_PIN      PA14
#define PIOUART1_RX_PIN      PA15
//+5V
//GND

// Additional motors
#define MOTOR5_PIN           PA16 // pwm0a
#define MOTOR6_PIN           PA17 // pwm0b
#define MOTOR7_PIN           PA18 // pwm1a
#define MOTOR8_PIN           PA19 // pwm1b
//+3.3V
//GND

// --- Third row of pins ---

// Debugging (trace) via UART
//PA20 used as PICO_TRACE_TX_GPIO
//PA21 used as PICO_TRACE_RX_GPIO
//+5V
//GND

// GPIOs
#define PINIO1_PIN PA22
#define PINIO2_PIN PA23
#define PINIO3_PIN PA24
#define PINIO4_PIN PA25
//+5V
//GND

// ADC pins
#define ADC_RSSI_PIN         PA40
#define ADC_CURR_PIN         PA41
#define ADC_EXTERNAL1_PIN    PA42
//PA43 unused
//+3.3V
//GND

// Internal BMP5xx barometer on I2C0
#define USE_BARO
#define USE_BARO_BMP5XX
#define DEFAULT_BARO_BMP5XX
#define BARO_I2C_INSTANCE    I2CDEV_0

// Internal MMC5603 compass on I2C0
#define USE_MAG
#define USE_MAG_MMC5603
#define MAG_I2C_INSTANCE     I2CDEV_0

// Optional external barometers on I2C1 (second i2c bus) PA2=SDA PA3=SCL
// Disabled to reduce I2C detection errors - uncomment if needed
//#define USE_BARO_MS5611
//#define USE_BARO_BMP280
//#define USE_BARO_BMP388
//#define USE_BARO_LPS
//#define USE_BARO_QMP6988
//#define USE_BARO_DPS310
//#define USE_BARO_BMP085
//#define USE_BARO_2SMBP_02B
//#define USE_BARO_LPS22DF

// Optional external compass connected to I2C1 (second i2c bus) PA2=SDA PA3=SCL
// Disabled to reduce I2C detection errors - uncomment if needed
//#define USE_MAG_HMC5883
//#define USE_MAG_QMC5883
//#define USE_MAG_LIS2MDL
//#define USE_MAG_LIS3MDL
//#define USE_MAG_AK8975
//#define USE_MAG_IST8310
