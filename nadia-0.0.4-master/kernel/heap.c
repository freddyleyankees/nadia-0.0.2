/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#define __LIST_HEAP__

#include "../include/heap.h"
#include "../include/bitmap.h"
#include "../include/paging.h"
#include "../include/alloc.h"
#include "../include/string.h"
#include "../include/opt.h"
#include "../drivers/vram/display.h"

/**
 *  ======== heap.c ==========
 * 
 * 
 * 
 */

uint32_t cur_pos_start_addr_heap_size = 0x0;
uint32_t cur_pos_start_addr_header_heap = 0x0;
uint32_t header_heap_size = 0x0;
bitset_t* vm_bitmap;

__void__ mem_heap_init(__void__){
    uint8_t* str;
    uint32_t size = 0x100000; //we have reserved 1Mb per list of heap's header
    uint32_t nb_header_require = div_round_up_digit_by(sizeof(heap_t), memory_info_system.mem_info_heap_sect_int);

    header_heap_size = nb_header_require * memory_info_system.mem_info_heap_sect_int;
    uint32_t nb_header = size / header_heap_size;
    //loadly list heap in memory
    k_l_heap = (list_heap_t*) mem_kmalloc(nb_header * header_heap_size+2*sizeof(list_heap_t));
    k_l_heap_h = (list_heap_t*)((size_t)k_l_heap + 8);
    __memset__((uint8_t*) k_l_heap,0,nb_header * header_heap_size+2*sizeof(list_heap_t));

    cur_pos_start_addr_heap_size = memory_info_system.mem_info_heap_frame_start; 
    cur_pos_start_addr_header_heap = ((uint32_t) k_l_heap + 16);
    
    vm_bitmap = (bitset_t*) mem_kmalloc(sizeof(bitset_t));
    vm_bitmap->size = INDEX_FROM_BIT(nb_header);
    vm_bitmap->addr = (uint32_t*) mem_kmalloc(vm_bitmap->size);
    __memset__((uint8_t*) vm_bitmap->addr,0,vm_bitmap->size);
    
    mem_list_init(k_l_heap); 
    mem_list_init(k_l_heap_h); 
}

__void__ mem_list_init(list_heap_t* list){
    list->head = NULL;
    list->tail = NULL;
}

heap_t* mem_div_heap(list_heap_t* list, heap_t* t_heap, size_t size){
    heap_t* tmp;
    uint8_t* str;
    tmp = (heap_t*)(get_free_frame(vm_bitmap)*header_heap_size + cur_pos_start_addr_header_heap);
    set_bit_frame(vm_bitmap,((size_t)tmp - cur_pos_start_addr_header_heap)/header_heap_size);
    
    tmp->size = t_heap->size - size;
    tmp->data = t_heap->data+size;
    tmp->addr_frame_start = (uint32_t) get_page((uint32_t)tmp->data,1,current_page_dir);
    tmp->nb_sect = div_round_up_digit_by(tmp->size, memory_info_system.mem_info_heap_sect_int);
    tmp->hold = 0;
    mem_heap_add(list, tmp);
    t_heap->size = size ;
    t_heap->nb_sect = div_round_up_digit_by(t_heap->size, memory_info_system.mem_info_heap_sect_int);
    return t_heap;
}

