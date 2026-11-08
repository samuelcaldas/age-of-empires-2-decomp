#include <cassert>
#include <vector>
#include "kt_gs_render_253e80.h"

int main() {
    std::vector<int> ctx(130, 0);
    ctx[119] = 123;
    func_00253E80(ctx.data());
    assert(ctx[119] == 0);

    func_00253E80(nullptr);
    return 0;
}
