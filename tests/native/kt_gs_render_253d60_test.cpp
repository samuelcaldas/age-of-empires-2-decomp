#include <cassert>
#include <vector>
#include "kt_gs_render_253d60.h"

int main() {
    std::vector<int> ctx(80, 0);
    ctx[71] = 42;
    func_00253D60(ctx.data());
    assert(ctx[71] == 0);

    // Call with null should not crash
    func_00253D60(nullptr);
    return 0;
}
