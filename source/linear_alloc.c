#include "printSource/memory.h"

typedef unsigned char byte;
typedef unsigned int u32;

#define NULL (void*)0
#define START 0x100000
#define END 0x400000


byte* current = (byte*) START;
byte* previous = NULL;

byte* kernel_malloc(u32 size) {
    if (current + size < (byte*) END) {
            previous = current;
            current += size;
            return previous;
    }
    return NULL;
}

byte* kernel_calloc(u32 size) {
    if (current + size < (byte*) END) {
        _clearcpy(current, size);
        previous = current;
        current += size;
        return previous;
    }
    return NULL;
}

byte* kernel_realloc(void* old_addr, u32 new_size) {
    if (current + new_size < (byte*) END) { 
        _memcpy(old_addr, current, new_size);
        previous = current;
        current += new_size;
        return previous;
    }
    return NULL;
}

// void kernel_free(void* addr) {
// }
