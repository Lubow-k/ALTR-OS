#!/bin/bash
gcc -m32 -ffreestanding -c -o kernel.o %SRC%/kernel.c
ld -m i386pe -o kernel.tmp -Ttext 0x20200 kernel.o
objcopy -I pe-i386 -O binary kernel.tmp kernel.bin

dd if=kernel.bin of=boot.img conv=notrunc seek=1
