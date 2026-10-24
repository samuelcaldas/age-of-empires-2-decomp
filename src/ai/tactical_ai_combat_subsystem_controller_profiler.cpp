#include "tactical_ai_combat_subsystem_controller_profiler.h"

int func_00329F00(void *a0, void *a1, void *a2, void *a3, void *t0, void *t1) {
    unsigned int start = func_2261C0();
    int ret = func_1F60F0(a0, a1, a2, a3, t0, t1);
    unsigned int end = func_2261C0();
    func_184B60(D_004E3180, 13, end - start);
    return ret;
}
