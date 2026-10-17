#include <cassert>
#include <vector>
#include "trade_action_candidates_test_support.h"

extern void *g_mock_candidate_entity;
extern void *g_mock_linked_entity;

void setup_candidate_env(char *base, std::vector<char> &mgr, std::vector<char> &group,
                         std::vector<char> &entity, std::vector<void *> &vtable,
                         std::vector<int> &items, std::vector<int> &excluded,
                         std::vector<int> &candidates);

void run_candidates_cases_part2(int test_case, std::vector<char> &storage) {
    reset_candidates_test_support();
    char *base = storage.data();
    std::vector<char> mgr(0x20000, 0);
    std::vector<char> group(0x1000, 0);
    std::vector<char> entity(0x100, 0);
    std::vector<void *> vtable;
    std::vector<int> items, excluded, candidates;
    setup_candidate_env(base, mgr, group, entity, vtable, items, excluded, candidates);

    if (test_case == 7) {
        excluded = {101};
        *reinterpret_cast<int **>(base + 3184) = excluded.data();
        *reinterpret_cast<int *>(base + 3188) = 1;
        g_147190_return_val = 10;
        int res = func_002B76B0(base, 10, 0, 0, 0);
        assert(res == 2);
        assert(*reinterpret_cast<int *>(base + 3172) == 2);
        assert(candidates[0] == 100 && candidates[1] == 102);
    } else if (test_case == 8) {
        g_1471a0_return_val = -1;
        g_147190_return_val = 999;
        int res = func_002B76B0(base, 10, 0, 0, 0);
        assert(res == 3);
        assert(*reinterpret_cast<int *>(base + 3172) == 3);
    } else if (test_case == 9) {
        g_1471a0_return_val = 600;
        g_1471c0_return_val = 500;
        std::vector<char> linked(0x100, 0);
        std::vector<char> field4(0x40, 0);
        *reinterpret_cast<void **>(linked.data() + 4) = field4.data();
        *reinterpret_cast<short *>(field4.data() + 14) = 27;
        g_mock_linked_entity = linked.data();
        g_147190_return_val = 999;
        int res = func_002B76B0(base, 10, 0, 0, 1);
        assert(res == 3);
        assert(*reinterpret_cast<int *>(base + 3172) == 3);
    } else if (test_case == 10) {
        g_1471a0_return_val = 600;
        g_1471c0_return_val = 500;
        std::vector<char> linked(0x100, 0);
        std::vector<char> field4(0x40, 0);
        *reinterpret_cast<void **>(linked.data() + 4) = field4.data();
        *reinterpret_cast<short *>(field4.data() + 14) = 18;
        g_mock_linked_entity = linked.data();
        g_147190_return_val = 999;
        int res = func_002B76B0(base, 10, 0, 0, 1);
        assert(res == 0);
        assert(*reinterpret_cast<int *>(base + 3172) == 0);
    } else if (test_case == 11) {
        g_1471a0_return_val = 600;
        g_1471c0_return_val = 500;
        g_mock_linked_entity = 0;
        g_147190_return_val = 999;
        int res = func_002B76B0(base, 10, 0, 0, 1);
        assert(res == 3);
        assert(*reinterpret_cast<int *>(base + 3172) == 3);
    } else if (test_case == 12) {
        candidates[0] = 100;
        *reinterpret_cast<int *>(base + 3172) = 1;
        g_147190_return_val = 10;
        int res = func_002B76B0(base, 10, 0, 0, 0);
        assert(res == 3);
        assert(*reinterpret_cast<int *>(base + 3172) == 3);
        assert(candidates[0] == 100 && candidates[1] == 101 && candidates[2] == 102);
    }
}
