#ifndef _UART_H
#define _UART_H
#include "stm32f10x.h"                  // Device header

void uart_init(u32 bound);
void uart2_init(u32 bt);
extern u8 res;
extern u8 res2;
extern uint16_t re;
extern uint16_t Z_Angle;

#endif
