#include <cassert>
#include <iostream>
#include "kt_gs_render_246be0.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00246BE0(dummy);
    assert(dummy[0] == 0xA0);
    std::cout << "kt_gs_render_246be0 native test passed!" << std::endl;
    return 0;
}
