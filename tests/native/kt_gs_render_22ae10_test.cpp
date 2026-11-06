#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22ae10.h"

extern int s_22ae10_ran;

int main() {
    printf("Running kt_gs_render_22ae10 native tests...\n");

    int dummy[128];
    memset(dummy, 0, sizeof(dummy));

    func_0022AE10(dummy, dummy, dummy);
    assert(s_22ae10_ran == 1);

    printf("kt_gs_render_22ae10 native tests passed!\n");
    return 0;
}
