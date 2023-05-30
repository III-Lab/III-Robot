#ifndef __BSP_KEY_H
#define	__BSP_KEY_H

#include "main.h"

#define KEY_DEBOUNCE_DELAY 70  // ����ʱ�䣬��λΪ����

// ���尴��״̬ö������
typedef enum {
    KEY_RELEASED = 0,  // δ����
    KEY_PRESSED,       // �Ѱ���
    KEY_PRESSING,      // ���ڱ����£������У�
    KEY_RELEASING      // ���ڱ��ͷţ������У�
} KeyStateTypeDef;

// ���尴���ṹ������
typedef struct {
    GPIO_TypeDef *GPIOx;   // GPIO�˿ں�
    uint16_t GPIO_Pin;     // GPIO���ź�
    uint32_t debounceTime; // ����ʱ��
    KeyStateTypeDef state; // ��ǰ����״̬
    uint32_t timestamp;    // ���һ��״̬�ı��ʱ���
} KeyTypeDef;

void key_Init(KeyTypeDef *key, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
KeyStateTypeDef key_GetState(KeyTypeDef *key);


#endif /* __BSP_KEY_H */




