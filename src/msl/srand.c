#ifdef __MWERKS__
asm void srand(unsigned int seed) {
    lui $v0, (0x390000 >> 16)
    lw $v1, -0x3D4C($v0)
    jr $ra
    sw $a0, 0x58($v1)
}
#else
static unsigned int s_native_rand_seed = 1;
void srand(unsigned int seed) {
    s_native_rand_seed = seed;
}
unsigned int msl_internal_get_seed(void) {
    return s_native_rand_seed;
}
void msl_internal_set_seed(unsigned int val) {
    s_native_rand_seed = val;
}
#endif

void msl_srand(unsigned int seed) {
    srand(seed);
}
