#include "kt_gs_render_252080.h"

extern "C" {

static uint32_t s_call_count_252080 = 0;
static uint32_t s_call_count_252100 = 0;
static uint32_t s_call_count_252190 = 0;

void func_00252080() {
    s_call_count_252080++;
}

void func_00252100() {
    s_call_count_252100++;
}

void func_00252190() {
    s_call_count_252190++;
}

uint32_t test_get_call_count_252080() { return s_call_count_252080; }
uint32_t test_get_call_count_252100() { return s_call_count_252100; }
uint32_t test_get_call_count_252190() { return s_call_count_252190; }

}
