#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct sceGsDispEnv {
    u64 pmode;
    u64 smode2;
    u64 dispfb;
    u64 display;
    u64 pad;
};

struct GsModeInfo {
    s16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
};

extern "C" {

GsModeInfo *func_00102818(void);

#if defined(__mips__)
asm void func_00102B00(const sceGsDispEnv *env) {
    .word 0x27bdffe0
    .word 0xffb00000
    .word 0xffbf0010
    .word 0x0c040a06
    .word 0x0080802d
    .word 0x84430006
    .word 0x24020001
    .word 0x14620011
    .word 0xde040000
    .word 0x3c021200
    .word 0x3c031200
    .word 0x3c061200
    .word 0xfc440000
    .word 0x34630070
    .word 0x34c60080
    .word 0x3c041200
    .word 0xde050010
    .word 0x348400c0
    .word 0xfc650000
    .word 0xde020018
    .word 0xfcc20000
    .word 0xde030020
    .word 0xfc830000
    .word 0x10000014
    .word 0xdfbf0010
    .word 0x3c031200
    .word 0x3c021200
    .word 0x3c061200
    .word 0xfc640000
    .word 0x34420020
    .word 0x34c60090
    .word 0x3c051200
    .word 0xde030008
    .word 0x34a500a0
    .word 0x3c041200
    .word 0xfc430000
    .word 0x348400e0
    .word 0xde020010
    .word 0xfcc20000
    .word 0xde030018
    .word 0xfca30000
    .word 0xde020020
    .word 0xfc820000
    .word 0xdfbf0010
    .word 0xdfb00000
    .word 0x03e00008
    .word 0x27bd0020
}
#else
void func_00102B00(const sceGsDispEnv *env) {
    if (func_00102818()->field_6 == 1) {
        *(volatile u64 *)0x12000000 = env->pmode;
        *(volatile u64 *)0x12000070 = env->dispfb;
        *(volatile u64 *)0x12000080 = env->display;
        *(volatile u64 *)0x120000c0 = env->pad;
    } else {
        *(volatile u64 *)0x12000000 = env->pmode;
        *(volatile u64 *)0x12000020 = env->smode2;
        *(volatile u64 *)0x12000090 = env->dispfb;
        *(volatile u64 *)0x120000a0 = env->display;
        *(volatile u64 *)0x120000e0 = env->pad;
    }
}
#endif

}
