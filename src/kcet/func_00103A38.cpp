#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

struct sceDmaEnv {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u16 e;
    u16 f;
    u16 g;
    u16 h;
    u32 i;
    u32 j;
};

#pragma options align=packed
struct sceDmaEnvRaw {
    u8 raw[0x14];
};
#pragma options align=reset

extern "C" {

#if defined(__mips__)
asm s32 func_00103A38(const sceDmaEnv *env) {
    .word 0x3c021000 // 00103A38:  lui $v0, 0x1000
    .word 0x3c031000 // 00103A3C:  lui $v1, 0x1000
    .word 0x3442e000 // 00103A40:  ori $v0, $v0, 0xe000
    .word 0x3463e020 // 00103A44:  ori $v1, $v1, 0xe020
    .word 0x8c4a0000 // 00103A48:  lw $t2, ($v0)
    .word 0x3c051000 // 00103A4C:  lui $a1, 0x1000
    .word 0x8c660000 // 00103A50:  lw $a2, ($v1)
    .word 0x0080482d // 00103A54:  move $t1, $a0
    .word 0x34a5e030 // 00103A58:  ori $a1, $a1, 0xe030
    .word 0x3c031000 // 00103A5C:  lui $v1, 0x1000
    .word 0x8ca50000 // 00103A60:  lw $a1, ($a1)
    .word 0x3463e050 // 00103A64:  ori $v1, $v1, 0xe050
    .word 0x3c021000 // 00103A68:  lui $v0, 0x1000
    .word 0x91240000 // 00103A6C:  lbu $a0, ($t1)
    .word 0x8c660000 // 00103A70:  lw $a2, ($v1)
    .word 0x3442e040 // 00103A74:  ori $v0, $v0, 0xe040
    .word 0x8c480000 // 00103A78:  lw $t0, ($v0)
    .word 0x2c84000a // 00103A7C:  sltiu $a0, $a0, 0xa
    .word 0x54800003 // 00103A80:  bnel $a0, $zero, 0x103a90
    .word 0x91220001 // 00103A84:  lbu $v0, 1($t1)
    .word 0x03e00008 // 00103A88:  jr $ra
    .word 0x2402ffff // 00103A8C:  addiu $v0, $zero, -1
    .word 0x2c42000a // 00103A90:  sltiu $v0, $v0, 0xa
    .word 0x54400003 // 00103A94:  bnel $v0, $zero, 0x103aa4
    .word 0x91220002 // 00103A98:  lbu $v0, 2($t1)
    .word 0x03e00008 // 00103A9C:  jr $ra
    .word 0x2402fffe // 00103AA0:  addiu $v0, $zero, -2
    .word 0x2c42000a // 00103AA4:  sltiu $v0, $v0, 0xa
    .word 0x54400003 // 00103AA8:  bnel $v0, $zero, 0x103ab8
    .word 0x912b0003 // 00103AAC:  lbu $t3, 3($t1)
    .word 0x03e00008 // 00103AB0:  jr $ra
    .word 0x2402fffd // 00103AB4:  addiu $v0, $zero, -3
    .word 0x2d620007 // 00103AB8:  sltiu $v0, $t3, 7
    .word 0x14400003 // 00103ABC:  bnez $v0, 0x103acc
    .word 0x3c020039 // 00103AC0:  lui $v0, 0x39
    .word 0x03e00008 // 00103AC4:  jr $ra
    .word 0x2402fffc // 00103AC8:  addiu $v0, $zero, -4
    .word 0x91230000 // 00103ACC:  lbu $v1, ($t1)
    .word 0x24429c18 // 00103AD0:  addiu $v0, $v0, -0x63e8
    .word 0x3c040039 // 00103AD4:  lui $a0, 0x39
    .word 0x91250001 // 00103AD8:  lbu $a1, 1($t1)
    .word 0x00621821 // 00103ADC:  addu $v1, $v1, $v0
    .word 0x24849c28 // 00103AE0:  addiu $a0, $a0, -0x63d8
    .word 0x90680000 // 00103AE4:  lbu $t0, ($v1)
    .word 0x00a42821 // 00103AE8:  addu $a1, $a1, $a0
    .word 0x3c02ffff // 00103AEC:  lui $v0, 0xffff
    .word 0x3442ffcf // 00103AF0:  ori $v0, $v0, 0xffcf
    .word 0x3c040039 // 00103AF4:  lui $a0, 0x39
    .word 0x91270002 // 00103AF8:  lbu $a3, 2($t1)
    .word 0x01421024 // 00103AFC:  and $v0, $t2, $v0
    .word 0x24849c38 // 00103B00:  addiu $a0, $a0, -0x63c8
    .word 0x00084100 // 00103B04:  sll $t0, $t0, 4
    .word 0x90a60000 // 00103B08:  lbu $a2, ($a1)
    .word 0x3c03ffff // 00103B0C:  lui $v1, 0xffff
    .word 0x00485025 // 00103B10:  or $t2, $v0, $t0
    .word 0x00e43821 // 00103B14:  addu $a3, $a3, $a0
    .word 0x3463ff3f // 00103B18:  ori $v1, $v1, 0xff3f
    .word 0x00063180 // 00103B1C:  sll $a2, $a2, 6
    .word 0x01431824 // 00103B20:  and $v1, $t2, $v1
    .word 0x90e40000 // 00103B24:  lbu $a0, ($a3)
    .word 0x3c02ffff // 00103B28:  lui $v0, 0xffff
    .word 0x00665025 // 00103B2C:  or $t2, $v1, $a2
    .word 0x3442fff3 // 00103B30:  ori $v0, $v0, 0xfff3
    .word 0x00042080 // 00103B34:  sll $a0, $a0, 2
    .word 0x01421024 // 00103B38:  and $v0, $t2, $v0
    .word 0x1160000a // 00103B3C:  beqz $t3, 0x103b68
    .word 0x00445025 // 00103B40:  or $t2, $v0, $a0
    .word 0x91230003 // 00103B44:  lbu $v1, 3($t1)
    .word 0x3c02ffff // 00103B48:  lui $v0, 0xffff
    .word 0x354a0002 // 00103B4C:  ori $t2, $t2, 2
    .word 0x3442fcff // 00103B50:  ori $v0, $v0, 0xfcff
    .word 0x2463ffff // 00103B54:  addiu $v1, $v1, -1
    .word 0x01421024 // 00103B58:  and $v0, $t2, $v0
    .word 0x00031a00 // 00103B5C:  sll $v1, $v1, 8
    .word 0x10000004 // 00103B60:  b 0x103b74
    .word 0x00435025 // 00103B64:  or $t2, $v0, $v1
    .word 0x3c02ffff // 00103B68:  lui $v0, 0xffff
    .word 0x3442fffd // 00103B6C:  ori $v0, $v0, 0xfffd
    .word 0x01425024 // 00103B70:  and $t2, $t2, $v0
    .word 0x95220004 // 00103B74:  lhu $v0, 4($t1)
    .word 0x3c041000 // 00103B78:  lui $a0, 0x1000
    .word 0x95260006 // 00103B7C:  lhu $a2, 6($t1)
    .word 0x3484e000 // 00103B80:  ori $a0, $a0, 0xe000
    .word 0x9525000a // 00103B84:  lhu $a1, 0xa($t1)
    .word 0x00021400 // 00103B88:  sll $v0, $v0, 0x10
    .word 0x8d280010 // 00103B8C:  lw $t0, 0x10($t1)
    .word 0x00463025 // 00103B90:  or $a2, $v0, $a2
    .word 0x95270008 // 00103B94:  lhu $a3, 8($t1)
    .word 0x3c031000 // 00103B98:  lui $v1, 0x1000
    .word 0xac8a0000 // 00103B9C:  sw $t2, ($a0)
    .word 0x3463e020 // 00103BA0:  ori $v1, $v1, 0xe020
    .word 0x00052c00 // 00103BA4:  sll $a1, $a1, 0x10
    .word 0x3c021000 // 00103BA8:  lui $v0, 0x1000
    .word 0xac660000 // 00103BAC:  sw $a2, ($v1)
    .word 0x00a72825 // 00103BB0:  or $a1, $a1, $a3
    .word 0x3442e030 // 00103BB4:  ori $v0, $v0, 0xe030
    .word 0x8d26000c // 00103BB8:  lw $a2, 0xc($t1)
    .word 0xac450000 // 00103BBC:  sw $a1, ($v0)
    .word 0x3c031000 // 00103BC0:  lui $v1, 0x1000
    .word 0x3463e050 // 00103BC4:  ori $v1, $v1, 0xe050
    .word 0x3c021000 // 00103BC8:  lui $v0, 0x1000
    .word 0xac660000 // 00103BCC:  sw $a2, ($v1)
    .word 0x3442e040 // 00103BD0:  ori $v0, $v0, 0xe040
    .word 0xac480000 // 00103BD4:  sw $t0, ($v0)
    .word 0x3c030039 // 00103BD8:  lui $v1, 0x39
    .word 0x24669c48 // 00103BDC:  addiu $a2, $v1, -0x63b8
    .word 0x69220007 // 00103BE0:  ldl $v0, 7($t1)
    .word 0x6d220000 // 00103BE4:  ldr $v0, ($t1)
    .word 0x6924000f // 00103BE8:  ldl $a0, 0xf($t1)
    .word 0x6d240008 // 00103BEC:  ldr $a0, 8($t1)
    .word 0x8d250010 // 00103BF0:  lw $a1, 0x10($t1)
    .word 0xb0c20007 // 00103BF4:  sdl $v0, 7($a2)
    .word 0xb4c20000 // 00103BF8:  sdr $v0, ($a2)
    .word 0xb0c4000f // 00103BFC:  sdl $a0, 0xf($a2)
    .word 0xb4c40008 // 00103C00:  sdr $a0, 8($a2)
    .word 0xacc50010 // 00103C04:  sw $a1, 0x10($a2)
    .word 0x03e00008 // 00103C08:  jr $ra
    .word 0x0000102d // 00103C0C:  move $v0, $zero
}
#else
s32 func_00103A38(const sceDmaEnv *env) {
    volatile u32 *d_ctrl  = (volatile u32 *)0x1000E000;
    volatile u32 *d_pcr   = (volatile u32 *)0x1000E020;
    volatile u32 *d_sqwc  = (volatile u32 *)0x1000E030;
    volatile u32 *d_rbor  = (volatile u32 *)0x1000E050;
    volatile u32 *d_rbsr  = (volatile u32 *)0x1000E040;

    u32 t2 = *d_ctrl;
    (void)*d_pcr;
    (void)*d_sqwc;
    (void)*d_rbor;
    (void)*d_rbsr;

    if (env->a >= 10) return -1;
    if (env->b >= 10) return -2;
    if (env->c >= 10) return -3;
    if (env->d >= 7) return -4;

    const u8 *table0 = (const u8 *)0x389C18;
    const u8 *table1 = (const u8 *)0x389C28;
    const u8 *table2 = (const u8 *)0x389C38;

    t2 = (t2 & ~0x30) | ((u32)table0[env->a] << 4);
    t2 = (t2 & ~0xC0) | ((u32)table1[env->b] << 6);
    t2 = (t2 & ~0x0C) | ((u32)table2[env->c] << 2);

    if (env->d != 0) {
        t2 |= 2;
        t2 = (t2 & ~0x300) | ((u32)(env->d - 1) << 8);
    } else {
        t2 &= ~2;
    }

    *d_ctrl = t2;
    *d_pcr = ((u32)env->e << 16) | env->f;
    *d_sqwc = ((u32)env->h << 16) | env->g;
    *d_rbor = env->i;
    *d_rbsr = env->j;

    *(sceDmaEnvRaw *)0x389C48 = *(const sceDmaEnvRaw *)env;

    return 0;
}
#endif

}
