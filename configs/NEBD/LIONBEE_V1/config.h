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

#define FC_TARGET_MCU     AT32F435G

#define BOARD_NAME        LIONBEE_V1
#define MANUFACTURER_ID   NEBD

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_BMI270
// The board has an onboard LED strip; a cloud build does not enable it by default.
#ifndef USE_LED_STRIP
#define USE_LED_STRIP
#endif
// Kit sensors (DPS310 barometer, QMC5883 compass, M10 GPS) are not enabled by default in a cloud build.
#define USE_BARO
#define USE_BARO_DPS310
#define USE_MAG
#define USE_MAG_QMC5883L
#define USE_GPS
// Unproven: BMI270 rotation direction is unconfirmed on hardware and may be 180 degrees off.
#define ENABLE_BMI270_ALIGN_AS_ICM 1
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456
#define USE_VTX_RTC6705
#define USE_RX_SPI
#define USE_RX_EXPRESSLRS
#define USE_RX_SX1280

#define MOTOR1_PIN          PA1
#define MOTOR2_PIN          PA0
#define MOTOR3_PIN          PA9
#define MOTOR4_PIN          PA10
#define LED_STRIP_PIN       PB1
#define LED0_PIN            PB8
#define UART5_TX_PIN        PB6
#define UART5_RX_PIN        PB5
#define I2C2_SCL_PIN        PB10
#define I2C2_SDA_PIN        PB11

#define SPI1_SCK_PIN        PA5
#define SPI1_SDI_PIN        PA6
#define SPI1_SDO_PIN        PA7
#define SPI2_SCK_PIN        PB13
#define SPI2_SDI_PIN        PB14
#define SPI2_SDO_PIN        PB15
#define SPI3_SCK_PIN        PB12
#define SPI3_SDI_PIN        PB4
#define SPI3_SDO_PIN        PB0

#define ADC_VBAT_PIN        PA2
#define ADC_CURR_PIN        PA3
#define FLASH_CS_PIN        PC15
#define MAX7456_SPI_CS_PIN  PC14
#define GYRO_1_EXTI_PIN     PC13
#define GYRO_1_CS_PIN       PA4

// Unproven: PA14 (low bit) and PB7 (high bit) are the VTX power-code lines, set as PINIO outputs (unverified: 00 = 25 mW, 01 = 100 mW, 10 = MAX).
// pinio_box sets the armed VTX power code (0 = ARM mode ID, 255 = no box); disarmed is always 00 (25 mW):
// pinio_box = 255,255,255,255   armed 00 = 25 mW
// pinio_box = 0,255,255,255     armed 01 = 100 mW (default here, set by PINIO1_BOX below)
// pinio_box = 255,0,255,255     armed 10 = MAX
// pinio_box = 0,0,255,255       armed 11 = meaning unknown, untested
#define RTC6705_CS_PIN      PB2
#define PINIO1_PIN          PA14
// 0 is the ARM mode ID, so PA14 follows the armed state: high when armed, low (lowest power) when disarmed.
#define PINIO1_BOX          0
// No box is set for PB7; the pilot assigns one with pinio_box.
#define PINIO2_PIN          PB7

#define RX_SPI_CS_PIN                   PA8
#define RX_SPI_EXTI_PIN                 PB3
#define RX_SPI_BIND_PIN                 PH2
#define RX_SPI_LED_PIN                  PB9
#define RX_EXPRESSLRS_SPI_RESET_PIN     PH3
#define RX_EXPRESSLRS_SPI_BUSY_PIN      PA15

// Unproven: this mapping is untested on a flashed build; the factory unit runs DShot as bit-bang.
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, LED_STRIP_PIN , 2,  0) \
    TIMER_PIN_MAP( 1, MOTOR1_PIN    , 1,  0) \
    TIMER_PIN_MAP( 2, MOTOR2_PIN    , 1,  0) \
    TIMER_PIN_MAP( 3, MOTOR3_PIN    , 1,  0) \
    TIMER_PIN_MAP( 4, MOTOR4_PIN    , 1,  0)

#define ADC_INSTANCE                    ADC1
#define ADC1_DMA_OPT                    12

#define SYSTEM_HSE_MHZ                  8
#define GYRO_1_SPI_INSTANCE             SPI1
// Unproven: CW270_DEG comes from the vendor config, not from the factory dump.
// Alignment values apply to the ICM42688P. ENABLE_BMI270_ALIGN_AS_ICM rotates BMI270 axes to match it.
#define GYRO_1_ALIGN                    CW270_DEG
#define RX_SPI_INSTANCE                 SPI2
#define FLASH_SPI_INSTANCE              SPI3
#define MAX7456_SPI_INSTANCE            SPI3
#define RTC6705_SPI_INSTANCE            SPI3
// Unproven: taken from the vendor config; its effect is not tested.
#define SPI_SHARED_MAX7456_AND_RTC6705
#define MAG_I2C_INSTANCE                I2CDEV_2
#define BARO_I2C_INSTANCE               I2CDEV_2
#define GPS_UART                        SERIAL_PORT_UART5

#define RX_SPI_LED_INVERTED
#define RX_SPI_DEFAULT_PROTOCOL         RX_SPI_EXPRESSLRS
#define DEFAULT_RX_FEATURE              FEATURE_RX_SPI
// The kit includes a GPS; the board has an OSD chip and an onboard LED strip.
#define DEFAULT_FEATURES                (FEATURE_GPS | FEATURE_OSD | FEATURE_LED_STRIP)
// Unproven: TMR5 comes from the vendor config and is not checked on the factory unit.
#define RX_EXPRESSLRS_TIMER_INSTANCE    TMR5
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
// Unproven: scale copied from the factory dump and not calibrated.
#define DEFAULT_CURRENT_METER_SCALE     447
#define DEFAULT_ALIGN_BOARD_PITCH       180
#define YAW_MOTORS_REVERSED             1
