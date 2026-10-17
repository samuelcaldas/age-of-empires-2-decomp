#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D2C70(void *self, float min_x, float min_y, float max_x, float max_y);

static int g_func_333500_calls = 0;
static char g_dummy_item[32];

void *func_333500(void *mgr) {
    g_func_333500_calls++;
    return g_dummy_item;
}
}

static void test_query_bounds_flow() {
    g_func_333500_calls = 0;
    char zm[0x100];
    void *res = func_001D2C70(zm, 0.0f, 0.0f, 10.0f, 10.0f);
    assert(g_func_333500_calls == 1);
    assert(res == g_dummy_item);
}

int main(int argc, char **argv) {
    test_query_bounds_flow();
    return 0;
}
