/****************************************Copyright (c)****************************************************
 
**--------------File Info---------------------------------------------------------------------------------
** File name:                 
** Last modified Date:          
** Last Version:           
** Descriptions:           
**                        
**--------------------------------------------------------------------------------------------------------
** Created by:               yunke120
** Created date:             2023/05/31
** Version:                  1.0
** Descriptions:          
**--------------------------------------------------------------------------------------------------------*/

#include "pid.h"

void pid_init(PID_t *pid, float kp, float ki, float kd)
{
	pid->set_val = 0.0f;
	pid->actual_val = 0.0f;
	pid->err = 0.0f;
	pid->err_last = 0.0f;
	pid->err_next = 0.0f;
	pid->Kp = kp;
	pid->Ki = ki;
	pid->Kd = kd;
	pid->output = 0.0f;
	pid->integral = 0.0f;
	pid->umax = 0.0f;
	pid->umin = 0.0f;
}

/*
	PID
*/
float pid_execute(PID_t *pid, float val)
{
	pid->set_val = val;
	pid->err = pid->set_val - pid->actual_val;
	pid->integral += pid->err;
	pid->output = pid->Kp * pid->err + pid->Ki * pid->integral + pid->Kd * (pid->err - pid->err_last);
	pid->err_last = pid->err;
	pid->actual_val = pid->output * PID_CONV_REAL;
	return pid->actual_val;
}


#if 0
#include "stdio.h"
#include "stdlib.h"
int main()
{
	int count = 0;
	PID_t *pid = (struct _pid *)malloc(sizeof(pid));
	pid_init(pid, 0.2,0.2,0.2);
	while (count < 100)
	{
		printf("%d ", count);
		float speed = pid_execute(pid, 300);
		printf("%.2f\r\n",speed);
		count++;
	}
	return 0;
}
#endif