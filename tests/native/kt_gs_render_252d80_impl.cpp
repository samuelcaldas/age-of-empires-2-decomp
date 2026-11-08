#include "kt_gs_render_252d80.h"

extern "C" {

static uint32_t s_call_count_252d80 = 0;

void func_00252D80() {
    s_call_count_252d80++;
}

uint32_t test_get_call_count_252d80() { return s_call_count_252d80; }

}
