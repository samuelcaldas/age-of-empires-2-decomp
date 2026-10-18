#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DD10(void *obj, void *arg1, void *arg2, void *arg3, void *arg4);
}

void test_trade_action_helper_21DD10() {
    void *dummy_obj[5] = {0, 0, 0, 0, 0};
    void *arg_a = (void *)0x111;
    void *arg_b = (void *)0x222;
    void *arg_c = (void *)0x333;
    void *arg_d = (void *)0x444;

    void *res = func_0021DD10(dummy_obj, arg_a, arg_b, arg_c, arg_d);
    assert(res == dummy_obj);
    assert(dummy_obj[0] == arg_a);
    assert(dummy_obj[1] == arg_b);
    assert(dummy_obj[2] == arg_c);
    assert(dummy_obj[3] == arg_d);

    void *null_res = func_0021DD10(0, arg_a, arg_b, arg_c, arg_d);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DD10();
    return 0;
}
