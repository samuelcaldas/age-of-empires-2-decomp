#include "kt_gs_render_253c20.h"

extern "C" {

static uint32_t s_call_count_253c20 = 0;

void func_00253C20() {
    s_call_count_253c20++;
}

uint32_t test_get_call_count_253c20() { return s_call_count_253c20; }

}
