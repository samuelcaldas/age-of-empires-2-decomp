#include <iostream>
#include <cassert>
#include <climits>
#include <cmath>
#include <vector>

extern float last_scaled_val;
extern int helper_call_count;
extern int custom_mock_return;
extern int last_helper_val;
extern void *last_mgr_target;

extern "C" {
int select_trade_increment(int mode, int flag);
float get_scaling_factor(int index, int mode, int flag);
extern void *p_sentinel;
extern void *ctx_sentinel;
extern void *D_004E3180;

extern int mock_mode;
extern int mock_flag;

int func_00332da0(void *ptr);
int func_00188070(void *ctx);
int func_00123350(float val);
int func_002a0b30(void *mgr, int id);
int func_0029df60(void *mgr, int val);
void func_002B6220(void *self, int index, int value);
}

void run_getters7_test_part2(int test_case, std::vector<char> &storage) {
    void *self = storage.data();
    if (test_case == 10) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 1;
        custom_mock_return = -1;
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 75);
        assert(std::fabs(last_scaled_val - 75.0f) < 0.0001f);
    } else if (test_case == 11) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 0;
        custom_mock_return = 0;
        func_002B6220(self, 0x10, 50);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 1);
    } else if (test_case == 12) {
        std::vector<char> p1_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<int *>(base + 0x0BEC) = 1;
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        func_002B6220(self, 0x14, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x14 * 4);
        assert(*slot == 50);
    } else if (test_case == 13) {
        std::vector<char> p1_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        helper_call_count = 0;
        func_002B6220(self, 0x56, 42);
        assert(helper_call_count == 1);
        assert(last_mgr_target == (p1_obj.data() + 0x3624));
    } else if (test_case == 14) {
        std::vector<char> p1_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        helper_call_count = 0;
        func_002B6220(self, 0x57, 55);
        assert(helper_call_count == 1);
        assert(last_mgr_target == (p1_obj.data() + 0x3624));
    } else if (test_case == 15) {
        std::vector<char> p1_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        helper_call_count = 0;
        last_helper_val = -1;
        func_002B6220(self, 0x69, 77);
        assert(helper_call_count == 1);
        assert(last_helper_val == 77);
        assert(last_mgr_target == (p1_obj.data() + 0x3624));
    } else if (test_case == 16) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 0;
        custom_mock_return = 59;
        func_002B6220(self, 0x24, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x24 * 4);
        assert(*slot == 59);
        assert(std::fabs(last_scaled_val - 60.0f) < 0.0001f);

        func_002B6220(self, 0x3A, 100);
        slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x3A * 4);
        assert(*slot == 59);
        assert(std::fabs(last_scaled_val - 60.0f) < 0.0001f);
    } else if (test_case == 17) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 0;
        custom_mock_return = 0;
        func_002B6220(self, 0x24, 50);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x24 * 4);
        assert(*slot == 1);

        func_002B6220(self, 0x3A, 50);
        slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x3A * 4);
        assert(*slot == 1);
    } else if (test_case == 18) {
        int modes[] = {2, 3, 4};
        int flags[] = {0, 1};
        float expected_factors[] = {0.6f, 0.4f, 0.2f};
        int ids[] = {0x24, 0x3A};

        for (size_t m = 0; m < 3; ++m) {
            for (size_t f = 0; f < 2; ++f) {
                for (size_t i = 0; i < 2; ++i) {
                    std::vector<char> p1_obj(16384, 0);
                    std::vector<char> p2_obj(16384, 0);
                    char *base = storage.data();
                    *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
                    *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
                    *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

                    mock_mode = modes[m];
                    mock_flag = flags[f];
                    custom_mock_return = 42;
                    int id = ids[i];
                    helper_call_count = 0;

                    func_002B6220(self, id, 100);
                    float expected_scaled = expected_factors[m] * 100.0f;
                    assert(std::fabs(last_scaled_val - expected_scaled) < 0.0001f);
                    assert(helper_call_count == 0); // matrix targets are not 0x56/0x57/0x69
                    int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + id * 4);
                    assert(*slot == 42);
                }
            }
        }
    } else if (test_case == 19) {
        int modes[] = {2, 3, 4};
        int flags[] = {0, 1};
        float expected_factors[] = {0.75f, 0.5f, 0.25f};
        int ids[] = {0x10, 0x1A, 0x3B, 0x3C};

        for (size_t m = 0; m < 3; ++m) {
            for (size_t f = 0; f < 2; ++f) {
                for (size_t i = 0; i < 4; ++i) {
                    std::vector<char> p1_obj(16384, 0);
                    std::vector<char> p2_obj(16384, 0);
                    char *base = storage.data();
                    *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
                    *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
                    *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

                    mock_mode = modes[m];
                    mock_flag = flags[f];
                    custom_mock_return = 77;
                    int id = ids[i];
                    helper_call_count = 0;

                    func_002B6220(self, id, 100);
                    float expected_scaled = expected_factors[m] * 100.0f;
                    assert(std::fabs(last_scaled_val - expected_scaled) < 0.0001f);
                    assert(helper_call_count == 0);
                    int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + id * 4);
                    assert(*slot == 77);
                }
            }
        }
    }
}
