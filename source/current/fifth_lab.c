#define IDT_SIZE 256
#include "print_functions.h"

typedef char byte;
typedef unsigned short int u16;
typedef unsigned int u32;

void LIDT();
void INT();
static void panic_handler();
static void tramplin_0();
static void tramplin_1();
static void tramplin_2();
static void tramplin_3();
static void tramplin_4();
static void tramplin_5();
static void tramplin_6();
static void tramplin_7();
static void tramplin_8();
static void tramplin_9();
static void tramplin_A();
static void tramplin_B();
static void tramplin_C();
static void tramplin_D();
static void tramplin_E();
static void tramplin_F();
static void tramplin_10();
static void tramplin_11();
static void tramplin_12();
static void tramplin_13();
static void tramplin_14();
static void tramplin_15();
static void tramplin_16();
static void tramplin_17();
static void tramplin_18();
static void tramplin_19();
static void tramplin_1A();
static void tramplin_1B();
static void tramplin_1C();
static void tramplin_1D();
static void tramplin_1E();
static void tramplin_1F();
static void tramplin_20();
static void tramplin_21();
static void tramplin_22();
static void tramplin_23();
static void tramplin_24();
static void tramplin_25();
static void tramplin_26();
static void tramplin_27();
static void tramplin_28();
static void tramplin_29();
static void tramplin_2A();
static void tramplin_2B();
static void tramplin_2C();
static void tramplin_2D();
static void tramplin_2E();
static void tramplin_2F();
static void tramplin_30();
static void tramplin_31();
static void tramplin_32();
static void tramplin_33();
static void tramplin_34();
static void tramplin_35();
static void tramplin_36();
static void tramplin_37();
static void tramplin_38();
static void tramplin_39();
static void tramplin_3A();
static void tramplin_3B();
static void tramplin_3C();
static void tramplin_3D();
static void tramplin_3E();
static void tramplin_3F();
static void tramplin_40();
static void tramplin_41();
static void tramplin_42();
static void tramplin_43();
static void tramplin_44();
static void tramplin_45();
static void tramplin_46();
static void tramplin_47();
static void tramplin_48();
static void tramplin_49();
static void tramplin_4A();
static void tramplin_4B();
static void tramplin_4C();
static void tramplin_4D();
static void tramplin_4E();
static void tramplin_4F();
static void tramplin_50();
static void tramplin_51();
static void tramplin_52();
static void tramplin_53();
static void tramplin_54();
static void tramplin_55();
static void tramplin_56();
static void tramplin_57();
static void tramplin_58();
static void tramplin_59();
static void tramplin_5A();
static void tramplin_5B();
static void tramplin_5C();
static void tramplin_5D();
static void tramplin_5E();
static void tramplin_5F();
static void tramplin_60();
static void tramplin_61();
static void tramplin_62();
static void tramplin_63();
static void tramplin_64();
static void tramplin_65();
static void tramplin_66();
static void tramplin_67();
static void tramplin_68();
static void tramplin_69();
static void tramplin_6A();
static void tramplin_6B();
static void tramplin_6C();
static void tramplin_6D();
static void tramplin_6E();
static void tramplin_6F();
static void tramplin_70();
static void tramplin_71();
static void tramplin_72();
static void tramplin_73();
static void tramplin_74();
static void tramplin_75();
static void tramplin_76();
static void tramplin_77();
static void tramplin_78();
static void tramplin_79();
static void tramplin_7A();
static void tramplin_7B();
static void tramplin_7C();
static void tramplin_7D();
static void tramplin_7E();
static void tramplin_7F();
static void tramplin_80();
static void tramplin_81();
static void tramplin_82();
static void tramplin_83();
static void tramplin_84();
static void tramplin_85();
static void tramplin_86();
static void tramplin_87();
static void tramplin_88();
static void tramplin_89();
static void tramplin_8A();
static void tramplin_8B();
static void tramplin_8C();
static void tramplin_8D();
static void tramplin_8E();
static void tramplin_8F();
static void tramplin_90();
static void tramplin_91();
static void tramplin_92();
static void tramplin_93();
static void tramplin_94();
static void tramplin_95();
static void tramplin_96();
static void tramplin_97();
static void tramplin_98();
static void tramplin_99();
static void tramplin_9A();
static void tramplin_9B();
static void tramplin_9C();
static void tramplin_9D();
static void tramplin_9E();
static void tramplin_9F();
static void tramplin_A0();
static void tramplin_A1();
static void tramplin_A2();
static void tramplin_A3();
static void tramplin_A4();
static void tramplin_A5();
static void tramplin_A6();
static void tramplin_A7();
static void tramplin_A8();
static void tramplin_A9();
static void tramplin_AA();
static void tramplin_AB();
static void tramplin_AC();
static void tramplin_AD();
static void tramplin_AE();
static void tramplin_AF();
static void tramplin_B0();
static void tramplin_B1();
static void tramplin_B2();
static void tramplin_B3();
static void tramplin_B4();
static void tramplin_B5();
static void tramplin_B6();
static void tramplin_B7();
static void tramplin_B8();
static void tramplin_B9();
static void tramplin_BA();
static void tramplin_BB();
static void tramplin_BC();
static void tramplin_BD();
static void tramplin_BE();
static void tramplin_BF();
static void tramplin_C0();
static void tramplin_C1();
static void tramplin_C2();
static void tramplin_C3();
static void tramplin_C4();
static void tramplin_C5();
static void tramplin_C6();
static void tramplin_C7();
static void tramplin_C8();
static void tramplin_C9();
static void tramplin_CA();
static void tramplin_CB();
static void tramplin_CC();
static void tramplin_CD();
static void tramplin_CE();
static void tramplin_CF();
static void tramplin_D0();
static void tramplin_D1();
static void tramplin_D2();
static void tramplin_D3();
static void tramplin_D4();
static void tramplin_D5();
static void tramplin_D6();
static void tramplin_D7();
static void tramplin_D8();
static void tramplin_D9();
static void tramplin_DA();
static void tramplin_DB();
static void tramplin_DC();
static void tramplin_DD();
static void tramplin_DE();
static void tramplin_DF();
static void tramplin_E0();
static void tramplin_E1();
static void tramplin_E2();
static void tramplin_E3();
static void tramplin_E4();
static void tramplin_E5();
static void tramplin_E6();
static void tramplin_E7();
static void tramplin_E8();
static void tramplin_E9();
static void tramplin_EA();
static void tramplin_EB();
static void tramplin_EC();
static void tramplin_ED();
static void tramplin_EE();
static void tramplin_EF();
static void tramplin_F0();
static void tramplin_F1();
static void tramplin_F2();
static void tramplin_F3();
static void tramplin_F4();
static void tramplin_F5();
static void tramplin_F6();
static void tramplin_F7();
static void tramplin_F8();
static void tramplin_F9();
static void tramplin_FA();
static void tramplin_FB();
static void tramplin_FC();
static void tramplin_FD();
static void tramplin_FE();
static void tramplin_FF();

