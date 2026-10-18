#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DC50(void *obj, void *arg1, void *arg2);
}

void test_trade_action_helper_21DC50() {
    void *dummy_obj[4] = {0, 0, 0, 0};
    void *arg_a = (void *)0x5555;
    void *arg_b = (void *)0x6666;

    void *res = func_0021DC50(dummy_obj, arg_a, arg_b);
    assert(res == dummy_obj);
    assert(dummy_obj[0] == arg_a);
    assert(dummy_obj[1] == arg_b);

    void *null_res = func_0021DC50(0, arg_a, arg_b);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DC50();
    return 0;
}
