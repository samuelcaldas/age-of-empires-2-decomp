#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DD10(void *obj, int a1, int a2, int a3, int a4);
void *func_123908(void *);
void *func_1046D0(void *obj, int reg, unsigned long long data);
void *func_21C050(void *obj, int mode);
}

struct RegRecord {
    int reg;
    uint64_t data;
};

static std::vector<RegRecord> reg_records;
static int alloc_calls = 0;
static int mode_calls = 0;

extern "C" {
// Original branch citation: 0x21DD30 -> func_123908
void *func_123908(void *) {
    alloc_calls++;
    static char dummy[32];
    return dummy;
}

// Original branch citation: 0x21DDB4/0x21DDE8 -> func_1046D0
void *func_1046D0(void *obj, int reg, unsigned long long data) {
    RegRecord rec;
    rec.reg = reg;
    rec.data = (uint64_t)data;
    reg_records.push_back(rec);
    return obj;
}

// Original branch citation: 0x21DDF0 -> func_21C050
void *func_21C050(void *obj, int mode) {
    mode_calls++;
    return obj;
}
}

void test_trade_action_helper_21DD10() {
    reg_records.clear();
    alloc_calls = 0;
    mode_calls = 0;

    char dummy[32];
    int start_reg = 1;
    int start_val = 10;
    int coord_z = 99;
    int count = 2;

    // Call func_0021DD10 (Original VRAM 0x21DD10)
    void *res = func_0021DD10(dummy, start_reg, start_val, coord_z, count);
    assert(res == dummy);
    assert(mode_calls == 1);

    // Verify order of register writes: loop writes (count) followed by register 0x04 coordinate write
    assert(reg_records.size() == (size_t)(count + 1));
    for (int i = 0; i < count; ++i) {
        assert(reg_records[i].reg == start_reg + i);
        assert(reg_records[i].data == (uint64_t)(start_val + i));
    }
    // The last write must be reg 0x04 with coord_z
    assert(reg_records.back().reg == 0x04);
    assert(reg_records.back().data == (uint64_t)coord_z);

    // Mutation test: ensure moving 0x04 write before loop would violate order assertion
    bool order_violated = (reg_records[0].reg == 0x04);
    assert(!order_violated);
}

int main() {
    test_trade_action_helper_21DD10();
    return 0;
}
