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
        inc bx               ; Increment counter
        push bx              ; Push counter on stack
        xor bx, bx           ; Clear bx

    read_int:
        mov ah, 2         ; Read sectors from drive
        mov al, 1         ; Number of sectors to read
        int 0x13
        jc read_int          ; Test if read sucsess
        
; TODO check for errors

        mov bx, es
        add bx, 0x20          ; Add to bx 512 (1 sectors)
        mov es, bx            ; Move es
        xor bx, bx            ; Clear bx

        inc cl                ; Increment sector number

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
    mov ax, 0x2000
    mov es, ax

    xor ax, ax                ; Initiate sum
    xor bx, bx                ; Initiate counter under 16

    sum_loop:
        add al, byte [es:bx]  ; May be error
        inc bx
        cmp bx, 0x10          ; Check if 16
        jz move_es            ; increment es
        jmp sum_loop          ; Repeat
        move_es:
            mov bx, es        ; Get es
            inc bx            ; Increment es
            cmp bx, 0x8000    ; Check if thats all
            jz end_end
            mov es, bx
            xor bx, bx        ; Get null to counter
            jmp sum_loop      ; Repeat

end_end:     
    loop:
        jmp loop

    times 510-($-$$) db 0
    dw 0xAA55