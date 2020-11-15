#ifndef __lcd12864_H
#define __lcd12854_H

void Lcd12864_Screen_Clear(void);
void Lcd12864_Screen_Init(void);
void Lcd12864_Write_Data(unsigned char Data);
void Lcd12864_Write_Cmd(unsigned char cmd);
void Lcd12864_Busy_Check(void);

//void Lcd12864_Show_String(unsigned char row, unsigned char col,unsigned char *str);
//void Lcd12864_Show_Specific_Symbol(void);

#endif