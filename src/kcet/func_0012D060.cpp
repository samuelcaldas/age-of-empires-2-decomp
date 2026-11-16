/* Function: func_0012D060 (0x0012D060 - 0x0012D0D0)
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
asm s32 func_0012D060(void *a0) {
    .word 0x27bdffd0 // 0012d060:  addiu $sp, $sp, -0x30
    .word 0xffb10010 // 0012d064:  sd $s1, 0x10($sp)
    .word 0xffb00000 // 0012d068:  sd $s0, ($sp)
    .word 0xffbf0020 // 0012d06c:  sd $ra, 0x20($sp)
    .word 0x0c04b3a8 // 0012d070:  jal 0x12cea0
    .word 0x0080882d // 0012d074:  move $s1, $a0
    .word 0x0040802d // 0012d078:  move $s0, $v0
    .word 0x2e020004 // 0012d07c:  sltiu $v0, $s0, 4
    .word 0x14400008 // 0012d080:  bnez $v0, 0x12d0a4
    .word 0x3c020039 // 0012d084:  lui $v0, 0x39
    .word 0x3c040049 // 0012d088:  lui $a0, 0x49
    .word 0x3c060049 // 0012d08c:  lui $a2, 0x49
    .word 0x2484fea0 // 0012d090:  addiu $a0, $a0, -0x160
    .word 0x24c6feb0 // 0012d094:  addiu $a2, $a2, -0x150
    .word 0x0c0450c8 // 0012d098:  jal 0x114320
    .word 0x240501ba // 0012d09c:  addiu $a1, $zero, 0x1ba
    .word 0x3c020039 // 0012d0a0:  lui $v0, 0x39
    .word 0x00101880 // 0012d0a4:  sll $v1, $s0, 2
    .word 0x2442c828 // 0012d0a8:  addiu $v0, $v0, -0x37d8
    .word 0x00621821 // 0012d0ac:  addu $v1, $v1, $v0
    .word 0x8c620000 // 0012d0b0:  lw $v0, ($v1)
    .word 0x0040f809 // 0012d0b4:  jalr $v0
    .word 0x0220202d // 0012d0b8:  move $a0, $s1
    .word 0xdfbf0020 // 0012d0bc:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012d0c0:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012d0c4:  ld $s0, ($sp)
    .word 0x03e00008 // 0012d0c8:  jr $ra
    .word 0x27bd0030 // 0012d0cc:  addiu $sp, $sp, 0x30
}
#else

typedef s32 (*DispatchFn)(void *);
extern const char D_48FEA0[];
extern const char D_48FEB0[];
extern void *D_38C828[];
s32 func_0012CEA0(void *);
void func_114320(const char *, s32, const char *);

s32 func_0012D060(void *arg) {
    s32 kind = func_0012CEA0(arg);
    if ((u32)kind >= 4) {
        func_114320(D_48FEA0, 0x1ba, D_48FEB0);
    }
    return ((DispatchFn)D_38C828[kind])(arg);
}

#endif

}
