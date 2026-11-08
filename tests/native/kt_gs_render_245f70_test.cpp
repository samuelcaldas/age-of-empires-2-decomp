#include "kt_gs_render_245f70.h"
#include <cassert>
#include <vector>

int main() {
    std::vector<unsigned char> buffer(16, 0);
    func_00245F70(buffer.data());
    assert(buffer[0] == 0x44);
    return 0;
}
