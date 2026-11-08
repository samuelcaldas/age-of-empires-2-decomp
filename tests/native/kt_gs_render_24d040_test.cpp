#include <cassert>
#include "kt_gs_render_24d040.h"

int main() {
    KtGsRender24d040Context ctx = {0};
    func_0024D040(&ctx);
    assert(ctx.state == 1);
    return 0;
}
