#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DE30(void *obj, void *arg1, void *arg2);
}

void test_trade_action_helper_21DE30() {
    char dummy_obj[64];
    std::memset(dummy_obj, 0, sizeof(dummy_obj));
    void *res = func_0021DE30(dummy_obj, dummy_obj, dummy_obj);
    assert(res != nullptr);
}

int main() {
    test_trade_action_helper_21DE30();
    return 0;
}
