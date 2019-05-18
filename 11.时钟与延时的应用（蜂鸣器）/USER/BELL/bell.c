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
  * @brief  ����������.
  *     I/O: ������ - PB0
  * @param  ��.
  * @retval ��.
  */
void Bell_Cfg(void)
{
    GPIO_InitTypeDef bell_gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    /* ������I/O���� */    
    bell_gpio.GPIO_Pin   = GPIO_Pin_0;	
    bell_gpio.GPIO_Mode  = GPIO_Mode_Out_PP;     // ͨ���������
    bell_gpio.GPIO_Speed = GPIO_Speed_2MHz;      // 2MHz
    GPIO_Init(GPIOB, &bell_gpio);

    /* ������ɺ�رշ����� */
    BELL_ON;
}
/******************************** END OF FILE *********************************/
