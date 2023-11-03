int X;
int Y;

void vga_move_screen() {
    short int* address = (short int*)0xB8000;
    for (int i = 0; i < 4000 - 80; i++) {
        *address = *(address + 80);
        address++;
    }
    for (int i = 0; i < 80; i++) {
        *address = 0;
    }
    X = 0;
    Y = 24;
}

void check_coord() {
    if (X == 80) {
        Y++;
        X = 0;
    }
    if (Y == 25) {
        vga_move_screen();
    }
}

void vga_print_char(char symbol) {  // печать символа в позиции (x, y)
    check_coord();
    short int mask = 0b10100000000;
    mask = mask | symbol;
    *((short int*)0xB8000 + (Y * 80 + X)) = mask;
    X++;
}

void vga_print_str(char* str) {    // печать строки, начиная с позиции (x, y)
    char c;
    int index = 0;
    while (str[index] != '\0') {
        c = str[index++];
        vga_print_char(c);
        check_coord();
    }
}

void check_end() {
    if (X == 80 && Y == 24) {
        vga_move_screen();
    }
}

void vga_clear_screen() {  // очистка экрана
    short int* start = (short int*)0xB8000;
    for (int i = 0; i < 4000; i++) {
        *((short int*)start) = 0;
        start++;
    }
}

void init_printer() {
    vga_clear_screen();
    X = 0;
    Y = 0;
}

void print_number(int number, int base) {
    if (number == 0) {
        vga_print_char(48);
    }
    else {
        int num = number;
        int counter = 0;
        while (num > 0) {
            num = num / base;
            counter++;
        }
        int deg = 1;
        for (int i = 0; i < counter - 1; i++) {  // get base^(counter - 1)
            deg *= base;
        }

        for (int i = 0; i < counter; i++) {
            int digit = number / deg;
            number = number % deg;
            deg = deg / base;
            if (digit > 9) {
                vga_print_char(digit + 55);
            }
            else {
                vga_print_char(digit + 48);
            }
        }
    }
}

void print(char* fmt, ...) {
    int* address = (int*)&fmt;
    address++;

    while (*fmt != '\0') {
        if (*fmt == '%') {
            fmt++;
            if (*fmt == 'd') {
                int num = *(int*)address;
                print_number(num, 10);
                address++;
            }
            else if (*fmt == 'x') {
                int num = *(int*)address;
                print_number(num, 16);
                address++;
            }
            else if (*fmt == 's') {
                vga_print_str(*(char**)address);
                address++;
            } // else not support
        }
        else if (*fmt == '\n') {
            Y++;
            X = 0;
        }
        else {
            vga_print_char(*fmt);
        }
        fmt++;
    }
}


void print_logo() {
    char* logo[] = { "                  ________   ___    _________   ________",
                    "                  |\\   __  \\ |\\  \\  |\\___   ___\\|\\   __  \\",
                    "                   \\ \\  \\|\\  \\\\ \\  \\ \\|___\\  \\_| \\ \\  \\|\\  \\",
                    "                     \\ \\   __  \\\\ \\  \\    \\ \\  \\   \\ \\   _  _\\",
                    "                       \\ \\  \\ \\  \\\\ \\  \\____\\ \\  \\   \\ \\  \\\\  \\|",
                    "                         \\ \\__\\ \\__\\\\ \\______\\\\ \\__\\   \\ \\__\\\\ _\\",
                    "                           \\|__|\\|__| \\|______| \\|__|    \\|__||__|" };


    X = 0;
    Y = 8;
    for (int i = 0; i < 7; i++) {
        vga_print_str(logo[i]);
        X = 0;
        Y++;
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

void __main() {
    init_printer();
    print_logo();
    //print("Hello, world!, %d", 5);
    // check_scroll();

    for (;;);
}

