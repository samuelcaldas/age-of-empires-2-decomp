#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012EE20(void *a0, void *a1) {
    .word 0x27bdff70 // 0012EE20:  addiu $sp, $sp, -0x90
    .word 0xffb70070 // 0012EE24:  sd $s7, 0x70($sp)
    .word 0xffb60060 // 0012EE28:  sd $s6, 0x60($sp)
    .word 0x2417ff81 // 0012EE2C:  addiu $s7, $zero, -0x7f
    .word 0xffb50050 // 0012EE30:  sd $s5, 0x50($sp)
    .word 0x2416ff80 // 0012EE34:  addiu $s6, $zero, -0x80
    .word 0xffb40040 // 0012EE38:  sd $s4, 0x40($sp)
    .word 0x2415ff82 // 0012EE3C:  addiu $s5, $zero, -0x7e
    .word 0xffb30030 // 0012EE40:  sd $s3, 0x30($sp)
    .word 0x00a0a02d // 0012EE44:  move $s4, $a1
    .word 0xffb10010 // 0012EE48:  sd $s1, 0x10($sp)
    .word 0x0000982d // 0012EE4C:  move $s3, $zero
    .word 0xffbf0080 // 0012EE50:  sd $ra, 0x80($sp)
    .word 0x0080882d // 0012EE54:  move $s1, $a0
    .word 0xffb20020 // 0012EE58:  sd $s2, 0x20($sp)
    .word 0xffb00000 // 0012EE5C:  sd $s0, ($sp)
    .word 0x8e300004 // 0012EE60:  lw $s0, 4($s1)
    .word 0x00101880 // 0012EE64:  sll $v1, $s0, 2
    .word 0x0220202d // 0012EE68:  move $a0, $s1
    .word 0x00741821 // 0012EE6C:  addu $v1, $v1, $s4
    .word 0x0000902d // 0012EE70:  move $s2, $zero
    .word 0x8c620000 // 0012EE74:  lw $v0, ($v1)
    .word 0x0040f809 // 0012EE78:  jalr $v0
    .word 0xae2200ac // 0012EE7C:  sw $v0, 0xac($s1)
    .word 0x0040182d // 0012EE80:  move $v1, $v0
    .word 0x1077000e // 0012EE84:  beq $v1, $s7, 0x12eec0
    .word 0x2862ff82 // 0012EE88:  slti $v0, $v1, -0x7e
    .word 0x10400005 // 0012EE8C:  beqz $v0, 0x12eea4
    .word 0x00000000 // 0012EE90:  nop 
    .word 0x5076000d // 0012EE94:  beql $v1, $s6, 0x12eecc
    .word 0x2413ff80 // 0012EE98:  addiu $s3, $zero, -0x80
    .word 0x10000006 // 0012EE9C:  b 0x12eeb8
    .word 0x02038021 // 0012EEA0:  addu $s0, $s0, $v1
    .word 0x50750008 // 0012EEA4:  beql $v1, $s5, 0x12eec8
    .word 0x26100001 // 0012EEA8:  addiu $s0, $s0, 1
    .word 0x10600007 // 0012EEAC:  beqz $v1, 0x12eecc
    .word 0x00000000 // 0012EEB0:  nop 
    .word 0x02038021 // 0012EEB4:  addu $s0, $s0, $v1
    .word 0x10000004 // 0012EEB8:  b 0x12eecc
    .word 0x24120001 // 0012EEBC:  addiu $s2, $zero, 1
    .word 0x10000002 // 0012EEC0:  b 0x12eecc
    .word 0x26100001 // 0012EEC4:  addiu $s0, $s0, 1
    .word 0x24120001 // 0012EEC8:  addiu $s2, $zero, 1
    .word 0x1640ffe6 // 0012EECC:  bnez $s2, 0x12ee68
    .word 0x00101880 // 0012EED0:  sll $v1, $s0, 2
    .word 0x8e230008 // 0012EED4:  lw $v1, 8($s1)
    .word 0x0260102d // 0012EED8:  move $v0, $s3
    .word 0xae300004 // 0012EEDC:  sw $s0, 4($s1)
    .word 0x24630001 // 0012EEE0:  addiu $v1, $v1, 1
    .word 0xdfbf0080 // 0012EEE4:  ld $ra, 0x80($sp)
    .word 0xae230008 // 0012EEE8:  sw $v1, 8($s1)
    .word 0xdfb70070 // 0012EEEC:  ld $s7, 0x70($sp)
    .word 0xdfb60060 // 0012EEF0:  ld $s6, 0x60($sp)
    .word 0xdfb50050 // 0012EEF4:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012EEF8:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012EEFC:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012EF00:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012EF04:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012EF08:  ld $s0, ($sp)
    .word 0x03e00008 // 0012EF0C:  jr $ra
    .word 0x27bd0090 // 0012EF10:  addiu $sp, $sp, 0x90
}
#else

struct TargetContext {
    u32 unk0;
    s32 index;
    s32 count;
    u8 pad[0xac - 0x0c];
    void *current_fn;
};

typedef s32 (*StepFn)(TargetContext *ctx);

s32 func_0012EE20(TargetContext *ctx, StepFn *table) {
    s32 status = 0;
    s32 index = ctx->index;
    s32 repeat;

    do {
        repeat = 0;
        StepFn fn = table[index];
        ctx->current_fn = (void *)fn;
        s32 res = fn(ctx);

        if (res == -0x7f) {
            index++;
        } else if (res < -0x7e) {
            if (res == -0x80) {
                status = -0x80;
            } else {
                index += res;
                repeat = 1;
            }
        } else {
            if (res == -0x7e) {
                index++;
                repeat = 1;
            } else if (res == 0) {
            } else {
                index += res;
                repeat = 1;
            }
        }
    } while (repeat != 0);

    ctx->index = index;
    ctx->count++;
    return status;
}

#endif

}
