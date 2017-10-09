/**
* Nadia OS descriptor Header
*
* this file describe input output port
*
* @author : kabong freddy
*/

/* desactive les interruptions */
#define cli __asm__ __volatile__("cli"::)

/* reactive les interruptions */
#define sti __asm__ __volatile__("sti"::)

/* ecrit un octet sur un port */
#define outb(port,value) \
	__asm__ __volatile__ ("outb %%al, %%dx" :: "d" (port), "a" (value));


/* lit un octet sur un port */
#define inb(port) ({    \
	unsigned char _v;       \
	__asm__ __volatile__ ("inb %%dx, %%al" : "=a" (_v) : "d" (port)); \
        _v;     \
})

/* ecrit un octet sur un port et marque une temporisation  */
#define outbp(port,value) \
	__asm__ __volatile__ ("outb %%al, %%dx; jmp 1f; 1:jmp 1f; 1:" :: "d" (port), "a" (value));

#define inbp(port) ({    \
	unsigned char _v;       \
	__asm__ __volatile__ ("inb %%dx, %%al; jmp 1f; 1:jmp 1f; 1:" : "=a" (_v) : "d" (port)); \
        _v;     \
})

/* ecrit un mot de 16 bits sur un port */
#define outw(port,value) \
	__asm__ __volatile__ ("outw %%ax, %%dx" :: "d" (port), "a" (value));

/* lit un mot de 16 bits sur un port */
#define inw(port) ({		\
	uint16_t _v;			\
	__asm__ __volatile__ ("inw %%dx, %%ax" : "=a" (_v) : "d" (port));	\
        _v;			\
})

/* ecrit un octet sur un port et marque une temporisation  */
#define outwp(port,value) \
	__asm__ __volatile__ ("outw %%ax, %%dx; jmp 1f; 1:jmp 1f; 1:" :: "d" (port), "a" (value));
	
#define inwp(port) ({    \
	uint16_t _v;       \
	__asm__ __volatile__ ("inw %%dx, %%ax; jmp 1f; 1:jmp 1f; 1:" : "=a" (_v) : "d" (port)); \
        _v;     \
})

/* ecrit un mot de 16 bits sur un port */
#define outl(port,value) \
	__asm__ __volatile__ ("outl %%eax, %%dx" :: "d" (port), "a" (value));

/* lit un mot de 32 bits sur un port */
#define inl(port) ({		\
	uint32_t _v;			\
	__asm__ __volatile__ ("inl %%dx, %%eax" : "=a" (_v) : "d" (port));	\
        _v;			\
})

/* ecrit un octet sur un port et marque une temporisation  */
#define outlp(port,value) \
	__asm__ __volatile__ ("outl %%eax, %%dx; jmp 1f; 1:jmp 1f; 1:" :: "d" (port), "a" (value));

#define inlp(port) ({    \
	uint32_t _v;       \
	__asm__ __volatile__ ("inl %%dx, %%eax; jmp 1f; 1:jmp 1f; 1:" : "=a" (_v) : "d" (port)); \
        _v;     \
})
