#!/bin/bash

if ! (nasm -felf source/internal_commands.asm -o internal_commands.o) ; then echo "internal_commands.asm error"; exit 1; fi
if ! (nasm -felf source/seven.asm -o seven_asm.o) ; then echo "seven.asm error"; exit 1; fi

if ! (gcc -m32 -ffreestanding -c -o fifth_lab.o source/fifth_lab.c) ; then echo "fifth_lab.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o seven.o source/seven.c) ; then echo "seven.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o memory.o source/printSource/memory.c) ; then echo "memory.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o print_functions.o source/printSource/print_functions.c) then echo "print_functions.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o linear_alloc.o source/allocator/linear_alloc.c) ; then echo "linear_alloc.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o six_lab.o source/configureController/six_lab.c) ; then echo "six_lab.c error"; exit 1; fi
if ! (gcc -m32 -ffreestanding -c -o kernel_entry.o source/kernel_entry.c) ; then echo "kernel_entry.c error"; exit 1; fi

ld -m i386pe -o kernel.tmp -Ttext 0x20200 kernel_entry.o print_functions.o fifth_lab.o six_lab.o seven.o linear_alloc.o memory.o seven_asm.o internal_commands.o

objcopy -I pe-i386 -O binary kernel.tmp kernel.bin

nasm -fbin source/load_kernel.asm -o boot.bin

dd if=/dev/zero of=boot.img bs=1024 count=1440
dd if=boot.bin of=boot.img conv=notrunc
dd if=kernel.bin of=boot.img conv=notrunc seek=1

bochs -f os.bxrc -q
# bochsdbg -f os-dbg.bxrc -q

rm internal_commands.o
rm seven_asm.o
rm seven.o
rm fifth_lab.o
rm six_lab.o
rm kernel_entry.o
rm linear_alloc.o
rm memory.o
rm print_functions.o
rm kernel.tmp
rm kernel.bin
rm boot.bin
rm boot.img
