/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "../../include/handler.h"
#ifndef __DRIVER_KEYBOARD_H__
#define __DRIVER_KEYBOARD_H__
#include "../../include/io.h"

#define __KBD_READ_STATUT_PORT__			0x64 	/* read status register */
#define __KBD_SEND_CMD_PORT__				0x64	/* write | send command to controller */
#define __KBD_READ_BUFFER_PORT__			0x60	/* read input buffer */
#define __KBD_WRITE_BUFFER_PORT__			0x60	/* write input buffer */

/* keyboard controller commands */ 

#define __KBD_READ_CTRL_BYTE__				0x20	/* read input buffer */
#define __KBD_WRITE_CTRL_BYTE__				0x60	/* read input buffer */
#define __KBD_SEFT_TEST__					0xAA	/* read input buffer */
#define __KBD_INTERFACE_TEST__				0xAB	/* read input buffer */
#define __KBD_DISABLE__						0xAD	/* read input buffer */
#define __KBD_ENABLE__						0xAE	/* read input buffer */
#define __KBD_READ_INPUT_PORT__				0xC0	/* read input buffer */
#define __KBD_READ_OUTPUT_PORT__			0xD0	/* read input buffer */
#define __KBD_WRITE_OUTPUT_PORT__			0xD1	/* read input buffer */
#define __KBD_ENABLE_A20__					0xDD	/* read input buffer */
#define __KBD_DISABLE_A20__					0xDF	/* read input buffer */
#define __KBD_READ_TEST_INPUT__				0xE0	/* read input buffer */
#define __KBD_RESET_SYSTEM__				0xFE	/* read input buffer */

#define __LSHIFT_KEY_ACTIVE__				0x01		
#define __RSHIFT_KEY_ACTIVE__				0x02		
#define __LCTRL_KEY_ACTIVE__				0x03		
#define __RCTRL_KEY_ACTIVE__				0x04		
#define __ALT_KEY_ACTIVE__					0x05		
#define __ALTGR_KEY_ACTIVE__				0x06		
#define __CAPLOCK_KEY_ACTIVE__				0x07		
#define __NUMLOCK_KEY_ACTIVE__				0x08
		
#define __KEY_NOACTIVE__					0x00		

#define __TYPE_KEYBOARD_EN__				0x1		
#define __TYPE_KEYBOARD_FR__				0x2

#define __KEYBOARD_NO_DEFINE__				0x0
#define __KEYBOARD_DEFINE__					0x1


#define __wait_input_buf_empty__()		({										 	\
											uint8_t _a, _b; 						\
											__asm__("1:"::); 						\
											do{ 									\
												_a = inb(__KBD_READ_STATUT_PORT__); \
												_b = _a & 2;						\
											}while(_b!=0); 							\
										})

#define __wait_output_buf_empty__()		({ 											\
											uint8_t _a, _b; 						\
											__asm__("1:"::); 						\
											do{ 									\
												_a = inb(__KBD_READ_STATUT_PORT__); \
												_b = _a & 1; 						\
											}while(_b==0);	 						\
										})

__static__ __void__ __kbd_callback__(registers_t);
__static__ __void__ __set_led_kbd__(uint8_t, uint8_t, uint8_t);
__static__ __void__ __set_self_test_kbd__();
__static__ __void__ __set_interface_test_kbd__();
__static__ __void__ __disable_kbd__();
__static__ __void__ __cmd_read_port_kbd__();
__static__ __void__ __cmd_write_port_kbd__();
__static__ uint8_t __read_input_port_kbd__();
__static__ __void__ __write_output_port_kbd__(uint8_t);
__static__ __void__ __enable_kbd__();
__static__ __void__ __system_reset__();
__static__ __void__ __init_device_keyboard__();
__void__ __init_keyboard_driver__();
__void__ __get_scanCode__();


struct __ctrl_key_struct__
{
	uint8_t lshift;
	uint8_t rshift;
	uint8_t lctrlkey;
	uint8_t rctrlkey;
	uint8_t altkey;
	uint8_t altGrkey;
	uint8_t caplock;
	uint8_t numlock;
};

struct __ctrl_key_struct__ key_controller;

__static__ uint8_t __fn_key_controller__(struct __ctrl_key_struct__*, uint8_t);
__static__ uint8_t __load_char__(uint8_t*, uint8_t);
__static__ __void__ __set_fn_key__(struct __ctrl_key_struct__*, uint8_t, uint8_t);
__static__ uint8_t __load_kbd__(uint8_t);
__static__ uint8_t* __get_kbd__();
__static__ __void__ __set_kbd__(uint8_t);

#endif
