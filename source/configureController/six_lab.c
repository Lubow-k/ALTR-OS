#include "../printSource/print_functions.h"

typedef unsigned char byte;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef enum Devices Devices;

byte inb(u16 port);
void outb(u16 port, byte data);


enum Devices {
  TIMER,
  KEYBOARD,
  SLAVE,
  COM2,
  COM1,
  LPT2,
  FlOPPYDISK,
  LPT1,
  CMOS,
  FREE_1,
  FREE_2,
  FREE_3,
  MOUSE,
  COPROCESSOR,
  PRIMARYHARDDISK,
  SECONDARYHARDDISK
};

void enable(Devices device) {
    print("Enable device with number: %d\n", device);
    byte port;
    if (device <= 7 && device >= 0){
        port = 0x21;
    } else if (device >= 8 && device <= 15) {
        port = 0xA1;
        device = device - 8;
    } else {
        return;
    }
    byte mask = inb(port);
    byte concat_mask = 1;
    // 0b00000001
    concat_mask = concat_mask << device;
    // 0b00001000
    concat_mask = ~concat_mask;
    // 0b11110111
    mask = mask & concat_mask;
    outb(port, mask);
}

void disable(Devices device) {
    print("Disable device with number: %d\n", device);
    byte port;
    if (device <= 7 && device >= 0){
        port = 0x21;
    } else if (device >= 8 && device <= 15) {
        port = 0xA1;
        device = device - 8;
    } else {
        return;
    }
    byte mask = inb(port);
    byte concat_mask = 1;
    // 0b00000001
    concat_mask = concat_mask << device;
    // 0b00001000
    mask = mask | concat_mask;
    outb(port, mask);
}


void configure_controller(u16 command, u16 data, byte ICW1, byte ICW2, byte ICW3, byte ICW4) {
    print("Configurating controller with command port %x\n", command);
    outb(command, ICW1);
    outb(0x80, ICW1);
    
    outb(data, ICW2);
    outb(0x80, ICW1);

    outb(data, ICW3);
    outb(0x80, ICW1);

    outb(data, ICW4);
}


void configure_master_controller(){
    // D0: Нужно ли еще одно до слово
    // D1: Сколько контроллеров
    // D3: Определеяет реакцию контроллера
    // (Нужно ли подавать ток на контакт постоянно или нет)
    // D4: Показывает что начинается инициализацию
    // D2, D5, D6, D7 -- не важны
    byte ICW1 = 0b00010001;
    // mapping исключений на вектора
    byte ICW2 = 0x20;
    // Определяет в какие порты подключены slave чипы
    byte ICW3 = 0b00000100;
    // Приоретизация устройств (используем стандартное)
    byte ICW4 = 0b00000001;

    configure_controller(0x20, 0x21, ICW1, ICW2, ICW3, ICW4);
    outb(0x21, 0b11111011);
}

void configure_slave_controller(){
    byte ICW1 = 0b00010001; 
    byte ICW2 = 0x28;
    byte ICW3 = 0b00000010;
    byte ICW4 = 0b00000001;

    configure_controller(0xA0, 0xA1, ICW1, ICW2, ICW3, ICW4);
    outb(0xA1, 0b11111111);
}