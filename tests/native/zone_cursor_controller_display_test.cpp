#include <cassert>
#include "zone_cursor_controller_hide_cursor.h"
#include "zone_cursor_controller_show_cursor.h"
#include "zone_cursor_controller_init_display_res.h"
#include "zone_cursor_controller_reset_global.h"

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

void *D_004E3260 = (void *)0x1234;

static int s_flag_224200 = -1;
static int s_w_2257C0 = -1;
static int s_h_2257C0 = -1;

extern "C" void func_224200(int flag) {
    s_flag_224200 = flag;
}

extern "C" void func_2257C0(int w, int h) {
    s_w_2257C0 = w;
    s_h_2257C0 = h;
}

static void test_cursor_display() {
    func_001DB7C0();
    assert(s_flag_224200 == 0);

    func_001DB7D0();
    assert(s_flag_224200 == 1);

    func_001DB7E0();
    assert(s_w_2257C0 == 0x140);
    assert(s_h_2257C0 == 0xE0);

    assert(D_004E3260 != nullptr);
    func_001DBB80();
    assert(D_004E3260 == nullptr);
}

int main(int argc, char **argv) {
    test_cursor_display();
    return 0;
}
