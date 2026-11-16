/* Function: func_0012AD58 (0x0012AD58 - 0x0012AD98)
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
asm void func_0012AD58(void) {
    .word 0x27bdffe0 // addiu $sp, $sp, -0x20
    .word 0x3c02004f // lui $v0, 0x4f
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0xffbf0010 // sd $ra, 0x10($sp)
    .word 0x2450d300 // addiu $s0, $v0, -0x2d00
    .word 0x8e040044 // lw $a0, 0x44($s0)
    .word 0x04800006 // bltz $a0, 0x12ad8c
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0x0c04d130 // jal 0x1344c0
    .word 0x00000000 // nop
    .word 0x2403ffff // addiu $v1, $zero, -1
    .word 0xae030044 // sw $v1, 0x44($s0)
    .word 0xdfbf0010 // ld $ra, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0020 // addiu $sp, $sp, 0x20
}
#else

struct CdvdServerData {
    u8 pad[0x44];
    s32 f_44;
};

extern CdvdServerData D_004ED300;

void func_001344C0(s32);

void func_0012AD58(void) {
    s32 id = D_004ED300.f_44;
    if (id >= 0) {
        func_001344C0(id);
        D_004ED300.f_44 = -1;
    }
}

#endif

}
