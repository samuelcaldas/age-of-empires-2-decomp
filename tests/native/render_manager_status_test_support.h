#ifndef RENDER_MANAGER_STATUS_TEST_SUPPORT_H
#define RENDER_MANAGER_STATUS_TEST_SUPPORT_H

#include "render_manager_status.h"
#include <initializer_list>

enum class StatusCall {
    Func191050,
    Func190FF0,
    GetString,
    Func19A1E0,
    Func19A1D0,
    Func19A1F0,
};

struct MockStatusCalls {
    int func_191050_ret{};
    void *last_191050_self{};
    int last_191050_arg{};
    int count_191050{};
    int func_190FF0_ret{};
    void *last_190FF0_self{};
    int last_190FF0_arg{};
    int count_190FF0{};
    int last_get_string_id{};
    char *last_get_string_dest{};
    int last_get_string_max_len{};
    char *last_get_string_return{};
    char *get_string_return_override{};
    int count_get_string{};
    void *last_19a1e0_ptr{};
    int last_19a1e0_arg{};
    int count_19a1e0{};
    void *last_19a1d0_ptr{};
    int last_19a1d0_arg{};
    int count_19a1d0{};
    void *last_19a1f0_ptr{};
    int count_19a1f0{};
    void **field_1600_slot_to_mutate{};
    void *field_1600_value_after_19a1e0{};
    StatusCall call_order[16]{};
    int call_count{};
};

extern MockStatusCalls g_mock_status;

void reset_mock_status();
void assert_call_order(std::initializer_list<StatusCall> expected);

void test_status_4b1_precedence();
void test_status_4b2_precedence();
void test_status_value_zero();
void test_status_value_three();
void test_status_value_four();
void test_status_below_threshold();
void test_status_equal_threshold();
void test_status_above_threshold();
void test_status_unsigned_high_value();
void test_status_unsigned_high_threshold();
void test_status_string_contract_and_shared_buffer();
void test_status_dispatch_order_and_arguments();
void test_status_dispatch_reloads_field_1600();
void test_status_dispatch_forwards_null_field();
void test_status_empty_stubs();

#endif
