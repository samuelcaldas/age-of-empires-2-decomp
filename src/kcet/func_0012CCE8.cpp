/* Function: func_0012CCE8 (0x0012CCE8 - 0x0012CDDC)
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
asm s32 func_0012CCE8(void *a0) {
    .word 0x27bdff70 // 0012cce8:  addiu $sp, $sp, -0x90
    .word 0xffb50050 // 0012ccec:  sd $s5, 0x50($sp)
    .word 0xffb20020 // 0012ccf0:  sd $s2, 0x20($sp)
    .word 0x3c15004f // 0012ccf4:  lui $s5, 0x4f
    .word 0xffb60060 // 0012ccf8:  sd $s6, 0x60($sp)
    .word 0x3c127fff // 0012ccfc:  lui $s2, 0x7fff
    .word 0xffb40040 // 0012cd00:  sd $s4, 0x40($sp)
    .word 0x3652ffff // 0012cd04:  ori $s2, $s2, 0xffff
    .word 0xffb30030 // 0012cd08:  sd $s3, 0x30($sp)
    .word 0x0000a02d // 0012cd0c:  move $s4, $zero
    .word 0xffbf0080 // 0012cd10:  sd $ra, 0x80($sp)
    .word 0x0080982d // 0012cd14:  move $s3, $a0
    .word 0xffb70070 // 0012cd18:  sd $s7, 0x70($sp)
    .word 0xffb10010 // 0012cd1c:  sd $s1, 0x10($sp)
    .word 0xffb00000 // 0012cd20:  sd $s0, ($sp)
    .word 0x12600017 // 0012cd24:  beqz $s3, 0x12cd84
    .word 0x8eb61508 // 0012cd28:  lw $s6, 0x1508($s5)
    .word 0x96620000 // 0012cd2c:  lhu $v0, ($s3)
    .word 0x10400008 // 0012cd30:  beqz $v0, 0x12cd54
    .word 0x3c170049 // 0012cd34:  lui $s7, 0x49
    .word 0x26940001 // 0012cd38:  addiu $s4, $s4, 1
    .word 0x001410c0 // 0012cd3c:  sll $v0, $s4, 3
    .word 0x00531021 // 0012cd40:  addu $v0, $v0, $s3
    .word 0x94430000 // 0012cd44:  lhu $v1, ($v0)
    .word 0x00000000 // 0012cd48:  nop
    .word 0x1460fffa // 0012cd4c:  bnez $v1, 0x12cd38
    .word 0x00000000 // 0012cd50:  nop
    .word 0x1a80000c // 0012cd54:  blez $s4, 0x12cd88
    .word 0x0260882d // 0012cd58:  move $s1, $s3
    .word 0x0280802d // 0012cd5c:  move $s0, $s4
    .word 0x0220202d // 0012cd60:  move $a0, $s1
    .word 0x0c04b2d8 // 0012cd64:  jal 0x12cb60
    .word 0x2610ffff // 0012cd68:  addiu $s0, $s0, -1
    .word 0x26310008 // 0012cd6c:  addiu $s1, $s1, 8
    .word 0x0052182a // 0012cd70:  slt $v1, $v0, $s2
    .word 0x1600fffa // 0012cd74:  bnez $s0, 0x12cd60
    .word 0x0043900b // 0012cd78:  movn $s2, $v0, $v1
    .word 0x10000003 // 0012cd7c:  b 0x12cd8c
    .word 0x26a21508 // 0012cd80:  addiu $v0, $s5, 0x1508
    .word 0x3c170049 // 0012cd84:  lui $s7, 0x49
    .word 0x26a21508 // 0012cd88:  addiu $v0, $s5, 0x1508
    .word 0xaeb31508 // 0012cd8c:  sw $s3, 0x1508($s5)
    .word 0xac520008 // 0012cd90:  sw $s2, 8($v0)
    .word 0x26e4fe38 // 0012cd94:  addiu $a0, $s7, -0x1c8
    .word 0x0260282d // 0012cd98:  move $a1, $s3
    .word 0x0280302d // 0012cd9c:  move $a2, $s4
    .word 0x0240382d // 0012cda0:  move $a3, $s2
    .word 0x0c046378 // 0012cda4:  jal 0x118de0
    .word 0xac540004 // 0012cda8:  sw $s4, 4($v0)
    .word 0x02c0102d // 0012cdac:  move $v0, $s6
    .word 0xdfbf0080 // 0012cdb0:  ld $ra, 0x80($sp)
    .word 0xdfb70070 // 0012cdb4:  ld $s7, 0x70($sp)
    .word 0xdfb60060 // 0012cdb8:  ld $s6, 0x60($sp)
    .word 0xdfb50050 // 0012cdbc:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012cdc0:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012cdc4:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012cdc8:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012cdcc:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012cdd0:  ld $s0, ($sp)
    .word 0x03e00008 // 0012cdd4:  jr $ra
    .word 0x27bd0090 // 0012cdd8:  addiu $sp, $sp, 0x90
}
#else

s32 func_0012CB60(void *p);
void func_118de0(void *a0, void *a1, s32 a2, s32 a3);

struct UnknownGlobal {
    void *ptr;
    s32 count;
    s32 min_val;
};

extern UnknownGlobal D_004F1508;
extern u8 D_0048FE38[];

s32 func_0012CCE8(void *arg0) {
    u16 *p = (u16 *)arg0;
    s32 min_val = 0x7fffffff;
    s32 count = 0;
    void *old_ptr = D_004F1508.ptr;

    if (p != 0) {
        if (*p != 0) {
            do {
                count++;
            } while (*(u16 *)((u8 *)p + count * 8) != 0);
        }
        if (count > 0) {
            u8 *curr = (u8 *)p;
            for (s32 i = count; i > 0; i--) {
                s32 v = func_0012CB60(curr);
                curr += 8;
                if (v < min_val) {
                    min_val = v;
                }
            }
        }
    }

    D_004F1508.ptr = arg0;
    D_004F1508.count = count;
    D_004F1508.min_val = min_val;

    func_118de0(D_0048FE38, arg0, count, min_val);

    return (s32)old_ptr;
}

#endif

}
