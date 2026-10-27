#include <cassert>
#include <iostream>
#include <string>

static int c221b60_calls = 0;
static int c21df50_calls = 0;
static int c221ac0_calls = 0;
static void *mock_ctx = (void *)0x7777;

extern "C" {
void *func_00221B60(int type) {
    c221b60_calls++;
    return mock_ctx;
}

int func_0021DF50(void *ctx, int a1, int a2, int a3, int a4, int a5, int a6, int a7, long long a8) {
    c21df50_calls++;
    return 0;
}

int func_00221AC0(void) {
    c221ac0_calls++;
    return 1;
}

int func_0021DE90(int a0, int a1, int a2, void *clut_buf, int t0, int t1, int t2, int t3);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <case_id>\n";
        return 1;
    }

    std::string test_case = argv[1];
    c221b60_calls = 0;
    c21df50_calls = 0;
    c221ac0_calls = 0;

    int clut_data[256];

    if (test_case == "0") {
        // Standard CLUT upload call from palette helper
        int res = func_0021DE90(0x1F00, 0, 4, clut_data, 16, 16, 0, 16);
        assert(c221b60_calls >= 1);
        assert(c21df50_calls == 1);
        assert(c221ac0_calls == 1);
        std::cout << "PASS case 0\n";
        return 0;
    }

    std::cerr << "Unknown case: " << test_case << "\n";
    return 2;
}
