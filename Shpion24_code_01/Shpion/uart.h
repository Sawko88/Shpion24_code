/*
 * uart.h
 *
 *  Created on: 1 ���. 2018 �.
 *      Author: shestakov.aa
 */
#include <ti/sysbios/knl/Queue.h>

#ifndef UART_H_
#define UART_H_

typedef struct messU {
      Queue_Elem _elem;
      char* mess;
      int size;
} messU;

Queue_Handle q;

void UARTinit(void);
void UARTpthread(void);
//void *mainThread(void *arg0)
void UARTtask(void);
void UARTsemaph(void);

#endif /* UART_H_ */
