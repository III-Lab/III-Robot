#ifndef __BSP_L298N_H
#define	__BSP_L298N_H

#include "main.h"


/* 左前轮引脚定义 */
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
}eWheelState;	/* 状态枚举 */

typedef enum
{
	Wheel_Stop,
	Wheel_Foreward,
	Wheel_Backward
}eWheelDir;	/* 轮子方向枚举 */

typedef enum
{
	Wheel_LT,			/* 左前轮 A1 */
	Wheel_RT,			/* 右前轮 A2 */
	Wheel_LB,			/* 左后轮 B1 */
	WHeel_RB			/* 右后轮 B2 */
}eWheel;	/* 轮子枚举 */


void motor_set_enable(eWheel wheel, eWheelState state);			/* 使能轮子 */
void motor_set_dir(eWheel wheel, eWheelDir dir);				/* 设置轮子方向 */
void motor_set_velocity(eWheel wheel, uint32_t velocity);		/* 设置轮子转动速度 0-1000 */


#endif /* __BSP_L298N_H */


