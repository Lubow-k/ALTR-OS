FILE = driver_v2

all: emulate clean


asm: $(FILE).asm
	nasm -fbin $(FILE).asm -o $(FILE).bin

img: asm
	dd if=/dev/zero of=$(FILE).img bs=1024 count=1440
	dd if=$(FILE).bin of=$(FILE).img conv=notrunc

	dd if=test.bin of=$(FILE).img conv=notrunc seek=1

emulate: img
	qemu-system-i386 -monitor stdio -drive file=$(FILE).img,if=floppy,format=raw

clean:
	# rm $(FILE).img
	# rm $(FILE).bin
