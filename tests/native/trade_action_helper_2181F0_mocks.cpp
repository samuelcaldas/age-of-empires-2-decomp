#include "trade_action_helper_2181F0_fixture.h"

int result_handle = 77;
int first_result = 91;
int callback_count = 0;
int begin_count = 0;
int finish_count = 0;
int lookup_count = 0;
int range_call_count = 0;
int mutate_callback_pointer = 0;
void *callback_pointer_value = nullptr;
void *range_argument_last = nullptr;
int range_value_last = -1;
int cleanup_count = 0;
void *lookup_argument = nullptr;
void *cleanup_argument = nullptr;
int begin_argument = -1;
int callback_mode = -1;
int mutate_begin_pointer = 0;
int mutate_callback_state = 0;
int stop_after_callback = 0;
int set_bound_after_callback = -1;
int callback_sequence_last = 0;
int callback_index_last = 0;
int callback_handle_last = 0;
void *callback_self_last = nullptr;
void *vtable[73];
unsigned char *active_object = nullptr;

static void mock_begin(void *self, int argument) {
    ++begin_count;
    begin_argument = argument;
    if (mutate_begin_pointer) *reinterpret_cast<void **>(active_object + 0x20) = nullptr;
}

static void mock_finish(void *self) { ++finish_count; }

static void mock_callback(void *self, void *handle, void *index, void *sequence, void *mode) {
    ++callback_count;
    callback_self_last = self;
    callback_handle_last = static_cast<int>(reinterpret_cast<uintptr_t>(handle));
    callback_index_last = static_cast<int>(reinterpret_cast<uintptr_t>(index));
    callback_sequence_last = static_cast<int>(reinterpret_cast<uintptr_t>(sequence));
    callback_mode = static_cast<int>(reinterpret_cast<uintptr_t>(mode));
    if (mutate_callback_pointer) {
        *reinterpret_cast<void **>(active_object + 0x20) = callback_pointer_value;
    }
    if (mutate_callback_state) {
        *reinterpret_cast<int *>(active_object + 0x8C) = 0;
        *reinterpret_cast<int *>(active_object + 0x90) = 0;
        *reinterpret_cast<int *>(active_object + 0x80) = 0;
    }
    if (set_bound_after_callback >= 0) {
        *reinterpret_cast<short *>(active_object + 0x126) =
            static_cast<short>(set_bound_after_callback);
    }
    if (stop_after_callback != 0 && callback_count == stop_after_callback) {
        *reinterpret_cast<short *>(active_object + 0x126) = -32768;
    }
}

static void *table_pointer(void (*function)()) {
    return reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(function));
}

static void install_vtable() {
    std::memset(vtable, 0, sizeof(vtable));
    vtable[0x30 / sizeof(void *)] = table_pointer(reinterpret_cast<void (*)()>(mock_begin));
    vtable[0x34 / sizeof(void *)] = table_pointer(reinterpret_cast<void (*)()>(mock_finish));
    vtable[0x120 / sizeof(void *)] = table_pointer(reinterpret_cast<void (*)()>(mock_callback));
}

void reset_fixture() {
    result_handle = 77;
    first_result = 91;
    callback_count = begin_count = finish_count = lookup_count = range_call_count = cleanup_count = 0;
    lookup_argument = cleanup_argument = nullptr;
    begin_argument = -1;
    callback_mode = -1;
    mutate_begin_pointer = mutate_callback_state = 0;
    mutate_callback_pointer = 0;
    callback_pointer_value = nullptr;
    range_argument_last = nullptr;
    range_value_last = -1;
    stop_after_callback = 0;
    set_bound_after_callback = -1;
    callback_sequence_last = callback_index_last = callback_handle_last = 0;
    callback_self_last = nullptr;
    install_vtable();
}

void initialize_object(unsigned char *object, short start, short bound) {
    std::memset(object, 0, 0x200);
    active_object = object;
    *reinterpret_cast<void ***>(object) = vtable;
    *reinterpret_cast<void **>(object + 0x20) = reinterpret_cast<void *>(0x1234);
    *reinterpret_cast<void **>(object + 0x88) = reinterpret_cast<void *>(0x5678);
    *reinterpret_cast<short *>(object + 0x124) = start;
    *reinterpret_cast<short *>(object + 0x126) = bound;
    *reinterpret_cast<int *>(object + 0x12C) = 0x3456;
}

extern "C" int func_001ABA00(void *argument) {
    ++lookup_count;
    lookup_argument = argument;
    return result_handle;
}

extern "C" int func_002257A0(void *argument, int value) {
    range_argument_last = argument;
    range_value_last = value;
    ++range_call_count;
    return range_call_count == 1 ? first_result : 0;
}

extern "C" int func_001ABA70(void *argument) {
    ++cleanup_count;
    cleanup_argument = argument;
    return 1;
}
