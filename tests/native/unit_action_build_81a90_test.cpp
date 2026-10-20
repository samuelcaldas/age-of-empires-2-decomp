#include <cassert>
#include <cstdio>

#include "unit_action_build_81a90.h"

// Tracking variables for mocks
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
static int g_func_00284720_arg_zero = -1;

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
    return g_func_00298880_ret;
}

int func_00203010(void *mgr, int id) {
    g_func_00203010_calls++;
    g_func_00203010_arg_mgr = mgr;
    g_func_00203010_arg_id = id;
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
    return g_func_002E01E0_ret;
}

int func_00297C20(void *mgr, int id) {
    g_func_00297C20_calls++;
    g_func_00297C20_arg_mgr = mgr;
    g_func_00297C20_arg_id = id;
    return g_func_00297C20_ret;
}

int func_00298100(void *mgr, int id) {
    g_func_00298100_calls++;
    g_func_00298100_arg_mgr = mgr;
    g_func_00298100_arg_id = id;
    return g_func_00298100_ret;
}

void func_00284720(void *mgr, int id, int zero) {
    g_func_00284720_calls++;
    g_func_00284720_arg_mgr = mgr;
    g_func_00284720_arg_id = id;
    g_func_00284720_arg_zero = zero;
}
}

static void reset_mocks() {
    D_4E3414 = 0;
    D_004E3414 = 0;
    g_func_00298880_calls = 0;
    g_func_00298880_arg_mgr = 0;
    g_func_00298880_arg_id = 0;
    g_func_00298880_ret = -1;

    g_func_00203010_calls = 0;
    g_func_00203010_arg_mgr = 0;
    g_func_00203010_arg_id = 0;
    g_func_00203010_ret = 1;

    g_func_002E01E0_calls = 0;
    g_func_002E01E0_arg_mgr = 0;
    g_func_002E01E0_arg_id = 0;
    g_func_002E01E0_arg_2 = -1;
    g_func_002E01E0_arg_3 = -1;
    g_func_002E01E0_arg_4 = -1;
    g_func_002E01E0_arg_5 = -1;
    g_func_002E01E0_arg_ratio = 0.0f;
    g_func_002E01E0_ret = 1;

    g_func_00297C20_calls = 0;
    g_func_00297C20_arg_mgr = 0;
    g_func_00297C20_arg_id = 0;
    g_func_00297C20_ret = -1;

    g_func_00298100_calls = 0;
    g_func_00298100_arg_mgr = 0;
    g_func_00298100_arg_id = 0;
    g_func_00298100_ret = 0;

    g_func_00284720_calls = 0;
    g_func_00284720_arg_mgr = 0;
    g_func_00284720_arg_id = 0;
    g_func_00284720_arg_zero = -1;
}

