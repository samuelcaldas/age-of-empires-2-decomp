#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DE30(void *obj, void *arg1, void *arg2);
}

void test_trade_action_helper_21DE30() {
    void *dummy_obj[4] = {0, 0, 0, 0};
    void *arg_a = (void *)0x1111;
    void *arg_b = (void *)0x2222;

    void *res = func_0021DE30(dummy_obj, arg_a, arg_b);
    assert(res == dummy_obj);
    assert(dummy_obj[0] == arg_a);
    assert(dummy_obj[1] == arg_b);

    void *null_res = func_0021DE30(0, arg_a, arg_b);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DE30();
    return 0;
}
