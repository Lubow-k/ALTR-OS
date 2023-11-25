typedef unsigned char byte;
typedef unsigned short int u16;
typedef unsigned int u32;
typedef enum Devices Devices;
void irq_fill(byte port, byte mask);
void configure_master_controller();
void configure_slave_controller();
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

void disable(Devices device);
void enable(Devices device);