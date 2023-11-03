#!/bin/bash

if ! (gcc -m32 -ffreestanding -c -o memory.o source/printSource/memory.c) ; then echo "memory.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o print_functions.o source/printSource/print_functions.c) then echo "print_functions.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o kernel.o source/printSource/kernel.c) then echo "kernel.c error"; exit 1; fi

ld -m i386pe -o kernel.tmp -Ttext 0x20200  kernel.o print_functions.o memory.o
objcopy -I pe-i386 -O binary kernel.tmp kernel.bin

nasm -fbin source/third_lab.asm -o boot.bin
dd if=/dev/zero of=boot.img bs=1024 count=1440
dd if=boot.bin of=boot.img conv=notrunc
dd if=kernel.bin of=boot.img conv=notrunc seek=1
bochs -f os.bxrc -q
# bochsdbg -f os-dbg.bxrc -q
