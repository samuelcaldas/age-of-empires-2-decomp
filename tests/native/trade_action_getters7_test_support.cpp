#include "trade_action_getters7_test_support.h"

#include <cassert>
#include <cmath>

float last_scaled_val = NAN;
int helper_call_count = 0;
int custom_mock_return = -1;
int last_helper_val = -1;
void *last_mgr_target = nullptr;
int scaler_call_count = 0;
void *p_sentinel = reinterpret_cast<void *>(0x78563412);
void *ctx_sentinel = reinterpret_cast<void *>(0x4E3180);
int mock_mode = 2;
int mock_flag = 0;

extern "C" {
void *D_004E3180 = ctx_sentinel;

/** Return the configured mode after checking the setup pointer. */
int func_00332da0(void *ptr) {
    assert(ptr == p_sentinel);
    return mock_mode;
}

/** Return the configured flag after checking the global context. */
int func_00188070(void *ctx) {
    assert(ctx == ctx_sentinel);
    return mock_flag;
}

/** Record the scaler argument and return the configured integer result. */
int func_00123350(float val) {
    scaler_call_count++;
    last_scaled_val = val;
    if (custom_mock_return != -1) return custom_mock_return;
    return static_cast<int>(val);
}

/** Record the selected tail helper and its receiver without interpreting id. */
int func_002a0b30(void *mgr, int id) {
    helper_call_count++;
    last_mgr_target = mgr;
    return id;
}

/** Record the value-consuming tail helper's receiver and input value. */
int func_0029df60(void *mgr, int val) {
    helper_call_count++;
    last_mgr_target = mgr;
    last_helper_val = val;
    return val;
}
}
