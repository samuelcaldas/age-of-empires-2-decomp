// Tests for func_276C70 — Milestone 97 (44B)
// Verifies ActionBuild task code compatibility predicate (0x32 and 0x2D).
#include <cassert>
#include <cstdio>
#include "unit_action_build_6c70.h"

static void test_task_32() {
    assert(func_276C70(nullptr, 0x32) == 1);
    printf("PASS test_task_32\n");
}

static void test_task_2d() {
    assert(func_276C70(nullptr, 0x2D) == 1);
    printf("PASS test_task_2d\n");
}

static void test_other_tasks() {
    assert(func_276C70(nullptr, 0) == 0);
    assert(func_276C70(nullptr, 1) == 0);
    assert(func_276C70(nullptr, 0x30) == 0);
    assert(func_276C70(nullptr, 0x31) == 0);
    assert(func_276C70(nullptr, 0x33) == 0);
    assert(func_276C70(nullptr, 0x2E) == 0);
    assert(func_276C70(nullptr, -1) == 0);
    printf("PASS test_other_tasks\n");
}

int main() {
    test_task_32();
    test_task_2d();
    test_other_tasks();
    printf("All unit_action_build_6c70 tests passed!\n");
    return 0;
}