#pragma pack(push, 1)
typedef struct {  // Возможно они в другом порядке разложены
    u16 high_16_bits;
    u16 flags;
    u16 segment_selector;
    u16 low_16_bits;
} descriptor;

typedef struct{
    u16 high_16_bits;
    u16 low_16_bits;
    u16 size;
} didt;
#pragma pack(pop)

static void** tramplins = {tramplin_0, tramplin_1, tramplin_2, tramplin_3, tramplin_4, tramplin_5, tramplin_6, tramplin_7, tramplin_8, tramplin_9, tramplin_A, tramplin_B, tramplin_C, tramplin_D, tramplin_E, tramplin_F, tramplin_10, tramplin_11, tramplin_12, tramplin_13, tramplin_14, tramplin_15, tramplin_16, tramplin_17, tramplin_18, tramplin_19, tramplin_1A, tramplin_1B, tramplin_1C, tramplin_1D, tramplin_1E, tramplin_1F, tramplin_20, tramplin_21, tramplin_22, tramplin_23, tramplin_24, tramplin_25, tramplin_26, tramplin_27, tramplin_28, tramplin_29, tramplin_2A, tramplin_2B, tramplin_2C, tramplin_2D, tramplin_2E, tramplin_2F, tramplin_30, tramplin_31, tramplin_32, tramplin_33, tramplin_34, tramplin_35, tramplin_36, tramplin_37, tramplin_38, tramplin_39, tramplin_3A, tramplin_3B, tramplin_3C, tramplin_3D, tramplin_3E, tramplin_3F, tramplin_40, tramplin_41, tramplin_42, tramplin_43, tramplin_44, tramplin_45, tramplin_46, tramplin_47, tramplin_48, tramplin_49, tramplin_4A, tramplin_4B, tramplin_4C, tramplin_4D, tramplin_4E, tramplin_4F, tramplin_50, tramplin_51, tramplin_52, tramplin_53, tramplin_54, tramplin_55, tramplin_56, tramplin_57, tramplin_58, tramplin_59, tramplin_5A, tramplin_5B, tramplin_5C, tramplin_5D, tramplin_5E, tramplin_5F, tramplin_60, tramplin_61, tramplin_62, tramplin_63, tramplin_64, tramplin_65, tramplin_66, tramplin_67, tramplin_68, tramplin_69, tramplin_6A, tramplin_6B, tramplin_6C, tramplin_6D, tramplin_6E, tramplin_6F, tramplin_70, tramplin_71, tramplin_72, tramplin_73, tramplin_74, tramplin_75, tramplin_76, tramplin_77, tramplin_78, tramplin_79, tramplin_7A, tramplin_7B, tramplin_7C, tramplin_7D, tramplin_7E, tramplin_7F, tramplin_80, tramplin_81, tramplin_82, tramplin_83, tramplin_84, tramplin_85, tramplin_86, tramplin_87, tramplin_88, tramplin_89, tramplin_8A, tramplin_8B, tramplin_8C, tramplin_8D, tramplin_8E, tramplin_8F, tramplin_90, tramplin_91, tramplin_92, tramplin_93, tramplin_94, tramplin_95, tramplin_96, tramplin_97, tramplin_98, tramplin_99, tramplin_9A, tramplin_9B, tramplin_9C, tramplin_9D, tramplin_9E, tramplin_9F, tramplin_A0, tramplin_A1, tramplin_A2, tramplin_A3, tramplin_A4, tramplin_A5, tramplin_A6, tramplin_A7, tramplin_A8, tramplin_A9, tramplin_AA, tramplin_AB, tramplin_AC, tramplin_AD, tramplin_AE, tramplin_AF, tramplin_B0, tramplin_B1, tramplin_B2, tramplin_B3, tramplin_B4, tramplin_B5, tramplin_B6, tramplin_B7, tramplin_B8, tramplin_B9, tramplin_BA, tramplin_BB, tramplin_BC, tramplin_BD, tramplin_BE, tramplin_BF, tramplin_C0, tramplin_C1, tramplin_C2, tramplin_C3, tramplin_C4, tramplin_C5, tramplin_C6, tramplin_C7, tramplin_C8, tramplin_C9, tramplin_CA, tramplin_CB, tramplin_CC, tramplin_CD, tramplin_CE, tramplin_CF, tramplin_D0, tramplin_D1, tramplin_D2, tramplin_D3, tramplin_D4, tramplin_D5, tramplin_D6, tramplin_D7, tramplin_D8, tramplin_D9, tramplin_DA, tramplin_DB, tramplin_DC, tramplin_DD, tramplin_DE, tramplin_DF, tramplin_E0, tramplin_E1, tramplin_E2, tramplin_E3, tramplin_E4, tramplin_E5, tramplin_E6, tramplin_E7, tramplin_E8, tramplin_E9, tramplin_EA, tramplin_EB, tramplin_EC, tramplin_ED, tramplin_EE, tramplin_EF, tramplin_F0, tramplin_F1, tramplin_F2, tramplin_F3, tramplin_F4, tramplin_F5, tramplin_F6, tramplin_F7, tramplin_F8, tramplin_F9, tramplin_FA, tramplin_FB, tramplin_FC, tramplin_FD, tramplin_FE, tramplin_FF};

