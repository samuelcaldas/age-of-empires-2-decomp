#include <cassert>
#include "kt_gs_render_24c820.h"

int main() {
    KtGsRender24c820Context ctx = {0};
    func_0024C820(&ctx, 1);
    assert(ctx.state == 1);
    func_0024C820(&ctx, 0);
    assert(ctx.state == 2);
    return 0;
}
