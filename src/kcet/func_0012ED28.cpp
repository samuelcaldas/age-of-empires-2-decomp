#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void *func_0012ED28(void *a0, s32 a1) {
    .word 0x27bdffb0 // 0012ED28:  addiu $sp, $sp, -0x50
    .word 0xffb20020 // 0012ED2C:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012ED30:  sd $s1, 0x10($sp)
    .word 0x00a0902d // 0012ED34:  move $s2, $a1
    .word 0xffb00000 // 0012ED38:  sd $s0, ($sp)
    .word 0x0080882d // 0012ED3C:  move $s1, $a0
    .word 0xffbf0040 // 0012ED40:  sd $ra, 0x40($sp)
    .word 0x0000802d // 0012ED44:  move $s0, $zero
    .word 0x1220001c // 0012ED48:  beqz $s1, 0x12edbc
    .word 0xffb30030 // 0012ED4C:  sd $s3, 0x30($sp)
    .word 0x3c130039 // 0012ED50:  lui $s3, 0x39
    .word 0x8e260018 // 0012ED54:  lw $a2, 0x18($s1)
    .word 0x8e64c8b0 // 0012ED58:  lw $a0, -0x3750($s3)
    .word 0x0c04bc82 // 0012ED5C:  jal 0x12f208
    .word 0x0220282d // 0012ED60:  move $a1, $s1
    .word 0x10400002 // 0012ED64:  beqz $v0, 0x12ed70
    .word 0x0000302d // 0012ED68:  move $a2, $zero
    .word 0x8c460018 // 0012ED6C:  lw $a2, 0x18($v0)
    .word 0x2e420005 // 0012ED70:  sltiu $v0, $s2, 5
    .word 0x10400011 // 0012ED74:  beqz $v0, 0x12edbc
    .word 0x3c020049 // 0012ED78:  lui $v0, 0x49
    .word 0x00121880 // 0012ED7C:  sll $v1, $s2, 2
    .word 0x24420270 // 0012ED80:  addiu $v0, $v0, 0x270
    .word 0x00621821 // 0012ED84:  addu $v1, $v1, $v0
    .word 0x8c640000 // 0012ED88:  lw $a0, ($v1)
    .word 0x00800008 // 0012ED8C:  jr $a0
    .word 0x00000000 // 0012ED90:  nop
    .word 0x10000009 // 0012ED94:  b 0x12edbc
    .word 0x0220802d // 0012ED98:  move $s0, $s1
    .word 0x10000007 // 0012ED9C:  b 0x12edbc
    .word 0x8e70c8b0 // 0012EDA0:  lw $s0, -0x3750($s3)
    .word 0x10000004 // 0012EDA4:  b 0x12edb8
    .word 0x24d00104 // 0012EDA8:  addiu $s0, $a2, 0x104
    .word 0x10000002 // 0012EDAC:  b 0x12edb8
    .word 0x24d00144 // 0012EDB0:  addiu $s0, $a2, 0x144
    .word 0x24d00184 // 0012EDB4:  addiu $s0, $a2, 0x184
    .word 0x0006800a // 0012EDB8:  movz $s0, $zero, $a2
    .word 0x0200102d // 0012EDBC:  move $v0, $s0
    .word 0xdfbf0040 // 0012EDC0:  ld $ra, 0x40($sp)
    .word 0xdfb30030 // 0012EDC4:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012EDC8:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012EDCC:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012EDD0:  ld $s0, ($sp)
    .word 0x03e00008 // 0012EDD4:  jr $ra
    .word 0x27bd0050 // 0012EDD8:  addiu $sp, $sp, 0x50
}
#else

extern const char *D_38C8B0[];
void *func_0012F208(const char *name, void *a1, s32 a2);

void *func_0012ED28(void *a0, s32 a1) {
    void *ret = 0;
    if (a0 == 0) {
        return 0;
    }

    s32 val = *(s32 *)((char *)a0 + 0x18);
    void *v0 = func_0012F208(D_38C8B0[0], a0, val);
    char *a2 = 0;
    if (v0 != 0) {
        a2 = *(char **)((char *)v0 + 0x18);
    }

    switch (a1) {
    case 0:
        ret = a0;
        break;
    case 1:
        ret = (void *)D_38C8B0[0];
        break;
    case 2:
        ret = a2 + 0x104;
        break;
    case 3:
        ret = a2 + 0x144;
        break;
    case 4:
        ret = a2 + 0x184;
        break;
    default:
        break;
    }

    if (a1 >= 2 && a1 <= 4) {
        if (a2 == 0) {
            ret = 0;
        }
    }
    return ret;
}

#endif

}
