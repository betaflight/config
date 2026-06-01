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

// OPENC5A3V1 — open FC bring-up board, STM32C5A3RG in LQFP64. PCB shares
// the TANTOF405 layout (schematic ~/src/ref/C591/C591-V1.pdf, rev V1.1)
// with the C5A3 die substituted for the C591RGT6. Pin-compatible swap;
// the two dies differ only in the crypto block.
//
// Flashing: ST-LINK SWD on PA13/PA14. The chip's built-in System DFU is
// available as a manual fallback (BOOT0 high + USB-C replug).

#define FC_TARGET_MCU                   STM32C5A3

#define BOARD_NAME                      OPENC5A3V1
#define MANUFACTURER_ID                 CUST

// HSE 8 MHz crystal on PH0/PH1 (Y1). system_stm32c5xx.c picks the
// matching PSI reference selector for HSE_VALUE.
#define SYSTEM_HSE_MHZ                  8

// Config in W25Q64.
#define CONFIG_IN_EXTERNAL_FLASH

// --- USB VCP -------------------------------------------------------------
// USB DRD FS on PA11 (DM) / PA12 (DP) — only DRD FS pin pair on this die.
// VBUS sense on PC5 (Q1 voltage divider on the schematic). Lets BF
// distinguish powered-on-USB from battery-only boots.
#define USE_VCP
#define USB_DETECT_PIN                  PC5
#define USE_USB_DETECT

// --- Status LEDs ---------------------------------------------------------
// LED0 = LED-MCU on PB4, LED1 = LED-GYRO on PC0 (V1.1 revision).
#define LED0_PIN                        PB4
#define LED1_PIN                        PC0

// --- UART pin map --------------------------------------------------------
// USART2 (PA2/PA3): on-board JST to a Prolific PL2303 USB-serial cable
// (host /dev/ttyUSB0). Reachable before USB VCP enumerates. PA3 also
// drives the SBUS-inverter mosfet (Q2) on the schematic.
//
// USART1 on PB6/PB7. I2C1 lives on PB8/PB9 (see baro block below) so
// no contention between UART1 and I2C1 on this board.
//
// USART6 isn't enabled by the shared STM32C5A3/target.h (it mirrors
// C591 which only declares UART1..5), so opt in here.
#define USE_UART6

#define UART1_TX_PIN                    PB6
#define UART1_RX_PIN                    PB7
#define UART2_TX_PIN                    PA2
#define UART2_RX_PIN                    PA3
#define UART3_TX_PIN                    PB10
#define UART3_RX_PIN                    PC4
#define UART4_TX_PIN                    PA0
#define UART4_RX_PIN                    PA1
#define UART5_TX_PIN                    PC12
#define UART5_RX_PIN                    PD2
#define UART6_TX_PIN                    PC6
#define UART6_RX_PIN                    PC7

// --- IMU: ICM-42688P on SPI1 ---------------------------------------------
// SCK=PA5, SDI(MISO)=PA6, SDO(MOSI)=PA7, CS=PA4 (the SPI1 hardware NSS
// pin used as software-managed CS), INT1/DRDY=PB2. SPI1 AF5 on all four
// data pins.
//
// Status (2026-05-31): SPI controller verified working end-to-end via
// SWD-driven manual WHO_AM_I transaction (CR1.SPE+CSTART, TSIZE=2,
// TXDR=0xF5,0x00). MISO stays at the pull-up idle level (RXDR=0xFF for
// both byte slots) — chip is silent at the wire. Software path is
// complete; the chip itself needs hardware-level verification (VDDIO,
// CSB routing, soldering).
#define USE_ACC
#define USE_GYRO
#define USE_GYRO_EXTI

#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN                    PA5
#define SPI1_SDI_PIN                    PA6
#define SPI1_SDO_PIN                    PA7

#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define ICM42688P_SPI_INSTANCE          SPI1
#define ICM42688P_CS_PIN                PA4
#define ICM42688P_EXTI_PIN              PB2
#define ICM42688P_ALIGN                 CW0_DEG

#define GYRO_1_SPI_INSTANCE             ICM42688P_SPI_INSTANCE
#define GYRO_1_CS_PIN                   ICM42688P_CS_PIN
#define GYRO_1_EXTI_PIN                 ICM42688P_EXTI_PIN
#define GYRO_1_ALIGN                    ICM42688P_ALIGN

// USE_VIRTUAL_GYRO would short-circuit mpuDetect() in gyro_init.c — the
// real driver path can't be exercised while it's defined. Keep removed.

// --- External flash: W25Q64JV on SPI3 ------------------------------------
// SPI3 SCK=PC10, MISO=PC11, MOSI=PB5 (all AF6). CS=PA15. Chip is a
// Winbond W25Q64JVSSIQ (8 MiB NOR, JEDEC ID 0xEF4017) — handled by the
// flash_m25p16.c driver which despite the name covers the broader
// Winbond / Spansion SPI-NOR family up to 1 Gbit.
//
// With CONFIG_IN_EXTERNAL_FLASH + USE_FLASHFS, drivers/flash/flash.c
// auto-partitions the chip: a CONFIG partition at the top sized to
// EEPROM_SIZE (8 KiB rounded up to one 4 KiB sector = 2 sectors), and
// the remaining ~8 MiB as the FLASHFS partition for blackbox logs.
//
// Status (2026-06-01): the chip is silent on the wire — SWD-driven
// JEDEC read returns 0xFF/0xFF/0xFF, same chip-silent pattern as the
// ICM-42688P. Both peripherals sit on the VDD3V3_SENSOR rail per the
// schematic, so they share whatever the underlying hardware issue
// is. Software path is complete pending hardware verification.
#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN                    PC10
#define SPI3_SDI_PIN                    PC11
#define SPI3_SDO_PIN                    PB5

