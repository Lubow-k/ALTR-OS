[BITS 32]

[GLOBAL _INT]
[GLOBAL _LIDT]

_INT:
    int 0x0
    ret

_LIDT:
    lidt [ESP + 8] 
    ret