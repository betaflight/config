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

#define FC_TARGET_MCU       STM32F405
#define BOARD_NAME          EMAX_F405_ELRS_AIO
#define MANUFACTURER_ID     EMAX 

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P 
#define USE_ACC_SPI_ICM42688P 

#define BEEPER_PIN B04
#define MOTOR1_PIN B00
#define MOTOR2_PIN B01
#define MOTOR3_PIN A03
#define MOTOR4_PIN A02
#define MOTOR5_PIN C08
#define MOTOR6_PIN A08
#define LED_STRIP_PIN B06
#define UART1_TX_PIN A09
#define UART3_TX_PIN B10
#define UART4_TX_PIN A00
#define UART6_TX_PIN C06
#define UART1_RX_PIN A10
#define UART3_RX_PIN B11
#define UART4_RX_PIN A01
#define UART5_RX_PIN D02
#define UART6_RX_PIN C07
#define INVERTER3_PIN C09
#define INVERTER6_PIN C08
#define LED1_PIN B05
#define SPI1_SCK_PIN A05
#define SPI2_SCK_PIN B13
#define SPI3_SCK_PIN C10
#define SPI1_SDI_PIN A06
#define SPI2_SDI_PIN B14
#define SPI3_SDI_PIN C11
#define SPI1_SDO_PIN A07
#define SPI2_SDO_PIN B15
#define SPI3_SDO_PIN C12
#define ESCSERIAL1_PIN B08
#define ADC_BATT_PIN C02
#define ADC_RSSI_PIN C00
#define ADC_CURR_PIN C01
#define BARO_CS_PIN B03
#define FLASH_CS_PIN B12
#define OSD_CS_PIN A15
#define GYRO_1_EXTI_PIN C04
#define GYRO_1_CS_PIN A04
#define USB_DETECT 1 C05

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0,PB8 , 3, 0)
    TIMER_PIN_MAP(1,PC8 , 3, 0)
    TIMER_PIN_MAP(2,PB0 , 2, 0)
    TIMER_PIN_MAP(3,PB1 , 2, 0)
    TIMER_PIN_MAP(4,PA3 , 1, 0)
    TIMER_PIN_MAP(5,PA2 , 1, 0)
    TIMER_PIN_MAP(6,PB6 , 2, 0)
    TIMER_PIN_MAP(7,PA8 , 1, 0)
    TIMER_PIN_MAP(8,PA9 , 1, 0)
    TIMER_PIN_MAP(9,PA10 , 1, 0)

#define ADC2_DMA_OPT        1

#define SERIALRX_PROVIDER CRSF
#define MAG_BUSTYPE SPI
#define BARO_SPI_DEVICE 3
#define ADC_DEVICE 2
#define BLACKBOX_DEVICE SPIFLASH
#define DSHOT_BURST ON
#define CURRENT_METER ADC
#define BATTERY_METER ADC
#define BEEPER_INVERSION ON
#define BEEPER_OD OFF
#define SYSTEM_HSE_MHZ 8
#define MAX7456_SPI_BUS 2
#define FLASH_SPI_BUS 2
#define GYRO_1_BUSTYPE SPI
#define GYRO_1_SPIBUS 1
#define GYRO_1_SENSOR_ALIGN CW90
#define GYRO_1_ALIGN_YAW 900
#define GYRO_2_BUSTYPE SPI
#define GYRO_2_SPIBUS 1
#define GYRO_1_SENSOR_ALIGN CW0

