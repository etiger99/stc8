#include "lcd12864.h"
#include "stc8h_conf.h"
/******************************************************************************/
// 函数名称：Lcd12864_Busy_Check 
// 函数功能：LCD1602忙信号检查 
/******************************************************************************/
void Lcd12864_Busy_Check(void){
	unsigned char tmp;
	do{
		RS = 0;
		RW = 1;
		EN = 0;
		EN = 1;
		L1P45RE = 1;
		delayNOP();
		tmp = lcdPort;
		L1P45RE = 0;
		EN = 0;
		delayNOP();
	}while(tmp&0x80);		
}
//

//
/******************************************************************************/
// 函数名称：Lcd12864_Screen_Init 
// 函数功能：LCD12864初始化
/******************************************************************************/
void Lcd12864_Screen_Init(){	
	RST = 0;
	delay1ms();
	RST = 1;
	
	//Lcd12864_Write_Cmd(0x34);//使用扩充指令集
	delay1ms();
	Lcd12864_Write_Cmd(0x30);//使用基本指令集
	delay1ms();
	Lcd12864_Write_Cmd(0x0c); //显示开，关光标
	delay1ms();
	Lcd12864_Write_Cmd(0x01);//清屏
	delay1ms();	
	//Lcd12864_Write_Cmd(0x06);//显示光标移动设置
}
//

//
/******************************************************************************/
// 函数名称：Lcd12864_Write_Cmd 
// 输入参数：cmd
// 输出参数：无 
// 函数功能：LCD12864发送命令
//  第一行第一位    cmd=0x80;  
//  第二行第一位    cmd=0x90;
//  第三行第一位    cmd=0x88;
//  第四行第一位    cmd=0x98;
/******************************************************************************/
void Lcd12864_Write_Cmd(unsigned char cmd){	
	Lcd12864_Busy_Check();//busycheck
//PSB = 1;
	RS = 0;
	RW = 0;
	EN = 0;
	_nop_();
	EN = 1;		
	delayNOP();	
	lcdPort = cmd;	
	delayNOP();	
	EN = 1;
	delayNOP();
	EN = 0;	
}
//

//
/******************************************************************************/
// 函数名称：Lcd12864_Write_Data 
// 输入参数：Data-写入数据
// 输出参数：无 
// 函数功能：LCD12864写一个字节数据
/******************************************************************************/
void Lcd12864_Write_Data(unsigned char Data){
	Lcd12864_Busy_Check();//busycheck		
//PSB = 1;
	RS = 1;
	RW = 0;
	EN = 0;
	EN = 1;
  delayNOP();	
	lcdPort = Data;
  delayNOP();
	EN = 0;		
}
//


/******************************************************************************/
// 函数名称：Lcd12864_Show_Ascii_Symbol 
// 函数功能：LCD12864显示ASCII码字符
/******************************************************************************/
//void Lcd12864_Show_Specific_Symbol(void){
//	unsigned char i;
//	Lcd12864_Write_Cmd(0x01);//清屏
//	for(i=0;i<32;i++){
//		Lcd12864_Write_Cmd(0x80+i); //显示位置
//		Lcd12864_Write_Data(0x02+i);//显示内容	
//	}	
//}


//专门清屏
//void  clr_screen(){
//		Lcd12864_Write_Cmd(0x34);      //扩充指令操作
//		delay1ms();  
//		Lcd12864_Write_Cmd(0x30);      //基本指令操作
//		delay1ms();
//		Lcd12864_Write_Cmd(0x01);      //清屏 
//		delay1ms();
//}