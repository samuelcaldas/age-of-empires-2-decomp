#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012E5B8(void) {
    .word 0x27bdfff0 // 0012E5B8:  addiu $sp, $sp, -0x10
    .word 0xffbf0000 // 0012E5BC:  sd $ra, ($sp)
    .word 0x0c04bb2a // 0012E5C0:  jal 0x12eca8
    .word 0x00000000 // 0012E5C4:  nop
    .word 0xdfbf0000 // 0012E5C8:  ld $ra, ($sp)
    .word 0x03e00008 // 0012E5CC:  jr $ra
    .word 0x27bd0010 // 0012E5D0:  addiu $sp, $sp, 0x10
}
#else

void func_0012ECA8(void);

void func_0012E5B8(void) {
    func_0012ECA8();
}

#endif

}
