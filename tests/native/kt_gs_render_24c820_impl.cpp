#include "kt_gs_render_24c820.h"

extern "C" void func_0024C820(void* pThis, int flag) {
    if (pThis) {
        auto* ctx = static_cast<KtGsRender24c820Context*>(pThis);
        ctx->state = (flag != 0) ? 1 : 2;
    }
}
