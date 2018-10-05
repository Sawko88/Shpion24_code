#include "timer.h"
#include <time.h>
#include <ti/sysbios/hal/Seconds.h>
#include <stdint.h>
#include <stddef.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <xdc/std.h>
#include <stdbool.h>

#define TASK_STACK_SIZE_TIMER    512
#define TASK_PRIORITY_TIMER      3


static Task_Struct Task_timer;    /* not static so you can see in ROV */
static Task_Params TaskParams_timer;
static uint8_t TaskStack_timer[TASK_STACK_SIZE_TIMER];
uint32_t second = 0;


void timerFnx(UArg arg0, UArg arg1)
{
    while(true){

       second = Seconds_get();

       System_printf("Task timer = %d\r\n", second);

       Task_sleep((1000000 / Clock_tickPeriod));
    }
}


void TimerTaskInit(void) {

    Task_Params_init(&TaskParams_timer);
    TaskParams_timer.stackSize = TASK_STACK_SIZE_TIMER;
    TaskParams_timer.priority = TASK_PRIORITY_TIMER;
    TaskParams_timer.stack = &TaskStack_timer;
    TaskParams_timer.arg0 = (UInt)1000000;


    Task_construct(&Task_timer, timerFnx, &TaskParams_timer, NULL);

}
