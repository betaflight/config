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

#define FC_TARGET_MCU     STM32H753

#define BOARD_NAME        ACCTON_GFH7
#define MANUFACTURER_ID   ACCT

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_ACC_SPI_LSM6DSK320X
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_GYRO_SPI_LSM6DSK320X
#define USE_BARO
#define USE_BARO_DPS310
#define USE_SDCARD
#define USE_GYRO_CLKIN
#define USE_OSD
#define USE_MAX7456

#define BEEPER_PIN PE12 // BUZZER
#define MOTOR1_PIN PE9 // TIM1_CH1
#define MOTOR2_PIN PE11 // TIM1_CH2
#define MOTOR3_PIN PE13 // TIM1_CH3
#define MOTOR4_PIN PE14 // TIM1_CH4
#define SERVO1_PIN PC6 // TIM8_CH1
#define SERVO2_PIN PC7 // TIM8_CH2
#define SERVO3_PIN PC8 // TIM8_CH3
#define SERVO4_PIN PC9 // TIM8_CH4
#define LED_STRIP_PIN PB10 //TIM2_CH3
                       
#define UART1_TX_PIN PA9
#define UART2_TX_PIN PD5
#define UART3_TX_PIN PD8
#define UART4_TX_PIN PC10
#define UART5_TX_PIN PB6
#define UART7_TX_PIN PE8
#define UART8_TX_PIN PE1
#define UART1_RX_PIN PA10
#define UART2_RX_PIN PA3
#define UART3_RX_PIN PD9
#define UART4_RX_PIN PC11
#define UART5_RX_PIN PD2
#define UART7_RX_PIN PE7
#define UART8_RX_PIN PE0
#define I2C1_SCL_PIN PB8
#define I2C1_SDA_PIN PB7
#define I2C4_SCL_PIN PD12
#define I2C4_SDA_PIN PD13
#define LED0_PIN     PE10
#define LED1_PIN     PC13
#define SPI1_SCK_PIN PA5
#define SPI2_SCK_PIN PD3
#define SPI4_SCK_PIN PE2
#define SPI1_SDI_PIN PA6
#define SPI2_SDI_PIN PC2
#define SPI4_SDI_PIN PE5
#define SPI1_SDO_PIN PD7
#define SPI2_SDO_PIN PC3
#define SPI4_SDO_PIN PE6
#define ADC_VBAT_PIN PC0
#define ADC_CURR_PIN PB0
#define ADC_RSSI_PIN PB1
#define GYRO_1_EXTI_PIN PD10
#define GYRO_1_CS_PIN PE4
#define GYRO_1_ALIGN CW0_DEG
#define GYRO_2_EXTI_PIN PD11
#define GYRO_2_CS_PIN PB9
#define GYRO_2_ALIGN CW0_DEG
#define GYRO_1_CLKIN_PIN PD14
#define MAX7456_SPI_CS_PIN PA4
#define SDIO_CK_PIN   PD6
#define SDIO_CMD_PIN  PA0
#define SDIO_D0_PIN   PB14
#define SDIO_D1_PIN   PB15
#define SDIO_D2_PIN   PB3
#define SDIO_D3_PIN   PB4
#define SDCARD_DETECT_PIN PA15

#define BOX_USER1_NAME      "VTX SWITCH"
#define PINIO1_BOX    40
#define PINIO1_CONFIG 1
#define PINIO1_PIN    PC12 // 12V_EN Switch
#define BOX_USER2_NAME      "HEARTER SWITCH"
#define PINIO2_BOX    41
#define PINIO2_CONFIG 1
#define PINIO2_PIN    PE3 // hearter switch pin

#define TIMER_PIN_MAPPING \
   TIMER_PIN_MAP( 0, MOTOR1_PIN,       1,  0) \ /* TIM1_CH1, DMA Opt 0 */ \
   TIMER_PIN_MAP( 1, MOTOR2_PIN,       1,  1) \ /* TIM1_CH2, DMA Opt 1 */ \
   TIMER_PIN_MAP( 2, MOTOR3_PIN,       1,  2) \ /* TIM1_CH3, DMA Opt 2 */ \
   TIMER_PIN_MAP( 3, MOTOR4_PIN,       1,  3) \ /* TIM1_CH4, DMA Opt 3 */ \
   TIMER_PIN_MAP( 4, LED_STRIP_PIN,    1,  0) \ /* TIM2_CH3 */ \
   TIMER_PIN_MAP( 5, GYRO_1_CLKIN_PIN, 1, -1) \ /* TIM4_CH3, No DMA */ \
   TIMER_PIN_MAP( 6, SERVO1_PIN,       2, -1) \ /* TIM8_CH1, No DMA */ \
   TIMER_PIN_MAP( 7, SERVO2_PIN,       2, -1) \ /* TIM8_CH2, No DMA */ \
   TIMER_PIN_MAP( 8, SERVO3_PIN,       2, -1) \ /* TIM8_CH3, No DMA */ \
   TIMER_PIN_MAP( 9, SERVO4_PIN,       2, -1)   /* TIM8_CH4, No DMA */

#define ADC_INSTANCE  ADC1
#define ADC1_DMA_OPT 1

#define BARO_I2C_INSTANCE I2CDEV_1
#define MAG_I2C_INSTANCE I2CDEV_1
#define DEFAULT_BARO_I2C_ADDRESS 119
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD
#define DEFAULT_DSHOT_BITBANG  DSHOT_BITBANG_OFF
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

#define LED0_INVERTED
#define LED1_INVERTED
#define BEEPER_INVERTED
#define SYSTEM_HSE_MHZ 16
#define GYRO_1_SPI_INSTANCE SPI4
#define GYRO_2_SPI_INSTANCE SPI2
#define MAX7456_SPI_INSTANCE SPI1
#define SDIO_DEVICE SDIODEV_2
#define SDIO_USE_4BIT 1