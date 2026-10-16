#include "trade_action_helper_2184D0_support.h"

using namespace helper_2184d0_test;

namespace {

void test_zero_x_step_with_positive_span_traps_before_visit() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    mutate_manager(manager, 100);
    state.mutate_begin = true;
    set_field(object, 0x184, static_cast<short>(0));
    set_field(object, 0x186, static_cast<short>(2));
    set_field(object, 0x14, 5);
    set_field(object, 0x18, 2);
    func_002184D0(object);
}

void test_zero_y_step_with_positive_span_traps_before_visit() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    mutate_manager(manager, 100);
    state.mutate_begin = true;
    set_field(object, 0x184, static_cast<short>(2));
    set_field(object, 0x186, static_cast<short>(0));
    set_field(object, 0x14, 5);
    set_field(object, 0x18, 5);
    func_002184D0(object);
}

void test_zero_spans_with_nonzero_steps_visit_once() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    set_field(object, 0x184, static_cast<short>(2));
    set_field(object, 0x186, static_cast<short>(2));
    set_field(object, 0x14, 0);
    set_field(object, 0x18, 0);
    func_002184D0(object);
    assert(state.handler_calls == 1);
    assert((state.events == std::vector<int>{1, 2, 3, 4}));
}

void test_rectangle_callback_arguments_and_cleanup() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    set_field(object, 0x180, static_cast<void *>(nullptr));
    set_field(object, 0x188, 1);
    set_field(object, 0x0c, 2);
    set_field(object, 0x10, 4);
    set_field(object, 0x14, 5);
    set_field(object, 0x18, 1);
    set_field(object, 0x18c, static_cast<unsigned char>(0xa5));
    func_002184D0(object);
    assert(state.rectangle_calls == 1);
    assert(state.rectangle_arguments[0] == manager);
    assert(state.rectangle_arguments[1] == reinterpret_cast<void *>(2));
    assert(state.rectangle_arguments[2] == reinterpret_cast<void *>(4));
    assert(state.rectangle_arguments[3] == reinterpret_cast<void *>(6));
    assert(state.rectangle_arguments[4] == reinterpret_cast<void *>(4));
    assert(state.rectangle_arguments[5] == reinterpret_cast<void *>(0xa5));
    assert((state.events == std::vector<int>{2, 5, 4}));
}

void test_fallback_virtual_slots_receive_exact_arguments() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    unsigned char receiver[0x100];
    void *vtable[18] = {};
    initialize(object, manager);
    std::memset(receiver, 0, sizeof(receiver));
    set_field(object, 0x180, static_cast<void *>(nullptr));
    set_field(object, 0x188, 0);
    set_field(object, 0x40, static_cast<void *>(receiver));
    set_field(receiver, 0, static_cast<void *>(vtable));
    vtable[0x3c / 4] = reinterpret_cast<void *>(&virtual_slot_3c);
    vtable[0x44 / 4] = reinterpret_cast<void *>(&virtual_slot_44);
    set_field(object, 0x1ac, 2);
    func_002184D0(object);
    assert(state.virtual_calls == 1);
    assert(state.events[0] == 7);
    assert(state.virtual_receiver == receiver);
    assert(state.virtual_argument == object + 0x24);
    state = CallbackState();
    state.self = object;
    set_field(object, 0x1ac, 1);
    func_002184D0(object);
    assert(state.virtual_calls == 1);
    assert(state.events[0] == 6);
    assert(state.virtual_receiver == receiver);
    assert(state.virtual_argument == object + 0x24);
}

void test_clip_mutations_are_reloaded_for_grid_counts() {
    unsigned char object[0x300];
    unsigned char manager[0x100];
    initialize(object, manager);
    set_field(object, 0x184, static_cast<short>(2));
    set_field(object, 0x186, static_cast<short>(2));
    set_field(object, 0x14, 2);
    set_field(object, 0x18, 2);
    state.mutate_clip = true;
    func_002184D0(object);
    assert(state.handler_calls == 3);
    assert(state.cleanup_calls == 1);
}

}  // namespace

namespace helper_2184d0_test {

void run_extra_case(int test_case) {
    switch (test_case) {
        case 6: test_zero_spans_with_nonzero_steps_visit_once(); break;
        case 7: test_rectangle_callback_arguments_and_cleanup(); break;
        case 8: test_fallback_virtual_slots_receive_exact_arguments(); break;
        case 9: test_clip_mutations_are_reloaded_for_grid_counts(); break;
        case 10: test_zero_x_step_with_positive_span_traps_before_visit(); break;
        case 11: test_zero_y_step_with_positive_span_traps_before_visit(); break;
    }
}

}  // namespace helper_2184d0_test
