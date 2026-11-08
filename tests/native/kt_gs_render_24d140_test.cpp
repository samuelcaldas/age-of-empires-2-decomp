#include <cassert>
#include "kt_gs_render_24d140.h"

int main() {
    KtGsRender24d140Context ctx = {0};
    func_0024D140(&ctx, 42);
    assert(ctx.state == 42);
    return 0;
}
