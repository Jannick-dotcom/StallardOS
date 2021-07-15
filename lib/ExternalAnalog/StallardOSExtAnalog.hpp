#ifndef StallardOS_ExtAnalog
#define StallardOS_ExtAnalog

#include <stm32f4xx_hal.h>
#include <system_stm32f4xx.h>
#include <stdint.h>
#include "StallardOSconfig.h"
#include "StallardOSsem.hpp"
#include "StallardOSSPI.hpp"
#include "StallardOSGPIO.hpp"
#include "StallardOSClass.hpp"

extern "C" void StallardOSGeneralFaultHandler();

class StallardOSExtAnalog
{
private:
    StallardOSSPI spihandle;
    uint8_t channel;
    uint8_t adcNumber;
    
    StallardOSGPIO cs;
    StallardOSGPIO drdy;
    StallardOSGPIO reset;

    StallardOSSemaphore sem;
    static uint8_t adcInitialized;
    int16_t offset;

    uint8_t registerRead(uint8_t address);
    void registerWrite(uint8_t address, uint8_t value);
    uint16_t channelRead(uint8_t channel);
public:

public:

/**
 * create a Analog input instance.
 *
 * @param adcNumber which adc to use
 * @param channel Number of channel
 */
    StallardOSExtAnalog(uint8_t channel, uint8_t adcNumber);

/**
 * get a analog reading.
 *
 * @return analog value
 */
    int16_t getValue();
};

#endif