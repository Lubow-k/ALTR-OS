#define IDT_SIZE 256
#include "printSource/print_functions.h"
#include "allocator/linear_alloc.h"


typedef unsigned char byte;
typedef unsigned short int u16;
typedef unsigned int u32;

void tramplin_0();
void tramplin_1();
void tramplin_2();
void tramplin_3();
void tramplin_4();
void tramplin_5();
void tramplin_6();
void tramplin_7();
void tramplin_8();
void tramplin_9();
void tramplin_A();
void tramplin_B();
void tramplin_C();
void tramplin_D();
void tramplin_E();
void tramplin_F();
void tramplin_10();
void tramplin_11();
void tramplin_12();
void tramplin_13();
void tramplin_14();
void tramplin_15();
void tramplin_16();
void tramplin_17();
void tramplin_18();
void tramplin_19();
void tramplin_1A();
void tramplin_1B();
void tramplin_1C();
void tramplin_1D();
void tramplin_1E();
void tramplin_1F();
void tramplin_20();
void tramplin_21();
void tramplin_22();
void tramplin_23();
void tramplin_24();
void tramplin_25();
void tramplin_26();
void tramplin_27();
void tramplin_28();
void tramplin_29();
void tramplin_2A();
void tramplin_2B();
void tramplin_2C();
void tramplin_2D();
void tramplin_2E();
void tramplin_2F();
void tramplin_30();
void tramplin_31();
void tramplin_32();
void tramplin_33();
void tramplin_34();
void tramplin_35();
void tramplin_36();
void tramplin_37();
void tramplin_38();
void tramplin_39();
void tramplin_3A();
void tramplin_3B();
void tramplin_3C();
void tramplin_3D();
void tramplin_3E();
void tramplin_3F();
void tramplin_40();
void tramplin_41();
void tramplin_42();
void tramplin_43();
void tramplin_44();
void tramplin_45();
void tramplin_46();
void tramplin_47();
void tramplin_48();
void tramplin_49();
void tramplin_4A();
void tramplin_4B();
void tramplin_4C();
void tramplin_4D();
void tramplin_4E();
void tramplin_4F();
void tramplin_50();
void tramplin_51();
void tramplin_52();
void tramplin_53();
void tramplin_54();
void tramplin_55();
void tramplin_56();
void tramplin_57();
void tramplin_58();
void tramplin_59();
void tramplin_5A();
void tramplin_5B();
void tramplin_5C();
void tramplin_5D();
void tramplin_5E();
void tramplin_5F();
void tramplin_60();
void tramplin_61();
void tramplin_62();
void tramplin_63();
void tramplin_64();
void tramplin_65();
void tramplin_66();
void tramplin_67();
void tramplin_68();
void tramplin_69();
void tramplin_6A();
void tramplin_6B();
void tramplin_6C();
void tramplin_6D();
void tramplin_6E();
void tramplin_6F();
void tramplin_70();
void tramplin_71();
void tramplin_72();
void tramplin_73();
void tramplin_74();
void tramplin_75();
void tramplin_76();
void tramplin_77();
void tramplin_78();
void tramplin_79();
void tramplin_7A();
void tramplin_7B();
void tramplin_7C();
void tramplin_7D();
void tramplin_7E();
void tramplin_7F();
void tramplin_80();
void tramplin_81();
void tramplin_82();
void tramplin_83();
void tramplin_84();
void tramplin_85();
void tramplin_86();
void tramplin_87();
void tramplin_88();
void tramplin_89();
void tramplin_8A();
void tramplin_8B();
void tramplin_8C();
void tramplin_8D();
void tramplin_8E();
void tramplin_8F();
void tramplin_90();
void tramplin_91();
void tramplin_92();
void tramplin_93();
void tramplin_94();
void tramplin_95();
void tramplin_96();
void tramplin_97();
void tramplin_98();
void tramplin_99();
void tramplin_9A();
void tramplin_9B();
void tramplin_9C();
void tramplin_9D();
void tramplin_9E();
void tramplin_9F();
void tramplin_A0();
void tramplin_A1();
void tramplin_A2();
void tramplin_A3();
void tramplin_A4();
void tramplin_A5();
void tramplin_A6();
void tramplin_A7();
void tramplin_A8();
void tramplin_A9();
void tramplin_AA();
void tramplin_AB();
void tramplin_AC();
void tramplin_AD();
void tramplin_AE();
void tramplin_AF();
void tramplin_B0();
void tramplin_B1();
void tramplin_B2();
void tramplin_B3();
void tramplin_B4();
void tramplin_B5();
void tramplin_B6();
void tramplin_B7();
void tramplin_B8();
void tramplin_B9();
void tramplin_BA();
void tramplin_BB();
void tramplin_BC();
void tramplin_BD();
void tramplin_BE();
void tramplin_BF();
void tramplin_C0();
void tramplin_C1();
void tramplin_C2();
void tramplin_C3();
void tramplin_C4();
void tramplin_C5();
void tramplin_C6();
void tramplin_C7();
void tramplin_C8();
void tramplin_C9();
void tramplin_CA();
void tramplin_CB();
void tramplin_CC();
void tramplin_CD();
void tramplin_CE();
void tramplin_CF();
void tramplin_D0();
void tramplin_D1();
void tramplin_D2();
void tramplin_D3();
void tramplin_D4();
void tramplin_D5();
void tramplin_D6();
void tramplin_D7();
void tramplin_D8();
void tramplin_D9();
void tramplin_DA();
void tramplin_DB();
void tramplin_DC();
void tramplin_DD();
void tramplin_DE();
void tramplin_DF();
void tramplin_E0();
void tramplin_E1();
void tramplin_E2();
void tramplin_E3();
void tramplin_E4();
void tramplin_E5();
void tramplin_E6();
void tramplin_E7();
void tramplin_E8();
void tramplin_E9();
void tramplin_EA();
void tramplin_EB();
void tramplin_EC();
void tramplin_ED();
void tramplin_EE();
void tramplin_EF();
void tramplin_F0();
void tramplin_F1();
void tramplin_F2();
void tramplin_F3();
void tramplin_F4();
void tramplin_F5();
void tramplin_F6();
void tramplin_F7();
void tramplin_F8();
void tramplin_F9();
void tramplin_FA();
void tramplin_FB();
void tramplin_FC();
void tramplin_FD();
void tramplin_FE();
void tramplin_FF();



