/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#ifndef __CONST__
	#define __CONST__
	
	#define __SYS_VERSION__ 				"0.0.1"
	#define __SYS_AUTHOR__ 					"0.0.1"
	#define __SYS_SERIAL_NUMBER__ 			"0.0.1"
	#define __SYS_ID__ 						"0.0.1"

	#define PAGE_SIZE               		0x1000
	#define BYTE                    		0x8
	#define ADDR_SIZE                  		0x20
	#define MEMORY_HIGH						0x40000000	// 1Gb 
	#define MEMORY_LOW 						0x100000
	#define MIN_MEMORY_ALLOC 				PAGE_SIZE
	#define END_MEMORY_UNUSED	 			0x400000
	#define MEMORY_MAPPING	 				0x36000000
	#define END_MEMORY_AVAIL	 			0x36000000
	#define NB_T_PAGES						(MEMORY_HIGH/PAGE_SIZE)
	#define END_MEMORY_KERNEL				0x1000000
	#define PAGE_DIRECTORY_SIZE				0x400
	#define NULL							0x0

	typedef struct meminfo{
		uint32_t mem_info_upper;
		uint32_t mem_info_lower;
		uint32_t mem_info_page_size;
		uint32_t mem_info_nb_page;
		uint32_t mem_info_directory_page_size;
		uint32_t mem_info_bit_per_int_page;
		uint32_t mem_info_kernel_start;
		uint32_t mem_info_kernel_end;
		uint32_t mem_info_cur_pos_frame;
		uint32_t mem_info_heap_frame_start;
		uint32_t mem_info_heap_addr_size;
		uint32_t mem_info_heap_size_default;
		uint32_t mem_info_all_mem_avail;
		uint32_t mem_info_heap_nb_block;
		uint32_t mem_info_heap_sect_int;
		uint32_t mem_info_heap_num_sect;
		uint32_t mem_info_heap_sect_size;
		uint32_t mem_info_heap_bit_per_int_sect;
		uint32_t mem_info_elf_sect;
		uint32_t mem_info_map;
	}mem_info_t;

	
	#ifdef __MEMORY_INFO__
	mem_info_t memory_info_system;
	#else
	__extern__ mem_info_t memory_info_system;
	#endif
#endif