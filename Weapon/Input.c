#include "stm32f10x.h"                  // Device header

/**
  * @brief  Used to Init Input 
  * @param None
  * @retval None
  */
void Input_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

/**
  * @brief  Get_Input
  * @param None
  * @retval Input Value
  */
uint8_t Get_Input(void)
{
	uint8_t IN = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0);
	return IN;
}
