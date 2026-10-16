#include "tactical_ai_target_scan_fixture.h"

static void test_mode_2_categories_with_gates() {
    TargetScanManager mgr; std::memset(&mgr, 0, sizeof(mgr));
    mgr.m_field194 = 2; mgr.m_field1A0 = 1;
    TargetEntitySubsystem sub; std::memset(&sub, 0, sizeof(sub));
    sub.m_player_count = 1; sub.m_my_player_index = 99;

    TargetPlayerManager own; std::memset(&own, 0, sizeof(own));
    own.m_diplomacy_vtable = s_diplomacy_vtable; own.m_player_id = 10;
    mgr.m_player = &own;
    unsigned char color_buf[64]; std::memset(color_buf, 0, sizeof(color_buf));
    color_buf[24] = 42; own.m_color_info = color_buf;

    // Cat 45 passes without vslot 88
    TargetTypeDesc d45; std::memset(&d45, 0, sizeof(d45)); d45.m_category = 45;
    TargetEntity e45; std::memset(&e45, 0, sizeof(e45)); e45.m_type_desc = &d45;
    TargetEntity *units45[1] = {&e45}; own.m_units = units45; own.m_unit_count = 1;
    TargetPlayerManager *players[2] = {0, &own}; sub.m_players = players; mgr.m_field11C = &sub;
    reset_tracking(); func_00307B80(&mgr);
    assert(s_mark_calls == 1 && s_mark_log[0].ent == &e45);
    assert(s_mark_log[0].mark == 42 && s_mark_log[0].a3 == 0 && s_mark_log[0].t0 == 0);

    // Categories requiring vslot 88 AND m_field1A0: 128, 204, 4, 21, 2
    short gated_cats[5] = {128, 204, 4, 21, 2};
    void *ent_vt_true[100]; std::memset(ent_vt_true, 0, sizeof(ent_vt_true));
    auto vslot88_true = [](void *) -> int { return 1; };
    ent_vt_true[88] = reinterpret_cast<void *>(+vslot88_true);

    void *ent_vt_false[100]; std::memset(ent_vt_false, 0, sizeof(ent_vt_false));
    auto vslot88_false = [](void *) -> int { return 0; };
    ent_vt_false[88] = reinterpret_cast<void *>(+vslot88_false);

    for (int i = 0; i < 5; i++) {
        TargetTypeDesc d; std::memset(&d, 0, sizeof(d)); d.m_category = gated_cats[i];
        TargetEntity e; std::memset(&e, 0, sizeof(e)); e.m_type_desc = &d;
        TargetEntity *u[1] = {&e}; own.m_units = u;

        // vt[88] == true && m_field1A0 == 1 -> mark called with receiver e
        e.m_vtable = ent_vt_true; mgr.m_field1A0 = 1;
        reset_tracking(); func_00307B80(&mgr);
        assert(s_mark_calls == 1 && s_mark_log[0].ent == &e);
        assert(s_mark_log[0].mark == 42 && s_mark_log[0].a3 == 0 && s_mark_log[0].t0 == 0);

        // vt[88] == true && m_field1A0 == 0 -> gate closed
        mgr.m_field1A0 = 0;
        reset_tracking(); func_00307B80(&mgr);
        assert(s_mark_calls == 0);

        // vt[88] == false && m_field1A0 == 1 -> gate closed
        e.m_vtable = ent_vt_false; mgr.m_field1A0 = 1;
        reset_tracking(); func_00307B80(&mgr);
        assert(s_mark_calls == 0);
    }
}

static void test_mode_1_predicates_and_id533() {
    TargetScanManager mgr; std::memset(&mgr, 0, sizeof(mgr));
    mgr.m_field194 = 1;
    TargetEntitySubsystem sub; std::memset(&sub, 0, sizeof(sub));
    sub.m_player_count = 1; sub.m_my_player_index = 99;

    TargetPlayerManager own; std::memset(&own, 0, sizeof(own));
    own.m_diplomacy_vtable = s_diplomacy_vtable; own.m_player_id = 10;
    mgr.m_player = &own;
    unsigned char color_buf[64]; std::memset(color_buf, 0, sizeof(color_buf));
    color_buf[24] = 242; own.m_color_info = color_buf;

    // ID 533 universal dispatch
    TargetTypeDesc d533; std::memset(&d533, 0, sizeof(d533)); d533.m_id = 533;
    TargetEntity e533; std::memset(&e533, 0, sizeof(e533)); e533.m_type_desc = &d533;
    TargetEntity *units[1] = {&e533}; own.m_units = units; own.m_unit_count = 1;
    TargetPlayerManager *players[2] = {0, &own}; sub.m_players = players; mgr.m_field11C = &sub;
    reset_tracking(); func_00307B80(&mgr);
    assert(s_action_calls == 1 && s_action_log[0].ent == &e533);
    assert(s_action_log[0].a2 == 242 && s_action_log[0].s6 == 23 && s_action_log[0].s2 == 17);

    // Type 80 predicate false when flag424 & 1 == 0
    TargetTypeDesc d80; std::memset(&d80, 0, sizeof(d80));
    d80.m_type_code = 80; d80.m_flag424 = 0; // flag 424 is 0 -> predicate false!
    TargetEntity e80; std::memset(&e80, 0, sizeof(e80)); e80.m_type_desc = &d80;
    TargetEntity *units80[1] = {&e80}; own.m_units = units80;
    reset_tracking(); func_00307B80(&mgr);
    assert(s_action_calls == 0);
}

