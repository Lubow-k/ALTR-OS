#include "printSource/print_functions.h"

typedef unsigned char byte;
typedef unsigned short int u16;
typedef unsigned int u32;

byte inb(u16 port);
void outb(u16 port, byte data);

void irq_fill(byte port, byte mask) {
    outb(port, mask);
}


void configure_master_controller(){
    init_printer();
    byte ICW1 = 0b00010001;
    byte ICW2 = 0x20;
    byte ICW3 = 0b00000100;
    byte ICW4 = 0b00000001;

    print("Start configurating master controller\n");

    outb(0x20, ICW1);
    print("Send ICW1 on 0x20\n");
    outb(0x80, ICW1);
    print("Send ICW1 on 0x80\n");


    outb(0x21, ICW2);
    print("Send ICW2 on 0x21\n");
    outb(0x80, ICW1);
    print("Send ICW1 on 0x80\n");

    outb(0x21, ICW3);
    print("Send ICW3 on 0x21\n");
    outb(0x80, ICW1);
    print("Send ICW1 on 0x80\n");

    outb(0x21, ICW4);
    print("Send ICW4 on 0x21\n");

    irq_fill(0x21, 0b11111111);
}

void configure_slave_controller(){
    byte ICW1 = 0b00010001; 
    byte ICW2 = 0x28;
    byte ICW3 = 0b00000010;
    byte ICW4 = 0b00000001;

    outb(0xA0, ICW1);
    outb(0x80, ICW1);
    
    outb(0xA1, ICW2);
    outb(0x80, ICW1);

    outb(0xA1, ICW3);
    outb(0x80, ICW1);

    outb(0xA1, ICW4);
}