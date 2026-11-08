#include <cassert>
#include <vector>
#include "kt_gs_render_254bb0.h"

int main() {
    std::vector<int> ctx(600, 0);
    func_00254BB0(ctx.data());
    assert(ctx[522] == 0x8D);

    func_00254BB0(nullptr);
    return 0;
}