static void test_special_table_and_building_modes() {
    TargetScanManager mgr; std::memset(&mgr, 0, sizeof(mgr));
    TargetPlayerManager cont0; std::memset(&cont0, 0, sizeof(cont0));
    mgr.m_player = &cont0;

    // Special table 3244: tag 10, tag 2, and non-matching tag 5
    TargetTypeDesc d_tag10; std::memset(&d_tag10, 0, sizeof(d_tag10)); d_tag10.m_tag77 = 10;
    TargetEntity e_tag10; std::memset(&e_tag10, 0, sizeof(e_tag10));
    e_tag10.m_type_desc = &d_tag10; e_tag10.m_flag347 = 1;
    e_tag10.m_coord348 = 15.0f; e_tag10.m_coord352 = 25.0f;

    TargetTypeDesc d_tag2; std::memset(&d_tag2, 0, sizeof(d_tag2)); d_tag2.m_tag77 = 2;
    TargetEntity e_tag2; std::memset(&e_tag2, 0, sizeof(e_tag2));
    e_tag2.m_type_desc = &d_tag2; e_tag2.m_flag347 = 1;
    e_tag2.m_coord348 = 30.0f; e_tag2.m_coord352 = 40.0f;

    TargetTypeDesc d_tag5; std::memset(&d_tag5, 0, sizeof(d_tag5)); d_tag5.m_tag77 = 5;
    TargetEntity e_tag5; std::memset(&e_tag5, 0, sizeof(e_tag5));
    e_tag5.m_type_desc = &d_tag5; e_tag5.m_flag347 = 1;

    TargetEntity e_noflag; std::memset(&e_noflag, 0, sizeof(e_noflag));
    e_noflag.m_type_desc = &d_tag10; e_noflag.m_flag347 = 0; // flag 347 == 0 -> no plot

    cont0.m_table3244[0] = &e_tag10;
    cont0.m_table3244[1] = &e_tag2;
    cont0.m_table3244[2] = &e_tag5;
    cont0.m_table3244[3] = &e_noflag;
    for (int i = 4; i < 40; i++) cont0.m_table3244[i] = 0;
    cont0.m_fieldD50 = 4;

    reset_tracking(); func_00307B80(&mgr);
    assert(s_mark_calls == 4);
    assert(s_plot_calls == 2);
    // Plot call 0: tag 10
    assert(s_plot_log[0].x == 15 && s_plot_log[0].y == 25 && s_plot_log[0].mark == 255 && s_plot_log[0].type == 2);
    // Plot call 1: tag 2
    assert(s_plot_log[1].x == 30 && s_plot_log[1].y == 40 && s_plot_log[1].mark == 255 && s_plot_log[1].type == 2);

    // Building mode: ID 274 with m_field1A0 == 1 -> mark 70, type 4
    cont0.m_fieldD50 = 0;
    TargetTypeDesc d274; std::memset(&d274, 0, sizeof(d274)); d274.m_id = 274;
    TargetEntity e274; std::memset(&e274, 0, sizeof(e274));
    e274.m_type_desc = &d274; e274.m_posX = 10.0f; e274.m_posY = 20.0f;
    TargetEntity *b_units[1] = {&e274};
    cont0.m_units = b_units; cont0.m_unit_count = 1;

    mgr.m_field1A0 = 1; reset_tracking(); func_00307B80(&mgr);
    assert(s_plot_calls == 1);
    assert(s_plot_log[0].x == 10 && s_plot_log[0].y == 20 && s_plot_log[0].mark == 70 && s_plot_log[0].type == 4);

    // Building mode: ID 274 with m_field1A0 == 0 -> mark 69, type 4
    mgr.m_field1A0 = 0; reset_tracking(); func_00307B80(&mgr);
    assert(s_plot_calls == 1);
    assert(s_plot_log[0].x == 10 && s_plot_log[0].y == 20 && s_plot_log[0].mark == 69 && s_plot_log[0].type == 4);
}

int main() {
    test_mode_2_categories_with_gates();
    test_mode_1_predicates_and_id533();
    test_special_table_and_building_modes();
    return 0;
}
