#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DB80(void *obj, int a1, int a2, int a3, const short *xy_pts, int t0, int t1, int t2, int t3);
void *func_123908(void *);
void *func_104448(void *obj, int a1, int a2, int a3);
void *func_1045E8(void *obj, void *tag);
void *func_1046A8(void *obj, int reg, unsigned long long data);
void *func_104600(void *obj);

extern unsigned int D_00392B80[4];
extern unsigned short D_00CA158C;
extern unsigned short D_00CA158E;
}

enum CallStep {
    STEP_ALLOC = 1,
    STEP_SETUP,
    STEP_TAG,
    STEP_REG,
    STEP_FINALIZE
};

struct RegRecord {
    int reg;
    uint64_t data;
};

static std::vector<CallStep> call_order;
static std::vector<RegRecord> reg_records;
static int alloc_calls = 0;
static int setup_calls = 0;
static int tag_calls = 0;
static int finalize_calls = 0;

extern "C" {
void *func_123908(void *) {
    alloc_calls++;
    call_order.push_back(STEP_ALLOC);
    static char dummy_packet[64];
    return dummy_packet;
}

void *func_104448(void *obj, int a1, int a2, int a3) {
    setup_calls++;
    call_order.push_back(STEP_SETUP);
    assert(a1 == 0);
    assert(a2 == 0);
    assert(a3 == 0);
    return obj;
}

void *func_1045E8(void *obj, void *tag) {
    tag_calls++;
    call_order.push_back(STEP_TAG);
    assert(tag != 0);
    return obj;
}

void *func_1046A8(void *obj, int reg, unsigned long long data) {
    call_order.push_back(STEP_REG);
    reg_records.push_back({reg, (uint64_t)data});
    return obj;
}

void *func_104600(void *obj) {
    finalize_calls++;
    call_order.push_back(STEP_FINALIZE);
    return obj;
}
}

void test_trade_action_helper_21DB80() {
    call_order.clear();
    reg_records.clear();
    alloc_calls = 0;
    setup_calls = 0;
    tag_calls = 0;
    finalize_calls = 0;

    D_00CA158C = 640;
    D_00CA158E = 480;
    D_00392B80[2] = 0x3333;
    D_00392B80[3] = 0x4444;

    short pts[16] = {0,0, 10,0, 10,10, 0,10};
    void *res = func_0021DB80(0, 43, 2, 101, pts, 5, 6, 7, 0);
    assert(res != 0);
    assert(alloc_calls == 1);
    assert(setup_calls == 1);
    assert(tag_calls == 1);
    assert(finalize_calls == 1);

    assert(call_order.size() >= 7);
    assert(call_order[0] == STEP_ALLOC);
    assert(call_order[1] == STEP_SETUP);
    assert(call_order[2] == STEP_TAG);
    assert(call_order.back() == STEP_FINALIZE);

    bool found_mode_06 = false;
    bool found_param_01 = false;
    int coord_writes = 0;
    for (const auto &rec : reg_records) {
        if (rec.reg == 0x06) {
            found_mode_06 = true;
            assert(rec.data == 43);
        } else if (rec.reg == 0x01) {
            found_param_01 = true;
            assert(rec.data == 101);
        } else if (rec.reg == 0x04) {
            coord_writes++;
            uint32_t z_val = (uint32_t)(rec.data >> 32);
            assert(z_val == 5);
        }
    }
    assert(found_mode_06);
    assert(found_param_01);
    assert(coord_writes == 4);
}

int main() {
    test_trade_action_helper_21DB80();
    return 0;
}
