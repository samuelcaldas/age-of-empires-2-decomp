#include <cassert>
#include <vector>
#include "trade_action_dispatcher_test_support.h"

void setup_test_pointers(char *base, std::vector<char> &mgr_buf, std::vector<char> &p172_buf);

void *mock_item_predicate(void *) { return 0; }
int mock_team_action(void *, int) { return 0; }
float mock_candidate_scale(void *) { return 1.0f; }
int mock_candidate_check(void *, int *, short, float, int, int, int, int) { return 1; }

void setup_market_mocks(std::vector<char> &item, std::vector<char> &group, void *record = 0) {
    static std::vector<void *> item_vtable(90, 0);
    static std::vector<void *> dispatcher_vtable(10, 0);
    static std::vector<void *> candidate_vtable(110, 0);
    static std::vector<char> dispatcher(64, 0);
    item_vtable[89] = reinterpret_cast<void *>(mock_item_predicate);
    dispatcher_vtable[9] = reinterpret_cast<void *>(mock_team_action);
    candidate_vtable[73] = reinterpret_cast<void *>(mock_candidate_scale);
    candidate_vtable[109] = reinterpret_cast<void *>(mock_candidate_check);
    *reinterpret_cast<void ***>(item.data()) = item_vtable.data();
    *reinterpret_cast<void ***>(dispatcher.data()) = dispatcher_vtable.data();
    *reinterpret_cast<void **>(group.data() + 6960) = dispatcher.data();
    if (record) {
        *reinterpret_cast<void ***>(record) = candidate_vtable.data();
    }
}

