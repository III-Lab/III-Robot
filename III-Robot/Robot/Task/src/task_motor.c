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
#include "bsp_led.h"
#include "bsp_l298n.h"
#include "bsp_encoder.h"

// g»Ò»Ò
osThreadId_t motor_handle;
const osThreadAttr_t motor_attr = {
  .name = "motor",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};


static void motor_entry(void *param)
{
	motor_set_velocity(Wheel_LT, 500);
	motor_set_enable(Wheel_LT, eWheelEnable);
	motor_set_dir(Wheel_LT, Wheel_Foreward);
	
	encoder_set_enable(Encoder_LT, eEncoderEnable);
	
	for(;;)
	{
		
		LED3_Toggle();
		print_encoder();
		osDelay(500);
	}
}


void create_motor_thread(void)
{
	motor_handle = osThreadNew(motor_entry, NULL, &motor_attr);
	if(motor_handle == NULL)
		printf("create motor thread failed\r\n");
	else
		printf("create motor thread success\r\n");
}

