#include <assert.h>
#include <stdio.h>
#include "ps2_mouse.h"

void test_cursor_pos_get_set() {
    POINT pt = {0, 0};
    func_002255A0(100, 200);
    func_00225580(&pt);
    assert(pt.x == 100);
    assert(pt.y == 200);

    // Clamping: negative values clamp to 0
    func_002255A0(-50, -100);
    func_00225580(&pt);
    assert(pt.x == 0);
    assert(pt.y == 0);

    // Clamping: overflow clamps to 639 and 479
    func_002255A0(1000, 800);
    func_00225580(&pt);
    assert(pt.x == 639);
    assert(pt.y == 479);

    printf("PASS: test_cursor_pos_get_set\n");
}

int main() {
    test_cursor_pos_get_set();
    return 0;
}
