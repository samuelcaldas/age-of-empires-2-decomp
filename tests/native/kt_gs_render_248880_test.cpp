#include <cassert>
#include <iostream>
#include "kt_gs_render_248880.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00248880(dummy);
    assert(dummy[0] == 0xF4);
    func_00248890(dummy);
    assert(dummy[1] == 0xC0);
    std::cout << "kt_gs_render_248880 native test passed!" << std::endl;
    return 0;
}
