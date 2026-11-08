#include <cassert>
#include <iostream>
#include "kt_gs_render_248c40.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00248C40(dummy);
    assert(dummy[0] == 0xFF);
    std::cout << "kt_gs_render_248c40 native test passed!" << std::endl;
    return 0;
}
