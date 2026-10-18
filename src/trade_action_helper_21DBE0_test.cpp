#include <cassert>
#include <cstring>
#include <cstdint>

extern "C" {
void *func_0021DBE0(void *obj, int a1, int a2, int a3);
}

void test_trade_action_helper_21DBE0() {
    int dummy_obj[4] = {0, 0, 0, 0};
    void *res = func_0021DBE0(dummy_obj, 100, 200, 300);
    assert(res == dummy_obj);
    assert(dummy_obj[0] == 100);
    assert(dummy_obj[1] == 200);
    assert(dummy_obj[2] == 300);

    void *null_res = func_0021DBE0(0, 1, 2, 3);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DBE0();
    return 0;
}
