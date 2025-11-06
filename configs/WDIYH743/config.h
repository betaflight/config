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
 
#define BOARD_NAME        WDIYH743
#define MANUFACTURER_ID   WDIY
 
#define USE_ACC
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P
#define USE_FLASH
#define USE_FLASH_W25N01G
#define USE_BARO
#define USE_BARO_BMP280
#define USE_MAX7456
  
#define BEEPER_PIN           PA10
#define MOTOR1_PIN           PA0          // TIM2_CH1
#define MOTOR2_PIN           PA1          // TIM2_CH2
#define MOTOR3_PIN           PA2          // TIM2_CH3
#define MOTOR4_PIN           PA3          // TIM2_CH4
#define MOTOR5_PIN           PB4          // TIM3_CH1
#define MOTOR6_PIN           PB5          // TIM3_CH2
#define MOTOR7_PIN           PB0          // TIM3_CH3
#define MOTOR8_PIN           PB1          // TIM3_CH4
#define SERVO1_PIN           PE11         // TIM1_CH2
#define SERVO2_PIN           PE14         // TIM1_CH3
 
#define RX_PPM_PIN           PB15         // TIM12_CH2
#define LED_STRIP_PIN        PB8          // TIM4_CH3
 
#define UART1_TX_PIN         PA9
#define UART2_TX_PIN         PD5
#define UART3_TX_PIN         PD8
#define UART4_TX_PIN         PD1
#define UART6_TX_PIN         PC6
#define UART7_TX_PIN         PE8
#define UART8_TX_PIN         PE1
#define UART1_RX_PIN         PB15
#define UART2_RX_PIN         PD6
#define UART3_RX_PIN         PD9
#define UART4_RX_PIN         PD0
#define UART6_RX_PIN         PC7
#define UART7_RX_PIN         PE7
#define UART8_RX_PIN         PE0
 
#define I2C1_SCL_PIN         PB6
#define I2C2_SCL_PIN         PB10
#define I2C3_SCL_PIN         PA8
#define I2C4_SCL_PIN         PD12
#define I2C1_SDA_PIN         PB7
#define I2C2_SDA_PIN         PB11
#define I2C3_SDA_PIN         PC9
#define I2C4_SDA_PIN         PD13
 
#define LED0_PIN             PE12
#define LED1_PIN             PE13
  
#define SPI1_SCK_PIN         PA5
#define SPI1_SDI_PIN         PA6
#define SPI1_SDO_PIN         PA7
 
#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PC2
#define SPI2_SDO_PIN         PC3
 
#define SPI3_SCK_PIN         PB3
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PB2
 
#define SPI4_SCK_PIN         PE2
#define SPI4_SDI_PIN         PE5
#define SPI4_SDO_PIN         PE6
 
#define ADC_VBAT_PIN         PC0
#define ADC_RSSI_PIN         PC4
#define ADC_CURR_PIN         PC1
 
#define FLASH_CS_PIN         PA15
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PE9
#define GYRO_2_EXTI_PIN      PE3
#define GYRO_1_CS_PIN        PA4
#define GYRO_2_CS_PIN        PE4

#define TIMER_PIN_MAPPING \
   TIMER_PIN_MAP( 0, MOTOR1_PIN,          2,  0) \
   TIMER_PIN_MAP( 1, MOTOR2_PIN,          2,  1) \
   TIMER_PIN_MAP( 2, MOTOR3_PIN,          2,  2) \
   TIMER_PIN_MAP( 3, MOTOR4_PIN,          2,  3) \
   TIMER_PIN_MAP( 4, MOTOR5_PIN,          1,  4) \
   TIMER_PIN_MAP( 5, MOTOR6_PIN ,         1,  5) \
   TIMER_PIN_MAP( 6, MOTOR7_PIN,          2,  6) \
   TIMER_PIN_MAP( 7, MOTOR8_PIN,          2,  7) \
   TIMER_PIN_MAP( 8, LED_STRIP_PIN,       2,  8) \
   TIMER_PIN_MAP( 9, RX_PPM_PIN,          2, -1) \
   TIMER_PIN_MAP(10, SERVO1_PIN,          1, -1) \
   TIMER_PIN_MAP(11, SERVO2_PIN,          1, -1)
   
#define TIMUP2_DMA_OPT      12
#define TIMUP3_DMA_OPT      13

#define ADC1_DMA_OPT        9
#define ADC2_DMA_OPT        10
#define ADC3_DMA_OPT        11
  
#define BARO_I2C_INSTANCE I2CDEV_2
#define MAG_I2C_INSTANCE  I2CDEV_1
  
#define DEFAULT_DSHOT_BITBANG DSHOT_BITBANG_ON
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE 350
#define BEEPER_INVERTED
#define MAX7456_SPI_INSTANCE SPI2
#define FLASH_SPI_INSTANCE SPI3
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_ALIGN CW90_DEG
#define GYRO_2_SPI_INSTANCE SPI4
#define GYRO_2_ALIGN CW90_DEG
