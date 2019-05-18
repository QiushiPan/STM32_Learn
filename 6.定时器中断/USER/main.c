#include "led.h"
#include "delay.h"
#include "sys.h"
#include "timer.h"

 int main(void)
 {	
	delay_init();	    	 //��ʱ������ʼ��
	NVIC_Configuration();//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	TIM3_Int_Init(5000,7199);//10Khz�ļ���Ƶ�ʣ�������5000Ϊ500ms  
   	while(1)
	{
		LED0=!LED0;
		delay_ms(50);		   
	}
}
