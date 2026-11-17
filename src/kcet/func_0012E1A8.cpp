#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012E1A8(const s32* ptr) {
    .word 0x10800002 // 0012E1A8:  beqz $a0, 0x12e1b4
    .word 0x0000102d // 0012E1AC:  move $v0, $zero
    .word 0x8c820008 // 0012E1B0:  lw $v0, 8($a0)
    .word 0x03e00008 // 0012E1B4:  jr $ra
    .word 0x00000000 // 0012E1B8:  nop 
}
#else

s32 func_0012E1A8(const s32* ptr) {
    if (!ptr) {
        return 0;
    }
    return ptr[2];
}

#endif

}
