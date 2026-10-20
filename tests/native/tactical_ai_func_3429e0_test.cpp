#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include "tactical_ai_func_3429e0.h"

struct MockDesc {
    const char *name;
    int value;
};

struct CallRecord {
    std::string name;
    void *ptr_arg;
    std::string str1;
    std::string str2;
};

static std::vector<CallRecord> g_call_history;

extern "C" {
const char *func_00188DB0(void *info) {
    CallRecord rec;
    rec.name = "func_00188DB0";
    rec.ptr_arg = info;
    g_call_history.push_back(rec);
    if (!info) return "";
    return ((MockDesc*)info)->name;
}

int func_11AA78(const char *s1, const char *s2) {
    CallRecord rec;
    rec.name = "func_11AA78";
    rec.ptr_arg = NULL;
    rec.str1 = s1 ? s1 : "";
    rec.str2 = s2 ? s2 : "";
    g_call_history.push_back(rec);
    return std::strcmp(s1, s2);
}

int func_00188DC0(void *info) {
    CallRecord rec;
    rec.name = "func_00188DC0";
    rec.ptr_arg = info;
    g_call_history.push_back(rec);
    if (!info) return 0;
    return ((MockDesc*)info)->value;
}
}

static void test_func_3429e0_resets_field_24_on_no_match_or_empty() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    std::strcpy(item.name, "target_unit");
    item.field_24 = 0x12345678;

    func_003429E0(&item, NULL, 0);

    assert(item.field_24 == 0);
    std::printf("PASS test_func_3429e0_resets_field_24_on_no_match_or_empty\n");
    std::fflush(stdout);
}

static void test_func_3429e0_matches_descriptor_and_upper_clamp() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    std::strcpy(item.name, "archer");
    item.field_10 = 5;
    item.field_18 = 20;

    MockDesc desc;
    desc.name = "archer";
    desc.value = 15;
    void *descs[1] = { &desc };

    func_003429E0(&item, descs, 1);

    assert(item.field_24 == (int)(long)&desc);
    assert(item.field_14 == 15);
    // Upper clamp: field_18 (20) >= field_14 (15) -> field_18 becomes 14
    assert(item.field_18 == 14);
    // Lower clamp: field_18 (14) >= field_10 (5) -> field_10 remains 5
    assert(item.field_10 == 5);

    std::printf("PASS test_func_3429e0_matches_descriptor_and_upper_clamp\n");
    std::fflush(stdout);
}

static void test_func_3429e0_lower_clamp_updates_field_10() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    std::strcpy(item.name, "knight");
    item.field_10 = 10;
    item.field_18 = 12;

    MockDesc desc;
    desc.name = "knight";
    desc.value = 8;
    void *descs[1] = { &desc };

    func_003429E0(&item, descs, 1);

    assert(item.field_24 == (int)(long)&desc);
    assert(item.field_14 == 8);
    // Upper clamp: field_18 (12) >= field_14 (8) -> field_18 becomes 7
    assert(item.field_18 == 7);
    // Lower clamp: field_18 (7) < field_10 (10) -> field_10 becomes 7
    assert(item.field_10 == 7);

    std::printf("PASS test_func_3429e0_lower_clamp_updates_field_10\n");
    std::fflush(stdout);
}

static void test_func_3429e0_multiple_descriptors_order() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    std::strcpy(item.name, "swordsman");
    item.field_10 = 1;
    item.field_18 = 10;

    MockDesc desc1; desc1.name = "scout"; desc1.value = 50;
    MockDesc desc2; desc2.name = "swordsman"; desc2.value = 25;
    MockDesc desc3; desc3.name = "archer"; desc3.value = 30;
    void *descs[3] = { &desc1, &desc2, &desc3 };

    func_003429E0(&item, descs, 3);

    // Exact match for "swordsman"
    assert(item.field_24 == (int)(long)&desc2);
    assert(item.field_14 == 25);
    // field_18 (10) < field_14 (25) -> upper clamp does not fire, remains 10
    assert(item.field_18 == 10);
    // field_18 (10) >= field_10 (1) -> lower clamp does not fire, remains 1
    assert(item.field_10 == 1);

    std::printf("PASS test_func_3429e0_multiple_descriptors_order\n");
    std::fflush(stdout);
}

