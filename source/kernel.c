short int* START_ADDRESS = (short int*)0xB8000;

int X;
int Y;

void _memcpy(short int* from, short int* to, int size);

void _clearcpy(short int* address, int size);

void vga_move_screen();

void check_coord();

void vga_print_char(char symbol);

void vga_print_str(char* str);

void vga_clear_screen();

void init_printer();

void print_number(int number, int base);

void print(char* fmt, ...);

void print_logo();

void check_scroll();

void __main() {
    init_printer();
    print_logo();
    //print("Hello, world!, %d, %%", 5);
    //check_scroll();


    for (;;);
}


void _memcpy(short int* from, short int* to, int size) {
    for (int i = 0; i < size; i++) {
        *(to + i) = *(from + i);
    }
}

void _clearcpy(short int* address, int size) {
    for (int i = 0; i < size; i++) {
        *(address + i) = 0;
    }
}

void vga_move_screen() {
    _memcpy(START_ADDRESS + 80, START_ADDRESS, 3920);
    _clearcpy(START_ADDRESS + 3920, 80);
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
    short int mask = 0b10100000000; // Маска при печати символа, ставит цвет
    mask = mask | symbol;
    *((short int*)START_ADDRESS + (Y * 80 + X)) = mask;
    X++;
}

void vga_print_str(char* str) {// печать строки, начиная с позиции (x, y)
    char c;
    int index = 0;
    while (str[index] != '\0') {
        c = str[index++];
        vga_print_char(c);
    }
}


void vga_clear_screen() {  // очистка экрана
    short int* start = (short int*)START_ADDRESS;
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
                vga_print_char(digit + 'A' - 10);
            }
            else {
                vga_print_char(digit + '0');
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
            }
            else {
                vga_print_char(*fmt);
            }
        }
        else if (*fmt == '\n') {
            Y++;
            X = 0;
            check_coord();
        }
        else {
            vga_print_char(*fmt);
        }
        fmt++;
    }
}


void print_logo() {
    char* logo[] = { "                ________   ___    _________   ________",
                    "                |\\   __  \\ |\\  \\  |\\___   ___\\|\\   __  \\",
                    "                 \\ \\  \\|\\  \\\\ \\  \\ \\|___\\  \\_| \\ \\  \\|\\  \\",
                    "                   \\ \\   __  \\\\ \\  \\    \\ \\  \\   \\ \\   _  _\\",
                    "                     \\ \\  \\ \\  \\\\ \\  \\____\\ \\  \\   \\ \\  \\\\  \\|",
                    "                       \\ \\__\\ \\__\\\\ \\______\\\\ \\__\\   \\ \\__\\\\ _\\",
                    "                         \\|__|\\|__| \\|______| \\|__|    \\|__||__|" };


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
