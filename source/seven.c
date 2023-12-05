#include "printSource/print_functions.h"

typedef unsigned char byte;
typedef unsigned short int u16;
typedef unsigned int u32;

void recovery_ctx();
void CLI();

#pragma pack(push, 1)
typedef struct {
    u32 edi;
    u32 esi;
    u32 ebp;
    u32 esp;
    u32 ebx;
    u32 edx;
    u32 ecx;
    u32 eax;
    u16 gs;
    u16 padding_1;
    u16 fs;
    u16 padding_2;
    u16 es;
    u16 padding_3;
    u16 ds;
    u16 padding_4;
    u32 vector;
    u32 error_code;
    u32 eip;
    u16 cs;
    u16 padding_5;
    u32 eflags;
    u32 edp;
    u16 ss;
    u16 padding_6;
} context;
#pragma pack(pop)


void print_context(context* ctx){
    print("uhandled interrupt %x, intrrupted process context: \n", ctx->vector);
    print("EAX = %x ECX = %x EDX = %x EBX = %x\n", ctx->eax, ctx->ecx, ctx->edx, ctx->ebx);
    print("ESP = %x EBP = %x ESI = %x EDI = %x\n", ctx->esp, ctx->ebp, ctx->esi, ctx->edi);
    print("DS = %x ES = %x FS = %x GS = %x\n", ctx->ds, ctx->es, ctx->fs, ctx->gs);
    print("CS = %x SS = %x EIP = %x\n", ctx->cs, ctx->ss, ctx->eip);
    print("EFLAGS = %x\n", ctx->eflags);
    print("error code = %x", ctx->error_code);
}

void panic(context* ctx) {
    CLI();
    print("PANIC!\n");
    print_context(ctx);
    for (;;);
}

int i;

void timer_handler(context* ctx) {
    print("%d ", i++);
    return;
}

void interrupt_handler(context ctx){
    switch (ctx.vector) {
    case 0x20:
        timer_handler(&ctx); 
        break;
        
    default:
        panic(&ctx);
        break;
    }
}
