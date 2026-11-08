#include "kt_gs_render_253980.h"

extern "C" {

static uint32_t s_call_count_253980 = 0;
static uint32_t s_call_count_2539d0 = 0;
static uint32_t s_call_count_253910 = 0;

void func_00253980() { s_call_count_253980++; }
void func_002539D0() { s_call_count_2539d0++; }
void func_00253A10() { s_call_count_253910++; }

uint32_t test_get_call_count_253980() { return s_call_count_253980; }
uint32_t test_get_call_count_2539d0() { return s_call_count_2539d0; }
uint32_t test_get_call_count_253a10() { return s_call_count_253910; }

}
