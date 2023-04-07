#include "bsp_key.h"
#include "stdio.h"
#include "cmsis_os.h"
// 初始化按键结构体
void key_Init(KeyTypeDef *key, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
    key->GPIOx = GPIOx;
    key->GPIO_Pin = GPIO_Pin;
    key->debounceTime = KEY_DEBOUNCE_DELAY;
    key->state = KEY_RELEASED;
    key->timestamp = xTaskGetTickCount();
}

// 获取按键状态
KeyStateTypeDef key_GetState(KeyTypeDef *key)
{
    uint32_t current_time = xTaskGetTickCount();
    switch (key->state) {
        case KEY_RELEASED:
            if (HAL_GPIO_ReadPin(key->GPIOx, key->GPIO_Pin) == GPIO_PIN_RESET) {
                key->state = KEY_PRESSING;
                key->timestamp = current_time;
            }
            break;

        case KEY_PRESSED:
            if (HAL_GPIO_ReadPin(key->GPIOx, key->GPIO_Pin) == GPIO_PIN_SET) {
                key->state = KEY_RELEASING;
                key->timestamp = current_time;
            }
            break;

        case KEY_PRESSING:
            if (HAL_GPIO_ReadPin(key->GPIOx, key->GPIO_Pin) == GPIO_PIN_RESET) {
                if ((current_time - key->timestamp) >= key->debounceTime) {
                    key->state = KEY_PRESSED;
                }
            } else {
                key->state = KEY_RELEASED;
            }
            break;

        case KEY_RELEASING:
            if (HAL_GPIO_ReadPin(key->GPIOx, key->GPIO_Pin) == GPIO_PIN_SET) {
                if ((current_time - key->timestamp) >= key->debounceTime) {
                    key->state = KEY_RELEASED;
                }
            } else {
                key->state = KEY_PRESSED;
            }
            break;
    }

    return key->state;
}


