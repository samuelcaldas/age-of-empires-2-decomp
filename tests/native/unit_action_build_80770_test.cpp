// Tests for func_00280770 (and func_280770) — Milestone 152 (96B)
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include "unit_action_build_80770.h"

struct ActionManager {
    void *vtable;
    int field_4;
    void *field_8;
};

static int g_baselist_calls = 0;
static void *g_baselist_last_self = NULL;
static int g_baselist_last_arg = -1;

static int g_vec_ctor_calls = 0;
static void *g_vec_ctor_last_self = NULL;

static std::vector<int> g_call_order; // 1: BaseList, 2: __vec_ctor

extern "C" {
    char __vt__004DC9F0 = 0;

    void func_138A50(void *self, int arg1) {
        g_baselist_calls++;
        g_baselist_last_self = self;
        g_baselist_last_arg = arg1;
        g_call_order.push_back(1);
    }

    void func_100670(void *self) {
        g_vec_ctor_calls++;
        g_vec_ctor_last_self = self;
        g_call_order.push_back(2);
    }
}

static void reset_mocks() {
    g_baselist_calls = 0;
    g_baselist_last_self = NULL;
    g_baselist_last_arg = -1;
    g_vec_ctor_calls = 0;
    g_vec_ctor_last_self = NULL;
    g_call_order.clear();
}

static void test_null_self_returns_null() {
    reset_mocks();
    void *res = func_00280770(NULL, 10);
    assert(res == NULL);
    assert(g_baselist_calls == 0);
    assert(g_vec_ctor_calls == 0);
    printf("PASS test_null_self_returns_null\n");
}

static void test_non_null_positive_count() {
    reset_mocks();
    ActionManager mgr;
    mgr.vtable = NULL;
    mgr.field_4 = 0;
    mgr.field_8 = NULL;

    void *res = func_00280770(&mgr, 5);
    assert(res == &mgr);
    assert(mgr.vtable == (void *)&__vt__004DC9F0);
    assert(g_baselist_calls == 1);
    assert(g_baselist_last_self == &mgr);
    assert(g_baselist_last_arg == 0);
    assert(g_vec_ctor_calls == 1);
    assert(g_vec_ctor_last_self == &mgr);

    // Call order: BaseList(0) first, then __vec_ctor
    assert(g_call_order.size() == 2);
    assert(g_call_order[0] == 1 && g_call_order[1] == 2);

    printf("PASS test_non_null_positive_count\n");
}

static void test_non_null_zero_and_negative_counts() {
    const short counts[] = { 0, -1, -5, -32768 };
    const size_t num_counts = sizeof(counts) / sizeof(counts[0]);

    for (size_t i = 0; i < num_counts; ++i) {
        reset_mocks();
        ActionManager mgr;
        mgr.vtable = NULL;

        void *res = func_00280770(&mgr, counts[i]);
        assert(res == &mgr);
        assert(mgr.vtable == (void *)&__vt__004DC9F0);
        assert(g_baselist_calls == 1);
        assert(g_baselist_last_self == &mgr);
        assert(g_baselist_last_arg == 0);
        // __vec_ctor must NOT be called when count <= 0!
        assert(g_vec_ctor_calls == 0);
        assert(g_call_order.size() == 1);
        assert(g_call_order[0] == 1);
    }
    printf("PASS test_non_null_zero_and_negative_counts\n");
}

static void test_alias() {
    reset_mocks();
    ActionManager mgr;
    mgr.vtable = NULL;

    void *res = func_280770(&mgr, 3);
    assert(res == &mgr);
    assert(mgr.vtable == (void *)&__vt__004DC9F0);
    assert(g_baselist_calls == 1);
    assert(g_vec_ctor_calls == 1);
    printf("PASS test_alias\n");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int case_num = argv[1][0] - '0';
        if (case_num == 0) {
            test_null_self_returns_null();
            return 0;
        } else if (case_num == 1) {
            test_non_null_positive_count();
            return 0;
        } else if (case_num == 2) {
            test_non_null_zero_and_negative_counts();
            return 0;
        } else if (case_num == 3) {
            test_alias();
            return 0;
        }
    }
    test_null_self_returns_null();
    test_non_null_positive_count();
    test_non_null_zero_and_negative_counts();
    test_alias();
    printf("All unit_action_build_80770 tests passed!\n");
    return 0;
}
