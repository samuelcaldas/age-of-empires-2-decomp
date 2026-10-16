#include <iostream>
#include <cassert>
#include <climits>
#include <cmath>
#include <vector>

#include "trade_action_getters7_test_support.h"

void run_getters7_test_part1(int test_case, std::vector<char> &storage) {
    void *self = storage.data();
    if (test_case == 0) {
        func_002B6220(self, -1, 50);
    } else if (test_case == 1) {
        func_002B6220(self, 239, 50);
    } else if (test_case == 2) {
        func_002B6220(self, 5, -2);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 5 * 4);
        assert(*slot == -2);

        func_002B6220(self, 5, 150);
        assert(*slot == 150);
    } else if (test_case == 3) {
        char *base = storage.data();
        *reinterpret_cast<int *>(base + 0x0BEC) = 1;
        func_002B6220(self, 0x75, -5);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x75 * 4);
        assert(*slot == 0);
    } else if (test_case == 4) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 1;
        func_002B6220(self, 0x68, 20);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x68 * 4);
        assert(*slot == 620);
    } else if (test_case == 5) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 0;
        custom_mock_return = 731;
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 731);
        assert(std::fabs(last_scaled_val - 75.0f) < 0.0001f);
    } else if (test_case == 6) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 1;
        mock_flag = 0;
        custom_mock_return = -1;
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 100);
        assert(std::fabs(last_scaled_val - 100.0f) < 0.0001f);
    } else if (test_case == 7) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 2;
        mock_flag = 0;
        func_002B6220(self, 0x68, 20);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x68 * 4);
        assert(*slot == 260);
    } else if (test_case == 8) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 1;
        mock_flag = 0;
        func_002B6220(self, 0xE3, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0xE3 * 4);
        assert(*slot == 100);
        assert(std::fabs(last_scaled_val - 100.0f) < 0.0001f);
    } else if (test_case == 9) {
        std::vector<char> p1_obj(16384, 0);
        std::vector<char> p2_obj(16384, 0);
        char *base = storage.data();
        *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
        *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
        *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

        mock_mode = 1;
        mock_flag = 1;
        func_002B6220(self, 0x10, 100);
        int *slot = reinterpret_cast<int *>(storage.data() + 0x858 + 0x10 * 4);
        assert(*slot == 80);
        assert(std::fabs(last_scaled_val - 80.0f) < 0.0001f);
    }
}
