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
void create_contexts();

void inf_print();


void __main() {

    init_printer();
    fill_tramplins();

    configure_master_controller();
    configure_slave_controller();

    init();
    create_contexts();

    enable(TIMER);
    STI();

    for(;;);
}


    // INT();
    // print_app("%d\n", 20200);
    // print_app("%d %x NONE", 30, 0x20);
    // panel_printing_scroll();
    // endless_panel_printing();
    // panel_printing_collisions();