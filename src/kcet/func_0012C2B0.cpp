/* Function: func_0012C2B0 (0x0012C2B0 - 0x0012C368)
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
asm s32 func_0012C2B0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    .word 0x27bdff70 // 0012C2B0:  addiu $sp, $sp, -0x90
    .word 0xffb40050 // 0012C2B4:  sd $s4, 0x50($sp)
    .word 0xffb20030 // 0012C2B8:  sd $s2, 0x30($sp)
    .word 0x00e0a02d // 0012C2BC:  move $s4, $a3
    .word 0xffb60070 // 0012C2C0:  sd $s6, 0x70($sp)
    .word 0x0080902d // 0012C2C4:  move $s2, $a0
    .word 0xffb50060 // 0012C2C8:  sd $s5, 0x60($sp)
    .word 0x0100b02d // 0012C2CC:  move $s6, $t0
    .word 0xffb30040 // 0012C2D0:  sd $s3, 0x40($sp)
    .word 0x00c0a82d // 0012C2D4:  move $s5, $a2
    .word 0xffb10020 // 0012C2D8:  sd $s1, 0x20($sp)
    .word 0x00a0982d // 0012C2DC:  move $s3, $a1
    .word 0xffb00010 // 0012C2E0:  sd $s0, 0x10($sp)
    .word 0x0280202d // 0012C2E4:  move $a0, $s4
    .word 0xffbf0080 // 0012C2E8:  sd $ra, 0x80($sp)
    .word 0x0c04afb0 // 0012C2EC:  jal 0x12bec0
    .word 0x0000802d // 0012C2F0:  move $s0, $zero
    .word 0x0040882d // 0012C2F4:  move $s1, $v0
    .word 0x12200010 // 0012C2F8:  beqz $s1, 0x12c33c
    .word 0x0240282d // 0012C2FC:  move $a1, $s2
    .word 0x26300030 // 0012C300:  addiu $s0, $s1, 0x30
    .word 0x0200202d // 0012C304:  move $a0, $s0
    .word 0x0c04b326 // 0012C308:  jal 0x12cc98
    .word 0x0260302d // 0012C30C:  move $a2, $s3
    .word 0x0200202d // 0012C310:  move $a0, $s0
    .word 0xafb10000 // 0012C314:  sw $s1, ($sp)
    .word 0x02a0282d // 0012C318:  move $a1, $s5
    .word 0x0280302d // 0012C31C:  move $a2, $s4
    .word 0x02c0582d // 0012C320:  move $t3, $s6
    .word 0x0000382d // 0012C324:  move $a3, $zero
    .word 0x0000402d // 0012C328:  move $t0, $zero
    .word 0x24090001 // 0012C32C:  addiu $t1, $zero, 1
    .word 0x0c04b01a // 0012C330:  jal 0x12c068
    .word 0x0000502d // 0012C334:  move $t2, $zero
    .word 0x0040802d // 0012C338:  move $s0, $v0
    .word 0x0200102d // 0012C33C:  move $v0, $s0
    .word 0xdfbf0080 // 0012C340:  ld $ra, 0x80($sp)
    .word 0xdfb60070 // 0012C344:  ld $s6, 0x70($sp)
    .word 0xdfb50060 // 0012C348:  ld $s5, 0x60($sp)
    .word 0xdfb40050 // 0012C34C:  ld $s4, 0x50($sp)
    .word 0xdfb30040 // 0012C350:  ld $s3, 0x40($sp)
    .word 0xdfb20030 // 0012C354:  ld $s2, 0x30($sp)
    .word 0xdfb10020 // 0012C358:  ld $s1, 0x20($sp)
    .word 0xdfb00010 // 0012C35C:  ld $s0, 0x10($sp)
    .word 0x03e00008 // 0012C360:  jr $ra
    .word 0x27bd0090 // 0012C364:  addiu $sp, $sp, 0x90
}
#else

void *func_0012BEC0(s32 a0);
void func_0012CC98(void *a0, s32 a1, s32 a2);
s32 func_0012C068(void *a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, void *req);

s32 func_0012C2B0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    s32 ret = 0;
    void *req = func_0012BEC0(a3);
    if (req != 0) {
        void *sub = (char *)req + 0x30;
        func_0012CC98(sub, a0, a1);
        ret = func_0012C068(sub, a2, a3, 0, 0, 1, 0, t0, req);
    }
    return ret;
}

#endif

}
