#include "printSource/memory.h"
#define SIZE_OF_PANEL 4
#define HALF_WIDTH 40

short int* START_ADDRESS = (short int*)0xB8000;

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
    for (int i=0;i<12;i++) {
        byte* start_local = (byte*)START_ADDRESS + (panel[num].bound_x - 40) * 2 + (panel[num].bound_y + i) * 80;
        _memcpy(start_local + 80 * 2, start_local, 40 * 2);  // ?????
    }
    _clearcpy((byte*) ((byte*)START_ADDRESS + (panel[num].bound_x - 40) * 2 + (panel[num].bound_y + 11) * 80), 40 * 2);  // ?????????????
    panel[num].x = panel[num].bound_x - 40;
    panel[num].y = panel[num].bound_y - 1; 
}

static void check(int num) {  // Не присвоитсz
    if (panel[num].x >= panel[num].bound_x) {
        panel[num].x = panel[num].bound_x - 40;
        panel[num].y++;
    }
    if (panel[num].y >= panel[num].bound_y) {
        move_screen(num);
    }
}

static void print_char(int num,char symbol) {  // печать символа в позиции (x, y)
    short int mask = 0b10100000000; // Маска при печати символа, ставит цвет
    mask = mask | symbol;
    *((short int*)START_ADDRESS + (panel[num].y * 80 + panel[num].x)) = mask;
    panel[num].x++;
    check(num);
}

static void clear_screen() { 
    short int* start = (short int*)START_ADDRESS;
    for (int i = 0; i < 4000; i++) {
        *((short int*)start) = 0;
        start++;
    }
}

void init() {
    clear_screen();
    coords first;
    first.x = 0;
    first.y = 0;
    first.bound_x = 40;
    first.bound_y = 13;
    panel[0] = first;

    coords second;
    second.x = 40;
    second.y = 0;
    second.bound_x = 80;
    second.bound_y = 13;
    panel[1] = second;

    coords third;
    third.x = 0;
    third.y = 13;
    third.bound_x = 40;
    third.bound_y = 25;
    panel[2] = third;

    coords fourth;
    fourth.x = 40;
    fourth.y = 13;
    fourth.bound_x = 80;
    fourth.bound_y = 25;
    panel[3] = fourth;
}


static void print_number(int panel_num, int number, int base) {
    if (number == 0) {
        print_char(panel_num, 48);
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
                print_char(panel_num, digit + 'A' - 10);
            }
            else {
                print_char(panel_num, digit + '0');
            }
        }
    }
}

void print_panel(int panel_num, char* fmt, ...) {
    int* args = (int*) &fmt;
    args += 2;
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
                print_char(panel_num, *fmt);
            }
        }
        else if (*fmt == '\n') {
            panel[panel_num].y++;
            panel[panel_num].x = 0;
            check(panel_num);
        }
        else {
            print_char(panel_num, *fmt);
        }
        fmt++;
    }
}


