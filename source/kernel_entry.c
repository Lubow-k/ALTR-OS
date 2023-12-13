#include "configureController/six_lab.h"
#include "printSource/print_functions.h"
#include "nine.h"
void fill_tramplins();
void STI();
void INT();
void experiment();

void __main() {

    init_printer();
    fill_tramplins();  
    
    configure_master_controller();
    configure_slave_controller();  

    init();
    for (;;) {
        print_panel(0, "A\n");
        print_panel(1, "P\n");
        print_panel(2, "U");
        print_panel(3, "R");
    }
    

    // experiment();

    // enable(KEYBOARD);

    // enable(TIMER);    
    // STI();

    // for (;;){
    //     print("*");
    // };

    // for(;;);

}
