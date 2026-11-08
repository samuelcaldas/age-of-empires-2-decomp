#include "kt_gs_render_245b60.h"
#include <cassert>
#include <vector>

int main() {
    std::vector<unsigned char> buffer(16, 0);
    func_00245B60(buffer.data());
    assert(buffer[0] == 0xB4);
    return 0;
}
