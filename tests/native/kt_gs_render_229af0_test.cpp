#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_229af0.h"

int main() {
    printf("Running kt_gs_render_229af0 native tests...\n");

    int dummy[32];
    memset(dummy, 0, sizeof(dummy));

    // Test func_00229BC0 returns 1
    int res = func_00229BC0(dummy, dummy, 1, 2, dummy, dummy);
    assert(res == 1);

    printf("kt_gs_render_229af0 native tests passed!\n");
    return 0;
}
