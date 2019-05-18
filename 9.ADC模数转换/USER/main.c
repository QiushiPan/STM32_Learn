#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "adc.h"

   	
 int main(void)
 { 
	u16 adcx;
	float temp;
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
 	Adc_Init();		  		//ADC��ʼ��	    	    
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_1,10);
		printf("������ADCֵ��%d\r\n",adcx);
		temp=(float)adcx*(3.3/4096);
		adcx=temp;
		printf("��õĵ�ѹΪ%f��\r\n\r\n",temp);
		delay_ms(500);	
	}											    
}	
