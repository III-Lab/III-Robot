/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define IIIRobot_DEBUG
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_5
#define LED1_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_6
#define LED2_GPIO_Port GPIOE
#define KEY1_Pin GPIO_PIN_8
#define KEY1_GPIO_Port GPIOI
#define KEY2_Pin GPIO_PIN_13
#define KEY2_GPIO_Port GPIOC
#define KEY3_Pin GPIO_PIN_10
#define KEY3_GPIO_Port GPIOI
#define KEY4_Pin GPIO_PIN_11
#define KEY4_GPIO_Port GPIOI
#define MPU6050_SDA_Pin GPIO_PIN_0
#define MPU6050_SDA_GPIO_Port GPIOF
#define MPU6050_SCL_Pin GPIO_PIN_1
#define MPU6050_SCL_GPIO_Port GPIOF
#define MRB_EN1_Pin GPIO_PIN_0
#define MRB_EN1_GPIO_Port GPIOA
#define MLB_EN2_Pin GPIO_PIN_3
#define MLB_EN2_GPIO_Port GPIOH
#define MLB_EN1_Pin GPIO_PIN_4
#define MLB_EN1_GPIO_Port GPIOH
#define MRT_EN2_Pin GPIO_PIN_5
#define MRT_EN2_GPIO_Port GPIOH
#define BEEP_Pin GPIO_PIN_2
#define BEEP_GPIO_Port GPIOB
#define MRT_EN1_Pin GPIO_PIN_15
#define MRT_EN1_GPIO_Port GPIOF
#define Debug_TX_Pin GPIO_PIN_10
#define Debug_TX_GPIO_Port GPIOB
#define Debug_RX_Pin GPIO_PIN_11
#define Debug_RX_GPIO_Port GPIOB
#define EncoderLTA_Pin GPIO_PIN_10
#define EncoderLTA_GPIO_Port GPIOH
#define EncoderLTB_Pin GPIO_PIN_11
#define EncoderLTB_GPIO_Port GPIOH
#define LED3_Pin GPIO_PIN_12
#define LED3_GPIO_Port GPIOB
#define MLT_EN1_Pin GPIO_PIN_12
#define MLT_EN1_GPIO_Port GPIOD
#define MLT_EN2_Pin GPIO_PIN_13
#define MLT_EN2_GPIO_Port GPIOD
#define EncoderLBA_Pin GPIO_PIN_6
#define EncoderLBA_GPIO_Port GPIOC
#define EncoderLBB_Pin GPIO_PIN_7
#define EncoderLBB_GPIO_Port GPIOC
#define EncoderRBA_Pin GPIO_PIN_8
#define EncoderRBA_GPIO_Port GPIOA
#define EncoderRBB_Pin GPIO_PIN_9
#define EncoderRBB_GPIO_Port GPIOA
#define MRB_EN2_Pin GPIO_PIN_10
#define MRB_EN2_GPIO_Port GPIOA
#define MLT_PWM_Pin GPIO_PIN_2
#define MLT_PWM_GPIO_Port GPIOI
#define MPU6050_INT_Pin GPIO_PIN_3
#define MPU6050_INT_GPIO_Port GPIOI
#define EncoderRTA_Pin GPIO_PIN_15
#define EncoderRTA_GPIO_Port GPIOA
#define RELAY1_Pin GPIO_PIN_10
#define RELAY1_GPIO_Port GPIOG
#define EncoderRTB_Pin GPIO_PIN_3
#define EncoderRTB_GPIO_Port GPIOB
#define MRB_PWM_Pin GPIO_PIN_5
#define MRB_PWM_GPIO_Port GPIOI
#define MRT_PWM_Pin GPIO_PIN_6
#define MRT_PWM_GPIO_Port GPIOI
#define MLB_PWM_Pin GPIO_PIN_7
#define MLB_PWM_GPIO_Port GPIOI

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
