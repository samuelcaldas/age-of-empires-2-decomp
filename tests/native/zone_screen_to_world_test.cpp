#include <cassert>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <string>

static_assert(sizeof(void *) == 4, "native fixture requires 32-bit pointers");

typedef long long int64_t;

static int64_t d2b(double d) { int64_t res; std::memcpy(&res, &d, 8); return res; }
static double b2d(int64_t b) { double res; std::memcpy(&res, &b, 8); return res; }

extern "C" {
void func_001CEA60(
    void *self, int screen_x, int screen_y, void *cmd_pkt, float *out_y, float *out_x
);

int64_t func_122690(int x) { return d2b(static_cast<double>(x)); }
int64_t func_1223C0(int64_t a, int64_t b) { return d2b(b2d(a) / b2d(b)); }
int64_t func_122118(int64_t a, int64_t b) { return d2b(b2d(a) * b2d(b)); }
int64_t func_1220B0(int64_t a, int64_t b) { return d2b(b2d(a) - b2d(b)); }
int64_t func_122058(int64_t a, int64_t b) { return d2b(b2d(a) + b2d(b)); }
int func_100120(int64_t a, int64_t b) { return b2d(a) < b2d(b) ? 1 : 0; }
int func_100170(int64_t a, int64_t b) { return b2d(a) > b2d(b) ? 1 : 0; }
float func_1228E8(int64_t a) { return static_cast<float>(b2d(a)); }
int64_t func_1234E0(float f) { return d2b(static_cast<double>(f)); }
}

struct CmdPacket { char pad[4]; unsigned char cmd; };

static void setup_zm(char *zm, short scale_x, short scale_y) {
    std::memset(zm, 0, 0x10000);
    *reinterpret_cast<short *>(zm + 0x8EAE) = scale_x;
    *reinterpret_cast<short *>(zm + 0x8EB0) = scale_y;
}

static void test_case0_exact_coordinates() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);
    CmdPacket pkt = {{}, 0};

    // fx = 16/64 = 0.25, fy = 16/32 = 0.5 -> exact original formula produces (0.25, 0.25)
    float out_x = -999.0f, out_y = -999.0f;
    func_001CEA60(zm, 16, 16, &pkt, &out_y, &out_x);
    assert(out_x == 0.25f);
    assert(out_y == 0.25f);

    // Dyadic rational non-integer coordinates: (17, 19) -> fx = 17/64 = 0.265625, fy = 19/32 = 0.59375
    // 23/64 = 0.359375f and 11/64 = 0.171875f are exact IEEE 754 dyadic floats
    out_x = -999.0f; out_y = -999.0f;
    func_001CEA60(zm, 17, 19, &pkt, &out_y, &out_x);
    assert(out_x == 0.359375f);
    assert(out_y == 0.171875f);
}

static void test_dual_sided_slope_branches() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);

    // Case 11: condition fx > 0.5
    // Branch 1 (fx <= 0.5): (16, 32) -> fx = 0.25, fy = 1.0 -> s2 = 0.5 -> x = 1.0f, y = -0.5f
    CmdPacket pkt11 = {{}, 11};
    float ox11_a = 0.0f, oy11_a = 0.0f;
    func_001CEA60(zm, 16, 32, &pkt11, &oy11_a, &ox11_a);
    assert(ox11_a == 1.0f);
    assert(oy11_a == -0.5f);

    // Branch 2 (fx > 0.5): (48, 32) -> fx = 0.75, fy = 1.0 -> s2 = 0.0 -> x = 1.25f, y = 0.25f
    float ox11_b = 0.0f, oy11_b = 0.0f;
    func_001CEA60(zm, 48, 32, &pkt11, &oy11_b, &ox11_b);
    assert(ox11_b == 1.25f);
    assert(oy11_b == 0.25f);

    // Case 12: condition fx > 0.5
    // Branch 1 (fx <= 0.5): (16, 32) -> s2 = 0.0 -> x = 0.75f, y = -0.25f
    CmdPacket pkt12 = {{}, 12};
    float ox12_a = 0.0f, oy12_a = 0.0f;
    func_001CEA60(zm, 16, 32, &pkt12, &oy12_a, &ox12_a);
    assert(ox12_a == 0.75f);
    assert(oy12_a == -0.25f);

    // Branch 2 (fx > 0.5): (48, 32) -> s2 = 0.5 -> x = 1.5f, y = 0.0f
    float ox12_b = 0.0f, oy12_b = 0.0f;
    func_001CEA60(zm, 48, 32, &pkt12, &oy12_b, &ox12_b);
    assert(ox12_b == 1.5f);
    assert(oy12_b == 0.0f);

    // Case 10: condition fy < 1.0
    // Branch 1 (fy < 1.0): (32, 16) -> fx = 0.5, fy = 0.5 -> s2 = -0.5 -> x = 0.25f, y = 0.75f
    CmdPacket pkt10 = {{}, 10};
    float ox10_a = 0.0f, oy10_a = 0.0f;
    func_001CEA60(zm, 32, 16, &pkt10, &oy10_a, &ox10_a);
    assert(ox10_a == 0.25f);
    assert(oy10_a == 0.75f);

    // Branch 2 (fy >= 1.0): (32, 48) -> fx = 0.5, fy = 1.5 -> s2 = -1.0 -> x = 1.0f, y = 0.0f
    float ox10_b = 0.0f, oy10_b = 0.0f;
    func_001CEA60(zm, 32, 48, &pkt10, &oy10_b, &ox10_b);
    assert(ox10_a != ox10_b || oy10_a != oy10_b);
    assert(ox10_b == 1.0f);
    assert(oy10_b == 0.0f);
}

