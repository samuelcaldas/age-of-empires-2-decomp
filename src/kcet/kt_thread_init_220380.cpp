#pragma exceptions off
#include "kt_thread_init_220380.h"

extern "C" {
int func_104B20(...);
int func_104C20(...);
int func_118DE0(...);
int func_105748(...);
int func_104A00(...);
int func_1057B0(...);

#ifdef __MWERKS__
asm int func_00220380(void *thread, void *entry, void *stack, int stack_size, int priority, int option) {
    .word 0x27BDFF90
    .word 0x7FBF0030
    .word 0x7FB10020
    .word 0x7FB00010
    .word 0xAC850008
    .word 0xAC86000C
    .word 0xAC870010
    .word 0x27820000
    .word 0xAC880018
    .word 0x70808E28
    .word 0xAC820014
    jal func_104B20
    .word 0x26240004
    .word 0x70408628
    .word 0x27A50040
    .word 0x72002628
    jal func_104C20
    .word 0xAE300000
    .word 0x8FA30058
    .word 0x3C020049
    .word 0x24442D40
    .word 0xFFA30000
    .word 0x8FA2005C
    .word 0xFFA20008
    .word 0x8FA70044
    .word 0x8FA80048
    .word 0x8FAA0050
    .word 0x8FA60040
    .word 0x8FA9004C
    .word 0x8FAB0054
    jal func_118DE0
    .word 0x72002E28
    .word 0x72001628
    .word 0x7BBF0030
    .word 0x7BB10020
    .word 0x7BB00010
    .word 0x03E00008
    .word 0x27BD0070
}

asm int func_00220420(void *a0, int a1, void *a2, int a3) {
    .word 0x27BDFFA0
    .word 0x7FBF0050
    .word 0x7FB40040
    .word 0x7FB30030
    .word 0x7FB20020
    .word 0x7FB10010
    .word 0x70A09E28
    .word 0x7080A628
    .word 0x70C09628
    .word 0x70E08E28
    .word 0x72602628
    jal func_105748
    .word 0x7FB00000
    .word 0x72602628
    .word 0x72402E28
    jal func_104A00
    .word 0x72203628
    .word 0x70408628
    .word 0x2402FFFF
    .word 0x1202FFFA
    .word 0x72602628
    jal func_1057B0
    .word 0x72602628
    .word 0xAE900000
    .word 0x3C020049
    .word 0xAE930004
    .word 0xAE92000C
    .word 0x24442DA0
    .word 0x72603628
    .word 0x72002E28
    jal func_118DE0
    .word 0xAE800008
    .word 0x72001628
    .word 0x7BBF0050
    .word 0x7BB40040
    .word 0x7BB30030
    .word 0x7BB20020
    .word 0x7BB10010
    .word 0x7BB00000
    .word 0x03E00008
    .word 0x27BD0060
}
#else
int func_00220380(void *thread, void *entry, void *stack, int stack_size, int priority, int option) {
    int *t = (int *)thread;
    t[2] = (int)entry;
    t[3] = (int)stack;
    t[4] = stack_size;
    t[6] = priority;
    int id = func_104B20((char *)thread + 4);
    func_104C20(id, 0);
    t[0] = id;
    return id;
}

int func_00220420(void *a0, int a1, void *a2, int a3) {
    func_105748(a1);
    int res = func_104A00(a1, a2, a3);
    func_1057B0(a1);
    int *arr = (int *)a0;
    arr[0] = res;
    arr[1] = a1;
    arr[3] = (int)a2;
    arr[2] = 0;
    return res;
}
#endif
}
