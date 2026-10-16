#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

extern "C" {
void func_001D0350(
    void *self, short *out_screen_x, short *out_screen_y,
    int base_x, int base_y, float x, float y, float z
);

int func_123350(float f) {
    return static_cast<int>(std::floor(f + 0.5f));
}
}

static void setup_zm(char *zm, short half_w, short half_h) {
    std::memset(zm, 0, 0x10000);
    *reinterpret_cast<short *>(zm + 0x8EB4) = half_w;
    *reinterpret_cast<short *>(zm + 0x8EB2) = half_h;
}

static void test_subtile_projection_flow() {
    char zm[0x10000];
    setup_zm(zm, 32, 16);

    short out_x = -999, out_y = -999;
    func_001D0350(zm, &out_x, &out_y, 100, 200, 1.0f, 2.0f, 0.5f);

    // sum_xy = 1.0 + 2.0 = 3.0 -> offset_x = round(32 * 3.0) = 96 -> out_x = 100 + 96 = 196
    assert(out_x == 196);
    // diff_term = (1.0 + 2.0 - 1.0) - 0.5 = 1.5 -> offset_y = round(16 * 1.5) = 24 -> out_y = 200 + 24 - 16 = 208
    assert(out_y == 208);
}

static void test_subtile_flat_ground() {
    char zm[0x10000];
    setup_zm(zm, 32, 16);

    short out_x = -999, out_y = -999;
    func_001D0350(zm, &out_x, &out_y, 0, 0, 0.0f, 0.0f, 0.0f);

    // sum_xy = 0 -> offset_x = 0 -> out_x = 0
    assert(out_x == 0);
    // diff_term = 1.0 -> offset_y = round(16 * 1.0) = 16 -> out_y = 0 + 16 - 16 = 0
    assert(out_y == 0);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "flat") {
        test_subtile_flat_ground();
    } else {
        test_subtile_projection_flow();
        test_subtile_flat_ground();
    }
    return 0;
}
