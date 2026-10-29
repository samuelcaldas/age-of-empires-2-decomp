#pragma exceptions off
#include "sub_list.h"

extern "C" {
void *func_00221B60(int type);
int func_0021DF50(void *ctx, int a1, int a2, int a3, void *a4, int a5, int a6, int a7, long long a8);
int func_00221AC0(void);

int func_0021DE90(int a0, int a1, int a2, void *clut_buf, int t0, int t1, int t2, long long t3) {
    void *ctx = func_00221B60(0x0C);
    func_0021DF50(ctx, (short)a0, (short)a1, (short)a2, clut_buf, t0, t1, t2, t3);
    func_00221B60(0x100);
    return func_00221AC0();
}
}