__void__ mem_list_heap(list_heap_t* list){
    heap_t* head = list->head;
    uint32_t i = 0;
    uint8_t* str;
    if(!head){
        str = __itoab__(i,16);
        __kprint_video__("\nheap number ");
        __kprint_video__(str);
        str = __itoab__((uint32_t) head,16);
         __kprint_video__(" : list empty ");
        __kprint_video__(str);
        return;
    }

    for(heap_t* tmp = head;tmp;tmp = tmp->next){
        str = __itoab__((uint32_t) tmp,16);
        __kprint_video__("\nheap num -> ");
        __kprint_video__(str);
        str = __itoab__(tmp->size,16);
        __kprint_video__(" size -> ");
        __kprint_video__(str);
        str = __itoab__((uint32_t) tmp->prev,16);
        __kprint_video__(" prev -> ");
        __kprint_video__(str);
        str = __itoab__((uint32_t) tmp->next,16);
        __kprint_video__(" next -> ");
        __kprint_video__(str);
        str = __itoab__(tmp->data,16);
        __kprint_video__(" frame -> ");
        __kprint_video__(str);
    }
}
// __void__ mem_heap_sort_by_size(list_heap_t* list){
//     heap_t* head = list->head;
//     heap_t* tail = list->tail;
//     heap_t* tmp_;
//     uint8_t* str;
//     str = __itoab__((uint32_t) head,16);
//         __kprint_video__("\n frame -> ");
//         __kprint_video__(str);
//         str = __itoab__((uint32_t) tail,16);
//         __kprint_video__(" frame -> ");
//         __kprint_video__(str);
//         mem_list_heap(k_l_heap);
//     for(heap_t* chunk = head;chunk != tail||chunk!=NULL;chunk = chunk->next){
//         for(heap_t* tmp = tail;tmp != chunk||tmp!=NULL;tmp = tmp_->prev){
//             str = __itoab__((uint32_t) tmp,16);
//         __kprint_video__("\n frame -> ");
//         __kprint_video__(str);
//         str = __itoab__((uint32_t) tmp->prev,16);
//         __kprint_video__(" frame -> ");
//         __kprint_video__(str);
//             if(tmp->data < tmp->prev->data){
//                 tmp_ = tmp->prev;
//                 if(tmp_->prev){
//                     tmp_->prev->next = tmp;
//                     tmp->prev = tmp_->prev; 
//                 }
//                 else{
//                     list->head = tmp;
//                     tmp->prev = NULL;
//                     list->tail = tmp; 
//                 }
//                 tmp_->next = tmp->next;
//                 tmp_->prev = tmp;
//                 tmp->next = tmp_;
//                 list->tail = tmp; 
//             }
//             mem_list_heap(k_l_heap);
//         }
//     }
// }
__void__ mem_heap_sort_by_frame(list_heap_t* list){

}
__static__ __void__* mem_heap_kmalloc(list_heap_t*list, size_t size, uint32_t align){
    uint8_t str;
    uint32_t vm_frame;
    
    uint32_t nb_sect_resv = div_round_up_digit_by(size, memory_info_system.mem_info_heap_sect_int);
    size = nb_sect_resv* memory_info_system.mem_info_heap_sect_int;

    
    heap_t* result = NULL;
    rep:
    for(heap_t* chunk = list->head;chunk;chunk = chunk->next)
        if(size <= chunk->size)
            result = chunk;
    
    if(!result){
        mem_heap_expand(list, size, align);
        goto rep;
    }
    if(!result->data)
        result->data = cur_pos_start_addr_heap_size;

    if(result->size >= size+1){
        result = mem_div_heap(list,result,size);
    }
    
    mem_heap_remove(list, result);
    mem_heap_add(k_l_heap_h, result);
    result->hold = 1;
    result->addr_frame_start = (uint32_t) get_page((uint32_t)result->data,1,current_page_dir);
    return (__void__*) result->data;
}

__void__* mem_malloc(size_t size){
    return (__void__*) mem_heap_kmalloc(k_l_heap, size, 0);
}

__void__* mem_malloc_a(size_t size, uint32_t align){
    return (__void__*) mem_heap_kmalloc(k_l_heap, size, align);    
}
uint32_t mem_test_heap_block_is_free(uint32_t addr){
    uint32_t nb_bl_per_page = div_round_up_digit_by(PAGE_SIZE, memory_info_system.mem_info_heap_sect_int);
    uint32_t nb_bl_size = nb_bl_per_page*memory_info_system.mem_info_heap_sect_int;

    uint32_t test;
    for(uint32_t i = addr;i<addr+nb_bl_per_page;i++){
        test = test_bit_frame(vm_bitmap,i);
        if(test) return NULL;
    }
    return 1;
}
// free heap
__static__ __void__ mem_heap_kfree(list_heap_t* list, uint32_t* addr){
    //provide heap from addr
    uint32_t header_sect_require = div_round_up_digit_by(sizeof(heap_t), memory_info_system.mem_info_heap_sect_int);
    uint32_t header_size = header_sect_require*memory_info_system.mem_info_heap_sect_int;
    uint8_t* str;
    heap_t* tmp;
    uint32_t t;
    for(heap_t* chunk = list->head;chunk;chunk = chunk->next)
        if(chunk->data == addr)
            tmp = chunk;
    tmp->hold = 0;
   
    __kprint_video__("\n free page ");
    
    mem_heap_remove(list, tmp);
    mem_heap_add(k_l_heap, tmp);

    if(tmp->prev != NULL){
        if((tmp->prev->data+tmp->prev->size) == tmp->data) { 
            str = __itoab__((uint32_t) tmp->data,16);
        __kprint_video__(str);
            tmp->prev->next = tmp->next;
            tmp->prev->size += tmp->size ;
            if(tmp->next != NULL){
                tmp->next->prev = tmp->prev;
            }else
                k_l_heap->tail = tmp->prev;
            clear_bit_frame(vm_bitmap,((size_t)tmp - cur_pos_start_addr_header_heap)/header_heap_size);
            tmp = tmp->prev;

        }
    }
    if(tmp->next != NULL){
        if((tmp->data + tmp->size) ==  tmp->next->data){
            str = __itoab__((uint32_t) tmp->next->data,16);
        __kprint_video__(str);
            tmp->size += tmp->next->size;
            tmp->next = tmp->next->next;
            if(tmp->next != NULL){
                tmp->next->prev = tmp;
            }else
                k_l_heap->tail = tmp;
            clear_bit_frame(vm_bitmap,((size_t)tmp->next - cur_pos_start_addr_header_heap)/header_heap_size);
        }
    }
    // mem_heap_sort_by_size(k_l_heap);
}

