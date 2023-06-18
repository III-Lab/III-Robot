// Header:
// File Name: 
// Author:
// Date:

#ifndef __PID_H
#define	__PID_H

#define PID_CONV_REAL 1.0

typedef struct _pid{
	float set_val;          /* �趨ֵ 		*/
	float actual_val;		/* ʵ��ֵ		*/
	float err;				/* ƫ��ֵ		*/
	float err_last;         /* ��һ��ƫ��ֵ	*/
	float err_next;         /* ��һ��ƫ��ֵ	*/
	float Kp, Ki, Kd;		/* �趨ֵ		*/
	float output;           /* ʵ��ת��ֵ	*/	
	float integral;			/* �����ۻ�		*/
	float umax;				/* ƫ������ֵ	*/
	float umin;				/* ƫ������ֵ	*/
}PID_t;

void  pid_init(PID_t *pid, float kp, float ki, float kd);
float pid_execute(PID_t *pid, float val);

#endif /* __PID_H */


