#ifndef StallardOSSerial_h
#define StallardOSSerial_h

#include <stm32f4xx_hal.h>
#include <system_stm32f4xx.h>
#include <stdint.h>
// #include "StallardOSconfig.h"
#include "StallardOSsem.hpp"
#include "StallardOSGPIO.hpp"
#include <iostream>

extern "C" void StallardOSGeneralFaultHandler();

class StallardOSSerial
{
private:
    UART_HandleTypeDef huart;
    StallardOSSemaphore sem;
    StallardOSGPIO tx;
    StallardOSGPIO rx;
    uint8_t portToAlternateFunc(USART_TypeDef *serPort);
public:
    StallardOSSerial(USART_TypeDef *serPort, gpio tx, gpio rx, uint32_t baud);
    void send(const char *dat, uint16_t bytes);
    void send(std::string str);
    void read(char *dat, uint16_t bytes);
};
#endif