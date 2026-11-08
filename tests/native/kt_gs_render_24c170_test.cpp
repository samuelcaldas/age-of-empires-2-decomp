#include <cassert>
#include "kt_gs_render_24c170.h"

int main() {
    KtGsRender24c170Context ctx = {0};
    func_0024C170(&ctx);
    assert(ctx.state == 1);
    return 0;
}
