#include "../printSource/print_functions.h"
#include "six_lab.h"

#define MASTER_COMMAND_PORT 0x20
#define MASTER_DATA_PORT 0x21
#define SLAVE_COMMAND_PORT 0xA0
#define SLAVE_DATA_PORT 0xA1
#define TRASH_PORT 0x80

#define DEBUG

byte inb(u16 port);
void outb(u16 port, byte data);


static byte operation(Devices device, int enable_flag) {
    byte port;
    if (device <= 7 && device >= 0){
        port = (byte) MASTER_DATA_PORT;
    } else {
        port = (byte) SLAVE_DATA_PORT;
        device -= 8;
    } 

    byte mask = inb(port);
    // 0b00000001 -> 0b00001000
    byte bit_mask = 1 << device;

    if (enable_flag) {
        // 0b11110111
        bit_mask = ~bit_mask;
        mask = mask & bit_mask;
    } else {
        mask = mask | bit_mask;
    }
    outb(port, mask);
}


void enable(Devices device) {
    #ifdef DEBUG
    print("Enable device with number: %d\n", device);
    #endif
    operation(device, 1);
}

void disable(Devices device) {
    #ifdef DEBUG
    print("Disable device with number: %d\n", device);
    #endif
    operation(device, 0);
}


void configure_controller(u16 command, u16 data, byte ICW1, byte ICW2, byte ICW3, byte ICW4) {
    #ifdef DEBUG
    print("Configurating controller with command port %x\n", command);
    #endif
    outb(command, ICW1);
    outb(TRASH_PORT, ICW1);
    
    outb(data, ICW2);
    outb(TRASH_PORT, ICW1);

    outb(data, ICW3);
    outb(TRASH_PORT, ICW1);

    outb(data, ICW4);
}


void configure_master_controller(){
    // D0: Нужно ли еще одно слово
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

    configure_controller(MASTER_COMMAND_PORT, MASTER_DATA_PORT, ICW1, ICW2, ICW3, ICW4);
    outb(MASTER_DATA_PORT, 0b11111011);
}

void configure_slave_controller(){
    byte ICW1 = 0b00010001; 
    byte ICW2 = 0x28;
    byte ICW3 = 0b00000010;
    byte ICW4 = 0b00000001;

    configure_controller(SLAVE_COMMAND_PORT, SLAVE_DATA_PORT, ICW1, ICW2, ICW3, ICW4);
    outb(SLAVE_DATA_PORT, 0b11111111);
}