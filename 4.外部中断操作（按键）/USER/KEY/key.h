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
/* °´¼ü×´Ì¬ */
#define KEY_DN  0       // °´¼ü°´ÏÂ
#define KEY_UP  1       // °´¼üËÉ¿ª

/* Exported macro ------------------------------------------------------------*/
#define KEY2_STA  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9)  // ¶Á°´¼üKey2×´Ì¬ 
#define KEY3_STA  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10) // ¶Á°´¼üKey3×´Ì¬ 
#define KEY4_STA  GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) // ¶Á°´¼üKey3×´Ì¬ 
/* Exported functions ------------------------------------------------------- */
void Key_Cfg(void);

#endif /* __KEY_H */
/******************************** END OF FILE *********************************/
