#ifndef __BSP_KEY_H
#define	__BSP_KEY_H

#include "main.h"

#define KEY_DEBOUNCE_DELAY 70  // 消抖时间，单位为毫秒

// 定义按键状态枚举类型
typedef enum {
    KEY_RELEASED = 0,  // 未按下
    KEY_PRESSED,       // 已按下
    KEY_PRESSING,      // 正在被按下（消抖中）
    KEY_RELEASING      // 正在被释放（消抖中）
} KeyStateTypeDef;

// 定义按键结构体类型
typedef struct {
    GPIO_TypeDef *GPIOx;   // GPIO端口号
    uint16_t GPIO_Pin;     // GPIO引脚号
    uint32_t debounceTime; // 消抖时间
    KeyStateTypeDef state; // 当前按键状态
    uint32_t timestamp;    // 最近一次状态改变的时间戳
} KeyTypeDef;

void key_Init(KeyTypeDef *key, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
KeyStateTypeDef key_GetState(KeyTypeDef *key);


#endif /* __BSP_KEY_H */




