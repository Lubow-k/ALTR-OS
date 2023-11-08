#!/bin/bash

if ! (nasm -felf source/internal_commands.asm -o internal_commands.o) ; then echo "internal_commands.asm error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o fifth_lab.o source/fifth_lab.c) ; then echo "fifth_lab.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o memory.o source/printSource/memory.c) ; then echo "memory.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o print_functions.o source/printSource/print_functions.c) then echo "print_functions.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o linear_alloc.o source/linear_alloc.c) ; then echo "linear_alloc.c error"; exit 1; fi


ld -m i386pe -o kernel.tmp -Ttext 0x20200 fifth_lab.o print_functions.o linear_alloc.o memory.o internal_commands.o

objcopy -I pe-i386 -O binary kernel.tmp kernel.bin

nasm -fbin source/load_kernel.asm -o boot.bin

dd if=/dev/zero of=boot.img bs=1024 count=1440
dd if=boot.bin of=boot.img conv=notrunc
dd if=kernel.bin of=boot.img conv=notrunc seek=1

bochs -f os.bxrc -q
# bochsdbg -f os-dbg.bxrc -q

rm internal_commands.o
rm fifth_lab.o
rm linear_alloc.o
rm memory.o
rm print_functions.o
rm kernel.tmp
rm kernel.bin
rm boot.bin
rm boot.img
