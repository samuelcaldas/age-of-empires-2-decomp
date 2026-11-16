/* Function: func_0012CEA0 (0x0012CEA0 - 0x0012CF00)
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
asm s32 func_0012CEA0(void *a0) {
    .word 0x27bdffe0 // 0012cea0:  addiu $sp, $sp, -0x20
    .word 0xffb00000 // 0012cea4:  sd $s0, ($sp)
    .word 0x0080802d // 0012cea8:  move $s0, $a0
    .word 0x16000003 // 0012ceac:  bnez $s0, 0x12cebc
    .word 0xffbf0010 // 0012ceb0:  sd $ra, 0x10($sp)
    .word 0x1000000e // 0012ceb4:  b 0x12cef0
    .word 0x24020003 // 0012ceb8:  addiu $v0, $zero, 3
    .word 0x0c04b2c0 // 0012cebc:  jal 0x12cb00
    .word 0x0200202d // 0012cec0:  move $a0, $s0
    .word 0x1440000a // 0012cec4:  bnez $v0, 0x12cef0
    .word 0x0000102d // 0012cec8:  move $v0, $zero
    .word 0x0c04b2c0 // 0012cecc:  jal 0x12cb00
    .word 0x96040000 // 0012ced0:  lhu $a0, ($s0)
    .word 0x14400006 // 0012ced4:  bnez $v0, 0x12cef0
    .word 0x24020002 // 0012ced8:  addiu $v0, $zero, 2
    .word 0x96030000 // 0012cedc:  lhu $v1, ($s0)
    .word 0x24020040 // 0012cee0:  addiu $v0, $zero, 0x40
    .word 0x14620002 // 0012cee4:  bne $v1, $v0, 0x12cef0
    .word 0x24020001 // 0012cee8:  addiu $v0, $zero, 1
    .word 0x24020002 // 0012ceec:  addiu $v0, $zero, 2
    .word 0xdfbf0010 // 0012cef0:  ld $ra, 0x10($sp)
    .word 0xdfb00000 // 0012cef4:  ld $s0, ($sp)
    .word 0x03e00008 // 0012cef8:  jr $ra
    .word 0x27bd0020 // 0012cefc:  addiu $sp, $sp, 0x20
}
#else

s32 func_0012CB00(void *arg);

s32 func_0012CEA0(void *arg) {
    if (arg == 0) {
        return 3;
    }
    if (func_0012CB00(arg) != 0) {
        return 0;
    }
    if (func_0012CB00((void *)(int)*(u16 *)arg) != 0) {
        return 2;
    }
    if (*(u16 *)arg != 0x40) {
        return 2;
    }
    return 1;
}

#endif

}
