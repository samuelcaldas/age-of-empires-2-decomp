#ifdef NDEBUG
#error "Tests require NDEBUG to be undefined so assertions remain active"
#endif

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include "mode_query_tertiary_329130.h"

#define TEST_ASSERT(cond, msg) do { \
    if (!(cond)) { \
        std::fprintf(stderr, "MUTATION_ASSERTION_FAILED: %s\n", msg); \
        std::exit(1); \
    } \
} while(0)

static int s_notify_count = 0;
static int s_notify_val = 0;

static int mock_notify(void *, int val, int) {
    s_notify_count++;
    s_notify_val = val;
    return 1;
}

static void test_early_exits() {
    int res = func_00329130(nullptr, 42, 10);
    TEST_ASSERT(res == -1, "early exit null descriptor failed");

    ModeQueryTertiaryContext ctx;
    std::memset(&ctx, 0, sizeof(ctx));
    ctx.m_active = 0;
    res = func_00329130(&ctx, 42, 10);
    TEST_ASSERT(res == 0, "early exit inactive mode failed");
}

static void test_active_query() {
    ModeQueryTertiaryContext ctx;
    std::memset(&ctx, 0, sizeof(ctx));
    ctx.m_active = 1;

    void *manager_vtable[8] = {
        nullptr, nullptr, nullptr, nullptr,
        nullptr, nullptr, (void *)mock_notify, nullptr
    };
    ctx.m_manager = manager_vtable;

    s_notify_count = 0;
    s_notify_val = 0;

    int res = func_00329130(&ctx, 100, 50);
    TEST_ASSERT(res == 5236, "active query execution failed"); // 100 + 50 + 86 + 5000
    TEST_ASSERT(ctx.m_field_8 == 100, "active query field 8 update failed");
    TEST_ASSERT(ctx.m_field_C == 50, "active query field C update failed");
    TEST_ASSERT(ctx.m_field_18 == 5000, "active query field 18 update failed");
    TEST_ASSERT(s_notify_count == 1, "manager notification call count failed");
    TEST_ASSERT(s_notify_val == 100, "manager notification argument failed");
}

int main(int argc, char **argv) {
    if (argc > 1) {
        if (std::strcmp(argv[1], "early_exits") == 0) { test_early_exits(); return 0; }
        if (std::strcmp(argv[1], "active_query") == 0) { test_active_query(); return 0; }
    }
    test_early_exits();
    test_active_query();
    return 0;
}
