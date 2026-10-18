#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void *func_0021DC50(void *a0, int a1, int a2 = 0, int a3 = 0);
void *func_123908(void *arg);
void *func_0021DBE0(void *obj, int a1, int a2, int a3);
}

enum CallStep {
    STEP_ALLOC = 1,
    STEP_DBE0
};

struct CallRecord {
    CallStep step;
    void *ptr_param;
    int a1;
    int a2;
};

static std::vector<CallRecord> call_records;
static int alloc_calls = 0;
static int dbe0_calls = 0;
static char mock_allocated_obj[64];

extern "C" {
// Original branch citation: 0x21DC68 -> func_123908
void *func_123908(void *arg) {
    alloc_calls++;
    CallRecord rec;
    rec.step = STEP_ALLOC;
    rec.ptr_param = arg;
    rec.a1 = 0;
    rec.a2 = 0;
    call_records.push_back(rec);
    return mock_allocated_obj;
}

// Original branch citation: 0x21DC78 -> func_0021DBE0
void *func_0021DBE0(void *obj, int a1, int a2, int a3) {
    (void)a3;
    dbe0_calls++;
    CallRecord rec;
    rec.step = STEP_DBE0;
    rec.ptr_param = obj;
    rec.a1 = a1;
    rec.a2 = a2;
    call_records.push_back(rec);
    return obj;
}
}

void test_trade_action_helper_21DC50() {
    // Case 1: Standard unconditional invocation with valid pointer input
    call_records.clear();
    alloc_calls = 0;
    dbe0_calls = 0;

    char dummy_input[32];
    int test_a1 = 0x5678;

    void *res1 = func_0021DC50(dummy_input, test_a1);
    assert(res1 == mock_allocated_obj);
    assert(alloc_calls == 1);
    assert(dbe0_calls == 1);
    assert(call_records.size() == 2);

    // Call 1: func_123908(0)
    assert(call_records[0].step == STEP_ALLOC);
    assert(call_records[0].ptr_param == 0);

    // Call 2: func_0021DBE0(mock_allocated_obj, dummy_input, test_a1)
    assert(call_records[1].step == STEP_DBE0);
    assert(call_records[1].ptr_param == mock_allocated_obj);
    assert(call_records[1].a1 == (int)(uintptr_t)dummy_input);
    assert(call_records[1].a2 == test_a1);

    // Case 2: Null pointer input (a0 = 0)
    // Asserts that func_123908 is STILL called unconditionally and a0 = 0 is forwarded as a1
    call_records.clear();
    alloc_calls = 0;
    dbe0_calls = 0;

    void *res2 = func_0021DC50(0, -42);
    assert(res2 == mock_allocated_obj);
    assert(alloc_calls == 1);
    assert(dbe0_calls == 1);
    assert(call_records.size() == 2);

    assert(call_records[0].step == STEP_ALLOC);
    assert(call_records[0].ptr_param == 0);

    assert(call_records[1].step == STEP_DBE0);
    assert(call_records[1].ptr_param == mock_allocated_obj);
    assert(call_records[1].a1 == 0);
    assert(call_records[1].a2 == -42);

    // Case 3: Boundary values for a1 (0, INT32_MAX)
    call_records.clear();
    alloc_calls = 0;
    dbe0_calls = 0;

    void *res3 = func_0021DC50((void *)0x7FFFFFF0, 0x7FFFFFFF);
    assert(res3 == mock_allocated_obj);
    assert(alloc_calls == 1);
    assert(dbe0_calls == 1);
    assert(call_records.size() == 2);

    assert(call_records[1].a1 == 0x7FFFFFF0);
    assert(call_records[1].a2 == 0x7FFFFFFF);
}

int main() {
    test_trade_action_helper_21DC50();
    return 0;
}
