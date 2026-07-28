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

// NWBLUE_PROH757 - 30x30 multirotor flight controller built on the
// CubePilot CubeNode H757 module. STM32H757 dual-core (M7/M4); Betaflight
// runs standalone on M7, M4 left halted (default BOOT_C2 state). Build with:
//   make CONFIG=NWBLUE_PROH757 CUBEFW_CORE=CM7
// CUBEFW_CORE=CM7 selects the M7 startup/linker and the H757-specific
// PLL1 path (VOS0/480 MHz at 24 MHz HSE) without linking the CubeFramework
// bridge library.

#pragma once

#define FC_TARGET_MCU                       STM32H757

#define BOARD_NAME                          NWBLUE_PROH757
#define MANUFACTURER_ID                     NWBL

// CubeNode module uses a 24 MHz HSE crystal
#define SYSTEM_HSE_MHZ                      24

// === CAN - FDCAN1 broken out on J? (CubeNode CAN1 pins) ===
// PD0 = FDCAN1_RX, PD1 = FDCAN1_TX (AF9). The H7 platform header defaults
// ENABLE_CAN=1 so we don't need to set it here; we only need to supply the
// pin defines. FDCAN2/3 are not broken out on this carrier — the empty
// canHardware rows for those skip init via the !reg guard.
#define CAN1_TX_PIN                         PD1
#define CAN1_RX_PIN                         PD0

// === IMU - on-module ICM-45686 on SPI3 (mounted upright; no rotation) ===
// AP hwdef has ROTATION_ROLL_180 but empirical testing shows the chip is
// mounted right-side up — any non-identity rotation produces an inverted
// model in the Configurator and a wrong-sign pitch/roll response.
#define USE_GYRO
#define USE_ACC
#define USE_ACCGYRO_ICM45686

#define USE_SPI
#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN                        PC10
#define SPI3_SDI_PIN                        PC11
#define SPI3_SDO_PIN                        PC12

#define GYRO_1_SPI_INSTANCE                 SPI3
#define GYRO_1_CS_PIN                       PG15
#define GYRO_1_EXTI_PIN                     NONE
// Chip is mounted right-side up — no rotation needed.
#define GYRO_1_ALIGN                        CW0_DEG

// === Baro - on-carrier DPS368 (DPS310-compatible) on SPI3 ===
#define USE_BARO
#define USE_BARO_SPI_DPS310
#define BARO_SPI_INSTANCE                   SPI3
#define BARO_CS_PIN                         PF14

// === Mag - on-board IIS2MDC on internal I2C3 (LIS2MDL driver) ===
#define USE_MAG
#define USE_MAG_LIS2MDL
#define I2C3_SCL_PIN                        PA8
#define I2C3_SDA_PIN                        PC9
#define MAG_I2C_INSTANCE                    I2CDEV_3

// === External I2C - GPS connector J8 (compass in GPS module) ===
#define I2C4_SCL_PIN                        PD12
#define I2C4_SDA_PIN                        PD13

// === SD card on SDMMC2 (4-bit SDIO) ===
#define USE_SDCARD
#define USE_SDCARD_SDIO
#define SDIO_DEVICE                         SDIODEV_2
#define SDIO_USE_4BIT                       true
#define SDIO_CK_PIN                         PD6
#define SDIO_CMD_PIN                        PD7
#define SDIO_D0_PIN                         PB14
#define SDIO_D1_PIN                         PB15
#define SDIO_D2_PIN                         PB3
#define SDIO_D3_PIN                         PB4
#define DEFAULT_BLACKBOX_DEVICE             BLACKBOX_DEVICE_SDCARD

// === UARTs (carrier wiring matches AP hwdef SERIAL_ORDER) ===

// USART1 - ESC telemetry RX only (J10 pin 3)
#define UART1_RX_PIN                        PB7
#define ESC_SENSOR_UART                     SERIAL_PORT_USART1

// USART2 - VTX camera/telem RX only (J9 pin 5, user-assignable)
#define UART2_RX_PIN                        PA3

// UART4 - RC input on J11 (default serial RX)
#define UART4_TX_PIN                        PA0
#define UART4_RX_PIN                        PB8
#define SERIALRX_UART                       SERIAL_PORT_UART4

// USART6 - HD VTX MSP DisplayPort / SmartAudio (J9 pins 3-4)
#define UART6_TX_PIN                        PC6
#define UART6_RX_PIN                        PC7
#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART                SERIAL_PORT_USART6
#endif

