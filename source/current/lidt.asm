[BITS 32]

[GLOBAL _LIDT]

_LIDT:
    lidt [EBP + 8]
    ret