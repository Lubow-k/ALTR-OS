[BITS 32]

[GLOBAL _tramplin_0]
[GLOBAL _tramplin_1]
[GLOBAL _tramplin_2]
[GLOBAL _tramplin_3]
[GLOBAL _tramplin_4]
[GLOBAL _tramplin_5]
[GLOBAL _tramplin_6]
[GLOBAL _tramplin_7]
[GLOBAL _tramplin_8]
[GLOBAL _tramplin_9]
[GLOBAL _tramplin_A]
[GLOBAL _tramplin_B]
[GLOBAL _tramplin_C]
[GLOBAL _tramplin_D]
[GLOBAL _tramplin_E]
[GLOBAL _tramplin_F]
[GLOBAL _tramplin_10]
[GLOBAL _tramplin_11]
[GLOBAL _tramplin_12]
[GLOBAL _tramplin_13]
[GLOBAL _tramplin_14]
[GLOBAL _tramplin_15]
[GLOBAL _tramplin_16]
[GLOBAL _tramplin_17]
[GLOBAL _tramplin_18]
[GLOBAL _tramplin_19]
[GLOBAL _tramplin_1A]
[GLOBAL _tramplin_1B]
[GLOBAL _tramplin_1C]
[GLOBAL _tramplin_1D]
[GLOBAL _tramplin_1E]
[GLOBAL _tramplin_1F]
[GLOBAL _tramplin_20]
[GLOBAL _recovery_ctx]

[EXTERN _interrupt_handler]

_recovery_ctx:     ;timer
    ; mov dx, 0x20
    ; mov al, 0x20
    ; out dx, al
    popa
    ; add esp, 4
    pop gs
    pop fs
    pop es
    pop ds
    add esp, 8
    IRETD

    
_tramplin_0:
    push 0xDEAD
    push 0x0
    jmp collect_context

_tramplin_1:
    push 0xDEAD
    push 0x1
    jmp collect_context

_tramplin_2:
    push 0xDEAD
    push 0x2
    jmp collect_context

_tramplin_3:
    push 0xDEAD
    push 0x3
    jmp collect_context

_tramplin_4:
    push 0xDEAD
    push 0x4
    jmp collect_context

_tramplin_5:
    push 0xDEAD
    push 0x5
    jmp collect_context

_tramplin_6:
    push 0xDEAD
    push 0x6
    jmp collect_context

_tramplin_7:
    push 0xDEAD
    push 0x7
    jmp collect_context

_tramplin_8:
    push 0x8
    jmp collect_context

_tramplin_9:
    push 0xDEAD
    push 0x9
    jmp collect_context

_tramplin_A:
    push 0xa
    jmp collect_context

_tramplin_B:
    push 0xb
    jmp collect_context

_tramplin_C:
    push 0xc
    jmp collect_context

_tramplin_D:
    push 0xd
    jmp collect_context

_tramplin_E:
    push 0xe
    jmp collect_context

_tramplin_F:
    push 0xDEAD
    push 0xf
    jmp collect_context

_tramplin_10:
    push 0xDEAD
    push 0x10
    jmp collect_context

_tramplin_11:
    push 0x11
    jmp collect_context

_tramplin_12:
    push 0xDEAD
    push 0x12
    jmp collect_context

_tramplin_13:
    push 0xDEAD
    push 0x13
    jmp collect_context

_tramplin_14:
    push 0xDEAD
    push 0x14
    jmp collect_context

_tramplin_15:
    push 0x15
    jmp collect_context

_tramplin_16:
    push 0xDEAD
    push 0x16
    jmp collect_context

_tramplin_17:
    push 0xDEAD
    push 0x17
    jmp collect_context

_tramplin_18:
    push 0xDEAD
    push 0x18
    jmp collect_context

_tramplin_19:
    push 0xDEAD
    push 0x19
    jmp collect_context

_tramplin_1A:
    push 0xDEAD
    push 0x1a
    jmp collect_context

_tramplin_1B:
    push 0xDEAD
    push 0x1b
    jmp collect_context

_tramplin_1C:
    push 0xDEAD
    push 0x1c
    jmp collect_context

_tramplin_1D:
    push 0x1d
    jmp collect_context

_tramplin_1E:
    push 0x1e
    jmp collect_context

_tramplin_1F:
    push 0xDEAD
    push 0x1f
    jmp collect_context

_tramplin_20:
    push 0xDEAD
    push 0x20
    jmp collect_context

collect_context:
    push ds
    push es
    push fs
    push gs
    pusha
    call _interrupt_handler
    
