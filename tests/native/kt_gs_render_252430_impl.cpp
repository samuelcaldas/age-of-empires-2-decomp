#include "kt_gs_render_252430.h"

extern "C" {

static uint32_t s_call_count_252430 = 0;

void func_00252430() {
    s_call_count_252430++;
}

uint32_t test_get_call_count_252430() { return s_call_count_252430; }

}
