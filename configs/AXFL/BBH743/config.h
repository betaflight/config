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

#define FC_TARGET_MCU        STM32H743

#define BOARD_NAME           BBH743
#define MANUFACTURER_ID      AXFL

#define SYSTEM_HSE_MHZ       8

#define USE_ACC
#define USE_GYRO
// Gyro 1: ICM-42688-P on SPI4. Gyro 2: LSM6DSK320X footprint on SPI3, not fitted by default.
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P
#define USE_ACCGYRO_LSM6DSK320X
#define USE_ACCGYRO_ICM40609D
#define USE_ACCGYRO_IIM42652
#define USE_ACCGYRO_LSM6DSV16X

#define USE_BARO
#define USE_BARO_DPS310

#define USE_FLASH
#define USE_FLASH_W25Q128FV

// OSD: MSP DisplayPort on UART7. Bluetooth module on UART8.
#define MSP_DISPLAYPORT_UART SERIAL_PORT_UART7
#define MSP_UART             SERIAL_PORT_UART8

// Passive buzzer, NPN driven, active high
#define BEEPER_PIN           PB0
#define BEEPER_PWM_HZ        2500

#define MOTOR1_PIN           PE13
#define MOTOR2_PIN           PE14
#define MOTOR3_PIN           PE9
#define MOTOR4_PIN           PE11

#define PINIO1_PIN           PD12
#define PINIO1_BOX           40
#define PINIO2_PIN           PC14
#define PINIO2_BOX           41
#define CAMERA_CONTROL_PIN   PD15

#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10
#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PD6
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

#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define I2C3_SCL_PIN         PA8
#define I2C3_SDA_PIN         PC9

#define LED0_PIN             PD0

#define SPI2_SCK_PIN         PB13
#define SPI2_SDI_PIN         PB14
#define SPI2_SDO_PIN         PB15
#define SPI3_SCK_PIN         PC10
#define SPI3_SDI_PIN         PC11
#define SPI3_SDO_PIN         PC12
#define SPI4_SCK_PIN         PE2
#define SPI4_SDI_PIN         PE5
#define SPI4_SDO_PIN         PE6

#define ADC_VBAT_PIN         PC3
#define ADC_CURR_PIN         PC2

#define FLASH_SPI_INSTANCE   SPI2
#define FLASH_CS_PIN         PB4

#define GYRO_1_SPI_INSTANCE  SPI4
#define GYRO_1_CS_PIN        PE4
#define GYRO_1_EXTI_PIN      PC4
#define GYRO_1_ALIGN         CW0_DEG
#define GYRO_2_SPI_INSTANCE  SPI3
#define GYRO_2_CS_PIN        PB12
#define GYRO_2_EXTI_PIN      PB7
#define GYRO_2_ALIGN         CW0_DEG

#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN     PA5
// Gyro 2 CLKIN net. Not driven yet: gyrodev.c "CLKIN gyro 2 on separate pin is not supported yet".
#define GYRO_2_CLKIN_PIN     PA6

// Motors: TIM1 CH3/CH4/CH1/CH2. Beeper: TIM3_CH3. CLKIN: TIM2_CH1, TIM13_CH1. Camera control: TIM4_CH4.
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PE13, 1,  0) \
    TIMER_PIN_MAP( 1, PE14, 1,  1) \
    TIMER_PIN_MAP( 2, PE9,  1,  2) \
    TIMER_PIN_MAP( 3, PE11, 1,  3) \
    TIMER_PIN_MAP( 4, PB0,  2, -1) \
    TIMER_PIN_MAP( 5, PA5,  1, -1) \
    TIMER_PIN_MAP( 6, PA6,  2, -1) \
    TIMER_PIN_MAP( 7, PD15, 1, -1)

#define ADC1_DMA_OPT         8
#define ADC3_DMA_OPT         9
#define TIMUP1_DMA_OPT       10

#define BARO_I2C_INSTANCE    I2CDEV_2
#define MAG_I2C_INSTANCE     I2CDEV_3

#define DEFAULT_BLACKBOX_DEVICE        BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE   CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE   VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE    80
#define DEFAULT_VOLTAGE_METER_SCALE    110