void run_dispatcher_cases_part2(int test_case, std::vector<char> &storage) {
    reset_dispatcher_test_support();
    char *base = storage.data();
    std::vector<char> mgr_buf(200000, 0);
    std::vector<char> p172_buf(65536, 0);
    setup_test_pointers(base, mgr_buf, p172_buf);

    if (test_case == 7) {
        func_002B66B0(base, 1, 0, 104, 5);
        assert(g_2261c0_calls == 1);
        assert(g_2c29e0_calls == 1);
        assert(g_2c29e0_last_target_idx == 5);
    } else if (test_case == 8) {
        std::vector<char> ent1(1024, 0);
        std::vector<char> ent2(1024, 0);
        std::vector<char> world1(4096, 0);
        std::vector<char> world2(4096, 0);
        *reinterpret_cast<void **>(ent1.data() + 8) = world1.data();
        *reinterpret_cast<void **>(ent2.data() + 8) = world2.data();
        *reinterpret_cast<int *>(world1.data() + 2976) = 1;
        *reinterpret_cast<int *>(p172_buf.data() + 2976) = 1;
        g_mock_entity = ent1.data();
        g_mock_target_ent = ent2.data();
        func_002B66B0(base, 2, 0, 513, 1);
        assert(g_2261c0_calls == 1);
        assert(g_2be490_calls == 0);
    } else if (test_case == 9) {
        std::vector<char> ent1(1024, 0);
        std::vector<char> ent2(1024, 0);
        std::vector<char> world1(4096, 0);
        std::vector<char> world2(4096, 0);
        std::vector<char> field4_ent1(128, 0);
        std::vector<char> field4_ent2(128, 0);
        std::vector<int> buf1(16, 0);
        std::vector<int> buf2(16, 0);
        *reinterpret_cast<int **>(base + 3800) = buf1.data();
        *reinterpret_cast<int *>(base + 3804) = 0;
        *reinterpret_cast<int *>(base + 3812) = 16;
        *reinterpret_cast<int **>(base + 3816) = buf2.data();
        *reinterpret_cast<int *>(base + 3820) = 0;
        *reinterpret_cast<int *>(base + 3828) = 16;
        *reinterpret_cast<void **>(ent1.data() + 8) = world1.data();
        *reinterpret_cast<void **>(ent2.data() + 8) = world2.data();
        *reinterpret_cast<void **>(ent1.data() + 4) = field4_ent1.data();
        *reinterpret_cast<void **>(ent2.data() + 4) = field4_ent2.data();
        *reinterpret_cast<short *>(field4_ent1.data() + 14) = 4;
        setup_market_mocks(ent1, p172_buf);
        *reinterpret_cast<short *>(ent1.data() + 36) = 41;
        *reinterpret_cast<short *>(ent2.data() + 36) = 52;
        *reinterpret_cast<int *>(world1.data() + 2976) = 2;
        *reinterpret_cast<int *>(world2.data() + 2976) = 2;
        *reinterpret_cast<int *>(p172_buf.data() + 2976) = 1;
        g_mock_entity = ent2.data();
        g_mock_target_ent = ent1.data();
        func_002B66B0(base, 2, 0, 513, 1);
        assert(g_2261c0_calls == 1);
        assert(g_2be490_calls == 1);
        assert(g_2bfe30_calls == 1);
        assert(g_2bfe30_last_id1 == 41 && g_2bfe30_last_id2 == 52);
        assert(g_144d20_calls == 1);
        assert(buf1[0] == 41 && buf2[0] == 41);
        assert(*reinterpret_cast<int *>(base + 3804) == 1);
        assert(*reinterpret_cast<int *>(base + 3820) == 1);
        assert(*reinterpret_cast<int *>(base + 3756) > 0);
    } else if (test_case == 10) {
        std::vector<char> ent1(1024, 0);
        std::vector<char> ent2(1024, 0);
        std::vector<char> world1(4096, 0);
        std::vector<char> world2(4096, 0);
        std::vector<char> field4_ent1(128, 0);
        std::vector<char> field4_ent2(128, 0);
        std::vector<int> buf1(16, 0);
        std::vector<int> buf2(16, 0);
        *reinterpret_cast<int **>(base + 3800) = buf1.data();
        *reinterpret_cast<int *>(base + 3804) = 0;
        *reinterpret_cast<int *>(base + 3812) = 16;
        *reinterpret_cast<int **>(base + 3816) = buf2.data();
        *reinterpret_cast<int *>(base + 3820) = 0;
        *reinterpret_cast<int *>(base + 3828) = 16;
        *reinterpret_cast<void **>(ent1.data() + 8) = world1.data();
        *reinterpret_cast<void **>(ent2.data() + 8) = world2.data();
        *reinterpret_cast<void **>(ent1.data() + 4) = field4_ent1.data();
        *reinterpret_cast<void **>(ent2.data() + 4) = field4_ent2.data();
        *reinterpret_cast<short *>(field4_ent1.data() + 14) = 21;
        setup_market_mocks(ent1, p172_buf);
        *reinterpret_cast<short *>(ent1.data() + 36) = 41;
        *reinterpret_cast<short *>(ent2.data() + 36) = 52;
        *reinterpret_cast<int *>(world1.data() + 2976) = 2;
        *reinterpret_cast<int *>(world2.data() + 2976) = 2;
        *reinterpret_cast<int *>(p172_buf.data() + 2976) = 1;
        g_mock_entity = ent2.data();
        g_mock_target_ent = ent1.data();
        func_002B66B0(base, 2, 0, 513, 1);
        assert(g_2261c0_calls == 1);
        assert(g_2b9770_calls == 1);
        assert(g_2b9770_last_id == 41 && g_2b9770_last_value == 100);
        assert(g_2a0420_calls == 1);
        assert(g_2a0420_last_id1 == 41 && g_2a0420_last_id2 == 52);
        assert(g_144d20_calls == 1);
        assert(buf1[0] == 41 && buf2[0] == 41);
        assert(*reinterpret_cast<int *>(base + 3804) == 1);
        assert(*reinterpret_cast<int *>(base + 3820) == 1);
        assert(*reinterpret_cast<int *>(base + 3756) > 0);
    } else if (test_case == 11) {
        std::vector<char> item(1024, 0), target(1024, 0);
        std::vector<char> item_world(4096, 0), target_world(4096, 0);
        std::vector<char> item_data(128, 0), target_data(128, 0);
        *reinterpret_cast<void **>(item.data() + 8) = item_world.data();
        *reinterpret_cast<void **>(target.data() + 8) = target_world.data();
        *reinterpret_cast<void **>(item.data() + 4) = item_data.data();
        *reinterpret_cast<void **>(target.data() + 4) = target_data.data();
        target_data[0] = 60;
        *reinterpret_cast<int *>(target_world.data() + 2976) = 2;
        *reinterpret_cast<int *>(p172_buf.data() + 2976) = 1;
        g_mock_entity = target.data();
        g_mock_target_ent = item.data();
        func_002B66B0(base, 2, 0, 513, 1);
        assert(g_2be490_calls == 0 && g_144d20_calls == 0);
        assert(*reinterpret_cast<int *>(base + 3804) == 0);
        assert(*reinterpret_cast<int *>(base + 3820) == 0);
    } else if (test_case == 12) {
        std::vector<char> item(1024, 0), target(1024, 0);
        std::vector<char> item_world(4096, 0), target_world(4096, 0);
        std::vector<char> item_data(128, 0), target_data(128, 0);
        std::vector<int> first_ids(16, 0), second_ids(16, 0);
        std::vector<char> candidate(1024, 0), zero_id_entity(128, 0);
        *reinterpret_cast<int **>(base + 3800) = first_ids.data();
        *reinterpret_cast<int *>(base + 3812) = 16;
        *reinterpret_cast<int **>(base + 3816) = second_ids.data();
        *reinterpret_cast<int *>(base + 3828) = 16;
        *reinterpret_cast<void **>(item.data() + 8) = item_world.data();
        *reinterpret_cast<void **>(target.data() + 8) = target_world.data();
        *reinterpret_cast<void **>(item.data() + 4) = item_data.data();
        *reinterpret_cast<void **>(target.data() + 4) = target_data.data();
        setup_market_mocks(item, p172_buf, zero_id_entity.data());
        *reinterpret_cast<short *>(item_data.data() + 14) = 4;
        *reinterpret_cast<short *>(item.data() + 36) = 41;
        *reinterpret_cast<int *>(target_world.data() + 2976) = 2;
        *reinterpret_cast<int *>(p172_buf.data() + 2976) = 1;
        g_mock_entity = target.data();
        g_mock_target_ent = item.data();
        g_mock_found_ent = candidate.data();
        g_mock_zero_id_entity = zero_id_entity.data();
        g_mock_mode_flag = 1;
        func_002B66B0(base, 2, 0, 513, 1);
        assert(g_2be250_calls == 1 && g_2be250_last_mode == 102);
        assert(g_2ac300_calls == 1 && g_2ac370_calls == 1);
        assert(*reinterpret_cast<int *>(candidate.data() + 232) == 1);
        assert(*reinterpret_cast<int *>(candidate.data() + 228) == 2);
        assert(g_144d20_calls == 0);
    }
}
