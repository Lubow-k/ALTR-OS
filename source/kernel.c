void vga_print_str(char* str, int x, int y) {// печать строки, начиная с позиции (x, y)
    str = "tutu";
    x = 0;
    y = 0;

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
    for (;;);
}

void vga_print_char(char symbol, int x, int y) {  // печать символа в позиции (x, y)
    *((short int*) 0xB8000 + (y*80 + x)) = symbol;
}

// void vga_clear_screen() {  // очистка экрана
//     short int* start = (short int*) 0xB8000;
//     for(int i = 0; i < 8000; i++) {
//         *((short int*) start) = 2345;
//         start++;
//     }

//     int x = 0;
//     int y = 0;
//     char symbol = 1;
//     *((short int*) 0xB8000 + (y*80 + x)) = symbol;

//     y = 1;
//     *((short int*) 0xB8000 + (y*80 + x)) = symbol;

//     for (;;);

// }

// void vga_print_char(char symbol, int x, int y) {  // печать символа в позиции (x, y)
//     *((short int*) 0xB8000 + (y*80 + x)) = symbol;
// }

// void vga_clear_screen() {  // очистка экрана
//     short int* start = (short int*) 0xB8000;
//     for(int i = 0; i < 4000; i++) {
//         *((short int*) start) = 0;
//         start++;
//     }
// }

// void kernel_entry() {
//     *((short int*) 0xB8000) = 0;
//     for (;;);
// }
