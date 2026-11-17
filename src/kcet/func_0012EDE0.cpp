#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm void func_0012EDE0(void) {
    .word 0x27bdffe0 // 0012EDE0:  addiu $sp, $sp, -0x20
    .word 0xffb00000 // 0012EDE4:  sd $s0, ($sp)
    .word 0x3c100050 // 0012EDE8:  lui $s0, 0x50
    .word 0xffbf0010 // 0012EDEC:  sd $ra, 0x10($sp)
    .word 0x8e029700 // 0012EDF0:  lw $v0, -0x6900($s0)
    .word 0x10400006 // 0012EDF4:  beqz $v0, 0x12ee10
    .word 0x26049700 // 0012EDF8:  addiu $a0, $s0, -0x6900
    .word 0x0040f809 // 0012EDFC:  jalr $v0
    .word 0x00000000 // 0012EE00:  nop 
    .word 0x2403ff80 // 0012EE04:  addiu $v1, $zero, -0x80
    .word 0x50430001 // 0012EE08:  beql $v0, $v1, 0x12ee10
    .word 0xae009700 // 0012EE0C:  sw $zero, -0x6900($s0)
    .word 0xdfbf0010 // 0012EE10:  ld $ra, 0x10($sp)
    .word 0xdfb00000 // 0012EE14:  ld $s0, ($sp)
    .word 0x03e00008 // 0012EE18:  jr $ra
    .word 0x27bd0020 // 0012EE1C:  addiu $sp, $sp, 0x20
}
#else

typedef int (*TargetCallback)(void *);

extern TargetCallback D_004F9700;

void func_0012EDE0(void) {
    TargetCallback cb = D_004F9700;
    if (cb != 0) {
        if (cb(&D_004F9700) == -128) {
            D_004F9700 = 0;
        }
    }
}

#endif

}
