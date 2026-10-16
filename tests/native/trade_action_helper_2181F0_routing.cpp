#include "trade_action_helper_2181F0_fixture.h"

void test_cases_callbacks(int case_number) {
    unsigned char object[0x200];
    reset_fixture();
    initialize_object(object, 4, 4);
    *reinterpret_cast<int *>(object + 0x80) = 1;
    if (case_number == 6) *reinterpret_cast<int *>(object + 0x8C) = 1;
    if (case_number == 7) {
        *reinterpret_cast<int *>(object + 0x8C) = 1;
        *reinterpret_cast<int *>(object + 0x90) = 1;
    }
    if (case_number == 9) {
        *reinterpret_cast<int *>(object + 0x8C) = 1;
        *reinterpret_cast<int *>(object + 0x90) = 1;
        *reinterpret_cast<short *>(object + 0x126) = 5;
        mutate_callback_state = 1;
        set_bound_after_callback = 5;
    }
    func_002181F0(object);
    if (case_number == 6) {
        assert(callback_count == 1 && callback_mode == 0);
        assert(callback_handle_last == result_handle && callback_index_last == 0);
        assert(callback_sequence_last == 4);
    } else if (case_number == 7) {
        assert(callback_count == 1 && callback_mode == 1);
        assert(callback_handle_last == result_handle && callback_index_last == 0);
        assert(callback_sequence_last == 4);
    } else if (case_number == 8) {
        assert(callback_count == 0 && callback_mode == -1);
    } else {
        assert(case_number == 9);
        assert(callback_count == 1 && callback_mode == 1);
        assert(*reinterpret_cast<short *>(object + 0x126) == 5);
        assert(*reinterpret_cast<short *>(object + 0x124) == 4);
    }
    assert(range_call_count == 2 && cleanup_count == 1 && finish_count == 1);
}
