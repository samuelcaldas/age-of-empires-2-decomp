/* Function: func_0012A288 (0x0012A288 - 0x0012A2A0)
 * Origin: SLES-50282, KCET kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm int func_0012A288(void *a0) {
    .word 0x8c820020 // lw $v0, 0x20($a0)
    .word 0x8c830028 // lw $v1, 0x28($a0)
    .word 0x8c85003c // lw $a1, 0x3c($a0)
    .word 0x00431021 // addu $v0, $v0, $v1
    .word 0x03e00008 // jr $ra
    .word 0x00451021 // addu $v0, $v0, $a1
}
#else

struct TargetStruct {
    char pad0[0x20];
    int field_20;
    int field_24;
    int field_28;
    char pad2C[0x3C - 0x2C];
    int field_3C;
};

int func_0012A288(TargetStruct *target) {
    return target->field_20 + target->field_28 + target->field_3C;
}

#endif

}
