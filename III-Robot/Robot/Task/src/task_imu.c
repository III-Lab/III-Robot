#include "task_imu.h"
#include "bsp_imu.h"
#include "bsp_led.h"
#include "stdio.h"

osThreadId_t imu_handle;
const osThreadAttr_t imu_attr = {
  .name = "imu",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};


static void imu_entry(void *param)
{
	imu_init();
	for(;;)
	{
//		if(data_check() == 0)
//		{
//			IMU_t imu;
//			imu_get_posture(&imu);
//			printf("roll = %.3f\tpitch = %.3f\theading = %.3f\r\n", imu.roll, imu.pitch, imu.heading);
//			imu_rx_reset();
//		}
//		else
//		{
			printf("1");
//		}	
		osDelay(100);
	}
}


void create_imu_thread(void)
{
	imu_handle = osThreadNew(imu_entry, NULL, &imu_attr);
	if(imu_handle == NULL)
		printf("<create> [task]	: imu		> 0\r\n");
	else
		printf("<create> [task]	: imu		> 1\r\n");
}


