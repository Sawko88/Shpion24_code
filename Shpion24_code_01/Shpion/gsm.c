/*
 * gsm.c
 *
 *  Created on: 4 ���. 2018 �.
 *      Author: shestakov.aa
 */

#include "gsm.h"
#include <stdint.h>
#include <stddef.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/knl/Clock.h>

#define TASK_STACK_SIZE_GSM    1024
#define TASK_PRIORITY_GSM      3

static Task_Struct task_gsm;    /* not static so you can see in ROV */
static Task_Params taskParams_gsm;
static uint8_t taskStack_gsm[TASK_STACK_SIZE_GSM];

void gsmFnx(UArg arg0, UArg arg1)
{
    while(1){
        //System_printf("Task gsm \r\n");
        Task_sleep((1000000 / Clock_tickPeriod));
    }
}

void GsmTaskInit(void){
    Task_Params_init(&taskParams_gsm);
    taskParams_gsm.stackSize = TASK_STACK_SIZE_GSM;
    taskParams_gsm.priority = TASK_PRIORITY_GSM;
    taskParams_gsm.stack = &taskStack_gsm;
    taskParams_gsm.arg0 = (UInt)1000000;

    Task_construct(&task_gsm, gsmFnx, &taskParams_gsm, NULL);
}


void GsmInit(void){

    GsmTaskInit();
}


