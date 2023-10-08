[BITS 16]

gdt_start:
    dq 0x0
  gdt_code:
    db ...
  gdt_data:
    db ...
gbt_end:

lbdt [gdt_descriptor]

gdt_descriptor:
  dw gdt_end - gdt_start - 1
  dd gdt_start + 0x20000

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

jmp CODE_SEG:protected_mode_tramplin + 0x7C00
[BITS 32]
protected_mode_tramplin:
    mov ds, DATA_SEG                            ; |
    mov ss, DATA_SEG                            ; |
    mov es, DATA_SEG                            ; | setup data segment registers
    mov fs, DATA_SEG                            ; |
    mov gs, DATA_SEG                            ; |  
    mov esp, 0x20000                            ;   setup stack
    jmp CODE_SEG:0x20200



