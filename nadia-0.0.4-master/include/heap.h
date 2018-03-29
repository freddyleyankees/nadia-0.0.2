/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */


#ifndef __HEAP_H__
#define __HEAP_H__


#include "types.h"


#define HEAP_START_ADDR     0xC0000000
#define HEAP_ADDR_SIZE      0x10000000

typedef struct heap{
    struct heap*    next;
    struct heap*    prev;
    bool_t          hold;
    uint32_t        data;
    uint32_t        addr_frame_start;
    size_t          size;
    size_t          nb_sect;
} heap_t;

typedef struct list_heap{
    heap_t* head;
    heap_t* tail;
} __attribute__((packed)) list_heap_t ;

#ifdef __LIST_HEAP__
list_heap_t* k_l_heap;
list_heap_t* k_l_heap_h;
#else
__extern__ list_heap_t* k_l_heap;
__extern__ list_heap_t* k_l_heap_h;
#endif

__void__ mem_heap_init(__void__);
__void__ mem_list_init(list_heap_t*);
heap_t* mem_div_heap(list_heap_t*, heap_t*, size_t);
__void__ mem_alloc_frame_heap(uint32_t);
__void__ mem_del_frame_heap(uint32_t);
__static__ __void__* mem_heap_kmalloc(list_heap_t*, size_t, uint32_t);
__void__* mem_malloc(size_t);
__void__* mem_malloc_a(size_t, uint32_t);
__static__ __void__ mem_heap_kfree(list_heap_t*, uint32_t*);
__void__ mem_free(uint32_t*);
__void__ mem_heap_add(list_heap_t*, heap_t*);
__void__ mem_heap_expand(list_heap_t*, size_t, uint32_t);
__void__ mem_list_heap(list_heap_t*);
uint32_t mem_test_heap_list(list_heap_t*, heap_t*);
__void__ mem_heap_sort_by_size(list_heap_t*);
__void__ mem_heap_sort_by_frame(list_heap_t*);
uint32_t mem_test_heap_block_is_free(uint32_t);
#endif




