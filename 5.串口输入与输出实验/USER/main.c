#include "delay.h"
#include "sys.h"
#include "usart.h"



 int main(void)
 {	
	u8 t;
	u8 len;	
	u16 times=0; 
 
	 SystemInit();
	delay_init();	    	 //延时函数初始化	
	NVIC_Configuration();// 设置中断优先级分组
	uart_init(9600);	 //串口初始化为9600 
 
	while(1)
	{
		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			printf("您发送的消息为:\r\n");
			for(t=0;t<len;t++)
			{
				USART1->DR=USART_RX_BUF[t];
				while((USART1->SR&0X40)==0);//等待发送结束
			}
			printf("\r\n\r\n");//插入换行
			USART_RX_STA=0;
		}else
		{
			times++;
			if(times%200==0)printf("请输入数据,以回车键结束\r\n");  
			delay_ms(10);   
		}
	}	 
}
