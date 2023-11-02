short int* ADDRESS;

void vga_print_char(char symbol, int x, int y) {  // печать символа в позиции (x, y)
    short int mask = 0b10100000000;
    mask = mask | symbol;
    *((short int*)0xB8000 + (y * 80 + x)) = mask;
}

void vga_print_str(char* str, int x, int y) {// печать строки, начиная с позиции (x, y)
    char c;
    int index = 0;
    while (str[index] != '\0') {
        c = str[index++];
        vga_print_char(c, x, y);
        x++;
        if (x >= 80) {
            y++;
            x = 0;
        }
    }
}

void inner_vga_move_screen() {
    short int* address = (short int*)0xB8000;
    for (int i = 0; i < 4000 - 80; i++) {
        *address = *(address + 80);
        address++;
    }
    for (int i = 0; i < 80; i++) {
        *address = 0;
    }
    ADDRESS -= 80;
}

void inner_check_end() {
    if (ADDRESS == (short int*)0xB8FA0) {
        inner_vga_move_screen();
    }
}

void inner_vga_print_char(char symbol) {
    inner_check_end();
    short int mask = 0b10100000000;
    mask = mask | symbol;
    *(ADDRESS) = mask;
    ADDRESS++;
}

void inner_vga_print_str(char* str) {
    char c;
    int index = 0;
    while (str[index] != '\0') {
        c = str[index++];
        inner_vga_print_char(c);
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
    ADDRESS = (short int*)0xB8000;
}

void print_number(int number, int base) {
    if (number == 0) {
        inner_vga_print_char(48);
    }
    else {
        int num = number;
        int counter = 0;
        while (num > 0) {
            num = num / base;
            counter++;
        }
        int deg = 1;
        int tmp = base;
        for (int i = 0; i < counter - 1; i++) {  // get base^(counter - 1)
            deg *= tmp;
        }

        for (int i = 0; i < counter; i++) {
            int digit = number / deg;
            number = number % deg;
            deg = deg / base;
            if (digit > 9) {
                inner_vga_print_char(digit + 55);
            }
            else {
                inner_vga_print_char(digit + 48);
            }
        }
    }
}

// Когда напишем print написать протестить check_end
void print(char* fmt, ...) {
    int* address = (int*)&fmt;
    address++;

    // vga_print_str(*(char**) address, 0, 0);
    // vga_print_str(*(char**) address, 1, 1);

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
                inner_vga_print_str(*(char**)address);
                address++;
            } // else not support
        } else if (*fmt == '\n') {
            ADDRESS += 80;  //ERROR
        }
        else {
            inner_vga_print_char(*fmt);
        }
        fmt++;
    }
}


void print_logo() {
    char* logo[] = { "                                                                                \0",
                    "                                                                                \0",
                    "                                                                                \0",
                    "                                                                                \0",
                    "                                                                                \0",
                    "                                                                                \0",
                    "                                                                                \0",
                    "                 ________   ___    _________   ________                        \0",
                    "                 |\\   __  \\ |\\  \\  |\\___   ___\\|\\   __  \\                      \0",
                    "                   \\ \\  \\|\\  \\\\ \\  \\ \\|___\\  \\_| \\ \\  \\|\\  \\                    \0",
                    "                     \\ \\   __  \\\\ \\  \\    \\ \\  \\   \\ \\   _  _\\                  \0",
                    "                       \\ \\  \\ \\  \\\\ \\  \\____\\ \\  \\   \\ \\  \\\\  \\|                \0",
                    "                         \\ \\__\\ \\__\\\\ \\______\\\\ \\__\\   \\ \\__\\\\ _\\               \0",
                    "                           \\|__|\\|__| \\|______| \\|__|    \\|__||__| \0" };

    for (int i = 0; i < 15; i++) {
        inner_vga_print_str(logo[i]);
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
    // print_logo();
    check_scroll();
    // print("Hello world , %d", 12340);
    for (;;);
}

