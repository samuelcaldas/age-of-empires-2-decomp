#include <cassert>
#include <cstring>
#include "kt_gs_render_23a050.h"

int main() {
    Struct23A050 obj;
    char buffer[64];
    obj.field_1050 = buffer;
    obj.field_1054 = 42;

    // Test func_0023A080 getter
    assert(func_0023A080(&obj) == 42);

    // Test func_0023A050 with non-null string
    func_0023A050(&obj, "Hello, world!");
    assert(strcmp(obj.field_1050, "Hello, world!") == 0);

    // Test func_0023A050 with null string
    func_0023A050(&obj, nullptr);
    assert(obj.field_1050[0] == '\0');

    return 0;
}
