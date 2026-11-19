#pragma exceptions off

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern "C" {

#if defined(__mips__)
asm s32 func_00105240(s32 a0, s32 a1, s32 a2) {
    .word 0x27bdffc0 // 00105240:  addiu $sp, $sp, -0x40
    .word 0x2484ffff // 00105244:  addiu $a0, $a0, -1
    .word 0xffb20020 // 00105248:  sd $s2, 0x20($sp)
    .word 0x2c840002 // 0010524C:  sltiu $a0, $a0, 2
    .word 0xffb10010 // 00105250:  sd $s1, 0x10($sp)
    .word 0x00c0902d // 00105254:  move $s2, $a2
    .word 0xffbf0030 // 00105258:  sd $ra, 0x30($sp)
    .word 0x00a0882d // 0010525C:  move $s1, $a1
    .word 0x1080000f // 00105260:  beqz $a0, 0x1052a0
    .word 0xffb00000 // 00105264:  sd $s0, ($sp)
    .word 0x3c100039 // 00105268:  lui $s0, 0x39
    .word 0x8e029c6c // 0010526C:  lw $v0, -0x6394($s0)
    .word 0x14400007 // 00105270:  bnez $v0, 0x105290
    .word 0x0220202d // 00105274:  move $a0, $s1
    .word 0x0c041912 // 00105278:  jal 0x106448
    .word 0x00000000 // 0010527C:  nop 
    .word 0x10400007 // 00105280:  beqz $v0, 0x1052a0
    .word 0x24020001 // 00105284:  addiu $v0, $zero, 1
    .word 0xae029c6c // 00105288:  sw $v0, -0x6394($s0)
    .word 0x0220202d // 0010528C:  move $a0, $s1
    .word 0x0c04188a // 00105290:  jal 0x106228
    .word 0x0240282d // 00105294:  move $a1, $s2
    .word 0x10000003 // 00105298:  b 0x1052a8
    .word 0xdfbf0030 // 0010529C:  ld $ra, 0x30($sp)
    .word 0x2402ffff // 001052A0:  addiu $v0, $zero, -1
    .word 0xdfbf0030 // 001052A4:  ld $ra, 0x30($sp)
    .word 0xdfb20020 // 001052A8:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 001052AC:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 001052B0:  ld $s0, ($sp)
    .word 0x03e00008 // 001052B4:  jr $ra
    .word 0x27bd0040 // 001052B8:  addiu $sp, $sp, 0x40
}
#else
int func_00106448(int);
int func_00106228(int, int);
extern int D_00389C6C;

s32 func_00105240(u32 a0, s32 a1, s32 a2) {
    if (a0 - 1 < 2) {
        if (!D_00389C6C) {
            if (!func_00106448(a1)) {
                return -1;
            }
            D_00389C6C = 1;
        }
        return func_00106228(a1, a2);
    }
    return -1;
}
#endif

}
