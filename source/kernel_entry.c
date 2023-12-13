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
    init_printer();
    for (;;) {
        print_panel(0, "A");
        print_panel(1, "*");
        print_panel(2, "-");
        print_panel(3, "R");
    }

    //print_panel(0, "A\n");
    //print_panel(1, "P\n");
    //print_panel(2, "U");
    //print_panel(3, "R");

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < i; j++) {
            print_panel(0, " ");
        }
        print_panel(0, "%d\n", i);
    }

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < i; j++) {
            print_panel(1, " ");
        }
        print_panel(1, "%d\n", i);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < i; j++) {
            print_panel(2, " ");
        }
        print_panel(2, "%d\n", i);
    }

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < i; j++) {
            print_panel(3, " ");
        }
        print_panel(3, "%d\n", i);
    }


    //for (int p = 0; p < 4; p++) {
    //    for (int i = 0; i < 5; i++) {
    //        for (int j = 0; j < i; j++) {
    //            print_panel(p, " ");
    //        }
    //        print_panel(p, "%d\n", i);
    //    }
    //}

    for (;;);
    // experiment();

    // enable(KEYBOARD);

    // enable(TIMER);    
    // STI();

    // for (;;){
    //     print("*");
    // };

    // for(;;);

}
