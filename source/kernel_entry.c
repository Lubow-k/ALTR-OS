#include "six_lab.h"
#include "printSource/print_functions.h"
void fill_tramplins();
void STI();

void __main() {
    fill_tramplins();
    
    configure_master_controller();
    configure_slave_controller();

    irq_fill(0x21, 0b11111010);
    STI();
    // irq_fill(0x21, 0b11111001);
    
    for (;;);

}


