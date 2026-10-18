#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DF50(void *obj, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5);
}

void test_trade_action_helper_21DF50() {
    void *dummy_obj[6] = {0, 0, 0, 0, 0, 0};
    void *arg_a = (void *)0x121;
    void *arg_b = (void *)0x232;
    void *arg_c = (void *)0x343;
    void *arg_d = (void *)0x454;
    void *arg_e = (void *)0x565;

    void *res = func_0021DF50(dummy_obj, arg_a, arg_b, arg_c, arg_d, arg_e);
    assert(res == dummy_obj);
    assert(dummy_obj[0] == arg_a);
    assert(dummy_obj[1] == arg_b);
    assert(dummy_obj[2] == arg_c);
    assert(dummy_obj[3] == arg_d);
    assert(dummy_obj[4] == arg_e);

    void *null_res = func_0021DF50(0, arg_a, arg_b, arg_c, arg_d, arg_e);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DF50();
    return 0;
}
