#include <cassert>
#include <cstdlib>
#include "zone_cursor_controller_set_hover_cursor.h"

struct CursorController {
    int max;
    char pad[0xC];
    int hover_cursor;
};

static void test_valid_hover_cursor() {
    CursorController ctrl;
    ctrl.max = 10;
    ctrl.hover_cursor = -999;

    func_001DB790((::CursorController *)&ctrl, 5);
    assert(ctrl.hover_cursor == 5);
}

static void test_boundary_hover_cursor() {
    CursorController ctrl;
    ctrl.max = 10;
    ctrl.hover_cursor = -999;

    func_001DB790((::CursorController *)&ctrl, 0);
    assert(ctrl.hover_cursor == 0);

    func_001DB790((::CursorController *)&ctrl, 9);
    assert(ctrl.hover_cursor == 9);
}

static void test_invalid_hover_cursor() {
    CursorController ctrl;
    ctrl.max = 10;
    ctrl.hover_cursor = 42;

    // Negative values must be ignored
    func_001DB790((::CursorController *)&ctrl, -1);
    assert(ctrl.hover_cursor == 42);

    func_001DB790((::CursorController *)&ctrl, -100);
    assert(ctrl.hover_cursor == 42);

    // Values >= max must be ignored
    func_001DB790((::CursorController *)&ctrl, 10);
    assert(ctrl.hover_cursor == 42);

    func_001DB790((::CursorController *)&ctrl, 100);
    assert(ctrl.hover_cursor == 42);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_valid_hover_cursor();
        test_boundary_hover_cursor();
        test_invalid_hover_cursor();
        return 0;
    }

    int case_num = std::atoi(argv[1]);
    switch (case_num) {
        case 0:
            test_valid_hover_cursor();
            break;
        case 1:
            test_boundary_hover_cursor();
            break;
        case 2:
            test_invalid_hover_cursor();
            break;
        default:
            return 1;
    }
    return 0;
}
