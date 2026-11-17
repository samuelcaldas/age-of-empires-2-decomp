#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012E178(const s32* ptr) {
    .word 0x10800002 // 0012E178:  beqz $a0, 0x12e184
    .word 0x24020001 // 0012E17C:  addiu $v0, $zero, 1
    .word 0x8c820000 // 0012E180:  lw $v0, ($a0)
    .word 0x03e00008 // 0012E184:  jr $ra
    .word 0x00000000 // 0012E188:  nop 
}
#else

s32 func_0012E178(const s32* ptr) {
    if (!ptr) {
        return 1;
    }
    return *ptr;
}

#endif

}
