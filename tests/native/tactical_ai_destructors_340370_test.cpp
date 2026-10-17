#include <cassert>
#include <cstdio>
#include "tactical_ai_destructors_340370.h"

// Mock external functions and vtables for native test
static void *g_last_base_called_ptr = nullptr;
static int g_last_base_called_flag = -1;
static int g_base_call_count = 0;
static void *g_last_delete_called_ptr = nullptr;
static int g_delete_call_count = 0;

void *__vt__004DF080 = (void*)0x4DF080;
void *__vt__004DF1B0 = (void*)0x4DF1B0;
void *__vt__004DF2E0 = (void*)0x4DF2E0;

extern "C" {
void func_210490(void *ptr, int flag) {
    g_last_base_called_ptr = ptr;
    g_last_base_called_flag = flag;
    g_base_call_count++;
}

void func_216020(void *ptr, int flag) {
    g_last_base_called_ptr = ptr;
    g_last_base_called_flag = flag;
    g_base_call_count++;
}

void func_208E20(void *ptr, int flag) {
    g_last_base_called_ptr = ptr;
    g_last_base_called_flag = flag;
    g_base_call_count++;
}

void func_100670(void *ptr) {
    g_last_delete_called_ptr = ptr;
    g_delete_call_count++;
}
}

static void reset_mocks() {
    g_last_base_called_ptr = nullptr;
    g_last_base_called_flag = -1;
    g_base_call_count = 0;
    g_last_delete_called_ptr = nullptr;
    g_delete_call_count = 0;
}

static void test_null_pointer_handling() {
    reset_mocks();
    assert(func_00340370(nullptr, 0) == nullptr);
    assert(func_00340370(nullptr, 1) == nullptr);
    assert(func_003403D0(nullptr, 0) == nullptr);
    assert(func_003403D0(nullptr, 1) == nullptr);
    assert(func_00340430(nullptr, 0) == nullptr);
    assert(func_00340430(nullptr, 1) == nullptr);
    assert(g_base_call_count == 0);
    assert(g_delete_call_count == 0);
    printf("PASS test_null_pointer_handling\n");
}

static void test_destructor_340370_behavior() {
    reset_mocks();
    TacticalObj_340370 obj;
    obj.vtable = nullptr;

    void *res = func_00340370(&obj, 0);
    assert(res == &obj);
    assert(obj.vtable == &__vt__004DF080);
    assert(g_last_base_called_ptr == &obj);
    assert(g_last_base_called_flag == 0);
    assert(g_base_call_count == 1);
    assert(g_delete_call_count == 0);

    // With delete flag > 0
    reset_mocks();
    res = func_00340370(&obj, 1);
    assert(res == &obj);
    assert(g_delete_call_count == 1);
    assert(g_last_delete_called_ptr == &obj);

    printf("PASS test_destructor_340370_behavior\n");
}

static void test_destructor_3403d0_behavior() {
    reset_mocks();
    TacticalObj_340370 obj;
    obj.vtable = nullptr;

    void *res = func_003403D0(&obj, 0);
    assert(res == &obj);
    assert(obj.vtable == &__vt__004DF1B0);
    assert(g_last_base_called_ptr == &obj);
    assert(g_last_base_called_flag == 0);
    assert(g_base_call_count == 1);
    assert(g_delete_call_count == 0);

    // With delete flag > 0
    reset_mocks();
    res = func_003403D0(&obj, 1);
    assert(res == &obj);
    assert(g_delete_call_count == 1);
    assert(g_last_delete_called_ptr == &obj);

    printf("PASS test_destructor_3403d0_behavior\n");
}

static void test_destructor_340430_behavior() {
    reset_mocks();
    TacticalObj_340370 obj;
    obj.vtable = nullptr;

    void *res = func_00340430(&obj, 0);
    assert(res == &obj);
    assert(obj.vtable == &__vt__004DF2E0);
    assert(g_last_base_called_ptr == &obj);
    assert(g_last_base_called_flag == 0);
    assert(g_base_call_count == 1);
    assert(g_delete_call_count == 0);

    // With delete flag > 0
    reset_mocks();
    res = func_00340430(&obj, 1);
    assert(res == &obj);
    assert(g_delete_call_count == 1);
    assert(g_last_delete_called_ptr == &obj);

    printf("PASS test_destructor_340430_behavior\n");
}

int main() {
    test_null_pointer_handling();
    test_destructor_340370_behavior();
    test_destructor_3403d0_behavior();
    test_destructor_340430_behavior();
    printf("All tactical_ai_destructors_340370 native tests passed!\n");
    return 0;
}
