#include "led.h"
#include "delay.h"
#include "sys.h"
#include "key.h"
#include "usart.h"
#include "exti.h" 
#include "stm32f10x.h"

int main(void)
{	
 
	delay_init();	    	 //��ʱ������ʼ��	
	NVIC_Configuration();// �����ж����ȼ�����  
	uart_init(9600);	 //���ڳ�ʼ��Ϊ9600
	LED_Cfg();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ� 
 	EXTIX_Init();		//�ⲿ�жϳ�ʼ��
  LED1_ON;				//����LED
	while(1)
	{	    
		printf("OK\n");	
		delay_ms(1000);	  
	} 
}
