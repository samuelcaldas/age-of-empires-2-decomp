#include <cassert>
#include <cstdio>
#include <cstring>
#include "kt_gs_render_229cd0.h"

extern "C" int s_calls;

int main() {
    printf("Running kt_gs_render_229cd0 native tests...\n");

    int dummy[64];
    memset(dummy, 0, sizeof(dummy));

    func_00229CD0(dummy, dummy, dummy, dummy, dummy);
    assert(s_calls > 0);

    printf("kt_gs_render_229cd0 native tests passed!\n");
    return 0;
}
