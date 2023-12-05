#include "configureController/six_lab.h"
#include "printSource/print_functions.h"
void fill_tramplins();
void STI();
void INT();
void experiment();

void __main() {

    init_printer();
    fill_tramplins();
    
    configure_master_controller();
    configure_slave_controller();  

    print("In kernel entry\n");
    experiment();

    // enable(KEYBOARD);    
    // STI();
    
    for (;;){
        // print("RR");
    };

}
