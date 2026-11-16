/* Function: func_001295D0 (0x001295D0 - 0x00129620)
 * Origin: SLES-50282, KCET kt_hd / kt_libcdvd_server module (originally compiled with ee-gcc -O2 -G0)
 */

extern "C" {

#if defined(__mips__)
asm void func_001295D0(void) {
    .word 0x27bdffe0
    .word 0x3c020049
    .word 0xffbf0010
    .word 0x0080302d
    .word 0x03a0202d
    .word 0x24050002
    .word 0x244af4d0
    .word 0x69430007
    .word 0x6d430000
    .word 0x6948000f
    .word 0x6d480008
    .word 0xb3a30007
    .word 0xb7a30000
    .word 0xb3a8000f
    .word 0xb7a80008
    .word 0x0c04a562
    .word 0x24070007
    .word 0xdfbf0010
    .word 0x03e00008
    .word 0x27bd0020
}
#else
struct Pair {
    int key;
    int val;
};

int func_00129588(const Pair *pairs, int count, int key);

int func_001295D0(int key) {
    static const Pair s_defaultPairs[2] = {
        {1, 6},
        {2, 1}
    };
    Pair localPairs[2];
    localPairs[0] = s_defaultPairs[0];
    localPairs[1] = s_defaultPairs[1];
    return func_00129588(localPairs, 2, key);
}
#endif

}
