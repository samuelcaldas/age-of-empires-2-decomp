typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

#if defined(__mips__)
asm s32 func_00105338(void) {
    .word 0x27bdfff0 // 00105338:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0010533C:  sd $ra, ($sp)
    .word 0x0c04564a // 00105340:  jal 0x115928
    .word 0x00000000 // 00105344:  nop 
    .word 0x24030005 // 00105348:  addiu $v1, $zero, 5
    .word 0xdfbf0000 // 0010534C:  ld $ra, ($sp)
    .word 0xac430000 // 00105350:  sw $v1, ($v0)
    .word 0x2402ffff // 00105354:  addiu $v0, $zero, -1
    .word 0x03e00008 // 00105358:  jr $ra
    .word 0x27bd0010 // 0010535C:  addiu $sp, $sp, 0x10
}
#else
s32* func_00115928(void);

s32 func_00105338(void) {
    s32* ptr = func_00115928();
    *ptr = 5;
    return -1;
}
#endif

}
