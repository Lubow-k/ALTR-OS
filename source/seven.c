#include "printSource/print_functions.h"
#include "seven.h"
#include "nine.h"
#include "allocator/linear_alloc.h"

typedef unsigned char byte;
typedef unsigned short int u16;
typedef unsigned int u32;
#define STACK_SIZE 1024 * 20

void printer_handler();
void recovery_ctx();
void CLI();
void STI();
void print_app(char* fmt, ...);
void print_panel(int panel_num, char* fmt, int* args);
static context* init_context(u32 func);


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

static void inf_print_0() {
    int i = 0;
    for (;;){
        print_app("%d ", i++);
    }
}

static void inf_print_1() {
    for (;;){
        print_app("ALTR OS\n");
    }
}

static void inf_print_2() {
    for (;;){
        print_app("()");
    }
}

static void inf_print_3() {
    for (;;){
        print_app("-x");
    }
}  

static context* init_context(u32 func) {
    u32* esp_ptr = (u32*) kernel_malloc(STACK_SIZE);
    context* ctx = (context*) (esp_ptr + STACK_SIZE - sizeof(context)); 
    ctx->esp = (u32) ctx;
    ctx->eax = 0;
    ctx->ebx = 0;
    ctx->ecx = 0;
    ctx->edx = 0;
    ctx->esi = 0;
    ctx->edi = 0;
    ctx->ebp = 0;
    ctx->vector = 0;
    ctx->error_code = 0xDEAD;
    ctx->eip = func;
    ctx->eflags = 0;
    ctx->cs = 0x8;
    ctx->es = 0x10;
    ctx->ds = 0x10;
    ctx->fs = 0x10;
    ctx->gs = 0x10;
    return ctx;
}

context* process_pointers[4];
int index = -1;

void create_contexts() {
    process_pointers[0] = init_context((u32) inf_print_0);
    process_pointers[1] = init_context((u32) inf_print_1);
    process_pointers[2] = init_context((u32) inf_print_2);
    process_pointers[3] = init_context((u32) inf_print_3);
}

void timer_handler(context** ctx) {
    if (index != -1) {
        process_pointers[index] = *ctx;
    }
    index = (index + 1) % 4;
    *ctx = process_pointers[index];
    return;
}

void printer_handler(context* ctx) {
    print_panel(index, *(char**) ctx->eax, (int*) ctx->eax + 1);
    STI();
}


void interrupt_handler(context* ctx){
    switch (ctx->vector) {
    case 0x20:
        timer_handler(&ctx);  
        break;
    case 0xFF:
        printer_handler(ctx);
        break;
    default:
        panic(ctx);
        break;
    }
}
