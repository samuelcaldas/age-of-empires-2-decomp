#include <cassert>
#include <cstdio>
#include <cstring>
#include "tactical_ai_func_342820.h"

static int g_func_11abbc_called = 0;
static void *g_func_11abbc_dst = NULL;
static const char *g_func_11abbc_src = NULL;

extern "C" {
void func_11ABBC(void *dst, const char *src) {
    g_func_11abbc_called++;
    g_func_11abbc_dst = dst;
    g_func_11abbc_src = src;
    if (dst && src) {
        std::strcpy((char*)dst, src);
    }
}
}

static void test_func_342820_clears_fields_and_calls_11abbc() {
    TacticalItem_342820 item;
    std::memset(&item, 0xAA, sizeof(item));
    g_func_11abbc_called = 0;
    g_func_11abbc_dst = NULL;
    g_func_11abbc_src = NULL;

    func_00342820(&item);

    assert(g_func_11abbc_called == 1);
    assert(g_func_11abbc_dst == &item);
    assert(g_func_11abbc_src == D_004D5668);

    assert(item.field_10 == 0);
    assert(item.field_14 == 0);
    assert(item.field_18 == 0);
    assert(item.field_24 == 0);

    for (int i = 0; i < 7; i++) {
        assert(item.field_1C[i] == 0);
    }

    // Byte at offset 35 (pad_23) is outside the 7-byte loop and must remain untouched
    assert(item.pad_23 == (char)0xAA);

    std::printf("PASS test_func_342820_clears_fields_and_calls_11abbc\n");
}

int main() {
    test_func_342820_clears_fields_and_calls_11abbc();
    std::printf("ALL TACTICAL AI FUNC 342820 TESTS PASSED\n");
    return 0;
}
