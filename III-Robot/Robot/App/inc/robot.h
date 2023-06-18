// Header:	
// File Name: drv_motor.h
// Author:	yunke120
// Date:	2023/04/08

#ifndef __DRV_MOTOR_H
#define	__DRV_MOTOR_H

#include "bsp_l298n.h"

typedef enum
{
	Robot_Stop,			/* 停止 	*/
	Robot_Foreward,		/* 前进     */
	Robot_Backward,		/* 后退     */
	Robot_Right,			/* 右转 	*/
	Robot_Left,			/* 左转 	*/
	Robot_Shift_Left,		/* 左平移 · */
	Robot_Shift_Right,	/* 右平移·  */
	Robot_Rotate_Right,	/* 原地右旋转 */
	Robot_Rotate_Left		/* 原地左旋转 */
}eRobotDir;	/* 小车运动方向枚举 */


void robot_set_dir(eRobotDir dir);								/* 设置小车方向 */
eRobotDir robot_get_dir(void);									/* 获取小车当前运动方向 */



#endif /* __DRV_MOTOR_H */


