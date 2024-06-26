#ifndef StallardOSClass_h
#define StallardOSClass_h

#include "StallardOSHelpers.h"

class NonAssignable {
public:
    NonAssignable(NonAssignable const&) = delete;
    NonAssignable& operator=(NonAssignable const&) = delete;
    NonAssignable() {};
};

class StallardOS
{
private:
  volatile struct function_struct *first_function_struct; //Pointer auf das erste erstellte Function struct
  uint8_t TCBsCreated;

  struct function_struct *searchFunction(/*Funktion*/ uint16_t id); //Search a TCB that matches the provided function
  struct function_struct *searchFreeFunction(void);                 //Search a TCB that isn't used
  void createTCBs(void);                                            //create the structs for all the functions (count is "countTasks")
  void initShared(void);
  void initMPU(void);                                               // setup the static part of the MPU configuration

  struct function_struct *initTask(void (*function)(), uint8_t prio, uint32_t *stackPtr, stack_T stackSize, uint16_t refreshRate = 0, uint16_t watchdogLimitMs = 0);
  void signal_handler(signals signal_code, function_struct *receivingTask);

public:
  static uint8_t cpu_load;
  //Constructor 
  StallardOS(); //Create a Task Scheduler
  
  //Functions to add functions
  struct function_struct *addFunction(void (*function)(), uint8_t prio, stack_T stackSize, uint16_t refreshRate = 0, uint16_t watchdogLimitMs=0);
  struct function_struct *addFunctionStatic(void (*function)(), uint8_t prio, uint32_t *stackPtr, stack_T stackSize, uint16_t refreshRate = 0, uint16_t watchdogLimitMs=0);

  void sendSignal(signals signal_code, uint16_t id);
  bool waitForSignal(signals signal_code, uint32_t timeout = 0);

  void remove_all_functions(void); //Remove all functions

  //Setters
  void setFunctionEnabled(/*Funktion*/ uint16_t id, /*Aktivieren oder Deaktivieren*/ bool act);
  void setFunctionPriority(/*Funktion*/ uint16_t id, /*New Priority*/ uint8_t prio);
  void setFunctionFrequency(/*Funktion*/ uint16_t id, /*New execution Frequency*/ float exec_freq);

  //Getters
  bool getPrivilegeLevel(); //returns true if privileged

  //Control
  static void goBootloader();
  static void goFlashloader();
  void startOS(void);                //RTOS Starten (preemtive Multitasking)
  static void delay(uint32_t milliseconds); //RTOS führt solange einen anderen Task aus bevor er zum jetzigen zurückspringt
  static void delay_us(uint16_t microseconds); //RTOS wartet bis zu 1000us
  static void yield();                      //RTOS sagen, dass jetzt der Code zuende ist
  static void kickTheDog();
  static void restartTask(function_struct *task);
};

#endif