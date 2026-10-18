#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DDC0(void *obj, int a1, int a2, int a3);
}

void test_trade_action_helper_21DDC0() {
    char dummy_obj[64];
    std::memset(dummy_obj, 0, sizeof(dummy_obj));
    void *res = func_0021DDC0(dummy_obj, 1, 2, 3);
    assert(res != nullptr);
}

int main() {
    test_trade_action_helper_21DDC0();
    return 0;
}
