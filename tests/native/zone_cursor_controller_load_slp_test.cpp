#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdarg>

#define func_11A498 mock_func_11A498
#define func_25F2B0 mock_func_25F2B0
#define func_25D6D0 mock_func_25D6D0
#define func_1DB6A0 mock_func_1DB6A0
#define func_1DB760 mock_func_1DB760
#define func_1DB790 mock_func_1DB790
#define func_224170 mock_func_224170
#define D_004E3248 mock_D_004E3248

static int g_1db6a0_called = 0;
static int g_1db760_called = 0;
static int g_1db790_called = 0;
static int g_224170_called = 0;
static char g_last_path[256];

extern "C" {
void *mock_D_004E3248 = NULL;

int mock_func_11A498(char *buf, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int ret = vsprintf(buf, fmt, args);
    va_end(args);
    return ret;
}

static char dummyRes[0x20];
void *mock_func_25F2B0(int size) {
    return dummyRes;
}

int mock_func_25D6D0(void *res, const char *path, int flags) {
    strcpy(g_last_path, path);
    return 1;
}

int mock_func_1DB6A0(void *self) {
    g_1db6a0_called++;
    return 1;
}

void mock_func_1DB760(void *self, int val) { g_1db760_called++; }
void mock_func_1DB790(void *self, int val) { g_1db790_called++; }
void mock_func_224170() { g_224170_called++; }
}

#include "../../src/zone/zone_cursor_controller_load_slp.cpp"

int main() {
    CursorController ctrl;
    memset(&ctrl, 0, sizeof(ctrl));
    memset(dummyRes, 0, sizeof(dummyRes));

    // Valid case: frame_count = 10, t1 = 5
    SlpRes *res = (SlpRes *)dummyRes;
    res->frame_count = 10;
    res->flags = 0;

    int ret = func_001DB500(&ctrl, 0, 0, "cursor", 1, 5);
    assert(ret == 1);
    assert(strcmp(g_last_path, "cursor.slp") == 0);
    assert(ctrl.f4 == 5);
    assert(ctrl.f0 == 10);
    assert(mock_D_004E3248 == &ctrl);
    assert(g_1db6a0_called == 1);
    assert(g_1db760_called == 1);
    assert(g_1db790_called == 1);
    assert(g_224170_called == 1);

    // Invalid case: flags & 2 != 0
    res->flags = 2;
    ret = func_001DB500(&ctrl, 0, 0, "cursor", 1, 5);
    assert(ret == 0);

    printf("zone_cursor_controller_load_slp_test passed\n");
    return 0;
}