#define USE_FLASH
#define USE_FLASH_M25P16
#define FLASH_SPI_INSTANCE              SPI3
#define FLASH_CS_PIN                    PA15

#define USE_FLASHFS
#define USE_BLACKBOX

// --- OSD: AT7456E on SPI2 ------------------------------------------------
// SPI2 PB13 SCK / PB14 MISO / PB15 MOSI / PB12 CS. AT7456E sits on the
// MCU 3V3 rail (not VDD3V3_SENSOR) so it's the rail-isolation probe
// alongside the sensor-rail SPI1/SPI3 chips.
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN                    PB13
#define SPI2_SDI_PIN                    PB14
#define SPI2_SDO_PIN                    PB15

#define USE_MAX7456
#define MAX7456_SPI_INSTANCE            SPI2
#define MAX7456_SPI_CS_PIN              PB12

#define USE_OSD
// AT7456E is an SD-only OSD. Declare USE_OSD_SD so common_pre.h does
// not auto-define USE_OSD_HD (which would default vcd_video_system
// to VIDEO_SYSTEM_HD and make init.c short-circuit to the MSP OSD
// path without ever running max7456Init).
#define USE_OSD_SD

// --- Baro: SPA06-003 on I2C1 ---------------------------------------------
// I2C1 SCL=PB8, SDA=PB9 (AF4 on C5A3). SPA06-003 sits on the
// VDD3V3_SENSOR rail, so it's the second independent rail probe alongside
// AT7456E. No SPA06 driver in BF yet; reuse the BMP280 driver which
// shares the I2C address (0x76) — even if SPA06 returns a different chip
// ID and detection fails, an ACK on the address shows the rail is
// alive and the I2C controller talks to the wire.
#define USE_BARO_BMP280
#define USE_BARO_I2C_BMP280
#define BARO_I2C_INSTANCE               I2CDEV_1
#define I2C1_SCL_PIN                    PB8
#define I2C1_SDA_PIN                    PB9

// --- Motors: DShot bitbang -----------------------------------------------
// M1 PA8 TIM1_CH1, M2 PA9 TIM1_CH2 (port A, one GPDMA channel).
// M3 PC9 TIM8_CH4, M4 PC8 TIM8_CH3 (port C, second GPDMA channel).
// PC8/PC9 also alias to TIM3_CH3/CH4 (occurrence 1) but the board
// wires them to TIM8 (occurrence 2). dmaopt = -1: bitbang uses
// per-port GPDMA on BSRR, channel auto-allocated.
#define MOTOR1_PIN                      PA8
#define MOTOR2_PIN                      PA9
#define MOTOR3_PIN                      PC9
#define MOTOR4_PIN                      PC8

// LED strip on PB3 (TIM2_CH2). Servo outputs on PB0/PB1 (TIM3_CH3/CH4)
// — runtime-assigned via `servo` CLI, so just expose the pins through
// TIMER_PIN_MAPPING. Motors took PC8/PC9 to TIM8 (occurrence 2), so
// TIM3 is free for servos.
#define USE_LED_STRIP
#define LED_STRIP_PIN                   PB3

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, PA8, 1, -1) \
    TIMER_PIN_MAP(1, PA9, 1, -1) \
    TIMER_PIN_MAP(2, PC9, 2, -1) \
    TIMER_PIN_MAP(3, PC8, 2, -1) \
    TIMER_PIN_MAP(4, PB0, 1, -1) \
    TIMER_PIN_MAP(5, PB1, 1, -1) \
    TIMER_PIN_MAP(6, PB3, 1, -1)

// 4 kHz PID at the 8 kHz gyro rate — matches NUCLEOC562 / OPENN657V1
// bring-up defaults; can be raised once the platform settles.
#define DEFAULT_PID_PROCESS_DENOM       2

// --- Mag still synthetic -------------------------------------------------
#define USE_BARO
#define USE_MAG
#define USE_VIRTUAL_MAG

// --- ADC: VBAT + current sense -------------------------------------------
// VBAT divider on PC2 (ADC1 channel), current shunt amp on PC1.
#define ADC_VBAT_PIN                    PC2
#define ADC_CURR_PIN                    PC1
#define ADC1_INSTANCE                   ADC1

// --- Buzzer --------------------------------------------------------------
// Passive buzzer driven by PC3 via Q3 MOSFET on the schematic.
#define USE_BEEPER
#define BEEPER_PIN                      PC3
#define BEEPER_INVERTED

// --- Camera control ------------------------------------------------------
// PC13 — single-wire camera OSD menu control. C5 platform doesn't yet
// implement cameraControlHardwarePwmInit; defer until that lands.
// #define CAMERA_CONTROL_PIN              PC13