static void test_case1_and_case5_slopes() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);

    CmdPacket pkt1 = {{}, 1};
    float out_x1 = 0.0f, out_y1 = 0.0f;
    func_001CEA60(zm, 20, 50, &pkt1, &out_y1, &out_x1);
    assert(out_x1 == 2.75f);
    assert(out_y1 == -2.125f);

    CmdPacket pkt5 = {{}, 5};
    float out_x5 = 0.0f, out_y5 = 0.0f;
    func_001CEA60(zm, 20, 50, &pkt5, &out_y5, &out_x5);
    assert(out_x5 == 3.125f);
    assert(out_y5 == -2.5f);
}

static void test_case9_and_case13_slopes() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);

    CmdPacket pkt9 = {{}, 9};
    float out_x9 = 0.0f, out_y9 = 0.0f;
    func_001CEA60(zm, 96, 48, &pkt9, &out_y9, &out_x9);
    assert(out_x9 == 3.5f);
    assert(out_y9 == -0.5f);

    CmdPacket pkt13 = {{}, 13};
    float out_x13 = 0.0f, out_y13 = 0.0f;
    func_001CEA60(zm, 96, 48, &pkt13, &out_y13, &out_x13);
    assert(out_x13 == 5.0f);
    assert(out_y13 == -2.0f);
}

static void test_all_17_cases_coverage() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);

    // Exact expected coordinates at (96, 48) where fx=1.5, fy=1.5 for all 17 cases
    const float expected_coords[17][2] = {
        {2.5f, 0.5f}, {3.0f, 0.0f}, {1.625f, 1.375f}, {1.875f, 1.125f},
        {2.375f, 0.625f}, {3.0f, 0.0f}, {1.625f, 1.375f}, {5.0f, -2.0f},
        {2.125f, 0.875f}, {3.5f, -0.5f}, {2.0f, 1.0f}, {2.5f, 0.5f},
        {3.5f, -0.5f}, {5.0f, -2.0f}, {2.125f, 0.875f}, {2.125f, 0.875f},
        {4.5f, -1.5f}
    };

    for (unsigned char c = 0; c <= 16; c++) {
        CmdPacket pkt = {{}, c};
        float ox = -999.0f, oy = -999.0f;
        func_001CEA60(zm, 96, 48, &pkt, &oy, &ox);
        assert(ox == expected_coords[c][0]);
        assert(oy == expected_coords[c][1]);
    }
}

static void test_default_cases_17_and_255() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);

    // Command 17 (> 16): original branches to common calculation with selected_term = 0 and writes outputs
    CmdPacket pkt17 = {{}, 17};
    float out_x = -777.0f, out_y = -888.0f;
    func_001CEA60(zm, 16, 16, &pkt17, &out_y, &out_x);

    assert(out_x == 0.25f);
    assert(out_y == 0.25f);

    // Command 255: also branches to common calculation with selected_term = 0 and writes outputs
    CmdPacket pkt255 = {{}, 255};
    out_x = -777.0f; out_y = -888.0f;
    func_001CEA60(zm, 16, 16, &pkt255, &out_y, &out_x);

    assert(out_x == 0.25f);
    assert(out_y == 0.25f);
}

static void test_float_x_rounding_before_y() {
    char zm[0x10000];
    setup_zm(zm, 7, 11);
    CmdPacket pkt = {{}, 0};

    float out_x = 0.0f, out_y = 0.0f;
    func_001CEA60(zm, 5, 9, &pkt, &out_y, &out_x);

    // Verify out_y is computed from the rounded float out_x, not the unrounded double
    double fx = 5.0 / 7.0;
    double fy = 9.0 / 11.0;
    double sum_term = (2.0 * fy - 1.0) + 2.0 * fx;
    double x_fp = sum_term / 2.0;
    float expected_x = static_cast<float>(x_fp);
    float expected_y = static_cast<float>(2.0 * fx - static_cast<double>(expected_x));

    assert(out_x == expected_x);
    assert(out_y == expected_y);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "case0_exact") {
        test_case0_exact_coordinates();
    } else if (argc > 1 && std::string(argv[1]) == "case1_case5") {
        test_case1_and_case5_slopes();
    } else if (argc > 1 && std::string(argv[1]) == "case9_case13") {
        test_case9_and_case13_slopes();
    } else if (argc > 1 && std::string(argv[1]) == "all_cases") {
        test_all_17_cases_coverage();
    } else if (argc > 1 && std::string(argv[1]) == "default_cases") {
        test_default_cases_17_and_255();
    } else if (argc > 1 && std::string(argv[1]) == "float_rounding") {
        test_float_x_rounding_before_y();
    } else if (argc > 1 && std::string(argv[1]) == "dual_sided_slopes") {
        test_dual_sided_slope_branches();
    } else {
        test_case0_exact_coordinates();
        test_case1_and_case5_slopes();
        test_case9_and_case13_slopes();
        test_all_17_cases_coverage();
        test_default_cases_17_and_255();
        test_float_x_rounding_before_y();
        test_dual_sided_slope_branches();
    }
    return 0;
}
