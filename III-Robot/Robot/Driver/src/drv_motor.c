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


/* ����С���˶�����Ĭ��ֹͣ */
static eCarDir g_Car_Dir = Car_Stop;


/**
 * @brief  ����С������ 
 * 
 * @param dir С������
 */
void car_set_dir(eCarDir dir)
{
	eCarDir r = dir;
	if(g_Car_Dir == r)	return;
	switch(r)
	{
		case Car_Stop:	/* ֹͣ */
			motor_set_dir(Wheel_LT, Wheel_Stop);
			motor_set_dir(Wheel_RT, Wheel_Stop);
			motor_set_dir(Wheel_LB, Wheel_Stop);
			motor_set_dir(Wheel_RB, Wheel_Stop);
			break;
		case Car_Foreward:	/* �ĸ�����ͬʱͬ��ǰ�� */
			motor_set_dir(Wheel_LT, Wheel_Foreward);
			motor_set_dir(Wheel_RT, Wheel_Foreward);
			motor_set_dir(Wheel_LB, Wheel_Foreward);
			motor_set_dir(Wheel_RB, Wheel_Foreward);
			break;
		case Car_Backward:	/* �ĸ�����ͬʱͬ�ٺ��� */
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
 * @brief ��ȡС����ǰ�˶�����
 * 
 * @return eCarDir С������
 */
eCarDir car_get_dir(void)
{
	return g_Car_Dir;
}

