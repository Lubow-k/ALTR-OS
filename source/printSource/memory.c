void _memcpy(short int* from, short int* to, int size) {
    for (int i = 0; i < size; i++) {
        *(to + i) = *(from + i);
    }
}

void _clearcpy(short int* address, int size) {
    for (int i = 0; i < size; i++) {
        *(address + i) = 0;
    }
}