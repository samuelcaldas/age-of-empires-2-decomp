/* Function: func_0012BD88 (0x0012BD88 - 0x0012BE1C)
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
asm s32 func_0012BD88(void *arg0) {
    .word 0x27bdffb0 // 0012BD88:  addiu $sp, $sp, -0x50
    .word 0x3c02004f // 0012BD8C:  lui $v0, 0x4f
    .word 0xffb30030 // 0012BD90:  sd $s3, 0x30($sp)
    .word 0xffb20020 // 0012BD94:  sd $s2, 0x20($sp)
    .word 0x2453d360 // 0012BD98:  addiu $s3, $v0, -0x2ca0
    .word 0xffb00000 // 0012BD9C:  sd $s0, ($sp)
    .word 0x0000902d // 0012BDA0:  move $s2, $zero
    .word 0xffbf0040 // 0012BDA4:  sd $ra, 0x40($sp)
    .word 0x0080802d // 0012BDA8:  move $s0, $a0
    .word 0x0c04af18 // 0012BDAC:  jal 0x12bc60
    .word 0xffb10010 // 0012BDB0:  sd $s1, 0x10($sp)
    .word 0x14400004 // 0012BDB4:  bnez $v0, 0x12bdc8
    .word 0x00000000 // 0012BDB8:  nop
    .word 0x0c043f56 // 0012BDBC:  jal 0x10fd58
    .word 0x0200202d // 0012BDC0:  move $a0, $s0
    .word 0x0040902d // 0012BDC4:  move $s2, $v0
    .word 0x12400003 // 0012BDC8:  beqz $s2, 0x12bdd8
    .word 0x24020001 // 0012BDCC:  addiu $v0, $zero, 1
    .word 0x12420004 // 0012BDD0:  beq $s2, $v0, 0x12bde4
    .word 0x00000000 // 0012BDD4:  nop
    .word 0x0200882d // 0012BDD8:  move $s1, $s0
    .word 0x10000003 // 0012BDDC:  b 0x12bdec
    .word 0x0260802d // 0012BDE0:  move $s0, $s3
    .word 0x0c04af0c // 0012BDE4:  jal 0x12bc30
    .word 0x0260882d // 0012BDE8:  move $s1, $s3
    .word 0x6a030007 // 0012BDEC:  ldl $v1, 7($s0)
    .word 0x6e030000 // 0012BDF0:  ldr $v1, ($s0)
    .word 0xb2230007 // 0012BDF4:  sdl $v1, 7($s1)
    .word 0x0240102d // 0012BDF8:  move $v0, $s2
    .word 0xb6230000 // 0012BDFC:  sdr $v1, ($s1)
    .word 0xdfbf0040 // 0012BE00:  ld $ra, 0x40($sp)
    .word 0xdfb30030 // 0012BE04:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012BE08:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012BE0C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012BE10:  ld $s0, ($sp)
    .word 0x03e00008 // 0012BE14:  jr $ra
    .word 0x27bd0050 // 0012BE18:  addiu $sp, $sp, 0x50
}
#else

struct CdvdClock {
    u8 data[8];
};

extern CdvdClock D_004ED360;

int func_0012BC60(void);
int func_0010FD58(void *);
void func_0012BC30(void);

s32 func_0012BD88(CdvdClock *arg0) {
    s32 res = 0;
    CdvdClock *src;
    CdvdClock *dst;

    if (func_0012BC60() == 0) {
        res = func_0010FD58(arg0);
    }

    if (res == 1) {
        dst = &D_004ED360;
        src = arg0;
        func_0012BC30();
    } else {
        dst = arg0;
        src = &D_004ED360;
    }

    *dst = *src;
    return res;
}

#endif

}
