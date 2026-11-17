#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E0B8(s32 arg0) {
    .word 0x27bdfff0 // 0012E0B8:  addiu $sp, $sp, -0x10
    .word 0x3c020050 // 0012E0BC:  lui $v0, 0x50
    .word 0xafa40000 // 0012E0C0:  sw $a0, ($sp)
    .word 0x244297d8 // 0012E0C4:  addiu $v0, $v0, -0x6828
    .word 0x8ba30003 // 0012E0C8:  lwl $v1, 3($sp)
    .word 0x9ba30000 // 0012E0CC:  lwr $v1, ($sp)
    .word 0xa8430023 // 0012E0D0:  swl $v1, 0x23($v0)
    .word 0xb8430020 // 0012E0D4:  swr $v1, 0x20($v0)
    .word 0x03e00008 // 0012E0D8:  jr $ra
    .word 0x27bd0010 // 0012E0DC:  addiu $sp, $sp, 0x10
}
#else

extern s32 D_004F97F8;

void func_0012E0B8(s32 arg0) {
    D_004F97F8 = arg0;
}

#endif

}
