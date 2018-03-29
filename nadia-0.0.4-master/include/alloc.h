/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "types.h"
#ifdef __POS_FRAME__
uint32_t current_addr_frame = 0;
#else
__extern__ uint32_t current_addr_frame;
#endif
uint32_t mem_kmalloc_real(size_t, uint32_t, uint32_t*);
uint32_t mem_kmalloc(size_t);
uint32_t mem_kmalloc_aligned(size_t);
uint32_t mem_kmalloc_phy(size_t, uint32_t*);
uint32_t mem_kmalloc_phy_aligned(size_t, uint32_t*);
uint32_t mem_addr_pos(__void__);
