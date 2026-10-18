#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4);
void *func_123908(void *);
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);
}

struct RegRecord {
    int reg;
    uint64_t data;
};

static std::vector<RegRecord> reg_records;
static int mode_calls = 0;

extern "C" {
// Original branch citation: 0x21DFA4 -> func_123908
void *func_123908(void *) {
    static char dummy[32];
    return dummy;
}

// Original branch citation: 0x21E044 -> func_1046D0
void *func_1046D0(void *obj, int reg, unsigned long long data) {
    RegRecord rec;
    rec.reg = reg;
    rec.data = (uint64_t)data;
    reg_records.push_back(rec);
    return obj;
}

// Original branch citation: 0x21E04C -> func_21C050
void *func_21C050(void *obj, int mode) {
    mode_calls++;
    return obj;
}
}

void test_trade_action_helper_21DF50() {
    reg_records.clear();
    mode_calls = 0;

    char dummy[32];
    int start_reg = 2;
    int start_val = 20;
    int reg_val_08 = 55;
    int count = 2;

    // Call func_0021DF50 (Original VRAM 0x21DF50)
    void *res = func_0021DF50(dummy, start_reg, start_val, reg_val_08, count);
    assert(res == dummy);
    assert(mode_calls == 1);

    // Verify registers written: loop writes followed by register 0x08 write
    assert(reg_records.size() == (size_t)(count + 1));
    for (int i = 0; i < count; ++i) {
        assert(reg_records[i].reg == start_reg + i);
        assert(reg_records[i].data == (uint64_t)(start_val + i));
    }
    assert(reg_records.back().reg == 0x08);
    assert(reg_records.back().data == (uint64_t)reg_val_08);

    // Mutation test: ensure expecting register 0x04 instead of 0x08 fails assertion
    bool wrong_reg_04 = (reg_records.back().reg == 0x04);
    assert(!wrong_reg_04);
}

int main() {
    test_trade_action_helper_21DF50();
    return 0;
}
