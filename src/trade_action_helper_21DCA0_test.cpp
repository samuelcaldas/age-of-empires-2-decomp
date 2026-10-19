#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void func_0021DCA0(void *base, int base_idx, int count);
void *func_0021DC50(void *obj, int a1);
}

struct CallRecord {
    void *passed_ptr;
    int passed_idx;
};

static std::vector<CallRecord> dc50_calls;

extern "C" {
// Original branch citation: 0x21DCD0 -> func_0021DC50
// Confirmed: 2-argument call consuming a0 (ptr) and a1 (idx) without touching a2/a3
void *func_0021DC50(void *obj, int a1) {
    CallRecord rec;
    rec.passed_ptr = obj;
    rec.passed_idx = a1;
    dc50_calls.push_back(rec);
    return obj;
}
}

void test_trade_action_helper_21DCA0() {
    // Case 1: Standard iteration with count = 4 (caller 0x224F38 ignores return value; void return)
    dc50_calls.clear();
    char dummy_pool[4096];
    int base_idx = 100;
    int count = 4;

    func_0021DCA0(dummy_pool, base_idx, count);
    assert(dc50_calls.size() == 4);

    for (int i = 0; i < count; ++i) {
        assert(dc50_calls[i].passed_ptr == dummy_pool + (i * 0x400));
        assert(dc50_calls[i].passed_idx == base_idx + i);
    }

    // Mutation test: ensure stride != 0x400 would violate contract
    assert(dc50_calls[1].passed_ptr != dummy_pool + 0x200);

    // Case 2: Zero count (count = 0) -> no iterations
    // Binary trace: jumps to epilogue without writing v0; assert no calls executed
    dc50_calls.clear();
    func_0021DCA0(dummy_pool, base_idx, 0);
    assert(dc50_calls.empty());

    // Case 3: Negative count (count = -5) -> no iterations
    // Binary trace: slt fails, jumps to epilogue without writing v0; assert no calls executed
    dc50_calls.clear();
    func_0021DCA0(dummy_pool, base_idx, -5);
    assert(dc50_calls.empty());

    // Case 4: Single iteration (count = 1)
    dc50_calls.clear();
    func_0021DCA0(dummy_pool, 55, 1);
    assert(dc50_calls.size() == 1);
    assert(dc50_calls[0].passed_ptr == dummy_pool);
    assert(dc50_calls[0].passed_idx == 55);
}

int main() {
    test_trade_action_helper_21DCA0();
    return 0;
}
