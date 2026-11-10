#include <cassert>
#include <cstdlib>
#include "zone_cursor_controller_set_normal_cursor.h"

struct CursorController {
    int max;
    char pad[0x8];
    int normal_cursor;
};

static void test_valid_normal_cursor() {
    CursorController ctrl;
    ctrl.max = 10;
    ctrl.normal_cursor = -999;

    func_001DB760((::CursorController *)&ctrl, 3);
    assert(ctrl.normal_cursor == 3);
}

static void test_boundary_normal_cursor() {
    CursorController ctrl;
    ctrl.max = 10;
    ctrl.normal_cursor = -999;

    func_001DB760((::CursorController *)&ctrl, 0);
    assert(ctrl.normal_cursor == 0);

    func_001DB760((::CursorController *)&ctrl, 9);
    assert(ctrl.normal_cursor == 9);
}

static void test_invalid_normal_cursor() {
    CursorController ctrl;
    ctrl.max = 10;
    ctrl.normal_cursor = 42;

    // Negative values must be ignored
    func_001DB760((::CursorController *)&ctrl, -1);
    assert(ctrl.normal_cursor == 42);

    func_001DB760((::CursorController *)&ctrl, -100);
    assert(ctrl.normal_cursor == 42);

    // Values >= max must be ignored
    func_001DB760((::CursorController *)&ctrl, 10);
    assert(ctrl.normal_cursor == 42);

    func_001DB760((::CursorController *)&ctrl, 100);
    assert(ctrl.normal_cursor == 42);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        test_valid_normal_cursor();
        test_boundary_normal_cursor();
        test_invalid_normal_cursor();
        return 0;
    }

    int case_num = std::atoi(argv[1]);
    switch (case_num) {
        case 0:
            test_valid_normal_cursor();
            break;
        case 1:
            test_boundary_normal_cursor();
            break;
        case 2:
            test_invalid_normal_cursor();
            break;
        default:
            return 1;
    }
    return 0;
}
