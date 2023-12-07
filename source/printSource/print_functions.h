void vga_move_screen();

void vga_print_char(char symbol);

void vga_print_str(char* str);

void vga_clear_screen();

void init_printer();

void print_number(int number, int base);

void print(char* fmt, ...);

void change_x(int x);

void change_y(int y);

int get_x();

int get_y();

