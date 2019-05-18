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
/* ����LED1-LED4(ֱ�Ӳ����Ĵ���) */
#define LED1_TOGGLE  GPIOA->ODR ^= GPIO_Pin_0    // PA0����෴״̬ - LED1״̬��ת
#define LED1_OFF     GPIOA->BSRR = GPIO_Pin_0    // PA0����ߵ�ƽ - LED1��
#define LED1_ON      GPIOA->BRR  = GPIO_Pin_0    // PA0����͵�ƽ - LED1��

#define LED2_TOGGLE  GPIOA->ODR ^= GPIO_Pin_1    // LED2״̬��ת
#define LED2_OFF     GPIOA->BSRR = GPIO_Pin_1    // LED2��
#define LED2_ON      GPIOA->BRR  = GPIO_Pin_1    // LED2��

#define LED3_TOGGLE  GPIOA->ODR ^= GPIO_Pin_2
#define LED3_OFF     GPIOA->BSRR = GPIO_Pin_2
#define LED3_ON      GPIOA->BRR  = GPIO_Pin_2

#define LED4_TOGGLE  GPIOA->ODR ^= GPIO_Pin_3
#define LED4_OFF     GPIOA->BSRR = GPIO_Pin_3
#define LED4_ON      GPIOA->BRR  = GPIO_Pin_3

/* ����LED5-LED8(���ÿ⺯��) */
#define LED5_OFF     GPIO_SetBits(GPIOA, GPIO_Pin_4)    // PA4����ߵ�ƽ - LED5��
#define LED5_ON      GPIO_ResetBits(GPIOA, GPIO_Pin_4)  // PA4����͵�ƽ - LED5��

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
