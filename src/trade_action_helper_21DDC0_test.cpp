#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DDC0(void *obj, int a1, int a2, int a3);
}

void test_trade_action_helper_21DDC0() {
    int dummy_obj[4] = {0, 0, 0, 0};
    void *res = func_0021DDC0(dummy_obj, 10, 20, 30);
    assert(res == dummy_obj);
    assert(dummy_obj[0] == 10);
    assert(dummy_obj[1] == 20);
    assert(dummy_obj[2] == 30);

    void *null_res = func_0021DDC0(0, 1, 2, 3);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DDC0();
    return 0;
}
