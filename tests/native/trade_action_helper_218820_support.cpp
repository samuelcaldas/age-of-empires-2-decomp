#include <cstdint>
#include <cstring>

extern "C" {
void func_00218820(void *self);

struct CallRecord {
    void *receiver;
    uintptr_t arguments[11];
    unsigned int argument_count;
};

int ab8f0_calls = 0;
int acdf0_calls = 0;
int ad940_calls = 0;
int ada70_calls = 0;
int adc00_calls = 0;
int ab9d0_calls = 0;
int return_ab8f0_val = 1;
void *last_manager = nullptr;
void *cleanup_manager = nullptr;
void *g_fixture_self = nullptr;
CallRecord begin_calls[2];
CallRecord handler_calls[2];
CallRecord cleanup_calls[2];
int handler_kinds[2];
int begin_call_count = 0;
int handler_call_count = 0;
int cleanup_call_count = 0;
int mutate_state_on_begin = 0;
int begin_next_state = 0;
int mutate_manager_on_begin = 0;
void *begin_next_manager = nullptr;
int mutate_manager_on_handler = 0;
void *handler_next_manager = nullptr;

static void record_call(CallRecord *records, int &count, void *receiver,
                        const uintptr_t *arguments, unsigned int argument_count) {
    CallRecord *record = &records[count++];
    record->receiver = receiver;
    record->argument_count = argument_count;
    for (unsigned int index = 0; index < argument_count; index++) {
        record->arguments[index] = arguments[index];
    }
}

static uintptr_t pointer_value(void *value) {
    return reinterpret_cast<uintptr_t>(value);
}

static void mutate_object_field(unsigned int offset, void *value) {
    *reinterpret_cast<void **>(static_cast<char *>(g_fixture_self) + offset) = value;
}

static void apply_begin_mutations() {
    if (mutate_state_on_begin) {
        *reinterpret_cast<int *>(static_cast<char *>(g_fixture_self) + 0x1AC) = begin_next_state;
    }
    if (mutate_manager_on_begin) {
        mutate_object_field(0x20, begin_next_manager);
    }
}

static void apply_handler_mutation() {
    if (mutate_manager_on_handler) {
        mutate_object_field(0x20, handler_next_manager);
    }
}

static void record_handler(int kind, const uintptr_t *arguments, unsigned int count) {
    record_call(handler_calls, handler_call_count, reinterpret_cast<void *>(arguments[0]), arguments, count);
    handler_kinds[handler_call_count - 1] = kind;
    apply_handler_mutation();
}

int func_001AB8F0(void *arg0, int arg1) {
    uintptr_t arguments[] = {pointer_value(arg0), static_cast<uintptr_t>(arg1)};
    ab8f0_calls++;
    record_call(begin_calls, begin_call_count, arg0, arguments, 2);
    apply_begin_mutations();
    return return_ab8f0_val;
}

int func_001ACDF0(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5) {
    uintptr_t arguments[] = {pointer_value(arg0), pointer_value(arg1), pointer_value(arg2), static_cast<uintptr_t>(arg3), static_cast<uintptr_t>(arg4), static_cast<uintptr_t>(arg5)};
    acdf0_calls++;
    last_manager = arg0;
    record_handler(0, arguments, 6);
    return 1;
}

int func_001AD940(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6) {
    uintptr_t arguments[] = {pointer_value(arg0), pointer_value(arg1), pointer_value(arg2), static_cast<uintptr_t>(arg3), static_cast<uintptr_t>(arg4), static_cast<uintptr_t>(arg5), static_cast<uintptr_t>(arg6)};
    ad940_calls++;
    last_manager = arg0;
    record_handler(1, arguments, 7);
    return 1;
}

int func_001ADA70(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8) {
    uintptr_t arguments[] = {pointer_value(arg0), pointer_value(arg1), pointer_value(arg2), static_cast<uintptr_t>(arg3), static_cast<uintptr_t>(arg4), static_cast<uintptr_t>(arg5), static_cast<uintptr_t>(arg6), static_cast<uintptr_t>(arg7), static_cast<uintptr_t>(arg8)};
    ada70_calls++;
    last_manager = arg0;
    record_handler(2, arguments, 9);
    return 1;
}

int func_001ADC00(void *arg0, void *arg1, void *arg2, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10) {
    uintptr_t arguments[] = {pointer_value(arg0), pointer_value(arg1), pointer_value(arg2), static_cast<uintptr_t>(arg3), static_cast<uintptr_t>(arg4), static_cast<uintptr_t>(arg5), static_cast<uintptr_t>(arg6), static_cast<uintptr_t>(arg7), static_cast<uintptr_t>(arg8), static_cast<uintptr_t>(arg9), static_cast<uintptr_t>(arg10)};
    adc00_calls++;
    last_manager = arg0;
    record_handler(3, arguments, 11);
    return 1;
}

int func_001AB9D0(void *arg0) {
    uintptr_t arguments[] = {pointer_value(arg0)};
    ab9d0_calls++;
    cleanup_manager = arg0;
    record_call(cleanup_calls, cleanup_call_count, arg0, arguments, 1);
    return 1;
}
}

void reset_mocks() {
    ab8f0_calls = acdf0_calls = ad940_calls = ada70_calls = adc00_calls = ab9d0_calls = 0;
    return_ab8f0_val = 1;
    last_manager = cleanup_manager = g_fixture_self = nullptr;
    begin_call_count = handler_call_count = cleanup_call_count = 0;
    mutate_state_on_begin = mutate_manager_on_begin = mutate_manager_on_handler = 0;
    begin_next_state = 0;
    begin_next_manager = handler_next_manager = nullptr;
    std::memset(begin_calls, 0, sizeof(begin_calls));
    std::memset(handler_calls, 0, sizeof(handler_calls));
    std::memset(cleanup_calls, 0, sizeof(cleanup_calls));
    std::memset(handler_kinds, 0, sizeof(handler_kinds));
}
