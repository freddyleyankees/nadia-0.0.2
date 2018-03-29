/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "types.h"

#define INDEX_FROM_BIT(addr)    (addr/0x20)
#define OFFSET_FROM_BIT(addr)   (addr%0x20)
#define FRAME_NUMBER(addr)      (addr/0x1000)

typedef struct bitset{
    uint32_t* addr;
    uint32_t size;
}bitset_t;

#ifdef __BITMAP__
bitset_t* bitmap = NULL;
#else 
__extern__ bitset_t* bitmap;
#endif

__void__ init_mem_bitmap(__void__);
__void__ set_bit_frame(bitset_t*,uint32_t);
__void__ clear_bit_frame(bitset_t*,uint32_t);
uint32_t test_bit_frame(bitset_t*,uint32_t);
uint32_t get_free_frame(bitset_t*);



