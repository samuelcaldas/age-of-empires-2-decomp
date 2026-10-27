#include <assert.h>
#include <stdio.h>
#include "ps2_mouse.h"

struct PostedMsg {
    int msg;
    int wParam;
    int lParam;
};

static PostedMsg s_posted[32];
static int s_num_posted = 0;

static int s_mock_packet_available = 0;
static int s_mock_packet_data[8] = {0};
static unsigned int s_mock_tick = 1000;

extern "C" int func_2263F0(int msg, int wParam, int lParam) {
    if (s_num_posted < 32) {
        s_posted[s_num_posted].msg = msg;
        s_posted[s_num_posted].wParam = wParam;
        s_posted[s_num_posted].lParam = lParam;
        s_num_posted++;
    }
    return 1;
}

extern "C" unsigned int func_2261C0(void) {
    return s_mock_tick;
}

extern "C" int func_00135118(int port, int *out) {
    (void)port;
    if (s_mock_packet_available > 0) {
        if (out) {
            for (int i = 0; i < 8; i++) {
                out[i] = s_mock_packet_data[i];
            }
        }
        s_mock_packet_available--;
        return 1;
    }
    return 0;
}

extern "C" int func_00135258(int port) {
    (void)port;
    return 1;
}

static void reset_posted() {
    s_num_posted = 0;
}

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

void test_mouse_button_dispatch() {
    func_002255A0(150, 250);
    int expected_lparam = (250 << 16) | (150 & 0xFFFF);

    // 1. Pressing LMB posts WM_LBUTTONDOWN with packed coordinates in lParam
    reset_posted();
    func_0036D700_dispatch_buttons(0x01, 0x00, 1000);
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_LBUTTONDOWN);
    assert(s_posted[0].lParam == expected_lparam);

    // 2. Releasing LMB posts WM_LBUTTONUP
    reset_posted();
    func_0036D700_dispatch_buttons(0x00, 0x01, 1100);
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_LBUTTONUP);
    assert(s_posted[0].lParam == expected_lparam);

    // 3. Pressing LMB twice within 250 ms posts WM_LBUTTONDBLCLK
    // First press at tick 2000
    reset_posted();
    func_0036D700_dispatch_buttons(0x01, 0x00, 2000);
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_LBUTTONDOWN);

    // Release at tick 2050
    reset_posted();
    func_0036D700_dispatch_buttons(0x00, 0x01, 2050);
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_LBUTTONUP);

    // Second press at tick 2150 (interval = 150 <= 250 ms) -> DBLCLK
    reset_posted();
    func_0036D700_dispatch_buttons(0x01, 0x00, 2150);
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_LBUTTONDBLCLK);
    assert(s_posted[0].lParam == expected_lparam);

    // 4. Pressing LMB after > 250 ms posts a second WM_LBUTTONDOWN (not a double-click)
    // Release at tick 2200
    reset_posted();
    func_0036D700_dispatch_buttons(0x00, 0x01, 2200);

    // Press at tick 3000 (interval > 250 ms) -> WM_LBUTTONDOWN
    reset_posted();
    func_0036D700_dispatch_buttons(0x01, 0x00, 3000);
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_LBUTTONDOWN);

    // Release at tick 3050
    func_0036D700_dispatch_buttons(0x00, 0x01, 3050);

    // 5. RMB and MMB transitions post matching messages
    reset_posted();
    func_0036D700_dispatch_buttons(0x02, 0x00, 4000); // RMB down
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_RBUTTONDOWN);
    assert(s_posted[0].lParam == expected_lparam);

    reset_posted();
    func_0036D700_dispatch_buttons(0x00, 0x02, 4100); // RMB up
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_RBUTTONUP);

    reset_posted();
    func_0036D700_dispatch_buttons(0x04, 0x00, 5000); // MMB down
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_MBUTTONDOWN);
    assert(s_posted[0].lParam == expected_lparam);

    reset_posted();
    func_0036D700_dispatch_buttons(0x00, 0x04, 5100); // MMB up
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_MBUTTONUP);

    printf("PASS: test_mouse_button_dispatch\n");
}

void test_relative_motion_accumulator() {
    func_002255A0(100, 100);
    reset_posted();

    // Send relative packet (dX = 25, dY = 30)
    s_mock_packet_available = 1;
    s_mock_packet_data[0] = 0;   // buttons
    s_mock_packet_data[1] = 25;  // dX
    s_mock_packet_data[2] = 30;  // dY
    s_mock_packet_data[3] = 0;   // wheel

    int res = func_0036D700();
    assert(res == 1);
    assert(g_cursor_x == 125);
    assert(g_cursor_y == 130);
    assert(s_num_posted >= 1);
    assert(s_posted[0].msg == WM_MOUSEMOVE);
    assert(s_posted[0].lParam == ((130 << 16) | 125));

    // Clamping to 0: negative delta
    reset_posted();
    s_mock_packet_available = 1;
    s_mock_packet_data[0] = 0;
    s_mock_packet_data[1] = -500;
    s_mock_packet_data[2] = -500;
    s_mock_packet_data[3] = 0;

    func_0036D700();
    assert(g_cursor_x == 0);
    assert(g_cursor_y == 0);
    assert(s_posted[0].msg == WM_MOUSEMOVE);
    assert(s_posted[0].lParam == 0);

    // Clamping to (639, 479): overflow delta
    reset_posted();
    s_mock_packet_available = 1;
    s_mock_packet_data[0] = 0;
    s_mock_packet_data[1] = 1000;
    s_mock_packet_data[2] = 1000;
    s_mock_packet_data[3] = 0;

    func_0036D700();
    assert(g_cursor_x == 639);
    assert(g_cursor_y == 479);
    assert(s_posted[0].msg == WM_MOUSEMOVE);
    assert(s_posted[0].lParam == ((479 << 16) | 639));

    printf("PASS: test_relative_motion_accumulator\n");
}

