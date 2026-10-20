#include <cassert>
#include <cstdio>
#include <cstring>
#include "tactical_ai_func_342ab0.h"

static void test_func_342ab0_force_flag_updates_field_10_and_returns_1() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    item.field_14 = 5;
    item.field_10 = 0;

    int res = func_00342AB0(&item, 3, 1);

    assert(res == 1);
    assert(item.field_10 == 3);
    std::printf("PASS test_func_342ab0_force_flag_updates_field_10_and_returns_1\n");
    std::fflush(stdout);
}

static void test_func_342ab0_force_flag_boundary_locked_returns_0() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    item.field_14 = 5;
    item.field_10 = 0;

    // level == field_14: boundary locked, must return 0 and not update field_10
    int res = func_00342AB0(&item, 5, 1);
    assert(res == 0);
    assert(item.field_10 == 0);

    // level > field_14: locked, must return 0 and not update field_10
    res = func_00342AB0(&item, 10, 1);
    assert(res == 0);
    assert(item.field_10 == 0);

    std::printf("PASS test_func_342ab0_force_flag_boundary_locked_returns_0\n");
    std::fflush(stdout);
}

static void test_func_342ab0_non_force_unlocked_with_field18_less_than_level() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    item.field_14 = 5;
    item.field_18 = 2;
    item.field_10 = 0;
    item.field_1C[3] = 1; // unlocked byte

    int res = func_00342AB0(&item, 3, 0);

    assert(res == 1);
    // Since field_18 (2) < level (3), field_10 takes field_18 (2)
    assert(item.field_10 == 2);
    std::printf("PASS test_func_342ab0_non_force_unlocked_with_field18_less_than_level\n");
    std::fflush(stdout);
}

static void test_func_342ab0_non_force_unlocked_with_field18_ge_level() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    item.field_14 = 5;
    item.field_18 = 4;
    item.field_10 = 0;
    item.field_1C[3] = 1; // unlocked byte

    int res = func_00342AB0(&item, 3, 0);

    assert(res == 1);
    // Since field_18 (4) >= level (3), field_10 takes level (3)
    assert(item.field_10 == 3);
    std::printf("PASS test_func_342ab0_non_force_unlocked_with_field18_ge_level\n");
    std::fflush(stdout);
}

static void test_func_342ab0_non_force_locked_byte_returns_0() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    item.field_14 = 5;
    item.field_10 = 0;
    item.field_1C[3] = 0; // locked byte

    int res = func_00342AB0(&item, 3, 0);

    assert(res == 0);
    assert(item.field_10 == 0);
    std::printf("PASS test_func_342ab0_non_force_locked_byte_returns_0\n");
    std::fflush(stdout);
}

static void test_func_342ab0_non_force_level_ge_field14_returns_0() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    item.field_14 = 5;
    item.field_10 = 0;
    item.field_1C[4] = 1;

    // level == field_14
    int res = func_00342AB0(&item, 5, 0);
    assert(res == 0);
    assert(item.field_10 == 0);

    // level > field_14
    res = func_00342AB0(&item, 8, 0);
    assert(res == 0);
    assert(item.field_10 == 0);

    std::printf("PASS test_func_342ab0_non_force_level_ge_field14_returns_0\n");
    std::fflush(stdout);
}

int main() {
    test_func_342ab0_force_flag_updates_field_10_and_returns_1();
    test_func_342ab0_force_flag_boundary_locked_returns_0();
    test_func_342ab0_non_force_unlocked_with_field18_less_than_level();
    test_func_342ab0_non_force_unlocked_with_field18_ge_level();
    test_func_342ab0_non_force_locked_byte_returns_0();
    test_func_342ab0_non_force_level_ge_field14_returns_0();
    std::printf("ALL TACTICAL AI FUNC 342AB0 TESTS PASSED\n");
    return 0;
}
