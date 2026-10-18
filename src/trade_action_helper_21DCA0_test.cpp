#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DCA0(void *obj, void *arg1, void *arg2, void *arg3);
}

void test_trade_action_helper_21DCA0() {
    void *dummy_obj[4] = {0, 0, 0, 0};
    void *arg_a = (void *)0x1234;
    void *arg_b = (void *)0x5678;
    void *arg_c = (void *)0x9ABC;

    void *res = func_0021DCA0(dummy_obj, arg_a, arg_b, arg_c);
    assert(res == dummy_obj);
    assert(dummy_obj[0] == arg_a);
    assert(dummy_obj[1] == arg_b);
    assert(dummy_obj[2] == arg_c);

    void *null_res = func_0021DCA0(0, arg_a, arg_b, arg_c);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DCA0();
    return 0;
}
