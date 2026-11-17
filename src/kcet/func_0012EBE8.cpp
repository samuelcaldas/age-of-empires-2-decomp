#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012EBE8(void *a0) {
    .word 0x3c020050 // 0012EBE8: lui $v0, 0x50
    .word 0x27bdfff0 // 0012EBEC: addiu $sp, $sp, -0x10
    .word 0x8c4397dc // 0012EBF0: lw $v1, -0x6824($v0)
    .word 0x0080282d // 0012EBF4: move $a1, $a0
    .word 0xffbf0000 // 0012EBF8: sd $ra, ($sp)
    .word 0x1060000b // 0012EBFC: beqz $v1, 0x12ec2c
    .word 0x0000102d // 0012EC00: move $v0, $zero
    .word 0x88a20023 // 0012EC04: lwl $v0, 0x23($a1)
    .word 0x98a20020 // 0012EC08: lwr $v0, 0x20($a1)
    .word 0x3c04ffff // 0012EC0C: lui $a0, 0xffff
    .word 0x0004203e // 0012EC10: dsrl32 $a0, $a0, 0
    .word 0x24a5000c // 0012EC14: addiu $a1, $a1, 0xc
    .word 0x0c04c19c // 0012EC18: jal 0x130670
    .word 0x00442024 // 0012EC1C: and $a0, $v0, $a0
    .word 0x2403ff81 // 0012EC20: addiu $v1, $zero, -0x7f
    .word 0x0002180a // 0012EC24: movz $v1, $zero, $v0
    .word 0x0060102d // 0012EC28: move $v0, $v1
    .word 0xdfbf0000 // 0012EC2C: ld $ra, ($sp)
    .word 0x03e00008 // 0012EC30: jr $ra
    .word 0x27bd0010 // 0012EC34: addiu $sp, $sp, 0x10
}
#else

extern volatile s32 D_004F97DC;
s32 func_00130670(u32 a0, void *a1);

s32 func_0012EBE8(u8 *a0) {
    if (D_004F97DC == 0) {
        return 0;
    }
    u32 magic = *(u32 *)(a0 + 0x20);
    s32 res = func_00130670(magic & 0xFFFF0000, a0 + 0xC);
    if (res != 0) {
        return -0x7F;
    }
    return 0;
}

#endif

}
