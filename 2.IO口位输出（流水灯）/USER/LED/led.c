/**
  ******************************************************************************
  * @file    led.c
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
#include "led.h"   

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  LED ����.
  *     I/O: LED1 - PA0
  *          LED2 - PA1
  *          LED3 - PA2
  *          LED4 - PA3
  *          LED5 - PA4
  *          LED6 - PA5
  *          LED7 - PA6
  *          LED8 - PA7
  * @param  ��.
  * @retval ��.
  */
void LED_Cfg(void)
{
    GPIO_InitTypeDef led_gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   // ʹ�ܶ˿�A��ʱ��

    /* LED I/O���� */    
    led_gpio.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 
                        | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;	
    led_gpio.GPIO_Mode  = GPIO_Mode_Out_PP;     // ͨ���������
    led_gpio.GPIO_Speed = GPIO_Speed_2MHz;      // 2MHz
    GPIO_Init(GPIOA, &led_gpio);

    /* ������ɺ�ر�����LED */
    LED1_OFF;
    LED2_OFF;
    LED3_OFF;
    LED4_OFF;
    LED5_OFF;
    LED6_OFF;
    LED7_OFF;
    LED8_OFF;
}

/******************************** END OF FILE *********************************/
