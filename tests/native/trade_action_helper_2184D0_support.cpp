#include "trade_action_helper_2184D0_support.h"
#include <csignal>
#include <cstdlib>

extern "C" void helper_2184d0_mock_break(int code) {
    helper_2184d0_test::state.break_code = code;
    std::raise(SIGTRAP);
}

namespace helper_2184d0_test {

CallbackState state;

void initialize(unsigned char *object, unsigned char *manager) {
    std::memset(object, 0, 0x300);
    std::memset(manager, 0, 0x100);
    state = CallbackState();
    state.self = object;
    state.manager = manager;
    state.begin_return = 1;
    set_field(object, 0x20, static_cast<void *>(manager));
    set_field(object, 0x180, reinterpret_cast<void *>(0x8888));
}

void mutate_manager(unsigned char *manager, int base) {
    for (int offset = 0x28; offset <= 0x34; offset += 4) {
        set_field(manager, static_cast<size_t>(offset), base + offset);
    }
}

void assert_manager(const unsigned char *manager, int base) {
    for (int offset = 0x28; offset <= 0x34; offset += 4) {
        assert(get_field<int>(manager, static_cast<size_t>(offset)) == base + offset);
    }
}

void mutate_handler(void *manager) {
    if (!state.mutate_handler) {
        return;
    }
    const int call = state.handler_calls;
    set_field(state.self, 0x184, static_cast<short>(call + 2));
    set_field(state.self, 0x0c, static_cast<void *>(reinterpret_cast<void *>(10 * call)));
    set_field(state.self, 0x180, reinterpret_cast<void *>(0x8888 + call));
    mutate_manager(static_cast<unsigned char *>(manager), call * 100 + 500);
    set_field(state.self, 0x20, state.handler_manager_replacement);
}

void virtual_slot_3c(void *receiver, void *argument) {
    state.events.push_back(6);
    ++state.virtual_calls;
    state.virtual_receiver = receiver;
    state.virtual_argument = argument;
}

void virtual_slot_44(void *receiver, void *argument) {
    state.events.push_back(7);
    ++state.virtual_calls;
    state.virtual_receiver = receiver;
    state.virtual_argument = argument;
}

}  // namespace helper_2184d0_test

using namespace helper_2184d0_test;

extern "C" {

int func_001AC470(void *, void *, void *, int, int) {
    state.events.push_back(1);
    ++state.begin_calls;
    if (state.mutate_begin) {
        set_field(state.self, 0x14, 5);
        set_field(state.self, 0x18, 2);
        void *manager = get_field<void *>(state.self, 0x20);
        mutate_manager(static_cast<unsigned char *>(manager), 900);
    }
    return 1;
}

int func_001AB8F0(void *, int) {
    state.events.push_back(2);
    ++state.clip_calls;
    if (state.mutate_clip) {
        set_field(state.self, 0x14, 5);
        set_field(state.self, 0x18, 2);
    }
    return state.begin_return;
}

int func_0025E640(void *field, void *manager, void *x, void *y, int arg4, int arg5) {
    state.events.push_back(3);
    ++state.handler_calls;
    state.positions_x.push_back(static_cast<int>(reinterpret_cast<intptr_t>(x)));
    state.positions_y.push_back(static_cast<int>(reinterpret_cast<intptr_t>(y)));
    state.handler_fields.push_back(field);
    state.handler_managers.push_back(manager);
    assert(arg4 == 0);
    assert(arg5 == 0);
    mutate_handler(manager);
    return 1;
}

int func_001AB9D0(void *) {
    state.events.push_back(4);
    ++state.cleanup_calls;
    return 1;
}

int func_001AD650(void *manager, void *x0, void *y0, int x1, int y1, int flag) {
    state.events.push_back(5);
    ++state.rectangle_calls;
    state.rectangle_arguments[0] = manager;
    state.rectangle_arguments[1] = x0;
    state.rectangle_arguments[2] = y0;
    state.rectangle_arguments[3] = reinterpret_cast<void *>(static_cast<intptr_t>(x1));
    state.rectangle_arguments[4] = reinterpret_cast<void *>(static_cast<intptr_t>(y1));
    state.rectangle_arguments[5] = reinterpret_cast<void *>(static_cast<intptr_t>(flag));
    return 1;
}

}
