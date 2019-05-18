#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "exti.h" 
#include "stm32f10x.h"

int main(void)
{	
 
	delay_init();	    	 //延时函数初始化	
	NVIC_Configuration();// 设置中断优先级分组  
	uart_init(9600);	 //串口初始化为9600
	LED_Cfg();		  	 //初始化与LED连接的硬件接口 
 	EXTIX_Init();		//外部中断初始化
  LED1_ON;				//点亮LED
	while(1)
	{	    
		printf("OK\n");	
		delay_ms(1000);	  
	} 
}
