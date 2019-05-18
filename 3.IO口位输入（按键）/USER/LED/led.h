/**
  ******************************************************************************
  * @file    led.h
  * @author  xxx
  * @version Vx.x
  * @date    xxxx-xx-xx
  * @brief   xxx.
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LED_H
#define __LED_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* 控制LED1-LED4(直接操作寄存器) */
#define LED1_TOGGLE  GPIOA->ODR ^= GPIO_Pin_0    // PA0输出相反状态 - LED1状态反转
#define LED1_OFF     GPIOA->BSRR = GPIO_Pin_0    // PA0输出高电平 - LED1关
#define LED1_ON      GPIOA->BRR  = GPIO_Pin_0    // PA0输出低电平 - LED1开

#define LED2_TOGGLE  GPIOA->ODR ^= GPIO_Pin_1    // LED2状态反转
#define LED2_OFF     GPIOA->BSRR = GPIO_Pin_1    // LED2关
#define LED2_ON      GPIOA->BRR  = GPIO_Pin_1    // LED2开

#define LED3_TOGGLE  GPIOA->ODR ^= GPIO_Pin_2
#define LED3_OFF     GPIOA->BSRR = GPIO_Pin_2
#define LED3_ON      GPIOA->BRR  = GPIO_Pin_2

#define LED4_TOGGLE  GPIOA->ODR ^= GPIO_Pin_3
#define LED4_OFF     GPIOA->BSRR = GPIO_Pin_3
#define LED4_ON      GPIOA->BRR  = GPIO_Pin_3

/* 控制LED5-LED8(调用库函数) */
#define LED5_OFF     GPIO_SetBits(GPIOA, GPIO_Pin_4)    // PA4输出高电平 - LED5关
#define LED5_ON      GPIO_ResetBits(GPIOA, GPIO_Pin_4)  // PA4输出低电平 - LED5开

#define LED6_OFF     GPIO_SetBits(GPIOA, GPIO_Pin_5)
#define LED6_ON      GPIO_ResetBits(GPIOA, GPIO_Pin_5)

#define LED7_OFF     GPIO_SetBits(GPIOA, GPIO_Pin_6)
#define LED7_ON      GPIO_ResetBits(GPIOA, GPIO_Pin_6)

#define LED8_OFF     GPIO_SetBits(GPIOA, GPIO_Pin_7)
#define LED8_ON      GPIO_ResetBits(GPIOA, GPIO_Pin_7)

/* Exported functions ------------------------------------------------------- */
void LED_Cfg(void);

#endif /* __LED_H */
/******************************** END OF FILE *********************************/
