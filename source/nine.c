#include "printSource/memory.h"
#define SIZE_OF_PANEL 4
#define HALF_WIDTH 39

short int* START = (short int*)0xB8000;
short int pink = 0b10100000000;
short int grey = 0b11100000000;

typedef unsigned char byte;
 

static int X;
static int Y;

typedef struct {
    int x;
    int y;
    int bound_x; 
    int bound_y;
} coords;

static coords panel[4];

static void move_screen(int num) {
    for (int i=11;i>0;i--) {
        byte* start_local = (byte*)START + (panel[num].bound_x - HALF_WIDTH) * 2 + (panel[num].bound_y - (i + 1)) * 80 * 2;
        _memcpy(start_local + 80 * 2, start_local, HALF_WIDTH * 2);
    }
    _clearcpy((byte*) ((byte*)START + (panel[num].bound_x - HALF_WIDTH) * 2 + (panel[num].bound_y - 1) * 80 * 2), HALF_WIDTH * 2);
    panel[num].y = panel[num].bound_y - 1; 
}

static void check(int num) {  
    if (panel[num].x >= panel[num].bound_x) {
        panel[num].x = panel[num].bound_x - HALF_WIDTH;
        panel[num].y++;
    }
    if (panel[num].y >= panel[num].bound_y) {
        move_screen(num);
    }
}

static void print_char(int num, char symbol, short int color) {  // печать символа в позиции (x, y)
    short int mask = color; // Маска при печати символа, ставит цвет
    mask = mask | symbol;
    *((short int*)START + (panel[num].y * 80 + panel[num].x)) = mask;
    panel[num].x++;
    check(num);
}

static void clear_screen() { 
    short int* start = (short int*)START;
    for (int i = 0; i < 4000; i++) {
        *((short int*)start) = 0;
        start++;
    }
}

static void fill_panel(int panelNum, int startX, int startY, int boundX, int boundY) {
    coords panelka;
    panelka.x = startX;
    panelka.y = startY;
    panelka.bound_x = boundX;
    panelka.bound_y = boundY;  // NOT inclusive
    panel[panelNum] = panelka;
}

void init() {
    clear_screen();
    fill_panel(0, 0, 0, 39, 12);
    fill_panel(1, 41, 0, 80, 12);
    fill_panel(2, 0, 13, 39, 25);
    fill_panel(3, 41, 13, 80, 25);

    short int mask = grey;
    unsigned char symbol = 205;   
    mask = mask | symbol;

    for (int i = 0; i < 80; i++) {
        *((short int*)START + (12 * 80 + i)) = mask;
    }

    mask = grey;
    symbol = 186;
    mask = mask | symbol;

    for (int i = 0; i < 25; i++) {
        *((short int*)START + (i * 80 + HALF_WIDTH)) = mask;
        *((short int*)START + (i * 80 + HALF_WIDTH + 1)) = mask;
    }
}


static void print_number(int panel_num, int number, int base) {
    if (number == 0) {
        print_char(panel_num, 48, pink);
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
                print_char(panel_num, digit + 'A' - 10, pink);
            }
            else {
                print_char(panel_num, digit + '0', pink);
            }
        }
    }
}

void print_panel(int panel_num, char* fmt, ...) {
    int* args = (int*) &fmt;
    args++;
    while (*fmt != '\0') {
        if (*fmt == '%') {
            fmt++;
            if (*fmt == 'd') {
                int num = *args;
                print_number(panel_num, num, 10);
                args++;
            }
            else if (*fmt == 'x') {
                int num = *args;
                print_number(panel_num, num, 16);
                args++;
            }
            else {
                print_char(panel_num, *fmt, pink);
            }
        }
        else if (*fmt == '\n') {
            panel[panel_num].y++;
            panel[panel_num].x = panel[panel_num].bound_x - 40;
            check(panel_num);
        }
        else {
            print_char(panel_num, *fmt, pink);
        }
        fmt++;
    }
}


