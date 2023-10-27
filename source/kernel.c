short int* ADDRESS;

void vga_print_char(char symbol, int x, int y) {  // печать символа в позиции (x, y)
    short int mask = 0b10100000000;
    mask = mask | symbol;
    *((short int*) 0xB8000 + (y*80 + x)) = mask;
}

void vga_print_str(char* str, int x, int y) {// печать строки, начиная с позиции (x, y)
    char c;
    int index = 0;
    while (str[index] != '\0'){
        c = str[index++];
        vga_print_char(c, x, y);
        x++;
        if (x >= 80){
            y++;
            x = 0;
        }
    }
}

void inner_vga_move_screen(){
    short int* address = (short int *) 0xB8000;
    for(int i = 0; i < 4000 - 80; i++) {
        *address = *(address + 80);
        address++;
    }
    for (int i = 0; i < 80; i++){
        *address = 0;
    }
    ADDRESS -= 80;
}

void inner_check_end() {
    if (ADDRESS == (short int*)0xB8FA0){
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
    while (str[index] != '\0'){
        c = str[index++];
        inner_vga_print_char(c);
    }
}

void vga_clear_screen() {  // очистка экрана
    short int* start = (short int*) 0xB8000;
    for(int i = 0; i < 4000; i++) {
        *((short int*) start) = 0;
        start++;
    }
}

void init_printer() {
    vga_clear_screen();
    ADDRESS = (short int*) 0xB8000;
}

// Когда напишем print написать протестить check_end
void print(char* fmt, ...) {
    int* address = (int*) &fmt;

    // vga_print_str(*(char**) address, 0, 0);
    address += 1;
    // vga_print_str(*(char**) address, 1, 1);
    

    while (*fmt != '\0') {
        if (*fmt == '%') {
            fmt++;
            if (*fmt == 'd') {
                num = *(int*) address;
                // Разделить на разряды и напечатать
                inner_vga_print_char(*(int*) address + 48);
                address++;
            }else if (*fmt == 'x') {
                // get symbol
                // vga_print_char(symbol + ??, X, Y);
            }else if (*fmt == 's') {
                inner_vga_print_str(*(char**) address);
                address++;
            }
        } else {
            inner_vga_print_char(*fmt);
        }
      fmt++;
   }
}

void __main() {
    init_printer();

    print("%d", 12);
    for (;;);
}

