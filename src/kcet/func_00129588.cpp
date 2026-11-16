/* Function: func_00129588 (0x00129588 - 0x001295D0)
 * Origin: SLES-50282, KCET kt_hd module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_00129588(void) {
    .word 0x18a0000f // 00129588 blez $a1, 0x1295c8
    .word 0x0000402d // 0012958C move $t0, $zero
    .word 0x8c820000 // 00129590 lw $v0, ($a0)
    .word 0x14460004 // 00129594 bne $v0, $a2, 0x1295a8
    .word 0x25080001 // 00129598 addiu $t0, $t0, 1
    .word 0x1000000a // 0012959C b 0x1295c8
    .word 0x8c870004 // 001295A0 lw $a3, 4($a0)
    .word 0x00000000 // 001295A4 nop
    .word 0x0105102a // 001295A8 slt $v0, $t0, $a1
    .word 0x10400006 // 001295AC beqz $v0, 0x1295c8
    .word 0x000810c0 // 001295B0 sll $v0, $t0, 3
    .word 0x00441021 // 001295B4 addu $v0, $v0, $a0
    .word 0x8c430000 // 001295B8 lw $v1, ($v0)
    .word 0x1466fffa // 001295BC bne $v1, $a2, 0x1295a8
    .word 0x25080001 // 001295C0 addiu $t0, $t0, 1
    .word 0x8c470004 // 001295C4 lw $a3, 4($v0)
    .word 0x03e00008 // 001295C8 jr $ra
    .word 0x00e0102d // 001295CC move $v0, $a3
}
#else
struct Pair {
    int key;
    int val;
};

int func_00129588(const Pair *pairs, int count, int key) {
    int val;
    int i = 0;
    if (count <= 0) {
        return val;
    }
    do {
        if (pairs[i].key == key) {
            val = pairs[i].val;
            break;
        }
        i++;
    } while (i < count);
    return val;
}
#endif

}
