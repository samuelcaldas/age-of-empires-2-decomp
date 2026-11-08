#include <cassert>
#include "kt_gs_render_24c500.h"

int main() {
    KtGsRender24c500Context ctx = {0};
    func_0024C500(&ctx);
    func_0024C590();
    assert(ctx.state == 1);
    return 0;
}
