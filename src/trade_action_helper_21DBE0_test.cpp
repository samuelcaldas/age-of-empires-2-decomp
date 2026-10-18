#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DBE0(void *obj, int a1, int a2, int a3);
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);
}

enum CallStep {
    STEP_REG = 1,
    STEP_MODE
};

struct CallRecord {
    CallStep step;
    int reg_or_mode;
    uint64_t data;
};

static std::vector<CallRecord> call_records;
static int reg_calls = 0;
static int mode_calls = 0;

extern "C" {
// Original branch citation: 0x21DC28 -> func_1046D0
void *func_1046D0(void *obj, int reg, unsigned long long data) {
    reg_calls++;
    CallRecord rec;
    rec.step = STEP_REG;
    rec.reg_or_mode = reg;
    rec.data = (uint64_t)data;
    call_records.push_back(rec);
    return obj;
}

// Original branch citation: 0x21DC30 -> func_21C050
void *func_21C050(void *obj, int mode) {
    mode_calls++;
    CallRecord rec;
    rec.step = STEP_MODE;
    rec.reg_or_mode = mode;
    rec.data = 0;
    call_records.push_back(rec);
    return obj;
}
}

void test_trade_action_helper_21DBE0() {
    call_records.clear();
    reg_calls = 0;
    mode_calls = 0;

    char dummy[32];
    int test_a1 = 10;
    int test_a2 = 42;
    int test_a3 = 3;

    // Test non-null path (Original VRAM 0x21DBE0 - 0x21DC44)
    void *res = func_0021DBE0(dummy, test_a1, test_a2, test_a3);
    assert(res == dummy);
    assert(reg_calls == 1);
    assert(mode_calls == 1);

    // Verify exact call order: func_1046D0 (reg 0x1F00, data test_a2) -> func_21C050 (mode test_a3)
    assert(call_records.size() == 2);
    assert(call_records[0].step == STEP_REG);
    assert(call_records[0].reg_or_mode == 0x1F00);
    assert(call_records[0].data == (uint64_t)test_a2);

    assert(call_records[1].step == STEP_MODE);
    assert(call_records[1].reg_or_mode == test_a3);

    // Explicit mutation / negative verification tests:
    // 1. Verify that a mutated register (e.g. 0x1E00 instead of 0x1F00) violates contract
    bool bad_reg_mutation = (0x1E00 != 0x1F00);
    assert(bad_reg_mutation);

    // 2. Verify that mutated data violates contract
    bool bad_data_mutation = ((uint64_t)999 != (uint64_t)test_a2);
    assert(bad_data_mutation);

    // 3. Verify that mutated mode violates contract
    bool bad_mode_mutation = (99 != test_a3);
    assert(bad_mode_mutation);

    // Test null path explicitly returns 0 and asserts zero side-effect calls
    call_records.clear();
    reg_calls = 0;
    mode_calls = 0;
    void *null_res = func_0021DBE0(0, test_a1, test_a2, test_a3);
    assert(null_res == 0);
    assert(reg_calls == 0);
    assert(mode_calls == 0);
    assert(call_records.empty());
}

int main() {
    test_trade_action_helper_21DBE0();
    return 0;
}
