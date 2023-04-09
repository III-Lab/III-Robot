// Header:		__BSP_ENCODER_H
// File Name: 	bsp_encoder.h
// Author:		yunke120
// Date:		2023/04/09

#ifndef __BSP_ENCODER_H
#define	__BSP_ENCODER_H

#include "main.h"

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

void encoder_set_enable(eEncoder encoder, eEncoderState state);



void print_encoder(void);
#endif /* __BSP_ENCODER_H */






