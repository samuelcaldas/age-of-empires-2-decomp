#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <vector>
#include "tactical_ai_combat_subsystem_controller_order_dispatch.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static int s_32e820_calls = 0;
static void *s_last_32e820_self = nullptr;

static int s_sub260ed0_calls = 0;
static void *s_last_sub260ed0_target = nullptr;

static int s_e640_calls = 0;
static void *s_last_e640_self = nullptr;
static int s_last_e640_id = -1;

static int s_sub260e50_calls = 0;
static void *s_last_260e50_target = nullptr;
static int s_last_260e50_action_id = -1;
static int s_last_260e50_a2 = -1;
static int s_last_260e50_param = -1;
static int s_last_260e50_a3 = 0;
static void *s_dummy_ret_slot = (void*)0x99887766;

static std::vector<const char*> s_call_order;

extern "C" {
    void func_0032E820(CombatSubsystemControllerInstance *self) {
        s_32e820_calls++;
        s_last_32e820_self = self;
        s_call_order.push_back("func_0032E820");
    }

    void sub_260ED0(void *target_sub) {
        s_sub260ed0_calls++;
        s_last_sub260ed0_target = target_sub;
        s_call_order.push_back("sub_260ED0");
    }

    void func_0032E640(CombatSubsystemControllerInstance *self, int id) {
        s_e640_calls++;
        s_last_e640_self = self;
        s_last_e640_id = id;
        s_call_order.push_back("func_0032E640");
    }

    void *sub_260E50(void *target_sub, int action_id, int a2, int param, int a3) {
        s_sub260e50_calls++;
        s_last_260e50_target = target_sub;
        s_last_260e50_action_id = action_id;
        s_last_260e50_a2 = a2;
        s_last_260e50_param = param;
        s_last_260e50_a3 = a3;
        s_call_order.push_back("sub_260E50");
        return s_dummy_ret_slot;
    }
}

static TargetSub12C s_target_sub12c;
static SlotEntry s_sample_slot;

static void reset_mocks() {
    s_32e820_calls = 0;
    s_last_32e820_self = nullptr;

    s_sub260ed0_calls = 0;
    s_last_sub260ed0_target = nullptr;

    s_e640_calls = 0;
    s_last_e640_self = nullptr;
    s_last_e640_id = -1;

    s_sub260e50_calls = 0;
    s_last_260e50_target = nullptr;
    s_last_260e50_action_id = -1;
    s_last_260e50_a2 = -1;
    s_last_260e50_param = -1;
    s_last_260e50_a3 = 0;

    s_call_order.clear();

    std::memset(&s_target_sub12c, 0, sizeof(s_target_sub12c));
    s_target_sub12c.m_sub_target = (void*)0x11223344;

    std::memset(&s_sample_slot, 0, sizeof(s_sample_slot));
    s_sample_slot.flag = 4;
    s_sample_slot.action_id = 2962;
}

static void test_cleanup_on_nonzero_t0() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;

    func_0032E6B0(&inst, 2961, 0, -1, 1);

    TEST_ASSERT(s_e640_calls == 1, "must unconditionally dispatch func_0032E640");
    TEST_ASSERT(s_last_e640_id == 2, "func_0032E640 target id must be 2");
    TEST_ASSERT(s_32e820_calls == 1, "t0!=0 must dispatch cleanup func_0032E820");
    TEST_ASSERT(s_last_32e820_self == &inst, "func_0032E820 self mismatch");
}

static void test_cleanup_suppressed_on_zero_t0() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;

    func_0032E6B0(&inst, 2962, 0, 0, 0);

    TEST_ASSERT(s_32e820_calls == 0, "t0==0 must suppress cleanup func_0032E820");
    TEST_ASSERT(s_e640_calls == 1, "must unconditionally dispatch func_0032E640");
}

static void test_sub260ed0_called_on_valid_slot() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;

    inst.m_slot_count = 0;
    inst.m_slots[0] = &s_sample_slot;
    inst.m_slot_action_ids[0] = 2962;

    func_0032E6B0(&inst, 2962, 0, 0, 0);

    TEST_ASSERT(s_sub260ed0_calls == 1, "valid slot on t0==0 must call sub_260ED0");
    TEST_ASSERT(s_last_sub260ed0_target == (void*)0x11223344, "sub_260ED0 target mismatch");
    TEST_ASSERT(inst.m_slots[0] == (SlotEntry*)s_dummy_ret_slot, "slot must receive new order return");
    TEST_ASSERT(inst.m_slot_action_ids[0] == 2962, "dispatched action id must be recorded in table");
    TEST_ASSERT(inst.m_slot_count == 1, "slot count must be incremented to 1");
}

static void test_final_sub260e50_param_encoding() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;

    // Case 1: action_id == 2961, a2 == 0 -> param must be 0
    func_0032E6B0(&inst, 2961, 0, -1, 1);
    TEST_ASSERT(s_last_260e50_target == (void*)0x11223344, "sub_260E50 receiver mismatch");
    TEST_ASSERT(s_last_260e50_action_id == 2961, "sub_260E50 action_id mismatch");
    TEST_ASSERT(s_last_260e50_a2 == 0, "sub_260E50 a2 must be 0");
    TEST_ASSERT(s_last_260e50_param == 0, "param for 2961 with a2==0 must be 0");
    TEST_ASSERT(s_last_260e50_a3 == -1, "sub_260E50 a3 mismatch");

    TEST_ASSERT(s_call_order.size() >= 3, "must have at least 3 calls in sequence");
    TEST_ASSERT(std::strcmp(s_call_order[0], "func_0032E820") == 0, "first call must be cleanup func_0032E820");
    TEST_ASSERT(std::strcmp(s_call_order[1], "func_0032E640") == 0, "second call must be func_0032E640");
    TEST_ASSERT(std::strcmp(s_call_order[2], "sub_260E50") == 0, "third call must be sub_260E50");

    // Case 2: action_id == 2962, a2 == 0 -> param must be 1 (bit 0 set)
    reset_mocks();
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;
    func_0032E6B0(&inst, 2962, 0, 5, 0);
    TEST_ASSERT(s_last_260e50_param == 1, "param for 2962 with a2==0 must be 1");
    TEST_ASSERT(s_last_260e50_a3 == 5, "sub_260E50 a3 mismatch on 2962");

    // Case 3: action_id == 2962, a2 == 4 -> param must be 1 | 4 = 5
    reset_mocks();
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;
    func_0032E6B0(&inst, 2962, 4, 7, 0);
    TEST_ASSERT(s_last_260e50_param == 5, "param for 2962 with a2!=0 must be 5");

    // Case 4: action_id == 2961, a2 == 0x120 -> param masked with 0xFF must be 0x20
    reset_mocks();
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;
    func_0032E6B0(&inst, 2961, 0x120, 0, 1);
    TEST_ASSERT(s_last_260e50_param == 0x20, "param with a2==0x120 must mask to 0x20");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "cleanup_t0") == 0) { test_cleanup_on_nonzero_t0(); return 0; }
        if (std::strcmp(argv[1], "suppress_t0") == 0) { test_cleanup_suppressed_on_zero_t0(); return 0; }
        if (std::strcmp(argv[1], "valid_slot") == 0) { test_sub260ed0_called_on_valid_slot(); return 0; }
        if (std::strcmp(argv[1], "param_encoding") == 0) { test_final_sub260e50_param_encoding(); return 0; }
    }
    test_cleanup_on_nonzero_t0();
    test_cleanup_suppressed_on_zero_t0();
    test_sub260ed0_called_on_valid_slot();
    test_final_sub260e50_param_encoding();
    return 0;
}
