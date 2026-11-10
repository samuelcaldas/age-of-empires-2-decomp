#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void *func_001D4E70(void *self, int p1, int p2, int p3);

static char g_grid_pool[64][64];
static int g_grid_idx = 0;
static int g_free_count = 0;

void *func_100730(int size) {
    assert(g_grid_idx < 64);
    return g_grid_pool[g_grid_idx++];
}

void *func_117CAC(void *dest, int c, int n) {
    return std::memset(dest, c, n);
}

void func_100630(void *ptr) {
    g_free_count++;
}

void func_2E6CD0(void *p) {}
void func_2E6D40(void *p) {}
void func_1D5610(void *self, ...) {}
void func_001D5EB0(void *self, int p) {}
void func_1D66E0(void *self, int p) {}
void func_1D6F10(void *self) {}
void func_1D51B0(void *self, void *res) {}
}

static void test_alloc_grid_flow() {
    g_grid_idx = 0;
    g_free_count = 0;
    char zm[0x200];
    char f94[0x100];
    char levels[8][0x20];
    char *level_ptrs[8];
    for (int i = 0; i < 8; ++i) {
        level_ptrs[i] = levels[i];
    }

    std::memset(zm, 0, sizeof(zm));
    std::memset(f94, 0, sizeof(f94));

    *reinterpret_cast<int *>(zm + 0xE4) = 4; // width 4
    *reinterpret_cast<int *>(zm + 0xE8) = 8; // height 8
    *reinterpret_cast<void **>(zm + 0x94) = f94;

    *reinterpret_cast<short *>(f94 + 0x50) = 4; // 4 levels
    *reinterpret_cast<void **>(f94 + 0x54) = level_ptrs;

    void *res = func_001D4E70(zm, 1, 2, 0);

    // Grid buffers should have been cleaned up and freed
    assert(g_free_count > 0);
    assert(res != nullptr);
}

int main(int argc, char **argv) {
    test_alloc_grid_flow();
    return 0;
}
