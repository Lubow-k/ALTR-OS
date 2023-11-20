#include "printSource/print_functions.h"

void CLI();

void kernel_panic(char* fmt, ...) {
    CLI();
    init_printer();
    int* address = (int*)&fmt;
    address++;
    inner_print(fmt, address);
    for (;;);
}
