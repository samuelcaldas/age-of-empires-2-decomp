#include <cassert>
#include "kt_gs_render_24c5a0.h"

int main() {
    KtGsRender24c5a0Context ctx = {0};
    func_0024C5A0(&ctx, 1);
    assert(ctx.state == 1);
    func_0024C5A0(&ctx, 0);
    assert(ctx.state == 2);
    return 0;
}
