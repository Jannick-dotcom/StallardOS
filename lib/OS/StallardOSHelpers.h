#ifndef StallardOSHelpers_H
#define StallardOSHelpers_H

#include "stdint.h"

#include "StallardOSconfig.h"
#include "StallardOSsyscalls.h"

#if defined STM32F4xxxx
#include <stm32f4xx_hal.h>
#include <system_stm32f4xx.h>
#elif defined STM32F1xxxx
#include <stm32f1xx_hal.h>
#include <system_stm32f1xx.h>
#endif

#define releaseBuild 1
#define debugBuild 0
#define isDebug (BuildType == debugBuild)

#if isDebug
#define DEBUGGER_BREAK() asm("bkpt")
#else
#define DEBUGGER_BREAK()
#endif

#define GEN_HARDFAULT() \
  DEBUGGER_BREAK();     \
  StallardOSGeneralFaultHandler()

#define functionModifier (uint32_t)0xFFFFFFFE // Use the function pointer with lowest bit zero

typedef enum oscillatorType
  {
    internal = RCC_OSCILLATORTYPE_HSI,
    external = RCC_OSCILLATORTYPE_HSE
  } oscillatorType;
#ifdef __cplusplus
extern "C"
{
#endif
  void StallardOS_SetSysClock(uint8_t clockspeed, oscillatorType oscType, uint8_t usePLL);
  void StallardOS_goBootloader();
  void enable_interrupts();
  void disable_interrupts();
  void disable_privilege();
  void taskOnEnd(void);
  struct function_struct;
  void prepareInitialStack(struct function_struct *task);
#ifdef __cplusplus
}
#endif

typedef enum signals
{
  SIG_NONE = 0,
  SIG_KILL,
  SIG_Exception,
  SIG_StackOverflow,
  SIG_StackUnderflow,
  SIG_FloatException,
  SIG_divByZero,
  SIG_segmentationFault,
  SIG_Interrupt,
  SIG_Notification,
  StallardOS_signalcount
} signals;

typedef uint32_t stack_T;

struct function_struct
{
  volatile stack_T *Stack;     // Stack pointer
  volatile stack_T *stackBase; // lowest address of stack allocation, used for MPU config
  uint32_t stackSize;          // Number of elements possible to store on stack, NOT size in bytes
  uint8_t staticAlloc;         // Is the stack static or dynamically allocated?

#ifdef useMPU
  uint8_t mpu_regionSize;   // might be offset from atcual stack pointer, if subregions are used
  uint32_t mpu_baseAddress; // might be offset from actual size, if subregions are used
  uint8_t mpu_subregions;
#endif // useMPU

  // Must have Variablen
  void (*function)();          // Auszuführende Funktion
  volatile uint8_t priority;   // Priorität 0 wird nicht unterbrochen außer Prozess wünscht es durch ein Delay
  volatile uint16_t id;        // ID des Tasks
  volatile uint8_t used;       // Ist dieser TCB schon belegt?
  volatile uint8_t executable; // Funktion ausführen?

  signals rcvSignal[StallardOS_signalcount*2]; // Signal, das empfangen wurde

  // nur für KontextSwitch
  volatile uint16_t refreshRate;
  volatile uint64_t lastYield;
  volatile uint64_t lastStart;                  // used for yield/frequency violation detection

  // SW watchdog
  volatile uint64_t watchdog_limit;           // user defined limit
  volatile uint64_t watchdog_exec_time_us;    // exec time since last kick
  volatile uint64_t watchdog_swapin_ts;       // last swapin OR time since last kick (whicever is later), in us

  // cpu load estimation
  volatile uint64_t perfmon_exec_time_us;       // accumulated exec time of task since last reset
  volatile uint64_t perfmon_swapin_ts;          // last swapIn, helper for exec time, ts in us

  volatile uint8_t waitingForSemaphore; // Is task waiting for a semaphore
  volatile uint32_t *semVal;            // First 16bit - ID-of-Task
                             // Last  16bit - Semaphore Value
  volatile uint64_t continue_ts; //Timestamp of continuation
};

#endif