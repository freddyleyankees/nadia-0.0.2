/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "../include/types.h"
#include "../include/string.h"
#include "../drivers/vram/display.h"

__void__ init_head_info(__void__);
__void__ load_com(__void__);

__void__ start_console(__void__){
    init_head_info();

}

__void__ init_head_info(__void__){
    uint8_t* str;
    __kprint_video__("========== Nadia Operating System ========\n");
    __kprint_video__("CLI IATECH Inc.\n");
    str = __itoab__(MEMORY_HIGH,10);
    __kprint_video__("\nsystem memory ");
    __kprint_video__(str);
    __kprint_video__(" octet");
    __kprint_video__("\ntotal page : ");
    str = __itoab__(NB_T_PAGES,10);
    __kprint_video__(str);
    __kprint_video__("\nThis system not provide the file descriptor,\nthe file system and process manager,\nall data would be lost when system restart!\n");
    __kprint_video__("The paging is actived and each drivers are featuring\n");
    __kprint_video__("\n");
    load_com();
    
}

uint32_t wait_cmd(__void__){}
__void__ exec_cmd(uint8_t* str){}
__void__ load_com(__void__){
   
        __kprint_video__("root@nadia$ ");
        uint8_t* cmd;
        cmd = (uint8_t*) wait_cmd();
        exec_cmd(cmd);

}