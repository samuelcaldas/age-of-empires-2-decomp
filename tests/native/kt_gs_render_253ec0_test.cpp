#include <cassert>
#include <vector>
#include "kt_gs_render_253ec0.h"

int main() {
    std::vector<int> ctx(20, 0);
    func_00253EC0(ctx.data(), nullptr);
    assert(ctx[0] == 0x4eb2c0);

    func_00253EC0(nullptr, nullptr);
    return 0;
}
