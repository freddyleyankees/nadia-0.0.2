#include "../include/panic.h"
#include "../drivers/graphics/display.h"

__void__ panic(uint8_t* str){
    __kprint_video__(str);
    __asm__ __volatile__("hlt"::);
}