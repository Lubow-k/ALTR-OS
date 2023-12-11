#include "configureController/six_lab.h"
// #include "printSource/print_functions.h"
#include "nine.h"
void fill_tramplins();
void STI();
void INT();
void experiment();

void __main() {

    init();
    fill_tramplins();
    
    configure_master_controller();
    configure_slave_controller();  

    print_panel(0, "In kernel entry\n");
    print_panel(1, "PP\n");
    print_panel(2, "TT\n");
    print_panel(3, "RR\n");
    

    // experiment();

    // enable(KEYBOARD);

    // enable(TIMER);    
    // STI();

    // for (int i=0; i < 30; i++){
    //     for (int j=0; j < i; j++) {
    //             print(" ");
    //     }
    //     print("%d\n", i);
    // }
    // for (;;){
    //     print("*");
    // };

    for(;;);

}
