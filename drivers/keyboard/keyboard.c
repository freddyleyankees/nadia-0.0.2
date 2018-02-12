#include "keyboard.h"
#include "../../include/string.h"


uint8_t scanCode[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,		/*esc*/
					  0x31,0x21,0x21,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x32,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x33,0x23,0x23,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x34,0x24,0x24,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x35,0x25,0x25,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x36,0x5e,0x5e,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x37,0x26,0x26,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x38,0x2a,0x2a,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x39,0x28,0x28,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x30,0x29,0x29,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x2D,0x5f,0x5f,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x3D,0x2B,0x2B,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x71,0x51,0x51,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x77,0x57,0x57,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x65,0x45,0x45,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x72,0x52,0x52,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x74,0x54,0x54,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x79,0x59,0x59,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x75,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x69,0x49,0x49,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x6f,0x4f,0x4f,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x70,0x50,0x50,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x5b,0x7b,0x7b,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x5d,0x7d,0x7d,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x61,0x41,0x41,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x73,0x53,0x53,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x64,0x44,0x44,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x66,0x46,0x46,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x67,0x47,0x47,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x68,0x48,0x48,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x6a,0x4a,0x4a,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x6b,0x4b,0x4b,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x6c,0x4c,0x4c,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x3b,0x3a,0x3a,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x27,0x22,0x22,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x60,0x7e,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x5c,0x7c,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x7a,0x5a,0x5a,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x78,0x58,0x58,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x63,0x43,0x43,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x76,0x56,0x56,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x62,0x42,0x42,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x6e,0x4e,0x4e,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x6d,0x4d,0x4d,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x2c,0x3c,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x2e,0x3e,0x3e,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x2f,0x3f,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x2a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,				/* caplock */
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
					  
					  

						};
buffChr = 0;
uint8_t* currentscanCode;
uint8_t kbdDefined = __KEYBOARD_NO_DEFINE__;

__extern__ __void__ __kprint_video__(uint8_t* str);
__extern__ __void__ __kernel_Put_Chr__(uint8_t, uint8_t );

__static__ uint8_t* __get_kbd__(){
	return currentscanCode;
}

__static__ __void__ __set_kbd__(uint8_t type){
	switch(type){
		case 0x1:
			currentscanCode = scanCode;
			break;
	}
}

__static__ uint8_t __load_kbd__(uint8_t scan){
	uint8_t* keyScanCode;
	keyScanCode = __get_kbd__();
	return __load_char__(keyScanCode, scan);
}

__static__ uint8_t __load_char__(uint8_t* keyScanCode, uint8_t scan){
	/* 
		no-control : 				0000000000000000		0x00
		Left_shift-control : 		0000000000000001		0x01
		Right_shift-control : 		0000000000000010		0x02
		Left_ctrl-control : 		0000000000000100		0x03
		Right_ctrl-control : 		0000000000001000		0x04
		Atl-control : 				0000000000010000		0x05
		AtlGr-control : 			0000000000100000		0x06
		capLock-control : 			0000000001000000		0x07
		numLock-control : 			0000000010000000		0x08
	*/
	struct __ctrl_key_struct__* __strt_keyctrl__ = &key_controller; 
	__static__ uint16_t channel_kbd  = 0;
	channel_kbd = (uint16_t) (__strt_keyctrl__->lshift + __strt_keyctrl__->rshift + __strt_keyctrl__->lctrlkey + __strt_keyctrl__->rctrlkey + __strt_keyctrl__->altkey + __strt_keyctrl__->altGrkey + __strt_keyctrl__->caplock + __strt_keyctrl__->numlock);
	
	return keyScanCode[9*(scan-1)+channel_kbd];
			
}


