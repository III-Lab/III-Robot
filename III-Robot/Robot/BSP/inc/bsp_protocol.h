#ifndef __BSP_PROTOCOL_H
#define	__BSP_PROTOCOL_H

#include "main.h"

#define USART1_RX_LEN	12


#define PROTOCOL_USART_Handle			huart1
#define PROTOCOL_USART_IRQHandler		USART1_IRQHandler

void usart1_init(void);
void usart1_send(unsigned char *buf, unsigned char len);
#endif /* __BSP_PROTOCOL_H */

