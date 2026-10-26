#ifndef TRADE_ACTION_HELPER_2181F0_FIXTURE_H
#define TRADE_ACTION_HELPER_2181F0_FIXTURE_H

#include <cassert>
#include <cstdint>
#include <cstring>

extern "C" void func_002181F0(void *self);
extern "C" int func_001ABA00(void *arg);
extern "C" int func_002257A0(void *arg, int value);
extern "C" int func_001ABA70(void *arg);

extern int result_handle;
extern int first_result;
extern int callback_count;
extern int begin_count;
extern int finish_count;
extern int lookup_count;
extern int range_call_count;
extern int mutate_callback_pointer;
extern void *callback_pointer_value;
extern void *range_argument_last;
extern int range_value_last;
extern int cleanup_count;
extern void *lookup_argument;
extern void *cleanup_argument;
extern int begin_argument;
extern int callback_mode;
extern int mutate_begin_pointer;
extern int mutate_callback_state;
extern int stop_after_callback;
extern int set_bound_after_callback;
extern int callback_sequence_last;
extern int callback_index_last;
extern int callback_handle_last;
extern void *callback_self_last;
extern void *vtable[73];
extern unsigned char *active_object;

void reset_fixture();
void initialize_object(unsigned char *object, short start, short bound);
void test_cases_basic(int case_number);
void test_cases_callbacks(int case_number);
void test_cases_mutations(int case_number);
void test_cases_wrap(int case_number);

#endif
