#include "trade_action_helper_2181F0_fixture.h"

void test_cases_mutations(int case_number) {
    unsigned char object[0x200];
    reset_fixture();
    initialize_object(object, 2, 2);
    if (case_number == 10) {
        result_handle = 0;
        mutate_begin_pointer = 1;
    } else {
        *reinterpret_cast<int *>(object + 0x8C) = 1;
        *reinterpret_cast<int *>(object + 0x90) = 1;
        if (case_number == 11) {
            mutate_callback_pointer = 1;
            callback_pointer_value = nullptr;
        }
        if (case_number == 12) {
            *reinterpret_cast<short *>(object + 0x126) = 4;
            set_bound_after_callback = 2;
        }
    }
    func_002181F0(object);
    if (case_number == 10) {
        assert(begin_count == 1 && begin_argument == 0);
        assert(lookup_count == 1 && lookup_argument == nullptr);
        assert(finish_count == 1 && cleanup_count == 0 && range_call_count == 0);
        return;
    }
    assert(case_number == 11 || case_number == 12);
    assert(callback_count == 1);
    assert(range_call_count == 2 && finish_count == 1 && cleanup_count == 1);
    if (case_number == 11) {
        assert(lookup_argument != nullptr && cleanup_argument == nullptr);
        assert(*reinterpret_cast<void **>(object + 0x20) == nullptr);
    }
    if (case_number == 12) {
        assert(cleanup_argument == *reinterpret_cast<void **>(object + 0x20));
        assert(*reinterpret_cast<short *>(object + 0x126) == 2);
        assert(*reinterpret_cast<short *>(object + 0x124) == 2);
    }
}
