#include "led_sd.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* ���ֱ��� 
 *  ������Ϊ����������� 1-9 ����
 *  �󷴵õ������������ 1-9 ����
 */
static uint16_t su16_DpyNum[] = {0xC000, 0xF900, 0xA400, 0xB000, 0x9900, 
                                 0x9200, 0x8200, 0xF800, 0x8000, 0x9000}; 

/* λѡ���� 
 *  0xF000 - 4λȫѡ
 *  0x1000 - ѡ��1λ(��)
 *  0x2000 - ѡ��2λ
 *  0x4000 - ѡ��3λ
 *  0x8000 - ѡ��4λ
 */
static uint16_t su16_DpyBit[] = {0xF000, 0x1000, 0x2000, 0x4000, 0x8000}; 

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  LED�����(LED Segment Displays)����.
  *     I/O: ����ӿ� a - PA8
  *                   b - PA9
  *                   c - PA10
  *                   d - PA11
  *                   e - PA12
  *                   f - PA13
  *                   g - PA14
  *                  dp - PA15
  *
  *          λѡ�ӿ� A - PB15
  *                   B - PB14
  *                   C - PB13
  *                   D - PB12
  * @param  ��.
  * @retval ��.
  */
void LED_SD_Cfg(void)
{
    GPIO_InitTypeDef led_sd_gpio;
    
    /* ��ʱ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);

    /* ����ӿ�I/O���� */
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);    // �ر�SWJ(JTAG-DP + SW-DP)����
    led_sd_gpio.GPIO_Pin   = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 
                           | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;	
    led_sd_gpio.GPIO_Mode  = GPIO_Mode_Out_PP;              // ͨ���������
    led_sd_gpio.GPIO_Speed = GPIO_Speed_2MHz;               // 2MHz
    GPIO_Init(GPIOA, &led_sd_gpio);

    /* λѡ�ӿ�I/O���� */
    led_sd_gpio.GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init(GPIOB, &led_sd_gpio);
    
    /* ������ɺ�ر��������ʾ */
    DPY_OFF;                    // ��λѡ, ��ֹ��ʾ����
}

/**
  * @brief  �������ʾ.
  * @param  u8_Bit: ��ʾλѡ����, ȡֵ0-4.
  *     @arg 0: λȫѡ.
  *     @arg 1-4: ��Ӧ��1λ����4λ.
  * @param  u8_Num: ��ʾ���ֱ���, ȡֵ0-9.
  *     @arg 0-9: ��Ӧ����0-9.
  * @param  u8_Dp: С������ʾ, ȡֵ0��1.
  *     @arg 0: ����ʾС����.
  *     @arg 1: ��ʾС����.
  * @retval ��.
  */
void LED_SD_Dpy(uint8_t u8_Bit, uint8_t u8_Num)
{
	GPIO_Write(GPIOB, su16_DpyBit[u8_Bit]);
	GPIO_Write(GPIOA, su16_DpyNum[u8_Num]);
}
/******************************** END OF FILE *********************************/
