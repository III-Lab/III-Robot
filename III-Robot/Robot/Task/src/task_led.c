#include "task_led.h"
#include "bsp_led.h"
#include "stdio.h"

osThreadId_t led_handle;
const osThreadAttr_t led_attr = {
  .name = "led",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};


static void led_entry(void *param)
{
	for(;;)
	{
		LED1_Toggle();
		osDelay(300);
	}
}


void create_led_thread(void)
{
	led_handle = osThreadNew(led_entry, NULL, &led_attr);
	if(led_handle == NULL)
		printf("create led thread failed\r\n");
	else
		printf("create led thread success\r\n");
}


