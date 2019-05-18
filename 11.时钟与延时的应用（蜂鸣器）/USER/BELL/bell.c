/**
  ******************************************************************************
  * @file    bell.c
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
#include "bell.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  蜂鸣器配置.
  *     I/O: 蜂鸣器 - PB0
  * @param  无.
  * @retval 无.
  */
void Bell_Cfg(void)
{
    GPIO_InitTypeDef bell_gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /* 蜂鸣器I/O配置 */    
    bell_gpio.GPIO_Pin   = GPIO_Pin_0;	
    bell_gpio.GPIO_Mode  = GPIO_Mode_Out_PP;     // 通用推挽输出
    bell_gpio.GPIO_Speed = GPIO_Speed_2MHz;      // 2MHz
    GPIO_Init(GPIOB, &bell_gpio);

    /* 配置完成后关闭蜂鸣器 */
    BELL_ON;
}
/******************************** END OF FILE *********************************/
