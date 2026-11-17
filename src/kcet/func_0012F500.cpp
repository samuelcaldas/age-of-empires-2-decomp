#pragma exceptions off

typedef signed int s32;
typedef unsigned int u32;

extern "C" {

#if defined(__mips__)
asm s32 func_0012F500(void *a0, void *a1, s32 *a2) {
    .word 0x27bdff70 // addiu $sp, $sp, -0x90
    .word 0xffb70070 // sd $s7, 0x70($sp)
    .word 0xffb60060 // sd $s6, 0x60($sp)
    .word 0x00c0b82d // move $s7, $a2
    .word 0xffb50050 // sd $s5, 0x50($sp)
    .word 0xffb30030 // sd $s3, 0x30($sp)
    .word 0x0000a82d // move $s5, $zero
    .word 0xffb20020 // sd $s2, 0x20($sp)
    .word 0x0080982d // move $s3, $a0
    .word 0xffb10010 // sd $s1, 0x10($sp)
    .word 0x00a0202d // move $a0, $a1
    .word 0xffbf0080 // sd $ra, 0x80($sp)
    .word 0x0000882d // move $s1, $zero
    .word 0xffb40040 // sd $s4, 0x40($sp)
    .word 0x0000902d // move $s2, $zero
    .word 0xffb00000 // sd $s0, ($sp)
    .word 0x8e70001c // lw $s0, 0x1c($s3)
    .word 0x0c04bd2c // jal 0x12f4b0
    .word 0x8e740018 // lw $s4, 0x18($s3)
    .word 0x1a80000f // blez $s4, 0x12f58c
    .word 0x0040b02d // move $s6, $v0
    .word 0x2610001c // addiu $s0, $s0, 0x1c
    .word 0x0260202d // move $a0, $s3
    .word 0x0c04bdec // jal 0x12f7b0
    .word 0x0220282d // move $a1, $s1
    .word 0x10400005 // beqz $v0, 0x12f57c
    .word 0x02c0282d // move $a1, $s6
    .word 0x8e040000 // lw $a0, ($s0)
    .word 0x0c04bd32 // jal 0x12f4c8
    .word 0x26b50001 // addiu $s5, $s5, 1
    .word 0x02429021 // addu $s2, $s2, $v0
    .word 0x26310001 // addiu $s1, $s1, 1
    .word 0x0234102a // slt $v0, $s1, $s4
    .word 0x1440fff4 // bnez $v0, 0x12f558
    .word 0x26100020 // addiu $s0, $s0, 0x20
    .word 0x56e00001 // bnel $s7, $zero, 0x12f594
    .word 0xaef50000 // sw $s5, ($s7)
    .word 0x0240102d // move $v0, $s2
    .word 0xdfbf0080 // ld $ra, 0x80($sp)
    .word 0xdfb70070 // ld $s7, 0x70($sp)
    .word 0xdfb60060 // ld $s6, 0x60($sp)
    .word 0xdfb50050 // ld $s5, 0x50($sp)
    .word 0xdfb40040 // ld $s4, 0x40($sp)
    .word 0xdfb30030 // ld $s3, 0x30($sp)
    .word 0xdfb20020 // ld $s2, 0x20($sp)
    .word 0xdfb10010 // ld $s1, 0x10($sp)
    .word 0xdfb00000 // ld $s0, ($sp)
    .word 0x03e00008 // jr $ra
    .word 0x27bd0090 // addiu $sp, $sp, 0x90
}
#else
void *func_0012F4B0(void *a0);
s32 func_0012F7B0(void *a0, s32 a1);
s32 func_0012F4C8(s32 a0, void *a1);

struct Container {
    char pad[0x18];
    s32 count;
    char *items;
};

s32 func_0012F500(Container *a0, void *a1, s32 *a2) {
    s32 match_count = 0;
    s32 total = 0;
    char *curr = a0->items;
    s32 count = a0->count;
    void *ref = func_0012F4B0(a1);

    if (count > 0) {
        curr += 0x1C;
        s32 i = 0;
        do {
            if (func_0012F7B0(a0, i) != 0) {
                total += func_0012F4C8(*(s32 *)curr, ref);
                match_count++;
            }
            i++;
            curr += 0x20;
        } while (i < count);
    }

    if (a2 != 0) {
        *a2 = match_count;
    }

    return total;
}
#endif

}
