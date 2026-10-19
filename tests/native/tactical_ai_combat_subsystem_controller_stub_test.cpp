#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_stub.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static void test_noop_behavior() {
    int buf[4] = { 0x12345678, 0x23456789, 0x3456789A, 0x456789AB };
    func_0032C5F0((CombatSubsystemControllerInstance*)buf);
    TEST_ASSERT(buf[0] == 0x12345678, "func_0032C5F0 must not mutate instance memory (word 0)");
    TEST_ASSERT(buf[1] == 0x23456789, "func_0032C5F0 must not mutate instance memory (word 1)");
    TEST_ASSERT(buf[2] == 0x3456789A, "func_0032C5F0 must not mutate instance memory (word 2)");
    TEST_ASSERT(buf[3] == 0x456789AB, "func_0032C5F0 must not mutate instance memory (word 3)");
}

static void test_null_self_noop() {
    func_0032C5F0(nullptr);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "noop") == 0) { test_noop_behavior(); return 0; }
        if (std::strcmp(argv[1], "null") == 0) { test_null_self_noop(); return 0; }
    }
    test_noop_behavior();
    test_null_self_noop();
    return 0;
}
