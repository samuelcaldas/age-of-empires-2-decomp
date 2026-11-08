#include "kt_gs_render_24c5a0.h"

extern "C" void func_0024C5A0(void* pThis, int flag) {
    if (pThis) {
        auto* ctx = static_cast<KtGsRender24c5a0Context*>(pThis);
        ctx->state = (flag != 0) ? 1 : 2;
    }
}
