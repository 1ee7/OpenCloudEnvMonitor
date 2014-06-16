/* Copyright (c) 2014 xiaogan Studio. All Rights Reserved.
 *
 */
#ifndef ENVMONITOR_H__
#define ENVMONITOR_H__

#include "nrf_gpio.h"

#define LED_START      (18)
#define LED_0          (18)
#define LED_1          (19)
#define LED_2          (20)
#define LED_3          (21)
#define LED_4          (22)
//#define LED_5          13
//#define LED_6          14
//#define LED_7          15
#define LED_STOP       (22)

#define BUTTON_START   (16)
#define BUTTON_0       (16)
#define BUTTON_1       (17)
//#define BUTTON_2       2
//#define BUTTON_3       3
//#define BUTTON_4       4
//#define BUTTON_5       5
//#define BUTTON_6       6
//#define BUTTON_7       7
#define BUTTON_STOP     (17)
#define BUTTON_PULL    NRF_GPIO_PIN_NOPULL

#define RX_PIN_NUMBER  (9)    // UART RX pin number.
#define TX_PIN_NUMBER  (11)    // UART TX pin number.
#define CTS_PIN_NUMBER (8)    // UART Clear To Send pin number. Not used if HWFC is set to false
#define RTS_PIN_NUMBER (10)    // Not used if HWFC is set to false
#define HWFC           false // UART hardware flow control

#define SPIS_MISO_PIN  (20)    // SPI MISO signal. 
#define SPIS_CSN_PIN   (21)    // SPI CSN signal. 
#define SPIS_MOSI_PIN  (22)    // SPI MOSI signal. 
#define SPIS_SCK_PIN   (23)    // SPI SCK signal. 

#endif  // ENVMONITOR_H__
