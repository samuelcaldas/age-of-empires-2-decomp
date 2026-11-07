#include <cassert>
#include <vector>
#include "kt_gs_render_23a500.h"

extern "C" int get_23a500_calls();

int main() {
    int dummy = 0;
    func_0023A500(&dummy, nullptr, nullptr, nullptr);
    assert(get_23a500_calls() == 1);
    assert(dummy == 0x12345678);
    return 0;
}
