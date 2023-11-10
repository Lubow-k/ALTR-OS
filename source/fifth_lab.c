#define IDT_SIZE 256
#include "printSource/print_functions.h"
#include "linear_alloc.h"

typedef unsigned char byte;
typedef unsigned short int u16;
typedef unsigned int u32;

void INT();
void STI();
void kernel_panic(char* fmt, ...);
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
typedef struct {  // Теперь в правильном порядке 
    u16 low_16_bits;
    u16 segment_selector;
    u16 flags;
    u16 high_16_bits;
} descriptor;

typedef struct{ // Тут тоже в правильном порядке 
    u16 size;
    u32 data;
} didt;
#pragma pack(pop)


void __main(){
    void** tramplins;
    tramplins = (void**) kernel_malloc(IDT_SIZE * sizeof(void*));
    tramplins[0] = tramplin_0;
    tramplins[1] = tramplin_1;
    tramplins[2] = tramplin_2;
    tramplins[3] = tramplin_3;
    tramplins[4] = tramplin_4;
    tramplins[5] = tramplin_5;
    tramplins[6] = tramplin_6;
    tramplins[7] = tramplin_7;
    tramplins[8] = tramplin_8;
    tramplins[9] = tramplin_9;
    tramplins[10] = tramplin_A;
    tramplins[11] = tramplin_B;
    tramplins[12] = tramplin_C;
    tramplins[13] = tramplin_D;
    tramplins[14] = tramplin_E;
    tramplins[15] = tramplin_F;
    tramplins[16] = tramplin_10;
    tramplins[17] = tramplin_11;
    tramplins[18] = tramplin_12;
    tramplins[19] = tramplin_13;
    tramplins[20] = tramplin_14;
    tramplins[21] = tramplin_15;
    tramplins[22] = tramplin_16;
    tramplins[23] = tramplin_17;
    tramplins[24] = tramplin_18;
    tramplins[25] = tramplin_19;
    tramplins[26] = tramplin_1A;
    tramplins[27] = tramplin_1B;
    tramplins[28] = tramplin_1C;
    tramplins[29] = tramplin_1D;
    tramplins[30] = tramplin_1E;
    tramplins[31] = tramplin_1F;
    tramplins[32] = tramplin_20;
    tramplins[33] = tramplin_21;
    tramplins[34] = tramplin_22;
    tramplins[35] = tramplin_23;
    tramplins[36] = tramplin_24;
    tramplins[37] = tramplin_25;
    tramplins[38] = tramplin_26;
    tramplins[39] = tramplin_27;
    tramplins[40] = tramplin_28;
    tramplins[41] = tramplin_29;
    tramplins[42] = tramplin_2A;
    tramplins[43] = tramplin_2B;
    tramplins[44] = tramplin_2C;
    tramplins[45] = tramplin_2D;
    tramplins[46] = tramplin_2E;
    tramplins[47] = tramplin_2F;
    tramplins[48] = tramplin_30;
    tramplins[49] = tramplin_31;
    tramplins[50] = tramplin_32;
    tramplins[51] = tramplin_33;
    tramplins[52] = tramplin_34;
    tramplins[53] = tramplin_35;
    tramplins[54] = tramplin_36;
    tramplins[55] = tramplin_37;
    tramplins[56] = tramplin_38;
    tramplins[57] = tramplin_39;
    tramplins[58] = tramplin_3A;
    tramplins[59] = tramplin_3B;
    tramplins[60] = tramplin_3C;
    tramplins[61] = tramplin_3D;
    tramplins[62] = tramplin_3E;
    tramplins[63] = tramplin_3F;
    tramplins[64] = tramplin_40;
    tramplins[65] = tramplin_41;
    tramplins[66] = tramplin_42;
    tramplins[67] = tramplin_43;
    tramplins[68] = tramplin_44;
    tramplins[69] = tramplin_45;
    tramplins[70] = tramplin_46;
    tramplins[71] = tramplin_47;
    tramplins[72] = tramplin_48;
    tramplins[73] = tramplin_49;
    tramplins[74] = tramplin_4A;
    tramplins[75] = tramplin_4B;
    tramplins[76] = tramplin_4C;
    tramplins[77] = tramplin_4D;
    tramplins[78] = tramplin_4E;
    tramplins[79] = tramplin_4F;
    tramplins[80] = tramplin_50;
    tramplins[81] = tramplin_51;
    tramplins[82] = tramplin_52;
    tramplins[83] = tramplin_53;
    tramplins[84] = tramplin_54;
    tramplins[85] = tramplin_55;
    tramplins[86] = tramplin_56;
    tramplins[87] = tramplin_57;
    tramplins[88] = tramplin_58;
    tramplins[89] = tramplin_59;
    tramplins[90] = tramplin_5A;
    tramplins[91] = tramplin_5B;
    tramplins[92] = tramplin_5C;
    tramplins[93] = tramplin_5D;
    tramplins[94] = tramplin_5E;
    tramplins[95] = tramplin_5F;
    tramplins[96] = tramplin_60;
    tramplins[97] = tramplin_61;
    tramplins[98] = tramplin_62;
    tramplins[99] = tramplin_63;
    tramplins[100] = tramplin_64;
    tramplins[101] = tramplin_65;
    tramplins[102] = tramplin_66;
    tramplins[103] = tramplin_67;
    tramplins[104] = tramplin_68;
    tramplins[105] = tramplin_69;
    tramplins[106] = tramplin_6A;
    tramplins[107] = tramplin_6B;
    tramplins[108] = tramplin_6C;
    tramplins[109] = tramplin_6D;
    tramplins[110] = tramplin_6E;
    tramplins[111] = tramplin_6F;
    tramplins[112] = tramplin_70;
    tramplins[113] = tramplin_71;
    tramplins[114] = tramplin_72;
    tramplins[115] = tramplin_73;
    tramplins[116] = tramplin_74;
    tramplins[117] = tramplin_75;
    tramplins[118] = tramplin_76;
    tramplins[119] = tramplin_77;
    tramplins[120] = tramplin_78;
    tramplins[121] = tramplin_79;
    tramplins[122] = tramplin_7A;
    tramplins[123] = tramplin_7B;
    tramplins[124] = tramplin_7C;
    tramplins[125] = tramplin_7D;
    tramplins[126] = tramplin_7E;
    tramplins[127] = tramplin_7F;
    tramplins[128] = tramplin_80;
    tramplins[129] = tramplin_81;
    tramplins[130] = tramplin_82;
    tramplins[131] = tramplin_83;
    tramplins[132] = tramplin_84;
    tramplins[133] = tramplin_85;
    tramplins[134] = tramplin_86;
    tramplins[135] = tramplin_87;
    tramplins[136] = tramplin_88;
    tramplins[137] = tramplin_89;
    tramplins[138] = tramplin_8A;
    tramplins[139] = tramplin_8B;
    tramplins[140] = tramplin_8C;
    tramplins[141] = tramplin_8D;
    tramplins[142] = tramplin_8E;
    tramplins[143] = tramplin_8F;
    tramplins[144] = tramplin_90;
    tramplins[145] = tramplin_91;
    tramplins[146] = tramplin_92;
    tramplins[147] = tramplin_93;
    tramplins[148] = tramplin_94;
    tramplins[149] = tramplin_95;
    tramplins[150] = tramplin_96;
    tramplins[151] = tramplin_97;
    tramplins[152] = tramplin_98;
    tramplins[153] = tramplin_99;
    tramplins[154] = tramplin_9A;
    tramplins[155] = tramplin_9B;
    tramplins[156] = tramplin_9C;
    tramplins[157] = tramplin_9D;
    tramplins[158] = tramplin_9E;
    tramplins[159] = tramplin_9F;
    tramplins[160] = tramplin_A0;
    tramplins[161] = tramplin_A1;
    tramplins[162] = tramplin_A2;
    tramplins[163] = tramplin_A3;
    tramplins[164] = tramplin_A4;
    tramplins[165] = tramplin_A5;
    tramplins[166] = tramplin_A6;
    tramplins[167] = tramplin_A7;
    tramplins[168] = tramplin_A8;
    tramplins[169] = tramplin_A9;
    tramplins[170] = tramplin_AA;
    tramplins[171] = tramplin_AB;
    tramplins[172] = tramplin_AC;
    tramplins[173] = tramplin_AD;
    tramplins[174] = tramplin_AE;
    tramplins[175] = tramplin_AF;
    tramplins[176] = tramplin_B0;
    tramplins[177] = tramplin_B1;
    tramplins[178] = tramplin_B2;
    tramplins[179] = tramplin_B3;
    tramplins[180] = tramplin_B4;
    tramplins[181] = tramplin_B5;
    tramplins[182] = tramplin_B6;
    tramplins[183] = tramplin_B7;
    tramplins[184] = tramplin_B8;
    tramplins[185] = tramplin_B9;
    tramplins[186] = tramplin_BA;
    tramplins[187] = tramplin_BB;
    tramplins[188] = tramplin_BC;
    tramplins[189] = tramplin_BD;
    tramplins[190] = tramplin_BE;
    tramplins[191] = tramplin_BF;
    tramplins[192] = tramplin_C0;
    tramplins[193] = tramplin_C1;
    tramplins[194] = tramplin_C2;
    tramplins[195] = tramplin_C3;
    tramplins[196] = tramplin_C4;
    tramplins[197] = tramplin_C5;
    tramplins[198] = tramplin_C6;
    tramplins[199] = tramplin_C7;
    tramplins[200] = tramplin_C8;
    tramplins[201] = tramplin_C9;
    tramplins[202] = tramplin_CA;
    tramplins[203] = tramplin_CB;
    tramplins[204] = tramplin_CC;
    tramplins[205] = tramplin_CD;
    tramplins[206] = tramplin_CE;
    tramplins[207] = tramplin_CF;
    tramplins[208] = tramplin_D0;
    tramplins[209] = tramplin_D1;
    tramplins[210] = tramplin_D2;
    tramplins[211] = tramplin_D3;
    tramplins[212] = tramplin_D4;
    tramplins[213] = tramplin_D5;
    tramplins[214] = tramplin_D6;
    tramplins[215] = tramplin_D7;
    tramplins[216] = tramplin_D8;
    tramplins[217] = tramplin_D9;
    tramplins[218] = tramplin_DA;
    tramplins[219] = tramplin_DB;
    tramplins[220] = tramplin_DC;
    tramplins[221] = tramplin_DD;
    tramplins[222] = tramplin_DE;
    tramplins[223] = tramplin_DF;
    tramplins[224] = tramplin_E0;
    tramplins[225] = tramplin_E1;
    tramplins[226] = tramplin_E2;
    tramplins[227] = tramplin_E3;
    tramplins[228] = tramplin_E4;
    tramplins[229] = tramplin_E5;
    tramplins[230] = tramplin_E6;
    tramplins[231] = tramplin_E7;
    tramplins[232] = tramplin_E8;
    tramplins[233] = tramplin_E9;
    tramplins[234] = tramplin_EA;
    tramplins[235] = tramplin_EB;
    tramplins[236] = tramplin_EC;
    tramplins[237] = tramplin_ED;
    tramplins[238] = tramplin_EE;
    tramplins[239] = tramplin_EF;
    tramplins[240] = tramplin_F0;
    tramplins[241] = tramplin_F1;
    tramplins[242] = tramplin_F2;
    tramplins[243] = tramplin_F3;
    tramplins[244] = tramplin_F4;
    tramplins[245] = tramplin_F5;
    tramplins[246] = tramplin_F6;
    tramplins[247] = tramplin_F7;
    tramplins[248] = tramplin_F8;
    tramplins[249] = tramplin_F9;
    tramplins[250] = tramplin_FA;
    tramplins[251] = tramplin_FB;
    tramplins[252] = tramplin_FC;
    tramplins[253] = tramplin_FD;
    tramplins[254] = tramplin_FE;
    tramplins[255] = tramplin_FF;

    descriptor* idt;
    idt = (descriptor*) kernel_malloc(IDT_SIZE * sizeof(descriptor));

    for (int vector = 0; vector < IDT_SIZE; vector++){
        byte* handler = tramplins[vector]; 
        u16 low_16_bits = (u16) handler;
        u16 high_16_bits = (u16) (((u32) handler) >> 16);
        u16 segment_selector = (u16) 8;      
        u16 flags = 0x8F00;

        idt[vector].low_16_bits = low_16_bits;
        idt[vector].high_16_bits = high_16_bits;
        idt[vector].segment_selector = segment_selector;
        idt[vector].flags = flags;
    }

    didt* local_didt = (didt*) kernel_malloc(sizeof(didt));
    local_didt->size = (u16) (sizeof(descriptor) * IDT_SIZE - 1);
    local_didt->data = (u32) idt;
    
    asm ("lidt %0" :: "m"(*local_didt));

    INT();
    // STI();
    // int a = 1 / 0;
    for (;;);
}

