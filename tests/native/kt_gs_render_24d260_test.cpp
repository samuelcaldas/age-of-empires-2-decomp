#include <cassert>
#include "kt_gs_render_24d260.h"

int main() {
    KtGsRender24d260Context ctx = {0};
    func_0024D260(&ctx, 42);
    assert(ctx.state == 42);
    return 0;
}
