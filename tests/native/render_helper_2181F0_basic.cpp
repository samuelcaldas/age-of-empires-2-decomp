#include "render_helper_2181F0_fixture.h"

void test_cases_basic(int case_number) {
    unsigned char object[0x200];
    reset_fixture();
    initialize_object(object, 10, 10);
    if (case_number == 0) *reinterpret_cast<void **>(object + 0x20) = nullptr;
    if (case_number == 1) *reinterpret_cast<void **>(object + 0x88) = nullptr;
    if (case_number == 2) result_handle = 0;
    if (case_number == 3) {
        *reinterpret_cast<int *>(object + 0x8C) = 1;
        *reinterpret_cast<int *>(object + 0x90) = 1;
    }
    if (case_number == 4) {
        *reinterpret_cast<int *>(object + 0x8C) = 1;
        *reinterpret_cast<int *>(object + 0x90) = 1;
        *reinterpret_cast<short *>(object + 0x126) = 11;
    }
    if (case_number == 5) {
        *reinterpret_cast<int *>(object + 0x8C) = 1;
        *reinterpret_cast<int *>(object + 0x90) = 1;
        *reinterpret_cast<short *>(object + 0x124) = 13;
        *reinterpret_cast<short *>(object + 0x126) = 12;
    }
    func_002181F0(object);
    assert(*reinterpret_cast<int *>(object + 0x38) == 0);
    if (case_number < 2) {
        assert(begin_count == 0 && lookup_count == 0 && finish_count == 0);
        return;
    }
    assert(begin_count == 1 && begin_argument == 0);
    assert(lookup_count == 1 && lookup_argument != nullptr);
    assert(finish_count == 1);
    if (case_number == 2) {
        assert(range_call_count == 0 && cleanup_count == 0 && callback_count == 0);
        return;
    }
    if (case_number == 3) {
        assert(callback_count == 1 && callback_mode == 1);
        assert(callback_self_last == object && callback_handle_last == result_handle);
        assert(callback_index_last == 0 && callback_sequence_last == 10);
        assert(*reinterpret_cast<short *>(object + 0x126) == 10);
        assert(range_call_count == 2 && range_value_last == first_result);
        assert(range_argument_last == reinterpret_cast<void *>(result_handle));
        assert(cleanup_count == 1 && cleanup_argument == lookup_argument);
        assert(*reinterpret_cast<short *>(object + 0x124) == 10);
        return;
    }
    if (case_number == 4) {
        assert(callback_count == 2 && callback_sequence_last == 11);
        assert(callback_index_last == 1 && range_call_count == 2);
        return;
    }
    assert(case_number == 5);
    assert(callback_count == 0 && range_call_count == 2 && cleanup_count == 1);
}
