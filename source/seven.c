#include "printSource/print_functions.h"
#include "seven.h"
#include "nine.h"

typedef unsigned char byte;
typedef unsigned short int u16;
typedef unsigned int u32;

void printer_handler();
void recovery_ctx();
void CLI();
void change_esp(int i);
void print_app(char* fmt, ...);


void print_context(context* ctx){
    print("uhandled interrupt %x, intrrupted process context: \n", ctx->vector);
    print("EAX = %x ECX = %x EDX = %x EBX = %x\n", ctx->eax, ctx->ecx, ctx->edx, ctx->ebx);
    print("ESP = %x EBP = %x ESI = %x EDI = %x\n", ctx->esp, ctx->ebp, ctx->esi, ctx->edi);
    print("DS = %x ES = %x FS = %x GS = %x\n", ctx->ds, ctx->es, ctx->fs, ctx->gs);
    print("CS = %x EIP = %x\n", ctx->cs, ctx->eip);
    print("EFLAGS = %x\n", ctx->eflags);
    print("error code = %x", ctx->error_code);
}

void panic(context* ctx) {
    CLI();
    init_printer();
    print("PANIC!\n");
    print_context(ctx);
    for (;;);
}

static u32 stack_pointers[4];
int index;


void timer_handler(context* ctx) {
    stack_pointers[index] = ctx->esp;
    index = (index + 1) % 4;
    print_app("Changing esp %d", index);
    change_esp(stack_pointers[index]);
}

void interrupt_handler(context* ctx){
    switch (ctx->vector) {
    case 0x20:
        timer_handler(ctx); 
        break;
    case 0xFF:
        print_panel(0, "In interrupt handler\n", (int*) 0);
        printer_handler(ctx);
        break;
    default:
        panic(ctx);
        break;
    }
}
