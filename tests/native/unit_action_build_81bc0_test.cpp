#include <cassert>
#include <cstdio>
#include <vector>

#include "unit_action_build_81bc0.h"

static int g_func_00298880_calls = 0;
static void *g_func_00298880_arg_mgr = 0;
static int g_func_00298880_arg_id = 0;
static int g_func_00298880_ret = -1;

static int g_func_00203010_calls = 0;
static void *g_func_00203010_arg_mgr = 0;
static int g_func_00203010_arg_id = 0;
static int g_func_00203010_ret = 1;

static int g_func_002E01E0_calls = 0;
static void *g_func_002E01E0_arg_mgr = 0;
static short g_func_002E01E0_arg_id = 0;
static int g_func_002E01E0_arg_2 = -1;
static int g_func_002E01E0_arg_3 = -1;
static int g_func_002E01E0_arg_4 = -1;
static int g_func_002E01E0_arg_5 = -1;
static float g_func_002E01E0_arg_ratio = 0.0f;
static int g_func_002E01E0_ret = 1;

static int g_func_00297C20_calls = 0;
static void *g_func_00297C20_arg_mgr = 0;
static int g_func_00297C20_arg_id = 0;
static int g_func_00297C20_ret = -1;

static int g_func_00298100_calls = 0;
static void *g_func_00298100_arg_mgr = 0;
static int g_func_00298100_arg_id = 0;
static int g_func_00298100_ret = 0;

static int g_func_00284720_calls = 0;
static void *g_func_00284720_arg_mgr = 0;
static int g_func_00284720_arg_id = 0;
static int g_func_00284720_arg_mode = -1;

static std::vector<int> g_call_sequence;
enum {
    CALL_298880 = 1,
    CALL_203010 = 2,
    CALL_2E01E0 = 3,
    CALL_297C20 = 4,
    CALL_298100 = 5,
    CALL_284720 = 6
};

static void *g_dummy_4e3420 = (void *)0x11111111;
static void *g_dummy_4e3424 = (void *)0x22222222;
static void *g_dummy_4e3428 = (void *)0x33333333;

extern "C" {
int D_4E3414 = 0;
int D_004E3414 = 0;

void *D_4E3420 = g_dummy_4e3420;
void *D_004E3420 = g_dummy_4e3420;

void *D_4E3424 = g_dummy_4e3424;
void *D_004E3424 = g_dummy_4e3424;

void *D_4E3428 = g_dummy_4e3428;
void *D_004E3428 = g_dummy_4e3428;

int func_00298880(void *mgr, int id) {
    g_func_00298880_calls++;
    g_func_00298880_arg_mgr = mgr;
    g_func_00298880_arg_id = id;
    g_call_sequence.push_back(CALL_298880);
    return g_func_00298880_ret;
}

int func_00203010(void *mgr, int id) {
    g_func_00203010_calls++;
    g_func_00203010_arg_mgr = mgr;
    g_func_00203010_arg_id = id;
    g_call_sequence.push_back(CALL_203010);
    return g_func_00203010_ret;
}

int func_002E01E0(void *owner, short proto_id, int arg2, int arg3, int arg4, int arg5, float ratio) {
    g_func_002E01E0_calls++;
    g_func_002E01E0_arg_mgr = owner;
    g_func_002E01E0_arg_id = proto_id;
    g_func_002E01E0_arg_2 = arg2;
    g_func_002E01E0_arg_3 = arg3;
    g_func_002E01E0_arg_4 = arg4;
    g_func_002E01E0_arg_5 = arg5;
    g_func_002E01E0_arg_ratio = ratio;
    g_call_sequence.push_back(CALL_2E01E0);
    return g_func_002E01E0_ret;
}

int func_00297C20(void *mgr, int id) {
    g_func_00297C20_calls++;
    g_func_00297C20_arg_mgr = mgr;
    g_func_00297C20_arg_id = id;
    g_call_sequence.push_back(CALL_297C20);
    return g_func_00297C20_ret;
}

int func_00298100(void *mgr, int id) {
    g_func_00298100_calls++;
    g_func_00298100_arg_mgr = mgr;
    g_func_00298100_arg_id = id;
    g_call_sequence.push_back(CALL_298100);
    return g_func_00298100_ret;
}

void func_00284720(void *mgr, int id, int mode) {
    g_func_00284720_calls++;
    g_func_00284720_arg_mgr = mgr;
    g_func_00284720_arg_id = id;
    g_func_00284720_arg_mode = mode;
    g_call_sequence.push_back(CALL_284720);
}
}