// UART7 - TELEM1 (J4)
// Note: J4 also exposes RTS/CTS on PE6/PE5, but those pins do not have
// UART7 hardware-flow-control alternate functions on STM32H757. Run 8N1.
#define UART7_TX_PIN                        PE8
#define UART7_RX_PIN                        PE7

// UART8 - GPS connector (J8)
#define UART8_TX_PIN                        PE1
#define UART8_RX_PIN                        PE0
#ifdef USE_GPS
#define GPS_UART                            SERIAL_PORT_UART8
#endif

// === ADC ===
// VBAT divider on PF3 (ADC3 ch5): R19=200k top, R20=10k bottom -> 21:1.
// Current sense on PC2 (ADC1 ch12): passthrough from J10 pin 2 via 1k+100nF
// RC filter, so the scale depends on the external current sensor wired in.
#define ADC_VBAT_PIN                        PF3
#define ADC_CURR_PIN                        PC2
#define DEFAULT_VOLTAGE_METER_SOURCE        VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE        CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE         210
#define DEFAULT_CURRENT_METER_SCALE         240

// === LEDs (all active-low, anodes tied to +3.3V) ===
#define LED0_PIN                            PF12   // RGB notify red
#define LED1_PIN                            PF13   // RGB notify green
#define LED2_PIN                            PA4    // RGB notify blue

// Status LED (single amber on PC0) exposed as PINIO so the user can drive it
#define PINIO1_PIN                          PC0
#define PINIO1_CONFIG                       1
#define PINIO1_BOX                          40

// === Buzzer (active alarm on PC8) ===
#define BEEPER_PIN                          PC8

// === USB VBUS detect ===
// PA9 = VUSB through R57 (10k); 5V-tolerant.
#define USE_USB_DETECT
#define USB_DETECT_PIN                      PA9

// === Motors / Servos / LED strip ===
// AP hwdef PWM groups:
//   PWM 1-4 (motors) on TIM1     -> MOTOR1..MOTOR4
//   PWM 5-6 on TIM4              -> MOTOR5..MOTOR6 / SERVO outputs
//   PWM 7-8 on TIM3              -> MOTOR7..MOTOR8 / SERVO outputs
//   PWM 9   on TIM2              -> LED_STRIP_PIN (BF cannot use as 9th motor)
#define MOTOR1_PIN                          PE9    // TIM1_CH1
#define MOTOR2_PIN                          PE11   // TIM1_CH2
#define MOTOR3_PIN                          PE13   // TIM1_CH3
#define MOTOR4_PIN                          PE14   // TIM1_CH4
#define MOTOR5_PIN                          PD14   // TIM4_CH3
#define MOTOR6_PIN                          PD15   // TIM4_CH4
#define MOTOR7_PIN                          PB0    // TIM3_CH3
#define MOTOR8_PIN                          PB1    // TIM3_CH4

#define LED_STRIP_PIN                       PB10   // TIM2_CH3 - PWM9 in AP

// TIMER_PIN_MAP(idx, pin, occurrence, dma_opt)
// On H7 dma_opt is informational (DMAMUX picks streams), occurrence is the
// 1-based index of the timer alt-function for the pin in timer_stm32h7xx.c.
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN,    1,  0) /* TIM1_CH1 */ \
    TIMER_PIN_MAP( 1, MOTOR2_PIN,    1,  1) /* TIM1_CH2 */ \
    TIMER_PIN_MAP( 2, MOTOR3_PIN,    1,  2) /* TIM1_CH3 */ \
    TIMER_PIN_MAP( 3, MOTOR4_PIN,    1,  3) /* TIM1_CH4 */ \
    TIMER_PIN_MAP( 4, MOTOR5_PIN,    1,  4) /* TIM4_CH3 */ \
    TIMER_PIN_MAP( 5, MOTOR6_PIN,    1, -1) /* TIM4_CH4 - no DMA (UP shared) */ \
    TIMER_PIN_MAP( 6, MOTOR7_PIN,    2,  5) /* TIM3_CH3 (occ 2) */ \
    TIMER_PIN_MAP( 7, MOTOR8_PIN,    2, -1) /* TIM3_CH4 (occ 2) */ \
    TIMER_PIN_MAP( 8, LED_STRIP_PIN, 1,  6) /* TIM2_CH3 */

// DMA stream hints for ADC (H7 DMAMUX makes these optional)
#define ADC1_DMA_OPT                        9
#define ADC3_DMA_OPT                        10

#define DEFAULT_DSHOT_BITBANG               DSHOT_BITBANG_OFF
#define DEFAULT_GYRO_TO_USE                 GYRO_CONFIG_USE_GYRO_1
