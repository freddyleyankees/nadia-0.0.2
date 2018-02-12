#ifndef __ORDERED_LIST_H__
#define __ORDERED_LIST_H__
#include "types.h"

typedef sint8_t (*less_than_t)(type_t, type_t);

typedef struct list{
    type_t *array;
    uint32_t size;
    uint32_t max_size;
    less_than_t less_than;
} list_t;

list_t create_list(uint32_t, less_than_t);
list_t place_list(type_t, uint32_t, less_than_t);

__void__ insert_list(type_t, list_t *);
__void__ destroy_list(list_t *);
type_t lookup_list(uint32_t, list_t *);
__void__ remove_list(uint32_t, list_t *);

#endif