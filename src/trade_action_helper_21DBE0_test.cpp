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
    // Scenario A: Standard invocation
    call_records.clear();
    reg_calls = 0;
    mode_calls = 0;

    char dummy[32];
    void *res1 = func_0021DBE0(dummy, 10, 42, 3);
    assert(res1 == dummy);
    assert(reg_calls == 1);
    assert(mode_calls == 1);
    assert(call_records.size() == 2);

    // Strict call order assertion: STEP_REG strictly precedes STEP_MODE
    assert(call_records[0].step == STEP_REG);
    assert(call_records[0].reg_or_mode == 0x1F00);
    assert(call_records[0].data == 42);
    assert(call_records[0].passed_obj == dummy); // Object pointer forwarding verification

    assert(call_records[1].step == STEP_MODE);
    assert(call_records[1].reg_or_mode == 3);
    assert(call_records[1].passed_obj == dummy); // Object pointer forwarding verification

    // Scenario B: Variant argument invocation (verifying argument forwarding behavior)
    call_records.clear();
    reg_calls = 0;
    mode_calls = 0;

    void *res2 = func_0021DBE0(dummy, 20, 100, 7);
    assert(res2 == dummy);
    assert(reg_calls == 1);
    assert(mode_calls == 1);
    assert(call_records.size() == 2);

    assert(call_records[0].step == STEP_REG);
    assert(call_records[0].reg_or_mode == 0x1F00);
    assert(call_records[0].data == 100);
    assert(call_records[0].passed_obj == dummy);

    assert(call_records[1].step == STEP_MODE);
    assert(call_records[1].reg_or_mode == 7);
    assert(call_records[1].passed_obj == dummy);

    // Scenario C: Null pointer safety and side-effect isolation
    call_records.clear();
    reg_calls = 0;
    mode_calls = 0;
    void *null_res = func_0021DBE0(0, 10, 42, 3);
    assert(null_res == 0);
    assert(reg_calls == 0);
    assert(mode_calls == 0);
    assert(call_records.empty());
}

int main() {
    test_trade_action_helper_21DBE0();
    return 0;
}
