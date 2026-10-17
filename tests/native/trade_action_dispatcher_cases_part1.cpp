#include <cassert>
#include <vector>
#include "trade_action_dispatcher_test_support.h"

void setup_test_pointers(char *base, std::vector<char> &mgr_buf, std::vector<char> &p172_buf) {
    *reinterpret_cast<void **>(base + 176) = mgr_buf.data();
    char *mgr_ptr = mgr_buf.data();
    *reinterpret_cast<void **>(mgr_ptr + 0x20000 - 3256) = p172_buf.data();
    *reinterpret_cast<void **>(p172_buf.data() + 2968) = mgr_ptr;
    *reinterpret_cast<void **>(mgr_ptr + 172) = p172_buf.data();
    *reinterpret_cast<void **>(mgr_ptr + 1028) = reinterpret_cast<void *>(0x1234);
    D_004E3180 = mgr_ptr;
}

void run_dispatcher_cases_part1(int test_case, std::vector<char> &storage) {
    reset_dispatcher_test_support();
    char *base = storage.data();
    std::vector<char> mgr_buf(200000, 0);
    std::vector<char> p172_buf(65536, 0);
    setup_test_pointers(base, mgr_buf, p172_buf);

    if (test_case == 0) {
        func_002B66B0(0, 1, 0, 114, 0);
        assert(g_2261c0_calls == 0);
    } else if (test_case == 1) {
        func_002B66B0(base, 1, 0, 50, 0);
        assert(g_2261c0_calls == 0);
    } else if (test_case == 2) {
        func_002B66B0(base, 1, 0, 114, 0);
        assert(g_2261c0_calls == 1);
        assert(g_2a03c0_calls == 1);
        assert(g_2a03c0_last_flag == 1);
    } else if (test_case == 3) {
        func_002B66B0(base, 1, 0, 115, 0);
        assert(g_2261c0_calls == 1);
        assert(g_2a03c0_calls == 1);
        assert(g_2a03c0_last_flag == 0);
    } else if (test_case == 4) {
        func_002B66B0(base, 1, 0, 109, 0);
        assert(g_2261c0_calls == 1);
        assert(g_2a03f0_calls == 1);
        assert(g_2a03f0_last_flag == 1);
    } else if (test_case == 5) {
        func_002B66B0(base, 1, 0, 110, 0);
        assert(g_2261c0_calls == 1);
        assert(g_2a03f0_calls == 1);
        assert(g_2a03f0_last_flag == 0);
    } else if (test_case == 6) {
        func_002B66B0(base, 1, 0, 108, 2);
        assert(g_2261c0_calls == 1);
        assert(g_297390_calls == 1);
        assert(g_mock_last_lookup_id == 2);
    }
}
