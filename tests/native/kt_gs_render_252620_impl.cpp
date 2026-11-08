#include "kt_gs_render_252620.h"

extern "C" {

static uint32_t s_call_count_252620 = 0;

void func_00252620() {
    s_call_count_252620++;
}

uint32_t test_get_call_count_252620() { return s_call_count_252620; }

}
