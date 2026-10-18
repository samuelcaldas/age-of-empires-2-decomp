#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DE90(void *obj, int a1, int a2, int a3, int a4);
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4);
void *func_221B60(void *obj);
void *func_221AC0(void *obj);
}

enum CallType {
    CALL_B60 = 1,
    CALL_DF50,
    CALL_AC0
};

static std::vector<CallType> call_sequence;

extern "C" {
// Original branch citation: 0x21DED8 / 0x21DF14 -> func_221B60
void *func_221B60(void *obj) {
    call_sequence.push_back(CALL_B60);
    return obj;
}

// Original branch citation: 0x21DF1C -> func_221AC0
void *func_221AC0(void *obj) {
    call_sequence.push_back(CALL_AC0);
    return obj;
}

// Original branch citation: 0x21DF0C -> func_0021DF50
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4) {
    call_sequence.push_back(CALL_DF50);
    return obj;
}
}

void test_trade_action_helper_21DE90() {
    call_sequence.clear();
    char dummy[32];

    // Call func_0021DE90 (Original VRAM 0x21DE90)
    void *res = func_0021DE90(dummy, 1, 2, 3, 4);
    assert(res == dummy);

    // Verify exact call order: B60 -> DF50 -> B60 -> AC0
    assert(call_sequence.size() == 4);
    assert(call_sequence[0] == CALL_B60);
    assert(call_sequence[1] == CALL_DF50);
    assert(call_sequence[2] == CALL_B60);
    assert(call_sequence[3] == CALL_AC0);

    // Mutation test: swapping calls (e.g. AC0 before second B60) must fail assertion
    bool swapped = (call_sequence[2] == CALL_AC0);
    assert(!swapped);
}

int main() {
    test_trade_action_helper_21DE90();
    return 0;
}