void __main(){
    init_printer();
    print("Starting\n");
    descriptor idt[256];
    for (int vector = 0; vector < IDT_SIZE; vector++){
        byte* handler = tramplins[vector]; // UB
        u16 low_16_bits = (u16) handler;
        u16 high_16_bits = (u16) (((u32) handler) >> 16);
        u16 segment_selector = (u16) 0;
        u16 flags = 0x8E00; // TODO: Поменять под разные прерывания
        descriptor local;

        local.low_16_bits = low_16_bits;
        local.high_16_bits = high_16_bits;
        local.segment_selector = segment_selector;
        local.flags = flags;
        idt[vector] = local;
    }
    print("IDT is ready\n");

    didt local_didt;
    local_didt.size = (u16) (8 * 256 - 1);

    local_didt.low_16_bits = (u16) idt;
    local_didt.high_16_bits = (u16) (((u32) idt) >> 16);
    print("Calling lidt\n");
    print("local adress %x\n", &local_didt);
    print("didt address %x\n", (u32) ((u32) &local_didt + (u32) 0x20200));
    LIDT((u32) ((u32) &local_didt + (u32) 0x20200)); // Вроде проблем с адресом нет
    print("Return from lidt\n");
    print("Calling int\n"); // Исполнение доходит до сюда, потом начинается бесконечная перезагрузка
    INT();
    print("Reterning from int\n");

    for (;;);
}

