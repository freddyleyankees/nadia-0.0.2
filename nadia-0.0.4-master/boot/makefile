OBJ=boot.o

all: $(OBJ) 

boot.o: boot.asm
	rm -f $(OBJ) *.o
	nasm -f bin -o $@ $^ ;

