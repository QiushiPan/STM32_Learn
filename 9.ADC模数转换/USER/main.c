#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "adc.h"

   	
 int main(void)
 { 
	u16 adcx;
	float temp;
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
 	Adc_Init();		  		//ADC初始化	    	    
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_1,10);
		printf("读到的ADC值是%d\r\n",adcx);
		temp=(float)adcx*(3.3/4096);
		adcx=temp;
		printf("测得的电压为%f伏\r\n\r\n",temp);
		delay_ms(500);	
	}											    
}	
