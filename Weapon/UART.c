#include "UART.h"
#include <string.h>
#include <stdio.h>
#include <string.h>

#include <stdio.h>

//struct SAngle 	stcAngle;

void uart_init( u32 bound )
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	USART_InitTypeDef	USART_InitStructure;
	NVIC_InitTypeDef	NVIC_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE );       

	/* USART1_TX   GPIOA.9 */
	GPIO_InitStructure.GPIO_Pin	= GPIO_Pin_9;                                        
	GPIO_InitStructure.GPIO_Speed	= GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_AF_PP;                                  
	GPIO_Init( GPIOA, &GPIO_InitStructure );                                              

	/* USART1_RX	  GPIOA.10*/
	GPIO_InitStructure.GPIO_Pin	= GPIO_Pin_10;                                         
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_IN_FLOATING;                             
	GPIO_Init( GPIOA, &GPIO_InitStructure );                                              


	NVIC_InitStructure.NVIC_IRQChannel			= USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority	= 3;                          
	NVIC_InitStructure.NVIC_IRQChannelSubPriority		= 3;                            
	NVIC_InitStructure.NVIC_IRQChannelCmd			= ENABLE;                      
	NVIC_Init( &NVIC_InitStructure );                                                       


	USART_InitStructure.USART_BaudRate		= bound;                                
	USART_InitStructure.USART_WordLength		= USART_WordLength_8b;                  
	USART_InitStructure.USART_StopBits		= USART_StopBits_1;                     
	USART_InitStructure.USART_Parity		= USART_Parity_No;                      
	USART_InitStructure.USART_HardwareFlowControl	= USART_HardwareFlowControl_None;      
	USART_InitStructure.USART_Mode			= USART_Mode_Rx | USART_Mode_Tx;       

	USART_Init( USART1, &USART_InitStructure );                                           
	USART_ITConfig( USART1, USART_IT_RXNE, ENABLE );                                       
	USART_Cmd( USART1, ENABLE );                                                            
}



uint16_t Z_Angle;
u8 res,res2;
int HEX(Z_Angle)
{
     int re=0;   
     int k=16;   
     int n=1;   
     while(Z_Angle != 0)  
     {
         re += (Z_Angle%10)*n;  
         Z_Angle /= 10;   
         n *= k; 

	 }	
	 return re;
}
void USART1_IRQHandler( void )                                                                 
{

	if (USART_GetITStatus(USART1, USART_IT_RXNE) !=RESET)										
	{
		res = USART_ReceiveData(USART1);  
//		USART_SendData(USART1,res1); 
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC) ==RESET);              
		USART_ClearFlag(USART1, USART_FLAG_RXNE);                              

	}

	
//	static unsigned char ucRxBuffer[250];
//	static unsigned char ucRxCnt = 0;	
//	
//	ucRxBuffer[ucRxCnt++]=USART_ReceiveData( USART1 );	//将收到的数据存入缓冲区中
//	if (ucRxBuffer[0]!=0x55) //数据头不对，则重新开始寻找0x55数据头
//	{
//		ucRxCnt=0;
//		return;
//	}
//	if (ucRxCnt<11) {return;}//数据不满11个，则返回
//	else
//	{
//		if (ucRxBuffer[1] == 0x53)
//		{
////			memcpy(&stcAngle,&ucRxBuffer[2],8);break;
//			USART_SendData(USART1, ucRxBuffer[6]);
//			USART_SendData(USART1, ucRxBuffer[7]);
//			Z_Angle = ucRxBuffer[7];
//			res = (float)ucRxBuffer[7]/255*360;

//			USART_SendData(USART2, Z_Angle);
//			 //re = 0;
//			//USART_SendData(USART2, ucRxBuffer[7]);
//		}
//		ucRxCnt=0;//清空缓存区
//	}

}

void uart2_init(u32 bt)    
{    
     USART_InitTypeDef USART_InitStructure;    
  NVIC_InitTypeDef NVIC_InitStructure;     
    GPIO_InitTypeDef GPIO_InitStructure;    
   
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE); 
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);    

    
   // Configure USART2 Rx (PA.3) as input floating      
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;    
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;    
   GPIO_Init(GPIOA, &GPIO_InitStructure);    

   // Configure USART2 Tx (PA.2) as alternate function push-pull    
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;    
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;    
   GPIO_Init(GPIOA, &GPIO_InitStructure);    

  
   USART_InitStructure.USART_BaudRate = bt;    
   USART_InitStructure.USART_WordLength = USART_WordLength_8b;    
   USART_InitStructure.USART_StopBits = USART_StopBits_1;    
   USART_InitStructure.USART_Parity = USART_Parity_No;    
   USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;    
   USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;    


   // Configure USART3     
   USART_Init(USART2, &USART_InitStructure);//????3    

  // Enable USART1 Receive interrupts ????????    
   USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);    
  
   //USART_ITConfig(USART2, USART_IT_TXE, ENABLE);    

   // Enable the USART3     
   USART_Cmd(USART2, ENABLE);//????3    


   //Configure the NVIC Preemption Priority Bits       
   NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);    

   // Enable the USART3 Interrupt     
   NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;    
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;    
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;    
   NVIC_Init(&NVIC_InitStructure);    
}   

void USART2_IRQHandler(void)  
{  
//	char res2;
	
	
	if (USART_GetITStatus(USART2, USART_IT_RXNE) !=RESET)										
	{
	    res2=USART_ReceiveData(USART2);  
		USART_SendData(USART2,res2); 
		while(USART_GetFlagStatus(USART2, USART_FLAG_TC) ==RESET);             
		USART_ClearFlag(USART2, USART_FLAG_RXNE);                              
	}
}  




