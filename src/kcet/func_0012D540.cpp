/* Function: func_0012D540 (0x0012D540 - 0x0012D5F0)
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
asm void func_0012D540(void *arg) {
    .word 0x27bdffa0 // 0012D540:  addiu $sp, $sp, -0x60
    .word 0xffb00000 // 0012D544:  sd $s0, ($sp)
    .word 0xffb40040 // 0012D548:  sd $s4, 0x40($sp)
    .word 0xffb30030 // 0012D54C:  sd $s3, 0x30($sp)
    .word 0xffb20020 // 0012D550:  sd $s2, 0x20($sp)
    .word 0xffb10010 // 0012D554:  sd $s1, 0x10($sp)
    .word 0xffbf0050 // 0012D558:  sd $ra, 0x50($sp)
    .word 0x0c04b3a8 // 0012D55C:  jal 0x12cea0
    .word 0x0080802d // 0012D560:  move $s0, $a0
    .word 0x0c04b3c0 // 0012D564:  jal 0x12cf00
    .word 0x0040202d // 0012D568:  move $a0, $v0
    .word 0x0040a02d // 0012D56C:  move $s4, $v0
    .word 0x0c04b418 // 0012D570:  jal 0x12d060
    .word 0x0200202d // 0012D574:  move $a0, $s0
    .word 0x0040982d // 0012D578:  move $s3, $v0
    .word 0x0c04b3d6 // 0012D57C:  jal 0x12cf58
    .word 0x0200202d // 0012D580:  move $a0, $s0
    .word 0x0040882d // 0012D584:  move $s1, $v0
    .word 0x0c04b3f2 // 0012D588:  jal 0x12cfc8
    .word 0x0200202d // 0012D58C:  move $a0, $s0
    .word 0x0040802d // 0012D590:  move $s0, $v0
    .word 0x0c04b2d8 // 0012D594:  jal 0x12cb60
    .word 0x0220202d // 0012D598:  move $a0, $s1
    .word 0x0040902d // 0012D59C:  move $s2, $v0
    .word 0x0c04b2e4 // 0012D5A0:  jal 0x12cb90
    .word 0x0220202d // 0012D5A4:  move $a0, $s1
    .word 0x0040882d // 0012D5A8:  move $s1, $v0
    .word 0x0c04b312 // 0012D5AC:  jal 0x12cc48
    .word 0x0200202d // 0012D5B0:  move $a0, $s0
    .word 0x0280282d // 0012D5B4:  move $a1, $s4
    .word 0x0260302d // 0012D5B8:  move $a2, $s3
    .word 0x0240382d // 0012D5BC:  move $a3, $s2
    .word 0x0220402d // 0012D5C0:  move $t0, $s1
    .word 0x3c040049 // 0012D5C4:  lui $a0, 0x49
    .word 0xdfbf0050 // 0012D5C8:  ld $ra, 0x50($sp)
    .word 0xdfb40040 // 0012D5CC:  ld $s4, 0x40($sp)
    .word 0x2484fed8 // 0012D5D0:  addiu $a0, $a0, -0x128
    .word 0xdfb30030 // 0012D5D4:  ld $s3, 0x30($sp)
    .word 0x0040482d // 0012D5D8:  move $t1, $v0
    .word 0xdfb20020 // 0012D5DC:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012D5E0:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012D5E4:  ld $s0, ($sp)
    .word 0x08046378 // 0012D5E8:  j 0x118de0
    .word 0x27bd0060 // 0012D5EC:  addiu $sp, $sp, 0x60
}
#else

extern const char D_48FED8[];

u32 func_0012CEA0(void *);
u32 func_0012CF00(u32);
u32 func_0012D060(void *);
void *func_0012CF58(void *);
u32 func_0012CFC8(void *);
u32 func_0012CB60(void *);
u32 func_0012CB90(void *);
void *func_0012CC48(u32);
void func_118de0(const char *, ...);

void func_0012D540(void *arg) {
    u32 s4 = func_0012CF00(func_0012CEA0(arg));
    u32 s3 = func_0012D060(arg);
    void *s1 = func_0012CF58(arg);
    u32 s0 = func_0012CFC8(arg);
    u32 s2 = func_0012CB60(s1);
    s1 = (void *)func_0012CB90(s1);
    void *v0 = func_0012CC48(s0);
    func_118de0(D_48FED8, s4, s3, s2, s1, v0);
}

#endif

}
