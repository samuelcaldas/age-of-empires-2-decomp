#include "kt_gs_render_245c70.h"
#include <cassert>
#include <vector>

int main() {
    std::vector<unsigned char> buffer(16, 0);
    func_00245C70(buffer.data());
    assert(buffer[0] == 0x90);
    return 0;
}
