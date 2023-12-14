#include "nine.h"


void endless_panel_printing() {
    for (;;) {
            print_panel(0, "A");
            print_panel(1, "*");
            print_panel(2, "-");
            print_panel(3, "R");
    }
}

void panel_printing_collisions() {
    for (;;) {
            print_panel(0, "A\n");
            print_panel(1, "*\n");
            print_panel(2, "-");
            print_panel(3, "R");
    }
}

void print_field(int panel, int unless) {
    for (int i = 0; i < unless; i++) {
        for (int j = 0; j < i; j++) {
            print_panel(panel, " ");
        }
        print_panel(panel, "%d\n", i);
    }
}


void panel_printing_scroll() {
    print_field(0, 15);
    print_field(1, 13);
    print_field(2, 10);
    print_field(3, 30);
    /*for (int i = 0; i < 15; i++) {
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
    }*/
}