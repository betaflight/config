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

#define FC_TARGET_MCU           STM32H730

#define BOARD_NAME              SPRACINGH7EVO
#define MANUFACTURER_ID         SPRO

#define TARGET_BOARD_IDENTIFIER "SP7V"
#define USBD_PRODUCT_STRING     "SPRacingH7EVO"

#define FC_VMA_ADDRESS          0x90100000

#define EEPROM_SIZE             8192

#define USE_SPRACING_PERSISTENT_RTC_WORKAROUND

// No physical buttons, BIND pad on bottom can be connected though a 10k resistor and switch to V3P3+
#define USE_BUTTONS
#define BUTTON_A_PIN            PC14
#define BUTTON_A_PIN_INVERTED
#define BUTTON_B_PIN            PC14
#define BUTTON_B_PIN_INVERTED

// Device has 2x flash chips in parallel using a single CS pin, initial support is for the first flash chip only.
#define USE_OCTOSPI
#define USE_OCTOSPI_DEVICE_1

#define USE_SPI

// On mezzanine expansion connector, for external flash for logging, second gyro, sx1280, etc
#define USE_SPI_DEVICE_1
#define SPI1_SCK_PIN            PA5
#define SPI1_SDI_PIN            PB4
#define SPI1_SDO_PIN            PB5
#define SPI1_NSS_PIN            PA15

#define USE_SPI_DEVICE_2
#define SPI2_SCK_PIN            PD3
#define SPI2_SDI_PIN            PB14
#define SPI2_SDO_PIN            PB15
#define SPI2_NSS_PIN            PB12

// SX1280 not installed, signals on mezzanine connector
#define SX1280_BUSY_PIN         PC7
#define SX1280_DIO1_PIN         PD4
#define SX1280_DIO2_PIN         NONE
#define SX1280_DIO3_PIN         NONE

#define USE_FLASH_MEMORY_MAPPED
#define FLASH_OCTOSPI_INSTANCE  OCTOSPI1
#define CONFIG_IN_MEMORY_MAPPED_FLASH
#define USE_FIRMWARE_PARTITION

#define USE_SDCARD_SDIO
#define SDCARD_DETECT_PIN       PC13
#define SDCARD_DETECT_INVERTED
#define SDIO_DEVICE             SDIODEV_1
#define SDIO_USE_4BIT           1
#define SDIO_CK_PIN             PC12
#define SDIO_CMD_PIN            PD2
#define SDIO_D0_PIN             PC8
#define SDIO_D1_PIN             PC9
#define SDIO_D2_PIN             PC10
#define SDIO_D3_PIN             PC11

// OCTOSPI pins excluded, as bootloader runs firmware in memory mapped mode
#define TARGET_IO_PORTA         0xffff
#define TARGET_IO_PORTB         (0xffff & ~(BIT(2)|BIT(6)))
#define TARGET_IO_PORTC         0xffff
#define TARGET_IO_PORTD         (0xffff & ~(BIT(11)|BIT(12)|BIT(13)))
#define TARGET_IO_PORTE         (0xffff & ~(BIT(2)|BIT(7)|BIT(8)|BIT(9)|BIT(10)))
#define TARGET_IO_PORTF         0xffff
#define TARGET_IO_PORTG         0xffff
#define TARGET_IO_PORTH         0xffff

#define USE_I2C

#define I2C1_SCL_PIN            NONE
#define I2C1_SDA_PIN            NONE

// on GPS connector and mezzanine expansion connector
// 10k pull-ups installed
#define USE_I2C_DEVICE_2
#define I2C2_SCL_PIN            PB10
#define I2C2_SDA_PIN            PB11

#define I2C3_SCL_PIN            NONE
#define I2C3_SDA_PIN            NONE

#define I2C4_SCL_PIN            NONE
#define I2C4_SDA_PIN            NONE


#define MAG_I2C_INSTANCE        (I2CDEV_2)
#define BARO_I2C_INSTANCE       (I2CDEV_2)

#define USE_MPU_DATA_READY_SIGNAL
#define ENSURE_MPU_DATA_READY_IS_LOW


#define DEFAULT_RX_FEATURE            FEATURE_RX_SERIAL
#define DEFAULT_FEATURES              (FEATURE_TELEMETRY | FEATURE_LED_STRIP)

#define ADC3_DMA_OPT                  10
#define ADC_INSTANCE                  ADC3
#define ADC1_INSTANCE                 ADC1
#define ADC3_INSTANCE                 ADC3

// Hardware ADC pins and intended usage
#define CURRENT_METER_1_ADC_PIN       PC3
#define CURRENT_METER_1_ADC_INSTANCE  ADC3
#define CURRENT_METER_2_ADC_PIN       PC1
#define CURRENT_METER_2_ADC_INSTANCE  ADC3
#define ADC_EXTERNAL1_PIN             PC2
#define ADC_EXTERNAL1_INSTANCE        ADC3
#define VBAT_ADC_INSTANCE             ADC3
// Video IN/Out ADC pins are N/C, reserved in schematic
#define VIDEO_IN_ADC_PIN              PC5
#define VIDEO_OUT_ADC_PIN             PC4

// BF usage of ADC pins
#define ADC_VBAT_PIN         PC0
#define ADC_RSSI_PIN         PC1 // current meter 2 on 4in1ESC2 connector
#define ADC_CURR_PIN         PC3 // current meter 1 on 4in1ESC2 connector
#define ADC_EXTERNAL1_PIN    PC2 // on mezannine connector

#define VTX_ENABLE_PIN                PC15
#define PINIO1_PIN                    VTX_ENABLE_PIN

