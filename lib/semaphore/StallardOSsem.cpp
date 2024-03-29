#include "StallardOSsem.hpp"

extern volatile struct function_struct *currentTask;

StallardOSSemaphore::StallardOSSemaphore()
{
    /* val must be written to using ldrex/strex
     * after initial assignment
     */
    val = 1;
}

void StallardOSSemaphore::give()
{
    uint16_t tmp;

    if(currentTask != nullptr)
    {
        /* see ::take method on info about ldrex and strex 
         * Restriction: val may NOT be written to using normal memory access
         */
        do{
            tmp = 0x0000FFFF & __LDREXW(&val);
        }while(__STREXW(tmp+1, &val) != 0);
        currentTask->semVal = nullptr;

        __DMB();  /* guarantees that semVal is nullptr when leaving method */
        
    }
}

void StallardOSSemaphore::take()
{
    uint32_t tmp;

    if(currentTask != nullptr)
    {
        currentTask->semVal = &val;

        /* ldrex and strex instructions use the internal exclusive monitor
         * do determin if another task has accessed the memory at that address
         *
         * therefore a context switch/interrupt can be detected, 
         * and the variable can be refetched, without blocking high-prio tasks
         * 
         * Note: The address used in a STREX instruction must be the same 
         *       as the address in the most recently executed LDREX instruction.
         * 
         * Restriction: val may NOT be written to using normal memory access
         */


        /* loop until the semaphore could get decremented */
        do{
            /* update the current val every iteration */
            tmp = 0x0000FFFF & __LDREXW(&val);
        }while(tmp < 1 || __STREXW((currentTask->id << 16) | (tmp-1), &val) != 0);  /* only try dec if not taken */

        __DMB();  /* docs say we need this */
    }
}
