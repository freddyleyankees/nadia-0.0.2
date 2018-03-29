/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */


#ifndef __PAGING_H__
#define __PAGING_H__


#include "types.h"

/*this structure is not change if you know what you do*/
typedef struct page{
    uint32_t present    :1;
    uint32_t rw         :1;
    uint32_t user       :1;
    uint32_t pwt        :1;
    uint32_t pcd        :1;
    uint32_t accessed   :1;
    uint32_t dirty      :1;
    uint32_t unused     :5;
    uint32_t frame      :20;
} __attribute__ ((packed)) page_t;

typedef struct page_table{
    page_t pages[1024];
}page_table_t;

typedef struct page_directory{
    page_table_t* tables[1024];
    uint32_t tables_physical[1024];
    uint32_t physical_addr;
}page_directory_t;

#ifdef __PAGE_DIRECTORY__
page_directory_t* current_page_dir;
#else 
__extern__ page_directory_t* current_page_dir;
#endif

__void__ __init_paging__(__void__);


__void__ swicth_directory_page(page_directory_t*);
__void__ update_directory_page(page_directory_t*);
__void__ kalloc_identy_page(uint32_t, uint32_t , uint32_t );
__void__ kalloc_page(page_t*, uint32_t, uint32_t);
page_t *get_page(uint32_t,uint32_t, page_directory_t*);
__void__ kfree_page(page_t*);
#endif
