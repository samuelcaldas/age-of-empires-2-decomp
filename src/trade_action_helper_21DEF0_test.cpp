#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DEF0(void *obj, void *arg1, void *arg2, void *arg3, void *arg4);
}

void test_trade_action_helper_21DEF0() {
    char dummy_obj[64];
    std::memset(dummy_obj, 0, sizeof(dummy_obj));
    void *res = func_0021DEF0(dummy_obj, dummy_obj, dummy_obj, dummy_obj, dummy_obj);
    assert(res != nullptr);
}

int main() {
    test_trade_action_helper_21DEF0();
    return 0;
}
