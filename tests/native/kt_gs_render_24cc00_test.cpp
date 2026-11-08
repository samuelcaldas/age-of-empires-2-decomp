#include <cassert>
#include "kt_gs_render_24cc00.h"

int main() {
    KtGsRender24cc00Context ctx = {0};
    func_0024CC00(&ctx);
    assert(ctx.state == 1);
    return 0;
}
