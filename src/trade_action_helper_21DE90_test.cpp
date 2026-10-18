#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DE90(void *obj, void *arg1, void *arg2, void *arg3, void *arg4);
}

void test_trade_action_helper_21DE90() {
    void *dummy_obj[5] = {0, 0, 0, 0, 0};
    void *arg_a = (void *)0xaaa;
    void *arg_b = (void *)0xbbb;
    void *arg_c = (void *)0xccc;
    void *arg_d = (void *)0xddd;

    void *res = func_0021DE90(dummy_obj, arg_a, arg_b, arg_c, arg_d);
    assert(res == dummy_obj);
    assert(dummy_obj[0] == arg_a);
    assert(dummy_obj[1] == arg_b);
    assert(dummy_obj[2] == arg_c);
    assert(dummy_obj[3] == arg_d);

    void *null_res = func_0021DE90(0, arg_a, arg_b, arg_c, arg_d);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DE90();
    return 0;
}
