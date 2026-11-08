#include "kt_gs_render_2528f0.h"

extern "C" {

static uint32_t s_call_count_2528f0 = 0;
static uint32_t s_call_count_252950 = 0;
static uint32_t s_call_count_25296c = 0;

void func_002528F0() {
    s_call_count_2528f0++;
}

void func_00252950() {
    s_call_count_252950++;
}

void func_0025296C() {
    s_call_count_25296c++;
}

uint32_t test_get_call_count_2528f0() { return s_call_count_2528f0; }
uint32_t test_get_call_count_252950() { return s_call_count_252950; }
uint32_t test_get_call_count_25296c() { return s_call_count_25296c; }

}
