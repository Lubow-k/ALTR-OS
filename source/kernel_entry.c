#include "configureController/six_lab.h"
#include "printSource/print_functions.h"
#include "allocator/linear_alloc.h"
#include "nine.h"
#include "experiments.h"
#include "seven.h"

typedef unsigned int u32;

void fill_tramplins();
void STI();
void INT(int i);
void experiment();

void endless_panel_printing();
void panel_printing_collisions();
void panel_printing_scroll();
void print_app(char* fmt, ...);

void inf_print();


void __main() {

    init_printer();
    fill_tramplins();

    configure_master_controller();
    configure_slave_controller();

    enable(TIMER);

    init();

    context* esp0 = (context*) kernel_malloc(20 * 1024);
    context* esp1 = (context*) kernel_malloc(20 * 1024);
    context* esp2 = (context*) kernel_malloc(20 * 1024);
    context* esp3 = (context*) kernel_malloc(20 * 1024);

    context ctx;
    ctx.esp = esp0;
    ctx.eip = inf_print;
    esp0[0] = ctx;

    ctx.esp = esp1;
    ctx.eip = inf_print;
    esp1[0] = ctx;

    ctx.esp = esp2;
    ctx.eip = inf_print;
    esp2[0] = ctx;

    ctx.esp = esp3;
    ctx.eip = inf_print;
    esp3[0] = ctx;

    STI();
    
    // INT();
    // print_app("%d\n", 20200);
    // print_app("%d %x NONE", 30, 0x20);
    // panel_printing_scroll();
    // endless_panel_printing();
    // panel_printing_collisions();

    for(;;);
}

void inf_print() {
    int i = 0;
    INT(0xd);
    for (;;){
        print_app("%d ", i++);
    }
}