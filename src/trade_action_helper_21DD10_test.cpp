#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DD10(int a0, int a1, int a2 = 0, int a3 = 0, int a4 = 0);
void *func_123908(void *arg);
void *func_1046D0(void *obj, int reg, int arg2, int arg3, int t0, int t1, int t2, int t3);
void *func_21C050(void *obj, int mode);
}

enum CallStep {
    STEP_ALLOC = 1,
    STEP_PACKET_WRITE,
    STEP_MODE
};

struct PacketWriteRecord {
    void *obj;
    int reg;
    int arg2;
    int arg3;
    int t0;
    int t1;
    int t2;
    int t3;
};

struct GenericStep {
    CallStep step;
    void *passed_obj;
    int mode_or_reg;
};

static std::vector<GenericStep> step_records;
static std::vector<PacketWriteRecord> write_records;
static int alloc_calls = 0;
static int mode_calls = 0;
static char mock_packet[64];

extern "C" {
// Original branch citation: 0x21DD30 -> func_123908
void *func_123908(void *arg) {
    (void)arg;
    alloc_calls++;
    GenericStep step;
    step.step = STEP_ALLOC;
    step.passed_obj = arg;
    step.mode_or_reg = 0;
    step_records.push_back(step);
    return mock_packet;
}

// Original branch citation: 0x21DDB4, 0x21DDE8 -> func_1046D0
void *func_1046D0(void *obj, int reg, int arg2, int arg3, int t0, int t1, int t2, int t3) {
    GenericStep step;
    step.step = STEP_PACKET_WRITE;
    step.passed_obj = obj;
    step.mode_or_reg = reg;
    step_records.push_back(step);

    PacketWriteRecord rec;
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

// Original branch citation: 0x21DDF0 -> func_21C050
void *func_21C050(void *obj, int mode) {
    mode_calls++;
    GenericStep step;
    step.step = STEP_MODE;
    step.passed_obj = obj;
    step.mode_or_reg = mode;
    step_records.push_back(step);
    return obj;
}
}

void test_trade_action_helper_21DD10() {
    // Case 1: Standard bit combination (a0 = 0x1000, a1 = 0x000F)
    step_records.clear();
    write_records.clear();
    alloc_calls = 0;
    mode_calls = 0;

    int test_a0 = 0x1000;
    int test_a1 = 0x000F;

    void *res1 = func_0021DD10(test_a0, test_a1);
    assert(res1 == mock_packet);
    assert(alloc_calls == 1);
    assert(mode_calls == 1);
    assert(write_records.size() == 2);
    assert(step_records.size() == 4);

    assert(step_records[0].step == STEP_ALLOC);
    assert(step_records[1].step == STEP_PACKET_WRITE);
    assert(step_records[2].step == STEP_PACKET_WRITE);
    assert(step_records[3].step == STEP_MODE);
    assert(step_records[3].mode_or_reg == 0x1F00);

    assert(write_records[0].obj == mock_packet);
    assert(write_records[0].reg == 0x1F00);
    assert(write_records[0].arg2 == 0);
    assert(write_records[0].arg3 == 4);
    assert(write_records[0].t1 == 2);

    assert(write_records[1].obj == mock_packet);
    assert(write_records[1].reg == 0x1F00);
    assert(write_records[1].arg2 == 0);
    assert(write_records[1].arg3 == 4);
    assert(write_records[1].t1 == 2);

    assert(write_records[1].t0 == write_records[0].t0 + 0x80);
    assert(write_records[1].t3 == write_records[0].t3 + 1);
    assert(write_records[1].t2 == write_records[0].t2);

    // Case 2: Zero inputs (a0 = 0, a1 = 0)
    step_records.clear();
    write_records.clear();
    alloc_calls = 0;
    mode_calls = 0;

    void *res2 = func_0021DD10(0, 0);
    assert(res2 == mock_packet);
    assert(alloc_calls == 1);
    assert(mode_calls == 1);
    assert(write_records.size() == 2);

    assert(write_records[0].t0 == 0);
    assert(write_records[0].t2 == 0);
    assert(write_records[0].t3 == 0);

    assert(write_records[1].t0 == 0x80);
    assert(write_records[1].t2 == 0);
    assert(write_records[1].t3 == 1);

    // Case 3: High bit input (a0 = 0x200, a1 = 0x1234)
    step_records.clear();
    write_records.clear();
    alloc_calls = 0;
    mode_calls = 0;

    void *res3 = func_0021DD10(0x200, 0x1234);
    assert(res3 == mock_packet);
    assert(alloc_calls == 1);
    assert(mode_calls == 1);
    assert(write_records.size() == 2);

    // a1 = 0x1234 -> a1_masked = 4, bit0 = 0
    // v0_calc = ((4 << 5) >> 1) << 2 = 256 = 0x100
    // v0_combined = 0x100, v0_aligned = 0x100
    // s1_val = 0x200 + 0x100 = 0x300
    // s2_val = ((0x1234 >> 6) << 5) + (0x1234 & 0x10) + 0 = (0x48 << 5) + 0x10 = 0x900 + 0x10 = 0x910
    // s3_val = ((0x1234 >> 1) & 0x10) + 4 = 0x10 + 4 = 0x14
    assert(write_records[0].t0 == 0x300);
    assert(write_records[0].t2 == 0x910);
    assert(write_records[0].t3 == 0x14);

    assert(write_records[1].t0 == 0x300 + 0x80);
    assert(write_records[1].t2 == 0x910);
    assert(write_records[1].t3 == 0x14 + 1);
}

int main() {
    test_trade_action_helper_21DD10();
    return 0;
}
