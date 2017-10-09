#include "../../include/types.h"
#include "../../include/io.h"

#define __TEXT_MODE__				0
#define __CURSOR_COL__				80
#define __CURSOR_ROW__				25
#define __ADDR_VIDEO__				0xB8000
#define __SIZE_MAX_VIDEO__  		0xB8FA0

 uint8_t cursorX = 0;
 uint8_t cursorY = 0;



__void__ __move_Cursor__(uint8_t x, uint8_t y){
	uint16_t pos_cur;
	pos_cur = y * 80 + x;
	outb(0x3d4, 0x0f);
	outb(0x3d5, (uint8_t) pos_cur);
	outb(0x3d4, 0x0e);
	outb(0x3d5, (uint8_t) (pos_cur >> 8));
}

__static__ __void__ __show_Cursor__(__void__){
	__move_Cursor__(cursorX, cursorY);
}

__static__ __void__ __hide_Cursor__(__void__){
	__move_Cursor__(-1, -1);
}

__extern__ __void__ __blink_Cursor__(__void__){
	
	__static__ uint8_t i=0;
	
	if(i == 0){
		__show_Cursor__();
		i++;
	}
	else{
		 __hide_Cursor__();
		i--;
	}
}

__static__ __void__ __kernelPutCharMem__(uint8_t d, uint8_t c){
	uint8_t data, color, n=1;
	uint8_t* videoMemory,*tmp;
	data = d;
	color = (c & 0x0f);
	if (cursorX == 80||data == 10){
		/* code */
		cursorY++;
		cursorX = 0;
	}
	
	videoMemory = (((__CURSOR_COL__ *cursorY+cursorX)*2) + (uint8_t*) __ADDR_VIDEO__);
	*videoMemory = data;
	*(videoMemory+1) = color;
	++cursorX;
	__blink_Cursor__();
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
				*videoMemory = 0x20;
				*(videoMemory+1) = color;
			}
			
		}
		cursorY-=1;
		if (cursorY <= 0) cursorY = 0;
	}

}

__void__ __kprint_video__(const char* str){
	
	for (int i = 0; str[i]!=0; i++)
	{
		/* code */
		__kernelPutCharMem__(str[i],0x0f);

	}
	

}

__extern__ __void__ __kernel_Put_Chr__(uint8_t d, uint8_t c){
	__kernelPutCharMem__(d, c);
}

__void__ __cleanterm__(){
	cursorX = 0;
	cursorY = 0;
	for (int i = 0; i < 2000; ++i)
	{
		/* code */
		__kernelPutCharMem__((uint8_t)0x20,0x0f);
	}
	cursorX = 0;
	cursorY = 0;
}
