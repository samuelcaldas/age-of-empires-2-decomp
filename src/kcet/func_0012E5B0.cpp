#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm u32 func_0012E5B0(u32 a0) {
    .word 0x03e00008 // 0012E5B0:  jr $ra
    .word 0x0080102d // 0012E5B4:  move $v0, $a0
}
#else
u32 func_0012E5B0(u32 a0) {
    return a0;
}
#endif

}
