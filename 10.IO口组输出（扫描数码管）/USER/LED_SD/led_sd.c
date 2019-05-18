#include "led_sd.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* 数字编码 
 *  该数组为共阳极数码管 1-9 编码
 *  求反得到共阴极数码管 1-9 编码
 */
static uint16_t su16_DpyNum[] = {0xC000, 0xF900, 0xA400, 0xB000, 0x9900, 
                                 0x9200, 0x8200, 0xF800, 0x8000, 0x9000}; 

/* 位选编码 
 *  0xF000 - 4位全选
 *  0x1000 - 选第1位(右)
 *  0x2000 - 选第2位
 *  0x4000 - 选第3位
 *  0x8000 - 选第4位
 */
static uint16_t su16_DpyBit[] = {0xF000, 0x1000, 0x2000, 0x4000, 0x8000}; 

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/**
  * @brief  LED数码管(LED Segment Displays)配置.
  *     I/O: 段码接口 a - PA8
  *                   b - PA9
  *                   c - PA10
  *                   d - PA11
  *                   e - PA12
  *                   f - PA13
  *                   g - PA14
  *                  dp - PA15
  *
  *          位选接口 A - PB15
  *                   B - PB14
  *                   C - PB13
  *                   D - PB12
  * @param  无.
  * @retval 无.
  */
void LED_SD_Cfg(void)
{
    GPIO_InitTypeDef led_sd_gpio;
    
    /* 打开时钟 */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);

    /* 段码接口I/O配置 */
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);    // 关闭SWJ(JTAG-DP + SW-DP)功能
    led_sd_gpio.GPIO_Pin   = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 
                           | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;	
    led_sd_gpio.GPIO_Mode  = GPIO_Mode_Out_PP;              // 通用推挽输出
    led_sd_gpio.GPIO_Speed = GPIO_Speed_2MHz;               // 2MHz
    GPIO_Init(GPIOA, &led_sd_gpio);

    /* 位选接口I/O配置 */
    led_sd_gpio.GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_Init(GPIOB, &led_sd_gpio);
    
    /* 配置完成后关闭数码管显示 */
    DPY_OFF;                    // 关位选, 防止显示混乱
}

/**
  * @brief  数码管显示.
  * @param  u8_Bit: 显示位选变量, 取值0-4.
  *     @arg 0: 位全选.
  *     @arg 1-4: 对应第1位到第4位.
  * @param  u8_Num: 显示数字变量, 取值0-9.
  *     @arg 0-9: 对应数字0-9.
  * @param  u8_Dp: 小数点显示, 取值0和1.
  *     @arg 0: 不显示小数点.
  *     @arg 1: 显示小数点.
  * @retval 无.
  */
void LED_SD_Dpy(uint8_t u8_Bit, uint8_t u8_Num)
{
	GPIO_Write(GPIOB, su16_DpyBit[u8_Bit]);
	GPIO_Write(GPIOA, su16_DpyNum[u8_Num]);
}
/******************************** END OF FILE *********************************/
