#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Input.h"
#include "OLED.h"
#include "UART.h"


int main(void)
{
	OLED_Init();
	uart_init(115200);
	uart2_init(115200);
//	OLED_ShowChar(1, 1, 'A');
//	OLED_ShowNum(2, 1, 123, 6);
	while(1)
	{
//		USART_SendData(USART1,1);
//		USART_SendData(USART2,1);
		OLED_ShowChar(1,1,'Y');
		OLED_ShowNum(2,1,res,3);
		OLED_ShowNum(3,1,res2,3);
	}
	OLED_ShowChar(3, 5,'y');
}
