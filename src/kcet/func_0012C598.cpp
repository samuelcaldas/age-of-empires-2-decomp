/* Function: func_0012C598 (0x0012C598 - 0x0012C63C)
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
asm s32 func_0012C598(s32 a0, s32 a1, s32 a2, s32 a3) {
    .word 0x27bdff90 // 0012C598:  addiu $sp, $sp, -0x70
    .word 0xffb40040 // 0012C59C:  sd $s4, 0x40($sp)
    .word 0xffb20020 // 0012C5A0:  sd $s2, 0x20($sp)
    .word 0x00c0a02d // 0012C5A4:  move $s4, $a2
    .word 0xffb50050 // 0012C5A8:  sd $s5, 0x50($sp)
    .word 0x0080902d // 0012C5AC:  move $s2, $a0
    .word 0xffb30030 // 0012C5B0:  sd $s3, 0x30($sp)
    .word 0x00e0a82d // 0012C5B4:  move $s5, $a3
    .word 0xffb10010 // 0012C5B8:  sd $s1, 0x10($sp)
    .word 0x00a0982d // 0012C5BC:  move $s3, $a1
    .word 0xffb00000 // 0012C5C0:  sd $s0, ($sp)
    .word 0x0280202d // 0012C5C4:  move $a0, $s4
    .word 0xffbf0060 // 0012C5C8:  sd $ra, 0x60($sp)
    .word 0x0c04afb0 // 0012C5CC:  jal 0x12bec0
    .word 0x0000802d // 0012C5D0:  move $s0, $zero
    .word 0x0040882d // 0012C5D4:  move $s1, $v0
    .word 0x1220000e // 0012C5D8:  beqz $s1, 0x12c614
    .word 0x0240282d // 0012C5DC:  move $a1, $s2
    .word 0x26300030 // 0012C5E0:  addiu $s0, $s1, 0x30
    .word 0x0200202d // 0012C5E4:  move $a0, $s0
    .word 0x0c04b326 // 0012C5E8:  jal 0x12cc98
    .word 0x0260302d // 0012C5EC:  move $a2, $s3
    .word 0x0200202d // 0012C5F0:  move $a0, $s0
    .word 0x0280282d // 0012C5F4:  move $a1, $s4
    .word 0x02a0482d // 0012C5F8:  move $t1, $s5
    .word 0x0220502d // 0012C5FC:  move $t2, $s1
    .word 0x0000302d // 0012C600:  move $a2, $zero
    .word 0x24070001 // 0012C604:  addiu $a3, $zero, 1
    .word 0x0c04b0ea // 0012C608:  jal 0x12c3a8
    .word 0x0000402d // 0012C60C:  move $t0, $zero
    .word 0x0040802d // 0012C610:  move $s0, $v0
    .word 0x0200102d // 0012C614:  move $v0, $s0
    .word 0xdfbf0060 // 0012C618:  ld $ra, 0x60($sp)
    .word 0xdfb50050 // 0012C61C:  ld $s5, 0x50($sp)
    .word 0xdfb40040 // 0012C620:  ld $s4, 0x40($sp)
    .word 0xdfb30030 // 0012C624:  ld $s3, 0x30($sp)
    .word 0xdfb20020 // 0012C628:  ld $s2, 0x20($sp)
    .word 0xdfb10010 // 0012C62C:  ld $s1, 0x10($sp)
    .word 0xdfb00000 // 0012C630:  ld $s0, ($sp)
    .word 0x03e00008 // 0012C634:  jr $ra
    .word 0x27bd0070 // 0012C638:  addiu $sp, $sp, 0x70
}
#else

void *func_0012BEC0(s32 a0);
void func_0012CC98(void *a0, s32 a1, s32 a2);
s32 func_0012C3A8(void *a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, void *t2);

s32 func_0012C598(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 ret = 0;
    void *req = func_0012BEC0(a2);
    if (req != 0) {
        void *sub = (char *)req + 0x30;
        func_0012CC98(sub, a0, a1);
        ret = func_0012C3A8(sub, a2, 0, 1, 0, a3, req);
    }
    return ret;
}

#endif

}
