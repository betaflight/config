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

// GEETAC591_V1 -- GEETA STM32C591 FC. Silkscreen reads "C593" but the placed
// part is an STM32C591RGT6 (LQFP64). C593 and C591 share an identical GPIO/USART
// alternate-function map, so the C591 platform target applies unchanged.
// Schematic: ~/src/ref/C591_2/STM32C593RGT6(0505).pdf

#define FC_TARGET_MCU                   STM32C591

#define BOARD_NAME                      GEETAC591_V1
#define MANUFACTURER_ID                 GEET

// HSE 8 MHz crystal on PH0/PH1 (Y1)
#define SYSTEM_HSE_MHZ                  8

// Config persists in the C591 internal flash (CONFIG_IN_FLASH, the default
// backend -- __config_start = 0x080FC000, a 16 KB region in the last two 8 KB
// pages of the 1 MB part). This avoids the early boot-time SPI3 read that the
// external flash (W25Q128) needs, which the C5 polled-SPI path corrupts before
// DMA is up. The W25Q128 still serves the blackbox.

// --- USB VCP -------------------------------------------------------------
// OTG FS on PA11 (D-) / PA12 (D+); USB VBUS sense on PC3.
#define USE_VCP
#define USB_DETECT_PIN                  PC3
#define USE_USB_DETECT

// --- Status LED ----------------------------------------------------------
#define LED0_PIN                        PA0

// --- UART pin map --------------------------------------------------------
// UART7 is enabled in the STM32C591 target. UART1 TX (PA15), UART3 RX (PB1)
// and UART7 TX (PA10) sit on pads added to the C5 serial driver pin tables.
#define UART1_TX_PIN                    PA15
#define UART1_RX_PIN                    PB7
#define UART2_TX_PIN                    PA2
#define UART2_RX_PIN                    PA3
#define UART3_TX_PIN                    PB10
#define UART3_RX_PIN                    PB1
#define UART4_TX_PIN                    PC10
#define UART4_RX_PIN                    PC11
#define UART5_TX_PIN                    PC12
#define UART5_RX_PIN                    PD2
#define UART7_TX_PIN                    PA10
#define UART7_RX_PIN                    PA8

// --- IMU on SPI1 ---------------------------------------------------------
// SPI1 SCK=PA5, MISO=PA6, MOSI=PA7 (AF5), CS=PA4, INT/DRDY=PC4.
// The board footprints an LSM6DSK320X (placed) alongside unpopulated
// ICM-42688P and MPU-6000 sites. Both the LSM6 and ICM-42688P drivers are
// compiled in (default in common_pre.h) so detection picks the part actually
// present by WHO_AM_I -- the sister C5 board silkscreened ICM but carried LSM6
// silicon, so do not assume the marking.
#define USE_ACC
#define USE_GYRO
#define USE_GYRO_EXTI
#define USE_ACCGYRO_LSM6DSK320X
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO_SPI_ICM42688P

#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN                    PA5
#define SPI1_SDI_PIN                    PA6
#define SPI1_SDO_PIN                    PA7

#define GYRO_1_SPI_INSTANCE             SPI1
#define GYRO_1_CS_PIN                   PA4
#define GYRO_1_EXTI_PIN                 PC4
// Placeholder orientation -- verify against the physical board and adjust.
#define GYRO_1_ALIGN                    CW0_DEG

// --- External flash: W25Q256JV on SPI3 -----------------------------------
// SPI3 SCK=PB3, MISO=PB4 (AF6), MOSI=PB5 (AF7 -- C5 quirk handled by the
// platform pinconfig), CS=PB6. The W25Q256 (JEDEC 0xEF4019) is detected by
// the generic m25p16 driver.
#define USE_SPI_DEVICE_3
#define SPI3_SCK_PIN                    PB3
#define SPI3_SDI_PIN                    PB4
#define SPI3_SDO_PIN                    PB5

#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_FLASH_W25Q128FV
#define FLASH_SPI_INSTANCE              SPI3
#define FLASH_CS_PIN                    PB6

#define USE_FLASHFS
#define USE_BLACKBOX

// --- OSD: AT7456E on SPI2 ------------------------------------------------
// SPI2 SCK=PB13, MISO=PB14, MOSI=PB15 (AF5), CS=PB12.
#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN                    PB13
#define SPI2_SDI_PIN                    PB14
#define SPI2_SDO_PIN                    PB15

