#include "stm32f10x.h"
#include "bell.h"
#include "delay.h"

void System_Cfg(void);
void Delay_ms(uint16_t u16_Time_ms);

int main(void)
{
   	  u16 i=0;
  	Bell_Cfg();           // 系统初始化
	  delay_init();	    	 //延时函数初始化	
    while (1)
    {
        for(i=0;i<500;i++)
			{
				delay_ms(1);
        BELL_ON;
        delay_ms(1);
        BELL_OFF;
			}
			for(i=0;i<250;i++)
			{
				delay_ms(2);
        BELL_ON;
        delay_ms(2);
        BELL_OFF;
			}
    }
}

