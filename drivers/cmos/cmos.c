/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#ifndef __CMOS_DRIVER_H__
#define __CMOS_DRIVER_H__
#include "../../include/types.h"
#include "../../include/io.h"

#define __CMOS_REGISTER_PORT__  		0x70
#define __CMOS_RW_PORT__  				0x71

#endif

__extern__ uint8_t __CMOS_READ__(uint8_t addr){
	outbp(addr,__CMOS_REGISTER_PORT__);
	return inbp(__CMOS_RW_PORT__);
}

__extern__ __void__ __CMOS_WRITE__(uint8_t addr, uint8_t val){
	outbp(addr,__CMOS_REGISTER_PORT__);
	outbp(val,__CMOS_RW_PORT__);
}

__extern__ __void__ __CMOS_END__(){
	outbp(0X80,__CMOS_REGISTER_PORT__);
}