__void__ mem_free(uint32_t* addr){
    return (__void__) mem_heap_kfree(k_l_heap_h, addr);
}
//add heap in list
__void__ mem_heap_add(list_heap_t* list, heap_t* t_heap){
    heap_t* head = list->head;
    if(!head){
        list->head = t_heap;
        t_heap->next = head;
        t_heap->prev = NULL;
        if(list->tail == NULL)
            list->tail = t_heap;
        return;
    }
    t_heap->prev = list->tail;
    t_heap->next = NULL;
    list->tail->next = t_heap;
    list->tail = t_heap;

}
//remove heap in list
__void__ mem_heap_remove(list_heap_t* list, heap_t* t_heap){
    heap_t* head = list->head;
    heap_t* tail = list->tail;
    heap_t* tmp = t_heap;
    if(tmp->prev != NULL)
        tmp->prev->next = tmp->next;
    else
        list->head = tmp->next;
    if(tmp->next != NULL)
        tmp->next->prev = tmp->prev;
    else
        list->tail = tmp->prev;
}
//expand heap
__void__ mem_heap_expand(list_heap_t* list, size_t size, uint32_t align){
    //find a virtual address available
    uint8_t* str;
    uint32_t size_h = memory_info_system.mem_info_heap_size_default;
    uint32_t nb_size_require = div_round_up_digit_by(size_h, memory_info_system.mem_info_heap_sect_int);
    size_h = nb_size_require*memory_info_system.mem_info_heap_sect_int;
    heap_t* tmp  = (heap_t*) (get_free_frame(vm_bitmap)*header_heap_size + cur_pos_start_addr_header_heap);
    set_bit_frame(vm_bitmap,((size_t)tmp - cur_pos_start_addr_header_heap)/header_heap_size);
    str = __itoab__((size_t)tmp,16);
        __kprint_video__(" frame -> ");
        __kprint_video__(str);
    uint32_t tmp_size = size_h;
    for(uint32_t i = 0;size_h<size;i++)
        size_h += tmp_size;
    tmp->size = size_h;
    tmp->hold = 0;
    mem_heap_add(list, tmp);
}

__void__ mem_alloc_frame_heap(uint32_t addr){
    uint8_t* str;
    uint32_t frame = (addr - cur_pos_start_addr_header_heap)/memory_info_system.mem_info_heap_sect_int;
    set_bit_frame(vm_bitmap,frame);
    kalloc_page(get_page(( addr),1,current_page_dir),1,0);
    
    return ;
}


__void__ mem_del_frame_heap(uint32_t addr){
    page_t* page;
    uint8_t* str;
    page = get_page(addr,0,current_page_dir);
    if(page){
        kfree_page(page);
        return;
    }
    panic("\nno possible to free this frame");
}

uint32_t mem_test_heap_list(list_heap_t* list,heap_t* t_heap){
    heap_t* chunk = list->head;
    while(chunk){
        if(chunk == t_heap){
            return 1;
        }
        chunk = chunk->next;
    }
    return -1;
}



