#include "types.h"
#ifndef __TIMER_H__
#define __TIMER_H__ 

typedef struct  date_t{
	uint32_t yeah; 
	uint8_t month; 
	uint8_t day; 
}date_t;

typedef struct  time_t{
	uint8_t hour; 
	uint8_t min; 
	uint8_t sec; 
}time_t;

typedef struct  __timer_struct__{
	date_t* date;
	time_t* time;
}timer_t;

#endif