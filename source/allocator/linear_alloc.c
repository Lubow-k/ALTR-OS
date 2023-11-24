#include "../printSource/memory.h"

void kernel_panic(char* fmt, ...);

typedef unsigned char byte;
typedef unsigned int u32;

#define START 0x100000
#define END 0x400000


static byte* current = (byte*) START;

byte* kernel_malloc(u32 size) {
    if (current + size < (byte*) END) {
            byte* previous = current;
            current += size;
            return previous;
    }
    kernel_panic("Out of memory");
}

byte* kernel_calloc(u32 size) {
    byte* new_addr = kernel_malloc(size);
    _clearcpy(new_addr, size);
    return new_addr;
}

byte* kernel_realloc(void* old_addr, u32 new_size) {
    byte* new_addr = kernel_malloc(new_size);
    _memcpy(old_addr, new_addr, new_size);
    return new_addr;
}

// void kernel_free(void* addr) {
// }
