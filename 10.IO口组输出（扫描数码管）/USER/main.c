#include "stm32f10x.h"
#include "led_sd.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"

int main(void)
{
    uint8_t i,j=4;              // ѭ������
    LED_SD_Cfg();            // ����ܳ�ʼ������ 
	  delay_init();
    
    /* ��1λ��ʾ�������֣�0.-9. */
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
