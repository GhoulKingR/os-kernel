CC = i686-elf-gcc
CPP = i686-elf-g++
AS = i686-elf-as
QEMU = qemu-system-i386
OBJFILES = obj

CCFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra
CPPFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
CCLDFLAGS = -T link.ld -ffreestanding -O2 -nostdlib -lgcc

$(OBJFILES):
	mkdir $(OBJFILES)
	$(CC) $(CCFLAGS) -c drivers/*.c #-o $(OBJFILES)/drivers.o
	$(CC) $(CCFLAGS) -c libs/*.c #-o $(OBJFILES)/drivers.o
	mv *.o $(OBJFILES)/
	$(CC) $(CCFLAGS) -c kernel.c -o $(OBJFILES)/kernel.o
	$(AS) -o $(OBJFILES)/asmdrivers.o drivers/*.s
	$(AS) -o $(OBJFILES)/boot.o boot.s

myos.bin: $(OBJFILES)
	$(CC) $(CCLDFLAGS) -o myos.bin $(OBJFILES)/*.o

build: myos.bin

run: myos.bin
	$(QEMU) -kernel myos.bin

clean:
	rm -f *.o *.bin a.out
	rm -rf obj
