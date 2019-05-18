#include "stm32f10x.h"
#include "led.h"
#include "key.h"
#include "delay.h"

int main(void)
{
    delay_init();
	  LED_Cfg();              // LED��ʼ������
    Key_Cfg();              // ������ʼ������
    
    while (1)
    {
        /* ����Key1��Key3 */
        if (KEY1_STA == KEY_DN)   // ����Ƿ��а�������
        {
            delay_ms(1);                      // ��ʱ����
            
            if (KEY1_STA == KEY_DN)           // ȷ���Ƿ񰴼�Key1����
            {	 
                while (KEY1_STA == KEY_DN);   // �ȴ������ͷ�
                LED1_TOGGLE;
            }
        }
				if (KEY3_STA == KEY_DN)   // ����Ƿ��а�������
        {
            delay_ms(1);                      // ��ʱ����
            if (KEY3_STA == KEY_DN)      // ȷ���Ƿ񰴼�Key3����
            {	 
                while (KEY3_STA == KEY_DN);   // �ȴ������ͷ�
                LED3_TOGGLE;
            }
        }

        /* ����Key2��Key4 */
        if (KEY2_STA == KEY_DN)   // ����Ƿ��а�������
        {
            delay_ms(1);                      // ��ʱ����
            
            if (KEY2_STA == KEY_DN)           // ȷ���Ƿ񰴼�Key2����
            {
                LED2_ON;
                while (KEY2_STA == KEY_DN);
                LED2_OFF;
            }
        }
				if (KEY4_STA == KEY_DN)   // ����Ƿ��а�������
        {
            delay_ms(1);                      // ��ʱ����
            
            if (KEY4_STA == KEY_DN)     // ȷ���Ƿ񰴼�Key4����
            {
                LED4_ON;
                while (KEY4_STA == KEY_DN);
                LED4_OFF;
            }
        }
			}
}
