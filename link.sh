#!/usr/bin/bash

nasm -fbin $1 -o out.bin  #$1 arg - name_file.asm

dd if=/dev/zero of=out.img bs=1024 count=1440
dd if=out.bin of=out.img conv=notrunc
dd if=test.bin of=out.img conv=notrunc seek=1

if [ $2 = "-d" ]   #$2 arg - optional -d (for debug)
then
    bochsdbg -f os-dbg.bxrc -q
else
    bochs -f os.bxrc -q
fi

#out.bin
#rm out.img
