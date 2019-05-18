#include "delay.h"
#include "sys.h"
#include "pwm.h"

 int main(void)
 {	
	u16 led0pwmval=0;    
	u8 dir=1;	
	delay_init();	    	 //延时函数初始化	  
	TIM1_PWM_Init(899,0);//不分频。PWM频率=72000/(899+1)=80Khz 
   	while(1)
	{
 		delay_us(500);	 
		if(dir)led0pwmval++;
		else led0pwmval--;	 
 		if(led0pwmval>300)dir=0;
		if(led0pwmval==0)dir=1;	   					 
		TIM_SetCompare1(TIM1,led0pwmval);	   
	} 
}
