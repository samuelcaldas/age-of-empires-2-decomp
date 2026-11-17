#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

void func_00110C00(void);
s32 func_0012FA60(s32 a0, void *a1);

#if defined(__mips__)
asm s32 func_0012FC18(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, void *t2) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0x0000102d // move $v0, $zero
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x2403ffff // addiu $v1, $zero, -1
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x10830005 // beq $a0, $v1, 0x12fc44
    .word 0x0140802d // move $s0, $t2
    .word 0x50a30004 // beql $a1, $v1, 0x12fc48
    .word 0x0200282d // move $a1, $s0
    .word 0x0c044300 // jal 0x110c00
    .word 0x00000000 // nop
    .word 0x0200282d // move $a1, $s0
    .word 0x0c04be98 // jal 0x12fa60
    .word 0x0040202d // move $a0, $v0
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else
s32 func_0012FC18(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, void *t2) {
    if (a0 != -1 && a1 != -1) {
        func_00110C00();
    }
    return func_0012FA60(0, t2);
}
#endif

}
