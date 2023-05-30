#ifndef __BSP_RELAY_H
#define	__BSP_RELAY_H

#include "main.h"

#define RELAY1_ON()			HAL_GPIO_WritePin(RELAY1_GPIO_Port, RELAY1_Pin, GPIO_PIN_SET)
#define RELAY1_OFF()		HAL_GPIO_WritePin(RELAY1_GPIO_Port, RELAY1_Pin, GPIO_PIN_RESET)


#endif /* __BSP_RELAY_H */

