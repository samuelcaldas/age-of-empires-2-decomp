#pragma exceptions off

typedef signed short s16;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned int u32;

struct Struct_12EFD8 {
    u16 unk0;
    s16 field_4;
    s16 field_6;
};

extern "C" {

void func_0012EFB0(Struct_12EFD8 *s, s32 a1);

#if defined(__mips__)
asm void func_0012EFD8(Struct_12EFD8 *s, s32 a1, s32 a2) {
    .word 0x27bdffd0
    .word 0xffb10010
    .word 0xffbf0020
    .word 0x0080882d
    .word 0x04c00005
    .word 0xffb00000
    .word 0x24100001
    .word 0x24020002
    .word 0x10000017
    .word 0x0046800a
    .word 0x2402ffff
    .word 0x10a2000c
    .word 0x24100001
    .word 0x04a10005
    .word 0x2402fffe
    .word 0x10a20007
    .word 0x2410ffff
    .word 0x10000007
    .word 0x86220004
    .word 0x14a00004
    .word 0x2410ffff
    .word 0x10000002
    .word 0x0000802d
    .word 0x24100002
    .word 0x86220004
    .word 0x10400007
    .word 0x28a2fffe
    .word 0x16000005
    .word 0x00000000
    .word 0x86220006
    .word 0x00021027
    .word 0x2c500001
    .word 0x28a2fffe
    .word 0x54400006
    .word 0x2405ffff
    .word 0x04a20004
    .word 0x24050001
    .word 0x14a00002
    .word 0x2405ffff
    .word 0x0000282d
    .word 0x50a00004
    .word 0xa6300006
    .word 0x0c04bbec
    .word 0x0220202d
    .word 0xa6300006
    .word 0xdfbf0020
    .word 0xdfb10010
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0030
}
#else
void func_0012EFD8(Struct_12EFD8 *s, s32 a1, s32 a2) {
    s32 s0;
    if (a2 < 0) {
        if (a1 == -1) {
            s0 = 1;
        } else if (a1 < 0) {
            s0 = (a1 == -2) ? 2 : -1;
        } else if (a1 == 0) {
            s0 = 0;
        } else {
            s0 = -1;
        }
        if (s->field_4 != 0 && s0 == 0) {
            s0 = (s->field_6 == -1) ? 1 : 0;
        }
    } else {
        s0 = (a2 == 0) ? 2 : 1;
    }
    if (a1 < -2) {
        a1 = -1;
    } else if (a1 < 0) {
        a1 = 1;
    } else if (a1 != 0) {
        a1 = -1;
    } else {
        a1 = 0;
    }
    if (a1 != 0) {
        func_0012EFB0(s, a1);
    }
    s->field_6 = (s16)s0;
}
#endif

}