__static__ __void__ __set_fn_key__(struct __ctrl_key_struct__* __strt_keyctrl__, uint8_t index, uint8_t val){
	switch(index){
		case 0x1:
			__strt_keyctrl__->lshift = val;
			break;
		case 0x2:
			__strt_keyctrl__->rshift = val;
			break;
		case 0x3:
			__strt_keyctrl__->lctrlkey = val;
			break;
		case 0x4:
			__strt_keyctrl__->rctrlkey = val;
		case 0x5:
			__strt_keyctrl__->altkey = val;
			break;
		case 0x6:
			__strt_keyctrl__->altGrkey = val;
			break;
		case 0x7:
			__strt_keyctrl__->caplock = val;
			break;
		case 0x8:
			__strt_keyctrl__->numlock = val;
			break;
	}
}

__static__ uint8_t __fn_key_controller__(struct __ctrl_key_struct__* __strt_keyctrl__, uint8_t key){
	__static__ uint8_t key_cap_lock =0, key_num_lock =0, key_2nd_ctrl =0;
	if (key == 0xe0)
	{
		/* code */
		++key_2nd_ctrl;
		return 10;
	}
	if (key != 0xe0 && key_2nd_ctrl == 0){
		if (key == 0x2a || key == 0xaa){		/* CTRL LEFT KEY*/
			if (key == 0x2a)
				__set_fn_key__(__strt_keyctrl__, 1, __LSHIFT_KEY_ACTIVE__);
			else
				__set_fn_key__(__strt_keyctrl__, 1, __KEY_NOACTIVE__);
			return 1;
		}
		else if (key == 0x36 || key == 0xb6){		/* CTRL RIGHT KEY*/
			if (key == 0x36)
				__set_fn_key__(__strt_keyctrl__, 2, __RSHIFT_KEY_ACTIVE__);
			else
				__set_fn_key__(__strt_keyctrl__, 2, __KEY_NOACTIVE__);
			return 2;
		}
		else if (key == 0x1d || key == 0x9d){
			if (key == 0x1d)
				__set_fn_key__(__strt_keyctrl__, 3, __LCTRL_KEY_ACTIVE__);
			else
				__set_fn_key__(__strt_keyctrl__, 3, __KEY_NOACTIVE__);
			return 3;
		}
		else if (key == 0x38 || key == 0xb8){
			if (key == 0x38)
				__set_fn_key__(__strt_keyctrl__, 5, __ALT_KEY_ACTIVE__);
			else
				__set_fn_key__(__strt_keyctrl__, 5, __KEY_NOACTIVE__);
			return 4;
		}
		else if (key == 0x3a || key == 0xba){
			if(key == 0x3a){
				if (key_cap_lock == 0){
					__set_fn_key__(__strt_keyctrl__, 7, __CAPLOCK_KEY_ACTIVE__);
					++key_cap_lock;
				}else{
					__set_fn_key__(__strt_keyctrl__, 7, __KEY_NOACTIVE__);
					--key_cap_lock;
				}
			}
			return 5;
		}
		else if (key == 0x45 || key == 0xc5){
			if (key_num_lock == 0){
				__set_fn_key__(__strt_keyctrl__, 8, __NUMLOCK_KEY_ACTIVE__);
				++key_num_lock;
			}else{
				__set_fn_key__(__strt_keyctrl__, 8, __KEY_NOACTIVE__);
				--key_num_lock;
			}
			return 5;
		}
	}
	else if(key_2nd_ctrl){
		
		if (key == 0x1d || key == 0x9d){
			if (key == 0x1d){
				__set_fn_key__(__strt_keyctrl__, 4, __RCTRL_KEY_ACTIVE__);
			}
			else{
				__set_fn_key__(__strt_keyctrl__, 4, __KEY_NOACTIVE__);
			}
			key_2nd_ctrl=0;
			return 6;
		}
		else if (key == 0x38 || key == 0xb8){
			if (key == 0x38){
				__set_fn_key__(__strt_keyctrl__, 6, __ALTGR_KEY_ACTIVE__);
			}
			else{
				__set_fn_key__(__strt_keyctrl__, 6, __KEY_NOACTIVE__);
			}
			key_2nd_ctrl=0;
			return 7;
		}
		
	}
	return 0;
}


