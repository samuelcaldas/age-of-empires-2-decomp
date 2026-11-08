#include "kt_gs_render_2460d0.h"
#include <cassert>
#include <vector>

int main() {
    std::vector<unsigned char> buffer(16, 0);
    func_002460D0(buffer.data());
    assert(buffer[0] == 0x30);
    return 0;
}
