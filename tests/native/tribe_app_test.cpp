// tests/native/tribe_app_test.cpp
#include <cassert>
#include <cstdio>
#include <cstring>
#include "tribe_app.h"

static int s_rge_app_init_called = 0;
static int s_rge_app_fail = 0;
static int s_smenu_stream_called = 0;

extern "C" void *func_184340(void *self, void *cfg, int arg) {
    s_rge_app_init_called++;
    if (s_rge_app_fail) {
        return NULL;
    }
    return self;
}

extern "C" int func_00300C90(void) {
    s_smenu_stream_called++;
    return 1;
}

void test_tribe_app_constructor() {
    unsigned char app_buf[0x1948];
    memset(app_buf, 0xAA, sizeof(app_buf));

    void *res = func_2F61F0(app_buf, NULL, 1);
    assert(res == app_buf);
    assert(s_rge_app_init_called == 1);

    // Verify vtable assigned at offset 0
    void **vtable = *(void ***)app_buf;
    assert(vtable != NULL);
    // Method 3 (offset 0xC) MUST point to func_00185230 (not NULL, preventing pc=0)
    assert(vtable[3] == (void *)func_00185230);

    // Verify critical field initialization
    assert(*(int *)(app_buf + 0x142C) == 0);
    assert(*(int *)(app_buf + 0x1430) == -1);
    assert(*(void **)(app_buf + 0x1F0) == (void *)app_buf);

    printf("PASS: test_tribe_app_constructor\n");
}

void test_tribe_app_base_constructor_failure() {
    unsigned char app_buf[0x1948];
    memset(app_buf, 0x55, sizeof(app_buf));

    s_rge_app_fail = 1;
    void *res = func_2F61F0(app_buf, NULL, 0);
    // Must preserve 'this' pointer in return register $v0 even on base failure
    assert(res == app_buf);
    s_rge_app_fail = 0;

    printf("PASS: test_tribe_app_base_constructor_failure\n");
}

void test_event_pump_no_unconditional_smenu() {
    unsigned char app_buf[0x1948];
    memset(app_buf, 0, sizeof(app_buf));
    func_2F61F0(app_buf, NULL, 1);

    // Set field 0x1C = 1 to signal immediate exit without looping
    *(int *)(app_buf + 0x1C) = 1;

    // Verify func_00185230 does not invoke func_00300C90
    s_smenu_stream_called = 0;
    int res = func_00185230(app_buf);
    assert(res == 0);
    assert(s_smenu_stream_called == 0);
    printf("PASS: test_event_pump_no_unconditional_smenu\n");
}

int main() {
    test_tribe_app_constructor();
    test_tribe_app_base_constructor_failure();
    test_event_pump_no_unconditional_smenu();
    return 0;
}
