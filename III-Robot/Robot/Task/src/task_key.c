#include "task_key.h"
#include "bsp_key.h"
#include "bsp_beep.h"
#include "stdio.h"

osThreadId_t key_handle;

const osThreadAttr_t key_attr = {
	.name = "key",
	.stack_size = 128 * 4,
	.priority = (osPriority_t) osPriorityHigh1,
};

static void key_entry(void *param)
{
	KeyTypeDef key[4] = {0};
	key_Init(&key[0], KEY1_GPIO_Port, KEY1_Pin);
	key_Init(&key[1], KEY2_GPIO_Port, KEY2_Pin);
	key_Init(&key[2], KEY3_GPIO_Port, KEY3_Pin);
	key_Init(&key[3], KEY4_GPIO_Port, KEY4_Pin);
	
	while(1)
	{
		for(int i = 0; i < 4; i++)
		{
			KeyStateTypeDef state = key_GetState(&key[i]);
			
			switch (state)
            {
            	case KEY_PRESSED:
//					printf("key%d KEY_PRESSED\r\n", i+1);
					BEEP_ON();
            		break;
//            	case KEY_PRESSING:
//					printf("key%d KEY_PRESSING\r\n", i+1);
//            		break;
				case KEY_RELEASING:
					BEEP_OFF();
//					printf("key%d KEY_RELEASING\r\n", i+1);
					break;
            	default:
            		break;
            }
		}
		osDelay(80);
	}
}

void create_key_thread(void)
{
	key_handle = osThreadNew(key_entry, NULL, &key_attr);
	if(key_handle == NULL)
		printf("create key thread failed\r\n");
	else
		printf("create key thread success\r\n");
}


