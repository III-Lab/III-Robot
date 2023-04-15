/****************************************Copyright (c)****************************************************
 
**--------------File Info---------------------------------------------------------------------------------
** File name:                 
** Last modified Date:          
** Last Version:           
** Descriptions:           
**                        
**--------------------------------------------------------------------------------------------------------
** Created by:               yunke120
** Created date:           2023/04/08
** Version:                  1.0
** Descriptions:          
**--------------------------------------------------------------------------------------------------------*/

#include "bsp_l298n.h"
#include "tim.h"


void motor_set_enable(eWheel wheel, eWheelState state)
{
	eWheel		w = wheel;
	eWheelState	s = state;
	
	switch(w){
		case Wheel_LT:
			(s==eWheelEnable)  ? 	HAL_TIM_PWM_Start(&WHEEL_LT_PWM_TIM, WHEEL_LT_PWM_CHANNEL): \
									HAL_TIM_PWM_Stop (&WHEEL_LT_PWM_TIM, WHEEL_LT_PWM_CHANNEL);
			break;
		case Wheel_RT:
			(s==eWheelEnable)  ? 	HAL_TIM_PWM_Start(&WHEEL_RT_PWM_TIM, WHEEL_RT_PWM_CHANNEL): \
									HAL_TIM_PWM_Stop (&WHEEL_RT_PWM_TIM, WHEEL_RT_PWM_CHANNEL);
			break;
		case Wheel_LB:
			(s==eWheelEnable)  ? 	HAL_TIM_PWM_Start(&WHEEL_LB_PWM_TIM, WHEEL_LB_PWM_CHANNEL): \
									HAL_TIM_PWM_Stop (&WHEEL_LB_PWM_TIM, WHEEL_LB_PWM_CHANNEL);
			break;
		case Wheel_RB:
			(s==eWheelEnable)  ? 	HAL_TIM_PWM_Start(&WHEEL_RB_PWM_TIM, WHEEL_RB_PWM_CHANNEL): \
									HAL_TIM_PWM_Stop (&WHEEL_RB_PWM_TIM, WHEEL_RB_PWM_CHANNEL);
			break;
		default: break;
	}
}



void motor_set_dir(eWheel wheel, eWheelDir dir)
{
	eWheel 		w = wheel;
	eWheelDir	d = dir;
	switch(w){
		case Wheel_LT:
			if(d == Wheel_Foreward)
			{
				HAL_GPIO_WritePin(WHEEL_LT_EN1_GPIO_Port, WHEEL_LT_EN1_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WHEEL_LT_EN2_GPIO_Port, WHEEL_LT_EN2_PIN, GPIO_PIN_SET);
			}
			else if(d == Wheel_Backward)
			{
				HAL_GPIO_WritePin(WHEEL_LT_EN1_GPIO_Port, WHEEL_LT_EN1_PIN, GPIO_PIN_SET);
				HAL_GPIO_WritePin(WHEEL_LT_EN2_GPIO_Port, WHEEL_LT_EN2_PIN, GPIO_PIN_RESET);
			}
			else
			{
				HAL_GPIO_WritePin(WHEEL_LT_EN1_GPIO_Port, WHEEL_LT_EN1_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WHEEL_LT_EN2_GPIO_Port, WHEEL_LT_EN2_PIN, GPIO_PIN_RESET);
			}
			break;
		case Wheel_RT:
			if(d == Wheel_Foreward)
			{
				HAL_GPIO_WritePin(WHEEL_RT_EN1_GPIO_Port, WHEEL_RT_EN1_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WHEEL_RT_EN2_GPIO_Port, WHEEL_RT_EN2_PIN, GPIO_PIN_SET);
			}
			else if(d == Wheel_Backward)
			{
				HAL_GPIO_WritePin(WHEEL_RT_EN1_GPIO_Port, WHEEL_RT_EN1_PIN, GPIO_PIN_SET);
				HAL_GPIO_WritePin(WHEEL_RT_EN2_GPIO_Port, WHEEL_RT_EN2_PIN, GPIO_PIN_RESET);
			}
			else
			{
				HAL_GPIO_WritePin(WHEEL_RT_EN1_GPIO_Port, WHEEL_RT_EN1_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WHEEL_RT_EN2_GPIO_Port, WHEEL_RT_EN2_PIN, GPIO_PIN_RESET);
			}
			break;
		case Wheel_LB:
			if(d == Wheel_Foreward)
			{
				HAL_GPIO_WritePin(WHEEL_LB_EN1_GPIO_Port, WHEEL_LB_EN1_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WHEEL_LB_EN2_GPIO_Port, WHEEL_LB_EN2_PIN, GPIO_PIN_SET);
			}
			else if(d == Wheel_Backward)
			{
				HAL_GPIO_WritePin(WHEEL_LB_EN1_GPIO_Port, WHEEL_LB_EN1_PIN, GPIO_PIN_SET);
				HAL_GPIO_WritePin(WHEEL_LB_EN2_GPIO_Port, WHEEL_LB_EN2_PIN, GPIO_PIN_RESET);
			}
			else
			{
				HAL_GPIO_WritePin(WHEEL_LB_EN1_GPIO_Port, WHEEL_LB_EN1_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WHEEL_LB_EN2_GPIO_Port, WHEEL_LB_EN2_PIN, GPIO_PIN_RESET);
			}
			break;
		case Wheel_RB:
			if(d == Wheel_Foreward)
			{
				HAL_GPIO_WritePin(WHEEL_RB_EN1_GPIO_Port, WHEEL_RB_EN1_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WHEEL_RB_EN2_GPIO_Port, WHEEL_RB_EN2_PIN, GPIO_PIN_SET);
			}
			else if(d == Wheel_Backward)
			{
				HAL_GPIO_WritePin(WHEEL_RB_EN1_GPIO_Port, WHEEL_RB_EN1_PIN, GPIO_PIN_SET);
				HAL_GPIO_WritePin(WHEEL_RB_EN2_GPIO_Port, WHEEL_RB_EN2_PIN, GPIO_PIN_RESET);
			}
			else
			{
				HAL_GPIO_WritePin(WHEEL_RB_EN1_GPIO_Port, WHEEL_RB_EN1_PIN, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(WHEEL_RB_EN2_GPIO_Port, WHEEL_RB_EN2_PIN, GPIO_PIN_RESET);
			}
			break;
			
		default: break;
	}
}

void motor_set_velocity(eWheel wheel, uint32_t velocity)
{
	eWheel 		w = wheel;
	uint32_t	v = velocity;
	assert_param(velocity <= 1000);
	switch(w){
		case Wheel_LT:
			__HAL_TIM_SetCompare(&WHEEL_LT_PWM_TIM, WHEEL_LT_PWM_CHANNEL, v);
			break;
		case Wheel_RT:
			__HAL_TIM_SetCompare(&WHEEL_RT_PWM_TIM, WHEEL_RT_PWM_CHANNEL, v);
			break;
		case Wheel_LB:
			__HAL_TIM_SetCompare(&WHEEL_LB_PWM_TIM, WHEEL_LB_PWM_CHANNEL, v);
			break;
		case Wheel_RB:
			__HAL_TIM_SetCompare(&WHEEL_RB_PWM_TIM, WHEEL_RB_PWM_CHANNEL, v);
			break;
			
		default: break;
	}
}











