#include <cassert>
#include <cstring>
#include "render_manager_status.h"

class MockErrorManager : public ErrorManager {
public:
    int last_line;
    char *last_buf;
    int last_size;
    int call_count;

    MockErrorManager() : last_line(0), last_buf(0), last_size(0), call_count(0) {}

    virtual void dummy0() {}
    virtual void dummy1() {}
    virtual void dummy2() {}
    virtual void dummy3() {}
    virtual void dummy4() {}
    virtual void dummy5() {}
    virtual void dummy6() {}
    virtual void dummy7() {}
    virtual void LogError(int line, char *buf, int size) {
        last_line = line;
        last_buf = buf;
        last_size = size;
        ++call_count;
    }
};

static MockErrorManager g_mock_error_mgr;
ErrorManager *D_004E3180 = &g_mock_error_mgr;
char D_568560[32];
const char D_491BA8[] = "ERROR";

static int g_ret_191050 = 0;
static int g_ret_190FF0 = 1;
static int g_calls_11A498 = 0;

extern "C" {

int func_00191050(void *self, int arg1) {
    (void)self;
    (void)arg1;
    return g_ret_191050;
}

int func_00190FF0(void *self, int arg1) {
    (void)self;
    (void)arg1;
    return g_ret_190FF0;
}

int func_11A498(char *dst, const char *fmt, ...) {
    (void)fmt;
    ++g_calls_11A498;
    std::strcpy(dst, "ERROR");
    return 5;
}

}

int main() {
    char manager_buf[0x3000];
    std::memset(manager_buf, 0, sizeof(manager_buf));

    // Test 1: func_00191050 returns 1 -> logs error 1201 and returns D_568560
    g_ret_191050 = 1;
    g_ret_190FF0 = 1;
    g_mock_error_mgr.call_count = 0;
    const char *ret1 = func_00189c80(manager_buf, 0);
    assert(ret1 == D_568560);
    assert(g_mock_error_mgr.call_count == 1);
    assert(g_mock_error_mgr.last_line == 1201);
    assert(g_mock_error_mgr.last_buf == D_568560);
    assert(g_mock_error_mgr.last_size == 32);

    // Test 2: func_00191050 returns 0, func_00190FF0 returns 0 -> logs error 1202
    g_ret_191050 = 0;
    g_ret_190FF0 = 0;
    g_mock_error_mgr.call_count = 0;
    const char *ret2 = func_00189c80(manager_buf, 1);
    assert(ret2 == D_568560);
    assert(g_mock_error_mgr.call_count == 1);
    assert(g_mock_error_mgr.last_line == 1202);

    // Test 3: type < 4 -> logs error 1203
    g_ret_191050 = 0;
    g_ret_190FF0 = 1;
    *reinterpret_cast<int *>(manager_buf + 0x2038 + 2 * 4) = 3; // type = 3 (< 4)
    g_mock_error_mgr.call_count = 0;
    const char *ret3 = func_00189c80(manager_buf, 2);
    assert(ret3 == D_568560);
    assert(g_mock_error_mgr.call_count == 1);
    assert(g_mock_error_mgr.last_line == 1203);

    // Test 4: type >= 4 but type < limit -> logs error 1204
    *reinterpret_cast<int *>(manager_buf + 0x2038 + 3 * 4) = 5; // type = 5
    *reinterpret_cast<unsigned int *>(manager_buf + 0x10C8) = 10; // limit = 10 (type < limit)
    g_mock_error_mgr.call_count = 0;
    const char *ret4 = func_00189c80(manager_buf, 3);
    assert(ret4 == D_568560);
    assert(g_mock_error_mgr.call_count == 1);
    assert(g_mock_error_mgr.last_line == 1204);

    // Test 5: type >= limit -> logs error 1200
    *reinterpret_cast<int *>(manager_buf + 0x2038 + 4 * 4) = 15; // type = 15
    *reinterpret_cast<unsigned int *>(manager_buf + 0x10C8) = 10; // limit = 10 (type >= limit)
    g_mock_error_mgr.call_count = 0;
    const char *ret5 = func_00189c80(manager_buf, 4);
    assert(ret5 == D_568560);
    assert(g_mock_error_mgr.call_count == 1);
    assert(g_mock_error_mgr.last_line == 1200);

    return 0;
}
