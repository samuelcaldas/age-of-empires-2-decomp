#include "kt_gs_render_253b00.h"

extern "C" {

static uint32_t s_call_count_253b00 = 0;

void func_00253B00() {
    s_call_count_253b00++;
}

uint32_t test_get_call_count_253b00() { return s_call_count_253b00; }

}
