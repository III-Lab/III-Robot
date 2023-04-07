#ifndef __BSP_BEEP_H
#define	__BSP_BEEP_H

#include "main.h"

#define BEEP_ON()		HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET)
#define BEEP_OFF()		HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET)
#define BEEP_Toggle()	HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin)


#endif /* __BSP_BEEP_H */

