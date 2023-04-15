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

static inline uint32_t _abs_(int32_t val)
{
	if(val < 0) return -val;
	return val;
}

void encoder_set_enable(eEncoder encoder, eEncoderState state)
{
	eEncoder		e = encoder;
	eEncoderState	s = state;
	
	switch (e)
    {
    	case Encoder_LT:
			(s == eEncoderEnable)	?	HAL_TIM_Encoder_Start(&Encoder_LT_TIM, TIM_CHANNEL_ALL):
										HAL_TIM_Encoder_Stop (&Encoder_LT_TIM, TIM_CHANNEL_ALL);
			
    		break;
    	case Encoder_RT:
			(s == eEncoderEnable)	?	HAL_TIM_Encoder_Start(&Encoder_RT_TIM, TIM_CHANNEL_ALL):
										HAL_TIM_Encoder_Stop (&Encoder_RT_TIM, TIM_CHANNEL_ALL);
    		break;
		case Encoder_LB:
			(s == eEncoderEnable)	?	HAL_TIM_Encoder_Start(&Encoder_LB_TIM, TIM_CHANNEL_ALL):
										HAL_TIM_Encoder_Stop (&Encoder_LB_TIM, TIM_CHANNEL_ALL);
    		break;
		case Encoder_RB:
			(s == eEncoderEnable)	?	HAL_TIM_Encoder_Start(&Encoder_RB_TIM, TIM_CHANNEL_ALL):
										HAL_TIM_Encoder_Stop (&Encoder_RB_TIM, TIM_CHANNEL_ALL);
    		break;
    	default:
    		break;
    }
}

/* 获取速度 ，单位s */
float encoder_get_velocity(eEncoder encoder, uint16_t t_ms)
{
	eEncoder		 e = encoder;
	uint32_t		 vel = 0;
	static	uint32_t old_val1;
	
	switch(e)
	{
		case Encoder_LT:
		{
			uint32_t cur_val = (__HAL_TIM_GET_COUNTER(&Encoder_LT_TIM));//获取encoder编码器的计数值
			vel = _abs_(cur_val - old_val1);
			old_val1 = cur_val;
		}
			break;
		case Encoder_RT:
		{
			uint32_t cur_val = (__HAL_TIM_GET_COUNTER(&Encoder_RT_TIM));//获取encoder编码器的计数值
			vel = _abs_(cur_val - old_val1);
			old_val1 = cur_val;
		}
			break;
		case Encoder_LB:
		{
			uint32_t cur_val = (__HAL_TIM_GET_COUNTER(&Encoder_LB_TIM));//获取encoder编码器的计数值
			vel = _abs_(cur_val - old_val1);
			old_val1 = cur_val;
		}
			break;
		case Encoder_RB:
		{
			uint32_t cur_val = (__HAL_TIM_GET_COUNTER(&Encoder_RB_TIM));//获取encoder编码器的计数值
			vel = _abs_(cur_val - old_val1);
			old_val1 = cur_val;
		}
			break;
	}
	
	return (float)vel*CALC_VELO(t_ms); 
}

eEncoderDir encoder_get_dir(eEncoder encoder)
{
	eEncoder	e = encoder;
	int			dir;
	
	switch(e)
	{
		case Encoder_LT:
			dir = __HAL_TIM_IS_TIM_COUNTING_DOWN(&Encoder_LT_TIM);
			break;
		case Encoder_RT:
			dir = __HAL_TIM_IS_TIM_COUNTING_DOWN(&Encoder_RT_TIM);
			break;
		case Encoder_LB:
			dir = __HAL_TIM_IS_TIM_COUNTING_DOWN(&Encoder_LB_TIM);
			break;
		case Encoder_RB:
			dir = __HAL_TIM_IS_TIM_COUNTING_DOWN(&Encoder_RB_TIM);
			break;
	}
	return (eEncoderDir)dir;
}