__static__ __void__ __kbd_callback__(registers_t reg){
	uint8_t scan_code,ctrl;
	uint8_t* str;
	__static__ uint32_t i = 0;
	scan_code = __read_input_port_kbd__();
	ctrl = __fn_key_controller__(&key_controller, scan_code);
	if (kbdDefined != __KEYBOARD_DEFINE__)
	{
		/* code */
		__set_kbd__(__TYPE_KEYBOARD_EN__);
		kbdDefined = __KEYBOARD_DEFINE__;
	}
	if (ctrl){
		if (ctrl < 10)
		{
			/* code allow to change type keyboard */
		
			/*switch(ctrl){
				case 0x1:
					__strt_keyctrl__->lshift = val;
					break;
				case 0x2:
					__strt_keyctrl__->rshift = val;
					break;
				case 0x3:
					__strt_keyctrl__->lctrlkey = val;
					break;
				case 0x4:
					__strt_keyctrl__->rctrlkey = val;
				case 0x5:
					__strt_keyctrl__->altkey = val;
					break;
				case 0x6:
					__strt_keyctrl__->altGrkey = val;
					break;
				case 0x7:
					__strt_keyctrl__->caplock = val;
					break;
				case 0x8:
					__strt_keyctrl__->numlock = val;
					break;
			}*/
			
		}
	}
	else{
		if(scan_code<0x80){
			
			__kernel_Put_Chr__(__load_kbd__(scan_code),0x0f);

		}
	}

	
}

/* init device */ 
__static__ __void__ __init_device_keyboard__(){
	uint8_t a=0, b=0;
	 __disable_kbd__();				/* Disable keyboard device */
	__cmd_read_port_kbd__();
	a = __read_input_port_kbd__();							/* read data in output port */ 
	__cmd_write_port_kbd__();
	__write_output_port_kbd__(a);						/* send command to write data in output port */ 
	__enable_kbd__();
	__kprint_video__("keyboard is initialized --- [ ok ]\n");
}

__void__ __init_keyboard_driver__(){
	__init_device_keyboard__();
	__register_int_handler__(IRQ1,&__kbd_callback__);
}

__static__ __void__ __set_led_kbd__(uint8_t a, uint8_t b, uint8_t c){

}

__static__ __void__ __set_self_test_kbd__(){

}

__static__ __void__ __set_interface_test_kbd__(){

}

__static__ __void__ __disable_kbd__(){
	__wait_input_buf_empty__();		/* test if buffer input is full */
	outb(__KBD_SEND_CMD_PORT__, __KBD_DISABLE__);
}

__static__ __void__ __cmd_read_port_kbd__(){
	__wait_input_buf_empty__();		/* test if buffer input is full */
	outb(__KBD_SEND_CMD_PORT__, __KBD_READ_OUTPUT_PORT__);		/* send command to read output port */ 
}

__static__ uint8_t __read_input_port_kbd__(){
	uint8_t b;
	__wait_output_buf_empty__();	/* test if buffer output is empty */
	b = inb(__KBD_READ_BUFFER_PORT__);
	return b;
}

__static__ __void__ __cmd_write_port_kbd__(){
	__wait_input_buf_empty__();		/* test if buffer input is full */
	outb(__KBD_SEND_CMD_PORT__, __KBD_WRITE_OUTPUT_PORT__);		/* send command to read output port */ 
}

__static__ __void__ __write_output_port_kbd__(uint8_t a){
	uint8_t d;
	__wait_input_buf_empty__();		/* test if buffer input is full */
	d = a|2;
	outb(__KBD_WRITE_BUFFER_PORT__,d);
}

__static__ __void__ __enable_kbd__(){
	__wait_input_buf_empty__();		/* test if buffer input is full */
	outb(__KBD_SEND_CMD_PORT__, __KBD_ENABLE__);					/* send command to enable A20 line */ 
	__wait_input_buf_empty__();		/* test if buffer input is full */
}

__static__ __void__ __system_reset__(){

}