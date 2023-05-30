// Header:	
// File Name: drv_motor.h
// Author:	yunke120
// Date:	2023/04/08

#ifndef __DRV_MOTOR_H
#define	__DRV_MOTOR_H

#include "bsp_l298n.h"

typedef enum
{
	Car_Stop,			/* 停止 	*/
	Car_Foreward,		/* 前进     */
	Car_Backward,		/* 后退     */
	Car_Right,			/* 右转 	*/
	Car_Left,			/* 左转 	*/
	Car_Shift_Left,		/* 左平移 · */
	Car_Shift_Right,	/* 右平移·  */
	Car_Rotate_Right,	/* 原地右旋转 */
	Car_Rotate_Left		/* 原地左旋转 */
}eCarDir;	/* 小车运动方向枚举 */


void car_set_dir(eCarDir dir);								/* 设置小车方向 */
eCarDir car_get_dir(void);									/* 获取小车当前运动方向 */



#endif /* __DRV_MOTOR_H */


