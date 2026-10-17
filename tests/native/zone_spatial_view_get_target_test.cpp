#include <cassert>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

struct Item {
    char pad0[8];
    void *field_8;
    int field_C;
};

struct SpatialViewObj {
    char pad[0xA8];
    void *sub;
};

struct GlobalContext {
    char pad[0x404];
    void *field_404;
};

static GlobalContext g_ctx;
void *D_004E3180 = &g_ctx;

static Item g_item;
static int g_target_id = -1;

extern "C" {
void *func_1FCE60(void *sub) {
    if (!sub) return nullptr;
    return &g_item;
}

void *func_3334A0(void *obj, int id) {
    assert(obj == g_ctx.field_404);
    g_target_id = id;
    static int dummy = 999;
    return &dummy;
}

void *func_001D91D0(SpatialViewObj *self);
}

static void test_get_target_null_sub() {
    SpatialViewObj view;
    std::memset(&view, 0, sizeof(view));
    view.sub = nullptr;
    assert(func_001D91D0(&view) == nullptr);
}

static void test_get_target_with_field8() {
    SpatialViewObj view;
    int dummy_sub = 1;
    int dummy_field8 = 42;
    std::memset(&view, 0, sizeof(view));
    view.sub = &dummy_sub;

    std::memset(&g_item, 0, sizeof(g_item));
    g_item.field_8 = &dummy_field8;

    void *res = func_001D91D0(&view);
    assert(res == &dummy_field8);
}

static void test_get_target_with_fieldC() {
    SpatialViewObj view;
    int dummy_sub = 1;
    int dummy_field404 = 77;
    std::memset(&view, 0, sizeof(view));
    view.sub = &dummy_sub;

    g_ctx.field_404 = &dummy_field404;

    std::memset(&g_item, 0, sizeof(g_item));
    g_item.field_8 = nullptr;
    g_item.field_C = 15;

    void *res = func_001D91D0(&view);
    assert(res != nullptr);
    assert(g_target_id == 15);
}

int main(int argc, char **argv) {
    test_get_target_null_sub();
    test_get_target_with_field8();
    test_get_target_with_fieldC();
    return 0;
}
