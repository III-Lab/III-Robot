// Header:	
// File Name: drv_motor.h
// Author:	yunke120
// Date:	2023/04/08

#ifndef __DRV_MOTOR_H
#define	__DRV_MOTOR_H

#include "bsp_l298n.h"

typedef enum
{
	Robot_Stop,			/* ֹͣ 	*/
	Robot_Foreward,		/* ǰ��     */
	Robot_Backward,		/* ����     */
	Robot_Right,			/* ��ת 	*/
	Robot_Left,			/* ��ת 	*/
	Robot_Shift_Left,		/* ��ƽ�� �� */
	Robot_Shift_Right,	/* ��ƽ�ơ�  */
	Robot_Rotate_Right,	/* ԭ������ת */
	Robot_Rotate_Left		/* ԭ������ת */
}eRobotDir;	/* С���˶�����ö�� */


void robot_set_dir(eRobotDir dir);								/* ����С������ */
eRobotDir robot_get_dir(void);									/* ��ȡС����ǰ�˶����� */



#endif /* __DRV_MOTOR_H */


