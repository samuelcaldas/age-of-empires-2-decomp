#include "trade_action_helper_2181F0_fixture.h"

void test_cases_wrap(int case_number) {
    assert(case_number == 13);
    unsigned char object[0x200];
    reset_fixture();
    initialize_object(object, 32767, 32767);
    *reinterpret_cast<int *>(object + 0x8C) = 1;
    *reinterpret_cast<int *>(object + 0x90) = 1;
    stop_after_callback = 32769;
    func_002181F0(object);
    assert(callback_count == 32769);
    assert(callback_sequence_last == -1);
    assert(callback_index_last == -32768);
    assert(range_call_count == 2 && cleanup_count == 1 && finish_count == 1);
}
