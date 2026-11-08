#include "kt_gs_render_246090.h"
#include <cassert>
#include <vector>

int main() {
    std::vector<unsigned char> buffer(16, 0);
    func_00246090(buffer.data());
    assert(buffer[0] == 0xF0);
    return 0;
}
