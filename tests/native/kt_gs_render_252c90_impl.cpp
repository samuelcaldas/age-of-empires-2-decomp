#include "kt_gs_render_252c90.h"

extern "C" {

static uint32_t s_call_count_252c90 = 0;
static uint32_t s_call_count_252ca0 = 0;
static uint32_t s_call_count_252ce0 = 0;
static uint32_t s_call_count_252cf0 = 0;
static uint32_t s_call_count_252d00 = 0;
static uint32_t s_call_count_252d10 = 0;
static uint32_t s_call_count_252d40 = 0;

void func_00252C90() { s_call_count_252c90++; }
void func_00252CA0() { s_call_count_252ca0++; }
void func_00252CE0() { s_call_count_252ce0++; }
void func_00252CF0() { s_call_count_252cf0++; }
void func_00252D00() { s_call_count_252d00++; }
void func_00252D10() { s_call_count_252d10++; }
void func_00252D40() { s_call_count_252d40++; }

uint32_t test_get_call_count_252c90() { return s_call_count_252c90; }
uint32_t test_get_call_count_252ca0() { return s_call_count_252ca0; }
uint32_t test_get_call_count_252ce0() { return s_call_count_252ce0; }
uint32_t test_get_call_count_252cf0() { return s_call_count_252cf0; }
uint32_t test_get_call_count_252d00() { return s_call_count_252d00; }
uint32_t test_get_call_count_252d10() { return s_call_count_252d10; }
uint32_t test_get_call_count_252d40() { return s_call_count_252d40; }

}
