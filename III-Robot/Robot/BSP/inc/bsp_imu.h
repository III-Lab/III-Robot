
#ifndef __BSP_IMU_H
#define	__BSP_IMU_H

#include "main.h"

#define IMU_RX_MAX_LEN			64
#define IMU_USART_Handle		huart6
#define IMU_DMA_USART_Handle	hdma_usart6_rx


typedef struct {
	uint8_t buf[IMU_RX_MAX_LEN];
    struct
    {
        uint16_t len    : 15;                               /* 帧接收长度，sta[14:0] */
        uint16_t finsh  : 1;                                /* 帧接收完成标志，sta[15] */
    } sta;                                                  /* 帧状态信息 */
}imu_rx_t;

typedef struct {
	float roll;
	float pitch;
	float heading;
}IMU_t;

void imu_init(void);
void imu_rx_reset(void);
uint8_t imu_get_finished(void);

uint8_t data_check(void);
void imu_get_posture(IMU_t *imu);

#endif /* __BSP_IMU_H */

