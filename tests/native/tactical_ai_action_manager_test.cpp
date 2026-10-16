#include "tactical_ai_action_manager_fixture.h"

static void test_constructor() {
    TacticalActionManagerObj obj;
    std::memset(&obj, 0xA5, sizeof(obj));

    TacticalActionManagerObj snapshot;
    std::memcpy(&snapshot, &obj, sizeof(obj));

    reset_tracking();
    s_expected_base_snapshot = &snapshot;

    void *ret = func_00307320(&obj);
    assert(ret == &obj);
    assert(s_call_count == 1);
    assert(s_call_history[0] == CALL_BASE_CTOR_3285D0);
    assert(s_last_self == &obj);

    // Build expected whole object starting with 0xA5 and applying documented stores
    TacticalActionManagerObj expected;
    std::memset(&expected, 0xA5, sizeof(expected));
    expected.m_vtable = &D_4DE780;
    expected.m_field19C = 0;
    expected.m_field1A0 = 0;
    expected.m_field194 = 0;
    expected.m_field1A4 = 0;
    expected.m_field198 = 0;
    expected.m_field1D0 = -1;
    expected.m_field1B1 = 0;
    expected.m_field1B2 = 0;
    expected.m_field1B3 = 0;
    expected.m_field1A8 = 0;
    expected.m_field1AC = 0;
    expected.m_field1B0 = 0;

    for (int i = 0; i < 5; i++) {
        expected.m_array1[i] = 0;
        expected.m_array2[i] = 0;
        expected.m_array3[i] = 0;
        expected.m_array4[i] = 0;
        expected.m_array5[i] = 0;
        expected.m_array6[i] = 0;
    }

    // Verify all 588 bytes match exactly, confirming pad04, pad44, pad8C, pad199, pad1B4
    assert(std::memcmp(&obj, &expected, sizeof(obj)) == 0);
}

static void test_destructor_null() {
    const int flag_cases[] = {0, 1, 2, -1, 0x10000, 0x18000, 0x10001};
    const int num_cases = sizeof(flag_cases) / sizeof(flag_cases[0]);

    for (int i = 0; i < num_cases; i++) {
        reset_tracking();
        void *ret = func_003073C0(0, flag_cases[i]);
        assert(ret == 0);
        assert(s_call_count == 0);
    }
}

static void test_destructor_flags() {
    struct TestCase {
        int flags;
        bool expect_free;
    };

    const TestCase cases[] = {
        {0, false}, {1, true}, {2, true}, {-1, false},
        {0x10000, false}, {0x18000, false}, {0x10001, true},
        {-32768, false}, {32767, true}
    };
    const int num_cases = sizeof(cases) / sizeof(cases[0]);

    for (int i = 0; i < num_cases; i++) {
        TacticalActionManagerObj obj;
        std::memset(&obj, 0x55, sizeof(obj));
        obj.m_vtable = &D_4DE780;

        reset_tracking();
        void *ret = func_003073C0(&obj, cases[i].flags);
        assert(ret == &obj);
        assert(s_call_count >= 1);
        assert(s_call_history[0] == CALL_SUB_DTOR_1A2CF0);
        assert(s_last_arg == 0);
        assert(s_vtable_at_sub_dtor == &D_4DEBF0);
        assert(obj.m_vtable == &D_4DEBF0);

        if (cases[i].expect_free) {
            assert(s_call_count == 2);
            assert(s_call_history[1] == CALL_FREE_100670);
            assert(s_last_self == &obj);
        } else {
            assert(s_call_count == 1);
        }
    }
}

static void test_dispatcher_condition_reads_after_pre_notify() {
    TacticalActionManagerObj obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.m_field40 = reinterpret_cast<void *>(0x404040);
    obj.m_field84 = reinterpret_cast<void *>(0x84);
    obj.m_field88 = 0; // Initially NULL! Pre-notify will mutate it to 0x88
    set_global_val(0); // Initially 0! Pre-notify will mutate it to 5

    reset_tracking();
    s_mutate_in_pre_notify = true;
    s_target_mutation_obj = &obj;

    func_00307420(&obj, 777);

    // Proves condition reads happened AFTER func_1a34d0 mutated the fields
    assert(s_call_count == 2);
    assert(s_call_history[0] == CALL_PRE_NOTIFY_1A34D0);
    assert(s_call_history[1] == CALL_FORWARD_242FC0);
    assert(s_last_self == obj.m_field40);
    assert(s_last_arg == 777);
}

static void test_dispatcher_outer_false() {
    TacticalActionManagerObj obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.m_field40 = reinterpret_cast<void *>(0x404040);
    set_global_val(4);

    // Case 1: arg1 == 0
    obj.m_field88 = reinterpret_cast<void *>(0x88);
    obj.m_field84 = reinterpret_cast<void *>(0x84);
    reset_tracking();
    func_00307420(&obj, 0);
    assert(s_call_count == 2 && s_call_history[1] == CALL_ERROR_LOG_118DE0);

    // Case 2: m_field88 == NULL
    obj.m_field88 = 0;
    reset_tracking();
    func_00307420(&obj, 42);
    assert(s_call_count == 2 && s_call_history[1] == CALL_ERROR_LOG_118DE0);

    // Case 3: m_field84 == NULL
    obj.m_field88 = reinterpret_cast<void *>(0x88);
    obj.m_field84 = 0;
    reset_tracking();
    func_00307420(&obj, 42);
    assert(s_call_count == 2 && s_call_history[1] == CALL_ERROR_LOG_118DE0);
    assert(s_last_msg == D_004D1930);
}

static void test_dispatcher_outer_true() {
    TacticalActionManagerObj obj;
    std::memset(&obj, 0, sizeof(obj));
    obj.m_field40 = reinterpret_cast<void *>(0x505050);
    obj.m_field84 = reinterpret_cast<void *>(0x84);
    obj.m_field88 = reinterpret_cast<void *>(0x88);

    const int target_arg = 999;
    const int match_globals[] = {4, 5};
    for (int i = 0; i < 2; i++) {
        set_global_val(match_globals[i]);
        reset_tracking();
        func_00307420(&obj, target_arg);
        assert(s_call_count == 2);
        assert(s_call_history[0] == CALL_PRE_NOTIFY_1A34D0);
        assert(s_call_history[1] == CALL_FORWARD_242FC0);
        assert(s_last_self == obj.m_field40);
        assert(s_last_arg == target_arg);
    }

    const int non_match_globals[] = {0, 1, 2, 3, 6, 7, 10, -1, INT_MIN, INT_MAX};
    const int num_non_match = sizeof(non_match_globals) / sizeof(non_match_globals[0]);
    for (int i = 0; i < num_non_match; i++) {
        set_global_val(non_match_globals[i]);
        reset_tracking();
        func_00307420(&obj, target_arg);
        assert(s_call_count == 1 && s_call_history[0] == CALL_PRE_NOTIFY_1A34D0);
    }
}

int main() {
    test_constructor();
    test_destructor_null();
    test_destructor_flags();
    test_dispatcher_condition_reads_after_pre_notify();
    test_dispatcher_outer_false();
    test_dispatcher_outer_true();
    return 0;
}
