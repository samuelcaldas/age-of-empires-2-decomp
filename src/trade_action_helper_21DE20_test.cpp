#include <cassert>
#include <cstring>
#include <cstdint>
#include <vector>

extern "C" {
void func_0021DE20(void *base, int base_idx, int count);
void *func_0021DD10(void *obj, int a1);
}

struct CallRecord {
    void *passed_ptr;
    int passed_idx;
};

static std::vector<CallRecord> dd10_calls;

extern "C" {
// Original branch citation: 0x21DE48 -> func_0021DD10
void *func_0021DD10(void *obj, int a1) {
    CallRecord rec;
    rec.passed_ptr = obj;
    rec.passed_idx = a1;
    dd10_calls.push_back(rec);
    return obj;
}
}

void test_trade_action_helper_21DE20() {
    // Case 1: Standard loop crossing 16-element boundary (caller 0x224F68 ignores return value; void return)
    dd10_calls.clear();
    char dummy_pool[8192];
    int base_idx = 10;
    int count = 20;

    func_0021DE20(dummy_pool, base_idx, count);
    assert(dd10_calls.size() == (size_t)count);

    for (int i = 0; i < count; ++i) {
        int expected_idx = base_idx + i;
        void *expected_ptr = (expected_idx < 16) ? (void *)dummy_pool : (void *)(dummy_pool + 0x400);
        assert(dd10_calls[i].passed_idx == expected_idx);
        assert(dd10_calls[i].passed_ptr == expected_ptr);
    }

    // Case 2: Zero count (count = 0) -> no iterations
    // Binary trace: jumps to epilogue without writing v0; assert no calls executed
    dd10_calls.clear();
    func_0021DE20(dummy_pool, base_idx, 0);
    assert(dd10_calls.empty());

    // Case 3: Multiple 16-element boundaries (count = 35, base_idx = 0)
    // 0..15: dummy_pool
    // 16..31: dummy_pool + 0x400
    // 32..34: dummy_pool + 0x800
    dd10_calls.clear();
    func_0021DE20(dummy_pool, 0, 35);
    assert(dd10_calls.size() == 35);

    for (int i = 0; i < 35; ++i) {
        void *expected_ptr;
        if (i < 16) {
            expected_ptr = dummy_pool;
        } else if (i < 32) {
            expected_ptr = dummy_pool + 0x400;
        } else {
            expected_ptr = dummy_pool + 0x800;
        }
        assert(dd10_calls[i].passed_idx == i);
        assert(dd10_calls[i].passed_ptr == expected_ptr);
    }

    // Case 4: Single iteration (count = 1)
    dd10_calls.clear();
    func_0021DE20(dummy_pool, 5, 1);
    assert(dd10_calls.size() == 1);
    assert(dd10_calls[0].passed_idx == 5);
    assert(dd10_calls[0].passed_ptr == dummy_pool);
}

int main() {
    test_trade_action_helper_21DE20();
    return 0;
}
