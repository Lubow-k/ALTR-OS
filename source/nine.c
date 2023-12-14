#include "printSource/memory.h"
#include "nine.h"

#define AMOUNT_OF_CONSOLES 4
#define CONSOLE_WIDTH 39
#define PANEL_HEIGHT 25
#define PANEL_WIDTH 80


short int* START = (short int*)0xB8000;

typedef unsigned char byte;
 

static int X;
static int Y;

typedef struct {
    int x;
    int y;
    int bound_x; 
    int bound_y;
    enum Color color;
} coords;

static coords panel[AMOUNT_OF_CONSOLES];

static void move_screen(int num) {
    for (int i = 11; i > 0; i--) {
        byte* start_local = (byte*)START + (panel[num].bound_x - CONSOLE_WIDTH) * 2 + (panel[num].bound_y - (i + 1)) * PANEL_WIDTH * 2;
        _memcpy(start_local + PANEL_WIDTH * 2, start_local, CONSOLE_WIDTH * 2);
    }
    _clearcpy((byte*) ((byte*)START + (panel[num].bound_x - CONSOLE_WIDTH) * 2 + (panel[num].bound_y - 1) * PANEL_WIDTH * 2), CONSOLE_WIDTH * 2);
    panel[num].y = panel[num].bound_y - 1; 
}

static void check(int num) {  
    if (panel[num].x >= panel[num].bound_x) {
        panel[num].x = panel[num].bound_x - CONSOLE_WIDTH;
        panel[num].y++;
    }
    if (panel[num].y >= panel[num].bound_y) {
        move_screen(num);
    }
}

static void print_char(int num, char symbol) {  // печать символа в позиции (x, y)
    short int mask = (short int) panel[num].color; // Маска при печати символа, ставит цвет
    mask = mask | symbol;
    *((short int*)START + (panel[num].y * PANEL_WIDTH + panel[num].x)) = mask;
    panel[num].x++;
    check(num);
}

static void clear_screen() { 
    short int* start = (short int*)START;
    for (int i = 0; i < PANEL_HEIGHT * PANEL_WIDTH; i++) {
        *((short int*)start) = 0;
        start++;
    }
}

static void fill_panel(int panelNum, int startX, int startY, int boundX, int boundY) {
    coords panelka;
    panelka.x = startX;
    panelka.y = startY;
    panelka.bound_x = boundX;
    panelka.bound_y = boundY; 
    enum Color color;
    switch (panelNum) {
        case 0:
            color = PINK;
            break;
        case 1:
            color = RED;
            break;
        case 2:
            color = GREEN;
            break;
        case 3:
            color = ORANGE;
            break;
        default:
            color = GREY;
    }
    panelka.color = color; 
    panel[panelNum] = panelka;

}

void init() {
    clear_screen();
    fill_panel(0, 0, 0, CONSOLE_WIDTH, PANEL_HEIGHT / 2);
    fill_panel(1, CONSOLE_WIDTH + 2, 0, PANEL_WIDTH, PANEL_HEIGHT / 2);
    fill_panel(2, 0, 13, CONSOLE_WIDTH, PANEL_HEIGHT);
    fill_panel(3, CONSOLE_WIDTH + 2, PANEL_HEIGHT / 2 + 1, PANEL_WIDTH, PANEL_HEIGHT);

    short int mask = (short int) GREY;
    unsigned char symbol = 205;   
    mask = mask | symbol;

    for (int i = 0; i < PANEL_WIDTH; i++) {
        *((short int*)START + (12 * 80 + i)) = mask;
    }

    mask = (short int) GREY;
    symbol = 186;
    mask = mask | symbol;

    for (int i = 0; i < PANEL_HEIGHT; i++) {
        *((short int*)START + (i * PANEL_WIDTH + CONSOLE_WIDTH)) = mask;
        *((short int*)START + (i * PANEL_WIDTH + CONSOLE_WIDTH + 1)) = mask;
    }
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
                print_char(panel_num, *fmt);
            }
        }
        else if (*fmt == '\n') {
            panel[panel_num].y++;
            panel[panel_num].x = panel[panel_num].bound_x - CONSOLE_WIDTH;
            check(panel_num);
        }
        else {
            print_char(panel_num, *fmt);
        }
        fmt++;
    }
}


