#pragma once

#define FC_TARGET_MCU     STM32F7X2
#define BOARD_NAME        VEKTRAF722
#define MANUFACTURER_ID   VEKTRA

#define USE_ACC
#define USE_GYRO
#define USE_ACCGYRO_BMI270
#define USE_BARO
#define USE_BARO_SPI_BMP280
#define USE_FLASH
#define USE_FLASH_M25P16
#define USE_MAX7456

#define BEEPER_PIN           PC15
#define MOTOR1_PIN           PA9
#define MOTOR2_PIN           PA8
#define MOTOR3_PIN           PC9
#define MOTOR4_PIN           PC8

#define RX_PPM_PIN           PB9

#define UART1_TX_PIN         PB6
#define UART2_TX_PIN         PA2
#define UART3_TX_PIN         PC10
#define UART4_TX_PIN         PA0
#define UART5_TX_PIN         PC12
#define UART1_RX_PIN         PB7
#define UART2_RX_PIN         PA3
#define UART3_RX_PIN         PC11
#define UART4_RX_PIN         PA1
#define UART5_RX_PIN         PD2
#define I2C2_SCL_PIN         PB10
#define I2C2_SDA_PIN         PB11
#define LED0_PIN             PC13
#define SPI1_SCK_PIN         PA5
#define SPI2_SCK_PIN         PB13
#define SPI3_SCK_PIN         PB3
#define SPI1_SDI_PIN         PA6
#define SPI2_SDI_PIN         PB14
#define SPI3_SDI_PIN         PB4
#define SPI1_SDO_PIN         PA7
#define SPI2_SDO_PIN         PB15
#define SPI3_SDO_PIN         PB5
#define ADC_VBAT_PIN         PC3
#define ADC_RSSI_PIN         PC2
#define ADC_CURR_PIN         PC1
#define BARO_CS_PIN          PC0
#define FLASH_CS_PIN         PA10
#define MAX7456_SPI_CS_PIN   PB12
#define GYRO_1_EXTI_PIN      PA15
#define GYRO_1_CS_PIN        PA4
#define PINIO1_PIN           PC14

#define TIMER_PIN_MAPPING \
    TIMER_PIN_MAP( 0, PA9 , 2,  1) \
    TIMER_PIN_MAP( 1, PA8 , 2,  1) \
    TIMER_PIN_MAP( 2, PC9 , 2,  1) \
    TIMER_PIN_MAP( 3, PC8 , 2,  1) \
    TIMER_PIN_MAP( 4, PB8 , 1,  0) \
    TIMER_PIN_MAP( 5, PB1 , 2,  0) \
    TIMER_PIN_MAP( 6, PB9 , 2, -1) 


#define ADC1_DMA_OPT        0
#define DEFAULT_BLACKBOX_DEVICE     BLACKBOX_DEVICE_FLASH
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define BEEPER_INVERTED
#define MAX7456_SPI_INSTANCE SPI2
#define FLASH_SPI_INSTANCE SPI2
#define BARO_SPI_INSTANCE SPI2
#define GYRO_1_SPI_INSTANCE SPI1

#define PINIO1_BOX 40
#define PINIO2_BOX 0
#define PINIO3_BOX 0
#define PINIO4_BOX 0
