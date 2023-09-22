[BITS 16]

cli
mov ax, 0x7C0              ; Correct data segment
mov ds, ax
sti

xor ax, ax                 ; Clear ax register
xor bx, bx                 ; Clear bx register


print_loop_start:
  mov al, [data + bx]      ; Get next ASCII symbol
  cmp al, 0x0              ; Check if al is 0
  jz loop_                 ; if so ends program
  mov ah, 0xE              ; Move 0xE in ah (to print char)
  int 0x10                 ; Call printing
  inc bx                   ; Increment bx
  jmp print_loop_start     ; Continue the loop


loop_:
  jmp loop_                ; Infinite loop


data:
  db 'Hello world!', 0x0   ; Line we want to print

times 510-($-$$) db 0

dw 0xAA55

