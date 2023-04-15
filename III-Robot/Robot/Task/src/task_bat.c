
/****************************************Copyright (c)****************************************************
 
**--------------File Info---------------------------------------------------------------------------------
** File name:                 
** Last modified Date:          
** Last Version:           
** Descriptions:           
**                        
**--------------------------------------------------------------------------------------------------------
** Created by:               yunke120
** Created date:           2023/04/15
** Version:                  1.0
** Descriptions:          
**--------------------------------------------------------------------------------------------------------*/

#include "task_bat.h"

#include "bsp_ina226.h"
#include "stdio.h"

extern UART_HandleTypeDef huart2;
extern uint8_t rx_buffer[64];
extern uint32_t rx_index;


osThreadId_t bat_handle;
const osThreadAttr_t bat_attr = {
  .name = "bat",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow1,
};


static void bat_entry(void *param)
{
	uint8_t ret;
	float number;
	ina226_uart_initEx();
	
	for(;;)
	{
		ina226_uart_printf("%s\r\n", INA226_GET_VOLTAGE);	/* 获取输入电压值 */
		osDelay(50);
		ret = ina226_get_response(&number);
		if(ret != 0 )
		{
			printf("get voltage failed.\r\n");
		}
		else
		{
			printf("volatge = %.3f\r\n", number);
		}
		
		ina226_uart_printf("%s\r\n", INA226_GET_CURRENT);	/* 获取输入电流值 */
		osDelay(50);
		ret = ina226_get_response(&number);
		if(ret != 0 )
		{
			printf("get current failed.\r\n");
		}
		else
		{
			printf("current = %.3f\r\n", number);
		}
		
		ina226_uart_printf("%s\r\n", INA226_GET_POWER);	/* 获取输入电流值 */
		osDelay(50);
		ret = ina226_get_response(&number);
		if(ret != 0 )
		{
			printf("get power failed.\r\n");
		}
		else
		{
			printf("power = %.3f\r\n", number);
		}
		
		osDelay(2000);									/* 更新频率 */
	}
}


void create_bat_thread(void)
{
	bat_handle = osThreadNew(bat_entry, NULL, &bat_attr);
	if(bat_handle == NULL)
		printf("<create> [task]	: bat		> 0\r\n");
	else
		printf("<create> [task]	: bat		> 1\r\n");
}



