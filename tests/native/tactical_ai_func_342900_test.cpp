#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include "tactical_ai_func_342900.h"

struct CallLog {
    std::string func_name;
    void *ptr_arg;
    const char *str_arg;
};

static std::vector<CallLog> g_calls;
static int g_188dc0_ret = 1;
static const char g_mock_string[] = "mock_unit_name";

extern "C" {
const char *func_00188DB0(void *info) {
    CallLog log;
    log.func_name = "func_00188DB0";
    log.ptr_arg = info;
    log.str_arg = NULL;
    g_calls.push_back(log);
    return g_mock_string;
}

void func_11ABBC(void *dst, const char *src) {
    CallLog log;
    log.func_name = "func_11ABBC";
    log.ptr_arg = dst;
    log.str_arg = src;
    g_calls.push_back(log);
    if (dst && src) {
        std::strcpy((char*)dst, src);
    }
}

int func_00188DC0(void *info) {
    CallLog log;
    log.func_name = "func_00188DC0";
    log.ptr_arg = info;
    log.str_arg = NULL;
    g_calls.push_back(log);
    return g_188dc0_ret;
}
}

static void test_func_342900_positive_branch_clears_and_sets_mode() {
    TacticalItem_342820 item;
    std::memset(&item, 0xAA, sizeof(item));
    g_calls.clear();
    g_188dc0_ret = 5;

    void *mock_info = (void*)0x12345678;
    func_00342900(&item, mock_info);

    // Behavioral assertions
    assert(item.field_24 == (int)(long)mock_info);

    // Call order: 188DB0 -> 11ABBC -> 188DC0
    assert(g_calls.size() == 3);
    assert(g_calls[0].func_name == "func_00188DB0");
    assert(g_calls[0].ptr_arg == mock_info);

    assert(g_calls[1].func_name == "func_11ABBC");
    assert(g_calls[1].ptr_arg == (void*)item.name);
    assert(g_calls[1].str_arg == g_mock_string);

    assert(g_calls[2].func_name == "func_00188DC0");
    assert(g_calls[2].ptr_arg == mock_info);

    assert(item.field_14 == 5);
    // Since field_14 > 0, branches to clear field_10, field_18 and set field_1C[0] = 2
    assert(item.field_10 == 0);
    assert(item.field_18 == 0);
    assert(item.field_1C[0] == 2);
    // Remaining bytes of field_1C must remain untouched (0xAA)
    assert(item.field_1C[1] == 0xAA);

    std::printf("PASS test_func_342900_positive_branch_clears_and_sets_mode\n");
}

static void test_func_342900_nonpositive_branch_leaves_fields_untouched() {
    TacticalItem_342820 item;
    std::memset(&item, 0x55, sizeof(item));
    g_calls.clear();
    g_188dc0_ret = 0; // zero: not > 0

    void *mock_info = (void*)0x56789ABC;
    func_00342900(&item, mock_info);

    assert(item.field_24 == (int)(long)mock_info);
    assert(item.field_14 == 0);

    // Since field_14 <= 0, fields +16, +24, +28 are NOT modified
    assert(item.field_10 == (int)0x55555555);
    assert(item.field_18 == (int)0x55555555);
    assert(item.field_1C[0] == 0x55);

    std::printf("PASS test_func_342900_nonpositive_branch_leaves_fields_untouched\n");
}

static void test_func_342900_negative_branch_leaves_fields_untouched() {
    TacticalItem_342820 item;
    std::memset(&item, 0x77, sizeof(item));
    g_calls.clear();
    g_188dc0_ret = -4; // negative

    void *mock_info = (void*)0xDEADBEEF;
    func_00342900(&item, mock_info);

    assert(item.field_24 == (int)(long)mock_info);
    assert(item.field_14 == -4);

    assert(item.field_10 == (int)0x77777777);
    assert(item.field_18 == (int)0x77777777);
    assert(item.field_1C[0] == 0x77);

    std::printf("PASS test_func_342900_negative_branch_leaves_fields_untouched\n");
}

int main() {
    test_func_342900_positive_branch_clears_and_sets_mode();
    test_func_342900_nonpositive_branch_leaves_fields_untouched();
    test_func_342900_negative_branch_leaves_fields_untouched();
    std::printf("ALL TACTICAL AI FUNC 342900 TESTS PASSED\n");
    return 0;
}
