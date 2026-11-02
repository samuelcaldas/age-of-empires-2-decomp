#include <cassert>
#include <cstdio>
#include <cstring>

#define func_00263700 mock_func_00263700
#define func_00263760 mock_func_00263760
#define func_002637C0 mock_func_002637C0
#define func_00263A30 mock_func_00263A30
#define func_0026A540 mock_func_0026A540
#define func_00263CC0 mock_func_00263CC0
#define func_00226D90 mock_func_00226D90

extern "C" {
int mock_func_00263700(void *a0, void *a1, void *a2, void *a3) { return 0; }
int mock_func_00263760(void *a0, void *a1, void *a2, void *a3) { return 0; }
void mock_func_002637C0(void *a0) {}
void mock_func_00263A30(void *a0) {}
void mock_func_0026A540(void *a0) {}
void mock_func_00263CC0(void *a0, void *a1) {}
void mock_func_00226D90(void *a0, void *a1, int sz) {}
}

#include "../../src/trade/trade_action_trade_helpers.cpp"

int main() {
    // Tests for func_001519D0:
    // Recognized IDs: 15, 32, and range [7, 10] (7, 8, 9, 10)
    assert(func_001519D0(NULL, 15) == 1);
    assert(func_001519D0(NULL, 32) == 1);
    assert(func_001519D0(NULL, 7) == 1);
    assert(func_001519D0(NULL, 8) == 1);
    assert(func_001519D0(NULL, 9) == 1);
    assert(func_001519D0(NULL, 10) == 1);

    // Other values should return 0
    assert(func_001519D0(NULL, 0) == 0);
    assert(func_001519D0(NULL, 6) == 0);
    assert(func_001519D0(NULL, 11) == 0);
    assert(func_001519D0(NULL, 14) == 0);
    assert(func_001519D0(NULL, 16) == 0);
    assert(func_001519D0(NULL, 31) == 0);
    assert(func_001519D0(NULL, 33) == 0);
    assert(func_001519D0(NULL, -1) == 0);

    // Constant return functions
    assert(func_00151A50() == 0);
    assert(func_00151A60() == -1);

    // Tests for func_00151A10
    {
        char buffer[64];
        std::memset(buffer, 0, sizeof(buffer));
        TradeAction *ta = (TradeAction *)buffer;
        *(unsigned char *)((char *)ta + 44) = 3; // count = 3
        buffer[4] = 10;
        buffer[5] = 20;
        buffer[6] = 30;

        assert(func_00151A10(ta, 20) == 1);
        assert(func_00151A10(ta, 10) == 1);
        assert(func_00151A10(ta, 30) == 1);
        assert(func_00151A10(ta, 40) == 0);
    }

    std::printf("All trade_action_trade_helpers tests passed!\n");
    return 0;
}
