#include "StallardOSHelpers.h"
#include <stdint.h>

extern struct function_struct *currentTask;
extern struct function_struct *taskMainStruct;
extern struct function_struct *nextTask;

void prepareInitialStack()
{
    //Prepare initial stack trace
  currentTask->Stack--;
  *currentTask->Stack = (uint32_t)0x01000000;
  currentTask->Stack--;
  *currentTask->Stack = (uint32_t)currentTask->function & (~1);
  currentTask->Stack--;
  *currentTask->Stack = (uint32_t)taskOnEnd;

  currentTask->Stack--;
  *currentTask->Stack = (uint32_t)12;
  currentTask->Stack--;
  *currentTask->Stack = (uint32_t)3;
  currentTask->Stack--;
  *currentTask->Stack = (uint32_t)2;
  currentTask->Stack--;
  *currentTask->Stack = (uint32_t)1;
  currentTask->Stack--;
  *currentTask->Stack = (uint32_t)0;
  
  currentTask->Stack--;
  *currentTask->Stack = 0xFFFFFFFD;

  #ifndef unprotectedBuild
  currentTask->Stack--;
  *currentTask->Stack = (CONTROL_nPRIV_Msk << CONTROL_nPRIV_Pos); //Control register (unprivileged)
  #endif

  for(uint8_t i = 11; i > 3; i--)
  {
    currentTask->Stack--;
    *currentTask->Stack = i;
  }
  //////////////////////////////
}

void StallardOSGeneralFaultHandler() //restarts a Task when a fault occurs
{
    asm("TST    LR, #4"); //firstly, find the PC
    asm("ITE    EQ");
    asm("MRSEQ	R0, MSP");
    asm("MRSNE	R0, PSP");

    asm("LDR	R0, [R0, #24]"); //PC is in R0
    // DEBUGGER_BREAK();
    if (taskMainStruct != 0)
    {
        currentTask->Stack = (stack_T*)((stack_T)currentTask->stackBase + (currentTask->stackSize - sizeof(stack_T))); //End of Stack
        prepareInitialStack();
        // currentTask->State = PAUSED; //Set Task state as new
        currentTask->continueInMS = HAL_GetTick() + 500; //Restart Task in 5 s
        if(currentTask->semVal != NULL){
            if(currentTask->waitingForSemaphore == 0){
                // only execute, if semaphore is actually owned by task (take finished)

                /* normal write access to semaphore is ok in this context, 
                * as no other task may execute during hardFault 
                */
                *(currentTask->semVal) = 1; //Semaphore freigeben
                __CLREX();  // reset exclusive monitor
            }
            else{
                // undefined state, task may or may not own the semaphore
                // assume it didn't own it, as that's more likely?
                // TODO: change this???
                DEBUGGER_BREAK();
            }
        }

        currentTask->waitingForSemaphore = 0;
        currentTask->semVal = NULL; //Semaphore von task lösen
        currentTask = taskMainStruct;
        nextTask = taskMainStruct;
    }
}

__attribute__((naked)) void HardFault_Handler()
{
    StallardOSGeneralFaultHandler();
    __ASM volatile("LDR r1, =taskMainStruct\n"
    "LDR r2, [r1]\n"
    "LDR r0, [r2]\n"

    #ifndef unprotectedBuild
    "LDMIA r0!, {r4-r12, r14}\n"   //load registers from memory
    "MSR CONTROL, r12\n"
    #else
    "LDMIA r0!, {r4-r11, r14}\n"   //load registers from memory
    #endif
    
    "MSR PSP, r0\n"           //set PSP
    "ISB\n"
    
    // "MOV %0, #1" //Set function state to running
    "LDR r1, =nextTask\n"
    "MOV r2, #0\n"
    "STR r2, [r1]\n"
    "MOV lr, #0xfffffffd\n"
    "bx lr\n" /*: "=r"(currentTask->State)*/);
}

void NMI_Handler()
{
    StallardOSGeneralFaultHandler();
}

void MemManage_Handler()
{
    DEBUGGER_BREAK();
    StallardOSGeneralFaultHandler();
}

void BusFault_Handler()
{
    StallardOSGeneralFaultHandler();
}

void UsageFault_Handler()
{
    StallardOSGeneralFaultHandler();
}

#ifdef STM32F4xxxx
#ifdef useFPU
// FPU IRQ Handler
void FPU_IRQHandler()
{
    asm("MOV R0, LR"); // move LR to R0
    asm("MOV R1, SP"); // Save SP to R1 to avoid any modification to the stack pointer from FPU_ExceptionHandler
    asm("MRS r4, MSP");
    asm("MRS r5, PSP");

    asm("VMRS R2, FPSCR"); // dummy read access, to force clear

    asm("CMP LR, #0xFFFFFFE9");
    asm("ITTT EQ"); //Next 3 instructions executed if LR = 0xFFFFFFE9
    asm("MOVEQ r2, r4");
    asm("ADDEQ r2, #0x60");
    asm("MSREQ MSP, r2");

    asm("CMP LR, #0xFFFFFFED");
    asm("ITTT EQ"); //Next 3 instructions executed if LR = 0xFFFFFFED
    asm("MOVEQ r2, r5");
    asm("ADDEQ r2, #0x60");
    asm("MSREQ PSP, r2");

    asm("LDR r3, [r2]");

    //check exception flags
    asm("BIC r3, #0x8F");
    asm("STR r3, [r2]");

    asm("DMB");
    StallardOSGeneralFaultHandler();
}
#endif
#endif