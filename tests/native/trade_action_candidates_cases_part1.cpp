#include <cassert>
#include <vector>
#include "trade_action_candidates_test_support.h"

extern void *g_mock_candidate_entity;
extern void *g_mock_linked_entity;

static int mock_predicate(void *) { return 1; }

void setup_candidate_env(char *base, std::vector<char> &mgr, std::vector<char> &group,
                         std::vector<char> &entity, std::vector<void *> &vtable,
                         std::vector<int> &items, std::vector<int> &excluded,
                         std::vector<int> &candidates) {
    *reinterpret_cast<void **>(base + 176) = mgr.data();
    *reinterpret_cast<void **>(mgr.data() + 0x1f348) = group.data();
    *reinterpret_cast<void **>(group.data() + 2968) = mgr.data();
    *reinterpret_cast<void **>(mgr.data() + 172) = group.data();

    vtable.assign(100, 0);
    vtable[356 / 4] = reinterpret_cast<void *>(mock_predicate);
    *reinterpret_cast<void ***>(entity.data()) = vtable.data();

    items = {100, 101, 102};
    *reinterpret_cast<int **>(base + 212) = items.data();
    *reinterpret_cast<int *>(base + 216) = items.size();
    *reinterpret_cast<int *>(base + 224) = 16;

    excluded = {999};
    *reinterpret_cast<int **>(base + 3184) = excluded.data();
    *reinterpret_cast<int *>(base + 3188) = 0;
    *reinterpret_cast<int *>(base + 3196) = 16;

    candidates.assign(16, 0);
    *reinterpret_cast<int **>(base + 3168) = candidates.data();
    *reinterpret_cast<int *>(base + 3172) = 0;
    *reinterpret_cast<int *>(base + 3180) = 16;

    g_mock_candidate_entity = entity.data();
}

void run_candidates_cases_part1(int test_case, std::vector<char> &storage) {
    reset_candidates_test_support();
    char *base = storage.data();
    std::vector<char> mgr(0x20000, 0);
    std::vector<char> group(0x1000, 0);
    std::vector<char> entity(0x100, 0);
    std::vector<void *> vtable;
    std::vector<int> items, excluded, candidates;
    setup_candidate_env(base, mgr, group, entity, vtable, items, excluded, candidates);

    if (test_case == 0) {
        *reinterpret_cast<int *>(base + 3172) = 5;
        int res = func_002B76B0(base, 10, 0, 1, 0);
        assert(*reinterpret_cast<int *>(base + 3172) == 0 || res >= 0);
    } else if (test_case == 1) {
        *reinterpret_cast<int *>(base + 216) = 0;
        int res = func_002B76B0(base, 10, 0, 0, 0);
        assert(res == 0);
        assert(*reinterpret_cast<int *>(base + 3172) == 0);
    } else if (test_case == 2) {
        g_147190_return_val = 5;
        int res = func_002B76B0(base, 10, -1, 0, 0);
        assert(res == 3);
        assert(*reinterpret_cast<int *>(base + 3172) == 3);
        assert(candidates[0] == 100 && candidates[1] == 101 && candidates[2] == 102);
    } else if (test_case == 3) {
        g_147190_return_val = 10;
        int res = func_002B76B0(base, 10, -1, 0, 0);
        assert(res == 0);
        assert(*reinterpret_cast<int *>(base + 3172) == 0);
    } else if (test_case == 4) {
        g_147190_return_val = 10;
        int res = func_002B76B0(base, 10, 1, 0, 0);
        assert(res == 0);
        assert(*reinterpret_cast<int *>(base + 3172) == 0);
    } else if (test_case == 5) {
        g_147190_return_val = 10;
        int res = func_002B76B0(base, 10, 0, 0, 0);
        assert(res == 3);
        assert(*reinterpret_cast<int *>(base + 3172) == 3);
    } else if (test_case == 6) {
        g_147190_return_val = 11;
        int res = func_002B76B0(base, 10, 0, 0, 0);
        assert(res == 0);
        assert(*reinterpret_cast<int *>(base + 3172) == 0);
    }
}
