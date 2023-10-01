[BITS 16]

; TODO read first sector!!!
; dl is ready
; TODO move buffer? 

cli
xor ax, ax                 ; Clear ax
mov ss, ax                 ; Correct stack segment
mov sp, 0x7c00             ; Correct sp

mov ax, 0x7D77             ; Correct extended segment
mov es, ax

mov ah, 2         ; Read sectors from drive
mov al, 17        ; Number of sectors to read -----> 18
mov ch, 0         ; Cylinder number
mov cl, 2         ; Starting sector number

mov bx, 0x2000    ; Push 0x2000 to ds
mov ds, bx

xor bx, bx        ; Clear bx to read in es:bx

xor dx, dx        ; Select head number
sti

push 0x2200       ; Push start counter for memory copy

read_loop:
    int 0x13      ; Syscall to write
    ; TODO: check if int do anything

move_memory:
        pop bx    ; Get counter from stack
        push ax   ; Save ax to stack
        push bx   ; Save value on stack

move_memory_cycle:
                mov ax, [es:bx]           ; Get data from buffer
                mov [ds:bx], ax           ; Move data to destination
                dec bx                    ; Counter--
                cmp bx, 0                 ; Check if counter == zero
                jz end_move_memory_cycle  ; If zero end cycle
                jmp move_memory_cycle     ; Else repeat

end_move_memory_cycle:
        pop bx         ; Get value of counter
        shr bx, 4      ; Move bx right by 4 bits to get new ds

        mov ax, ds    ; |
        add ax, bx    ; | Add to ds counter
        mov ds, ax    ; |

        pop ax        ; Get value of ax back

        push 0x2400
        xor bx, bx

    mov al, 18        ; Except first read
    mov cl, 1         ; Read from first sector except first read

    cmp dh, 0         ; Check if dh == 0
    jz inc_dh_zero    ; If zero increment
    jmp dec_dh_one    ; If one decrement
inc_dh_zero:
        inc dh        ; Increment head number
        jmp dh_end
dec_dh_one:
        dec dh        ; Decrement head number
        inc ch        ; If dh == 1 then increment ch also (Цилиндр)
dh_end:
    cmp ch, 20        ; Check if we done 20 reads
    jz end            ; Exit loop
    jmp read_loop     ; Repeat


end:


    

times 510-($-$$) db 0
dw 0xAA55
