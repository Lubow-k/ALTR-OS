#!/bin/bash

gcc -m32 -ffreestanding -c -o kernel.o kernel.c
ld -m i386pe -o kernel.tmp -Ttext 0x20200 kernel.o
objcopy -I pe-i386 -O binary kernel.tmp kernel.bin

nasm -fbin third_lab.asm -o boot.bin
dd if=/dev/zero of=boot.img bs=1024 count=1440
dd if=boot.bin of=boot.img conv=notrunc
dd if=kernel.bin of=boot.img conv=notrunc seek=1
bochs -f os.bxrc -q
