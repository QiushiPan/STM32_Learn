#include "stm32f10x.h"
#include "led_sd.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"

int main(void)
{
    uint8_t i,j=4;              // 循环变量
    LED_SD_Cfg();            // 数码管初始化配置 
	  delay_init();
    
    /* 第1位显示递增数字：0.-9. */
    while(1)
		{
			for (i = 0; i < 10; i++)
			{
				LED_SD_Dpy(1, i);
        delay_ms(20);
      }
      for (i=0; i < 20; i++)
      {
        LED_SD_Dpy(j--, i%10);
        delay_ms(20);
			  if(j==0)
				j=4;
      }
			for (i = 0; i <200; i++)
			{
				for (j = 0; j < 4; j++)
				{
					LED_SD_Dpy(j+1, j);
					delay_us(100);
				}
			}
	}
    
}
