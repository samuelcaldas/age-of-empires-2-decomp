#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DEF0(void *obj, void *arg1, void *arg2, void *arg3, void *arg4);
}

void test_trade_action_helper_21DEF0() {
    void *dummy_obj[5] = {0, 0, 0, 0, 0};
    void *arg_a = (void *)0x1111;
    void *arg_b = (void *)0x2222;
    void *arg_c = (void *)0x3333;
    void *arg_d = (void *)0x4444;

    void *res = func_0021DEF0(dummy_obj, arg_a, arg_b, arg_c, arg_d);
    assert(res == dummy_obj);
    assert(dummy_obj[0] == arg_a);
    assert(dummy_obj[1] == arg_b);
    assert(dummy_obj[2] == arg_c);
    assert(dummy_obj[3] == arg_d);

    void *null_res = func_0021DEF0(0, arg_a, arg_b, arg_c, arg_d);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DEF0();
    return 0;
}
