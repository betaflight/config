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
#define SYSTEM_HSE_MHZ      16
#define BOARD_NAME          ARK_FPV
#define MANUFACTURER_ID     ARKE

#define USE_CONFIG_TARGET_PREINIT
#define VDD_3V3_SENSORS1_EN PI11
#define VDD_3V3_SD_CARD_EN  PC13

#define LED0_PIN            PE5
#define LED1_PIN            PE4
#define LED2_PIN            PE3

#define USE_BEEPER
#define BEEPER_PIN          PF9
#define USE_USB_DETECT
#define USB_DETECT_PIN      PA9

// PINIO Box Config -- VTX Pit Mode
#define PERIPH_12V_EN       PG4
#define PINIO1_PIN          PERIPH_12V_EN
#define PINIO1_CONFIG       129
#define PINIO1_BOX          40

// TODO: useful for...? Suggestions?
// PINIO Box Config -- USER1
// #define MOTOR9_PIN          PD12     // TIM4_CH1
// #define PINIO2_PIN          MOTOR9_PIN
// #define PINIO2_CONFIG       1
// #define PINIO2_BOX          40

// GPS1 UART
#ifndef USE_GPS
#define USE_GPS
#endif
#define UART1_TX_PIN         PB6
#define UART1_RX_PIN         PB7
#define GPS_UART             SERIAL_PORT_UART1
// GPS1 I2C
#define I2C1_SCL_PIN         PB8
#define I2C1_SDA_PIN         PB9

// DJI HDL (RX only)
#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PA3

// Debug
#define UART3_TX_PIN         PD8
#define UART3_RX_PIN         PD9
#define MSP_UART             SERIAL_PORT_UART3

// ESC Telemetry (RX only)
#define UART4_TX_PIN         PH13
#define UART4_RX_PIN         PH14
#define ESC_SENSOR_UART      SERIAL_PORT_UART4

// VTX
#define UART5_TX_PIN         PC12
#define UART5_RX_PIN         PD2
#define MSP_DISPLAYPORT_UART SERIAL_PORT_UART5

// RC Input
#define UART6_TX_PIN         PC6
#define UART6_RX_PIN         PC7
#define SERIALRX_UART        SERIAL_PORT_UART6

// Telem
#define UART7_TX_PIN         PE8
#define UART7_RX_PIN         PF6
#define UART7_RTS_PIN        PF8
#define UART7_CTS_PIN        PE10

// Baro I2C bus
#define USE_BARO
#define USE_BARO_BMP388
#define I2C2_SCL_PIN        PF1
#define I2C2_SDA_PIN        PF0
#define BARO_I2C_INSTANCE   I2CDEV_2

// Compass I2C bus
#ifndef USE_MAG
#define USE_MAG
#endif
#ifndef USE_MAG_LIS2MDL
#define USE_MAG_LIS2MDL
#endif
#define I2C4_SCL_PIN        PF14
#define I2C4_SDA_PIN        PF15
#define MAG_I2C_INSTANCE    I2CDEV_4
#define MAG_ALIGN           CW180_DEG

// IIM42653 on SPI1
#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_IIM42653
#define USE_SPI
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN        PA5
#define SPI1_SDI_PIN        PG9
#define SPI1_SDO_PIN        PB5
#define USE_EXTI
#define GYRO_1_SPI_INSTANCE SPI1
#define GYRO_1_EXTI_PIN     PF2
#define GYRO_1_CS_PIN       PI9
#define GYRO_1_ALIGN        CW90_DEG_FLIP

// External SPI port (OSD or IMU)
#define SPI6_SCK_PIN        PB3
#define SPI6_SDI_PIN        PA6
#define SPI6_SDO_PIN        PG14

// SD card
#define USE_SDCARD
#define USE_SDCARD_SDIO
#define USE_SDIO_PULLUP
#define SDIO_CLOCK_DIV      2
#define SDIO_DEVICE         SDIODEV_2
#define SDIO_USE_4BIT       true
#define SDIO_CK_PIN         PD6
#define SDIO_CMD_PIN        PD7
#define SDIO_D0_PIN         PB14
#define SDIO_D1_PIN         PB15
#define SDIO_D2_PIN         PG11
#define SDIO_D3_PIN         PB4
#define DEFAULT_BLACKBOX_DEVICE BLACKBOX_DEVICE_SDCARD

// BAT voltage ADC
#define ADC_VBAT_PIN        PB0
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE  210
// BAT current ADC
#define ADC_CURR_PIN        PC2
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE  120
// 3V3 ADC
#define ADC_EXTERNAL1_PIN   PA0
// 5V ADC
#define ADC_EXTERNAL2_PIN   PB1
// 12V ADC
#define ADC_EXTERNAL3_PIN   PA4

// Motor configuration
#define USE_TIMER_MAP_PRINT
#define MOTOR1_PIN          PI0    // PI0  : TIM5_CH4
#define MOTOR2_PIN          PH12   // PH12 : TIM5_CH3
#define MOTOR3_PIN          PH11   // PH11 : TIM5_CH2
#define MOTOR4_PIN          PH10   // PH10 : TIM5_CH1
#define MOTOR5_PIN          PI5    // PI5  : TIM8_CH1
#define MOTOR6_PIN          PI6    // PI6  : TIM8_CH2
#define MOTOR7_PIN          PI7    // PI7  : TIM8_CH3
#define MOTOR8_PIN          PI2    // PI2  : TIM8_CH4

// TIMER_PIN_MAP(mot_idx, pin, occurance, dma_opt)
// NOTE: dma_opt unnecessary since H7 has dmamux
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN, 1, 0) \
    TIMER_PIN_MAP(1, MOTOR2_PIN, 1, 1) \
    TIMER_PIN_MAP(2, MOTOR3_PIN, 1, 2) \
    TIMER_PIN_MAP(3, MOTOR4_PIN, 1, 3) \
    TIMER_PIN_MAP(4, MOTOR5_PIN, 1, 4) \
    TIMER_PIN_MAP(5, MOTOR6_PIN, 1, 5) \
    TIMER_PIN_MAP(6, MOTOR7_PIN, 1, 6) \
    TIMER_PIN_MAP(7, MOTOR8_PIN, 1, 7)

// DMA stream assignment
#define TIMUP8_DMA_OPT      10
#define TIMUP5_DMA_OPT      11
#define ADC1_DMA_OPT        12
#define ADC3_DMA_OPT        13
#define SPI1_TX_DMA_OPT     14
#define SPI1_RX_DMA_OPT     15

// Remaining unmapped signals (no use in betaflight?)
// TODO: 12v pgood   : PE15 --> 12V regulator PGOOD
// TODO: 5v pgood    : PF13 --> 5V regulator PGOOD
// TODO: 5V_ON_BATn  : PG1  --> Diode status signal (5V from USB or 5V from regulator)
// TODO: IMU heater  : PB10 --> TIM2_CH3 for PWM resistor IMU temperature control
