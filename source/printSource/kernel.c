#include "print_functions.h"

void print_logo();

void check_scroll();


void __main() {
    init_printer();
    print_logo();
    //print("Hello, world!, %d, %%", 5);
    //check_scroll();
    for (;;);
}


void print_logo() {
    char* logo[] = {"                 ________   ___    _________   ________",
                    "                |\\   __  \\ |\\  \\  |\\___   ___\\|\\   __  \\",
                    "                 \\ \\  \\|\\  \\\\ \\  \\ \\|___\\  \\_| \\ \\  \\|\\  \\",
                    "                   \\ \\   __  \\\\ \\  \\    \\ \\  \\   \\ \\   _  _\\",
                    "                     \\ \\  \\ \\  \\\\ \\  \\____\\ \\  \\   \\ \\  \\\\  \\|",
                    "                       \\ \\__\\ \\__\\\\ \\______\\\\ \\__\\   \\ \\__\\\\ _\\",
                    "                         \\|__|\\|__| \\|______| \\|__|    \\|__||__|" };


    change_x(0);
    change_y(8);
    for (int i = 0; i < 7; i++) {
        vga_print_str(logo[i]);
        change_x(0);
        change_y(get_y() + 1);
    }
}

void check_scroll() {
    init_printer();
    for (int i = 0; i < 30; i++) {
        for (int j = 0; j < i; j++) {
            print(" ");
        }
        print("%d\n", i);
    }
}
