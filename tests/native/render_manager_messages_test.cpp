#include <cassert>
#include <cstdlib>
#include <cstring>

static int g_calls = 0;
static int g_last_id = 0;
static char g_dest_at_callback = 'X';

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
    virtual char *GetString(int id, char *dest, int max_len) {
        g_calls++;
        g_last_id = id;
        g_dest_at_callback = dest[0];
        std::strncpy(dest, "msg_resolved", max_len);
        return dest;
    }
};

extern "C" {
char *func_00184ce0(ScreenManager *self, int mode, int msg_id, int a3, char *dest, int max_len);
}

static void test_mode1_table_resolution() {
    ScreenManager mgr;
    char buf[32];
    g_calls = 0;

    std::memset(buf, 'Z', sizeof(buf));
    char *ret = func_00184ce0(&mgr, 1, 3, 0, buf, sizeof(buf));
    assert(ret == buf);
    assert(g_calls == 1);
    assert(g_last_id == 0x7E0);
    assert(g_dest_at_callback == '\0');
    assert(std::strcmp(buf, "msg_resolved") == 0);

    ret = func_00184ce0(&mgr, 1, 7, 0, buf, sizeof(buf));
    assert(ret == buf);
    assert(g_last_id == 0x7D3);

    ret = func_00184ce0(&mgr, 1, 23, 0, buf, sizeof(buf));
    assert(ret == buf);
    assert(g_last_id == 0x7E1);
}

static void test_mode2_and_defaults() {
    ScreenManager mgr;
    char buf[32];
    g_calls = 0;

    std::memset(buf, 'Q', sizeof(buf));
    char *ret = func_00184ce0(&mgr, 2, 0x1234, 0, buf, sizeof(buf));
    assert(ret == buf);
    assert(g_calls == 1);
    assert(g_last_id == 0x1234);
    assert(g_dest_at_callback == '\0');

    std::memset(buf, 'X', sizeof(buf));
    ret = func_00184ce0(&mgr, 1, 99, 0, buf, sizeof(buf));
    assert(ret == buf);
    assert(buf[0] == '\0');
    assert(buf[31] == '\0');

    std::memset(buf, 'Z', sizeof(buf));
    ret = func_00184ce0(&mgr, 0, 1, 0, buf, sizeof(buf));
    assert(ret == buf);
    assert(buf[0] == '\0');
    assert(buf[31] == '\0');
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    int c = std::atoi(argv[1]);
    if (c == 0) test_mode1_table_resolution();
    else if (c == 1) test_mode2_and_defaults();
    else return 1;
    return 0;
}