static void panic_handler(int vector){
    kernel_panic("unhandled interrupt %x", vector);
}

static void tramplin_0() { panic_handler(0x0); }
static void tramplin_1() { panic_handler(0x1); }
static void tramplin_2() { panic_handler(0x2); }
static void tramplin_3() { panic_handler(0x3); }
static void tramplin_4() { panic_handler(0x4); }
static void tramplin_5() { panic_handler(0x5); }
static void tramplin_6() { panic_handler(0x6); }
static void tramplin_7() { panic_handler(0x7); }
static void tramplin_8() { panic_handler(0x8); }
static void tramplin_9() { panic_handler(0x9); }
static void tramplin_A() { panic_handler(0xa); }
static void tramplin_B() { panic_handler(0xb); }
static void tramplin_C() { panic_handler(0xc); }
static void tramplin_D() { panic_handler(0xd); }
static void tramplin_E() { panic_handler(0xe); }
static void tramplin_F() { panic_handler(0xf); }
static void tramplin_10() { panic_handler(0x10); }
static void tramplin_11() { panic_handler(0x11); }
static void tramplin_12() { panic_handler(0x12); }
static void tramplin_13() { panic_handler(0x13); }
static void tramplin_14() { panic_handler(0x14); }
static void tramplin_15() { panic_handler(0x15); }
static void tramplin_16() { panic_handler(0x16); }
static void tramplin_17() { panic_handler(0x17); }
static void tramplin_18() { panic_handler(0x18); }
static void tramplin_19() { panic_handler(0x19); }
static void tramplin_1A() { panic_handler(0x1a); }
static void tramplin_1B() { panic_handler(0x1b); }
static void tramplin_1C() { panic_handler(0x1c); }
static void tramplin_1D() { panic_handler(0x1d); }
static void tramplin_1E() { panic_handler(0x1e); }
static void tramplin_1F() { panic_handler(0x1f); }
static void tramplin_20() { panic_handler(0x20); }
static void tramplin_21() { panic_handler(0x21); }
static void tramplin_22() { panic_handler(0x22); }
static void tramplin_23() { panic_handler(0x23); }
static void tramplin_24() { panic_handler(0x24); }
static void tramplin_25() { panic_handler(0x25); }
static void tramplin_26() { panic_handler(0x26); }
static void tramplin_27() { panic_handler(0x27); }
static void tramplin_28() { panic_handler(0x28); }
static void tramplin_29() { panic_handler(0x29); }
static void tramplin_2A() { panic_handler(0x2a); }
static void tramplin_2B() { panic_handler(0x2b); }
static void tramplin_2C() { panic_handler(0x2c); }
static void tramplin_2D() { panic_handler(0x2d); }
static void tramplin_2E() { panic_handler(0x2e); }
static void tramplin_2F() { panic_handler(0x2f); }
static void tramplin_30() { panic_handler(0x30); }
static void tramplin_31() { panic_handler(0x31); }
static void tramplin_32() { panic_handler(0x32); }
static void tramplin_33() { panic_handler(0x33); }
static void tramplin_34() { panic_handler(0x34); }
static void tramplin_35() { panic_handler(0x35); }
static void tramplin_36() { panic_handler(0x36); }
static void tramplin_37() { panic_handler(0x37); }
static void tramplin_38() { panic_handler(0x38); }
static void tramplin_39() { panic_handler(0x39); }
static void tramplin_3A() { panic_handler(0x3a); }
static void tramplin_3B() { panic_handler(0x3b); }
static void tramplin_3C() { panic_handler(0x3c); }
static void tramplin_3D() { panic_handler(0x3d); }
static void tramplin_3E() { panic_handler(0x3e); }
static void tramplin_3F() { panic_handler(0x3f); }
static void tramplin_40() { panic_handler(0x40); }
static void tramplin_41() { panic_handler(0x41); }
static void tramplin_42() { panic_handler(0x42); }
static void tramplin_43() { panic_handler(0x43); }
static void tramplin_44() { panic_handler(0x44); }
static void tramplin_45() { panic_handler(0x45); }
static void tramplin_46() { panic_handler(0x46); }
static void tramplin_47() { panic_handler(0x47); }
static void tramplin_48() { panic_handler(0x48); }
static void tramplin_49() { panic_handler(0x49); }
static void tramplin_4A() { panic_handler(0x4a); }
static void tramplin_4B() { panic_handler(0x4b); }
static void tramplin_4C() { panic_handler(0x4c); }
static void tramplin_4D() { panic_handler(0x4d); }
static void tramplin_4E() { panic_handler(0x4e); }
static void tramplin_4F() { panic_handler(0x4f); }
static void tramplin_50() { panic_handler(0x50); }
static void tramplin_51() { panic_handler(0x51); }
static void tramplin_52() { panic_handler(0x52); }
static void tramplin_53() { panic_handler(0x53); }
static void tramplin_54() { panic_handler(0x54); }
static void tramplin_55() { panic_handler(0x55); }
static void tramplin_56() { panic_handler(0x56); }
static void tramplin_57() { panic_handler(0x57); }
static void tramplin_58() { panic_handler(0x58); }
static void tramplin_59() { panic_handler(0x59); }
static void tramplin_5A() { panic_handler(0x5a); }
static void tramplin_5B() { panic_handler(0x5b); }
static void tramplin_5C() { panic_handler(0x5c); }
static void tramplin_5D() { panic_handler(0x5d); }
static void tramplin_5E() { panic_handler(0x5e); }
static void tramplin_5F() { panic_handler(0x5f); }
static void tramplin_60() { panic_handler(0x60); }
static void tramplin_61() { panic_handler(0x61); }
static void tramplin_62() { panic_handler(0x62); }
static void tramplin_63() { panic_handler(0x63); }
static void tramplin_64() { panic_handler(0x64); }
static void tramplin_65() { panic_handler(0x65); }
static void tramplin_66() { panic_handler(0x66); }
static void tramplin_67() { panic_handler(0x67); }
static void tramplin_68() { panic_handler(0x68); }
static void tramplin_69() { panic_handler(0x69); }
static void tramplin_6A() { panic_handler(0x6a); }
static void tramplin_6B() { panic_handler(0x6b); }
static void tramplin_6C() { panic_handler(0x6c); }
static void tramplin_6D() { panic_handler(0x6d); }
static void tramplin_6E() { panic_handler(0x6e); }
static void tramplin_6F() { panic_handler(0x6f); }
static void tramplin_70() { panic_handler(0x70); }
static void tramplin_71() { panic_handler(0x71); }
static void tramplin_72() { panic_handler(0x72); }
static void tramplin_73() { panic_handler(0x73); }
static void tramplin_74() { panic_handler(0x74); }
static void tramplin_75() { panic_handler(0x75); }
static void tramplin_76() { panic_handler(0x76); }
static void tramplin_77() { panic_handler(0x77); }
static void tramplin_78() { panic_handler(0x78); }
static void tramplin_79() { panic_handler(0x79); }
static void tramplin_7A() { panic_handler(0x7a); }
static void tramplin_7B() { panic_handler(0x7b); }
static void tramplin_7C() { panic_handler(0x7c); }
static void tramplin_7D() { panic_handler(0x7d); }
static void tramplin_7E() { panic_handler(0x7e); }
static void tramplin_7F() { panic_handler(0x7f); }
static void tramplin_80() { panic_handler(0x80); }
static void tramplin_81() { panic_handler(0x81); }
static void tramplin_82() { panic_handler(0x82); }
static void tramplin_83() { panic_handler(0x83); }
static void tramplin_84() { panic_handler(0x84); }
static void tramplin_85() { panic_handler(0x85); }
static void tramplin_86() { panic_handler(0x86); }
static void tramplin_87() { panic_handler(0x87); }
static void tramplin_88() { panic_handler(0x88); }
static void tramplin_89() { panic_handler(0x89); }
static void tramplin_8A() { panic_handler(0x8a); }
static void tramplin_8B() { panic_handler(0x8b); }
static void tramplin_8C() { panic_handler(0x8c); }
static void tramplin_8D() { panic_handler(0x8d); }
static void tramplin_8E() { panic_handler(0x8e); }
static void tramplin_8F() { panic_handler(0x8f); }
static void tramplin_90() { panic_handler(0x90); }
static void tramplin_91() { panic_handler(0x91); }
static void tramplin_92() { panic_handler(0x92); }
static void tramplin_93() { panic_handler(0x93); }
static void tramplin_94() { panic_handler(0x94); }
static void tramplin_95() { panic_handler(0x95); }
static void tramplin_96() { panic_handler(0x96); }
static void tramplin_97() { panic_handler(0x97); }
static void tramplin_98() { panic_handler(0x98); }
static void tramplin_99() { panic_handler(0x99); }
static void tramplin_9A() { panic_handler(0x9a); }
static void tramplin_9B() { panic_handler(0x9b); }
static void tramplin_9C() { panic_handler(0x9c); }
static void tramplin_9D() { panic_handler(0x9d); }
static void tramplin_9E() { panic_handler(0x9e); }
static void tramplin_9F() { panic_handler(0x9f); }
static void tramplin_A0() { panic_handler(0xa0); }
static void tramplin_A1() { panic_handler(0xa1); }
static void tramplin_A2() { panic_handler(0xa2); }
static void tramplin_A3() { panic_handler(0xa3); }
static void tramplin_A4() { panic_handler(0xa4); }
static void tramplin_A5() { panic_handler(0xa5); }
static void tramplin_A6() { panic_handler(0xa6); }
static void tramplin_A7() { panic_handler(0xa7); }
static void tramplin_A8() { panic_handler(0xa8); }
static void tramplin_A9() { panic_handler(0xa9); }
static void tramplin_AA() { panic_handler(0xaa); }
static void tramplin_AB() { panic_handler(0xab); }
static void tramplin_AC() { panic_handler(0xac); }
static void tramplin_AD() { panic_handler(0xad); }
static void tramplin_AE() { panic_handler(0xae); }
static void tramplin_AF() { panic_handler(0xaf); }
static void tramplin_B0() { panic_handler(0xb0); }
static void tramplin_B1() { panic_handler(0xb1); }
static void tramplin_B2() { panic_handler(0xb2); }
static void tramplin_B3() { panic_handler(0xb3); }
static void tramplin_B4() { panic_handler(0xb4); }
static void tramplin_B5() { panic_handler(0xb5); }
static void tramplin_B6() { panic_handler(0xb6); }
static void tramplin_B7() { panic_handler(0xb7); }
static void tramplin_B8() { panic_handler(0xb8); }
static void tramplin_B9() { panic_handler(0xb9); }
static void tramplin_BA() { panic_handler(0xba); }
static void tramplin_BB() { panic_handler(0xbb); }
static void tramplin_BC() { panic_handler(0xbc); }
static void tramplin_BD() { panic_handler(0xbd); }
static void tramplin_BE() { panic_handler(0xbe); }
static void tramplin_BF() { panic_handler(0xbf); }
static void tramplin_C0() { panic_handler(0xc0); }
static void tramplin_C1() { panic_handler(0xc1); }
static void tramplin_C2() { panic_handler(0xc2); }
static void tramplin_C3() { panic_handler(0xc3); }
static void tramplin_C4() { panic_handler(0xc4); }
static void tramplin_C5() { panic_handler(0xc5); }
static void tramplin_C6() { panic_handler(0xc6); }
static void tramplin_C7() { panic_handler(0xc7); }
static void tramplin_C8() { panic_handler(0xc8); }
static void tramplin_C9() { panic_handler(0xc9); }
static void tramplin_CA() { panic_handler(0xca); }
static void tramplin_CB() { panic_handler(0xcb); }
static void tramplin_CC() { panic_handler(0xcc); }
static void tramplin_CD() { panic_handler(0xcd); }
static void tramplin_CE() { panic_handler(0xce); }
static void tramplin_CF() { panic_handler(0xcf); }
static void tramplin_D0() { panic_handler(0xd0); }
static void tramplin_D1() { panic_handler(0xd1); }
static void tramplin_D2() { panic_handler(0xd2); }
static void tramplin_D3() { panic_handler(0xd3); }
static void tramplin_D4() { panic_handler(0xd4); }
static void tramplin_D5() { panic_handler(0xd5); }
static void tramplin_D6() { panic_handler(0xd6); }
static void tramplin_D7() { panic_handler(0xd7); }
static void tramplin_D8() { panic_handler(0xd8); }
static void tramplin_D9() { panic_handler(0xd9); }
static void tramplin_DA() { panic_handler(0xda); }
static void tramplin_DB() { panic_handler(0xdb); }
static void tramplin_DC() { panic_handler(0xdc); }
static void tramplin_DD() { panic_handler(0xdd); }
static void tramplin_DE() { panic_handler(0xde); }
static void tramplin_DF() { panic_handler(0xdf); }
static void tramplin_E0() { panic_handler(0xe0); }
static void tramplin_E1() { panic_handler(0xe1); }
static void tramplin_E2() { panic_handler(0xe2); }
static void tramplin_E3() { panic_handler(0xe3); }
static void tramplin_E4() { panic_handler(0xe4); }
static void tramplin_E5() { panic_handler(0xe5); }
static void tramplin_E6() { panic_handler(0xe6); }
static void tramplin_E7() { panic_handler(0xe7); }
static void tramplin_E8() { panic_handler(0xe8); }
static void tramplin_E9() { panic_handler(0xe9); }
static void tramplin_EA() { panic_handler(0xea); }
static void tramplin_EB() { panic_handler(0xeb); }
static void tramplin_EC() { panic_handler(0xec); }
static void tramplin_ED() { panic_handler(0xed); }
static void tramplin_EE() { panic_handler(0xee); }
static void tramplin_EF() { panic_handler(0xef); }
static void tramplin_F0() { panic_handler(0xf0); }
static void tramplin_F1() { panic_handler(0xf1); }
static void tramplin_F2() { panic_handler(0xf2); }
static void tramplin_F3() { panic_handler(0xf3); }
static void tramplin_F4() { panic_handler(0xf4); }
static void tramplin_F5() { panic_handler(0xf5); }
static void tramplin_F6() { panic_handler(0xf6); }
static void tramplin_F7() { panic_handler(0xf7); }
static void tramplin_F8() { panic_handler(0xf8); }
static void tramplin_F9() { panic_handler(0xf9); }
static void tramplin_FA() { panic_handler(0xfa); }
static void tramplin_FB() { panic_handler(0xfb); }
static void tramplin_FC() { panic_handler(0xfc); }
static void tramplin_FD() { panic_handler(0xfd); }
static void tramplin_FE() { panic_handler(0xfe); }
static void tramplin_FF() { panic_handler(0xff); }