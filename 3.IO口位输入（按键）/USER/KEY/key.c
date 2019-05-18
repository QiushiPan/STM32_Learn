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
  * @brief  ����Key ����.
  *     I/O: Key1 - PB8
  *          Key2 - PB9
  *          Key3 - PB10
  *          Key4 - PB11
  * @param  ��.
  * @retval ��.
  */
void Key_Cfg(void)
{
    GPIO_InitTypeDef key_gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /* ����I/O���� */
    key_gpio.GPIO_Pin  = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
    key_gpio.GPIO_Mode = GPIO_Mode_IPU;                 // ��������
    GPIO_Init(GPIOB, &key_gpio);
}
/******************************** END OF FILE *********************************/