void test_absolute_mouse_mode() {
    Mouse_SetMode(MOUSE_MODE_ABSOLUTE);
    assert(Mouse_GetMode() == MOUSE_MODE_ABSOLUTE);

    reset_posted();
    Mouse_SetAbsolutePosition(320, 240, 0x01); // LMB at center screen
    assert(g_cursor_x == 320);
    assert(g_cursor_y == 240);
    assert(s_num_posted >= 1);
    assert(s_posted[s_num_posted - 1].msg == WM_LBUTTONDOWN);
    assert(s_posted[s_num_posted - 1].lParam == ((240 << 16) | 320));

    // When in absolute mode, func_0036D700 ignores relative dX, dY packets
    reset_posted();
    s_mock_packet_available = 1;
    s_mock_packet_data[0] = 0x01;
    s_mock_packet_data[1] = 50;
    s_mock_packet_data[2] = 50;
    s_mock_packet_data[3] = 0;
    func_0036D700();
    assert(g_cursor_x == 320); // Position unchanged by relative packet
    assert(g_cursor_y == 240);

    // Return to relative mode
    Mouse_SetMode(MOUSE_MODE_RELATIVE);
    s_mock_packet_available = 1;
    s_mock_packet_data[0] = 0x01;
    s_mock_packet_data[1] = 50;
    s_mock_packet_data[2] = 50;
    s_mock_packet_data[3] = 0;
    func_0036D700();
    assert(g_cursor_x == 370); // Accumulated
    assert(g_cursor_y == 290);

    printf("PASS: test_absolute_mouse_mode\n");
}

void test_double_click_requires_same_position() {
    func_002255A0(100, 100);
    reset_posted();

    // First press at (100, 100)
    func_0036D700_dispatch_buttons(0x01, 0x00, 10000);
    assert(s_posted[0].msg == WM_LBUTTONDOWN);

    // Release at (100, 100)
    func_0036D700_dispatch_buttons(0x00, 0x01, 10050);

    // Move cursor to (200, 200)
    func_002255A0(200, 200);

    // Second press at (200, 200) within 100 ms -> should NOT be double click
    reset_posted();
    func_0036D700_dispatch_buttons(0x01, 0x00, 10100);
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_LBUTTONDOWN); // NOT WM_LBUTTONDBLCLK!

    printf("PASS: test_double_click_requires_same_position\n");
}

void test_double_click_at_tick_zero() {
    func_002255A0(100, 100);
    reset_posted();

    // First click at tick 0
    func_0036D700_dispatch_buttons(0x01, 0x00, 0);
    assert(s_posted[0].msg == WM_LBUTTONDOWN);

    func_0036D700_dispatch_buttons(0x00, 0x01, 50);

    // Second click at tick 100 (within 250 ms of tick 0) -> DBLCLK
    reset_posted();
    func_0036D700_dispatch_buttons(0x01, 0x00, 100);
    assert(s_num_posted == 1);
    assert(s_posted[0].msg == WM_LBUTTONDBLCLK);

    printf("PASS: test_double_click_at_tick_zero\n");
}

void test_extreme_delta_clamping() {
    func_002255A0(100, 100);
    reset_posted();

    s_mock_packet_available = 1;
    s_mock_packet_data[0] = 0;
    s_mock_packet_data[1] = 0x7FFFFFFF;
    s_mock_packet_data[2] = 0x7FFFFFFF;
    s_mock_packet_data[3] = 0;

    func_0036D700();
    assert(g_cursor_x == 639);
    assert(g_cursor_y == 479);

    printf("PASS: test_extreme_delta_clamping\n");
}

void test_negative_wheel_delta() {
    func_002255A0(100, 100);
    reset_posted();

    s_mock_packet_available = 1;
    s_mock_packet_data[0] = 0;
    s_mock_packet_data[1] = 0;
    s_mock_packet_data[2] = 0;
    s_mock_packet_data[3] = -2;

    func_0036D700();
    assert(s_num_posted >= 1);
    assert(s_posted[0].msg == WM_MOUSEWHEEL);
    short wheel_delta = (short)((s_posted[0].wParam >> 16) & 0xFFFF);
    assert(wheel_delta == -2);

    printf("PASS: test_negative_wheel_delta\n");
}

int main() {
    test_cursor_pos_get_set();
    test_mouse_button_dispatch();
    test_relative_motion_accumulator();
    test_absolute_mouse_mode();
    test_double_click_requires_same_position();
    test_double_click_at_tick_zero();
    test_extreme_delta_clamping();
    test_negative_wheel_delta();
    return 0;
}
