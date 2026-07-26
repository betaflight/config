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

#define FC_TARGET_MCU     X32M7B

#define BOARD_NAME        HUMMINGBIRD_FC305_M7V2
#define MANUFACTURER_ID   HBRD

//ERROR from CLI dump: CORRUPTED CONFIG: baro_i2c_device = 10

// sensor drivers inherited from a sibling config -- verify against the board: gyro/acc<-HUMMINGBIRD_FC305 baro<-HUMMINGBIRD_FC305
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_GYRO
#define USE_GYRO_CLKIN
#define USE_GYRO_SPI_ICM42688P
#define USE_MAG
#define USE_MAX7456
#define USE_SDCARD
#define USE_SDCARD_SDIO
#define USE_SPI_GYRO
//TODO mag driver, e.g. USE_MAG_QMC5883 / USE_MAG_HMC5883

#define BEEPER_PIN           PA15
#define LED0_PIN             PD3
#define LED1_PIN             PD4
#define LED_STRIP_PIN        PE6
#define MOTOR1_PIN           PA0
#define MOTOR2_PIN           PA1
#define MOTOR3_PIN           PA2
#define MOTOR4_PIN           PA3
#define MOTOR5_PIN           PD12
#define MOTOR6_PIN           PD13
#define MOTOR7_PIN           PD14
#define MOTOR8_PIN           PD15
#define SERVO1_PIN           PB14
#define SERVO2_PIN           PB15

#define UART1_RX_PIN         PB7
#define UART1_TX_PIN         PB6
#define UART3_RX_PIN         PD9
#define UART3_TX_PIN         PD8
#define UART4_RX_PIN         PC7
#define UART4_TX_PIN         PC6
#define UART5_RX_PIN         PE2
#define UART5_TX_PIN         PE3
#define UART6_RX_PIN         PE4
#define UART6_TX_PIN         PE5
#define UART9_RX_PIN         PD0
#define UART9_TX_PIN         PD1
#define UART10_RX_PIN        PB12
#define UART10_TX_PIN        PB13
#define UART11_RX_PIN        PE7
#define UART11_TX_PIN        PE8
#define UART12_RX_PIN        PE0
#define UART12_TX_PIN        PE1

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define I2C10_SCL_PIN        PJ14
#define I2C10_SDA_PIN        PJ13

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
#define SPI3_SCK_PIN         PB3
#define SPI3_SDI_PIN         PB4
#define SPI3_SDO_PIN         PB5
#define SPI6_SCK_PIN         PE12
#define SPI6_SDI_PIN         PE13
#define SPI6_SDO_PIN         PE14

#define SDIO_CK_PIN          PC12
#define SDIO_CMD_PIN         PD2
#define SDIO_D0_PIN          PC8
#define SDIO_D1_PIN          PC9
#define SDIO_D2_PIN          PC10
#define SDIO_D3_PIN          PC11

#define ADC_CURR_PIN         PC1
#define ADC_EXTERNAL1_PIN    PC4
#define ADC_RSSI_PIN         PC5
#define ADC_VBAT_PIN         PC0
#define GYRO_1_CLKIN_PIN     PE9
#define GYRO_1_CS_PIN        PA4
#define GYRO_1_EXTI_PIN      PE10
#define MAX7456_SPI_CS_PIN   PD10
#define PINIO1_PIN           PC15
#define PINIO2_PIN           PC14
#define PINIO3_PIN           PC13

// FIXME occurrence indices below are placeholders (1). Get the real map with
//   make CONFIG=<BOARD> EXTRA_FLAGS="-DUSE_TIMER_MAP_PRINT"
// then "timer map" in the CLI, and re-run with --timer-map <capture>.
// From the capture, for checking the indices:
//   A00   TIM6 CH1 (AF8)
//   A01   TIM6 CH2 (AF5)
//   A02   TIM6 CH3 (AF4)
//   A03   TIM6 CH4 (AF8)
//   D12   TIM5 CH1 (AF3)
//   D13   TIM5 CH2 (AF3)
//   D14   TIM5 CH3 (AF6)
//   D15   TIM5 CH4 (AF6)
//   B14   TIM9 CH1 (AF8)
//   B15   TIM9 CH2 (AF8)
//   A15   TIM3 CH1 (AF9)
//   E06   TIM10 CH2 (AF5)
//   E09   TIM1 CH1 (AF6)
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(  0, PA0,   1,  2) \
    TIMER_PIN_MAP(  1, PA1,   1,  2) \
    TIMER_PIN_MAP(  2, PA2,   1,  2) \
    TIMER_PIN_MAP(  3, PA3,   1,  2) \
    TIMER_PIN_MAP(  4, PD12,  1,  3) \
    TIMER_PIN_MAP(  5, PD13,  1,  3) \
    TIMER_PIN_MAP(  6, PD14,  1,  3) \
    TIMER_PIN_MAP(  7, PD15,  1,  3) \
    TIMER_PIN_MAP(  8, PB14,  1, -1) \
    TIMER_PIN_MAP(  9, PB15,  1, -1) \
    TIMER_PIN_MAP( 10, PA15,  1, -1) \
    TIMER_PIN_MAP( 11, PE6,   1,  0) \
    TIMER_PIN_MAP( 12, PE9,   1, -1)

#define ADC1_DMA_OPT         8
#define ADC2_DMA_OPT         9
#define ADC3_DMA_OPT         10
#define ADC_INSTANCE         ADC1

#define BARO_I2C_INSTANCE            I2CDEV_10
#define GYRO_1_SPI_INSTANCE          SPI1
#define MAG_I2C_INSTANCE             I2CDEV_1
#define MAX7456_SPI_INSTANCE         SPI3
#define SDIO_DEVICE                  SDIODEV_1
#define SDIO_USE_4BIT

#define DEFAULT_FEATURES             (FEATURE_TELEMETRY | FEATURE_LED_STRIP | FEATURE_OSD | FEATURE_AIRMODE | FEATURE_ANTI_GRAVITY)
#define DEFAULT_RX_FEATURE           FEATURE_RX_SERIAL
#define ESC_SENSOR_UART              SERIAL_PORT_UART3
#define GPS_UART                     SERIAL_PORT_UART9
#define SERIALRX_UART                SERIAL_PORT_UART11

#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SCALE  800
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_DSHOT_BITBANG        DSHOT_BITBANG_ON
#define DEFAULT_DSHOT_BURST          DSHOT_DMAR_OFF
#define DEFAULT_VOLTAGE_METER_SCALE  110
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

#define BEEPER_INVERTED
#define SDCARD_DETECT_INVERTED

#define PINIO1_BOX                   40
#define PINIO1_CONFIG                129
#define PINIO2_BOX                   41
#define PINIO2_CONFIG                129
#define PINIO3_BOX                   42
#define PINIO3_CONFIG                129

// no config.h equivalent -- delete, or move to a preset
//TODO set i2c1_clockspeed_khz = 800
//TODO set i2c2_clockspeed_khz = 800
//TODO set i2c3_clockspeed_khz = 800
//TODO set i2c4_clockspeed_khz = 800
//TODO set motor_kv = 1960
//TODO set scheduler_debug_task = 0
//TODO set scheduler_relax_osd = 25
//TODO set scheduler_relax_rx = 25
//TODO set usb_msc_pin_pullup = ON
