[BITS 32]
tramplin_0x0
    push 0xDEAD
    push 0x0
    jmp collect_context

tramplin_0x1
    push 0xDEAD
    push 0x1
    jmp collect_context

tramplin_0x2
    push 0xDEAD
    push 0x2
    jmp collect_context

tramplin_0x3
    push 0xDEAD
    push 0x3
    jmp collect_context

tramplin_0x4
    push 0xDEAD
    push 0x4
    jmp collect_context

tramplin_0x5
    push 0xDEAD
    push 0x5
    jmp collect_context

tramplin_0x6
    push 0xDEAD
    push 0x6
    jmp collect_context

tramplin_0x7
    push 0xDEAD
    push 0x7
    jmp collect_context

tramplin_0x8
    push 0x8
    jmp collect_context

tramplin_0x9
    push 0xDEAD
    push 0x9
    jmp collect_context

tramplin_0xa
    push 0xa
    jmp collect_context

tramplin_0xb
    push 0xb
    jmp collect_context

tramplin_0xc
    push 0xc
    jmp collect_context

tramplin_0xd
    push 0xd
    jmp collect_context

tramplin_0xe
    push 0xe
    jmp collect_context

tramplin_0xf
    push 0xDEAD
    push 0xf
    jmp collect_context

tramplin_0x10
    push 0xDEAD
    push 0x10
    jmp collect_context

tramplin_0x11
    push 0x11
    jmp collect_context

tramplin_0x12
    push 0xDEAD
    push 0x12
    jmp collect_context

tramplin_0x13
    push 0xDEAD
    push 0x13
    jmp collect_context

tramplin_0x14
    push 0xDEAD
    push 0x14
    jmp collect_context

tramplin_0x15
    push 0x15
    jmp collect_context

tramplin_0x16
    push 0xDEAD
    push 0x16
    jmp collect_context

tramplin_0x17
    push 0xDEAD
    push 0x17
    jmp collect_context

tramplin_0x18
    push 0xDEAD
    push 0x18
    jmp collect_context

tramplin_0x19
    push 0xDEAD
    push 0x19
    jmp collect_context

tramplin_0x1a
    push 0xDEAD
    push 0x1a
    jmp collect_context

tramplin_0x1b
    push 0xDEAD
    push 0x1b
    jmp collect_context

tramplin_0x1c
    push 0xDEAD
    push 0x1c
    jmp collect_context

tramplin_0x1d
    push 0x1d
    jmp collect_context

tramplin_0x1e
    push 0x1e
    jmp collect_context

tramplin_0x1f
    push 0xDEAD
    push 0x1f
    jmp collect_context

collect_context:
    push ds
    push es
    push fs
    push gs
    pusha
