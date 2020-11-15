#include "stc8h_conf.h"

unsigned char   DIS1[] = {"    电子技术    "};
unsigned char   DIS2[] = {"    STC8H8K     "};

/**************主函数***********************/
void main (){ 
	unsigned char i = 0;
	
	P0M0 = 0x00;
	P0M1 = 0x00;	
	P2M0 = 0x00;
	P2M1 = 0x00;
	P3M0 = 0x00;
	P3M1 = 0x00;	
	P4M0 = 0x00;
	P4M1 = 0x00;  
	
	L1P45RE = 1;
	L2P46GR = 1;
 
	Lcd12864_Screen_Init();   
  delay1ms();	
	Lcd12864_Write_Cmd(0x80);
	delay1ms();
	Lcd12864_Write_Data('A');	
	delay1ms();
	Lcd12864_Write_Cmd(0x90);
	delay1ms();
	for(i=0;i<16;i++){ 
		Lcd12864_Write_Data(DIS2[i]);
		delay1ms();
		delay1ms();		
	}	
	
	delay1ms();
	Lcd12864_Write_Cmd(0x01);      //清屏 
	delay1ms();
	
	while(1){			
		L1P45RE = 0;	
		delay1ms();	
		L1P45RE = 1;	
		delay1ms();
	}
}
