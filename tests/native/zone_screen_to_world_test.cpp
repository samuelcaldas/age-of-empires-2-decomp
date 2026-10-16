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

static void test_case0_flat() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);
    CmdPacket pkt = {{}, 0}; // case 0: flat
    float out_x = -999.0f, out_y = -999.0f;

    func_001CEA60(zm, 128, 64, &pkt, &out_y, &out_x);

    assert(out_x != -999.0f && out_y != -999.0f);
    assert(!std::isnan(out_x) && !std::isnan(out_y));
}

static void test_case1_and_case5_slopes() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);

    // With screen_x = 20 (fx = 20/64 = 0.3125 <= 0.5), case 1 and case 5 evaluate different branches
    CmdPacket pkt1 = {{}, 1};
    float out_x1 = 0.0f, out_y1 = 0.0f;
    func_001CEA60(zm, 20, 50, &pkt1, &out_y1, &out_x1);
    assert(!std::isnan(out_x1) && !std::isnan(out_y1));

    CmdPacket pkt5 = {{}, 5};
    float out_x5 = 0.0f, out_y5 = 0.0f;
    func_001CEA60(zm, 20, 50, &pkt5, &out_y5, &out_x5);
    assert(!std::isnan(out_x5) && !std::isnan(out_y5));
    // Different slope formulas must produce distinct coordinates
    assert(out_x1 != out_x5 || out_y1 != out_y5);
}

static void test_case9_and_case13_slopes() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);

    CmdPacket pkt9 = {{}, 9};
    float out_x9 = 0.0f, out_y9 = 0.0f;
    func_001CEA60(zm, 80, 40, &pkt9, &out_y9, &out_x9);
    assert(!std::isnan(out_x9) && !std::isnan(out_y9));

    CmdPacket pkt13 = {{}, 13};
    float out_x13 = 0.0f, out_y13 = 0.0f;
    func_001CEA60(zm, 80, 40, &pkt13, &out_y13, &out_x13);
    assert(!std::isnan(out_x13) && !std::isnan(out_y13));
}

static void test_all_17_cases_coverage() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);
    float prev_x = -999.0f, prev_y = -999.0f;
    int distinct_count = 0;

    for (unsigned char c = 0; c <= 16; c++) {
        CmdPacket pkt = {{}, c};
        float ox = 0.0f, oy = 0.0f;
        func_001CEA60(zm, 96, 48, &pkt, &oy, &ox);
        assert(!std::isnan(ox) && !std::isnan(oy));
        if (ox != prev_x || oy != prev_y) {
            distinct_count++;
            prev_x = ox; prev_y = oy;
        }
    }
    // Verifies that across all 17 slope cases, the jump table activates multiple distinct slope outputs
    assert(distinct_count >= 8);
}

static void test_invalid_cmd_skips_output() {
    char zm[0x10000];
    setup_zm(zm, 64, 32);
    CmdPacket pkt = {{}, 25}; // > 16: invalid
    float out_x = -777.0f, out_y = -888.0f;

    func_001CEA60(zm, 128, 64, &pkt, &out_y, &out_x);

    assert(out_x == -777.0f);
    assert(out_y == -888.0f);

    // Also test boundary cmd 17 (first out of range)
    pkt.cmd = 17;
    func_001CEA60(zm, 128, 64, &pkt, &out_y, &out_x);
    assert(out_x == -777.0f);
    assert(out_y == -888.0f);
}

int main(int argc, char **argv) {
    if (argc > 1 && std::string(argv[1]) == "case0_flat") {
        test_case0_flat();
    } else if (argc > 1 && std::string(argv[1]) == "case1_case5") {
        test_case1_and_case5_slopes();
    } else if (argc > 1 && std::string(argv[1]) == "case9_case13") {
        test_case9_and_case13_slopes();
    } else if (argc > 1 && std::string(argv[1]) == "all_cases") {
        test_all_17_cases_coverage();
    } else if (argc > 1 && std::string(argv[1]) == "invalid_cmd") {
        test_invalid_cmd_skips_output();
    } else {
        test_case0_flat();
        test_case1_and_case5_slopes();
        test_case9_and_case13_slopes();
        test_all_17_cases_coverage();
        test_invalid_cmd_skips_output();
    }
    return 0;
}
