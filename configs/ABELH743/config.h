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

#define FC_TARGET_MCU       STM32H743

#define BOARD_NAME          ABELH743
#define MANUFACTURER_ID     DNFR

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_MAX7456
#define USE_SDCARD
#define USE_BARO
#define USE_BARO_BMP280
#define USE_BARO_DPS310
#ifndef USE_MAG
#define USE_MAG
#endif

#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN        PD13
#define GYRO_2_CLKIN_PIN        PD15

//#define BEEPER_PIN              PC9
#define MOTOR1_PIN              PE9
#define MOTOR2_PIN              PE11
#define MOTOR3_PIN              PE13
#define MOTOR4_PIN              PE14
#define MOTOR5_PIN              PC6
#define MOTOR6_PIN              PC7
#define MOTOR7_PIN              PC8
#define MOTOR8_PIN              PC9
//#define LED_STRIP_PIN           PA8
#define UART1_TX_PIN            PA9
#define UART2_TX_PIN            PD5
#define UART3_TX_PIN            PD8
#define UART4_TX_PIN            PD1
#define UART5_TX_PIN            PB13
#define UART7_TX_PIN            PE8
#define UART8_TX_PIN            PE1
#define UART1_RX_PIN            PA10
#define UART2_RX_PIN            PD6
#define UART3_RX_PIN            PD9
#define UART4_RX_PIN            PD0
#define UART5_RX_PIN            PB12
#define UART7_RX_PIN            PE7
#define UART8_RX_PIN            PE0
#define I2C1_SCL_PIN            PB6
#define I2C1_SDA_PIN            PB7
#define I2C2_SCL_PIN            PB10
#define I2C2_SDA_PIN            PB11
#define LED0_PIN                PE3
#define LED1_PIN                PE4
#define LED2_PIN                PE5
#define SPI1_SCK_PIN            PA5
#define SPI2_SCK_PIN            PD3
#define SPI3_SCK_PIN            PC10
#define SPI1_SDI_PIN            PA6
#define SPI2_SDI_PIN            PC2
#define SPI3_SDI_PIN            PC11
#define SPI1_SDO_PIN            PA7
#define SPI2_SDO_PIN            PC3
#define SPI3_SDO_PIN            PC12
#define ADC_VBAT_PIN            PB1
#define ADC_CURR_PIN            PC4
#define PINIO1_PIN              PB0
#define MAX7456_SPI_CS_PIN      PC13
#define GYRO_1_EXTI_PIN         PB2
#define GYRO_1_CS_PIN           PA4
#define GYRO_2_EXTI_PIN         PC14
#define GYRO_2_CS_PIN           PC0

#define USE_SDCARD_SDIO
#define SDIO_DEVICE             SDIODEV_2
#define SDIO_USE_4BIT           1
#define SDIO_CK_PIN             PC1
#define SDIO_CMD_PIN            PA0
#define SDIO_D0_PIN             PB14
#define SDIO_D1_PIN             PB15
#define SDIO_D2_PIN             PB3
#define SDIO_D3_PIN             PB4

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0,  PE9,  1,  0) \
    TIMER_PIN_MAP(1,  PE11, 1,  1) \
    TIMER_PIN_MAP(2,  PE13, 1,  2) \
    TIMER_PIN_MAP(3,  PE14, 1,  3) \
    TIMER_PIN_MAP(4,  PC6,  2,  4) \
    TIMER_PIN_MAP(5,  PC7,  2,  5) \
    TIMER_PIN_MAP(6,  PC8,  2,  6) \
    TIMER_PIN_MAP(7,  PC9,  2,  7) \
    TIMER_PIN_MAP(8,  PD13, 1, -1) \
    TIMER_PIN_MAP(9,  PD15, 1, -1) 

#define ADC1_DMA_OPT        8
#define ADC3_DMA_OPT        9
#define TIMUP1_DMA_OPT      10
#define TIMUP8_DMA_OPT      11

#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_2_SPI_INSTANCE             SPI2
#define MAX7456_SPI_INSTANCE            SPI3
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_SDCARD
#define DEFAULT_GYRO_TO_USE             GYRO_CONFIG_USE_GYRO_BOTH

#define MAG_I2C_INSTANCE                I2CDEV_2
#define BARO_I2C_INSTANCE               I2CDEV_1

#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
//#define DEFAULT_CURRENT_METER_SCALE     250
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
//#define DEFAULT_VOLTAGE_METER_SCALE     110

#define PINIO1_BOX                      40
#define PINIO1_CONFIG                   129

#define BEEPER_INVERTED

#define GYRO_1_ALIGN                    CW180_DEG
#define GYRO_2_ALIGN                    CW180_DEG
