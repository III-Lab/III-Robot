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

#include "drv_motor.h"


/* 定义小车运动方向，默认停止 */
static eCarDir g_Car_Dir = Car_Stop;


/**
 * @brief  设置小车方向 
 * 
 * @param dir 小车方向
 */
void car_set_dir(eCarDir dir)
{
	eCarDir r = dir;
	if(g_Car_Dir == r)	return;
	switch(r)
	{
		case Car_Stop:	/* 停止 */
			motor_set_dir(Wheel_LT, Wheel_Stop);
			motor_set_dir(Wheel_RT, Wheel_Stop);
			motor_set_dir(Wheel_LB, Wheel_Stop);
			motor_set_dir(Wheel_RB, Wheel_Stop);
			break;
		case Car_Foreward:	/* 四个轮子同时同速前进 */
			motor_set_dir(Wheel_LT, Wheel_Foreward);
			motor_set_dir(Wheel_RT, Wheel_Foreward);
			motor_set_dir(Wheel_LB, Wheel_Foreward);
			motor_set_dir(Wheel_RB, Wheel_Foreward);
			break;
		case Car_Backward:	/* 四个轮子同时同速后退 */
			motor_set_dir(Wheel_LT, Wheel_Backward);
			motor_set_dir(Wheel_RT, Wheel_Backward);
			motor_set_dir(Wheel_LB, Wheel_Backward);
			motor_set_dir(Wheel_RB, Wheel_Backward);
			break;
		case Car_Right:
			motor_set_dir(Wheel_LT, Wheel_Foreward);
			motor_set_dir(Wheel_RT, Wheel_Backward);
			motor_set_dir(Wheel_LB, Wheel_Foreward);
			motor_set_dir(Wheel_RB, Wheel_Backward);
			break;
		case Car_Left:
			motor_set_dir(Wheel_LT, Wheel_Backward);
			motor_set_dir(Wheel_RT, Wheel_Foreward);
			motor_set_dir(Wheel_LB, Wheel_Backward);
			motor_set_dir(Wheel_RB, Wheel_Foreward);
			break;
		case Car_Shift_Left:
			motor_set_dir(Wheel_LT, Wheel_Backward);
			motor_set_dir(Wheel_RT, Wheel_Foreward);
			motor_set_dir(Wheel_LB, Wheel_Foreward);
			motor_set_dir(Wheel_RB, Wheel_Backward);
			break;
		case Car_Shift_Right:
			motor_set_dir(Wheel_LT, Wheel_Foreward);
			motor_set_dir(Wheel_RT, Wheel_Backward);
			motor_set_dir(Wheel_LB, Wheel_Backward);
			motor_set_dir(Wheel_RB, Wheel_Foreward);
			break;
		case Car_Rotate_Right:
			motor_set_dir(Wheel_LT, Wheel_Foreward);
			motor_set_dir(Wheel_RT, Wheel_Backward);
			motor_set_dir(Wheel_LB, Wheel_Foreward);
			motor_set_dir(Wheel_RB, Wheel_Backward);
			break;
		case Car_Rotate_Left:
			motor_set_dir(Wheel_LT, Wheel_Backward);
			motor_set_dir(Wheel_RT, Wheel_Foreward);
			motor_set_dir(Wheel_LB, Wheel_Backward);
			motor_set_dir(Wheel_RB, Wheel_Foreward);
			break;
	}
	g_Car_Dir = r;
}

/**
 * @brief 获取小车当前运动方向
 * 
 * @return eCarDir 小车方向
 */
eCarDir car_get_dir(void)
{
	return g_Car_Dir;
}

