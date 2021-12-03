#ifndef StallardOS_h
#define StallardOS_h

#include <stdint.h>
#include <malloc.h>
#include <stm32f4xx_hal.h>
#include <system_stm32f4xx.h>

#include "StallardOSClass.hpp"
#include "StallardOSsem.hpp"
#include "StallardOSGPIO.hpp"
#include "StallardOSpwm.hpp"
#include "StallardOSanalog.hpp"
#include "StallardOSExtAnalog.hpp"
#include "StallardOScan.hpp"
#include "StallardOSSerial.hpp"
#include "StallardOSi2c.hpp"
#include "StallardOSPID.hpp"
#include "StallardOSSPI.hpp"
#include "StallardOSDAC.hpp"

#ifdef STM32F417xx
static StallardOSCAN MS4_CAN(StallardOSCAN2, CAN1M);
static StallardOSCAN AD_CAN(StallardOSCAN1, CAN500k);
#define AD_CAN_PORT StallardOSCAN1
#define MS4_CAN_PORT StallardOSCAN2
#endif
#ifdef STM32F415xx
static StallardOSCAN AD_CAN(StallardOSCAN2, CAN500k);
#define AD_CAN_PORT StallardOSCAN2
#endif
#ifdef STM32F407xx
// static StallardOSCAN MS4_CAN(StallardOSCAN2, CAN1M, CAN_DEBUG);
// static StallardOSCAN AD_CAN(StallardOSCAN1, CAN500k, CAN_DEBUG);
// #define AD_CAN_PORT StallardOSCAN1
// #define MS4_CAN_PORT StallardOSCAN2
#endif

#endif //StallardOS_h