#define USE_ACC
#define USE_ACC_SPI_ICM42605
#define USE_ACC_SPI_ICM42688P
#define USE_GYRO
#define USE_GYRO_SPI_ICM42605
#define USE_GYRO_SPI_ICM42688P
#define USE_BARO
#define USE_BARO_BMP388
#define USE_MAG
#define USE_MAG_HMC5883
#define USE_MAG_QMC5883
#define USE_FLASH_W25Q128FV
#define USE_SDCARD
// The target has a specific set of pads for the LED strip.
#ifndef USE_LED_STRIP
#define USE_LED_STRIP
#endif

// Pin layout supports SPRacingPixelOSD and signals reserved in schematic.
#define VIDEO_IN_ADC_PIN              PC5
#define VIDEO_OUT_ADC_PIN             PC4
#define SPRACING_PIXEL_OSD_BLACK_PIN                    PE12
#define SPRACING_PIXEL_OSD_WHITE_PIN                    PE13
#define SPRACING_PIXEL_OSD_MASK_ENABLE_PIN              PE14
#define SPRACING_PIXEL_OSD_WHITE_SOURCE_SELECT_PIN      PE15

#define SPRACING_PIXEL_OSD_SYNC_IN_PIN                  PE11
#define SPRACING_PIXEL_OSD_SYNC_OUT_PIN                 PA8

#define SPRACING_PIXEL_OSD_WHITE_SOURCE_PIN             PA4
#define SPRACING_PIXEL_OSD_VIDEO_THRESHOLD_DEBUG_PIN    PA5 // used by SPI1_CLK on mezzanine connector

#define SPRACING_PIXEL_OSD_PIXEL_DEBUG_1_PIN            PE5 // led 0
#define SPRACING_PIXEL_OSD_PIXEL_DEBUG_2_PIN            PE6 // led 1
#define SPRACING_PIXEL_OSD_PIXEL_GATING_DEBUG_PIN       PB0 // pwm 6
#define SPRACING_PIXEL_OSD_PIXEL_BLANKING_DEBUG_PIN     PB1 // pwm 5

#define BEEPER_INVERTED
#define BEEPER_PIN           PE4

// RX and TX on "RX" connector, RX on "HD-VTX" connector
#define UART1_TX_PIN         PA9
#define UART1_RX_PIN         PA10

// on mezzanine connector
#define UART2_TX_PIN         PD5
#define UART2_RX_PIN         PD6

// RX and TX on "HD-VTX" connector
#define UART3_TX_PIN         PD8
#define UART3_RX_PIN         PD9

// for ESC TLM, with series 10k resistor
#define UART5_TX_PIN         NONE
#define UART5_RX_PIN         PB13 // TX signal pin-swapped

// on mezzanine connector (other useful signals on these pins too)
#define UART4_TX_PIN         PB9
#define UART4_RX_PIN         PB8

#define UART6_TX_PIN         NONE
#define UART6_RX_PIN         NONE

#define UART7_TX_PIN         NONE
#define UART7_RX_PIN         NONE

// on GPS connector
#define UART8_TX_PIN         PE1
#define UART8_RX_PIN         PE0

#define UART9_TX_PIN         NONE
#define UART9_RX_PIN         NONE

#define UART10_TX_PIN        NONE
#define UART10_RX_PIN        NONE

// 8Mbps CAN transceiver installed with CAN termination, CANL/CANH available on GPS, mezzanine and servo connectors.
#define FDCAN1_RX            PD0
#define FDCAN2_RX            PD1

#define LED0_PIN             PE5
#define LED1_PIN             PE6
#define LED2_PIN             NONE

#define SPEKTRUM_RX_BIND_PIN NONE
#define RX_BIND_PLUG_PIN     NONE

#define RX_SPI_CS_PIN        PA15
//#define RX_SPI_EXTI_PIN      PD4
#define RX_SPI_BIND_PIN      NONE
#define RX_SPI_LED_PIN       NONE
#define RX_SPI_EXPRESSLRS_RESET_PIN PD10
#define RX_SPI_EXPRESSLRS_BUSY_PIN PC7

#define GYRO_1_EXTI_PIN      PE3
#define GYRO_2_EXTI_PIN      PC15 // on mezzanine connector
#define GYRO_1_CS_PIN        PB12
#define GYRO_2_CS_PIN        PA15 // on mezzanine connector

#define MOTOR1_PIN           PA3
#define MOTOR2_PIN           PA2
#define MOTOR3_PIN           PA1
#define MOTOR4_PIN           PA0
#define MOTOR5_PIN           PB1
#define MOTOR6_PIN           PB0
#define MOTOR7_PIN           PA7
#define MOTOR8_PIN           PA6
#define LED_STRIP_PIN        PC6

// Index, Pin, 1-based occurrence of pin in fullTimerHardware, dma opt (use -1 for no DMA)
// See timerio.c and timer_stm32h7xx.c

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA3 , 2,  7 ) \
    TIMER_PIN_MAP( 1, PA2 , 2,  6 ) \
    TIMER_PIN_MAP( 2, PA1 , 2,  5 ) \
    TIMER_PIN_MAP( 3, PA0 , 2,  4 ) \
    TIMER_PIN_MAP( 4, PB1 , 2,  1 ) \
    TIMER_PIN_MAP( 5, PB0 , 2,  0 ) \
    TIMER_PIN_MAP( 6, PA7 , 2,  3 ) \
    TIMER_PIN_MAP( 7, PA6 , 1,  2 ) \
    TIMER_PIN_MAP( 8, PC6 , 2,  8 )

#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD

#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC

#define GYRO_1_SPI_INSTANCE SPI2
#define GYRO_1_ALIGN CW270_DEG_FLIP

// Prevent flash being used for logs as target requires EXST
#ifdef USE_FLASH
#undef USE_FLASH
#endif
