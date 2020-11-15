#include "clock.h"
#include "intrins.h"



void delay1ms(){
	int a =0;
	int b =0;
	for(a=0;a<1095;a++){		
		_nop_(); 
		_nop_();
		_nop_();
	}
}

//void delay10us(){
//	int a =0;
//	int b =0;
//	for(a=0;a<9;a++){		
//		_nop_(); 		
//	}	
//}