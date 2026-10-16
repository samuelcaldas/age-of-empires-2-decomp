#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D8370(void *self, void *arg1, void *arg2, int flag, float x, float y, float z);

static int g_func_194c60_calls = 0;
static int g_func_1d8520_calls = 0;

void func_194C60(void *self, void *arg1, void *arg2, int zero, float x, float y, float z) {
    g_func_194c60_calls++;
    assert(zero == 0);
    assert(x == 1.5f);
    assert(y == 2.5f);
    assert(z == 3.5f);
}

void func_1D8520(void *self, void *arg1, void *arg2, float x, float y, float z) {
    g_func_1d8520_calls++;
    assert(x == 1.5f);
    assert(y == 2.5f);
    assert(z == 3.5f);
}
}

static void test_notify_pos_flag_zero() {
    g_func_194c60_calls = 0;
    g_func_1d8520_calls = 0;

    func_001D8370(nullptr, nullptr, nullptr, 0, 1.5f, 2.5f, 3.5f);
    assert(g_func_194c60_calls == 1);
    assert(g_func_1d8520_calls == 0);
}

static void test_notify_pos_flag_nonzero() {
    g_func_194c60_calls = 0;
    g_func_1d8520_calls = 0;

    func_001D8370(nullptr, nullptr, nullptr, 1, 1.5f, 2.5f, 3.5f);
    assert(g_func_194c60_calls == 1);
    assert(g_func_1d8520_calls == 1);
}

int main(int argc, char **argv) {
    test_notify_pos_flag_zero();
    test_notify_pos_flag_nonzero();
    return 0;
}