#pragma pack(push, 1)
typedef struct {
    u16 low_16_bits;
    u16 segment_selector;
    u16 flags;
    u16 high_16_bits;
} descriptor;

typedef struct{
    u16 size;
    u32 data;
} didt;
#pragma pack(pop)

 void fill_gate_types(descriptor* idt, void** tramplins, int start_vector, int last_vector, u16 flag) {

     for (int vector = start_vector; vector < last_vector; vector++){
             byte* handler = tramplins[vector];
             u16 low_16_bits = (u16) handler;
             u16 high_16_bits = (u16) (((u32) handler) >> 16);
             u16 segment_selector = (u16) 8;
             u16 flags = flag;

             idt[vector].low_16_bits = low_16_bits;
             idt[vector].high_16_bits = high_16_bits;
             idt[vector].segment_selector = segment_selector;
             idt[vector].flags = flags;
     }
 }


void fill_tramplins() {
    void* tramplins[IDT_SIZE];
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

    fill_gate_types(idt, tramplins, 0, 32, 0x8E00);          // interrupts
    fill_gate_types(idt, tramplins, 32, IDT_SIZE, 0x8F00);   // traps

    didt* local_didt = (didt*) kernel_malloc(sizeof(didt));
    local_didt->size = (u16) (sizeof(descriptor) * IDT_SIZE - 1);
    local_didt->data = (u32) idt;
    
    asm ("lidt %0" :: "m"(*local_didt));
}

