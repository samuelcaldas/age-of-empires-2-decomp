#include <cassert>
#include <vector>
#include "kt_gs_render_253f20.h"

int main() {
    std::vector<int> ctx(130, 0);
    ctx[119] = 50;
    func_00253F20(ctx.data());
    assert(ctx[119] == 0);

    func_00253F90(ctx.data());
    assert(ctx[119] == 100);

    func_00253F20(nullptr);
    func_00253F90(nullptr);
    return 0;
}
