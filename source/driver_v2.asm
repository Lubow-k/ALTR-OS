[BITS 16]

cli
xor ax, ax        ; |
mov ss, ax        ; |
mov sp, 0x7C00    ; |Correct stack segment

mov ax, 0x7C0
mov ds, ax        ; Correct data segment

mov ax, 0x2000    ; Correct extended segment
mov es, ax

mov ch, 0         ; Cylinder number
mov cl, 1         ; Starting sector number
xor dh, dh        ; Set head
xor bx, bx        ; Clear bx register

main:
    read_loop:

        inc bx               ; Increment counter
        push bx              ; Push counter on stack
        xor bx, bx           ; Clear bx
        push bx              ; Send 0 to stack (for 3 loop)

    read_int:
        mov ah, 2            ; Read sectors from drive
        mov al, 1            ; Number of sectors to read
        int 0x13
        jc error_message          ; Test if read successfully
        pop bx                    ; get sub counter from stack (to open access to global counter)


        mov bx, es
        add bx, 0x20              ; Add to bx 512 (1 sectors)
        mov es, bx                ; Move es
        xor bx, bx                ; Clear bx

        inc cl                    ; Increment sector number
        cmp cl, 0x13              ; Check if we on 19th sector
        jz check_increment_head   ; Then need to increment more
        jmp check_if_end          ; Continue reading

    check_increment_head:
        mov cl, 0x1           ; Set sectors to 1
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
        cmp bx, 0x300         ; Check if we read 768 sectors
        jz count_sum          ; Exit loop
        jmp read_loop         ; Repeat

error_message:
    pop bx                    ; Get local counter from stack
    inc bx                    ; Increment the bad tries to read from disk
    cmp bx, 0x4               ; | If we tried more than 3 times -> finish
    jz end                    ; |
    push bx                   ; Push local counter on stack
    xor bx, bx                ; Clean bx for [es:bx]
    jmp read_int              ; Try to read from disk one more time

count_sum:
    mov ax, 0x2000
    mov es, ax

    xor ax, ax                ; Initiate sum
    xor bx, bx                ; Initiate counter under 16

    sum_loop:
        add al, byte [es:bx]
        inc bx
        cmp bx, 0x10          ; Check if 16
        jz move_es            ; increment es
        jmp sum_loop          ; Repeat
        move_es:
            mov bx, es        ; Get es
            inc bx            ; Increment es
            cmp bx, 0x8000    ; Check if that's all
            jz end
            mov es, bx
            xor bx, bx        ; Get null to counter
            jmp sum_loop      ; Repeat

end:
    loop:
        jmp loop

    times 510-($-$$) db 0
    dw 0xAA55