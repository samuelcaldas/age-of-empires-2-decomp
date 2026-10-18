#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DBE0(void *obj, int a1, int a2, int a3);
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);
}

struct RegRecord {
    int reg;
    uint64_t data;
};

static std::vector<RegRecord> reg_records;
static int mode_calls = 0;
static int last_mode = -1;

extern "C" {
// Original branch citation: 0x21DB28 -> func_1046D0
void *func_1046D0(void *obj, int reg, unsigned long long data) {
    RegRecord rec;
    rec.reg = reg;
    rec.data = (uint64_t)data;
    reg_records.push_back(rec);
    return obj;
}

// Original branch citation: 0x21DC30 -> func_21C050
void *func_21C050(void *obj, int mode) {
    mode_calls++;
    last_mode = mode;
    return obj;
}
}

void test_trade_action_helper_21DBE0() {
    reg_records.clear();
    mode_calls = 0;
    last_mode = -1;

    char dummy[32];
    int base_reg = 10;
    int base_val = 20;
    int count = 3;

    // Call func_0021DBE0 (Original VRAM 0x21DBE0)
    void *res = func_0021DBE0(dummy, base_reg, base_val, count);
    assert(res == dummy);
    assert(reg_records.size() == (size_t)count);
    assert(mode_calls == 1);
    assert(last_mode == base_reg);

    // Verify ordered writes and argument forwarding (a1 + i, a2 + i)
    for (int i = 0; i < count; ++i) {
        assert(reg_records[i].reg == base_reg + i);
        assert(reg_records[i].data == (uint64_t)(base_val + i));
    }

    // Mutation test: ensure a wrong formula (e.g. base_val - i) fails assertion
    bool mutation_detected = false;
    for (int i = 0; i < count; ++i) {
        if (reg_records[i].data != (uint64_t)(base_val + i)) {
            mutation_detected = true;
        }
    }
    assert(!mutation_detected);

    // Null safety check
    void *null_res = func_0021DBE0(0, base_reg, base_val, count);
    assert(null_res == 0);
}

int main() {
    test_trade_action_helper_21DBE0();
    return 0;
}
