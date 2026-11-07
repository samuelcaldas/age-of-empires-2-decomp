#include "kt_gs_render_23a500.h"
#include <vector>

static int s_calls = 0;

extern "C" {

void func_0023A500(void *a0, void *a1, void *a2, void *a3) {
    s_calls++;
    if (a0 != nullptr) {
        *(int *)a0 = 0x12345678;
    }
}

int get_23a500_calls() {
    return s_calls;
}

}
