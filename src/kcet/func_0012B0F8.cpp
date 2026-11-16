/* Function: func_0012B0F8 (0x0012B0F8 - 0x0012B220)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012B0F8(void *a0) {
    .word 0x27bdffa0 // addiu $sp, $sp, -0x60
    .word 0xffb30040 // sd $s3, 0x40($sp)
    .word 0xffbf0050 // sd $ra, 0x50($sp)
    .word 0x27b30004 // addiu $s3, $sp, 4
    .word 0xffb20030 // sd $s2, 0x30($sp)
    .word 0xffb00010 // sd $s0, 0x10($sp)
    .word 0xffb10020 // sd $s1, 0x20($sp)
    .word 0x8c910000 // lw $s1, ($a0)
    .word 0x8c920004 // lw $s2, 4($a0)
    .word 0x8e220014 // lw $v0, 0x14($s1)
    .word 0x8e230018 // lw $v1, 0x18($s1)
    .word 0xafa20000 // sw $v0, ($sp)
    .word 0xafa30004 // sw $v1, 4($sp)
    .word 0x0240202d // move $a0, $s2
    .word 0x03a0282d // move $a1, $sp
    .word 0x0c04aba0 // jal 0x12ae80
    .word 0x0260302d // move $a2, $s3
    .word 0x14400030 // bnez $v0, 0x12b200
    .word 0x24100008 // addiu $s0, $zero, 8
    .word 0x8fa30000 // lw $v1, ($sp)
    .word 0x0240202d // move $a0, $s2
    .word 0xae230014 // sw $v1, 0x14($s1)
    .word 0x8fa20004 // lw $v0, 4($sp)
    .word 0x0c04b40e // jal 0x12d038
    .word 0xae220018 // sw $v0, 0x18($s1)
    .word 0xae22002c // sw $v0, 0x2c($s1)
    .word 0x0c04b3d6 // jal 0x12cf58
    .word 0x0240202d // move $a0, $s2
    .word 0x0040202d // move $a0, $v0
    .word 0x26250020 // addiu $a1, $s1, 0x20
    .word 0x0c04b2ea // jal 0x12cba8
    .word 0x26260024 // addiu $a2, $s1, 0x24
    .word 0x8fa30004 // lw $v1, 4($sp)
    .word 0x10600010 // beqz $v1, 0x12b1c0
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0x1062000a // beq $v1, $v0, 0x12b1b0
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fd68 // addiu $a0, $a0, -0x298
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c06004e // lui $a2, 0x4e
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x24c62c58 // addiu $a2, $a2, 0x2c58
    .word 0x0c0450c8 // jal 0x114320
    .word 0x240508db // addiu $a1, $zero, 0x8db
    .word 0x00000000 // nop
    .word 0x0c04aa6c // jal 0x12a9b0
    .word 0x0220202d // move $a0, $s1
    .word 0x10000004 // b 0x12b1cc
    .word 0x00000000 // nop
    .word 0x0220202d // move $a0, $s1
    .word 0x0c04aa02 // jal 0x12a808
    .word 0x24050001 // addiu $a1, $zero, 1
    .word 0x0c04a83e // jal 0x12a0f8
    .word 0x0040802d // move $s0, $v0
    .word 0x1040000a // beqz $v0, 0x12b200
    .word 0x8fa20004 // lw $v0, 4($sp)
    .word 0x14400008 // bnez $v0, 0x12b200
    .word 0x24030001 // addiu $v1, $zero, 1
    .word 0x12030006 // beq $s0, $v1, 0x12b200
    .word 0x24020004 // addiu $v0, $zero, 4
    .word 0x12020004 // beq $s0, $v0, 0x12b200
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0xafa30004 // sw $v1, 4($sp)
    .word 0x1000ffcc // b 0x12b12c
    .word 0xafa20000 // sw $v0, ($sp)
    .word 0x0200102d // move $v0, $s0
    .word 0xdfbf0050 // ld $ra, 0x50($sp)
    .word 0xdfb30040 // ld $s3, 0x40($sp)
    .word 0xdfb20030 // ld $s2, 0x30($sp)
    .word 0xdfb10020 // ld $s1, 0x20($sp)
    .word 0xdfb00010 // ld $s0, 0x10($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0060 // addiu $sp, $sp, 0x60
}
#else

struct TargetStruct {
    u8 pad0[0x14];
    s32 f_14;
    s32 f_18;
    u8 pad1c[0x4];
    s32 f_20;
    s32 f_24;
    u8 pad28[0x4];
    s32 f_2c;
};

struct ArgStruct {
    TargetStruct *s1;
    void *s2;
};

s32 func_0012AE80(void *s2, s32 *sp_val, s32 *s3);
s32 func_0012D038(void *s2);
s32 func_0012CF58(void *s2);
void func_0012CBA8(s32 v0, s32 *p20, s32 *p24);
void func_118de0(const char *, ...);
void func_114320(const char *, int, const char *);
void func_0012A9B0(TargetStruct *s1);
void func_0012A808(TargetStruct *s1, s32 one);
s32 func_0012A0F8(void);

extern const char D_48FD68[];
extern const char D_48F500[];
extern const char D_4E2C58[];

s32 func_0012B0F8(ArgStruct *a0) {
    TargetStruct *s1 = a0->s1;
    void *s2 = a0->s2;
    s32 sp[2];
    s32 s0;

    sp[0] = s1->f_14;
    sp[1] = s1->f_18;

    while (1) {
        if (func_0012AE80(s2, sp, &sp[1]) != 0) {
            return s0;
        }
        s0 = 8;
        s1->f_14 = sp[0];
        s32 v0_d038 = func_0012D038(s2);
        s1->f_18 = v0_d038;
        s1->f_2c = v0_d038;
        s32 v0_cf58 = func_0012CF58(s2);
        func_0012CBA8(v0_cf58, &s1->f_20, &s1->f_24);
        if (sp[1] == 0) {
            func_0012A808(s1, 1);
        } else if (sp[1] == 1) {
            func_0012A9B0(s1);
        } else {
            func_118de0(D_48FD68);
            func_114320(D_48F500, 0x8db, D_4E2C58);
            func_0012A9B0(s1);
        }
        s0 = func_0012A0F8();
        if (s0 == 0 || sp[1] != 0 || s0 == 1 || s0 == 4) {
            break;
        }
        sp[1] = 1;
        sp[0] = 2;
    }
    return s0;
}

#endif

}
