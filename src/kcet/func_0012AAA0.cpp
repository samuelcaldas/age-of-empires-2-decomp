/* Function: func_0012AAA0 (0x0012AAA0 - 0x0012AB28)
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
asm void func_0012AAA0(void) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x3c10004f // lui $s0, 0x4f
    .word 0x2610d300 // addiu $s0, $s0, -0x2d00
    .word 0x8e040034 // lw $a0, 0x34($s0)
    .word 0x0c04d110 // jal 0x134440
    .word 0x00000000 // nop
    .word 0x8e040038 // lw $a0, 0x38($s0)
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x0804d140 // j 0x134500
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
    .word 0x00000000 // nop
    .word 0x27bdffc0 // addiu $sp, $sp, -0x40
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x2412ffff // addiu $s2, $zero, -1
    .word 0xffbf0030 // sd $ra, 0x30($sp)
    .word 0x2451d300 // addiu $s1, $v0, -0x2d00
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x8e300034 // lw $s0, 0x34($s1)
    .word 0x0c041360 // jal 0x104d80
    .word 0x0200202d // move $a0, $s0
    .word 0x50500001 // beql $v0, $s0, 0x12ab0c
    .word 0x8e320038 // lw $s2, 0x38($s1)
    .word 0x0240102d // move $v0, $s2
    .word 0xdfbf0030 // ld $ra, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0040 // addiu $sp, $sp, 0x40
}
#else

struct CdvdServerSemaphores {
    u8 pad[0x34];
    s32 sem1;
    s32 sem2;
};

extern CdvdServerSemaphores D_004ED300;

int func_00134440(int);
int func_00134500(int);
int func_104D80(int);

void func_0012AAA0(void) {
    func_00134440(D_004ED300.sem1);
    func_00134500(D_004ED300.sem2);
}

int func_0012AAD8(void) {
    s32 s0 = D_004ED300.sem1;
    if (func_104D80(s0) == s0) {
        return D_004ED300.sem2;
    }
    return -1;
}

#endif

}
