[BITS 16]

cli
xor ax, ax                       ; |
mov ss, ax                       ; |
mov sp, 0x7C00                   ; |Correct stack segment

xor ch, ch                       ; Cylinder number
mov cl, 1                        ; Starting sector number
xor dh, dh                       ; Set head 0
xor bx, bx                       ; Clear bx register --> Always 0 for int
mov di, 0x2000                   ; Clear global counter

main:
    read_loop:
        xor si, si               ; Clear counter for error loop
        mov es, di               ; Move es

    read_int:
        mov ah, 2                ; Read sectors from drive
        mov al, 1                ; Number of sectors to read
        int 0x13
        jc error_message         ; Test if read successfully

        add di, 0x20             ; Add 200 (move 200 after reading one sector)

        inc cl                   ; Increment sector number
        cmp cl, 0x13             ; Check if we on 19th sector
        jne check_if_end         ; Then need to increment more

        mov cl, 0x1              ; Set sectors to 1
        inc dh                   ; | Increment head
        cmp dh, 0x2              ; If head became 2 --> we done 1 cylinder + reset head
        jne check_if_end         ; If not check if we finished
        xor dh, dh
        inc ch                   ; Increment cylinder number

    check_if_end:
        cmp di, 0x8000           ; Check if we read 768 sectors -->0x0
        je main_gdt              ; Exit loop
        jmp read_loop            ; Repeat

error_message:
    inc si                       ; Increment the bad tries to read from disk
    cmp si, 0x4                  ; | If we tried more than 3 times -> finish
    je main_gdt               
    jmp read_int                 ; Try to read from disk one more time


gdt_start:
    dq 0x0
  gdt_code:
    dw 0xFFFF
    dw 0x0
    dw 0x9A00
    dw 0xCF
  gdt_data:                                   
    dw 0xFFFF
    dw 0x0
    dw 0x9200
    dw 0xCF
gdt_end:

gdt_descriptor:
  dw gdt_end - gdt_start - 1
  dd gdt_start + 0x20000


main_gdt:
  lgdt [gdt_descriptor + 0x7c00]
  mov ecx, cr0
  or ecx, 0x1
  mov cr0, ecx 
  CODE_SEG equ gdt_code - gdt_start
  DATA_SEG equ gdt_data - gdt_start
  jmp CODE_SEG:protected_mode_tramplin + 0x7C00   ; Far jump


[BITS 32]
protected_mode_tramplin:
    mov eax, DATA_SEG
    mov ds, eax                            ; |
    mov ss, eax                            ; |
    mov es, eax                            ; | setup data segment registers
    mov fs, eax                            ; |
    mov gs, eax                            ; |  
    mov esp, 0x20000                       ;   setup stack
    jmp CODE_SEG:0x20200


times 510-($-$$) db 0
dw 0xAA55
