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

#include "task_motor.h"
#include "stdio.h"
#include "tim.h"
#include "i2c.h"
#include "bsp_led.h"
#include "bsp_l298n.h"
#include "bsp_encoder.h"
#include "bsp_mpu6050.h"

/**
 * 电机运行任务
 */
osThreadId_t motor_handle;
const osThreadAttr_t motor_attr = {
  .name = "motor",
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

static MPU6050_t MPU6050;

static void timer_decoder_callback(void *param)
{

	
	short counter_LT = encoder_get_counter(Encoder_LT, 100);
	eEncoderDir dir_LT = encoder_get_dir(Encoder_LT);
	
	short counter_RT = encoder_get_counter(Encoder_RT, 100);
	eEncoderDir dir_RT = encoder_get_dir(Encoder_RT);
	
	short counter_LB = encoder_get_counter(Encoder_LB, 100);
	eEncoderDir dir_LB = encoder_get_dir(Encoder_LB);
	
	short counter_RB = encoder_get_counter(Encoder_RB, 100);
	eEncoderDir dir_RB = encoder_get_dir(Encoder_RB);
	
	printf("---------- motor state --------- \r\n");
	printf("counter_LT = %d, dir = %s\r\n", counter_LT, (dir_LT==eEncoderForeward)?"foreward":"backward");
	printf("counter_RT = %d, dir = %s\r\n", counter_RT, (dir_RT==eEncoderForeward)?"foreward":"backward");
	printf("counter_LB = %d, dir = %s\r\n", counter_LB, (dir_LB==eEncoderForeward)?"foreward":"backward");
	printf("counter_RB = %d, dir = %s\r\n", counter_RB, (dir_RB==eEncoderForeward)?"foreward":"backward");

	
	
}
/*


---------- motor state --------- Wheel_Foreward

Encoder_LT : -209
Encoder_RT : -186
Encoder_LB : -198
Encoder_RB : -256
vel_LT = -0.039 r/s, dir = foreward
vel_RT = -0.034 r/s, dir = foreward
vel_LB = -0.037 r/s, dir = foreward
vel_RB = -0.047 r/s, dir = foreward


---------- motor state --------- Wheel_Backward

Encoder_LT : 191
Encoder_RT : 183
Encoder_LB : 237
Encoder_RB : 258
vel_LT = 0.035 r/s, dir = backward
vel_RT = 0.034 r/s, dir = backward
vel_LB = 0.044 r/s, dir = backward
vel_RB = 0.048 r/s, dir = backward

*/
static void motor_entry(void *param)
{
	motor_set_velocity(Wheel_LT, 500);				
	motor_set_enable(Wheel_LT, eWheelEnable);
	motor_set_dir(Wheel_LT, Wheel_Foreward);
	
	motor_set_velocity(Wheel_RT, 500);       		
	motor_set_enable(Wheel_RT, eWheelEnable);
	motor_set_dir(Wheel_RT, Wheel_Backward);

	motor_set_velocity(Wheel_LB, 500);				
	motor_set_enable(Wheel_LB, eWheelEnable);
	motor_set_dir(Wheel_LB, Wheel_Backward);

	motor_set_velocity(Wheel_RB, 500);				
	motor_set_enable(Wheel_RB, eWheelEnable);
	motor_set_dir(Wheel_RB, Wheel_Backward);
	
	encoder_set_enable(Encoder_LT, eEncoderEnable);
	encoder_set_enable(Encoder_RT, eEncoderEnable);
	encoder_set_enable(Encoder_LB, eEncoderEnable);
	encoder_set_enable(Encoder_RB, eEncoderEnable);

	
	for(;;)
	{
		LED1_Toggle();
		osDelay(500);
	}
}


void create_motor_thread(void)
{
	motor_handle = osThreadNew(motor_entry, NULL, &motor_attr);
	
	timer_decoder_handle = osTimerNew(	timer_decoder_callback, 
										osTimerPeriodic, 
										NULL, 
										&time_decoder_attr);
	
	if(timer_decoder_handle == NULL)
		printf("<create> [timer] : decoder	> 0\r\n");
	else
	{
		printf("<create> [timer] : decoder	> 1\r\n");
		osTimerStart(timer_decoder_handle, 100);
	}


	
	if(motor_handle == NULL)
		printf("<create> [task]	: motor		> 0\r\n");
	else
		printf("<create> [task]	: motor		> 1\r\n");
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

