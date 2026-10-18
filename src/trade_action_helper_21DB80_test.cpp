#include <cassert>
#include <cstring>
#include <cstdint>

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

static int alloc_calls = 0;
static int setup_calls = 0;
static int tag_calls = 0;
static int reg_calls = 0;
static int finalize_calls = 0;

extern "C" {
void *func_123908(void *) {
    alloc_calls++;
    static char dummy_packet[64];
    return dummy_packet;
}

void *func_104448(void *obj, int a1, int a2, int a3) {
    setup_calls++;
    return obj;
}

void *func_1045E8(void *obj, void *tag) {
    tag_calls++;
    return obj;
}

void *func_1046A8(void *obj, int reg, unsigned long long data) {
    reg_calls++;
    return obj;
}

void *func_104600(void *obj) {
    finalize_calls++;
    return obj;
}
}

void test_trade_action_helper_21DB80() {
    alloc_calls = 0;
    setup_calls = 0;
    tag_calls = 0;
    reg_calls = 0;
    finalize_calls = 0;

    D_00CA158C = 640;
    D_00CA158E = 480;
    D_00392B80[2] = 0x3333;
    D_00392B80[3] = 0x4444;

    short pts[16] = {0,0, 10,0, 10,10, 0,10};
    void *res = func_0021DB80(nullptr, 43, 2, 101, pts, 5, 6, 7, 0);
    assert(res != nullptr);
    assert(alloc_calls == 1);
    assert(setup_calls == 1);
    assert(tag_calls == 1);
    assert(reg_calls >= 5);
    assert(finalize_calls == 1);
}

int main() {
    test_trade_action_helper_21DB80();
    return 0;
}
