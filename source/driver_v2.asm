[BITS 16]

cli
xor ax, ax        ; |
mov ss, ax        ; |
mov sp, 0x7C00    ; |Correct stack segment

mov ax, 0x7C0
mov ds, ax        ; Correct data segment

mov ax, 0x2000    ; Correct extended segment
mov es, ax

mov ah, 2         ; Read sectors from drive
mov al, 1         ; Number of sectors to read
mov ch, 0         ; Cylinder number
mov cl, 1         ; Starting sector number
xor dh, dh        ; Set head
xor bx, bx        ; Clear bx register

main:
    read_loop:
; Move after check errors
        add bx, 0x1          ; Increment counter
        push bx              ; Push counter on stack
        xor bx, bx           ; Clear bx

    read_int:
        mov ah, 0x2         ; Read sectors from drive
        mov al, 0x1         ; Number of sectors to read

        test bx, bx
        int 0x13

        jc endless_loop          ; Test if read sucsess
        
; TODO check for errors

        mov bx, es
        add bx, 0x20          ; Add to bx 512 (1 sectors)
        mov es, bx            ; Move es
        xor bx, bx            ; Clear bx

        add cl, 0x1           ; Increment sector number

        test bx, bx           ; Clear flags
        cmp cl, 0x13          ; Check if we on 19th sector
        jz check_increment_head; Then need to increment more
        jmp check_if_end      ; Continue reading

    check_increment_head:
        mov cl, 0x1           ; Set sectors to 1

        test bx, bx           ; Clear flags
        cmp dh, 0             ; Check if head is 0
        jz increment_head     ; If zero increment
        jmp decrement_head    ; If one decrement

    increment_head:
            inc dh            ; Increment head number
            jmp check_if_end

    decrement_head:
            dec dh            ; Decrement head number
            inc ch            ; then increment cylinder number

    check_if_end:
        pop bx                ; Get counter

        test bx, bx           ; Clear flags
        cmp bx, 0x300         ; Check if we read 768 sectors
        jz end                ; Exit loop
        jmp read_loop         ; Repeat

end:
end_end:
    endless_loop:
        jmp endless_loop
    times 510-($-$$) db 0
    dw 0xAA55
