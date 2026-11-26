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

#define FC_TARGET_MCU     STM32H743

#define BOARD_NAME        HDZERO_HALO
#define MANUFACTURER_ID   HDZO

#define USE_GYRO
#define USE_GYRO_SPI_MPU6000
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC
#define USE_ACC_SPI_MPU6000
#define USE_ACC_SPI_ICM42688P
#define USE_FLASH
#define USE_FLASH_W25Q128FV

#ifndef USE_OSD_HD
#define USE_OSD_HD
#endif

#ifndef USE_LED_STRIP
#define USE_LED_STRIP
#endif

#define BEEPER_PIN PD12
#define MOTOR1_PIN PC6
#define MOTOR2_PIN PC7
#define MOTOR3_PIN PC8
#define MOTOR4_PIN PC9 
#define LED_STRIP_PIN PA10
#define UART1_TX_PIN PB6
#define UART2_TX_PIN PA2
#define UART5_TX_PIN PC12
#define UART7_TX_PIN PE8
#define UART8_TX_PIN PE1
#define UART1_RX_PIN PB7
#define UART2_RX_PIN PA3
#define UART3_RX_PIN PB11
#define UART4_RX_PIN PA1
#define UART5_RX_PIN PD2
#define UART7_RX_PIN PE7
#define UART8_RX_PIN PE0
#define I2C1_SCL_PIN PB8
#define I2C1_SDA_PIN PB9
#define LED0_PIN PE2
#define SPI1_SCK_PIN PA5
#define SPI2_SCK_PIN PB13
#define SPI1_SDI_PIN PA6
#define SPI2_SDI_PIN PB14
#define SPI1_SDO_PIN PA7
#define SPI2_SDO_PIN PB15
#define ADC_VBAT_PIN PC0
#define ADC_RSSI_PIN PC1
#define ADC_CURR_PIN PC2
#define FLASH_CS_PIN PB12
#define GYRO_1_EXTI_PIN PC13
#define GYRO_1_CS_PIN PB4
#define GYRO_2_EXTI_PIN PA15
#define GYRO_2_CS_PIN PB3

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(  0, MOTOR1_PIN,  1,  0 ) /* TIM3 CH1 */ \
    TIMER_PIN_MAP(  1, MOTOR2_PIN,  1,  1 ) /* TIM3 CH2 */ \
    TIMER_PIN_MAP(  2, MOTOR3_PIN,  1,  2 ) /* TIM3 CH3 */ \
    TIMER_PIN_MAP(  3, MOTOR4_PIN,  1,  3 ) /* TIM3 CH4 */ \
    TIMER_PIN_MAP(  4, LED_STRIP_PIN,  1,  4 ) /* TIM1 CH3 */ \
    TIMER_PIN_MAP(  5, BEEPER_PIN,  1,  -1 ) /* TIM4 CH1 */

#define TIMUP3_DMA_OPT      5

#define ADC1_DMA_OPT 8
#define ADC2_DMA_OPT 9
#define ADC3_DMA_OPT 10

#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON

#define DEFAULT_FEATURES (FEATURE_OSD | FEATURE_LED_STRIP | FEATURE_TELEMETRY)

#define SERIALRX_UART                   SERIAL_PORT_USART1
#define MSP_DISPLAYPORT_UART            SERIAL_PORT_UART5
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE     100
#define BEEPER_INVERTED
#define FLASH_SPI_INSTANCE              SPI2
#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_2_SPI_INSTANCE             SPI1
