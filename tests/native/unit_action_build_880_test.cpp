#include <cassert>
#include <cstdlib>
#include <cstring>
#include "unit_action_build_880.h"

static int s_query_call_count = 0;
static int s_success_on_step = -1;

static int mock_query(void *target, void *owner, int zero_arg,
                      int one_arg1, int one_arg2, int zero_arg2,
                      int zero_arg3, void *self) {
    (void)target; (void)owner; (void)zero_arg;
    (void)one_arg1; (void)one_arg2; (void)zero_arg2;
    (void)zero_arg3; (void)self;

    int current_call = s_query_call_count++;
    if (current_call == s_success_on_step) {
        return 1;
    }
    return 0;
}

int main() {
    char target_buf[0x120];
    std::memset(target_buf, 0, sizeof(target_buf));

    void *vtbl[20];
    std::memset(vtbl, 0, sizeof(vtbl));
    vtbl[15] = (void *)mock_query;
    *(void ***)(target_buf + 0xA0) = vtbl;

    char self_buf[0x20];
    std::memset(self_buf, 0, sizeof(self_buf));
    *(void **)(self_buf + 0x8) = (void *)0x1234;

    float out_x = 0.0f;
    float out_y = 0.0f;

    // Test 1: success on step 0 (initial coords, step 0 update does nothing)
    s_query_call_count = 0;
    s_success_on_step = 0;
    int res = func_00272880(self_buf, target_buf, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(res == 1);
    assert(s_query_call_count == 1);
    assert(out_x == 10.0f);
    assert(out_y == 20.0f);

    // Test 2: success on step 1 (y -= dy -> 20 - 3 = 17)
    s_query_call_count = 0;
    s_success_on_step = 1;
    res = func_00272880(self_buf, target_buf, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(res == 1);
    assert(s_query_call_count == 2);
    assert(out_x == 10.0f);
    assert(out_y == 17.0f);

    // Test 3: success on step 2 (x += dx -> 10 + 2 = 12)
    s_query_call_count = 0;
    s_success_on_step = 2;
    res = func_00272880(self_buf, target_buf, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(res == 1);
    assert(s_query_call_count == 3);
    assert(out_x == 12.0f);
    assert(out_y == 17.0f);

    // Test 4: success on step 3 (y += dy -> 17 + 3 = 20)
    s_query_call_count = 0;
    s_success_on_step = 3;
    res = func_00272880(self_buf, target_buf, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(res == 1);
    assert(s_query_call_count == 4);
    assert(out_x == 12.0f);
    assert(out_y == 20.0f);

    // Test 5: all queries return 0 -> failure (0)
    s_query_call_count = 0;
    s_success_on_step = -1;
    res = func_00272880(self_buf, target_buf, &out_x, &out_y, 10.0f, 20.0f, 2.0f, 3.0f);
    assert(res == 0);
    assert(s_query_call_count == 4);

    return 0;
}
