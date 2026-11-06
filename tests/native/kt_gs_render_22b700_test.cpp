#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_22b700.h"

extern int s_22b700_ran;

int main() {
    printf("Running kt_gs_render_22b700 native tests...\n");

    int dummy[128];
    memset(dummy, 0, sizeof(dummy));

    func_0022B700(dummy, dummy, dummy);
    assert(s_22b700_ran > 0);

    float val = func_0022B870(10, 5);
    assert(val != 0.0f);

    printf("kt_gs_render_22b700 native tests passed!\n");
    return 0;
}
