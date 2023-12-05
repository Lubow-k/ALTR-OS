[BITS 32]

[GLOBAL _INT]
[GLOBAL _CLI]
[GLOBAL _STI]
[GLOBAL _inb]
[GLOBAL _outb]

_INT:
    int 0x20
    ret

_CLI:
    cli
    ret

_STI:
    sti
    ret

_inb:
    mov dx, [esp + 4] ; ??
    in al, dx
    ret

_outb:
    mov dx, [esp + 4]
    mov al, [esp + 8]
    out dx, al
    ret