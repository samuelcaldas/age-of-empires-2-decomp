#include <cassert>
#include "kt_gs_render_24c040.h"

int main() {
    KtGsRender24c040Context ctx = {0};
    func_0024C040(&ctx);
    assert(ctx.state == 1);
    return 0;
}
