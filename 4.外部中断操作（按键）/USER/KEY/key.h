/**
  ******************************************************************************
  * @file    key.h
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
#ifndef __KEY_H
#define __KEY_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* ����״̬ */
#define KEY_DN  0       // ��������
#define KEY_UP  1       // �����ɿ�

/* Exported macro ------------------------------------------------------------*/
#define KEY2_STA  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9)  // ������Key2״̬ 
#define KEY3_STA  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) // ������Key3״̬ 
#define KEY4_STA  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) // ������Key3״̬ 
/* Exported functions ------------------------------------------------------- */
void Key_Cfg(void);

#endif /* __KEY_H */
/******************************** END OF FILE *********************************/
