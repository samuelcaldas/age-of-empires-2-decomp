#include "render_manager_status_test_support.h"
#include <cassert>
#include <cstdarg>
#include <cstdio>

MockStatusCalls g_mock_status{};

namespace {

MockStatusCalls *status_calls() {
    return &g_mock_status;
}

void record_call(StatusCall call) {
    MockStatusCalls *calls = status_calls();
    assert(calls->call_count < 16);
    calls->call_order[calls->call_count] = call;
    calls->call_count++;
}

class MockLanguageManager : public LanguageManager {
public:
    void M0() override {}
    void M1() override {}
    void M2() override {}
    void M3() override {}
    void M4() override {}
    void M5() override {}
    void M6() override {}
    void M7() override {}

    char *GetString(int id, char *dest, int max_len) override {
        record_call(StatusCall::GetString);
        g_mock_status.last_get_string_id = id;
        g_mock_status.last_get_string_dest = dest;
        g_mock_status.last_get_string_max_len = max_len;
        g_mock_status.count_get_string++;
        std::snprintf(dest, max_len, "Str_%X", id);
        char *result = g_mock_status.get_string_return_override;
        if (result == nullptr) {
            result = dest;
        }
        g_mock_status.last_get_string_return = result;
        return result;
    }
};

MockLanguageManager mock_language_manager;

}

extern "C" {

LanguageManager *D_004E3180 = &mock_language_manager;
char D_00568560[32] = {};
const char D_00491BA8[] = "ERROR";

int func_191050(void *self, int a1) {
    record_call(StatusCall::Func191050);
    g_mock_status.last_191050_self = self;
    g_mock_status.last_191050_arg = a1;
    g_mock_status.count_191050++;
    return g_mock_status.func_191050_ret;
}

int func_190FF0(void *self, int a1) {
    record_call(StatusCall::Func190FF0);
    g_mock_status.last_190FF0_self = self;
    g_mock_status.last_190FF0_arg = a1;
    g_mock_status.count_190FF0++;
    return g_mock_status.func_190FF0_ret;
}

int func_11A498(char *dst, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int result = std::vsprintf(dst, fmt, args);
    va_end(args);
    return result;
}

void func_19A1E0(void *p, int a1) {
    record_call(StatusCall::Func19A1E0);
    g_mock_status.last_19a1e0_ptr = p;
    g_mock_status.last_19a1e0_arg = a1;
    g_mock_status.count_19a1e0++;
    if (g_mock_status.field_1600_slot_to_mutate != nullptr) {
        *g_mock_status.field_1600_slot_to_mutate =
            g_mock_status.field_1600_value_after_19a1e0;
    }
}

void func_19A1D0(void *p, int a1) {
    record_call(StatusCall::Func19A1D0);
    g_mock_status.last_19a1d0_ptr = p;
    g_mock_status.last_19a1d0_arg = a1;
    g_mock_status.count_19a1d0++;
}

void func_19A1F0(void *p) {
    record_call(StatusCall::Func19A1F0);
    g_mock_status.last_19a1f0_ptr = p;
    g_mock_status.count_19a1f0++;
}

}

void reset_mock_status() {
    g_mock_status = {};
    D_00568560[0] = '\0';
}

void assert_call_order(std::initializer_list<StatusCall> expected) {
    assert(static_cast<std::size_t>(g_mock_status.call_count) == expected.size());
    int index = 0;
    for (StatusCall call : expected) {
        assert(g_mock_status.call_order[index] == call);
        index++;
    }
}
