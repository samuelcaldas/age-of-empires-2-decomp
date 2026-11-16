/* Function: func_0012A808 (0x0012A808 - 0x0012A9AC)
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
asm s32 func_0012A808(void *a0, s32 a1) {
    .word 0x27bdff90 // addiu $sp, $sp, -0x70
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0x0080882d // move $s1, $a0
    .word 0xffb50050 // sd $s5, 0x50($sp)
    .word 0x00a0a02d // move $s4, $a1
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x24150005 // addiu $s5, $zero, 5
    .word 0xffbf0060 // sd $ra, 0x60($sp)
    .word 0x0000902d // move $s2, $zero
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x0c04a838 // jal 0x12a0e0
    .word 0x0000982d // move $s3, $zero
    .word 0x2403ffff // addiu $v1, $zero, -1
    .word 0x0c04a83e // jal 0x12a0f8
    .word 0x0062a80a // movz $s5, $v1, $v0
    .word 0x02a2900a // movz $s2, $s5, $v0
    .word 0x10000009 // b 0x12a878
    .word 0x0240a82d // move $s5, $s2
    .word 0x1202004b // beq $s0, $v0, 0x12a988
    .word 0x0200102d // move $v0, $s0
    .word 0x1240004a // beqz $s2, 0x12a98c
    .word 0xdfbf0060 // ld $ra, 0x60($sp)
    .word 0x0c04aaa8 // jal 0x12aaa0
    .word 0x00000000 // nop
    .word 0x0012102a // slt $v0, $zero, $s2
    .word 0x02429023 // subu $s2, $s2, $v0
    .word 0x0c04b68e // jal 0x12da38
    .word 0x00000000 // nop
    .word 0x24030001 // addiu $v1, $zero, 1
    .word 0x1043003c // beq $v0, $v1, 0x12a978
    .word 0x24100005 // addiu $s0, $zero, 5
    .word 0x0c04a992 // jal 0x12a648
    .word 0x00000000 // nop
    .word 0x10400009 // beqz $v0, 0x12a8bc
    .word 0x00000000 // nop
    .word 0x0c04a994 // jal 0x12a650
    .word 0x00000000 // nop
    .word 0x10400034 // beqz $v0, 0x12a978
    .word 0x24100006 // addiu $s0, $zero, 6
    .word 0x0c04a9cc // jal 0x12a730
    .word 0x00000000 // nop
    .word 0x14400030 // bnez $v0, 0x12a978
    .word 0x24100007 // addiu $s0, $zero, 7
    .word 0x0c04a95e // jal 0x12a578
    .word 0x00000000 // nop
    .word 0x0040802d // move $s0, $v0
    .word 0x52000012 // beql $s0, $zero, 0x12a914
    .word 0x8e300014 // lw $s0, 0x14($s1)
    .word 0x26730001 // addiu $s3, $zero, 1 // wait, 26730001 is addiu $s3, $s3, 1
    .word 0x2a62001f // slti $v0, $s3, 0x1f
    .word 0x14400027 // bnez $v0, 0x12a978
    .word 0x02a0902d // move $s2, $s5
    .word 0x0c04b6d2 // jal 0x12db48
    .word 0x00000000 // nop
    .word 0x24030001 // addiu $v1, $zero, 1
    .word 0x14430022 // bne $v0, $v1, 0x12a978
    .word 0x0000202d // move $a0, $zero
    .word 0x0c04a53a // jal 0x1294e8
    .word 0x0000982d // move $s3, $zero
    .word 0x0c04b6b2 // jal 0x12dac8
    .word 0x00000000 // nop
    .word 0x0c04a53a // jal 0x1294e8
    .word 0x0000202d // move $a0, $zero
    .word 0x1000001a // b 0x12a978
    .word 0x02a0902d // move $s2, $s5
    .word 0x24020002 // addiu $v0, $zero, 2
    .word 0x16020011 // bne $s0, $v0, 0x12a960
    .word 0x00000000 // nop
    .word 0x0c04a860 // jal 0x12a180
    .word 0x0220202d // move $a0, $s1
    .word 0x0040182d // move $v1, $v0
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0x50620005 // beql $v1, $v0, 0x12a948
    .word 0x8e22004c // lw $v0, 0x4c($s1)
    .word 0x10700009 // beq $v1, $s0, 0x12a960
    .word 0x24100009 // addiu $s0, $zero, 9
    .word 0x1000000e // b 0x12a97c
    .word 0x0000902d // move $s2, $zero
    .word 0x8e230048 // lw $v1, 0x48($s1)
    .word 0x244207ff // addiu $v0, $v0, 0x7ff
    .word 0xae200028 // sw $zero, 0x28($s1)
    .word 0x000212c2 // srl $v0, $v0, 0xb
    .word 0xae230020 // sw $v1, 0x20($s1)
    .word 0xae220024 // sw $v0, 0x24($s1)
    .word 0x06800005 // bltz $s4, 0x12a978
    .word 0x24100001 // addiu $s0, $zero, 1
    .word 0xae340040 // sw $s4, 0x40($s1)
    .word 0x0c04a9ce // jal 0x12a738
    .word 0x0220202d // move $a0, $s1
    .word 0x0040802d // move $s0, $v0
    .word 0x24020001 // addiu $v0, $zero, 1
    .word 0x1602ffb6 // bne $s0, $v0, 0x12a858
    .word 0x24020004 // addiu $v0, $zero, 4
    .word 0x0200102d // move $v0, $s0
    .word 0xdfbf0060 // ld $ra, 0x60($sp)
    .word 0xdfb50050 // ld $s5, 0x50($sp)
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0070 // addiu $sp, $sp, 0x70
}
#else

struct TargetStruct {
    u8 pad0[0x14];
    s32 f_14;
    u8 pad14[0x8];
    s32 f_20;
    s32 f_24;
    s32 f_28;
    u8 pad2c[0x14];
    s32 f_40;
    u8 pad44[0x4];
    s32 f_48;
    s32 f_4c;
};

void func_0012A0E0(void);
s32 func_0012A0F8(void);
void func_0012AAA0(void);
s32 func_0012DA38(void);
s32 func_0012A648(void);
s32 func_0012A650(void);
s32 func_0012A730(void);
s32 func_0012A578(void);
s32 func_0012DB48(void);
void func_001294E8(s32);
void func_0012DAC8(void);
s32 func_0012A180(TargetStruct *);
s32 func_0012A738(TargetStruct *);

s32 func_0012A808(TargetStruct *a0, s32 a1) {
    s32 s5 = 5;
    s32 s2 = 0;
    s32 s3 = 0;
    s32 s0;

    func_0012A0E0();
    if (func_0012A0F8() == 0) {
        s5 = -1;
        s2 = -1;
    }

    for (;;) {
        if (func_0012DA38() == 1) {
            s0 = 5;
        } else {
            if (func_0012A648() != 0) {
                if (func_0012A650() == 0) {
                    s0 = 6;
                    goto check_end;
                }
                if (func_0012A730() != 0) {
                    s0 = 7;
                    goto check_end;
                }
            }

            s0 = func_0012A578();
            if (s0 == 0) {
                s0 = a0->f_14;
                s3++;
                if (s3 < 0x1f) {
                    s2 = s5;
                    goto check_end;
                }
                if (func_0012DB48() == 1) {
                    func_001294E8(0);
                    s3 = 0;
                    func_0012DAC8();
                    func_001294E8(0);
                }
                s2 = s5;
                goto check_end;
            }

            if (s0 == 2) {
                s32 v1 = func_0012A180(a0);
                if (v1 == 1) {
                    a0->f_28 = 0;
                    a0->f_20 = a0->f_48;
                    a0->f_24 = (a0->f_4c + 0x7ff) >> 11;
                } else if (v1 == s0) {
                    s0 = 9;
                    s2 = 0;
                    goto check_end;
                }
            }

            if (a1 < 0) {
                s0 = 1;
            } else {
                a0->f_40 = a1;
                s0 = func_0012A738(a0);
            }
        }

check_end:
        if (s0 != 1) {
            if (s0 == 4) {
                return s0;
            }
            if (s2 == 0) {
                return s0;
            }
            s5 = s2;
            func_0012AAA0();
            if (s2 > 0) {
                s2--;
            }
        }
    }
}

#endif

}
