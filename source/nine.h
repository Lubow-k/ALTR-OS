#define NULL (int*) 0

enum Color {
  PINK = 0b10100000000,
  RED = 0b10000000000,
  GREY = 0b11100000000,
  GREEN = 0b01100000000,
  ORANGE = 0b11000000000
};

void init();
void print_panel(int panel_num, char* fmt, int* args);
