#include "kt_gs_render_2456a0.h"
#include <cassert>
#include <vector>

int main() {
    std::vector<unsigned char> buffer(16, 0);
    func_002456A0(buffer.data());
    assert(buffer[0] == 0x60);
    return 0;
}
