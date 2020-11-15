#ifndef __STC8H_CONF_H
#define __STC8H_CONF_H

#include "STC8G.h"
#include "intrins.h"
#include "clock.h"

#define HAL_MODULE_ENABLED
#define HAL_ADC_MODULE_ENABLED
#define HAL_CAN_MODULE_ENABLED
#define HAL_CRC_MODULE_ENABLED
#define HAL_CRYP_MODULE_ENABLED
#define HAL_DAC_MODULE_ENABLED
#define HAL_DCMI_MODULE_ENABLED
#define HAL_DMA_MODULE_ENABLED
#define HAL_DMA2D_MODULE_ENABLED
#define HAL_ETH_MODULE_ENABLED
#define HAL_FLASH_MODULE_ENABLED
#define HAL_NAND_MODULE_ENABLED
#define HAL_NOR_MODULE_ENABLED
#define HAL_PCCARD_MODULE_ENABLED
#define HAL_SRAM_MODULE_ENABLED
#define HAL_SDRAM_MODULE_ENABLED
#define HAL_HASH_MODULE_ENABLED
#define HAL_GPIO_MODULE_ENABLED
#define HAL_I2S_MODULE_ENABLED
#define HAL_IWDG_MODULE_ENABLED
#define HAL_LTDC_MODULE_ENABLED
#define HAL_PWR_MODULE_ENABLED
#define HAL_RCC_MODULE_ENABLED
#define HAL_RNG_MODULE_ENABLED
#define HAL_RTC_MODULE_ENABLED
#define HAL_SAI_MODULE_ENABLED
#define HAL_SD_MODULE_ENABLED

#define HAL_TIM_MODULE_ENABLED
#define HAL_UART_MODULE_ENABLED
#define HAL_USART_MODULE_ENABLED
#define HAL_IRDA_MODULE_ENABLED
#define HAL_SMARTCARD_MODULE_ENABLED
#define HAL_WWDG_MODULE_ENABLED
#define HAL_CORTEX_MODULE_ENABLED
#define HAL_PCD_MODULE_ENABLED
#define HAL_HCD_MODULE_ENABLED

#define DEV_LCD12864_MODULE_ENABLED
#define DEV_LCD1602_MODULE_ENABLED
#define DEV_I2C_MODULE_ENABLED
#define DEV_SPI_MODULE_ENABLED

#ifdef DEV_LCD1602_MODULE_ENABLED
  #include "lcd1602.h"
#endif /* HAL_RCC_MODULE_ENABLED */

#ifdef DEV_LCD12864_MODULE_ENABLED
  #include "lcd12864.h"
#endif /* HAL_GPIO_MODULE_ENABLED */

#ifdef DEV_I2C_MODULE_ENABLED
  #include "I2C.h"
#endif /* HAL_DMA_MODULE_ENABLED */

/******************************************************************************/
// LCD12864引脚配置
// LCD12864下载程序时注意选中ALE脚用作P4.5口
/******************************************************************************/


sbit L1P45RE = P4^5;
sbit L2P46GR = P4^6;

//LCD12864
sbit RS = P3^5;    //P4^5    //并行的指令数据选择信号
sbit RW = P3^6;    //P4^6    //并行的读写信号 
sbit EN = P3^7;    //P0^0    //并行的使能信号
//sbit PSB = P4^6;
//sbit vout = P3^5;//V
sbit RST = P4^3;
#define lcdPort  P0   //P2 //双向数据端口
#define lcdData  1	  //写数据
#define lcdCmd   0	  //写命令
#define delayNOP(); {_nop_();_nop_();_nop_();_nop_();};

#endif /* __STC8H_CONF_H */
 
 