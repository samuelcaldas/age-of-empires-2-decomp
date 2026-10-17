#include <cassert>
#include <cstddef>
#include <cstring>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D2460(void *self, int level, int x, int y, void *p1, void *p2);

static int g_func_1d29f0_calls = 0;

void func_1D29F0(void *self, int x, int y, void *p1) {
    g_func_1d29f0_calls++;
    *reinterpret_cast<char *>(p1) = 1;
}
}

static void test_process_cell_leaf() {
    g_func_1d29f0_calls = 0;
    char zm[0x200];
    std::memset(zm, 0, sizeof(zm));

    char cell[4] = { 0, 0, 0, 0 };
    void *level0[1] = { cell };
    void **root[1] = { level0 };
    *reinterpret_cast<void ****>(zm + 0) = root;

    *reinterpret_cast<int *>(zm + 0xF4) = 0; // x0
    *reinterpret_cast<int *>(zm + 0xF8) = 0; // y0
    *reinterpret_cast<int *>(zm + 0xFC) = 2; // x1
    *reinterpret_cast<int *>(zm + 0x100) = 2; // y1

    char p1 = 0;
    char p2 = 0;
    func_001D2460(zm, 0, 0, 0, &p1, &p2);

    assert(g_func_1d29f0_calls == 1);
    assert((cell[1] & 0x10) != 0);
}

int main(int argc, char **argv) {
    test_process_cell_leaf();
    return 0;
}
