#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

int main(void)
{
	  SystemInit();
    LED_Cfg();           // ϵͳ��ʼ��
    delay_init();	    	 //��ʱ������ʼ��	
    while (1)
    {
        /* ��ˮ�� */
        LED1_ON;
        delay_ms(100);
        LED1_OFF;
			  LED2_ON;
        delay_ms(100);
        LED2_OFF;
//        Delay_ms(200);

        LED3_ON;
        delay_ms(100);
        LED3_OFF;
//        Delay_ms(200);

        LED4_ON;
        delay_ms(100);
        LED4_OFF;
//        Delay_ms(200);

        LED5_ON;
        delay_ms(100);
        LED5_OFF;
//        Delay_ms(200);

        LED6_ON;
        delay_ms(100);
        LED6_OFF;
//        Delay_ms(200);

        LED7_ON;
        delay_ms(100);
        LED7_OFF;
//        Delay_ms(200);

        LED8_ON;
        delay_ms(100);
        LED8_OFF;
//        Delay_ms(200);
    }
}
