GCCPARAMS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector

NASMPARAMS = -f elf

LINKER = entry

LDPARAMS = -melf_i386 

BOOT = boot.o

OBJECT = main.o gdt.o segment.o seg_asm.o pic.o idt.o handler.o keyboard.o pit.o paging.o mem.o video.o console.o pci.o string.o panic.o int.o terminal.o sys.o

%.o: kernel/%.asm
	nasm $(NASMPARAMS) -o $@ $<

%.o: kernel/%.c
	gcc $(GCCPARAMS) -o $@ -c $<

%.o: sys/%.c
	gcc $(GCCPARAMS) -o $@ -c $<

%.o: sys/%.c
	gcc $(GCCPARAMS) -o $@ -c $<

%.o: init/%.c
	gcc $(GCCPARAMS) -o $@ -c $<

%.o: drivers/keyboard/%.c
	gcc $(GCCPARAMS) -o $@ -c $<

%.o: drivers/graphics/%.c
	gcc $(GCCPARAMS) -o $@ -c $<

%.o: drivers/pci/%.c
	gcc $(GCCPARAMS) -o $@ -c $<

nadia.bin: linker.ld $(OBJECT)
	sudo cp boot/boot.o ./
	ld $(LDPARAMS) -T $< -o $@ $(BOOT) $(OBJECT)

install: nadia.bin
	sudo cp $< /boot/nadia.bin
	

nadia.iso: nadia.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo '' >> iso/boot/grub/grub.cfg
	echo 'menuentry "My operating system" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/nadia.bin' >> iso/boot/grub/grub.cfg
	echo '  boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso
	rm -f *.o *.img *.bin
qemu:
	qemu-system-x86_64 -cdrom nadia.iso
clean: 
	rm -f *.o *.img *.bin
	sudo rm -f /boot/nadia.bin

build:
	make clean
	make install
	make nadia.iso
	make qemu