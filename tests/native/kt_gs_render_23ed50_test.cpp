#include "kt_gs_render_23ed50.h"
#include <cassert>
#include <cstring>
#include <iostream>

int main() {
    u8 buffer[0x100];
    std::memset(buffer, 0, sizeof(buffer));

    func_0023ED50(buffer, 0, 0);
    func_0023EE70();
    std::cout << "kt_gs_render_23ed50 native tests passed." << std::endl;
    return 0;
}
