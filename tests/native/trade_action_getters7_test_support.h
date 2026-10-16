#ifndef TRADE_ACTION_GETTERS7_TEST_SUPPORT_H
#define TRADE_ACTION_GETTERS7_TEST_SUPPORT_H

extern float last_scaled_val;
extern int helper_call_count;
extern int custom_mock_return;
extern int last_helper_val;
extern void *last_mgr_target;
extern int scaler_call_count;
extern void *p_sentinel;
extern void *ctx_sentinel;
extern int mock_mode;
extern int mock_flag;

extern "C" {
extern void *D_004E3180;
int func_00332da0(void *ptr);
int func_00188070(void *ctx);
int func_00123350(float val);
int func_002a0b30(void *mgr, int id);
int func_0029df60(void *mgr, int val);
void func_002B6220(void *self, int index, int value);
}

#endif
