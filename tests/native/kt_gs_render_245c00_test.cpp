#include "kt_gs_render_245c00.h"
#include <cassert>
#include <vector>

int main() {
    std::vector<unsigned char> buffer(16, 0);
    func_00245C00(buffer.data());
    assert(buffer[0] == 0xE0);
    return 0;
}
