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
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// BBH753 (AIRBOT H743): Restored based on the BetaFlight CLI backup (BTFL_cli_20260624) and the schematic diagram.
// Dual ICM42688P: Gyro1 = SPI4 (PE2/PE5/PE6), Gyro2 = SPI3 (PC10/PC11/PC12); MAX7456 OSD = SPI1; Flash = SPI2.
// 4-channel motor (QUADX): M1/M2 are on TIM3, and M3/M4 are on TIM1.
#define FC_TARGET_MCU        STM32H743

#define BOARD_NAME           BBH753
#define MANUFACTURER_ID      AIRB

#define USE_ACC
#define USE_GYRO
// Enable only the ICM42688P that is actually soldered in. Do not enable the ICM206xx/MPU6500-compatible driver;
// The MPU6500 detection path matches WHO_AM_I=0x47 before the ICM42688P driver does, resulting in the incorrect initialization process being used.
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define USE_BARO
#define USE_BARO_DPS310
#define USE_BARO_BMP280
#define USE_BARO_MS5611
#define USE_BARO_LPS22H

#define USE_MAG

#define USE_FLASH
#define USE_FLASH_W25Q128FV
#define USE_FLASH_W25N01G

#define USE_MAX7456
#define USE_GPS
#define USE_LED_STRIP

// Beeper — PD15 (CLI: beeper_inversion = ON)
// Passive Buzzer: Driven by a PWM square wave, 2500 Hz pitch (TIM4_CH4 / AF2)
#define BEEPER_PIN           PD15
#define BEEPER_INVERTED
#define BEEPER_PWM_HZ        2500

// Motors (QUADX, 4-channel): M1/M2 TIM3, M3/M4 TIM1
#define MOTOR1_PIN           PB0
#define MOTOR2_PIN           PB1
#define MOTOR3_PIN           PE9
#define MOTOR4_PIN           PE11

#define LED_STRIP_PIN        PD12

// UART x8
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART2_TX_PIN         PA2
#define UART2_RX_PIN         PA3
#define UART3_TX_PIN         PD8
#define UART3_RX_PIN         PD9
#define UART4_TX_PIN         PA0
#define UART4_RX_PIN         PA1
#define UART5_TX_PIN         PB6
#define UART5_RX_PIN         PB5
#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7
#define UART7_TX_PIN         PE8
#define UART7_RX_PIN         PE7
#define UART8_TX_PIN         PE1
#define UART8_RX_PIN         PE0

// I2C2 (Barometer) + I2C3
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define I2C3_SCL_PIN         PA8
#define I2C3_SDA_PIN         PC9

// Status Indicator Light
#define LED0_PIN             PF11

// SPI1 — MAX7456 OSD
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
// SPI2 — Flash
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15
// SPI3 — Gyro 2 (MISO=SDI, MOSI=SDO)
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12
// SPI4 — Gyro 1 (MISO=SDI, MOSI=SDO)
#define SPI4_SCK_PIN         PE2
#define SPI4_SDI_PIN         PE5
#define SPI4_SDO_PIN         PE6

// ADC (adc_device = 1)
#define ADC_VBAT_PIN         PC3
#define ADC_CURR_PIN         PC2
#define ADC_EXTERNAL1_PIN    PC0

// OSD — MAX7456 on SPI1
#define MAX7456_SPI_INSTANCE SPI1
#define MAX7456_SPI_CS_PIN   PA15

// Flash — SPI2
#define FLASH_SPI_INSTANCE   SPI2
#define FLASH_CS_PIN         PB4

// Gyro 1 — SPI4
#define GYRO_1_SPI_INSTANCE  SPI4
#define GYRO_1_CS_PIN        PE4
#define GYRO_1_ALIGN         CW0_DEG
// Gyro 2 — SPI3
#define GYRO_2_SPI_INSTANCE  SPI3
#define GYRO_2_CS_PIN        PB12
#define GYRO_2_ALIGN         CW0_DEG

// Gyro data-ready interrupts
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_2_EXTI_PIN      PB7

// Timer Mappings (Numbering based on timer_stm32h7xx.c; dmaopt uses the DMA pin values from the CLI backup)
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PB0,  2,  0) \
    TIMER_PIN_MAP( 1, PB1,  2,  1) \
    TIMER_PIN_MAP( 2, PE9,  1,  2) \
    TIMER_PIN_MAP( 3, PE11, 1,  3) \
    TIMER_PIN_MAP( 4, PD12, 1,  4) \
    TIMER_PIN_MAP( 5, PD15, 1, -1)

#define ADC1_DMA_OPT         8
#define ADC3_DMA_OPT         9
#define TIMUP1_DMA_OPT       0
#define TIMUP3_DMA_OPT       2

#define BARO_I2C_INSTANCE    I2CDEV_2
#define MAG_I2C_INSTANCE     I2CDEV_2

#define DEFAULT_BLACKBOX_DEVICE        BLACKBOX_DEVICE_FLASH
#define DEFAULT_GYRO_TO_USE            GYRO_CONFIG_USE_GYRO_BOTH
#define DEFAULT_CURRENT_METER_SOURCE   CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE   VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE    80
#define DEFAULT_VOLTAGE_METER_SCALE    110

#define SERIALRX_PROVIDER    SERIALRX_SBUS

