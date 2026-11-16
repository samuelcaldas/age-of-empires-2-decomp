/* Function: func_0012A458 (0x0012A458 - 0x0012A50C)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm int func_0012A458(void *a0) {
    .word 0x27bdffb0 // addiu $sp, $sp, -0x50
    .word 0x3c020049 // lui $v0, 0x49
    .word 0xffb10030 // sd $s1, 0x30($sp)
    .word 0x24050005 // addiu $a1, $zero, 5
    .word 0xffb00020 // sd $s0, 0x20($sp)
    .word 0x2407ffff // addiu $a3, $zero, -1
    .word 0xffbf0040 // sd $ra, 0x40($sp)
    .word 0x0080802d // move $s0, $a0
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x0000882d // move $s1, $zero
    .word 0x8e060040 // lw $a2, 0x40($s0)
    .word 0x244afa00 // addiu $t2, $v0, -0x600
    .word 0x69430007 // ldl $v1, 7($t2)
    .word 0x6d430000 // ldr $v1, ($t2)
    .word 0x6948000f // ldl $t0, 0xf($t2)
    .word 0x6d480008 // ldr $t0, 8($t2)
    .word 0x8d490010 // lw $t1, 0x10($t2)
    .word 0xb3a30007 // sdl $v1, 7($sp)
    .word 0xb7a30000 // sdr $v1, ($sp)
    .word 0xb3a8000f // sdl $t0, 0xf($sp)
    .word 0xb7a80008 // sdr $t0, 8($sp)
    .word 0xafa90010 // sw $t1, 0x10($sp)
    .word 0x0c04a562 // jal 0x129588
    .word 0x2484f9d8 // addiu $a0, $a0, -0x628
    .word 0x04410009 // bgez $v0, 0x12a4e0
    .word 0x00021080 // sll $v0, $v0, 2
    .word 0x3c040049 // lui $a0, 0x49
    .word 0x3c060049 // lui $a2, 0x49
    .word 0x2484f500 // addiu $a0, $a0, -0x5b00
    .word 0x24c6fa18 // addiu $a2, $a2, -0x5e8
    .word 0x0c0450c8 // jal 0x114320
    .word 0x240504c0 // addiu $a1, $zero, 0x4c0
    .word 0x10000007 // b 0x12a4f8
    .word 0x0220102d // move $v0, $s1
    .word 0x03a21821 // addu $v1, $sp, $v0
    .word 0x8c620000 // lw $v0, ($v1)
    .word 0x0040f809 // jalr $v0
    .word 0x0200202d // move $a0, $s0
    .word 0x0040882d // move $s1, $v0
    .word 0x0220102d // move $v0, $s1
    .word 0xdfbf0040 // ld $ra, 0x40($sp)
    .word 0xdfb10030 // ld $s1, 0x30($sp)
    .word 0xdfb00020 // ld $s0, 0x20($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0050 // addiu $sp, $sp, 0x50
}
#else

typedef int (*DispatchFn)(void *);

struct TargetStruct {
    char pad0[0x40];
    int field_40;
};

struct Pair {
    int key;
    int val;
};

struct JumpTable {
    DispatchFn handlers[5];
};

int func_00129588(const Pair *pairs, int count, int key, int default_val);
void func_114320(const char *file, int line, const char *assertion);

extern const Pair D_0048F9D8[];
extern const JumpTable D_0048FA00;
extern const char D_0048F500[];
extern const char D_0048FA18[];

int func_0012A458(TargetStruct *target) {
    JumpTable localTable = D_0048FA00;
    int idx = func_00129588(D_0048F9D8, 5, target->field_40, -1);
    if (idx < 0) {
        func_114320(D_0048F500, 0x4C0, D_0048FA18);
        return 0;
    }
    return localTable.handlers[idx](target);
}

#endif

}
