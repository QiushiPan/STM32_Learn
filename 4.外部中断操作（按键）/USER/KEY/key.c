#include "key.h"

void Key_Cfg(void)
{
    GPIO_InitTypeDef key_gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /* 按键I/O配置 */
    key_gpio.GPIO_Pin  = GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
    key_gpio.GPIO_Mode = GPIO_Mode_IPU;                 // 上拉输入
    GPIO_Init(GPIOB, &key_gpio);
}
