// Header:	
// File Name: drv_motor.h
// Author:	yunke120
// Date:	2023/04/08

#ifndef __DRV_MOTOR_H
#define	__DRV_MOTOR_H

#include "bsp_l298n.h"

typedef enum
{
	Car_Stop,			/* ֹͣ 	*/
	Car_Foreward,		/* ǰ��     */
	Car_Backward,		/* ����     */
	Car_Right,			/* ��ת 	*/
	Car_Left,			/* ��ת 	*/
	Car_Shift_Left,		/* ��ƽ�� �� */
	Car_Shift_Right,	/* ��ƽ�ơ�  */
	Car_Rotate_Right,	/* ԭ������ת */
	Car_Rotate_Left		/* ԭ������ת */
}eCarDir;	/* С���˶�����ö�� */





#endif /* __DRV_MOTOR_H */


