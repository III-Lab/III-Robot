
#ifndef __PROTOCOL_H
#define __PROTOCOL_H
#include "bsp_protocol.h"

#define PROTOCOL_MSG_LEN			USART1_RX_LEN

#define FrameHeader0				0xAA
#define FrameHeader1				0x55
#define FrameTail					0xDD

typedef enum
{
	PC2R	= 	0x00,
	R2PC
}eFrameType;

typedef enum
{
	DEVNone  = 0x00,
	Robot		,
	PTZ			,
	RoboticArm	,
	Battery		,
}eDEVICE;


typedef enum
{
	HandShake = 0xFF,
}eRobot;

void protocol_init(void);
unsigned char _data_check(unsigned char* buf, int len);
void protocol_send(eDEVICE device, unsigned char cmd, unsigned char *userdata);


#endif /* __PROTOCOL_H */


