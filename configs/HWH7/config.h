/*
- This file is part of Betaflight.
*
- Betaflight is free software. You can redistribute this software
- and/or modify this software under the terms of the GNU General
- Public License as published by the Free Software Foundation,
- either version 3 of the License, or (at your option) any later
- version.
*
- Betaflight is distributed in the hope that it will be useful,
- but WITHOUT ANY WARRANTY; without even the implied warranty of
- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
- See the GNU General Public License for more details.
*
- You should have received a copy of the GNU General Public
- License along with this software.
*
- If not, see <http://www.gnu.org/licenses/>.
*/

/*
    SUPPORTED TARGET - THANK YOU
    REFERENCE: sha256_2cc832462ab98aded88047386660fc2f74293dffe74d8af4a739874c6ee20323
    DATE: 2025-01-01
*/

#pragma once

#define FC_TARGET_MCU     STM32H743
#define BOARD_NAME        HWH7
#define MANUFACTURER_ID   HOWI

//Gyroscope
#define USE_ACC
#define USE_ACC_SPI_ICM42688P

#define USE_GYRO
#define USE_GYRO_SPI_ICM42688P

#define USE_ACCGYRO_LSM6DSV16X

//barometer
#define USE_BARO
#define USE_BARO_DPS310
#define BARO_I2C_INSTANCE             I2CDEV_2
#define MAG_I2C_INSTANCE              I2CDEV_2

//LED
#define LED0_PIN                      PB2 
#define LED_STRIP_PIN                 PA0       // TIM2_CH1/TIM5_CH1/UART4_TX

//BEEPER
#define BEEPER_PIN                    PA1       // TIM2_CH2/TIM5_CH2
#define BEEPER_PWM_HZ                 3000
#define BEEPER_INVERTED

//motor
#define MOTOR1_PIN                    PE14    // TIM1_CH4  
#define MOTOR2_PIN                    PE13    // TIM1_CH3  
#define MOTOR3_PIN                    PE11    // TIM1_CH2  
#define MOTOR4_PIN                    PE9     // TIM1_CH1  
#define MOTOR5_PIN                    PD12    // TIM4_CH1  
#define MOTOR6_PIN                    PD13    // TIM4_CH2  
#define MOTOR7_PIN                    PD14    // TIM4_CH3
#define MOTOR8_PIN                    PD15    // TIM4_CH4

//steering engine
#define SERVO1_PIN                    PE5     // TIM15_CH1 
#define SERVO2_PIN                    PE6     // TIM15_CH2 

//I2C
#define I2C2_SCL_PIN                  PB10    // I2C2_SCL/TIM2_CH3/USART3_TX
#define I2C2_SDA_PIN                  PB11    // I2C2_SDA/TIM2_CH4/USART3_RX

//ICM Clock
#define USE_GYRO_CLKIN
#define GYRO_1_CLKIN_PIN              PB8     // TIM16_CH1,
#define GYRO_2_CLKIN_PIN              PB9     // TIM17_CH1

#define DEFAULT_GYRO_TO_USE          GYRO_CONFIG_USE_GYRO_BOTH

//ICM-42688 (1)
#define SPI1_SCK_PIN                  PA5
#define SPI1_SDI_PIN                  PA6
#define SPI1_SDO_PIN                  PA7

#define GYRO_1_CS_PIN                 PA4
#define GYRO_1_EXTI_PIN               PC14
#define GYRO_1_SPI_INSTANCE           SPI1
#define GYRO_1_ALIGN                  CW0_DEG

//ICM-42688 (2)
#define SPI2_SCK_PIN                  PD3
#define SPI2_SDI_PIN                  PC2
#define SPI2_SDO_PIN                  PC3

#define GYRO_2_CS_PIN                 PB12
#define GYRO_2_EXTI_PIN               PC15
#define GYRO_2_SPI_INSTANCE           SPI2
#define GYRO_2_ALIGN                  CW270_DEG

