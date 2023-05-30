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


#define ENCODER_LINES	500	/* GMR±àÂëÆ÷500Ïß */
#define MOTOR_LINES		27

#define CALC_VELO(m)	1000/ENCODER_LINES/MOTOR_LINES/4/m

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






