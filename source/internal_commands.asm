[BITS 32]

[GLOBAL _INT]
[GLOBAL _LIDT]

_INT:
    int 1
    ret

_LIDT:
    lidt [EBP + 8] 
    ret