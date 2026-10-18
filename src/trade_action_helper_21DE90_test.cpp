#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DE90(void *obj, int a1, int a2, int a3, int a4, int t0 = 0, int t1 = 0, int t2 = 0, int t3 = 0);
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4);
void *func_221B60(void *obj);
void *func_221AC0(void *obj);
}

enum CallType {
    CALL_B60 = 1,
    CALL_DF50,
    CALL_AC0
};

struct StepRecord {
    CallType type;
    void *passed_arg;
    int a1;
    int a2;
    int a3;
    int a4;
};

static std::vector<StepRecord> call_records;
static char mock_allocated_buf[64];

extern "C" {
// Original branch citation: 0x21DED8 / 0x21DF14 -> func_221B60
void *func_221B60(void *obj) {
    StepRecord rec;
    rec.type = CALL_B60;
    rec.passed_arg = obj;
    rec.a1 = 0;
    rec.a2 = 0;
    rec.a3 = 0;
    rec.a4 = 0;
    call_records.push_back(rec);
    return mock_allocated_buf;
}

// Original branch citation: 0x21DF1C -> func_221AC0
void *func_221AC0(void *obj) {
    StepRecord rec;
    rec.type = CALL_AC0;
    rec.passed_arg = obj;
    rec.a1 = 0;
    rec.a2 = 0;
    rec.a3 = 0;
    rec.a4 = 0;
    call_records.push_back(rec);
    return obj;
}

// Original branch citation: 0x21DF0C -> func_0021DF50
void *func_0021DF50(void *obj, int a1, int a2, int a3, int a4) {
    StepRecord rec;
    rec.type = CALL_DF50;
    rec.passed_arg = obj;
    rec.a1 = a1;
    rec.a2 = a2;
    rec.a3 = a3;
    rec.a4 = a4;
    call_records.push_back(rec);
    return obj;
}
}

void test_trade_action_helper_21DE90() {
    // Case 1: Unconditional execution with null input pointer (obj = 0)
    call_records.clear();
    void *res1 = func_0021DE90(0, 1, 2, 3, 4);
    assert(res1 == mock_allocated_buf);

    assert(call_records.size() == 4);
    assert(call_records[0].type == CALL_B60);
    assert(call_records[0].passed_arg == (void *)0xC);

    assert(call_records[1].type == CALL_DF50);
    assert(call_records[1].passed_arg == mock_allocated_buf);
    assert(call_records[1].a1 == 0);
    assert(call_records[1].a2 == 1);
    assert(call_records[1].a3 == 2);
    assert(call_records[1].a4 == 3);

    assert(call_records[2].type == CALL_B60);
    assert(call_records[2].passed_arg == (void *)0x100);

    assert(call_records[3].type == CALL_AC0);
    assert(call_records[3].passed_arg == mock_allocated_buf);

    // Case 2: Sign-extension of short parameters (dsll32 16, dsra32 16)
    // Negative 16-bit values (0xFFFF -> -1)
    call_records.clear();
    void *res2 = func_0021DE90((void *)0x1234FFFF, 0x56788000, 0x00007FFF, 42, 100);
    assert(res2 == mock_allocated_buf);

    assert(call_records.size() == 4);
    assert(call_records[1].type == CALL_DF50);
    assert(call_records[1].a1 == -1);         // 0xFFFF sign-extended to -1
    assert(call_records[1].a2 == -32768);     // 0x8000 sign-extended to -32768
    assert(call_records[1].a3 == 32767);      // 0x7FFF sign-extended to 32767
    assert(call_records[1].a4 == 42);
}

int main() {
    test_trade_action_helper_21DE90();
    return 0;
}
