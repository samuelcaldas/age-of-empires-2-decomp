#include "kt_gs_render_252fc0.h"

extern "C" {

static uint32_t s_call_count_252fc0 = 0;
static uint32_t s_call_count_2532b0 = 0;

void func_00252FC0() { s_call_count_252fc0++; }
void func_002532B0() { s_call_count_2532b0++; }

uint32_t test_get_call_count_252fc0() { return s_call_count_252fc0; }
uint32_t test_get_call_count_2532b0() { return s_call_count_2532b0; }

}
