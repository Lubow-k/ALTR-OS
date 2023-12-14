#include "configureController/six_lab.h"
#include "printSource/print_functions.h"
#include "nine.h"
#include "experiments.h"

void fill_tramplins();
void STI();
void INT();
void experiment();

void endless_panel_printing();
void panel_printing_collisions();
void panel_printing_scroll();

void __main() {

    init_printer();
    fill_tramplins();  
    
    configure_master_controller();
    configure_slave_controller();  

    init();
    // panel_printing_scroll();
    endless_panel_printing();
    // panel_printing_collisions();

    for(;;);
}
