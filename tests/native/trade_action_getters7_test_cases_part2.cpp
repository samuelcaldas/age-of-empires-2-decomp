#include <iostream>
#include <cassert>
#include <climits>
#include <cmath>
#include <vector>
#include "trade_action_getters7_matrix_support.h"

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
        int ids[] = {0x24, 0x3A};
        float expected_factors[] = {0.6f, 0.4f, 0.2f};
        run_matrix_test(storage, ids, 2, expected_factors, 42);
    } else if (test_case == 19) {
        int ids[] = {0x10, 0x1A, 0x3B, 0x3C};
        float expected_factors[] = {0.75f, 0.5f, 0.25f};
        run_matrix_test(storage, ids, 4, expected_factors, 77);
    } else if (test_case == 20) {
        int ids[] = {0x13, 0x14};
        float expected_factors[] = {0.6f, 0.4f, 0.2f};
        run_matrix_test(storage, ids, 2, expected_factors, 88);
    } else if (test_case == 21) {
        int ids[] = {0xE3, 0xE4};
        float expected_factors[] = {0.75f, 0.5f, 0.25f};
        run_matrix_test(storage, ids, 2, expected_factors, 99);
    }
}
