#include <cassert>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001CEA30(void *self, int index, int a2, int a3, int t0);
}

static void test_set_ranges_index0() {
    char mem[0x100];
    std::memset(mem, 0, sizeof(mem));

    func_001CEA30(mem, 0, 10, 20, 30);

    assert(*reinterpret_cast<short *>(mem + 0x18) == 10);
    assert(*reinterpret_cast<short *>(mem + 0x1A) == 20);
    assert(*reinterpret_cast<short *>(mem + 0x1C) == 30);
}

static void test_set_ranges_index_stride() {
    char mem[0x200];
    std::memset(mem, 0, sizeof(mem));

    // Index 5: stride is 6 bytes per entry -> offset 5 * 6 = 30 (0x1E)
    func_001CEA30(mem, 5, 100, 200, 300);

    char *entry = mem + 5 * 6;
    assert(*reinterpret_cast<short *>(entry + 0x18) == 100);
    assert(*reinterpret_cast<short *>(entry + 0x1A) == 200);
    assert(*reinterpret_cast<short *>(entry + 0x1C) == 300);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "stride") {
        test_set_ranges_index_stride();
    } else {
        test_set_ranges_index0();
        test_set_ranges_index_stride();
    }
    return 0;
}