//UART
#define UART1_TX_PIN                  PA9     //        
#define UART1_RX_PIN                  PA10    //
#define UART2_TX_PIN                  PA2     //
#define UART2_RX_PIN                  PA3     //
#define UART3_TX_PIN                  PD8     // BLUETOOTH
#define UART3_RX_PIN                  PD9     //
#define UART4_TX_PIN                  PD1     // 仅串口功能
#define UART4_RX_PIN                  PD0     // 仅串口功能
#define UART5_TX_PIN                  PB6     //
#define UART5_RX_PIN                  PB5     //
#define UART6_TX_PIN                  PC6     //
#define UART6_RX_PIN                  PC7     //
#define UART7_TX_PIN                  PE8     //
#define UART7_RX_PIN                  PE7     //
#define UART8_TX_PIN                  PE1     //
#define UART8_RX_PIN                  PE0     //

//AT7456E
#define USE_MAX7456
#define SPI3_SCK_PIN                  PB3
#define SPI3_SDI_PIN                  PB4
#define SPI3_SDO_PIN                  PD6
#define MAX7456_SPI_CS_PIN            PA15
#define MAX7456_SPI_INSTANCE          SPI3

//Flash external/SDMMC
#define USE_SDCARD
#define SDCARD_DETECT_PIN             NONE
#define SDIO_DEVICE                   SDIODEV_1
#define SDIO_USE_4BIT                 1

#define SDIO_CK_PIN                   PC12
#define SDIO_CMD_PIN                  PD2
#define SDIO_D0_PIN                   PC8
#define SDIO_D1_PIN                   PC9
#define SDIO_D2_PIN                   PC10
#define SDIO_D3_PIN                   PC11

#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_SDCARD

//ADC
#define ADC_VBAT_PIN                  PC0        // ADC123_INP10,
#define ADC_CURR_PIN                  PC1        // ADC123_INP11,
#define ADC_EXTERNAL1_PIN             PC4        // ADC12_INP4,   
#define ADC_EXTERNAL2_PIN             PC5        // ADC12_INP8,   CU2

#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SCALE         117

// Debug
#define USE_SWDIO_PIN                   PA13
#define USE_SWCLK_PIN                   PA14

//TIME MAP
#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP(0, MOTOR1_PIN, 1, 1) \
    TIMER_PIN_MAP(1, MOTOR2_PIN, 1, 2) \
    TIMER_PIN_MAP(2, MOTOR3_PIN, 1, 3) \
    TIMER_PIN_MAP(3, MOTOR4_PIN, 1, 4) \
    TIMER_PIN_MAP(4, MOTOR5_PIN, 1, 5) \
    TIMER_PIN_MAP(5, MOTOR6_PIN, 1, 6) \
    TIMER_PIN_MAP(6, MOTOR7_PIN, 1, 7) \
    TIMER_PIN_MAP(7, MOTOR8_PIN, 1, -1) \
    TIMER_PIN_MAP(8, SERVO1_PIN, 1, -1) \
    TIMER_PIN_MAP(9, SERVO2_PIN, 1, -1) \
    TIMER_PIN_MAP(10, GYRO_1_CLKIN_PIN, 1, -1) \
    TIMER_PIN_MAP(11, GYRO_2_CLKIN_PIN, 1, -1) \
    TIMER_PIN_MAP(12, BEEPER_PIN, 2, -1) \
    TIMER_PIN_MAP(13, LED_STRIP_PIN, 1, 0)

#define DEFAULT_DSHOT_BITBANG           DSHOT_BITBANG_ON

//DMA
#define TIMUP1_DMA_OPT                8
#define TIMUP4_DMA_OPT                9
#define ADC1_DMA_OPT                  11
#define ADC3_DMA_OPT                  12

//Default Pin switch
#define PINIO1_PIN PE2
#define PINIO1_BOX 40
#define BOX_USER1_NAME       "CAM 1,2"

#define PINIO2_PIN PE4
#define PINIO2_BOX 41
#define PINIO2_CONFIG 129
#define BOX_USER2_NAME       "SW_VTX"

#define PINIO3_PIN PD10
#define PINIO3_BOX 0
#define PINIO3_CONFIG 129

//Default Module
#define SERIALRX_PROVIDER        SERIALRX_CRSF
#ifdef USE_OSD_HD
#define MSP_DISPLAYPORT_UART     SERIAL_PORT_USART2
#endif
#define MSP_UART                 SERIAL_PORT_USART3
#ifdef USE_GPS
#define GPS_UART                 SERIAL_PORT_UART4
#endif
