/* Function: func_0012E0E0 (0x0012E0E0 - 0x0012E114)
 * Origin: SLES-50282, KCET kt_file module (originally compiled with ee-gcc -O2 -G0)
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
asm void func_0012E0E0(s32 arg0, s32 arg1) {
    .word 0x27bdffe0 // 0012E0E0:  addiu $sp, $sp, -0x20
    .word 0xafa50000 // 0012E0E4:  sw $a1, ($sp)
    .word 0xffbf0010 // 0012E0E8:  sd $ra, 0x10($sp)
    .word 0x0c04b82a // 0012E0EC:  jal 0x12e0a8
    .word 0x00000000 // 0012E0F0:  nop 
    .word 0x8fa20000 // 0012E0F4:  lw $v0, ($sp)
    .word 0x3c04ffff // 0012E0F8:  lui $a0, 0xffff
    .word 0x0004203e // 0012E0FC:  dsrl32 $a0, $a0, 0
    .word 0x0c04b82e // 0012E100:  jal 0x12e0b8
    .word 0x00442024 // 0012E104:  and $a0, $v0, $a0
    .word 0xdfbf0010 // 0012E108:  ld $ra, 0x10($sp)
    .word 0x03e00008 // 0012E10C:  jr $ra
    .word 0x27bd0020 // 0012E110:  addiu $sp, $sp, 0x20
}
#else

void func_0012E0A8(s32 arg0);
void func_0012E0B8(s32 arg0);

void func_0012E0E0(s32 arg0, s32 arg1) {
    func_0012E0A8(arg0);
    func_0012E0B8(arg1 & 0xFFFF);
}

#endif

}
