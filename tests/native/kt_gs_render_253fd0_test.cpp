#include <cassert>
#include <vector>
#include "kt_gs_render_253fd0.h"

int main() {
    std::vector<int> ctx(80, 0);
    void *res = func_00253FD0(ctx.data());
    assert(res == ctx.data());
    assert(ctx[61] == 1);

    assert(func_00253FD0(nullptr) == nullptr);
    return 0;
}
