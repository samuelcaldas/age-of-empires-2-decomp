#ifdef __MWERKS__
asm int rand(void) {
    lui $v0, (0x390000 >> 16)
    lui $a0, (0x41C64E6D >> 16)
    lw $a1, -0x3D4C($v0)
    ori $a0, $a0, (0x41C64E6D & 0xFFFF)
    lui $v0, (0x7FFFFFFF >> 16)
    lw $v1, 0x58($a1)
    ori $v0, $v0, (0x7FFFFFFF & 0xFFFF)
    mult $v1, $v1, $a0
    addiu $v1, $v1, 0x3039
    and $v0, $v1, $v0
    jr $ra
    sw $v1, 0x58($a1)
}
#else
extern unsigned int msl_internal_get_seed(void);
extern void msl_internal_set_seed(unsigned int val);

int rand(void) {
    unsigned int next = msl_internal_get_seed();
    next = next * 1103515245U + 12345U;
    msl_internal_set_seed(next);
    return (int)(next & 0x7FFFFFFFU);
}
#endif

int msl_rand(void) {
    return rand();
}
