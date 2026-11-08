#include <cassert>
#include <vector>
#include "kt_gs_render_253dc0.h"

int main() {
    std::vector<int> ctx(80, 0);
    ctx[71] = 99;
    func_00253DC0(ctx.data());
    assert(ctx[71] == 0);

    func_00253E60(ctx.data(), 12345);
    assert(ctx[72] == 12345);

    func_00253DC0(nullptr);
    func_00253E60(nullptr, 0);
    return 0;
}
