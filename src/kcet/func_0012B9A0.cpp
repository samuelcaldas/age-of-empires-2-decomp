/* Function: func_0012B9A0 (0x0012B9A0 - 0x0012B9F4)
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
asm void func_0012B9A0(void) {
    .word 0x27bdffd0 // addiu $sp, $sp, -0x30
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x3c10004f // lui $s0, 0x4f
    .word 0xffbf0020 // sd $ra, 0x20($sp)
    .word 0x2610d300 // addiu $s0, $s0, -0x2d00
    .word 0x2411ffff // addiu $s1, $zero, -1
    .word 0x0c04d06e // jal 0x1341b8
    .word 0x8e040050 // lw $a0, 0x50($s0)
    .word 0x8e040048 // lw $a0, 0x48($s0)
    .word 0x0c04d130 // jal 0x1344c0
    .word 0xae110050 // sw $s1, 0x50($s0)
    .word 0x8e04004c // lw $a0, 0x4c($s0)
    .word 0x0c04d130 // jal 0x1344c0
    .word 0xae110048 // sw $s1, 0x48($s0)
    .word 0xae11004c // sw $s1, 0x4c($s0)
    .word 0xdfbf0020 // ld $ra, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0030 // addiu $sp, $sp, 0x30
}
#else

struct CdvdServerData {
    u8 pad[0x48];
    s32 sem1;
    s32 sem2;
    s32 thread;
};
extern CdvdServerData D_004ED300;

int func_001341B8(s32);
int func_001344C0(s32);

void func_0012B9A0(void) {
    func_001341B8(D_004ED300.thread);
    func_001344C0(D_004ED300.sem1);
    D_004ED300.thread = -1;
    func_001344C0(D_004ED300.sem2);
    D_004ED300.sem1 = -1;
    D_004ED300.sem2 = -1;
}

#endif

}
