#include "kt_gs_render_252980.h"

extern "C" {

static uint32_t s_call_count_252980 = 0;

void func_00252980() {
    s_call_count_252980++;
}

uint32_t test_get_call_count_252980() { return s_call_count_252980; }

}
