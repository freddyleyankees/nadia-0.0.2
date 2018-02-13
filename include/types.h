#include "config.h"
#ifndef __TYPES_H__
#define __TYPES_H__

	typedef char int8_t;
	typedef unsigned char uint8_t;
	typedef signed char sint8_t;

	typedef short int16_t;
	typedef unsigned short uint16_t;
	typedef signed short sint16_t;

	typedef int int32_t;
	typedef unsigned int uint32_t;
	typedef signed int sint32_t;

	typedef unsigned int bool_t;
	typedef unsigned int bool_t;

	typedef unsigned int pid_t;
	typedef unsigned int size_t;
	typedef void* type_t;
	__extern__ uint8_t* _stdin_;
	__extern__ uint8_t* _stdout_;
	__extern__ uint8_t* _stderr_;
#endif