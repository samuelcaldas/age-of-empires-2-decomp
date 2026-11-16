/* Function: func_0012D400 (0x0012D400 - 0x0012D46C)
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
asm u32 func_0012D400(u32 a0) {
    .word 0x27bdffd0 // 0012D400:  addiu $sp, $sp, -0x30
    .word 0xffb00000 // 0012D404:  sd $s0, ($sp)
    .word 0x0080802d // 0012D408:  move $s0, $a0
    .word 0xffb10010 // 0012D40C:  sd $s1, 0x10($sp)
    .word 0xffbf0020 // 0012D410:  sd $ra, 0x20($sp)
    .word 0x0c04b438 // 0012D414:  jal 0x12d0e0
    .word 0x0000882d // 0012D418:  move $s1, $zero
    .word 0x10400005 // 0012D41C:  beqz $v0, 0x12d434
    .word 0x00000000 // 0012D420:  nop 
    .word 0x0c04b2c8 // 0012D424:  jal 0x12cb20
    .word 0x0040202d // 0012D428:  move $a0, $v0
    .word 0x10000008 // 0012D42C:  b 0x12d450
    .word 0x0040882d // 0012D430:  move $s1, $v0
    .word 0x0c04b48a // 0012D434:  jal 0x12d228
    .word 0x0200202d // 0012D438:  move $a0, $s0
    .word 0x10400004 // 0012D43C:  beqz $v0, 0x12d450
    .word 0x00000000 // 0012D440:  nop 
    .word 0x0c04b2fe // 0012D444:  jal 0x12cbf8
    .word 0x0040202d // 0012D448:  move $a0, $v0
    .word 0x0040882d // 0012D44C:  move $s1, $v0
    .word 0x0c04b2c2 // 0012D450:  jal 0x12cb08
    .word 0x0220202d // 0012D454:  move $a0, $s1
    .word 0xdfbf0020 // 0012D458:  ld $ra, 0x20($sp)
    .word 0xdfb10010 // 0012D45C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012D460:  ld $s0, ($sp)
    .word 0x03e00008 // 0012D464:  jr $ra
    .word 0x27bd0030 // 0012D468:  addiu $sp, $sp, 0x30
}
#else

void *func_0012D0E0(void *);
u32 func_0012CB20(void *);
void *func_0012D228(u32);
u32 func_0012CBF8(void *);
u32 func_0012CB08(u32);

u32 func_0012D400(u32 a0) {
    u32 s1 = 0;
    void *v0 = func_0012D0E0((void *)a0);
    if (v0 != 0) {
        s1 = func_0012CB20(v0);
    } else {
        void *entry = func_0012D228(a0);
        if (entry != 0) {
            s1 = func_0012CBF8(entry);
        }
    }
    return func_0012CB08(s1);
}

#endif

}
