/*
 * uart.h
 *
 *  Created on: 1 окт. 2018 г.
 *      Author: shestakov.aa
 */

#ifndef UART_H_
#define UART_H_

void UARTinit(void);
void UARTpthread(void);
//void *mainThread(void *arg0)
void UARTtask(void);
void UARTsemaph(void);

#endif /* UART_H_ */
