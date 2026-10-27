// tests/native/screen_manager_test.cpp
#include <cassert>
#include <cstdio>
#include <cstring>
#include "screen_manager.h"
#include "overlay_loader.h"

static int s_func_188140_called = 0;
static int s_smenu_load_count = 0;
static int s_multimcd_load_count = 0;

extern "C" int func_188140(void *app) {
    (void)app;
    s_func_188140_called++;
    return 1;
}

extern "C" int func_002240B0(const char *filename, void *dest) {
    (void)dest;
    if (strcmp(filename, "smenu_cd.bin") == 0) {
        s_smenu_load_count++;
    } else if (strcmp(filename, "multimcd.bin") == 0) {
        s_multimcd_load_count++;
    }
    return 1;
}

void test_screen_manager_transitions() {
    unsigned char app_buf[0x1948];
    memset(app_buf, 0, sizeof(app_buf));

    // func_002FD5A0 calls func_188140 and returns 1
    s_func_188140_called = 0;
    int res = func_002FD5A0(app_buf);
    assert(res == 1);
    assert(s_func_188140_called == 1);

    // func_002FD5C0 streams smenu_cd.bin and clears 0x191C/0x1924 arrays
    s_smenu_load_count = 0;
    res = func_002FD5C0(app_buf);
    assert(res == 1);
    assert(s_smenu_load_count == 1);
    for (int i = 0; i < 7; ++i) {
        assert(app_buf[0x191C + i] == 0);
        assert(*(int *)(app_buf + 0x1924 + i * 4) == 0);
    }

    // func_002FC350 delegates to func_002FD5C0
    s_smenu_load_count = 0;
    res = func_002FC350(app_buf);
    assert(res == 1);
    assert(s_smenu_load_count == 1);

    // func_002FC510 calls func_002FD5A0 then func_002FD5C0
    s_func_188140_called = 0;
    s_smenu_load_count = 0;
    res = func_002FC510(app_buf);
    assert(res == 1);
    assert(s_func_188140_called == 1);
    assert(s_smenu_load_count == 1);

    // func_002F8EA0 triggers multimcd.bin load
    s_multimcd_load_count = 0;
    res = func_002F8EA0(app_buf);
    assert(res == 1);
    assert(s_multimcd_load_count == 1);

    printf("PASS: test_screen_manager_transitions\n");
}

int main() {
    test_screen_manager_transitions();
    return 0;
}
