#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include "tactical_ai_combat_subsystem_controller_cleanup.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static int s_sub260ed0_calls = 0;
static void *s_last_sub260ed0_target = nullptr;
static bool s_slot_intact_during_callback = false;

static CombatSubsystemControllerInstance *s_active_inst = nullptr;

extern "C" {
    void sub_260ED0(void *target_sub) {
        s_sub260ed0_calls++;
        s_last_sub260ed0_target = target_sub;
        if (s_active_inst != nullptr && s_active_inst->m_slots[0] != nullptr) {
            s_slot_intact_during_callback = true;
        }
    }
}

static TargetSub12C s_target_sub12c;
static SlotSub s_slot_sub;
static SlotEntry s_slot_entry;

static SlotSub s_slot_sub_signed;
static SlotEntry s_slot_entry_signed;

static SlotSub s_slot_sub_9;
static SlotEntry s_slot_entry_9;

static void reset_mocks() {
    s_sub260ed0_calls = 0;
    s_last_sub260ed0_target = nullptr;
    s_slot_intact_during_callback = false;
    s_active_inst = nullptr;

    std::memset(&s_target_sub12c, 0, sizeof(s_target_sub12c));
    s_target_sub12c.m_sub_target = (void*)0x11223344;

    std::memset(&s_slot_sub, 0, sizeof(s_slot_sub));
    s_slot_sub.action_id = 100;

    std::memset(&s_slot_entry, 0, sizeof(s_slot_entry));
    s_slot_entry.flag = 4;
    s_slot_entry.m_sub = &s_slot_sub;

    std::memset(&s_slot_sub_signed, 0, sizeof(s_slot_sub_signed));
    s_slot_sub_signed.action_id = (short)-500;

    std::memset(&s_slot_entry_signed, 0, sizeof(s_slot_entry_signed));
    s_slot_entry_signed.flag = 4;
    s_slot_entry_signed.m_sub = &s_slot_sub_signed;

    std::memset(&s_slot_sub_9, 0, sizeof(s_slot_sub_9));
    s_slot_sub_9.action_id = 200;

    std::memset(&s_slot_entry_9, 0, sizeof(s_slot_entry_9));
    s_slot_entry_9.flag = 4;
    s_slot_entry_9.m_sub = &s_slot_sub_9;
}

static void test_matching_active_slot_callback_and_clearing() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;

    inst.m_slots[0] = &s_slot_entry;
    inst.m_slot_action_ids[0] = 100;
    s_active_inst = &inst;

    func_0032E820(&inst);

    TEST_ASSERT(s_sub260ed0_calls == 1, "matching active slot must call sub_260ED0");
    TEST_ASSERT(s_last_sub260ed0_target == (void*)0x11223344, "callback must receive target_sub->field_120");
    TEST_ASSERT(s_slot_intact_during_callback == true, "slot must remain intact during callback");
    TEST_ASSERT(inst.m_slots[0] == nullptr, "slot must be cleared after return");
}

static void test_signed_action_id_sign_extension() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;

    inst.m_slots[0] = &s_slot_entry_signed;
    inst.m_slot_action_ids[0] = -500; // 32-bit signed int matching short -500
    s_active_inst = &inst;

    func_0032E820(&inst);

    TEST_ASSERT(s_sub260ed0_calls == 1, "signed negative action_id must sign-extend and match");
    TEST_ASSERT(inst.m_slots[0] == nullptr, "signed matching slot must be cleared");
}

static void test_all_ten_slots_traversed() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;

    inst.m_slots[9] = &s_slot_entry_9;
    inst.m_slot_action_ids[9] = 200;

    func_0032E820(&inst);

    TEST_ASSERT(inst.m_slots[9] == nullptr, "slot 9 must be traversed and cleared on match");
    TEST_ASSERT(s_sub260ed0_calls == 1, "slot 9 match must dispatch sub_260ED0");
}

static void test_null_sub_skips_callback() {
    reset_mocks();
    CombatSubsystemControllerInstance inst;
    std::memset(&inst, 0, sizeof(inst));
    inst.m_sub12c = &s_target_sub12c;

    // entry with flag=4 but m_sub=null: must not call sub_260ED0 or clear slot
    static SlotEntry s_null_sub_entry;
    std::memset(&s_null_sub_entry, 0, sizeof(s_null_sub_entry));
    s_null_sub_entry.flag = 4;
    s_null_sub_entry.m_sub = nullptr;

    inst.m_slots[0] = &s_null_sub_entry;
    inst.m_slot_action_ids[0] = 0;

    func_0032E820(&inst);

    TEST_ASSERT(s_sub260ed0_calls == 0, "null m_sub must not dispatch sub_260ED0");
    TEST_ASSERT(inst.m_slots[0] == &s_null_sub_entry, "null m_sub slot must not be cleared");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "matching_slot") == 0) { test_matching_active_slot_callback_and_clearing(); return 0; }
        if (std::strcmp(argv[1], "signed_id") == 0) { test_signed_action_id_sign_extension(); return 0; }
        if (std::strcmp(argv[1], "slot_9") == 0) { test_all_ten_slots_traversed(); return 0; }
        if (std::strcmp(argv[1], "null_sub") == 0) { test_null_sub_skips_callback(); return 0; }
    }
    test_matching_active_slot_callback_and_clearing();
    test_signed_action_id_sign_extension();
    test_all_ten_slots_traversed();
    test_null_sub_skips_callback();
    return 0;
}
