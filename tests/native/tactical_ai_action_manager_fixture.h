#ifndef TACTICAL_AI_ACTION_MANAGER_FIXTURE_H
#define TACTICAL_AI_ACTION_MANAGER_FIXTURE_H

#include <cassert>
#include <climits>
#include <cstddef>
#include <cstring>
#include "tactical_ai_action_manager.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");
static_assert(sizeof(int) == 4, "native fixture requires 32-bit integers");
static_assert(sizeof(TacticalActionManagerObj) == 588, "TacticalActionManagerObj ABI size");

// Mock global addresses and buffers
static int s_dummy_vtable_ctor = 0x4DE780;
static int s_dummy_vtable_dtor = 0x4DEBF0;
void *D_4DE780 = &s_dummy_vtable_ctor;
void *D_4DEBF0 = &s_dummy_vtable_dtor;
const char D_004D1930[] = "TacticalActionManager Error Notification";

static char s_global_state_buffer[1024] __attribute__((aligned(4)));
void *D_004E3180 = s_global_state_buffer;

enum CallType {
    CALL_NONE = 0,
    CALL_BASE_CTOR_3285D0,
    CALL_SUB_DTOR_1A2CF0,
    CALL_FREE_100670,
    CALL_PRE_NOTIFY_1A34D0,
    CALL_FORWARD_242FC0,
    CALL_ERROR_LOG_118DE0
};

static const int MAX_CALLS = 16;
static CallType s_call_history[MAX_CALLS];
static int s_call_count = 0;
static void *s_last_self = 0;
static int s_last_arg = 0;
static const char *s_last_msg = 0;
static void *s_vtable_at_sub_dtor = 0;

// Pre-call snapshot and mutation control
static const void *s_expected_base_snapshot = 0;
static bool s_mutate_in_pre_notify = false;
static TacticalActionManagerObj *s_target_mutation_obj = 0;

static void set_global_val(int val) {
    std::memcpy(s_global_state_buffer + 456, &val, sizeof(val));
}

static void reset_tracking() {
    std::memset(s_call_history, 0, sizeof(s_call_history));
    s_call_count = 0;
    s_last_self = 0;
    s_last_arg = 0;
    s_last_msg = 0;
    s_vtable_at_sub_dtor = 0;
    s_expected_base_snapshot = 0;
    s_mutate_in_pre_notify = false;
    s_target_mutation_obj = 0;
}

static void record_call(CallType call) {
    assert(s_call_count < MAX_CALLS);
    s_call_history[s_call_count++] = call;
}

extern "C" {

void *func_3285d0(void *self) {
    record_call(CALL_BASE_CTOR_3285D0);
    s_last_self = self;
    if (s_expected_base_snapshot) {
        assert(std::memcmp(self, s_expected_base_snapshot, sizeof(TacticalActionManagerObj)) == 0);
    }
    return self;
}

void func_1a2cf0(void *self, int zero) {
    record_call(CALL_SUB_DTOR_1A2CF0);
    s_last_self = self;
    s_last_arg = zero;
    TacticalActionManagerObj *obj = static_cast<TacticalActionManagerObj *>(self);
    s_vtable_at_sub_dtor = obj->m_vtable;
}

void func_100670(void *ptr) {
    record_call(CALL_FREE_100670);
    s_last_self = ptr;
}

void func_1a34d0(void *self) {
    record_call(CALL_PRE_NOTIFY_1A34D0);
    s_last_self = self;
    if (s_mutate_in_pre_notify && s_target_mutation_obj) {
        s_target_mutation_obj->m_field88 = reinterpret_cast<void *>(0x88);
        set_global_val(5);
    }
}

void func_242fc0(void *field40, int arg1) {
    record_call(CALL_FORWARD_242FC0);
    s_last_self = field40;
    s_last_arg = arg1;
}

void func_118de0(const char *msg) {
    record_call(CALL_ERROR_LOG_118DE0);
    s_last_msg = msg;
}

} // extern "C"

#endif // TACTICAL_AI_ACTION_MANAGER_FIXTURE_H
