/****************************************Copyright (c)****************************************************
 
**--------------File Info---------------------------------------------------------------------------------
** File name:                 
** Last modified Date:          
** Last Version:           
** Descriptions:           
**                        
**--------------------------------------------------------------------------------------------------------
** Created by:               yunke120
** Created date:           2023/04/09
** Version:                  1.0
** Descriptions:          
**--------------------------------------------------------------------------------------------------------*/

#include "bsp_encoder.h"
#include "tim.h"
#include "stdio.h"
void encoder_set_enable(eEncoder encoder, eEncoderState state)
{
	eEncoder		e = encoder;
	eEncoderState	s = state;
	
	switch (e)
    {
    	case Encoder_LT:
			(s == eEncoderEnable)	?	HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL):
										HAL_TIM_Encoder_Stop (&htim1, TIM_CHANNEL_ALL);
			
    		break;
    	case Encoder_RT:
    		break;
		case Encoder_LB:
    		break;
		case Encoder_RB:
    		break;
    	default:
    		break;
    }
}

void print_encoder(void)
{
	int dir = __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim1);
	uint32_t vel = (__HAL_TIM_GET_COUNTER(&htim1));//获取encoder编码器的计数值
	
	printf("dir = %d, vel = %d\r\n", dir, vel);
}




