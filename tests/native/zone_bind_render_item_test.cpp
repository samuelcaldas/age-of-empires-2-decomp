#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D17A0(void *self, void *item);

static int g_func_25f2b0_calls = 0;
static int g_func_25dbf0_calls = 0;
static int g_func_25de30_calls = 0;
static char g_dummy_alloc[0x14];

void *func_25F2B0(int size) {
    g_func_25f2b0_calls++;
    assert(size == 0x14);
    return g_dummy_alloc;
}

void func_25DBF0(void *item, void *template_item) {
    g_func_25dbf0_calls++;
}

void func_25DE30(void *item, int flag) {
    g_func_25de30_calls++;
}

int func_1F6DD0(void *camera) {
    return 100;
}

int func_1F6DE0(void *camera) {
    return 200;
}
}

static void reset_test_state() {
    g_func_25f2b0_calls = 0;
    g_func_25dbf0_calls = 0;
    g_func_25de30_calls = 0;
}

static void test_bind_render_item_no_template_src() {
    reset_test_state();
    char zm[0x10000];
    char item[32];
    std::memset(zm, 0, sizeof(zm));
    std::memset(item, 0, sizeof(item));
    item[4] = 2; // slot 2

    char dummy_sub[16];
    *reinterpret_cast<void **>(zm + 0x9114 + 2 * 4) = dummy_sub;
    *reinterpret_cast<void **>(zm + 0x9038) = nullptr;

    func_001D17A0(zm, item);

    assert(*reinterpret_cast<void **>(item + 0x10) == dummy_sub);
}

static void test_bind_render_item_free_list() {
    reset_test_state();
    char zm[0x10000];
    char item[32];
    std::memset(zm, 0, sizeof(zm));
    std::memset(item, 0, sizeof(item));
    item[4] = 1; // slot 1

    char dummy_sub[16];
    void *free_node[2] = { dummy_sub, nullptr };
    int offset = 1 * 4;
    *reinterpret_cast<void **>(zm + offset + 0x90D0) = free_node;
    *reinterpret_cast<void **>(zm + 0x9038) = reinterpret_cast<void *>(0x1);

    func_001D17A0(zm, item);

    assert(*reinterpret_cast<void **>(item + 0x10) == dummy_sub);
    assert(free_node[0] == item);
    assert(*reinterpret_cast<void **>(zm + offset + 0x9048) == free_node); // appended to active
    assert(*reinterpret_cast<void **>(zm + offset + 0x90D0) == nullptr);  // popped from free
}

int main(int argc, char **argv) {
    test_bind_render_item_no_template_src();
    test_bind_render_item_free_list();
    return 0;
}
