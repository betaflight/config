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

#define FC_TARGET_MCU     STM32F405

#define BOARD_NAME        TEFPVF405
#define MANUFACTURER_ID   TEHD

#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP280
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

#ifndef USE_WING
#define USE_WING
#endif

#ifndef USE_SERVOS
#define USE_SERVOS
#endif

#define BEEPER_PIN           PB9   // TIM11_CH1

#define MOTOR1_PIN           PA8   // TIM1_CH1
#define MOTOR2_PIN           PA9   // TIM1_CH2
#define MOTOR3_PIN           PC8   // TIM8_CH3
#define MOTOR4_PIN           PC9   // TIM8_CH4

#define SERVO1_PIN           PB0   // TIM3_CH3
#define SERVO2_PIN           PB1   // TIM3_CH4
#define SERVO3_PIN           PA3   // TIM9_CH2
#define SERVO4_PIN           PB14  // TIM12_CH1
#define SERVO5_PIN           PB15  // TIM12_CH2
#define SERVO6_PIN           PA6   // TIM13_CH1

#define LED_STRIP_PIN        PA2   // TIM5_CH3

#define UART1_TX_PIN         PB6
#define UART1_RX_PIN         PA10
#define UART3_TX_PIN         PB10
#define UART3_RX_PIN         PB11
#define UART4_TX_PIN         PA0
#define UART4_RX_PIN         PA1
#define UART5_TX_PIN         PC12
#define UART5_RX_PIN         PD2
#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7

#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB7

#define LED0_PIN             PA14
#define LED1_PIN             PA15

#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PB4
#define SPI1_SDO_PIN         PA7
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PC2
#define SPI2_SDO_PIN         PC3
#define SPI3_SCK_PIN         PB3
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PB5

#define ADC_VBAT_PIN         PC0
#define ADC_CURR_PIN         PC1

#define PINIO1_PIN           PA13
#define PINIO2_PIN           PA4

#define FLASH_CS_PIN         PC13
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PC15
#define GYRO_1_CS_PIN        PC14

/*
 * Native per-channel DShot DMA options.  Burst DShot is the default below,
 * so TIM1 and TIM8 use their update streams instead and leave room for ADC2.
 */
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN,    1,  1) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN,    1,  0) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN,    2,  1) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN,    2,  0) \
    TIMER_PIN_MAP( 4, SERVO1_PIN,    2, -1) \
    TIMER_PIN_MAP( 5, SERVO2_PIN,    2, -1) \
    TIMER_PIN_MAP( 6, SERVO3_PIN,    3, -1) \
    TIMER_PIN_MAP( 7, SERVO4_PIN,    3, -1) \
    TIMER_PIN_MAP( 8, SERVO5_PIN,    3, -1) \
    TIMER_PIN_MAP( 9, SERVO6_PIN,    2, -1) \
    TIMER_PIN_MAP(10, BEEPER_PIN,    2, -1) \
    TIMER_PIN_MAP(11, LED_STRIP_PIN, 2,  0)

/* DMA2: SPI1 RX=S0, ADC2=S2, SPI1 TX=S3, TIM8_UP=S1, TIM1_UP=S5. */
#define SPI1_RX_DMA_OPT     0
#define SPI1_TX_DMA_OPT     0
#define ADC2_DMA_OPT        0

/* DMA1: LED=S0, SPI3 RX=S2, SPI2 RX=S3, SPI2 TX=S4, SPI3 TX=S5. */
#define SPI2_RX_DMA_OPT     0
#define SPI2_TX_DMA_OPT     0
#define SPI3_RX_DMA_OPT     1
#define SPI3_TX_DMA_OPT     0

#define ADC_INSTANCE                    ADC2

#define BARO_I2C_INSTANCE               I2CDEV_1
#define MAG_I2C_INSTANCE                I2CDEV_1

#define SERIALRX_UART                   SERIAL_PORT_USART1
#define DEFAULT_RX_FEATURE              FEATURE_RX_SERIAL

#define PINIO1_BOX                      40
#define PINIO1_CONFIG                   129
#define BOX_USER1_NAME                  "12V BEC"
#define PINIO2_BOX                      41
#define PINIO2_CONFIG                   129
#define BOX_USER2_NAME                  "CAM 1,2"

#define DEFAULT_BLACKBOX_DEVICE         BLACKBOX_DEVICE_FLASH
#define DEFAULT_DSHOT_BURST             DSHOT_DMAR_ON
#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_OFF
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE     250

#define BEEPER_INVERTED
#define LED0_INVERTED
#define LED1_INVERTED

#define SYSTEM_HSE_MHZ                  8

#define MAX7456_SPI_INSTANCE            SPI2
#define FLASH_SPI_INSTANCE              SPI3
#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_ALIGN                    CW90_DEG
