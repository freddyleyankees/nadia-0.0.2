#ifndef __TERMINAL_H__
#define __TERMINAL_H__
#include "../include/types.h"
//these functions are build for text mode
typedef struct interface{
    uint16_t buf;
    uint32_t start_addr_v;
    uint32_t current_addr_v;
    uint32_t end_addr_v;
    uint32_t max_row;
    uint32_t max_col;
    uint32_t cursorX;
    uint32_t cursorY;
    uint32_t marginTop;
    uint32_t marginLeft;
} interface_t;
__void__ init_terminal(__void__);
 interface_t create_term (uint16_t*,uint32_t,uint32_t,uint32_t,uint32_t);
 __void__ interface_putchr(interface_t*,uint8_t,uint8_t);
 __void__ interface_write(interface_t*,uint8_t*);
 __void__ update_addr_video(interface_t*);
  uint32_t update_addr_scroll(uint8_t*);
interface_t* current_interface;
 #endif