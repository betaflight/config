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

#define FC_TARGET_MCU     STM32F7X2

#define BOARD_NAME        NEXUSXR
#define MANUFACTURER_ID   RDMS

#define USE_ACC
#define USE_GYRO
#define USE_GYRO_CLKIN
#define USE_GYRO_SPI_ICM42688P
#define USE_ACC_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_DPS310
#define USE_FLASH
#define USE_FLASH_W25N

#ifndef USE_WING
#define USE_WING
#endif

#ifndef USE_SERVOS
#define USE_SERVOS
#endif

#define MOTOR1_PIN           PA9  // ESC
#define MOTOR2_PIN           PA15 // Tail
#define SERVO1_PIN           PB4  // S1
#define SERVO2_PIN           PB5  // S2
#define SERVO3_PIN           PB0  // S3

#define UART1_TX_PIN         PB6 // AUX or S6
#define UART1_RX_PIN         PB7 // SBUS or S7

#define UART2_TX_PIN         PA2 // RPM or S4
#define UART2_RX_PIN         PA3 // TLM or S5

// Port C
#define UART3_TX_PIN         PB10
#define UART3_RX_PIN         PB11

// Port A
#define UART4_TX_PIN         PA0
#define UART4_RX_PIN         PA1

// Internal ELRS
#define UART5_TX_PIN         PC12
#define UART5_RX_PIN         PD2

// Port B
#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7

#define I2C3_SCL_PIN         PA8
#define I2C3_SDA_PIN         PC9
#define LED0_PIN             PC10
#define LED1_PIN             PC11
#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PB15
#define ADC_VBAT_PIN         PC0 // EXT-V
#define ADC_CURR_PIN         PC3 // ADC-CS
#define ADC_EXTERNAL1_PIN    PC1 // ADC-RX
#define ADC_EXTERNAL2_PIN    PC2 // ADC-5V
#define PINIO1_PIN           PC8 // RF EN
#define FLASH_CS_PIN         PB12
#define GYRO_1_EXTI_PIN      PB8
#define GYRO_1_CS_PIN        PA4
#define GYRO_1_CLKIN_PIN     PB9

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA9,  1,  0 ) /* TIM1_CH2 */ \
    TIMER_PIN_MAP( 1, PA15, 1,  0 ) /* TIM2_CH1 */ \
    TIMER_PIN_MAP( 2, PB4,  1, -1 ) /* TIM3_CH1 */ \
    TIMER_PIN_MAP( 3, PB5,  1, -1 ) /* TIM3_CH2 */ \
    TIMER_PIN_MAP( 4, PB0,  2, -1 ) /* TIM3_CH3 */ \
    TIMER_PIN_MAP( 5, PA2,  2, -1 ) /* TIM5_CH3 */ \
	TIMER_PIN_MAP( 6, PA3,  2, -1 ) /* TIM5_CH4 */ \
    TIMER_PIN_MAP( 7, PB6,  1, -1 ) /* TIM4_CH1 */ \
	TIMER_PIN_MAP( 8, PB7,  1, -1 ) /* TIM4_CH2 */ \
	TIMER_PIN_MAP( 9, PB9,  2, -1 ) /* TIM11_CH1 */ 

#define ADC1_DMA_OPT                    0

#define BARO_I2C_INSTANCE               I2CDEV_3
#define MAG_I2C_INSTANCE                I2CDEV_3
#define ADC_INSTANCE                    ADC1
#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE     475
#define DEFAULT_CURRENT_METER_SCALE     273
#define PINIO1_BOX                      40
#define PINIO1_CONFIG                   129
#define BOX_USER1_NAME                  "ELRS OFF"
#define DEFAULT_RX_FEATURE              FEATURE_RX_SERIAL
#define SERIALRX_UART                   SERIAL_PORT_UART5
#define SERIALRX_PROVIDER               SERIALRX_CRSF
#define FLASH_SPI_INSTANCE              SPI2
#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_ALIGN                    CW0_DEG
