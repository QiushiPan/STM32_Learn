#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "dma.h"

const u8 TEXT_TO_SEND[]={"北京科技大学 DMA 串口实验"};
#define TEXT_LENTH  sizeof(TEXT_TO_SEND)-1			//TEXT_TO_SEND字符串长度(不包含结束符)
u8 SendBuff[TEXT_LENTH+2];

 int main(void)
 { 
	u16 i;
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600	 	
 	MYDMA_Config(DMA1_Channel4,(u32)&USART1->DR,(u32)SendBuff,TEXT_LENTH+2);//DMA1通道4,外设为串口1,存储器为SendBuff,长TEXT_LENTH+2	   
	for(i=0;i<TEXT_LENTH;i++)//填充ASCII字符集数据
    {
		SendBuff[i]=TEXT_TO_SEND[i];//复制TEXT_TO_SEND语句    
    }
	SendBuff[TEXT_LENTH]=0x0d; //换行
	SendBuff[TEXT_LENTH+1]=0x0a; 
	 while(1)
	{	    
		    USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);   
			MYDMA_Enable(DMA1_Channel4);//开始一次DMA传输！	  
		    //等待DMA传输完成
		
		    //实际应用中，传输数据期间，可以执行另外的任务
		    while(1)
		    {
				if(DMA_GetFlagStatus(DMA1_FLAG_TC4)!=RESET)//等待通道4传输完成
				{
					DMA_ClearFlag(DMA1_FLAG_TC4);//清除通道4传输完成标志
					break; 
		        }	  
		    }		
		delay_ms(100); 
	}
}
