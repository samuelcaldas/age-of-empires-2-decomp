#ifndef TRADE_ACTION_GETTERS7_MATRIX_SUPPORT_H
#define TRADE_ACTION_GETTERS7_MATRIX_SUPPORT_H

#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>

#include "trade_action_getters7_test_support.h"

inline void run_matrix_test(std::vector<char> &storage, const int *ids, size_t num_ids, const float *expected_factors, int expected_mock_return) {
    int modes[] = {2, 3, 4};
    int flags[] = {0, 1};

    for (size_t m = 0; m < 3; ++m) {
        for (size_t f = 0; f < 2; ++f) {
            for (size_t i = 0; i < num_ids; ++i) {
                std::fill(storage.begin(), storage.end(), 0);
                std::vector<char> p1_obj(16384, 0);
                std::vector<char> p2_obj(16384, 0);
                char *base = storage.data();
                *reinterpret_cast<void **>(base + 0xB0) = p1_obj.data();
                *reinterpret_cast<void **>(p1_obj.data() + 0xAC) = p2_obj.data();
                *reinterpret_cast<void **>(p2_obj.data() + 0xB98) = p_sentinel;

                int *slot_pre = reinterpret_cast<int *>(base + 0x858 + ids[i] * 4);
                *slot_pre = -999;

                mock_mode = modes[m];
                mock_flag = flags[f];
                custom_mock_return = expected_mock_return;
                int id = ids[i];
                scaler_call_count = 0;
                last_scaled_val = NAN;
                helper_call_count = 0;

                func_002B6220(base, id, 100);
                float expected_scaled = expected_factors[m] * 100.0f;
                assert(scaler_call_count == 1);
                assert(std::fabs(last_scaled_val - expected_scaled) < 0.0001f);
                assert(helper_call_count == 0);
                int *slot = reinterpret_cast<int *>(base + 0x858 + id * 4);
                assert(*slot == expected_mock_return);
            }
        }
    }
}

#endif
