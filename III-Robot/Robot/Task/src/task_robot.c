/****************************************Copyright (c)****************************************************
 
**--------------File Info---------------------------------------------------------------------------------
** File name:                 
** Last modified Date:          
** Last Version:           
** Descriptions:           
**                        
**--------------------------------------------------------------------------------------------------------
** Created by:               yunke120
** Created date:           2023/04/09
** Version:                  1.0
** Descriptions:          
**--------------------------------------------------------------------------------------------------------*/

#include "task_robot.h"
#include "stdio.h"
#include "stdlib.h"
#include "tim.h"
#include "i2c.h"
#include "pid.h"
#include "robot.h"
#include "protocol.h"
#include "bsp_led.h"
#include "bsp_l298n.h"
#include "bsp_encoder.h"
#include "bsp_mpu6050.h"


//static MPU6050_t MPU6050;
//static PID_t	 *pid_LT;

/**
 * 电机运行任务
 */
osThreadId_t robot_handle;
const osThreadAttr_t robot_attr = {
  .name = "robot",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};

/**
 * 编码器软定时器
*/
osTimerId_t timer_decoder_handle;
const osTimerAttr_t time_decoder_attr = {
  .name = "timer_decoder"
};

osMessageQueueId_t robotQueueHandle;
const osMessageQueueAttr_t robotQueue_attributes = {
  .name = "robotQueue"
};


static void timer_decoder_callback(void *param)
{
	short counter_LT = encoder_get_counter(Encoder_LT, 100);
	float vel_LT = encoder_get_velocity(Encoder_LT, counter_LT);
	eEncoderDir dir_LT = encoder_get_dir(Encoder_LT);
	
//	short counter_RT = encoder_get_counter(Encoder_RT, 100);
//	float vel_RT = encoder_get_velocity(Encoder_RT, counter_RT);
//	eEncoderDir dir_RT = encoder_get_dir(Encoder_RT);
//	
//	short counter_LB = encoder_get_counter(Encoder_LB, 100);
//	float vel_LB = encoder_get_velocity(Encoder_LB, counter_LB);
//	eEncoderDir dir_LB = encoder_get_dir(Encoder_LB);
//	
//	short counter_RB = encoder_get_counter(Encoder_RB, 100);
//	float vel_RB = encoder_get_velocity(Encoder_RB, counter_RB);
//	eEncoderDir dir_RB = encoder_get_dir(Encoder_RB);
	
	printf("\r\n");
	printf("counter_LT = %d, vel = %.3fr/s, dir = %s\r\n", counter_LT, vel_LT, (dir_LT==eEncoderForeward)?"foreward":"backward");
//	printf("counter_RT = %d, vel = %.3fr/s, dir = %s\r\n", counter_RT, vel_RT, (dir_RT==eEncoderForeward)?"foreward":"backward");
//	printf("counter_LB = %d, vel = %.3fr/s, dir = %s\r\n", counter_LB, vel_LB, (dir_LB==eEncoderForeward)?"foreward":"backward");
//	printf("counter_RB = %d, vel = %.3fr/s, dir = %s\r\n", counter_RB, vel_RB, (dir_RB==eEncoderForeward)?"foreward":"backward");

}

static void robot_entry(void *param)
{
	uint8_t buf[PROTOCOL_MSG_LEN] = {0};
	uint8_t data[4] = {0x00, 0x00, 0x00, 0x00};
//	pid_LT = (struct _pid *)malloc(sizeof(pid_LT));
//	pid_init(pid_LT, 0.2,0.2,0.2);
	

	motor_set_velocity(Wheel_LT, VelocityMin);				
	motor_set_enable(Wheel_LT, eWheelEnable);
	
	motor_set_velocity(Wheel_RT, VelocityMin);       		
	motor_set_enable(Wheel_RT, eWheelEnable);

	motor_set_velocity(Wheel_LB, VelocityMin);				
	motor_set_enable(Wheel_LB, eWheelEnable);

	motor_set_velocity(Wheel_RB, VelocityMin);				
	motor_set_enable(Wheel_RB, eWheelEnable);

//	encoder_set_enable(Encoder_LT, eEncoderEnable);
//	encoder_set_enable(Encoder_RT, eEncoderEnable);
//	encoder_set_enable(Encoder_LB, eEncoderEnable);
//	encoder_set_enable(Encoder_RB, eEncoderEnable);

	while(1)
	{
        if(osMessageQueueGet(robotQueueHandle, buf, NULL, osWaitForever) == osOK)
        {
#if 0
			printf("robot [RX]: ");
			for(int i = 0; i < PROTOCOL_MSG_LEN; i++)
			{
				printf("%02x ", buf[i]);
			}
			printf("\r\n");
#endif
			switch(buf[4])
			{
				case HandShake:
					protocol_send(Robot, HandShake, data);
					break;
				default:
					robot_set_dir((eRobotDir)buf[4]);
					break;
			}
		}
	}
}


void create_robot_thread(void)
{
	robotQueueHandle = osMessageQueueNew (3, PROTOCOL_MSG_LEN*sizeof(uint8_t), &robotQueue_attributes);
	if(robotQueueHandle)
		printf("<create> [queue] : robot\t> 1\r\n");
	else
		printf("<create> [queue] : robot\t> 0\r\n");	

	robot_handle = osThreadNew(robot_entry, NULL, &robot_attr);
	
//	timer_decoder_handle = osTimerNew(	timer_decoder_callback, 
//										osTimerPeriodic, 
//										NULL, 
//										&time_decoder_attr);
//	
//	if(timer_decoder_handle == NULL)
//		printf("<create> [timer] : decoder	> 0\r\n");
//	else
//	{
//		printf("<create> [timer] : decoder	> 1\r\n");
//		osTimerStart(timer_decoder_handle, ECONDER_TIMING);
//	}


	
	if(robot_handle == NULL)
		printf("<create> [task]	: robot		> 0\r\n");
	else
		printf("<create> [task]	: robot		> 1\r\n");
}


/*
	while(MPU6050_Init(&hi2c2) == 1)
	{
		LED1_Toggle();
		osDelay(200);
	}
		// https://www.hackster.io/Kenan-Paralija/making-a-2wd-arduino-vehicle-drive-straight-ae40ee

		MPU6050_Read_All(&hi2c2, &MPU6050);
		MPU6050_Print(&MPU6050);
*/

