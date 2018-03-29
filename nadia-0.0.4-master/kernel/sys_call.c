/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */
#include "../drivers/vram/display.h"
#include "../include/sys_call.h"
#include "../include/string.h"
#include "../include/kernel.h"

__void__ syscall_callback(registers_t reg){
    
    uint32_t eax = (uint32_t) reg.eax;
    uint8_t* str = (uint8_t*) reg.ebx;
    switch(eax){
        case 0x1:
            while(*str != 0){
            }
            break;
        case 0x5:
            __kprint_video__("\nfree memory");
            break;
        default:
            break;
    }
   
}

__void__ write_sys_console(uint8_t* buffer){
    __asm__ __volatile__("movl $0x1, %%eax ;movl %0, %%ebx ;int $0x60"::"m"(buffer));
}
