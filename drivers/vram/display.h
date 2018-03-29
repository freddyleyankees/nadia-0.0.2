/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#ifndef __DISPLAY_H__
#define __DISPLAY_H__
    #include "../../include/types.h"
    #include "../../include/io.h"

#define __TEXT_MODE__				0
#define __CURSOR_COL__				80
#define __CURSOR_ROW__				25
#define __ADDR_VIDEO__				0xB8000
#define __SIZE_MAX_VIDEO__  		0xB8FA0

__extern__ uint8_t cursorX;
__extern__ uint8_t cursorY;

#endif

__void__ __cleanterm__(__void__);
__void__ __kprint_video__(uint8_t* );
__void__ __kernel_Put_Chr__(uint8_t, uint8_t);
__void__ __move_Cursor__(int8_t, int8_t);
__void__ enable_cursor(uint8_t , uint8_t );
__void__ disable_cursor(__void__);
__void__ setBackground(uint8_t);