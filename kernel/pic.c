/**
* Nadia OS descriptor file .c
*
* This file describe 
*
* @author : kabong freddy
*/

#include "../include/types.h"
#include "../include/io.h"

__extern__ __void__ __INIT_PIC__(__void__){

	/* Initialisation de ICW1 */
	outb(0x20, 0x11);
	outb(0xA0, 0x11);

	/* Initialisation de ICW2 */
	outb(0x21, 0x20);	/* vecteur de depart = 32 */
	outb(0xA1, 0x28);	/* vecteur de depart = 96 */

	/* Initialisation de ICW3 */
	outb(0x21, 0x04);
	outb(0xA1, 0x02);

	/* Initialisation de ICW4 */
	outb(0x21, 0x01);
	outb(0xA1, 0x01);

	/* masquage des interruptions */
	outb(0x21, 0x0);
	outb(0xA1, 0x0);
}
 
