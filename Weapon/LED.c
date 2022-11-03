#include "stm32f10x.h"                  // Device header

/**
  * @brief  Used to Init LED
  * @param None
  * @retval None
  */
void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/**
  * @brief  LED_ON
  * @param None
  * @retval None
  */
void LED_ON(void)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET);
}

/**
  * @brief  LED_OFF
  * @param None
  * @retval None
  */
void LED_OFF(void)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_SET);
}
