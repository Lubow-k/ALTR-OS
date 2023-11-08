typedef unsigned char byte;

void _memcpy(byte* from, byte* to, int size) {
    for (int i = 0; i < size; i++) {
        *(to + i) = *(from + i);
    }
}

void _clearcpy(byte* address, int size) {
    for (int i = 0; i < size; i++) {
        *(address + i) = 0;
    }
}