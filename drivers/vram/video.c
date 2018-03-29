/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "display.h"


 uint8_t cursorX = 0;
 uint8_t cursorY = 0;
 uint8_t colorText = 0x0f;
 uint8_t bgcolor = 0x00;


__void__ enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3E0) & 0xE0) | cursor_end);
}

void disable_cursor ( ) 
{ 
	outb ( 0x3D4 ,  0x0A ) ; 
	outb ( 0x3D5 ,  0x20 ) ; 
}

__void__ __move_Cursor__(int8_t x, int8_t y){

 
	uint16_t pos = y * 80 + x ;
 
	outb ( 0x3D4 ,  0x0F ) ; 
	outb ( 0x3D5 ,  ( uint8_t )  ( pos &  0xFF ) ) ; 
	outb ( 0x3D4 ,  0x0E ) ; 
	outb ( 0x3D5 ,  ( uint8_t )  ( ( pos >>  8 )  &  0xFF ) ) ; 

}


__static__ __void__ __kernelPutCharMem__(uint8_t d, uint8_t c){
	uint8_t data, color, n=1;
	uint8_t* videoMemory,*tmp;
	data = d;
	color = c;
	if (cursorX == 80||d == 10){
		/* code */
		cursorY++;
		cursorX = 0;
	}else{
		videoMemory = (((__CURSOR_COL__ *cursorY+cursorX)*2) + (uint8_t*) __ADDR_VIDEO__);
		*videoMemory = data;
		*(videoMemory+1) = color;
		++cursorX;
	}
	if (cursorY>=25)
	{
		/* code */
		for (videoMemory = (uint8_t*) __ADDR_VIDEO__; videoMemory < (uint8_t*) (__SIZE_MAX_VIDEO__); videoMemory+=2)
		{
			tmp = (uint8_t*)(videoMemory)+160;
			if (tmp < (uint8_t*)(__SIZE_MAX_VIDEO__))
			{
				/* code */
				*videoMemory = *tmp;
				*(videoMemory+1) = *(tmp+1);
			}else{
				*videoMemory = 0x00;
				*(videoMemory+1) = color;
			}
			
		}
		cursorY-=1;
		if (cursorY <= 0) cursorY = 0;
	}
	colorText = color;
	__move_Cursor__(cursorX, cursorY);
}

__void__ __kprint_video__(uint8_t* str){
	
	for (int i = 0; str[i]!=0; i++)
	{
		/* code */
		__kernelPutCharMem__(str[i],0x0f);

	}
}

__void__ __kernel_Put_Chr__(uint8_t d, uint8_t c){
	__kernelPutCharMem__(d, c);
}

__void__ __cleanterm__(){
	uint8_t* videoMemory;
	
	for (videoMemory = (uint8_t*) __ADDR_VIDEO__; videoMemory < (uint8_t*) (__SIZE_MAX_VIDEO__); videoMemory+=2)
		*(videoMemory) = 0x00;
	cursorX = 0;
	cursorY = 0;
	__move_Cursor__(cursorX, cursorY);
}

__void__ setBackground(uint8_t bg){
	uint8_t* videoMemory;
	for (videoMemory = (uint8_t*) __ADDR_VIDEO__; videoMemory < (uint8_t*) (__SIZE_MAX_VIDEO__); videoMemory+=2)
		*(videoMemory+1) = ((bg << 2) & 0xff)|colorText;
	bgcolor = ((bg << 2) & 0xf0)|(colorText & 0x0f);
}