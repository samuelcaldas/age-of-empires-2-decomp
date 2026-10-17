#include <cassert>
#include "zone_cursor_controller_set_field_2c.h"
#include "zone_cursor_controller_set_field_30.h"
#include "zone_cursor_controller_get_field_30.h"
#include "zone_cursor_controller_set_bounds.h"
#include "zone_cursor_controller_is_active.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct CursorController {
    char pad[0x1C];
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
    int f30;
};

static void test_cursor_controller_accessors() {
    CursorController ctrl;
    for (int i = 0; i < sizeof(ctrl); i++) ((char *)&ctrl)[i] = 0;

    func_001DB650((::CursorController *)&ctrl, 42);
    assert(ctrl.f2C == 42);

    func_001DB660((::CursorController *)&ctrl, 99);
    assert(ctrl.f30 == 99);
    assert(func_001DB670((::CursorController *)&ctrl) == 99);

    func_001DB680((::CursorController *)&ctrl, 10, 20, 30, 40);
    assert(ctrl.f1C == 10);
    assert(ctrl.f20 == 20);
    assert(ctrl.f24 == 30);
    assert(ctrl.f28 == 40);

    assert(func_001DB6A0((::CursorController *)&ctrl) == 1);
}

int main(int argc, char **argv) {
    test_cursor_controller_accessors();
    return 0;
}
