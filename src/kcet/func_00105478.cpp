#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

#if defined(__mips__)
asm s32 func_00105478(void) {
    .word 0x27bdfff0 // 00105478:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0010547C:  sd $ra, ($sp)
    .word 0x0c04564a // 00105480:  jal 0x115928
    .word 0x00000000 // 00105484:  nop 
    .word 0x24030005 // 00105488:  addiu $v1, $zero, 5
    .word 0xdfbf0000 // 0010548C:  ld $ra, ($sp)
    .word 0xac430000 // 00105490:  sw $v1, ($v0)
    .word 0x2402ffff // 00105494:  addiu $v0, $zero, -1
    .word 0x03e00008 // 00105498:  jr $ra
    .word 0x27bd0010 // 0010549C:  addiu $sp, $sp, 0x10
}
#else
s32* func_00115928(void);

s32 func_00105478(void) {
    s32* ptr = func_00115928();
    *ptr = 5;
    return -1;
}
#endif

}