#define USE_MAX7456
#define MAX7456_SPI_INSTANCE            SPI2
#define MAX7456_SPI_CS_PIN              PB12

#define USE_OSD
// AT7456E is an SD (analog) OSD; declare USE_OSD_SD so common_pre.h does not
// auto-select USE_OSD_HD and short-circuit init.c onto the MSP OSD path.
#define USE_OSD_SD

// --- Baro: LPS22DF on I2C1 -----------------------------------------------
// I2C1 SCL=PB8, SDA=PB9 (AF4) -- real hardware I2C1 (not I3C-as-I2C). The
// LPS22DF driver fixes the bus address to 0x5D. The same I2C1 bus carries the
// external compass on the GPS connector.
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C1_SCL_PIN                    PB8
#define I2C1_SDA_PIN                    PB9

#define USE_BARO
#define USE_BARO_LPS22DF
#define BARO_I2C_INSTANCE               I2CDEV_1

// --- Mag: external compass on I2C1 (GPS port) ----------------------------
#define USE_MAG
#define MAG_I2C_INSTANCE                I2CDEV_1

// --- Motors: TIM8 --------------------------------------------------------
// M1 PC6 / M2 PC7 / M3 PC8 / M4 PC9. On C591 each PCx pin appears in the
// timer table for both TIM3 (occurrence 1) and TIM8 (occurrence 2); the
// TIMER_PIN_MAP index is 1-based, so TIM8 is index 2. LED strip PA9
// (TIM1_CH2) is index 1.
#define MOTOR1_PIN                      PC6
#define MOTOR2_PIN                      PC7
#define MOTOR3_PIN                      PC8
#define MOTOR4_PIN                      PC9

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, PC6, 2, -1) \
    TIMER_PIN_MAP(1, PC7, 2, -1) \
    TIMER_PIN_MAP(2, PC8, 2, -1) \
    TIMER_PIN_MAP(3, PC9, 2, -1) \
    TIMER_PIN_MAP(4, PA9, 1, -1)

// --- LED strip -----------------------------------------------------------
#define USE_LED_STRIP
#define LED_STRIP_PIN                   PA9

// --- ADC: VBAT + current -------------------------------------------------
// PC2 = ADC channel 12 (VBAT divider), PC1 = ADC channel 11 (current sense).
// ADC1_DMA_OPT picks the first DMA spec for ADC1; the defaults make the
// external channels active (config.c forces .enabled = (source == ADC)).
#define USE_ADC
#define USE_ADC_INTERNAL
#define ADC_INSTANCE                    ADC1
#define ADC1_INSTANCE                   ADC1
#define ADC1_DMA_OPT                    0
#define ADC_VBAT_PIN                    PC2
#define ADC_CURR_PIN                    PC1
#define DEFAULT_VOLTAGE_METER_SOURCE    VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE    CURRENT_METER_ADC

// --- Buzzer --------------------------------------------------------------
// Passive buzzer driven by PB2 via Q1 (MMBT3904 NPN low-side, base pulled to
// GND) -- active high, idle-safe, so not inverted.
#define USE_BEEPER
#define BEEPER_PIN                      PB2

// --- PINIO: VTX/O4 power switch + camera switch --------------------------
// PC0 gates VTX/air-unit power; PC15 selects CAM1/CAM2 through the video mux.
// Output push-pull, active high by default -- verify switch polarity on the
// bench and flip the *_CONFIG value (to 129) if a rail is inverted.
#define PINIO1_PIN                      PC0
#define PINIO1_CONFIG                   1
#define PINIO2_PIN                      PC15
#define PINIO2_CONFIG                   1

// --- Deferred ------------------------------------------------------------
// Analog camera control: PA1 (TIM2_CH2). The camera-control PWM backend
// (camera_control_stm32.c) is not yet compiled for the STM32C5 platform, so
// the feature is left off until that support lands.
// CAN/DroneCAN: FDCAN1 on PC13 (TX) / PC14 (RX), SIT1051 silent on PE2.
// Gyro CLKIN: PB0 (TIM3_CH3) routes an external clock to the IMU.
// None of these are enabled in this first bring-up config.
