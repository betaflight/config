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

/*
    VERSION: 2026.6.0
*/

#pragma once

#define FC_TARGET_MCU   STM32H743
#define SYSTEM_HSE_MHZ  8

#define BOARD_NAME      MICOAIR743LITE
#define MANUFACTURER_ID MICO

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_ICM45686
#define USE_SDCARD
#ifndef USE_BARO
#define USE_BARO
#endif
#define USE_BARO_SPA06_003

#define MOTOR1_PIN PE14
#define MOTOR2_PIN PE13
#define MOTOR3_PIN PE11
#define MOTOR4_PIN PE9
#define MOTOR5_PIN PB1
#define MOTOR6_PIN PB0
#define MOTOR7_PIN PA7
#define MOTOR8_PIN PA6

// M9 through M14 are auxiliary PWM outputs.
#define SERVO1_PIN PE5
#define SERVO2_PIN PE6
#define SERVO3_PIN PD12
#define SERVO4_PIN PD13
#define SERVO5_PIN PB14
#define SERVO6_PIN PB15

#define UART1_TX_PIN PA9
#define UART2_TX_PIN PA2
#define UART3_TX_PIN PD8
#define UART4_TX_PIN PA0
#define UART5_TX_PIN PB6
#define UART6_TX_PIN PC6
#define UART8_TX_PIN PE1
#define UART1_RX_PIN PA10
#define UART2_RX_PIN PA3
#define UART3_RX_PIN PD9
#define UART4_RX_PIN PA1
#define UART5_RX_PIN PB5
#define UART6_RX_PIN PC7
#define UART7_RX_PIN PE7
#define UART8_RX_PIN PE0

#define I2C1_SCL_PIN PB8
#define I2C1_SDA_PIN PB9
#define I2C2_SCL_PIN PB10
#define I2C2_SDA_PIN PB11

#define SPI3_SCK_PIN PB3
#define SPI3_SDI_PIN PB4
#define SPI3_SDO_PIN PD6

#define SDIO_CK_PIN  PC12
#define SDIO_CMD_PIN PD2
#define SDIO_D0_PIN  PC8
#define SDIO_D1_PIN  PC9
#define SDIO_D2_PIN  PC10
#define SDIO_D3_PIN  PC11

#define ADC_VBAT_PIN PC0
#define ADC_CURR_PIN PC1
#define USB_DETECT_PIN PA8

#define LED0_PIN           PE3
#define LED1_PIN           PE2
#define LED2_PIN           PE4
#define BEEPER_PIN         PD15
#define LED_STRIP_PIN      PD14 // Shares TIM4 with the M11 and M12 servo outputs.
#define GYRO_1_CS_PIN      PD4
#define GYRO_1_EXTI_PIN    PD5
#define GYRO_1_ALIGN       CW90_DEG

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN, 1,  0 ) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN, 1,  1 ) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN, 1,  2 ) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN, 1,  3 ) \
    TIMER_PIN_MAP( 4, MOTOR5_PIN, 2,  4 ) \
    TIMER_PIN_MAP( 5, MOTOR6_PIN, 2,  5 ) \
    TIMER_PIN_MAP( 6, MOTOR7_PIN, 2,  6 ) \
    TIMER_PIN_MAP( 7, MOTOR8_PIN, 1,  7 ) \
    TIMER_PIN_MAP( 8, SERVO1_PIN, 1, -1 ) \
    TIMER_PIN_MAP( 9, SERVO2_PIN, 1, -1 ) \
    TIMER_PIN_MAP(10, SERVO3_PIN, 1, -1 ) \
    TIMER_PIN_MAP(11, SERVO4_PIN, 1, -1 ) \
    TIMER_PIN_MAP(12, SERVO5_PIN, 2, -1 ) \
    TIMER_PIN_MAP(13, SERVO6_PIN, 2, -1 ) \
    TIMER_PIN_MAP(14, LED_STRIP_PIN, 1, 12 ) \
    TIMER_PIN_MAP(15, BEEPER_PIN, 1, -1 )

#define ADC1_DMA_OPT   8
#define ADC3_DMA_OPT   9
#define TIMUP1_DMA_OPT 10
#define TIMUP3_DMA_OPT 11

#define ADC_INSTANCE         ADC1
#define GYRO_1_SPI_INSTANCE  SPI3
#define SDIO_USE_4BIT        1
#define SDIO_DEVICE          SDIODEV_1
// External compass connector. Cloud builds can select Magnetometers.
#ifndef CLOUD_BUILD
#define USE_MAG
#endif
#define MAG_I2C_INSTANCE     I2CDEV_1
#define BARO_I2C_INSTANCE    I2CDEV_2
#define DEFAULT_BARO_I2C_ADDRESS 119

#define BEEPER_INVERTED
#define DEFAULT_BLACKBOX_DEVICE      BLACKBOX_DEVICE_SDCARD
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE  249 // 40.2 A/V
#define DEFAULT_VOLTAGE_METER_SCALE  211

#if defined(USE_OSD_HD) || (!defined(CLOUD_BUILD) && !defined(USE_OSD_SD))
#define MSP_DISPLAYPORT_UART SERIAL_PORT_USART2
#endif
#define GPS_UART             SERIAL_PORT_USART3
#define SERIALRX_UART        SERIAL_PORT_USART6
#define ESC_SENSOR_UART      SERIAL_PORT_USART7
#define MSP_UART             SERIAL_PORT_USART8 // Onboard Bluetooth
