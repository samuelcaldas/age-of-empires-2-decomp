#include <cassert>
#include <cstdlib>
#include <cstring>

static int g_calls = 0;
static int g_last_id = 0;

class ScreenManager {
public:
    virtual void M0() {}
    virtual void M1() {}
    virtual void M2() {}
    virtual void M3() {}
    virtual void M4() {}
    virtual void M5() {}
    virtual void M6() {}
    virtual void M7() {}
    virtual void M8() {}
    virtual void M9() {}
    virtual void GetString(int id, char *dest, int max_len) {
        g_calls++;
        g_last_id = id;
        strncpy(dest, "msg_resolved", max_len);
    }
};

extern "C" {
void func_00184ce0(ScreenManager *self, int mode, int msg_id, int a3, char *dest, int max_len);
}

static void test_mode1_table_resolution() {
    ScreenManager mgr;
    char buf[32];
    g_calls = 0;
    func_00184ce0(&mgr, 1, 3, 0, buf, sizeof(buf));
    assert(g_calls == 1);
    assert(g_last_id == 0x7E0);
    assert(strcmp(buf, "msg_resolved") == 0);

    func_00184ce0(&mgr, 1, 7, 0, buf, sizeof(buf));
    assert(g_last_id == 0x7D3);

    func_00184ce0(&mgr, 1, 23, 0, buf, sizeof(buf));
    assert(g_last_id == 0x7E1);
}

static void test_mode2_and_defaults() {
    ScreenManager mgr;
    char buf[32];
    g_calls = 0;
    func_00184ce0(&mgr, 2, 0x1234, 0, buf, sizeof(buf));
    assert(g_calls == 1);
    assert(g_last_id == 0x1234);

    memset(buf, 'X', sizeof(buf));
    func_00184ce0(&mgr, 1, 99, 0, buf, sizeof(buf));
    assert(buf[0] == '\0');
    assert(buf[31] == '\0');

    memset(buf, 'Z', sizeof(buf));
    func_00184ce0(&mgr, 0, 1, 0, buf, sizeof(buf));
    assert(buf[0] == '\0');
    assert(buf[31] == '\0');
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = atoi(argv[1]);
    if (c == 0) test_mode1_table_resolution();
    else if (c == 1) test_mode2_and_defaults();
    else return 1;
    return 0;
}
