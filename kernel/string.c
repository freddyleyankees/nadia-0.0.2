#include "../include/string.h"

int32_t __atoi__(uint8_t* str){
	/* this function allow us to transform string number to integer */

}

int32_t __atoib__(uint8_t* str, uint8_t base){
	/* this function allow us to transform string number to integer in the base */
}

uint8_t* __itoa__(int32_t a){
	uint8_t mod,tmp;
	uint32_t i=0,n;
	n = (uint32_t) a;
	
	i=0;
	do{
		mod = n%10;
		str_buffer[i++] = (mod < 10) ? (mod + '0') : ('\0');
	}while(n /= 10);
	str_buffer[i--] = 0;
	for (uint32_t j = 0; j < i; j++, i--) {
		tmp = str_buffer[j];
		str_buffer[j] = str_buffer[i];
		str_buffer[i] = tmp;
	}
	return str_buffer;
}

uint8_t* __itoab__(int32_t a, uint8_t base){
	uint8_t mod,tmp;
	uint32_t i=0,n;
	n = (uint8_t) a;
	
	i=0;
	do{
		
		switch(base){
			case 2:
				mod = n%base;
				str_buffer[i++] = (mod < base) ? (mod + '0') : ('\0');
				if (n/base == 0)
				{
					/* code */
					str_buffer[i++] = 'b';
					str_buffer[i++] = '0';
				}
				break;
			case 8:
				mod = n%base;
				str_buffer[i++] = (mod < base) ? (mod + '0') : ('\0');
				if (n/base == 0)
				{
					/* code */
					str_buffer[i++] = 'o';
					str_buffer[i++] = '0';
				}
				break;
			case 10:
				mod = n%base;
				str_buffer[i++] = (mod < base) ? (mod + '0') : ('\0');
				break;
			case 16:
				mod = n%base;
				str_buffer[i++] = (mod < 10) ? (mod + '0') : (mod-10 + 'a');
				if (n/base == 0 && a<0x10)
				{
					/* code */
					str_buffer[i++] = '0';
				}
				break;
			default:
				mod = n%10;
				str_buffer[i++] = (mod < 10) ? (mod + '0') : ('\0');
				break;
		}
	}while(n /= base);

	str_buffer[i--] = 0;
	for (uint32_t j = 0; j < i; j++, i--) {
		tmp = str_buffer[j];
		str_buffer[j] = str_buffer[i];
		str_buffer[i] = tmp;
	}
	return str_buffer;
}

uint32_t __strlen__(uint8_t* str){

}

uint32_t __strcpy__(uint8_t* dest, uint8_t* src){

}

uint32_t __strsrch__(uint8_t* motif, uint8_t* str){

}

uint32_t __strcmp__(uint8_t* strcmp, uint8_t* str){

}

uint32_t __stroccur__(uint8_t* strocc, uint8_t* str){

}

uint32_t __strmem__(uint8_t* str){
	
}