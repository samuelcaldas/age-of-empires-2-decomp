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
    void *passed_obj;
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
    rec.passed_obj = obj;
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
    rec.passed_obj = obj;
    call_records.push_back(rec);
    return obj;
}
}

void test_trade_action_helper_21DBE0() {
    // Scenario A: Standard unconditional invocation
    call_records.clear();
    reg_calls = 0;
    mode_calls = 0;

    char dummy[32];
    void *res1 = func_0021DBE0(dummy, 10, 42, 3);
    assert(res1 == dummy);
    assert(reg_calls == 1);
    assert(mode_calls == 1);
    assert(call_records.size() == 2);

    // Verify delay-slot semantics: data passed to func_1046D0 is 0 (cleared by paddub delay slot at 0x21DC2C)
    // Verify retained a1 = 0x1F00 passed to func_21C050 at 0x21DC30
    assert(call_records[0].step == STEP_REG);
    assert(call_records[0].reg_or_mode == 0x1F00);
    assert(call_records[0].data == 0);
    assert(call_records[0].passed_obj == dummy);

    assert(call_records[1].step == STEP_MODE);
    assert(call_records[1].reg_or_mode == 0x1F00);
    assert(call_records[1].passed_obj == dummy);
}

int main() {
    test_trade_action_helper_21DBE0();
    return 0;
}
