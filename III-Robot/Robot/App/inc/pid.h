// Header:
// File Name: 
// Author:
// Date:

#ifndef __PID_H
#define	__PID_H

#define PID_CONV_REAL 1.0

typedef struct _pid{
	float set_val;          /* 设定值 		*/
	float actual_val;		/* 实际值		*/
	float err;				/* 偏差值		*/
	float err_last;         /* 上一次偏差值	*/
	float err_next;         /* 下一次偏差值	*/
	float Kp, Ki, Kd;		/* 设定值		*/
	float output;           /* 实际转换值	*/	
	float integral;			/* 积分累积		*/
	float umax;				/* 偏差上限值	*/
	float umin;				/* 偏差下限值	*/
}PID_t;

void  pid_init(PID_t *pid, float kp, float ki, float kd);
float pid_execute(PID_t *pid, float val);

#endif /* __PID_H */


