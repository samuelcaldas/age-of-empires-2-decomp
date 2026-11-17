#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

s32 func_0012FA08(s32 a0);
void func_118de0(const char *fmt, ...);
s32 func_0012E448(u32 a0);
s32 func_001305D0(void *a0, s32 a1);

extern const char D_00490390[];

#if defined(__mips__)
asm s32 func_001304D0(s32 a0, s32 a1, s32 a2, s32 *a3, s32 t0, void *t1) {
    .word 0x27bdffb0
    .word 0xffb30030
    .word 0xffb20020
    .word 0x0000982d
    .word 0xffb10010
    .word 0x0120902d
    .word 0xffb00000
    .word 0x00e0882d
    .word 0xffbf0040
    .word 0x0080802d
    .word 0x0c04be82
    .word 0x8e240000
    .word 0x1200002a
    .word 0x0040282d
    .word 0x1e000006
    .word 0x24020001
    .word 0x2402ffff
    .word 0x12020022
    .word 0x0260102d
    .word 0x10000025
    .word 0xdfbf0040
    .word 0x16020022
    .word 0x0260102d
    .word 0x2402fff6
    .word 0x10a2000d
    .word 0x2413ff82
    .word 0x28a2fff6
    .word 0x14400005
    .word 0x3c040049
    .word 0x1ca00003
    .word 0x28a2fffe
    .word 0x10400018
    .word 0x0260102d
    .word 0x0c046378
    .word 0x24840390
    .word 0x2403fff7
    .word 0x10000012
    .word 0xae230000
    .word 0x8a42000f
    .word 0x9a42000c
    .word 0x3c04ffff
    .word 0x0004203e
    .word 0x0c04b912
    .word 0x00442024
    .word 0x24030002
    .word 0x1443000a
    .word 0x0260102d
    .word 0x0240202d
    .word 0x0c04c174
    .word 0x2405fff6
    .word 0x10000004
    .word 0x0040982d
    .word 0x2402fff7
    .word 0x2413ff82
    .word 0xae220000
    .word 0x0260102d
    .word 0xdfbf0040
    .word 0xdfb30030
    .word 0xdfb20020
    .word 0xdfb10010
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0050
}
#else
s32 func_001304D0(s32 a0, s32 a1, s32 a2, s32 *a3, s32 t0, void *t1) {
    s32 s3 = 0;
    void *s2 = t1;
    s32 *s1 = a3;
    s32 s0 = a0;

    s32 r = func_0012FA08(*s1);
    if (s0 == 0) {
        return s3;
    }
    if (s0 > 0) {
        if (s0 != 1) {
            return s3;
        }
        if (r == -10) {
            u32 val = *(u32*)((char*)s2 + 12);
            if (func_0012E448(val) == 2) {
                return func_001305D0(s2, -10);
            }
            return s3;
        }
        if (r < -10 || r > 0 || r < -2) {
            func_118de0(D_00490390);
            *s1 = -9;
            return s3;
        }
        return s3;
    }
    if (s0 == -1) {
        *s1 = -9;
        return -0x7e;
    }
    return s3;
}
#endif

}
