#include "kt_gs_render_253a40.h"

extern "C" {

static uint32_t s_call_count_253a40 = 0;

void func_00253A40() {
    s_call_count_253a40++;
}

uint32_t test_get_call_count_253a40() { return s_call_count_253a40; }

}
