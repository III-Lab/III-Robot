/****************************************Copyright (c)****************************************************
 
**--------------File Info---------------------------------------------------------------------------------
** File name:                 
** Last modified Date:          
** Last Version:           
** Descriptions:           
**                        
**--------------------------------------------------------------------------------------------------------
** Created by:               yunke120
** Created date:           2023/06/16
** Version:                  1.0
** Descriptions:          
**--------------------------------------------------------------------------------------------------------*/

#include "bsp_protocol.h"
#include "stdio.h"
#include "cmsis_os.h"

extern UART_HandleTypeDef huart1;
extern osMessageQueueId_t protocolQueueHandle;

static uint8_t USART1_RX_BUF[USART1_RX_LEN];	/* 接收缓存区 */
static uint8_t rx_count;

void usart1_init(void)
{
	__HAL_UART_CLEAR_FLAG(&PROTOCOL_USART_Handle,UART_FLAG_RXNE);
	__HAL_UART_ENABLE_IT(&PROTOCOL_USART_Handle, UART_IT_RXNE);     
}

void usart1_send(unsigned char *buf, unsigned char len)
{
	HAL_UART_Transmit(&PROTOCOL_USART_Handle, buf, len, HAL_MAX_DELAY);
}

void PROTOCOL_USART_IRQHandler(void)
{
	if(__HAL_UART_GET_FLAG(&PROTOCOL_USART_Handle,UART_FLAG_RXNE)!= RESET) { // 接收中断：接收到数据
		
		uint8_t data;
		data=READ_REG(PROTOCOL_USART_Handle.Instance->RDR); 
		USART1_RX_BUF[rx_count] = data;
		rx_count++;
		if (rx_count >= USART1_RX_LEN)
		{
			rx_count = 0;
			
			// deal data
#if 0
			for(int i = 0; i < USART1_RX_LEN; i++)
			{
				printf("%02x ", USART1_RX_BUF[i]);
			}
			printf("\r\n");
#endif
			osMessageQueuePut(protocolQueueHandle, USART1_RX_BUF, 0U, 0U);
		}
		
	} 
	
	HAL_UART_IRQHandler(&PROTOCOL_USART_Handle);
}





