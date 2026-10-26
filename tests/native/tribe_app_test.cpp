// tests/native/tribe_app_test.cpp
#include <cassert>
#include <cstdio>
#include <cstring>
#include "tribe_app.h"

static int s_rge_app_init_called = 0;
extern "C" void func_184340(void *self, void *cfg, int arg) {
    s_rge_app_init_called++;
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

int main() {
    test_tribe_app_constructor();
    return 0;
}
