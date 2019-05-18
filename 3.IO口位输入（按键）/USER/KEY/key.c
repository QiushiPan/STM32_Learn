/**
  ******************************************************************************
  * @file    key.c
  * @author  xxx
  * @version Vx.x
  * @date    xxxx-xx-xx
  * @brief   xxx.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
 
/* Includes ------------------------------------------------------------------*/
#include "key.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  按键Key 配置.
  *     I/O: Key1 - PB8
  *          Key2 - PB9
  *          Key3 - PB10
  *          Key4 - PB11
  * @param  无.
  * @retval 无.
  */
void Key_Cfg(void)
{
    GPIO_InitTypeDef key_gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /* 按键I/O配置 */
    key_gpio.GPIO_Pin  = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
    key_gpio.GPIO_Mode = GPIO_Mode_IPU;                 // 上拉输入
    GPIO_Init(GPIOB, &key_gpio);
}
/******************************** END OF FILE *********************************/
