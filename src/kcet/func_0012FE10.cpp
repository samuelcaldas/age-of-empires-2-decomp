#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

void func_0012FA20(void);
void func_0012FDE0(void*, void*);

#if defined(__mips__)
asm void func_0012FE10(void* a0, void* a1) {
    .word 0x27bdffd0 // addiu $sp, $sp, -0x30
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x00a0882d // move $s1, $a1
    .word 0xffbf0020 // sd $ra, 0x20($sp)
    .word 0x0c04be88 // jal 0x12fa20
    .word 0x0080802d // move $s0, $a0
    .word 0x3c020050 // lui $v0, 0x50
    .word 0x0200202d // move $a0, $s0
    .word 0xac509804 // sw $s0, -0x67fc($v0)
    .word 0x0c04bf78 // jal 0x12fde0
    .word 0x0220282d // move $a1, $s1
    .word 0xdfbf0020 // ld $ra, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0030 // addiu $sp, $sp, 0x30
}
#else
extern void* D_004F9804;

void func_0012FE10(void* a0, void* a1) {
    func_0012FA20();
    D_004F9804 = a0;
    func_0012FDE0(a0, a1);
}
#endif

}
