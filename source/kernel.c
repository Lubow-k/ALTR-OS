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
            // TODO: перенести экран вверх если y > 25
        }
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
    // start print
}

void print(char* fmt, ...) {
    
}

void __main() {
    vga_clear_screen();
    // vga_print_char('A', 1, 1);
    vga_print_str("RRRRRRRRRRRRRRR\0", 0, 0);
    for (;;);
}

