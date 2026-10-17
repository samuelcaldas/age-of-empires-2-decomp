#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D1430(void *self, void *template_source);

static int g_func_25f2b0_calls = 0;
static int g_func_25dbf0_calls = 0;
static char g_alloc_pool[32][0x14];
static int g_pool_idx = 0;

void *func_25F2B0(int size) {
    g_func_25f2b0_calls++;
    assert(size == 0x14);
    assert(g_pool_idx < 32);
    return g_alloc_pool[g_pool_idx++];
}

void func_25DBF0(void *item, void *template_item) {
    g_func_25dbf0_calls++;
}
}

static void reset_test_state() {
    g_func_25f2b0_calls = 0;
    g_func_25dbf0_calls = 0;
    g_pool_idx = 0;
    std::memset(g_alloc_pool, 0, sizeof(g_alloc_pool));
}

static void test_init_render_items_flow() {
    reset_test_state();
    char zm[0x10000];
    std::memset(zm, 0, sizeof(zm));

    char template_src[0x3000];
    std::memset(template_src, 0, sizeof(template_src));
    char dummy_templates[17][16];
    for (int i = 0; i < 17; i++) {
        *reinterpret_cast<void **>(template_src + 0x26F4 + i * 4) = dummy_templates[i];
    }

    func_001D1430(zm, template_src);

    assert(*reinterpret_cast<void **>(zm + 0x9034) == template_src);
    assert(g_func_25f2b0_calls == 17);
    assert(g_func_25dbf0_calls == 17);
    assert(*reinterpret_cast<int *>(zm + 0x9038) == 1);
    assert(*reinterpret_cast<int *>(zm + 0x9040) == 0);

    // Verify all 17 slots populated
    for (int i = 0; i < 17; i++) {
        assert(*reinterpret_cast<void **>(zm + 0x9114 + i * 4) != nullptr);
    }
}

int main(int argc, char **argv) {
    test_init_render_items_flow();
    return 0;
}
