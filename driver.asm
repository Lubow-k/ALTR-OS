[BITS 16]



cli
mov ax, 0x2000    ; Correct stack segment
mov ss, ax

mov ax, 0x7D77    ; Correct extendet segment
mov es, ax
sti

mov ah, 2         ; Read sectors from drive
mov al, 17        ; Number of sectors to read ----- 18
mov ch, 0         ; Cylinder number 
mov cl, 2         ; Starting sector number
xor bx, bx        ; Clear bx to read in es:bx

mov dh, 0x2200    ; First time we read 17 segments so first counter
                  ; must be lesser than 0x2400
push dh
xor dh, dh        ; Select head number

read_loop:
    int 0x13      ; Syscall to write

    mov ah,
move_memmory:
        pop bx    ; Get counter
        push ax   ; Save ax

move_memmory_loop:
        mov ax, [es + bx] ; Move memory to ax from es + bx
        mov ax, 

    mov al, 18    ; Except first read
    mov cl, 1     ; Read from first sector except first read

    cmp dh, 0     ; Check if dh == 0
    jz inc_dh_zero; If zero increment
    jmp dec_dh_one; If one decrement
inc_dh_zero:
        inc dh    ; Increment head number
        jmp dh_end
dec_dh_one:
        dec dh    ; Decrement head number
        inc ch    ; If dh == 1 then increment ch also
dh_end:
    cmp ch, 12   ; Check if we done 13 reads
    jz end       ; Exit loop
    jmp read_loop; Repeat



;0x07D770     ;start buffer

end:

times 510-($-$$) db 0

dw 0xAA55