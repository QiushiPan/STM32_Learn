#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "dma.h"

const u8 TEXT_TO_SEND[]={"�����Ƽ���ѧ DMA ����ʵ��"};
#define TEXT_LENTH  sizeof(TEXT_TO_SEND)-1			//TEXT_TO_SEND�ַ�������(������������)
u8 SendBuff[TEXT_LENTH+2];

 int main(void)
 { 
	u16 i;
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600	 	
 	MYDMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)SendBuff,TEXT_LENTH+2);//DMA1ͨ��4,����Ϊ����1,�洢��ΪSendBuff,��TEXT_LENTH+2	   
	for(i=0;i<TEXT_LENTH;i++)//���ASCII�ַ�������
    {
		SendBuff[i]=TEXT_TO_SEND[i];//����TEXT_TO_SEND���    
    }
	SendBuff[TEXT_LENTH]=0x0d; //����
	SendBuff[TEXT_LENTH+1]=0x0a; 
	 while(1)
	{	    
		    USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);   
			MYDMA_Enable(DMA1_Channel4);//��ʼһ��DMA���䣡	  
		    //�ȴ�DMA�������
		
		    //ʵ��Ӧ���У����������ڼ䣬����ִ�����������
		    while(1)
		    {
				if(DMA_GetFlagStatus(DMA1_FLAG_TC4)!=RESET)//�ȴ�ͨ��4�������
				{
					DMA_ClearFlag(DMA1_FLAG_TC4);//���ͨ��4������ɱ�־
					break; 
		        }	  
		    }		
		delay_ms(100); 
	}
}
