[BITS 32]

[GLOBAL _timer_interrupt]

[GLOBAL _tramplin_0x0]
[GLOBAL _tramplin_0x1]
[GLOBAL _tramplin_0x2]
[GLOBAL _tramplin_0x3]
[GLOBAL _tramplin_0x4]
[GLOBAL _tramplin_0x5]
[GLOBAL _tramplin_0x6]
[GLOBAL _tramplin_0x7]
[GLOBAL _tramplin_0x8]
[GLOBAL _tramplin_0x9]
[GLOBAL _tramplin_0xa]
[GLOBAL _tramplin_0xb]
[GLOBAL _tramplin_0xc]
[GLOBAL _tramplin_0xd]
[GLOBAL _tramplin_0xe]
[GLOBAL _tramplin_0xf]
[GLOBAL _tramplin_0x10]
[GLOBAL _tramplin_0x11]
[GLOBAL _tramplin_0x12]
[GLOBAL _tramplin_0x13]
[GLOBAL _tramplin_0x14]
[GLOBAL _tramplin_0x15]
[GLOBAL _tramplin_0x16]
[GLOBAL _tramplin_0x17]
[GLOBAL _tramplin_0x18]
[GLOBAL _tramplin_0x19]
[GLOBAL _tramplin_0x1a]
[GLOBAL _tramplin_0x1b]
[GLOBAL _tramplin_0x1c]
[GLOBAL _tramplin_0x1d]
[GLOBAL _tramplin_0x1e]
[GLOBAL _tramplin_0x1f]

_timer_interrupt:
    mov dx, 0x20
    mov al, 0x20
    out dx, al
    popa
    pop gs
    pop fs
    pop es
    pop ds
    add sp, 8
    IRETD

    

_tramplin_0x1:
    push 0xDEAD
    push 0x1
    jmp collect_context

_tramplin_0x2:
    push 0xDEAD
    push 0x2
    jmp collect_context

_tramplin_0x3:
    push 0xDEAD
    push 0x3
    jmp collect_context

_tramplin_0x4:
    push 0xDEAD
    push 0x4
    jmp collect_context

_tramplin_0x5:
    push 0xDEAD
    push 0x5
    jmp collect_context

_tramplin_0x6:
    push 0xDEAD
    push 0x6
    jmp collect_context

_tramplin_0x7:
    push 0xDEAD
    push 0x7
    jmp collect_context

_tramplin_0x8:
    push 0x8
    jmp collect_context

_tramplin_0x9:
    push 0xDEAD
    push 0x9
    jmp collect_context

_tramplin_0xa:
    push 0xa
    jmp collect_context

_tramplin_0xb:
    push 0xb
    jmp collect_context

_tramplin_0xc:
    push 0xc
    jmp collect_context

_tramplin_0xd:
    push 0xd
    jmp collect_context

_tramplin_0xe:
    push 0xe
    jmp collect_context

_tramplin_0xf:
    push 0xDEAD
    push 0xf
    jmp collect_context

_tramplin_0x10:
    push 0xDEAD
    push 0x10
    jmp collect_context

_tramplin_0x11:
    push 0x11
    jmp collect_context

_tramplin_0x12:
    push 0xDEAD
    push 0x12
    jmp collect_context

_tramplin_0x13:
    push 0xDEAD
    push 0x13
    jmp collect_context

_tramplin_0x14:
    push 0xDEAD
    push 0x14
    jmp collect_context

_tramplin_0x15:
    push 0x15
    jmp collect_context

_tramplin_0x16:
    push 0xDEAD
    push 0x16
    jmp collect_context

_tramplin_0x17:
    push 0xDEAD
    push 0x17
    jmp collect_context

_tramplin_0x18:
    push 0xDEAD
    push 0x18
    jmp collect_context

_tramplin_0x19:
    push 0xDEAD
    push 0x19
    jmp collect_context

_tramplin_0x1a:
    push 0xDEAD
    push 0x1a
    jmp collect_context

_tramplin_0x1b:
    push 0xDEAD
    push 0x1b
    jmp collect_context

_tramplin_0x1c:
    push 0xDEAD
    push 0x1c
    jmp collect_context

_tramplin_0x1d:
    push 0x1d
    jmp collect_context

_tramplin_0x1e:
    push 0x1e
    jmp collect_context

_tramplin_0x1f:
    push 0xDEAD
    push 0x1f
    jmp collect_context

collect_context:
    push ds
    push es
    push fs
    push gs
    pusha
    ret
