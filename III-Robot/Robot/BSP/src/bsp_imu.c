
#include "bsp_imu.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

#ifndef PI
#define PI	3.141592653
#endif	

#define Rad2Degree	360/2/PI

extern UART_HandleTypeDef huart6;
extern DMA_HandleTypeDef hdma_usart6_rx;

/******************************************* USART DMA RECEIVE ***********************************************/
imu_rx_t imu_rx;

void imu_rx_reset(void)
{
	memset(&imu_rx, 0, sizeof(imu_rx));
	HAL_UARTEx_ReceiveToIdle_DMA(&IMU_USART_Handle, imu_rx.buf, IMU_RX_MAX_LEN);
	__HAL_DMA_DISABLE_IT(&IMU_DMA_USART_Handle, DMA_IT_HT);
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart->Instance == IMU_USART_Handle.Instance)
	{
//		printf("\t Size: %d\r\n", Size);
		printf("\t [1]: %d\r\n", imu_rx.buf[1]);
		imu_rx.sta.len = Size;
		imu_rx.sta.finsh = 1;
		imu_rx_reset();
//		for(int i = 0; i < imu_rx.sta.len; i++)
//		{
//			printf("%d ", imu_rx.buf[i]);
//		}
//		printf("\r\n");
	}
}

uint8_t imu_get_finished(void)
{
	return imu_rx.sta.finsh;
}

void imu_init(void)
{
	imu_rx_reset();
}

/******************************************* IMU DATA TRANSFORM ***********************************************/

uint8_t data_check(void)
{
	if(imu_get_finished() == 1)
	{
		if(imu_rx.buf[0] == 0xFC && imu_rx.buf[1] == 0x63 && imu_rx.buf[imu_rx.sta.len-1] == 0xFD)
		{
			return 0;
		}
		else
		{
			imu_rx_reset();
		}			
	}
	return 1;
}

static float data_trans(uint8_t data_1, uint8_t data_2, uint8_t data_3, uint8_t data_4)
{
    uint32_t transition_32;
	float tmp=0;
	int sign=0;
	int exponent=0;
	float mantissa=0;
    transition_32 = 0;
    transition_32 |=  data_4<<24;   
    transition_32 |=  data_3<<16; 
	transition_32 |=  data_2<<8;
	transition_32 |=  data_1;
    sign = (transition_32 & 0x80000000) ? -1 : 1;
	exponent = ((transition_32 >> 23) & 0xff) - 127;
	mantissa = 1 + ((float)(transition_32 & 0x7fffff) / 0x7fffff);
	tmp=sign * mantissa * pow(2, exponent);
	return tmp;
}

void imu_get_posture(IMU_t *imu)
{
	float r = data_trans(imu_rx.buf[7], imu_rx.buf[8], imu_rx.buf[9], imu_rx.buf[10]);
	float p = data_trans(imu_rx.buf[11], imu_rx.buf[12], imu_rx.buf[13], imu_rx.buf[14]);
	float h = data_trans(imu_rx.buf[15], imu_rx.buf[16], imu_rx.buf[17], imu_rx.buf[18]);
	imu->roll    = r * Rad2Degree;
	imu->pitch   = p * Rad2Degree;
	imu->heading = h * Rad2Degree;
}























