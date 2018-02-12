#include "types.h"
#include "handler.h"
#include "segment.h"
#ifdef __PAGING_H__

#define PAGE_SIZE               0x1000
#define BYTE                    0x8
#define FBYTE                   0x20
#define INDEX_FROM_BIT(addr)    (addr/FBYTE)
#define OFFSET_FROM_BIT(addr)   (addr%FBYTE)


typedef struct page_count{
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

    __void__ __init_paging__(__void__);
    __static__ __void__ __set_frame__(uint32_t);
    __static__ uint32_t __get_frame__(__void__);
    __static__ __void__ __clear_frame__(uint32_t);
    __static__ uint32_t __test_frame__(uint32_t);
    __void__ __alloc_frame__(page_t*, uint32_t, uint32_t);
    __void__ __free_frame__(page_t*);
    __void__ switch_page_directory(page_directory_t*);
    page_t* __get_page__(uint32_t, int32_t, page_directory_t*);
    uint32_t kmalloc_main (uint32_t, int32_t, uint32_t*);
    uint32_t kmalloc (uint32_t);
    uint32_t kmalloc_align (uint32_t);
    uint32_t kmalloc_phy (uint32_t, uint32_t*);
    uint32_t kmalloc_phy_align (uint32_t, uint32_t*);

#endif