static void test_func_3429e0_negative_and_zero_count_boundary() {
    TacticalItem_342820 item;
    std::memset(&item, 0x55, sizeof(item));
    std::strcpy(item.name, "hero");
    item.field_24 = 0x11223344;
    MockDesc desc; desc.name = "hero"; desc.value = 99;
    void *descs[1] = { &desc };

    // Negative count boundary: signed slt v1, s0, s1 (0 < -1 is false) -> loop body never runs
    g_call_history.clear();
    func_003429E0(&item, descs, -1);
    assert(item.field_24 == 0);
    assert(g_call_history.empty());

    // Another negative count boundary: count = -100
    g_call_history.clear();
    item.field_24 = 0x99887766;
    func_003429E0(&item, descs, -100);
    assert(item.field_24 == 0);
    assert(g_call_history.empty());

    // Zero count boundary
    g_call_history.clear();
    item.field_24 = 0xAABBCCDD;
    func_003429E0(&item, descs, 0);
    assert(item.field_24 == 0);
    assert(g_call_history.empty());

    std::printf("PASS test_func_3429e0_negative_and_zero_count_boundary\n");
    std::fflush(stdout);
}

static void test_func_3429e0_exact_call_order_and_arguments() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    std::strcpy(item.name, "target_type");

    MockDesc descA; descA.name = "type_alpha"; descA.value = 10;
    MockDesc descB; descB.name = "target_type"; descB.value = 20;
    MockDesc descC; descC.name = "type_gamma"; descC.value = 30;
    void *descs[3] = { &descA, &descB, &descC };

    g_call_history.clear();
    func_003429E0(&item, descs, 3);

    // Call order:
    // descA: 188DB0(A) -> 11AA78("type_alpha", "target_type") -> mismatch, no 188DC0
    // descB: 188DB0(B) -> 11AA78("target_type", "target_type") -> match, calls 188DC0(B)
    // descC: 188DB0(C) -> 11AA78("type_gamma", "target_type") -> mismatch, no 188DC0
    // Total exact 7 calls in exact order:
    assert(g_call_history.size() == 7);

    assert(g_call_history[0].name == "func_00188DB0");
    assert(g_call_history[0].ptr_arg == &descA);

    assert(g_call_history[1].name == "func_11AA78");
    assert(g_call_history[1].str1 == "type_alpha");
    assert(g_call_history[1].str2 == "target_type");

    assert(g_call_history[2].name == "func_00188DB0");
    assert(g_call_history[2].ptr_arg == &descB);

    assert(g_call_history[3].name == "func_11AA78");
    assert(g_call_history[3].str1 == "target_type");
    assert(g_call_history[3].str2 == "target_type");

    assert(g_call_history[4].name == "func_00188DC0");
    assert(g_call_history[4].ptr_arg == &descB);

    assert(g_call_history[5].name == "func_00188DB0");
    assert(g_call_history[5].ptr_arg == &descC);

    assert(g_call_history[6].name == "func_11AA78");
    assert(g_call_history[6].str1 == "type_gamma");
    assert(g_call_history[6].str2 == "target_type");

    std::printf("PASS test_func_3429e0_exact_call_order_and_arguments\n");
    std::fflush(stdout);
}

static void test_func_3429e0_multiple_matching_descriptors_sequential_override() {
    TacticalItem_342820 item;
    std::memset(&item, 0, sizeof(item));
    std::strcpy(item.name, "shared_name");
    item.field_10 = 20;
    item.field_18 = 25;

    MockDesc match1; match1.name = "shared_name"; match1.value = 30;
    MockDesc match2; match2.name = "shared_name"; match2.value = 15;
    void *descs[2] = { &match1, &match2 };

    func_003429E0(&item, descs, 2);

    // Iteration 0 (match1):
    // field_24 = &match1, field_14 = 30.
    // field_18 (25) < field_14 (30) -> no upper clamp.
    // field_18 (25) >= field_10 (20) -> no lower clamp.
    //
    // Iteration 1 (match2):
    // field_24 = &match2, field_14 = 15.
    // field_18 (25) >= field_14 (15) -> upper clamp fires: field_18 becomes 14.
    // field_18 (14) < field_10 (20) -> lower clamp fires: field_10 becomes 14.
    assert(item.field_24 == (int)(long)&match2);
    assert(item.field_14 == 15);
    assert(item.field_18 == 14);
    assert(item.field_10 == 14);

    std::printf("PASS test_func_3429e0_multiple_matching_descriptors_sequential_override\n");
    std::fflush(stdout);
}

int main() {
    test_func_3429e0_resets_field_24_on_no_match_or_empty();
    test_func_3429e0_matches_descriptor_and_upper_clamp();
    test_func_3429e0_lower_clamp_updates_field_10();
    test_func_3429e0_multiple_descriptors_order();
    test_func_3429e0_negative_and_zero_count_boundary();
    test_func_3429e0_exact_call_order_and_arguments();
    test_func_3429e0_multiple_matching_descriptors_sequential_override();
    std::printf("ALL TACTICAL AI FUNC 3429E0 TESTS PASSED\n");
    return 0;
}
