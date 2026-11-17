#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012F388(void *a0, s32 a1, s32 a2) {
    .word 0x84830004 // 0012F388:  lh $v1, 4($a0)
    .word 0x0000282d // 0012F38C:  move $a1, $zero
    .word 0x24020001 // 0012F390:  addiu $v0, $zero, 1
    .word 0x1062000c // 0012F394:  beq $v1, $v0, 0x12f3c8
    .word 0x84870006 // 0012F398:  lh $a3, 6($a0)
    .word 0x28620002 // 0012F39C:  slti $v0, $v1, 2
    .word 0x50400005 // 0012F3A0:  beql $v0, $zero, 0x12f3b8
    .word 0x24020003 // 0012F3A4:  addiu $v0, $zero, 3
    .word 0x50600008 // 0012F3A8:  beql $v1, $zero, 0x12f3cc
    .word 0x2405ff81 // 0012F3AC:  addiu $a1, $zero, -0x7f
    .word 0x10000006 // 0012F3B0:  b 0x12f3cc
    .word 0x00000000 // 0012F3B4:  nop
    .word 0x50620004 // 0012F3B8:  beql $v1, $v0, 0x12f3cc
    .word 0x2405ff82 // 0012F3BC:  addiu $a1, $zero, -0x7e
    .word 0x10000002 // 0012F3C0:  b 0x12f3cc
    .word 0x00000000 // 0012F3C4:  nop
    .word 0x2405ff81 // 0012F3C8:  addiu $a1, $zero, -0x7f
    .word 0x14a00010 // 0012F3CC:  bnez $a1, 0x12f410
    .word 0x24020001 // 0012F3D0:  addiu $v0, $zero, 1
    .word 0x50e0000e // 0012F3D4:  beql $a3, $zero, 0x12f410
    .word 0x2405ff82 // 0012F3D8:  addiu $a1, $zero, -0x7e
    .word 0x1ce00006 // 0012F3DC:  bgtz $a3, 0x12f3f8
    .word 0x24020002 // 0012F3E0:  addiu $v0, $zero, 2
    .word 0x2402ffff // 0012F3E4:  addiu $v0, $zero, -1
    .word 0x50e20008 // 0012F3E8:  beql $a3, $v0, 0x12f40c
    .word 0x2405ff81 // 0012F3EC:  addiu $a1, $zero, -0x7f
    .word 0x10000007 // 0012F3F0:  b 0x12f410
    .word 0x24020001 // 0012F3F4:  addiu $v0, $zero, 1
    .word 0x50e20003 // 0012F3F8:  beql $a3, $v0, 0x12f408
    .word 0x2405ff84 // 0012F3FC:  addiu $a1, $zero, -0x7c
    .word 0x10000003 // 0012F400:  b 0x12f410
    .word 0x24020001 // 0012F404:  addiu $v0, $zero, 1
    .word 0x0006280b // 0012F408:  movn $a1, $zero, $a2
    .word 0x24020001 // 0012F40C:  addiu $v0, $zero, 1
    .word 0x03e00008 // 0012F410:  jr $ra
    .word 0x00a5100b // 0012F414:  movn $v0, $a1, $a1
}
#else
s32 func_0012F388(void *a0, s32 a1, s32 a2) {
    short v1 = *(short *)((char *)a0 + 4);
    short a3 = *(short *)((char *)a0 + 6);
    a1 = 0;
    if (v1 == 1 || v1 == 0) {
        a1 = -0x7F;
    } else if (v1 == 3) {
        a1 = -0x7E;
    }

    if (a1 == 0) {
        if (a3 == 0) {
            a1 = -0x7E;
        } else if (a3 == 1) {
            a1 = a2 ? 0 : -0x7C;
        } else if (a3 == -1) {
            a1 = -0x7F;
        }
    }

    return a1 ? a1 : 1;
}
#endif

}
