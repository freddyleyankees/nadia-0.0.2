/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "../include/int.h"
#include "../include/string.h"
#include "../include/panic.h"
#include "../drivers/vram/display.h"

__static__ __void__ isr0_callback(registers_t reg){
    __kprint_video__("interrupt divide by zero");
}

__static__ __void__ isr1_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr2_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr3_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr4_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr5_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr6_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr7_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr8_callback(registers_t reg){
    uint8_t* str,*error;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    error = __itoab__(reg.err_code,16);
    __kprint_video__("Error : ");
    __kprint_video__(error);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr9_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr10_callback(registers_t reg){
    uint8_t* str,*error;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    error = __itoab__(reg.err_code,16);
    __kprint_video__("Error : ");
    __kprint_video__(error);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr11_callback(registers_t reg){
    uint8_t* str,*error;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    error = __itoab__(reg.err_code,16);
    __kprint_video__("Error : ");
    __kprint_video__(error);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr12_callback(registers_t reg){
    uint8_t* str,*error;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    error = __itoab__(reg.err_code,16);
    __kprint_video__("Error : ");
    __kprint_video__(error);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr13_callback(registers_t reg){
    uint8_t* str,*error;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    error = __itoab__(reg.err_code,16);
    __kprint_video__("Error : ");
    __kprint_video__(error);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr14_callback(registers_t reg){
    uint8_t* str,*error;
    uint32_t addr_error, present, rw, user,reserved,id;
    __asm__ __volatile__("mov %%cr2, %0" : "=r" (addr_error));
    
    present  =   !(reg.err_code & 0x1);
    rw       =   reg.err_code & 0x2;
    user     =   reg.err_code & 0x4;
    reserved =   reg.err_code & 0x8;
    id       =   reg.err_code & 0x10;

    
    if(present){
        str = __itoab__(reg.num_int,16);
        __kprint_video__("\n");
        __kprint_video__("\ninterrupt 0x");
        __kprint_video__(str);
        str = __itoab__(reg.err_code,16);
        __kprint_video__("\nerror interrupt number ");
        __kprint_video__(str);
        str = __itoab__(addr_error,16);
        __kprint_video__("\nAddress error 0x");
        __kprint_video__(str);
        panic("\nthis page is not present \n");
    }
    if(rw){
        panic("this page is in mode [ Read-only ]\n");
    }
    if(user){
        panic("this page is not access in [ user-mode ]\n");
    }
    if(reserved){
        panic("you want access to page reserved by cpu");
    }
    if(id){
        panic("intruction not found\n");
    }
}
__static__ __void__ isr16_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}

__static__ __void__ isr17_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}

__static__ __void__ isr18_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr19_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}
__static__ __void__ isr_reserved_callback(registers_t reg){
    uint8_t* str;
    str = __itoab__(reg.num_int,16);
    __kprint_video__("interrupt 0x");
    __kprint_video__(str);
    __kprint_video__("\n");
    panic("panic system!");
}

__void__ divid_by_zero(__void__){
    __register_int_handler__(ISR0,&isr0_callback);
}
__void__ nm_int(__void__){
    __register_int_handler__(ISR2,&isr2_callback);
}
__void__ break_point(__void__){
    __register_int_handler__(ISR3,&isr3_callback);
}
__void__ overflow(__void__){
    __register_int_handler__(ISR4,&isr4_callback);
}
__void__ bound_rang_exc(__void__){
    __register_int_handler__(ISR5,&isr5_callback);
}
__void__ invalid_op(__void__){
    __register_int_handler__(ISR6,&isr6_callback);
}
__void__ device_not_avail(__void__){
    __register_int_handler__(ISR7,&isr7_callback);
}
__void__ double_fault(__void__){
    __register_int_handler__(ISR8,&isr8_callback);
}
__void__ copro_seg(__void__){
    __register_int_handler__(ISR9,&isr9_callback);
}
__void__ invalid_tss(__void__){
    __register_int_handler__(ISR16,&isr16_callback);
}
__void__ seg_not_pre(__void__){
    __register_int_handler__(ISR11,&isr11_callback);
}
__void__ stack_seg_error(__void__){
    __register_int_handler__(ISR12,&isr12_callback);
}
__void__ general_protect(__void__){
    __register_int_handler__(ISR13,&isr13_callback);
}
__void__ page_fault(__void__){
    __register_int_handler__(ISR14,&isr14_callback);
}
__void__ fpu_error(__void__){
    __register_int_handler__(ISR16,&isr16_callback);
}
__void__ align_check(__void__){
    __register_int_handler__(ISR17,&isr17_callback);
}
__void__ machine_check(__void__){
    __register_int_handler__(ISR18,&isr18_callback);
}
__void__ fp_excep(__void__){
    __register_int_handler__(ISR19,&isr19_callback);
}
__void__ sys_call(__void__){
    __register_int_handler__(INT_SYS_CALL,&syscall_callback);
}
__void__ default_int(__void__){
    __register_int_handler__(ISR1,&isr_reserved_callback);
    __register_int_handler__(ISR15,&isr_reserved_callback);
    __register_int_handler__(ISR20,&isr_reserved_callback);
    __register_int_handler__(ISR21,&isr_reserved_callback);
    __register_int_handler__(ISR22,&isr_reserved_callback);
    __register_int_handler__(ISR23,&isr_reserved_callback);
    __register_int_handler__(ISR24,&isr_reserved_callback);
    __register_int_handler__(ISR25,&isr_reserved_callback);
    __register_int_handler__(ISR26,&isr_reserved_callback);
    __register_int_handler__(ISR27,&isr_reserved_callback);
    __register_int_handler__(ISR28,&isr_reserved_callback);
    __register_int_handler__(ISR29,&isr_reserved_callback);
    __register_int_handler__(ISR30,&isr_reserved_callback);
    __register_int_handler__(ISR31,&isr_reserved_callback);
}

__void__ init_int(__void__){
    divid_by_zero();
    nm_int();
    break_point();
    overflow();
    bound_rang_exc();
    invalid_op();
    device_not_avail();
    double_fault();
    copro_seg();
    invalid_tss();
    seg_not_pre();
    general_protect();
    page_fault();
    fpu_error();
    align_check();
    machine_check();
    fp_excep();
    default_int();
    sys_call();
}