typedef unsigned char byte;
typedef unsigned int u32;

void _memcpy(byte* from, byte* to, u32 size) {
    for (int i = 0; i < size; i++) {
        *(to + i) = *(from + i);
    }
}

void _clearcpy(byte* address, u32 size) {
    for (int i = 0; i < size; i++) {
        *(address + i) = 0;
    }
}