// Tests for func_002784D0 & func_00278530 — Milestone 110 (168B)
// Verifies ActionType <-> StanceMode bijective mappings.
#include <cassert>
#include <cstdio>
#include "unit_action_build_784d0.h"

static void test_action_to_stance() {
    assert(func_002784D0(nullptr, 0) == 4);
    assert(func_002784D0(nullptr, 3) == 3);
    assert(func_002784D0(nullptr, 0x38) == 2);
    assert(func_002784D0(nullptr, 1) == 0);
    assert(func_002784D0(nullptr, 2) == 0);
    assert(func_002784D0(nullptr, 5) == -1);
    assert(func_002784D0(nullptr, -1) == -1);
    printf("PASS test_action_to_stance\n");
}

static void test_stance_to_action() {
    assert(func_00278530(nullptr, 4) == 0);
    assert(func_00278530(nullptr, 3) == 3);
    assert(func_00278530(nullptr, 2) == 0x38);
    assert(func_00278530(nullptr, 1) == 1);
    assert(func_00278530(nullptr, 0) == 0);
    assert(func_00278530(nullptr, 5) == -1);
    assert(func_00278530(nullptr, -1) == -1);
    printf("PASS test_stance_to_action\n");
}

int main() {
    test_action_to_stance();
    test_stance_to_action();
    printf("All unit_action_build_784d0 tests passed!\n");
    return 0;
}