int main() {
    // ------------------------------------------------------------------------
    // Tests 1a-1e: All five filtered building IDs individually
    // Must initialize D_4E3414 = 1 and suppress all downstream calls.
    // ------------------------------------------------------------------------
    int filtered_ids[] = { 72, 117, 155, 487, -399 };
    for (int i = 0; i < 5; ++i) {
        reset_mocks();
        func_00281A90(filtered_ids[i]);

        assert(D_4E3414 == 1);
        assert(g_func_00298880_calls == 0);
        assert(g_func_00203010_calls == 0);
        assert(g_func_002E01E0_calls == 0);
        assert(g_func_00297C20_calls == 0);
        assert(g_func_00298100_calls == 0);
        assert(g_func_00284720_calls == 0);
    }

    // ------------------------------------------------------------------------
    // Test 2a: Mapped range match (-398) with lookup failure (-1)
    // Calls func_00298880(D_4E3428, -398); returns -1 -> early return.
    // ------------------------------------------------------------------------
    reset_mocks();
    g_func_00298880_ret = -1;
    func_00281A90(-398);

    assert(D_4E3414 == 1);
    assert(g_func_00298880_calls == 1);
    assert(g_func_00298880_arg_mgr == g_dummy_4e3428);
    assert(g_func_00298880_arg_id == -398);
    assert(g_func_00203010_calls == 0);
    assert(g_func_002E01E0_calls == 0);

    // ------------------------------------------------------------------------
    // Test 2b: Mapped range match (-398) with successful mapping (mapped to 500)
    // Calls func_00298880, SKIPS func_00203010, and calls func_002E01E0 with 500!
    // ------------------------------------------------------------------------
    reset_mocks();
    g_func_00298880_ret = 500;
    g_func_002E01E0_ret = 0; // stop at validation
    func_00281A90(-398);

    assert(D_4E3414 == 1);
    assert(g_func_00298880_calls == 1);
    assert(g_func_00298880_arg_id == -398);
    assert(g_func_00203010_calls == 0); // SKIPPED!
    assert(g_func_002E01E0_calls == 1);
    assert(g_func_002E01E0_arg_id == 500);

    // ------------------------------------------------------------------------
    // Test 2c: Adjacent mapping bound below (-400)
    // Does NOT trigger mapping range [-399, -397); falls through to func_00203010.
    // ------------------------------------------------------------------------
    reset_mocks();
    g_func_00203010_ret = 0; // stop at func_00203010
    func_00281A90(-400);

    assert(D_4E3414 == 1);
    assert(g_func_00298880_calls == 0); // NOT called
    assert(g_func_00203010_calls == 1);
    assert(g_func_00203010_arg_id == -400);

    // ------------------------------------------------------------------------
    // Test 2d: Adjacent mapping bound above (-397)
    // Does NOT trigger mapping range [-399, -397); falls through to func_00203010.
    // ------------------------------------------------------------------------
    reset_mocks();
    g_func_00203010_ret = 0;
    func_00281A90(-397);

    assert(D_4E3414 == 1);
    assert(g_func_00298880_calls == 0); // NOT called
    assert(g_func_00203010_calls == 1);
    assert(g_func_00203010_arg_id == -397);

    // ------------------------------------------------------------------------
    // Test 2e: Unmapped ID (-396)
    // Does NOT trigger mapping; falls through to func_00203010.
    // ------------------------------------------------------------------------
    reset_mocks();
    g_func_00203010_ret = 0;
    func_00281A90(-396);

    assert(D_4E3414 == 1);
    assert(g_func_00298880_calls == 0);
    assert(g_func_00203010_calls == 1);
    assert(g_func_00203010_arg_id == -396);

    // ------------------------------------------------------------------------
    // Test 3: Validation failure on func_00203010 (returns 0)
    // ------------------------------------------------------------------------
    reset_mocks();
    g_func_00203010_ret = 0;
    func_00281A90(100);

    assert(D_4E3414 == 1);
    assert(g_func_00203010_calls == 1);
    assert(g_func_00203010_arg_mgr == g_dummy_4e3420);
    assert(g_func_00203010_arg_id == 100);
    assert(g_func_002E01E0_calls == 0);

    // ------------------------------------------------------------------------
    // Test 4: Validation call func_002E01E0 (returns 0)
    // ------------------------------------------------------------------------
    reset_mocks();
    g_func_00203010_ret = 1;
    g_func_002E01E0_ret = 0;
    func_00281A90(100);

    assert(D_4E3414 == 1);
    assert(g_func_00203010_calls == 1);
    assert(g_func_002E01E0_calls == 1);
    assert(g_func_002E01E0_arg_mgr == g_dummy_4e3420);
    assert(g_func_002E01E0_arg_id == 100);
    assert(g_func_002E01E0_arg_2 == 0);
    assert(g_func_002E01E0_arg_3 == 1);
    assert(g_func_002E01E0_arg_4 == 1);
    assert(g_func_002E01E0_arg_5 == 1);
    assert(g_func_002E01E0_arg_ratio == 1.0f);
    assert(g_func_00297C20_calls == 0);

    // ------------------------------------------------------------------------
    // Test 5: Resolution call func_00297C20 returns -1
    // ------------------------------------------------------------------------
    reset_mocks();
    g_func_00203010_ret = 1;
    g_func_002E01E0_ret = 1;
    g_func_00297C20_ret = -1;
    func_00281A90(100);

    assert(D_4E3414 == 1);
    assert(g_func_00297C20_calls == 1);
    assert(g_func_00297C20_arg_mgr == g_dummy_4e3428);
    assert(g_func_00297C20_arg_id == 100);
    assert(g_func_00298100_calls == 0);
    assert(g_func_00284720_calls == 0);

    // ------------------------------------------------------------------------
    // Test 6: Full dispatch
    // ------------------------------------------------------------------------
    reset_mocks();
    g_func_00203010_ret = 1;
    g_func_002E01E0_ret = 1;
    g_func_00297C20_ret = 42;
    g_func_00298100_ret = 999;

    func_00281A90(100);

    assert(g_func_00203010_calls == 1);
    assert(g_func_002E01E0_calls == 1);
    assert(g_func_00297C20_calls == 1);
    assert(g_func_00297C20_arg_id == 100);
    assert(g_func_00298100_calls == 1);
    assert(g_func_00298100_arg_mgr == g_dummy_4e3428);
    assert(g_func_00298100_arg_id == 42);
    assert(g_func_00284720_calls == 1);
    assert(g_func_00284720_arg_mgr == g_dummy_4e3424);
    assert(g_func_00284720_arg_id == 999);
    assert(g_func_00284720_arg_zero == 0);

    // ------------------------------------------------------------------------
    // Test 7: Already-initialized flag (D_4E3414 == 1) with filtered ID 72
    // Must bypass pre-validation entirely and jump directly to func_00297C20.
    // ------------------------------------------------------------------------
    reset_mocks();
    D_4E3414 = 1;
    g_func_00297C20_ret = -1;
    func_00281A90(72);

    assert(g_func_00298880_calls == 0);
    assert(g_func_00203010_calls == 0);
    assert(g_func_002E01E0_calls == 0);
    assert(g_func_00297C20_calls == 1); // DIRECTLY INVOKED!
    assert(g_func_00297C20_arg_id == 72);

    // ------------------------------------------------------------------------
    // Test 8: Already-initialized flag (D_4E3414 == 1) with mapped ID -398
    // Must bypass func_00298880 entirely and jump directly to func_00297C20.
    // ------------------------------------------------------------------------
    reset_mocks();
    D_4E3414 = 1;
    g_func_00297C20_ret = -1;
    func_00281A90(-398);

    assert(g_func_00298880_calls == 0); // BYPASSED!
    assert(g_func_00203010_calls == 0);
    assert(g_func_002E01E0_calls == 0);
    assert(g_func_00297C20_calls == 1);
    assert(g_func_00297C20_arg_id == -398);

    // ------------------------------------------------------------------------
    // Test 9: Alias func_281A90 forwards to func_00281A90
    // ------------------------------------------------------------------------
    reset_mocks();
    D_4E3414 = 1;
    g_func_00297C20_ret = -1;
    func_281A90(100);

    assert(g_func_00297C20_calls == 1);
    assert(g_func_00297C20_arg_id == 100);

    std::printf("All func_00281A90 native tests (all branches, boundaries, flag states) passed!\n");
    return 0;
}
