#ifndef StallardOSSerial_h
#define StallardOSSerial_h

#include <stm32f4xx_hal.h>
#include <system_stm32f4xx.h>
#include <stdint.h>
#include "StallardOSconfig.h"

extern "C" void StallardOSGeneralFaultHandler();

class StallardOSSerial
{
private:
    UART_HandleTypeDef huart;
public:
    StallardOSSerial(USART_TypeDef *serPort, uint32_t baud);
    void send(const char *dat, uint16_t bytes);
    void read(char *dat, uint16_t bytes);

};
#endif