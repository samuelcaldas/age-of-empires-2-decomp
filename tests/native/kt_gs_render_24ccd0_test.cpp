#include <cassert>
#include "kt_gs_render_24ccd0.h"

int main() {
    KtGsRender24ccd0Context ctx = {0};
    func_0024CCD0(&ctx, 10, 20);
    assert(ctx.state == 30);
    return 0;
}
