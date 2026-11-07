#include <cassert>
#include <cstring>
#include "kt_gs_render_23a370.h"

extern "C" void *get_last_deleted();

int main() {
    Struct23A370 obj;
    std::memset(&obj, 0, sizeof(obj));

    // Test func_0023A370 bounds and mapping
    assert(func_0023A370(&obj, -1) == 0);
    assert(func_0023A370(&obj, 9) == 0);
    obj.field_18F0[3] = 4;
    assert(func_0023A370(&obj, 3) == 4);
    obj.field_18F0[3] = 10;
    assert(func_0023A370(&obj, 3) == 0);

    // Test func_0023A400
    char buf[0x300];
    assert(func_0023A400(buf, 2) == buf + 0x210);

    // Test func_0023A410, 450, 490
    obj.field_1930[5] = 123;
    obj.field_1970[5] = 456;
    obj.field_19B0[5] = 789;
    assert(func_0023A410(&obj, 5) == 123);
    assert(func_0023A450(&obj, 5) == 456);
    assert(func_0023A490(&obj, 5) == 789);
    assert(func_0023A410(&obj, 16) == 0);

    // Test func_0023A4D0
    int dummy = 42;
    void *ptr = &dummy;
    func_0023A4D0(&ptr);
    assert(get_last_deleted() == &dummy);

    ptr = nullptr;
    func_0023A4D0(&ptr);
    assert(get_last_deleted() == &dummy); // unchanged

    return 0;
}
