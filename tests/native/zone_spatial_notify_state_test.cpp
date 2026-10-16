#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D8410(void *self, void *arg1, void *arg2, int flag);

static int g_func_194d00_calls = 0;
static int g_func_1d8550_calls = 0;

void func_194D00(void *self, void *arg1, void *arg2, int zero) {
    g_func_194d00_calls++;
    assert(zero == 0);
}

void func_1D8550(void *self, void *arg1, void *arg2) {
    g_func_1d8550_calls++;
}
}

static void test_notify_state_flag_zero() {
    g_func_194d00_calls = 0;
    g_func_1d8550_calls = 0;

    func_001D8410(nullptr, nullptr, nullptr, 0);
    assert(g_func_194d00_calls == 1);
    assert(g_func_1d8550_calls == 0);
}

static void test_notify_state_flag_nonzero() {
    g_func_194d00_calls = 0;
    g_func_1d8550_calls = 0;

    func_001D8410(nullptr, nullptr, nullptr, 1);
    assert(g_func_194d00_calls == 1);
    assert(g_func_1d8550_calls == 1);
}

int main(int argc, char **argv) {
    test_notify_state_flag_zero();
    test_notify_state_flag_nonzero();
    return 0;
}
