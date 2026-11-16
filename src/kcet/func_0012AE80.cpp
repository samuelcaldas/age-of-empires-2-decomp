/* Function: func_0012AE80 (0x0012AE80 - 0x0012B0F8)
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
asm s32 func_0012AE80(void *a0, s32 *a1, s32 *a2) {
    .word 0x27bdff70 // addiu $sp, $sp, -0x90
    .word 0xffb70070 // sd $s7, 0x70($sp)
    .word 0xffb60060 // sd $s6, 0x60($sp)
    .word 0x00c0b82d // move $s7, $a2
    .word 0xffb50050 // sd $s5, 0x50($sp)
    .word 0x00a0b02d // move $s6, $a1
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0x0000a82d // move $s5, $zero
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0080 // sd $ra, 0x80($sp)
    .word 0x0080802d // move $s0, $a0
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x8ed10000 // lw $s1, ($s6)
    .word 0x0c04b40e // jal 0x12d038
    .word 0x8ef40000 // lw $s4, ($s7)
    .word 0x0040902d // move $s2, $v0
    .word 0x0c04b3d6 // jal 0x12cf58
    .word 0x0200202d // move $a0, $s0
    .word 0x0c04a810 // jal 0x12a040
    .word 0x0040982d // move $s3, $v0
    .word 0x10400011 // beqz $v0, 0x12af20
    .word 0x00000000 // nop
    .word 0x0c04b534 // jal 0x12d4d0
    .word 0x0200202d // move $a0, $s0
    .word 0x1040000d // beqz $v0, 0x12af20
    .word 0x00000000 // nop
    .word 0x56400007 // bnel $s2, $zero, 0x12af10
    .word 0x24110002 // addiu $s1, $zero, 2
    .word 0x0c04b3a8 // jal 0x12cea0
    .word 0x0200202d // move $a0, $s0
    .word 0x24030001 // addiu $v1, $zero, 1
    .word 0x14430004 // bne $v0, $v1, 0x12af18
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x24110002 // addiu $s1, $zero, 2
    .word 0x10000003 // b 0x12af20
    .word 0x24140001 // addiu $s4, $zero, 1
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fc08 // addiu $a0, $a0, -0x3f8
    .word 0x0c04b3a8 // jal 0x12cea0
    .word 0x0200202d // move $a0, $s0
    .word 0x0040182d // move $v1, $v0
    .word 0x24040001 // addiu $a0, $zero, 1
    .word 0x10640019 // beq $v1, $a0, 0x12af98
    .word 0x28620002 // slti $v0, $v1, 2
    .word 0x10400005 // beqz $v0, 0x12af50
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0x10600007 // beqz $v1, 0x12af60
    .word 0x00000000 // nop
    .word 0x1000005d // b 0x12b0c0
    .word 0x24150001 // addiu $s5, $zero, 1
    .word 0x10620038 // beq $v1, $v0, 0x12b034
    .word 0x00000000 // nop
    .word 0x10000059 // b 0x12b0c0
    .word 0x24150001 // addiu $s5, $zero, 1
    .word 0x16240003 // bne $s1, $a0, 0x12af70
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0x12600006 // beqz $s3, 0x12af84
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x56220054 // bnel $s1, $v0, 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x56400052 // bnel $s2, $zero, 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x24150001 // addiu $s5, $zero, 1
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fc28 // addiu $a0, $a0, -0x3d8
    .word 0x1000004c // b 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x0c04b316 // jal 0x12cc58
    .word 0x0200202d // move $a0, $s0
    .word 0x1040000e // beqz $v0, 0x12afdc
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0x56400008 // bnel $s2, $zero, 0x12afcc
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c06004e // lui $a2, 0x4e
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x24c62c70 // addiu $a2, $a2, 0x2c70
    .word 0x0c0450c8 // jal 0x114320
    .word 0x24050899 // addiu $a1, $zero, 0x899
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x24110002 // addiu $s1, $zero, 2
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fc50 // addiu $a0, $a0, -0x3b0
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0x56220039 // bnel $s1, $v0, 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x12400008 // beqz $s2, 0x12b008
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x52600007 // beql $s3, $zero, 0x12b00c
    .word 0x24110002 // addiu $s1, $zero, 2
    .word 0x0c04a834 // jal 0x12a0d0
    .word 0x00000000 // nop
    .word 0x54400031 // bnel $v0, $zero, 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x24110002 // addiu $s1, $zero, 2
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fc78 // addiu $a0, $a0, -0x388
    .word 0x5680002b // bnel $s4, $zero, 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x24140001 // addiu $s4, $zero, 1
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fcb0 // addiu $a0, $a0, -0x350
    .word 0x10000025 // b 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x0c04b31e // jal 0x12cc78
    .word 0x0200202d // move $a0, $s0
    .word 0x1040000e // beqz $v0, 0x12b078
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0x56600008 // bnel $s3, $zero, 0x12b068
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c06004e // lui $a2, 0x4e
    .word 0x2484f500 // addiu $a0, $a0, -0xb00
    .word 0x24c62c78 // addiu $a2, $a2, 0x2c78
    .word 0x0c0450c8 // jal 0x114320
    .word 0x240508aa // addiu $a1, $zero, 0x8aa
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x24110001 // addiu $s1, $zero, 1
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fcc8 // addiu $a0, $a0, -0x338
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0x56220012 // bnel $s1, $v0, 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x56400010 // bnel $s2, $zero, 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x24110001 // addiu $s1, $zero, 1
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fcf0 // addiu $a0, $a0, -0x310
    .word 0x5691000a // bnel $s4, $s1, 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x0c04a834 // jal 0x12a0d0
    .word 0x00000000 // nop
    .word 0x54400006 // bnel $v0, $zero, 0x12b0c4
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x0000a02d // move $s4, $zero
    .word 0x0c046378 // jal 0x118de0
    .word 0x2484fd30 // addiu $a0, $a0, -0x2d0
    .word 0xaed10000 // sw $s1, ($s6)
    .word 0x02a0102d // move $v0, $s5
    .word 0xaef40000 // sw $s4, ($s7)
    .word 0xdfbf0080 // ld $ra, 0x80($sp)
    .word 0xdfb70070 // ld $s7, 0x70($sp)
    .word 0xdfb60060 // ld $s6, 0x60($sp)
    .word 0xdfb50050 // ld $s5, 0x50($sp)
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0090 // addiu $sp, $sp, 0x90
}
#else

void func_118de0(const char *, ...);
void func_114320(const char *, int, const char *);
s32 func_0012A0D0(void);
s32 func_0012A040(void);
s32 func_12D038(void *);
s32 func_12CF58(void *);
s32 func_12D4D0(void *);
s32 func_12CEA0(void *);
s32 func_0012CC58(void *);
s32 func_0012CC78(void *);

extern const char D_48FC08[];
extern const char D_48FC28[];
extern const char D_48F500[];
extern const char D_48FC50[];
extern const char D_48FC78[];
extern const char D_48FCB0[];
extern const char D_48FCC8[];
extern const char D_48FCF0[];
extern const char D_48FD30[];
extern const char D_4E2C70[];
extern const char D_4E2C78[];

s32 func_0012AE80(void *a0, s32 *a1, s32 *a2) {
    s32 s1 = *a1;
    s32 s4 = *a2;
    s32 s5 = 0;
    s32 s2 = func_12D038(a0);
    s32 s3 = func_12CF58(a0);

    if (func_0012A040() != 0 && func_12D4D0(a0) != 0) {
        if (s2 != 0) {
            s1 = 2;
            s4 = 1;
        } else {
            if (func_12CEA0(a0) == 1) {
                s1 = 2;
                s4 = 1;
            } else {
                func_118de0(D_48FC08);
            }
        }
    }

    switch (func_12CEA0(a0)) {
    case 1:
        if (func_0012CC58(a0) != 0) {
            if (s2 == 0) {
                func_114320(D_48F500, 0x899, D_4E2C70);
            }
            s1 = 2;
            func_118de0(D_48FC50);
        }
        if (s1 == 1) {
            if (s2 == 0 || (s3 != 0 && func_0012A0D0() == 0)) {
                s1 = 2;
                func_118de0(D_48FC78);
                if (s4 == 0) {
                    s4 = 1;
                    func_118de0(D_48FCB0);
                }
            }
        }
        break;

    case 2:
        if (func_0012CC78(a0) != 0) {
            if (s3 == 0) {
                func_114320(D_48F500, 0x8AA, D_4E2C78);
            }
            s1 = 1;
            func_118de0(D_48FCC8);
        }
        if (s1 == 2) {
            if (s2 == 0) {
                s1 = 1;
                func_118de0(D_48FCF0);
                if (s4 == s1 && func_0012A0D0() == 0) {
                    s4 = 0;
                    func_118de0(D_48FD30);
                }
            }
        }
        break;

    case 0:
        if (s1 == 1) {
            if (s3 != 0) {
                break;
            }
        } else if (s1 == 2) {
            if (s2 != 0) {
                break;
            }
        }
        s5 = 1;
        func_118de0(D_48FC28);
        break;

    default:
        s5 = 1;
        break;
    }

    *a1 = s1;
    *a2 = s4;
    return s5;
}

#endif

}
