#include <cassert>
#include <iostream>
#include "kt_gs_render_247190.h"

int main() {
    unsigned char dummy[64] = {0};
    func_00247190(dummy);
    assert(dummy[0] == 0x90);
    std::cout << "kt_gs_render_247190 native test passed!" << std::endl;
    return 0;
}
