#pragma exceptions off
#include "kt_game_thread_spawn_2205e0.h"

extern "C" {
int func_220300(struct SemaContainer *sema, int max_count, int init_count, int option);
int func_220380(struct ThreadContainer *thread, void *entry, void *stack, int stack_size, int priority, int option);
int func_104B40(int thread_id, void *arg);
void func_002206A0(void);

#ifdef __MWERKS__
asm int func_002205E0(void *arg) {
    addiu $sp, $sp, -0x40
    sq $ra, 0x20($sp)
    sq $s1, 0x10($sp)
    lui $v0, 0xC6
    addiu $s1, $v0, -0xCB0
    sq $s0, 0($sp)
    .word 0x70808628 // por $s0, $a0, $zero
    lui $v0, 0xC7
    addiu $a0, $v0, -0xC70
    addiu $v0, $sp, 0x3C
    .word 0xAC5D0000 // sw $sp, 0($v0)
    addiu $a1, $zero, 1
    .word 0x70003628 // por $a2, $zero, $zero
    jal func_220300
    .word 0x70003E28 // por $a3, $zero, $zero
    lui $v0, 0xC7
    addiu $a0, $v0, -0xC50
    addiu $a1, $zero, 1
    .word 0x70003628 // por $a2, $zero, $zero
    jal func_220300
    .word 0x70003E28 // por $a3, $zero, $zero
    lui $v0, 0xC7
    addiu $a1, $zero, 1
    addiu $a0, $v0, -0xC30
    .word 0x70A03628 // por $a2, $a1, $zero
    jal func_220300
    .word 0x70003E28 // por $a3, $zero, $zero
    lui $v0, 0x22
    addiu $a1, $v0, 0x06A0
    lui $v0, 0xC6
    addiu $a2, $v0, -0xC70
    addiu $t0, $zero, 13
    lui $a3, 1
    .word 0x70004E28 // por $t1, $zero, $zero
    jal func_220380
    .word 0x72202628 // por $a0, $s1, $zero
    lw $a0, 0($s1)
    jal func_104B40
    .word 0x72002E28 // por $a1, $s0, $zero
    lq $ra, 0x20($sp)
    lq $s1, 0x10($sp)
    lq $s0, 0($sp)
    addiu $v0, $zero, 1
    jr $ra
    addiu $sp, $sp, 0x40
}
#else
int func_002205E0(void *arg) {
    func_220300(&D_00C7F390, 1, 0, 0);
    func_220300(&D_00C7F3B0, 1, 0, 0);
    func_220300(&D_00C7F3D0, 1, 1, 0);
    func_220380(&D_00C6F350, (void *)func_002206A0, D_00C6F390, 0x10000, 13, 0);
    func_104B40(D_00C6F350.id, arg);
    return 1;
}
#endif
}
