#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_decrement_by_id.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static void test_one_match_decrements_count() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    TableEntry entries[1];
    std::memset(entries, 0, sizeof(entries));
    entries[0].active = 1;
    entries[0].pad4 = 0;
    entries[0].count = 50;
    entries[0].decrement = 15;
    entries[0].id = 42;

    inst.m_table = entries;
    inst.m_count = 1;

    func_0032E640(&inst, 42);

    TEST_ASSERT(entries[0].count == 35, "matching active entry count must be decremented by decrement value");
}

static void test_zero_entries_noop() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    TableEntry entries[1];
    entries[0].active = 1;
    entries[0].count = 50;
    entries[0].decrement = 15;
    entries[0].id = 42;

    inst.m_table = entries;
    inst.m_count = 0; // zero entries

    func_0032E640(&inst, 42);

    TEST_ASSERT(entries[0].count == 50, "zero count table must not be decremented");
}

static void test_inactive_matching_id_preserved() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    TableEntry entries[1];
    entries[0].active = 0; // inactive
    entries[0].count = 50;
    entries[0].decrement = 15;
    entries[0].id = 42;

    inst.m_table = entries;
    inst.m_count = 1;

    func_0032E640(&inst, 42);

    TEST_ASSERT(entries[0].count == 50, "inactive entry count must not be decremented");
}

static void test_active_mismatched_id_preserved() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    TableEntry entries[1];
    entries[0].active = 1;
    entries[0].count = 50;
    entries[0].decrement = 15;
    entries[0].id = 99; // mismatched

    inst.m_table = entries;
    inst.m_count = 1;

    func_0032E640(&inst, 42);

    TEST_ASSERT(entries[0].count == 50, "mismatched id entry count must not be decremented");
}

static void test_multiple_matches_processed() {
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));

    TableEntry entries[3];
    std::memset(entries, 0, sizeof(entries));
    entries[0].active = 1; entries[0].count = 100; entries[0].decrement = 10; entries[0].id = 5;
    entries[1].active = 1; entries[1].count = 200; entries[1].decrement = 20; entries[1].id = 6;
    entries[2].active = 1; entries[2].count = 300; entries[2].decrement = 30; entries[2].id = 5;

    inst.m_table = entries;
    inst.m_count = 3;

    func_0032E640(&inst, 5);

    TEST_ASSERT(entries[0].count == 90, "first matching entry count must be 90");
    TEST_ASSERT(entries[1].count == 200, "mismatched entry count must stay 200");
    TEST_ASSERT(entries[2].count == 270, "second matching entry count must be 270");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "one_match") == 0) { test_one_match_decrements_count(); return 0; }
        if (std::strcmp(argv[1], "zero_count") == 0) { test_zero_entries_noop(); return 0; }
        if (std::strcmp(argv[1], "inactive") == 0) { test_inactive_matching_id_preserved(); return 0; }
        if (std::strcmp(argv[1], "mismatch") == 0) { test_active_mismatched_id_preserved(); return 0; }
        if (std::strcmp(argv[1], "multiple") == 0) { test_multiple_matches_processed(); return 0; }
    }
    test_one_match_decrements_count();
    test_zero_entries_noop();
    test_inactive_matching_id_preserved();
    test_active_mismatched_id_preserved();
    test_multiple_matches_processed();
    return 0;
}
