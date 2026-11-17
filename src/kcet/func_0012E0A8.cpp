#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E0A8(s32 arg0) {
    .word 0x3c020050 // 0012E0A8:  lui $v0, 0x50
    .word 0x03e00008 // 0012E0AC:  jr $ra
    .word 0xac4497f4 // 0012E0B0:  sw $a0, -0x680c($v0)
}
#else

extern s32 D_004F97F4;

void func_0012E0A8(s32 arg0) {
    D_004F97F4 = arg0;
}

#endif

}
