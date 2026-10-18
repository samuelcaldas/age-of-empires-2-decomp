#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DF50(void *obj, int a1, int a2, int a3, int t0, int t1, int t2, int t3, int arg9 = 0);
void *func_123908(void *arg);
void *func_1046D0(void *obj, int reg, int arg2, int arg3, int t0, int t1, int t2, int t3);
void *func_21C050(void *obj, int mode);
}

struct CallRecord1046D0 {
    void *obj;
    int reg;
    int arg2;
    int arg3;
    int t0;
    int t1;
    int t2;
    int t3;
};

static std::vector<CallRecord1046D0> write_records;
static int alloc_calls = 0;
static int mode_calls = 0;
static int last_mode = 0;
static char mock_packet[64];

extern "C" {
// Original branch citation: 0x21DFA4 -> func_123908
void *func_123908(void *arg) {
    (void)arg;
    alloc_calls++;
    return mock_packet;
}

// Original branch citation: 0x21E044 -> func_1046D0
void *func_1046D0(void *obj, int reg, int arg2, int arg3, int t0, int t1, int t2, int t3) {
    CallRecord1046D0 rec;
    rec.obj = obj;
    rec.reg = reg;
    rec.arg2 = arg2;
    rec.arg3 = arg3;
    rec.t0 = t0;
    rec.t1 = t1;
    rec.t2 = t2;
    rec.t3 = t3;
    write_records.push_back(rec);
    return obj;
}

// Original branch citation: 0x21E04C -> func_21C050
void *func_21C050(void *obj, int mode) {
    mode_calls++;
    last_mode = mode;
    return obj;
}
}

void test_trade_action_helper_21DF50() {
    write_records.clear();
    alloc_calls = 0;
    mode_calls = 0;

    char dummy_obj[32];
    int a1 = 0x1234;
    int mode_a2 = 0x14; // divisor = 0x200 (512)
    int a3 = 0x5678;
    int t0 = 100;
    int t1 = 200;
    int t2 = 300;
    int t3 = 10;
    int arg9 = 20;

    // Expected calculation:
    // prod = (short)t3 * (short)arg9 = 10 * 20 = 200
    // num = (prod << 4) + divisor - 1 = (200 * 16) + 512 - 1 = 3200 + 511 = 3711
    // expected_t1 = 3711 / 512 = 7
    void *res = func_0021DF50(dummy_obj, a1, mode_a2, a3, t0, t1, t2, t3, arg9);
    assert(res == dummy_obj);
    assert(alloc_calls == 0); // non-null obj skips func_123908
    assert(mode_calls == 1);
    assert(last_mode == 0x1234);

    assert(write_records.size() == 1);
    assert(write_records[0].obj == dummy_obj);
    assert(write_records[0].reg == 0x1234);
    assert(write_records[0].arg2 == 0x14);
    assert(write_records[0].arg3 == 0x5678);
    assert(write_records[0].t0 == t0);
    assert(write_records[0].t1 == 7);
    assert(write_records[0].t2 == (short)t1);
    assert(write_records[0].t3 == (short)t2);
}

int main() {
    test_trade_action_helper_21DF50();
    return 0;
}
