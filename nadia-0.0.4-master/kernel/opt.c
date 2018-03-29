/**
 *	Nadia operating system 
 *  @Author Kabong freddy
 *  @copyright(c) 2017 - 2018
 *  @Email freddyleyankees@gmail.com
 * 
 */

#include "../include/opt.h"

uint32_t div_round_up_digit_by(uint32_t n, uint32_t m){
    uint32_t div = (n/m);
    return (n/m)*m < n ? div + 1: div ;
}
uint32_t div_round_default_digit_by(uint32_t n, uint32_t m){
    uint32_t div = (n/m);
    return (n/m)*m <= n ? div: 0;
}