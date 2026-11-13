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

#define FC_TARGET_MCU                  STM32H743
#define SYSTEM_HSE_MHZ                 8

#define BOARD_NAME                     TUSTIN_MACH
#define MANUFACTURER_ID                TUST

// ICM-45686-P on SPI3
#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_ICM45686

// ICP-20100 pressure sensor on I2C2
#define USE_BARO
#define USE_BARO_ICP20100

// IST8310 on I2C2
#define USE_MAG
#define USE_MAG_IST8310

// FM25V02A SPI F-RAM on SPI4
#define USE_FLASH
#define USE_FLASH_FM25V02A

// AT7456E analog OSD on SPI1
#define USE_OSD_SD
#define USE_MAX7456

// microSD card on SDMMC2
#define USE_SDCARD
#define USE_SDCARD_SDIO

#define MOTOR1_PIN                     PE14
#define MOTOR2_PIN                     PE13
#define MOTOR3_PIN                     PE11
#define MOTOR4_PIN                     PE9
#define MOTOR5_PIN                     PB1
#define MOTOR6_PIN                     PB0
#define MOTOR7_PIN                     PD12
#define MOTOR8_PIN                     PD13

#define UART1_TX_PIN                   PA9
#define UART1_RX_PIN                   PA10
#define UART2_TX_PIN                   PA2
#define UART2_RX_PIN                   PA3
#define UART3_TX_PIN                   PD8
#define UART3_RX_PIN                   PD9
#define UART4_TX_PIN                   PA0
#define UART4_RX_PIN                   PA1
#define UART5_TX_PIN                   PB6
#define UART5_RX_PIN                   PB5
#define UART6_TX_PIN                   PC6
#define UART6_RX_PIN                   PC7
#define UART7_RX_PIN                   PE7

#define I2C1_SCL_PIN                   PB8
#define I2C1_SDA_PIN                   PB9
#define I2C2_SCL_PIN                   PB10
#define I2C2_SDA_PIN                   PB11

#define SPI1_SCK_PIN                   PA5
#define SPI1_SDI_PIN                   PA6
#define SPI1_SDO_PIN                   PA7
#define SPI2_SCK_PIN                   PD3
#define SPI2_SDI_PIN                   PC2
#define SPI2_SDO_PIN                   PC3
#define SPI3_SCK_PIN                   PC10
#define SPI3_SDI_PIN                   PC11
#define SPI3_SDO_PIN                   PC12

#define SPI4_SCK_PIN                   PE12
#define SPI4_SDI_PIN                   PE5
#define SPI4_SDO_PIN                   PE6

#define LED0_PIN                       PE2 // Green
#define LED1_PIN                       PE3 // Red
#define LED2_PIN                       PE4 // Blue
#define LED0_INVERTED
#define LED1_INVERTED
#define LED2_INVERTED

#define ADC_VBAT_PIN                   PC0
#define ADC_CURR_PIN                   PC1

#define CAN1_TX_PIN                    PD1
#define CAN1_RX_PIN                    PD0
#define CAN1_SILENT_PIN                PD11

#define MAX7456_SPI_CS_PIN             PB12
#define GYRO_1_CS_PIN                  PA15
#define GYRO_1_EXTI_PIN                PB7

// Unused BMI088 footprint on SPI2: gyro CS PD5, gyro EXTI PC15, accel CS PD4.
// BMI088 is intentionally not enabled; keep these pins documented for PCB reference.
#define FLASH_CS_PIN                   PD10
#define USB_DETECT_PIN                 PA8

#define SDIO_DEVICE                    SDIODEV_2
#define SDIO_USE_4BIT                  1
#define SDIO_CK_PIN                    PD6
#define SDIO_CMD_PIN                   PD7
#define SDIO_D0_PIN                    PB14
#define SDIO_D1_PIN                    PB15
#define SDIO_D2_PIN                    PB3
#define SDIO_D3_PIN                    PB4
#define SDCARD_DETECT_PIN              NONE

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, MOTOR1_PIN, 1, 0 ) \
    TIMER_PIN_MAP( 1, MOTOR2_PIN, 1, 1 ) \
    TIMER_PIN_MAP( 2, MOTOR3_PIN, 1, 2 ) \
    TIMER_PIN_MAP( 3, MOTOR4_PIN, 1, 3 ) \
    TIMER_PIN_MAP( 4, MOTOR5_PIN, 2, 4 ) \
    TIMER_PIN_MAP( 5, MOTOR6_PIN, 2, 5 ) \
    TIMER_PIN_MAP( 6, MOTOR7_PIN, 1, 6 ) \
    TIMER_PIN_MAP( 7, MOTOR8_PIN, 1, 7 )

#define ADC1_DMA_OPT                   8
#define ADC3_DMA_OPT                   9
#define TIMUP1_DMA_OPT                 10
#define TIMUP3_DMA_OPT                 11
#define TIMUP4_DMA_OPT                 12

#define GYRO_1_SPI_INSTANCE            SPI3
#define MAG_I2C_INSTANCE               I2CDEV_2
#define BARO_I2C_INSTANCE              I2CDEV_2
#define MAX7456_SPI_INSTANCE           SPI1
#define FLASH_SPI_INSTANCE             SPI4
#define DEFAULT_BARO_DEVICE            BARO_ICP20100

#define ADC_INSTANCE                   ADC1
#define DEFAULT_VOLTAGE_METER_SOURCE   VOLTAGE_METER_ADC
#define DEFAULT_VOLTAGE_METER_SCALE    210
#define DEFAULT_CURRENT_METER_SOURCE   CURRENT_METER_ADC
#define DEFAULT_BLACKBOX_DEVICE        BLACKBOX_DEVICE_SDCARD

#define MSP_UART                       SERIAL_PORT_USART1
#define GPS_UART                       SERIAL_PORT_USART3
#define SERIALRX_UART                  SERIAL_PORT_USART6
#define ESC_SENSOR_UART                SERIAL_PORT_USART7

#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART           SERIAL_PORT_USART2
#endif

/*
 * The schematic does not specify the ICM-45686 or IST8310 mounting
 * orientation. Verify sensor alignment from the PCB or on hardware before
 * flight, then add GYRO_1_ALIGN and MAG_ALIGN here.
 *
 * The current-meter scale depends on the connected ESC and must be calibrated
 * for that ESC. F-RAM is 32 KiB; microSD remains the blackbox default.
 */
