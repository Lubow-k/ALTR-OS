[BITS 32]

[GLOBAL _INT]
[GLOBAL _CLI]
[GLOBAL _STI]

_INT:
    int 0x22
    ret

_CLI:
    cli
    ret

_STI:
    sti
    ret