static void panic_handler(int vector){
    init_printer();
    print("unhandled interrupt %d", vector);
    for (;;);
}

static void tramplin_0() { panic_handler(0X0); }
static void tramplin_1() { panic_handler(0X1); }
static void tramplin_2() { panic_handler(0X2); }
static void tramplin_3() { panic_handler(0X3); }
static void tramplin_4() { panic_handler(0X4); }
static void tramplin_5() { panic_handler(0X5); }
static void tramplin_6() { panic_handler(0X6); }
static void tramplin_7() { panic_handler(0X7); }
static void tramplin_8() { panic_handler(0X8); }
static void tramplin_9() { panic_handler(0X9); }
static void tramplin_A() { panic_handler(0XA); }
static void tramplin_B() { panic_handler(0XB); }
static void tramplin_C() { panic_handler(0XC); }
static void tramplin_D() { panic_handler(0XD); }
static void tramplin_E() { panic_handler(0XE); }
static void tramplin_F() { panic_handler(0XF); }
static void tramplin_10() { panic_handler(0X10); }
static void tramplin_11() { panic_handler(0X11); }
static void tramplin_12() { panic_handler(0X12); }
static void tramplin_13() { panic_handler(0X13); }
static void tramplin_14() { panic_handler(0X14); }
static void tramplin_15() { panic_handler(0X15); }
static void tramplin_16() { panic_handler(0X16); }
static void tramplin_17() { panic_handler(0X17); }
static void tramplin_18() { panic_handler(0X18); }
static void tramplin_19() { panic_handler(0X19); }
static void tramplin_1A() { panic_handler(0X1A); }
static void tramplin_1B() { panic_handler(0X1B); }
static void tramplin_1C() { panic_handler(0X1C); }
static void tramplin_1D() { panic_handler(0X1D); }
static void tramplin_1E() { panic_handler(0X1E); }
static void tramplin_1F() { panic_handler(0X1F); }
static void tramplin_20() { panic_handler(0X20); }
static void tramplin_21() { panic_handler(0X21); }
static void tramplin_22() { panic_handler(0X22); }
static void tramplin_23() { panic_handler(0X23); }
static void tramplin_24() { panic_handler(0X24); }
static void tramplin_25() { panic_handler(0X25); }
static void tramplin_26() { panic_handler(0X26); }
static void tramplin_27() { panic_handler(0X27); }
static void tramplin_28() { panic_handler(0X28); }
static void tramplin_29() { panic_handler(0X29); }
static void tramplin_2A() { panic_handler(0X2A); }
static void tramplin_2B() { panic_handler(0X2B); }
static void tramplin_2C() { panic_handler(0X2C); }
static void tramplin_2D() { panic_handler(0X2D); }
static void tramplin_2E() { panic_handler(0X2E); }
static void tramplin_2F() { panic_handler(0X2F); }
static void tramplin_30() { panic_handler(0X30); }
static void tramplin_31() { panic_handler(0X31); }
static void tramplin_32() { panic_handler(0X32); }
static void tramplin_33() { panic_handler(0X33); }
static void tramplin_34() { panic_handler(0X34); }
static void tramplin_35() { panic_handler(0X35); }
static void tramplin_36() { panic_handler(0X36); }
static void tramplin_37() { panic_handler(0X37); }
static void tramplin_38() { panic_handler(0X38); }
static void tramplin_39() { panic_handler(0X39); }
static void tramplin_3A() { panic_handler(0X3A); }
static void tramplin_3B() { panic_handler(0X3B); }
static void tramplin_3C() { panic_handler(0X3C); }
static void tramplin_3D() { panic_handler(0X3D); }
static void tramplin_3E() { panic_handler(0X3E); }
static void tramplin_3F() { panic_handler(0X3F); }
static void tramplin_40() { panic_handler(0X40); }
static void tramplin_41() { panic_handler(0X41); }
static void tramplin_42() { panic_handler(0X42); }
static void tramplin_43() { panic_handler(0X43); }
static void tramplin_44() { panic_handler(0X44); }
static void tramplin_45() { panic_handler(0X45); }
static void tramplin_46() { panic_handler(0X46); }
static void tramplin_47() { panic_handler(0X47); }
static void tramplin_48() { panic_handler(0X48); }
static void tramplin_49() { panic_handler(0X49); }
static void tramplin_4A() { panic_handler(0X4A); }
static void tramplin_4B() { panic_handler(0X4B); }
static void tramplin_4C() { panic_handler(0X4C); }
static void tramplin_4D() { panic_handler(0X4D); }
static void tramplin_4E() { panic_handler(0X4E); }
static void tramplin_4F() { panic_handler(0X4F); }
static void tramplin_50() { panic_handler(0X50); }
static void tramplin_51() { panic_handler(0X51); }
static void tramplin_52() { panic_handler(0X52); }
static void tramplin_53() { panic_handler(0X53); }
static void tramplin_54() { panic_handler(0X54); }
static void tramplin_55() { panic_handler(0X55); }
static void tramplin_56() { panic_handler(0X56); }
static void tramplin_57() { panic_handler(0X57); }
static void tramplin_58() { panic_handler(0X58); }
static void tramplin_59() { panic_handler(0X59); }
static void tramplin_5A() { panic_handler(0X5A); }
static void tramplin_5B() { panic_handler(0X5B); }
static void tramplin_5C() { panic_handler(0X5C); }
static void tramplin_5D() { panic_handler(0X5D); }
static void tramplin_5E() { panic_handler(0X5E); }
static void tramplin_5F() { panic_handler(0X5F); }
static void tramplin_60() { panic_handler(0X60); }
static void tramplin_61() { panic_handler(0X61); }
static void tramplin_62() { panic_handler(0X62); }
static void tramplin_63() { panic_handler(0X63); }
static void tramplin_64() { panic_handler(0X64); }
static void tramplin_65() { panic_handler(0X65); }
static void tramplin_66() { panic_handler(0X66); }
static void tramplin_67() { panic_handler(0X67); }
static void tramplin_68() { panic_handler(0X68); }
static void tramplin_69() { panic_handler(0X69); }
static void tramplin_6A() { panic_handler(0X6A); }
static void tramplin_6B() { panic_handler(0X6B); }
static void tramplin_6C() { panic_handler(0X6C); }
static void tramplin_6D() { panic_handler(0X6D); }
static void tramplin_6E() { panic_handler(0X6E); }
static void tramplin_6F() { panic_handler(0X6F); }
static void tramplin_70() { panic_handler(0X70); }
static void tramplin_71() { panic_handler(0X71); }
static void tramplin_72() { panic_handler(0X72); }
static void tramplin_73() { panic_handler(0X73); }
static void tramplin_74() { panic_handler(0X74); }
static void tramplin_75() { panic_handler(0X75); }
static void tramplin_76() { panic_handler(0X76); }
static void tramplin_77() { panic_handler(0X77); }
static void tramplin_78() { panic_handler(0X78); }
static void tramplin_79() { panic_handler(0X79); }
static void tramplin_7A() { panic_handler(0X7A); }
static void tramplin_7B() { panic_handler(0X7B); }
static void tramplin_7C() { panic_handler(0X7C); }
static void tramplin_7D() { panic_handler(0X7D); }
static void tramplin_7E() { panic_handler(0X7E); }
static void tramplin_7F() { panic_handler(0X7F); }
static void tramplin_80() { panic_handler(0X80); }
static void tramplin_81() { panic_handler(0X81); }
static void tramplin_82() { panic_handler(0X82); }
static void tramplin_83() { panic_handler(0X83); }
static void tramplin_84() { panic_handler(0X84); }
static void tramplin_85() { panic_handler(0X85); }
static void tramplin_86() { panic_handler(0X86); }
static void tramplin_87() { panic_handler(0X87); }
static void tramplin_88() { panic_handler(0X88); }
static void tramplin_89() { panic_handler(0X89); }
static void tramplin_8A() { panic_handler(0X8A); }
static void tramplin_8B() { panic_handler(0X8B); }
static void tramplin_8C() { panic_handler(0X8C); }
static void tramplin_8D() { panic_handler(0X8D); }
static void tramplin_8E() { panic_handler(0X8E); }
static void tramplin_8F() { panic_handler(0X8F); }
static void tramplin_90() { panic_handler(0X90); }
static void tramplin_91() { panic_handler(0X91); }
static void tramplin_92() { panic_handler(0X92); }
static void tramplin_93() { panic_handler(0X93); }
static void tramplin_94() { panic_handler(0X94); }
static void tramplin_95() { panic_handler(0X95); }
static void tramplin_96() { panic_handler(0X96); }
static void tramplin_97() { panic_handler(0X97); }
static void tramplin_98() { panic_handler(0X98); }
static void tramplin_99() { panic_handler(0X99); }
static void tramplin_9A() { panic_handler(0X9A); }
static void tramplin_9B() { panic_handler(0X9B); }
static void tramplin_9C() { panic_handler(0X9C); }
static void tramplin_9D() { panic_handler(0X9D); }
static void tramplin_9E() { panic_handler(0X9E); }
static void tramplin_9F() { panic_handler(0X9F); }
static void tramplin_A0() { panic_handler(0XA0); }
static void tramplin_A1() { panic_handler(0XA1); }
static void tramplin_A2() { panic_handler(0XA2); }
static void tramplin_A3() { panic_handler(0XA3); }
static void tramplin_A4() { panic_handler(0XA4); }
static void tramplin_A5() { panic_handler(0XA5); }
static void tramplin_A6() { panic_handler(0XA6); }
static void tramplin_A7() { panic_handler(0XA7); }
static void tramplin_A8() { panic_handler(0XA8); }
static void tramplin_A9() { panic_handler(0XA9); }
static void tramplin_AA() { panic_handler(0XAA); }
static void tramplin_AB() { panic_handler(0XAB); }
static void tramplin_AC() { panic_handler(0XAC); }
static void tramplin_AD() { panic_handler(0XAD); }
static void tramplin_AE() { panic_handler(0XAE); }
static void tramplin_AF() { panic_handler(0XAF); }
static void tramplin_B0() { panic_handler(0XB0); }
static void tramplin_B1() { panic_handler(0XB1); }
static void tramplin_B2() { panic_handler(0XB2); }
static void tramplin_B3() { panic_handler(0XB3); }
static void tramplin_B9() { panic_handler(0XB9); }
static void tramplin_B4() { panic_handler(0XB4); }
static void tramplin_B5() { panic_handler(0XB5); }
static void tramplin_B6() { panic_handler(0XB6); }
static void tramplin_B7() { panic_handler(0XB7); }
static void tramplin_B8() { panic_handler(0XB8); }
static void tramplin_BA() { panic_handler(0XBA); }
static void tramplin_BB() { panic_handler(0XBB); }
static void tramplin_BC() { panic_handler(0XBC); }
static void tramplin_BD() { panic_handler(0XBD); }
static void tramplin_BE() { panic_handler(0XBE); }
static void tramplin_BF() { panic_handler(0XBF); }
static void tramplin_C0() { panic_handler(0XC0); }
static void tramplin_C1() { panic_handler(0XC1); }
static void tramplin_C2() { panic_handler(0XC2); }
static void tramplin_C3() { panic_handler(0XC3); }
static void tramplin_C4() { panic_handler(0XC4); }
static void tramplin_C5() { panic_handler(0XC5); }
static void tramplin_C6() { panic_handler(0XC6); }
static void tramplin_C7() { panic_handler(0XC7); }
static void tramplin_C8() { panic_handler(0XC8); }
static void tramplin_C9() { panic_handler(0XC9); }
static void tramplin_CA() { panic_handler(0XCA); }
static void tramplin_CB() { panic_handler(0XCB); }
static void tramplin_CC() { panic_handler(0XCC); }
static void tramplin_CD() { panic_handler(0XCD); }
static void tramplin_CE() { panic_handler(0XCE); }
static void tramplin_CF() { panic_handler(0XCF); }
static void tramplin_D0() { panic_handler(0XD0); }
static void tramplin_D1() { panic_handler(0XD1); }
static void tramplin_D2() { panic_handler(0XD2); }
static void tramplin_D3() { panic_handler(0XD3); }
static void tramplin_D4() { panic_handler(0XD4); }
static void tramplin_D5() { panic_handler(0XD5); }
static void tramplin_D6() { panic_handler(0XD6); }
static void tramplin_D7() { panic_handler(0XD7); }
static void tramplin_D8() { panic_handler(0XD8); }
static void tramplin_D9() { panic_handler(0XD9); }
static void tramplin_DA() { panic_handler(0XDA); }
static void tramplin_DB() { panic_handler(0XDB); }
static void tramplin_DC() { panic_handler(0XDC); }
static void tramplin_DD() { panic_handler(0XDD); }
static void tramplin_DE() { panic_handler(0XDE); }
static void tramplin_DF() { panic_handler(0XDF); }
static void tramplin_E0() { panic_handler(0XE0); }
static void tramplin_E1() { panic_handler(0XE1); }
static void tramplin_E2() { panic_handler(0XE2); }
static void tramplin_E3() { panic_handler(0XE3); }
static void tramplin_E4() { panic_handler(0XE4); }
static void tramplin_E5() { panic_handler(0XE5); }
static void tramplin_E6() { panic_handler(0XE6); }
static void tramplin_E7() { panic_handler(0XE7); }
static void tramplin_E8() { panic_handler(0XE8); }
static void tramplin_E9() { panic_handler(0XE9); }
static void tramplin_EA() { panic_handler(0XEA); }
static void tramplin_EB() { panic_handler(0XEB); }
static void tramplin_EC() { panic_handler(0XEC); }
static void tramplin_ED() { panic_handler(0XED); }
static void tramplin_EE() { panic_handler(0XEE); }
static void tramplin_EF() { panic_handler(0XEF); }
static void tramplin_F0() { panic_handler(0XF0); }
static void tramplin_F1() { panic_handler(0XF1); }
static void tramplin_F2() { panic_handler(0XF2); }
static void tramplin_F3() { panic_handler(0XF3); }
static void tramplin_F4() { panic_handler(0XF4); }
static void tramplin_F5() { panic_handler(0XF5); }
static void tramplin_F6() { panic_handler(0XF6); }
static void tramplin_F7() { panic_handler(0XF7); }
static void tramplin_F8() { panic_handler(0XF8); }
static void tramplin_F9() { panic_handler(0XF9); }
static void tramplin_FA() { panic_handler(0XFA); }
static void tramplin_FB() { panic_handler(0XFB); }
static void tramplin_FC() { panic_handler(0XFC); }
static void tramplin_FD() { panic_handler(0XFD); }
static void tramplin_FE() { panic_handler(0XFE); }
static void tramplin_FF() { panic_handler(0XFF); }
