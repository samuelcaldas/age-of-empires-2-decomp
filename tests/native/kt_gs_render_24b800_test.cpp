#include <cassert>
#include "kt_gs_render_24b800.h"

int main() {
    KtGsRender24b800Context ctx = {0};
    func_0024B800(&ctx);
    assert(ctx.state == 1);
    return 0;
}
