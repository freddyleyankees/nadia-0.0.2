/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */ 

#define __BITMAP__
#include "../include/bitmap.h"
#include "../include/alloc.h"
#include "../include/mem.h"
#include "../include/string.h"
#include "../drivers/vram/display.h"

//init bitmap array

__void__ init_mem_bitmap(__void__){
    bitmap = (bitset_t*) mem_kmalloc(sizeof(bitset_t));
    bitmap->size = INDEX_FROM_BIT(memory_info_system.mem_info_nb_page);
    bitmap->addr = (uint32_t*) mem_kmalloc(bitmap->size);
    __memset__((uint8_t*) bitmap->addr,0,bitmap->size);
}

// set a bit to allocate a page
__void__ set_bit_frame(bitset_t* bit,uint32_t frame){
    
    uint32_t index = INDEX_FROM_BIT(frame);
    uint32_t offset = OFFSET_FROM_BIT(frame);
    bit->addr[index] |= (1 << offset);
}
// clean bit to free page
__void__ clear_bit_frame(bitset_t* bit,uint32_t frame){
    
    uint32_t index = INDEX_FROM_BIT(frame);
    uint32_t offset = OFFSET_FROM_BIT(frame);
    bit->addr[index] &= ~(1 << offset);
}
// test bit if page is allocated
uint32_t test_bit_frame(bitset_t* bit,uint32_t frame){
    
    uint32_t index = INDEX_FROM_BIT(frame);
    uint32_t offset = OFFSET_FROM_BIT(frame);
    return (bit->addr[index] & (1 << offset));
}
// to obtain a page free 
uint32_t get_free_frame(bitset_t* bit){
    for(uint32_t i=0;i<bit->size;i++){
        if(bit->addr[i] != 0xFFFFFFFF){
            for(uint32_t j=0;j<32;j++){
                if(!(bit->addr[i] & (1 << j))){
                    return i*0x20+j;
                }
            }
        }
    }
    return -1;
}
