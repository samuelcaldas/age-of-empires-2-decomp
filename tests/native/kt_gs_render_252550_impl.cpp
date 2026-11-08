#include "kt_gs_render_252550.h"

extern "C" {

static uint32_t s_call_count_252550 = 0;

void func_00252550() {
    s_call_count_252550++;
}

uint32_t test_get_call_count_252550() { return s_call_count_252550; }

}
