#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012E190(const s32* ptr) {
    .word 0x10800002 // 0012E190:  beqz $a0, 0x12e19c
    .word 0x0000102d // 0012E194:  move $v0, $zero
    .word 0x8c820004 // 0012E198:  lw $v0, 4($a0)
    .word 0x03e00008 // 0012E19c:  jr $ra
    .word 0x00000000 // 0012E1a0:  nop 
}
#else

s32 func_0012E190(const s32* ptr) {
    if (!ptr) {
        return 0;
    }
    return ptr[1];
}

#endif

}
