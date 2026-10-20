#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_update.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static std::vector<int> s_trace;
static int s_pre_calls = 0;
static int s_virt_calls = 0;
static int s_post_calls = 0;
static void *s_last_pre_self = nullptr;
static void *s_last_virt_self = nullptr;
static void *s_last_post_self = nullptr;

void CombatSubsystemControllerInstance::func_0() {}
void CombatSubsystemControllerInstance::func_4() {}
void CombatSubsystemControllerInstance::func_8() {}
void CombatSubsystemControllerInstance::func_C() {}
void CombatSubsystemControllerInstance::func_10() {}
void CombatSubsystemControllerInstance::func_14() {}
void CombatSubsystemControllerInstance::func_18() {}
void CombatSubsystemControllerInstance::func_1C() {}
void CombatSubsystemControllerInstance::func_20() {}
void CombatSubsystemControllerInstance::func_24() {}
void CombatSubsystemControllerInstance::func_28() {}
void CombatSubsystemControllerInstance::func_2C() {}
void CombatSubsystemControllerInstance::func_30() {}
void CombatSubsystemControllerInstance::func_34() {}
void CombatSubsystemControllerInstance::func_38() {}
void CombatSubsystemControllerInstance::func_3C() {}
void CombatSubsystemControllerInstance::func_40() {}
void CombatSubsystemControllerInstance::func_44() {}
void CombatSubsystemControllerInstance::func_48() {}
void CombatSubsystemControllerInstance::func_4C() {}
void CombatSubsystemControllerInstance::func_50() {}
void CombatSubsystemControllerInstance::func_54() {}
void CombatSubsystemControllerInstance::func_58() {}
void CombatSubsystemControllerInstance::func_5C() {}
void CombatSubsystemControllerInstance::func_60() {}
void CombatSubsystemControllerInstance::func_64() {}
void CombatSubsystemControllerInstance::func_68() {}
void CombatSubsystemControllerInstance::func_6C() {}
void CombatSubsystemControllerInstance::func_70() {}
void CombatSubsystemControllerInstance::func_74() {}
void CombatSubsystemControllerInstance::func_78() {}
void CombatSubsystemControllerInstance::func_7C() {}
void CombatSubsystemControllerInstance::func_80() {}
void CombatSubsystemControllerInstance::func_84() {}
void CombatSubsystemControllerInstance::func_88() {}
void CombatSubsystemControllerInstance::func_8C() {}
void CombatSubsystemControllerInstance::func_90() {}
void CombatSubsystemControllerInstance::func_94() {}
void CombatSubsystemControllerInstance::func_98() {}
void CombatSubsystemControllerInstance::func_9C() {}
void CombatSubsystemControllerInstance::func_A0() {}
void CombatSubsystemControllerInstance::func_A4() {}
void CombatSubsystemControllerInstance::func_A8() {}
void CombatSubsystemControllerInstance::func_AC() {}
void CombatSubsystemControllerInstance::func_B0() {}
void CombatSubsystemControllerInstance::func_B4() {}
void CombatSubsystemControllerInstance::func_B8() {}
void CombatSubsystemControllerInstance::func_BC() {}
void CombatSubsystemControllerInstance::func_C0() {}
void CombatSubsystemControllerInstance::func_C4() {}
void CombatSubsystemControllerInstance::func_C8() {}
void CombatSubsystemControllerInstance::func_CC() {}
void CombatSubsystemControllerInstance::func_D0() {}
void CombatSubsystemControllerInstance::func_D4() {}
void CombatSubsystemControllerInstance::func_D8() {}
void CombatSubsystemControllerInstance::func_DC() {}
void CombatSubsystemControllerInstance::func_E0() {}
void CombatSubsystemControllerInstance::func_E4() {}
void CombatSubsystemControllerInstance::func_E8() {}
void CombatSubsystemControllerInstance::func_EC() {}
void CombatSubsystemControllerInstance::func_F0() {}
void CombatSubsystemControllerInstance::func_F4() {}
void CombatSubsystemControllerInstance::func_F8() {}
void CombatSubsystemControllerInstance::func_FC() {}
void CombatSubsystemControllerInstance::func_100() {}
void CombatSubsystemControllerInstance::func_104() {}
void CombatSubsystemControllerInstance::func_108() {}
void CombatSubsystemControllerInstance::func_10C() {}
void CombatSubsystemControllerInstance::func_110() {}
void CombatSubsystemControllerInstance::func_114() {}
void CombatSubsystemControllerInstance::func_118() {}
void CombatSubsystemControllerInstance::func_11C() {}
void CombatSubsystemControllerInstance::func_120() {}
void CombatSubsystemControllerInstance::func_124() {}
void CombatSubsystemControllerInstance::func_128() {}
void CombatSubsystemControllerInstance::func_12C() {}
void CombatSubsystemControllerInstance::func_130() {}
void CombatSubsystemControllerInstance::func_134() {}
void CombatSubsystemControllerInstance::func_138() {
    s_virt_calls++;
    s_trace.push_back(2);
    s_last_virt_self = this;
}
CombatSubsystemControllerInstance::~CombatSubsystemControllerInstance() {}

extern "C" {
    void func_329550(void *self) {
        s_pre_calls++;
        s_trace.push_back(1);
        s_last_pre_self = self;
    }

    void func_1F4FA0(void *self) {
        s_post_calls++;
        s_trace.push_back(3);
        s_last_post_self = self;
    }
}

static void reset_mocks() {
    s_trace.clear();
    s_pre_calls = 0;
    s_virt_calls = 0;
    s_post_calls = 0;
    s_last_pre_self = nullptr;
    s_last_virt_self = nullptr;
    s_last_post_self = nullptr;
}

static void test_sequence() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    func_00329310(&inst);

    TEST_ASSERT(s_trace.size() == 3, "expected exactly 3 update calls in trace");
    TEST_ASSERT(s_trace[0] == 1, "pre-hook func_329550 must be called first");
    TEST_ASSERT(s_trace[1] == 2, "virtual method func_138 must be called second");
    TEST_ASSERT(s_trace[2] == 3, "post-hook func_1F4FA0 must be called third");
}

static void test_receivers() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    func_00329310(&inst);

    TEST_ASSERT(s_last_pre_self == &inst, "pre-hook receiver mismatch");
    TEST_ASSERT(s_last_virt_self == &inst, "virtual method receiver mismatch");
    TEST_ASSERT(s_last_post_self == &inst, "post-hook receiver mismatch");
}

static void test_call_counts() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    func_00329310(&inst);

    TEST_ASSERT(s_pre_calls == 1, "pre-hook call count mismatch");
    TEST_ASSERT(s_virt_calls == 1, "virtual method call count mismatch");
    TEST_ASSERT(s_post_calls == 1, "post-hook call count mismatch");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "sequence") == 0) { test_sequence(); return 0; }
        if (std::strcmp(argv[1], "receivers") == 0) { test_receivers(); return 0; }
        if (std::strcmp(argv[1], "call_counts") == 0) { test_call_counts(); return 0; }
    }
    test_sequence();
    test_receivers();
    test_call_counts();
    return 0;
}