int main() {
    // ------------------------------------------------------------------------
    // Test 1: Distinct dispatch argument (mode == 1) on normal dispatch
    // ------------------------------------------------------------------------
    D_4E3414 = 1; // pre-initialized flag
    g_func_00297C20_ret = 42;
    g_func_00298100_ret = 42;
    g_func_00284720_calls = 0;
    g_func_00284720_arg_mgr = 0;
    g_func_00284720_arg_id = 0;
    g_func_00284720_arg_mode = -1;

    func_00281BC0(42);

    assert(g_func_00284720_calls == 1);
    assert(g_func_00284720_arg_mgr == g_dummy_4e3424);
    assert(g_func_00284720_arg_id == 42);
    assert(g_func_00284720_arg_mode == 1);

    // ------------------------------------------------------------------------
    // Test 2: Guarded flag initialization: 0 -> 1 on entry
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    func_00281BC0(42);

    assert(D_4E3414 == 1);

    // ------------------------------------------------------------------------
    // Test 3: Filtered building ID 72 early returns without dispatch
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00284720_calls = 0;

    func_00281BC0(72);

    assert(D_4E3414 == 1);
    assert(g_func_00284720_calls == 0);

    // ------------------------------------------------------------------------
    // Test 4: Filtered building ID 117 early returns without dispatch
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00284720_calls = 0;

    func_00281BC0(117);

    assert(D_4E3414 == 1);
    assert(g_func_00284720_calls == 0);

    // ------------------------------------------------------------------------
    // Test 5: Filtered building ID 155 early returns without dispatch
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00284720_calls = 0;

    func_00281BC0(155);

    assert(D_4E3414 == 1);
    assert(g_func_00284720_calls == 0);

    // ------------------------------------------------------------------------
    // Test 6: Filtered building ID 487 early returns without dispatch
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00284720_calls = 0;

    func_00281BC0(487);

    assert(D_4E3414 == 1);
    assert(g_func_00284720_calls == 0);

    // ------------------------------------------------------------------------
    // Test 7: Filtered building ID -399 early returns without dispatch
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00284720_calls = 0;

    func_00281BC0(-399);

    assert(D_4E3414 == 1);
    assert(g_func_00284720_calls == 0);

    // ------------------------------------------------------------------------
    // Test 8: Characterization test when D_4E3414 is already 1
    // Filtered ID (72) must bypass first-call filters and dispatch mode 1
    // ------------------------------------------------------------------------
    D_4E3414 = 1;
    D_004E3414 = 1;
    g_func_00297C20_ret = 72;
    g_func_00298100_ret = 72;
    g_func_00284720_calls = 0;
    g_func_00284720_arg_mgr = 0;
    g_func_00284720_arg_id = 0;
    g_func_00284720_arg_mode = -1;

    func_00281BC0(72);

    assert(D_4E3414 == 1);
    assert(g_func_00284720_calls == 1);
    assert(g_func_00284720_arg_mgr == g_dummy_4e3424);
    assert(g_func_00284720_arg_id == 72);
    assert(g_func_00284720_arg_mode == 1);

    // ------------------------------------------------------------------------
    // Test 9: Mapping lookup for building_id == -398 with lookup failure (-1)
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00298880_calls = 0;
    g_func_00298880_arg_mgr = 0;
    g_func_00298880_arg_id = 0;
    g_func_00298880_ret = -1;
    g_func_00284720_calls = 0;

    func_00281BC0(-398);

    assert(D_4E3414 == 1);
    assert(g_func_00298880_calls == 1);
    assert(g_func_00298880_arg_mgr == g_dummy_4e3428);
    assert(g_func_00298880_arg_id == -398);
    assert(g_func_00284720_calls == 0);

    // ------------------------------------------------------------------------
    // Test 10: Full ABI for mapped-success path (-398 mapped to 500)
    // When func_002E01E0 returns 0, early returns.
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00298880_calls = 0;
    g_func_00298880_ret = 500;
    g_func_00203010_calls = 0;
    g_func_002E01E0_calls = 0;
    g_func_002E01E0_ret = 0; // stop at validation

    func_00281BC0(-398);

    assert(D_4E3414 == 1);
    assert(g_func_00298880_calls == 1);
    assert(g_func_00298880_arg_mgr == g_dummy_4e3428);
    assert(g_func_00298880_arg_id == -398);
    assert(g_func_00203010_calls == 0); // SKIPPED!
    assert(g_func_002E01E0_calls == 1);
    assert(g_func_002E01E0_arg_mgr == g_dummy_4e3420);
    assert(g_func_002E01E0_arg_id == 500);
    assert(g_func_002E01E0_arg_2 == 0);
    assert(g_func_002E01E0_arg_3 == 1);
    assert(g_func_002E01E0_arg_4 == 1);
    assert(g_func_002E01E0_arg_5 == 1);
    assert(g_func_002E01E0_arg_ratio == 1.0f);

    // ------------------------------------------------------------------------
    // Test 11: Prospective Red for func_002E01E0 returning 1, then
    // func_00297C20(D_4E3428, building_id) returning -1.
    // Assert exact args, call order (2E01E0 then 297C20), and that
    // func_00298100 and func_00284720 are NOT called.
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00298880_calls = 0;
    g_func_00298880_ret = 500;
    g_func_00203010_calls = 0;
    g_func_002E01E0_calls = 0;
    g_func_002E01E0_ret = 1; // passes validation!
    g_func_00297C20_calls = 0;
    g_func_00297C20_arg_mgr = 0;
    g_func_00297C20_arg_id = 0;
    g_func_00297C20_ret = -1; // resolution fails!
    g_func_00298100_calls = 0;
    g_func_00284720_calls = 0;
    g_call_sequence.clear();

    func_00281BC0(-398);

    assert(D_4E3414 == 1);
    assert(g_func_002E01E0_calls == 1);
    assert(g_func_00297C20_calls == 1);
    assert(g_func_00297C20_arg_mgr == g_dummy_4e3428);
    assert(g_func_00297C20_arg_id == 500);

    // Assert exact call sequence: 2E01E0 must occur before 297C20
    assert(g_call_sequence.size() >= 2);
    int idx_2e01e0 = -1;
    int idx_297c20 = -1;
    for (size_t i = 0; i < g_call_sequence.size(); ++i) {
        if (g_call_sequence[i] == CALL_2E01E0) idx_2e01e0 = (int)i;
        if (g_call_sequence[i] == CALL_297C20) idx_297c20 = (int)i;
    }
    assert(idx_2e01e0 != -1);
    assert(idx_297c20 != -1);
    assert(idx_2e01e0 < idx_297c20);

    assert(g_func_00298100_calls == 0);
    assert(g_func_00284720_calls == 0);

    // ------------------------------------------------------------------------
    // Test 12: Prospective Red — when func_00297C20 returns a valid id (42),
    // func_00298100(D_4E3428, 42) must be called, and its return value (999,
    // not building_id 100) must be passed as $a1 to
    // func_00284720(D_4E3424, 999, 1).
    // Call order must be: 297C20 -> 298100 -> 284720.
    // ------------------------------------------------------------------------
    D_4E3414 = 1; // flag pre-initialized, skip guard block
    g_func_00297C20_calls = 0;
    g_func_00297C20_arg_mgr = 0;
    g_func_00297C20_arg_id = 0;
    g_func_00297C20_ret = 42;     // resolution succeeds with id 42
    g_func_00298100_calls = 0;
    g_func_00298100_arg_mgr = 0;
    g_func_00298100_arg_id = 0;
    g_func_00298100_ret = 999;    // 298100 maps id 42 to 999
    g_func_00284720_calls = 0;
    g_func_00284720_arg_mgr = 0;
    g_func_00284720_arg_id = 0;
    g_func_00284720_arg_mode = -1;
    g_call_sequence.clear();

    func_00281BC0(100); // building_id 100; must NOT appear in dispatch

    // func_00297C20 called with D_4E3428 and building_id 100
    assert(g_func_00297C20_calls == 1);
    assert(g_func_00297C20_arg_mgr == g_dummy_4e3428);
    assert(g_func_00297C20_arg_id == 100);

    // func_00298100 called with D_4E3428 and the 297C20 return (42)
    assert(g_func_00298100_calls == 1);
    assert(g_func_00298100_arg_mgr == g_dummy_4e3428);
    assert(g_func_00298100_arg_id == 42);

    // func_00284720 dispatched with 298100 return (999), NOT building_id 100
    assert(g_func_00284720_calls == 1);
    assert(g_func_00284720_arg_mgr == g_dummy_4e3424);
    assert(g_func_00284720_arg_id == 999);
    assert(g_func_00284720_arg_mode == 1);

    // Strict call order: 297C20 then 298100 then 284720
    assert(g_call_sequence.size() >= 3);
    {
        int idx_297c20 = -1;
        int idx_298100 = -1;
        int idx_284720 = -1;
        for (size_t i = 0; i < g_call_sequence.size(); ++i) {
            if (g_call_sequence[i] == CALL_297C20) idx_297c20 = (int)i;
            if (g_call_sequence[i] == CALL_298100) idx_298100 = (int)i;
            if (g_call_sequence[i] == CALL_284720) idx_284720 = (int)i;
        }
        assert(idx_297c20 != -1);
        assert(idx_298100 != -1);
        assert(idx_284720 != -1);
        assert(idx_297c20 < idx_298100);
        assert(idx_298100 < idx_284720);
    }

    // ------------------------------------------------------------------------
    // Test 13: Prospective Red — unmapped path (building_id == 50) with D_4E3414 == 0
    // When building_id is not in [-399, -397), func_00203010(D_4E3420, 50) must be called.
    // When func_00203010 returns 0, execution must early return without downstream calls.
    // ------------------------------------------------------------------------
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00298880_calls = 0;
    g_func_00203010_calls = 0;
    g_func_00203010_arg_mgr = 0;
    g_func_00203010_arg_id = 0;
    g_func_00203010_ret = 0; // validation fails
    g_func_002E01E0_calls = 0;
    g_func_00297C20_calls = 0;
    g_func_00298100_calls = 0;
    g_func_00284720_calls = 0;
    g_call_sequence.clear();

    func_00281BC0(50);

    assert(D_4E3414 == 1);
    assert(g_func_00298880_calls == 0); // must NOT call mapper
    assert(g_func_00203010_calls == 1);
    assert(g_func_00203010_arg_mgr == g_dummy_4e3420);
    assert(g_func_00203010_arg_id == 50);
    assert(g_func_002E01E0_calls == 0);
    assert(g_func_00297C20_calls == 0);
    assert(g_func_00298100_calls == 0);
    assert(g_func_00284720_calls == 0);

    std::printf("func_00281BC0 native tests passed!\n");
    return 0;
}
