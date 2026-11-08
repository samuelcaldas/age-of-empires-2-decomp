#include <cassert>
#include <iostream>
#include "kt_gs_render_248200.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00248200(dummy);
    assert(dummy[0] == 0xB0);
    std::cout << "kt_gs_render_248200 native test passed!" << std::endl;
    return 0;
}
