#include "types.h"
#ifdef __MEMORY_H__
	__void__ __memset__ (uint8_t*,uint8_t,uint32_t);
	__void__ __memcpy__ (uint32_t,uint32_t,uint8_t);
	__void__ __get_byte__ (uint32_t,uint32_t,uint8_t);
	__void__ __get_word__ (uint32_t,uint32_t,uint8_t);
	__void__ __get_double_word__ (uint32_t,uint32_t,uint8_t);
#endif
#ifdef __DESCR_TABLE_H__
	__void__ __init_table_descr__(__void__);
#endif
