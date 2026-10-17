#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct SpatialViewObj {
    char pad[0xA8];
    void *sub;
};

struct Item {
    char pad0[8];
    void *field_8;
    int field_C;
    int field_10;
};

struct Target {
    char pad[0x20];
    char count;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

static GlobalContext g_ctx;
void *D_004E3180 = &g_ctx;

static Item g_item;
static Target g_target;

extern "C" {
void *func_1FCE60(void *sub) {
    if (!sub) return nullptr;
    return &g_item;
}

void *func_3334A0(void *obj, int id) {
    assert(obj == g_ctx.field_404);
    return &g_target;
}

int func_001D9250(SpatialViewObj *self);
}

static void test_limit_reached() {
    SpatialViewObj view;
    int dummy = 1;
    std::memset(&view, 0, sizeof(view));
    view.sub = &dummy;

    std::memset(&g_item, 0, sizeof(g_item));
    g_item.field_8 = nullptr;
    g_item.field_C = 5;
    g_item.field_10 = 10;

    std::memset(&g_target, 0, sizeof(g_target));
    g_target.count = 11; // limit is count - 1 = 10. 10 >= 10 -> returns 1

    int res = func_001D9250(&view);
    assert(res == 1);
}

static void test_limit_not_reached() {
    SpatialViewObj view;
    int dummy = 1;
    std::memset(&view, 0, sizeof(view));
    view.sub = &dummy;

    std::memset(&g_item, 0, sizeof(g_item));
    g_item.field_8 = nullptr;
    g_item.field_C = 5;
    g_item.field_10 = 8;

    std::memset(&g_target, 0, sizeof(g_target));
    g_target.count = 11; // limit is 10. 8 < 10 -> returns 0

    int res = func_001D9250(&view);
    assert(res == 0);
}

int main(int argc, char **argv) {
    test_limit_reached();
    test_limit_not_reached();
    return 0;
}
