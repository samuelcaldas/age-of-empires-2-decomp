#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D85D0(void *self);

static int g_func_139d50_calls = 0;
static void *g_last_self = nullptr;

void func_139D50(void *self) {
    g_func_139d50_calls++;
    g_last_self = self;
}
}

static void test_action_stub() {
    g_func_139d50_calls = 0;
    void *dummy = reinterpret_cast<void *>(0x12345678);

    func_001D85D0(dummy);
    assert(g_func_139d50_calls == 1);
    assert(g_last_self == dummy);
}

int main(int argc, char **argv) {
    test_action_stub();
    return 0;
}
