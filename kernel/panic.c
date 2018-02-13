/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "../include/panic.h"
#include "../drivers/graphics/display.h"

__void__ panic(uint8_t* str){
    __kprint_video__(str);
    __asm__ __volatile__("hlt"::);
}