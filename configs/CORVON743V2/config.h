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

#define FC_TARGET_MCU   STM32H743

#define BOARD_NAME      CORVON743V2
#define MANUFACTURER_ID CORV

// Four MSP-capable ports are used at once (USB VCP, USART1 MSP, USART2
// DisplayPort, UART8 Bluetooth); the default cap of 3 rejects this config.
#define MAX_MSP_PORT_COUNT 4

// --- Sensor drivers ---
#define USE_ACC
#define USE_GYRO
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP581
#define DEFAULT_BARO_BMP581
#define USE_SDCARD

#ifndef USE_MAG
#define USE_MAG
#define USE_MAG_IST8310
#endif

// --- Motor pins (8 DShot motors + 2 PWM servos) ---
#define MOTOR1_PIN  PE9     // TIM1_CH1
#define MOTOR2_PIN  PE11    // TIM1_CH2
#define MOTOR3_PIN  PE13    // TIM1_CH3
#define MOTOR4_PIN  PE14    // TIM1_CH4
#define MOTOR5_PIN  PB0     // TIM3_CH3
#define MOTOR6_PIN  PB1     // TIM3_CH4
#define MOTOR7_PIN  PD12    // TIM4_CH1
#define MOTOR8_PIN  PD13    // TIM4_CH2
// PD14 / PD15: ESC pads 9-10, not mapped by this target.
#define SERVO1_PIN  PB14    // TIM12_CH1, PWM-only
#define SERVO2_PIN  PB15    // TIM12_CH2, PWM-only

// --- UART pins (8 UARTs) ---
#define UART1_TX_PIN PA9
#define UART1_RX_PIN PA10
#define UART2_TX_PIN PA2
#define UART2_RX_PIN PA3
#define UART3_TX_PIN PD8
#define UART3_RX_PIN PD9
#define UART4_TX_PIN PA0
#define UART4_RX_PIN PA1
#define UART5_TX_PIN PB13
#define UART5_RX_PIN PB12
#define UART6_TX_PIN PC6
#define UART6_RX_PIN PC7
#define UART7_TX_PIN PE8
#define UART7_RX_PIN PE7
#define UART8_TX_PIN PE1
#define UART8_RX_PIN PE0

// --- I2C pins ---
#define I2C1_SCL_PIN PB6     // external (GPS / compass)
#define I2C1_SDA_PIN PB7
#define I2C2_SCL_PIN PB10    // internal (BMP581 baro + IST8310 mag)
#define I2C2_SDA_PIN PB11

// --- SPI3 (IMU bus) ---
#define SPI3_SCK_PIN PB3
#define SPI3_SDI_PIN PB4     // MISO
#define SPI3_SDO_PIN PB5     // MOSI

// --- SDIO (SDMMC1, 4-bit) ---
#define SDIO_CK_PIN  PC12
#define SDIO_CMD_PIN PD2
#define SDIO_D0_PIN  PC8
#define SDIO_D1_PIN  PC9
#define SDIO_D2_PIN  PC10
#define SDIO_D3_PIN  PC11

// --- ADC ---
#define ADC_VBAT_PIN PC0
#define ADC_CURR_PIN PC1
#define ADC_RSSI_PIN PA6
// PC4 / PC5: secondary battery ADC pads, not mapped by this target.
// PD0 / PA8 / PD1 / PE2: user GPIO pads SW1-4 (assignable as PINIO via CLI).

// --- Status LEDs (PE4 blue, PE5 red, PE6 green) ---
#define LED0_PIN PE4
#define LED1_PIN PE5
#define LED2_PIN PE6

// --- Beeper + WS2812 ---
#define BEEPER_PIN    PA7    // TIM14_CH1
#define LED_STRIP_PIN PA5    // TIM2_CH1

// --- Gyro: ICM-42688P on SPI3 ---
#define GYRO_1_SPI_INSTANCE SPI3
#define GYRO_1_CS_PIN       PA15
#define GYRO_1_EXTI_PIN     PD10
#define GYRO_1_ALIGN        CW90_DEG

// --- Baro: BMP581 on I2C2 ---
#define BARO_I2C_INSTANCE        I2CDEV_2
#define DEFAULT_BARO_I2C_ADDRESS 0x46     // SDO = GND

// --- Mag: IST8310 on I2C2 @ 0x0E ---
#define MAG_I2C_INSTANCE I2CDEV_2
#define MAG_I2C_ADDRESS  14          // 0x0E
#define MAG_ALIGN        CW90_DEG

// --- Timer pin mapping ---
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN,    1,  0 ) /* PE9  TIM1_CH1  */ \
    TIMER_PIN_MAP( 1, MOTOR2_PIN,    1,  1 ) /* PE11 TIM1_CH2  */ \
    TIMER_PIN_MAP( 2, MOTOR3_PIN,    1,  2 ) /* PE13 TIM1_CH3  */ \
    TIMER_PIN_MAP( 3, MOTOR4_PIN,    1,  3 ) /* PE14 TIM1_CH4  */ \
    TIMER_PIN_MAP( 4, MOTOR5_PIN,    2,  4 ) /* PB0  TIM3_CH3  */ \
    TIMER_PIN_MAP( 5, MOTOR6_PIN,    2,  5 ) /* PB1  TIM3_CH4  */ \
    TIMER_PIN_MAP( 6, MOTOR7_PIN,    1,  6 ) /* PD12 TIM4_CH1  */ \
    TIMER_PIN_MAP( 7, MOTOR8_PIN,    1,  7 ) /* PD13 TIM4_CH2  */ \
    TIMER_PIN_MAP( 8, SERVO1_PIN,    2, -1 ) /* PB14 TIM12_CH1 */ \
    TIMER_PIN_MAP( 9, SERVO2_PIN,    2, -1 ) /* PB15 TIM12_CH2 */ \
    TIMER_PIN_MAP(10, LED_STRIP_PIN, 1, 10 ) /* PA5  TIM2_CH1  */ \
    TIMER_PIN_MAP(11, BEEPER_PIN,    4, -1 ) /* PA7  TIM14_CH1 */

#define ADC1_DMA_OPT   8
#define ADC3_DMA_OPT   9
#define TIMUP1_DMA_OPT 0
#define TIMUP3_DMA_OPT 0
#define TIMUP4_DMA_OPT 0

#define SDIO_USE_4BIT 1
#define SDIO_DEVICE   SDIODEV_1

#define BEEPER_INVERTED
#define BEEPER_PWM_HZ 2500

#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE  402
#define DEFAULT_VOLTAGE_METER_SCALE  210     // 21:1 divider

// --- Default serial port functions ---
#define MSP_UART             SERIAL_PORT_USART1
#define MSP_DISPLAYPORT_UART SERIAL_PORT_USART2   // DJI O4
#define GPS_UART             SERIAL_PORT_USART3
#define SERIALRX_UART        SERIAL_PORT_USART6
#define ESC_SENSOR_UART      SERIAL_PORT_UART7
#define USE_MSP_UART         SERIAL_PORT_UART8    // onboard Bluetooth
// UART4 / UART5 have no default function.
