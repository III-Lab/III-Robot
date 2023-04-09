#ifndef __BSP_L298N_H
#define	__BSP_L298N_H

#include "main.h"


/* ��ǰ�����Ŷ��� */
#define WHEEL_LT_EN1_PIN			MLT_EN1_Pin
#define WHEEL_LT_EN1_GPIO_Port		MLT_EN1_GPIO_Port
#define WHEEL_LT_EN2_PIN			MLT_EN2_Pin
#define WHEEL_LT_EN2_GPIO_Port		MLT_EN2_GPIO_Port
#define WHEEL_LT_PWM_CHANNEL		TIM_CHANNEL_1		
#define WHEEL_LT_PWM_TIM			htim8

typedef enum
{
	eWheelEnable,
	eWheelDisable
}eWheelState;	/* ״̬ö�� */

typedef enum
{
	Wheel_Stop,
	Wheel_Foreward,
	Wheel_Backward
}eWheelDir;	/* ���ӷ���ö�� */

typedef enum
{
	Wheel_LT,			/* ��ǰ�� A1 */
	Wheel_RT,			/* ��ǰ�� A2 */
	Wheel_LB,			/* ����� B1 */
	WHeel_RB			/* �Һ��� B2 */
}eWheel;	/* ����ö�� */


void motor_set_enable(eWheel wheel, eWheelState state);			/* ʹ������ */
void motor_set_dir(eWheel wheel, eWheelDir dir);				/* �������ӷ��� */
void motor_set_velocity(eWheel wheel, uint32_t velocity);		/* ��������ת���ٶ� 0-1000 */


#endif /* __BSP_L298N_H */


