#include "led.h"
#include "delay.h"
#include "sys.h"
#include "timer.h"

 int main(void)
 {	
	delay_init();	    	 //延时函数初始化
	NVIC_Configuration();//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	LED_Init();		  	//初始化与LED连接的硬件接口
	TIM3_Int_Init(5000,7199);//10Khz的计数频率，计数到5000为500ms  
   	while(1)
	{
		LED0=!LED0;
		delay_ms(50);		   
	}
}
