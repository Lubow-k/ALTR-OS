#include "configureController/six_lab.h"
#include "printSource/print_functions.h"
void fill_tramplins();
void STI();
void INT();
void recovery_ctx();

void __main() {

    init_printer();
    fill_tramplins();
    
    configure_master_controller();
    configure_slave_controller();  

    enable(KEYBOARD);    
    STI();
    
    print("In kernel entry\n");
    for (;;){
        print("RR");
    };

}

