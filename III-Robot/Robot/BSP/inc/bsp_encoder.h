// Header:		__BSP_ENCODER_H
// File Name: 	bsp_encoder.h
// Author:		yunke120
// Date:		2023/04/09

#ifndef __BSP_ENCODER_H
#define	__BSP_ENCODER_H

#include "main.h"

#define Encoder_LT_TIM		htim5
#define Encoder_RT_TIM		htim2
#define Encoder_LB_TIM		htim3
#define Encoder_RB_TIM		htim1


#define ENCODER_LINES	13		/* GMR编码器500线 */
#define MOTOR_LINES		27  	/* 电机减速比 */
#define ECONDER_TIMING	100		/* ms */
/*
	电机转一圈的脉冲数：500*4*27 = 54000
*/

#define CALC_VELO	1000/(ENCODER_LINES*MOTOR_LINES*ECONDER_TIMING*4)

#define VelocityMin		600
#define VelocityMax		1000

typedef enum
{
	eEncoderEnable,
	eEncoderDisable,
}eEncoderState;

typedef enum
{
	Encoder_LT,
	Encoder_RT,
	Encoder_LB,
	Encoder_RB,
}eEncoder;

typedef enum
{
	eEncoderForeward,
	eEncoderBackward,
//	eEncoderStop,
}eEncoderDir;

void encoder_set_enable(eEncoder encoder, eEncoderState state);
short encoder_get_counter(eEncoder encoder, uint16_t t_ms);
float encoder_get_velocity(eEncoder encoder, short counter);
eEncoderDir encoder_get_dir(eEncoder encoder);

#endif /* __BSP_ENCODER_H */






