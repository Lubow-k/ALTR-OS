FILE = hello

all: emulate clean


asm: $(FILE).asm
	nasm -fbin $(FILE).asm -o $(FILE).bin

img: asm
	dd if=/dev/zero of=$(FILE).img bs=1024 count=1440
	dd if=$(FILE).bin of=$(FILE).img conv=notrunc

emulate: img
	qemu-system-i386 -monitor stdio $(FILE).img

clean:
	rm $(FILE).img
	rm $(FILE).bin
